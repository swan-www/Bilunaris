const std = @import("std");
const zmath = @import("zmath");

const Mat4 = zmath.Mat;
const Vec4 = zmath.Vec;
const Vec3 = zmath.Vec;
const RndGen = std.rand.DefaultPrng;

const Ztf = @import("ztf");

const ZtfApp = Ztf.app;
const ztf_App = ZtfApp.ztf_App;

const ZtfOS = Ztf.os;
const ztf_ReloadDesc = ZtfOS.ztf_ReloadDesc;

const ZtfUI = Ztf.ui;
const ZtfLog = Ztf.log;
const ZtfMath = Ztf.math;
const ZtfCC = Ztf.camera_controller;
const ZtfGfx = Ztf.gfx;
const ZtfFS = Ztf.fs;
const ZtfFont = Ztf.font;
const ZtfInput = Ztf.input;
const ZtfBString = Ztf.bstring;
const BString = ZtfBString.bstring;
const ZtfRL = Ztf.resource_loader;
const ZtfProfiler = Ztf.profiler;
const ZtfMem = Ztf.memory;

usingnamespace ZtfGfx;

const LunRender = @import("lun_render");

const RingBuffer = LunRender.ringbuffer;

const ZtfExt = @import("ztf_ext");

const MAX_PLANETS = 20;

var gpa : std.heap.GeneralPurposeAllocator(.{.safety = true, .thread_safe = true}) = undefined;
var global_alloc : std.mem.Allocator = undefined;

const PlanetInfoStruct = struct
{
	mTranslationMat : Mat4 = zmath.identity(),
    mScaleMat : Mat4 = zmath.identity(),
    mSharedMat : Mat4 = zmath.identity(), // Matrix to pass down to children
	mColor : Vec4 = zmath.f32x4s(0.0),
	mParentIndex : u32 = 0,
    mYOrbitSpeed : f32 = 0.0, // Rotation speed around parent
    mZOrbitSpeed : f32 = 0.0,
    mRotationSpeed : f32 = 0.0, // Rotation speed around self
    mMorphingSpeed : f32 = 0.0, // Speed of morphing betwee cube and sphere
};

const UniformBlock_C = extern struct
{
    mProjectView : ZtfCC.ZTF_CameraMatrix = std.mem.zeroes(ZtfCC.ZTF_CameraMatrix),
    mToWorldMat : [MAX_PLANETS]Mat4 = std.mem.zeroes([MAX_PLANETS]Mat4),
    mColor : [MAX_PLANETS]Vec4 = std.mem.zeroes([MAX_PLANETS]Vec4),
    mGeometryWeight : [MAX_PLANETS]ZtfMath.ztf_Float4 = std.mem.zeroes([MAX_PLANETS]ZtfMath.ztf_Float4),

    // Point Light Information
    mLightPosition : @Vector(3, f32) = [_]f32{0,0,0},
    mLightColor : @Vector(3, f32) = [_]f32{0,0,0},
};

const UniformBlockSky_C = extern struct
{
	mProjectView : ZtfCC.ZTF_CameraMatrix = std.mem.zeroes(ZtfCC.ZTF_CameraMatrix),
};

// But we only need Two sets of resources (one in flight and one being used on CPU)
const gDataBufferCount : u32 = 2;
const gNumPlanets : c_uint = 11;     // Sun, Mercury -> Neptune, Pluto, Moon
const gTimeOffset : c_uint = 600000; // For visually better starting locations
const gRotSelfScale : f32 = 0.0004;
const gRotOrbitYScale : f32 = 0.001;
const gRotOrbitZScale : f32 = 0.00001;

var GPURingBuffer = RingBuffer.GPURingBuffer{};

var pRenderer : *ZtfGfx.ztf_Renderer = undefined;
var pRendererOpt : ?*ZtfGfx.ztf_Renderer = null;

var pGraphicsQueue : ?*ZtfGfx.ztf_Queue = null;
var gGraphicsCmdRing = RingBuffer.GpuCmdRing{};

var pSwapChain : ?*ZtfGfx.ztf_SwapChain = null;
var pDepthBuffer : ?*ZtfGfx.ztf_RenderTarget = null;
var pImageAcquiredSemaphore : ?*ZtfGfx.ztf_Semaphore = null;

var pSphereShader : ?*ZtfGfx.ztf_Shader = null;
var pSphereVertexBuffer : ?*ZtfGfx.ztf_Buffer = null;
var pSphereIndexBuffer : ?*ZtfGfx.ztf_Buffer = null;
var gSphereIndexCount : u32 = 0;
var pSpherePipeline : ?*ZtfGfx.ztf_Pipeline = null;
var gSphereVertexLayout = ZtfGfx.ztf_VertexLayout{};
var gSphereLayoutType : u32 = 0;

var pSkyBoxDrawShader : ?*ZtfGfx.ztf_Shader = null;
var pSkyBoxVertexBuffer : ?*ZtfGfx.ztf_Buffer = null;
var pSkyBoxDrawPipeline : ?*ZtfGfx.ztf_Pipeline = null;
var pRootSignature : ?*ZtfGfx.ztf_RootSignature = null;
var pSamplerSkyBox : ?*ZtfGfx.ztf_Sampler = null;
var pSkyBoxTextures : [6]?*ZtfGfx.ztf_Texture = [_]?*ZtfGfx.ztf_Texture{null} ** 6;
var pDescriptorSetTexture : ?*ZtfGfx.ztf_DescriptorSet = null;
var pDescriptorSetUniforms : ?*ZtfGfx.ztf_DescriptorSet = null;

var pProjViewUniformBuffer : [gDataBufferCount]?*ZtfGfx.ztf_Buffer = [_]?*ZtfGfx.ztf_Buffer{null} ** gDataBufferCount;
var pSkyboxUniformBuffer : [gDataBufferCount]?*ZtfGfx.ztf_Buffer = [_]?*ZtfGfx.ztf_Buffer{null} ** gDataBufferCount;

var gFrameIndex : u32 = 0;
var gGpuProfileToken : ZtfProfiler.ztf_ProfileToken = ZtfProfiler.ZTF_PROFILE_INVALID_TOKEN;

var gNumberOfSpherePoints : i32 = 0;
var gUniformData = UniformBlock_C{};
var gUniformDataSky = UniformBlockSky_C{};
var gPlanetInfoData : [gNumPlanets]PlanetInfoStruct = .{PlanetInfoStruct{}} ** gNumPlanets;

var pCameraController : ?*ZtfCC.ICameraController = null;

var pGuiWindow : ?*ZtfUI.ztf_UIComponent = null;

var gFontID : u32 = 0;

var pPipelineStatsQueryPool : [gDataBufferCount]?*ZtfGfx.ztf_QueryPool = [_]?*ZtfGfx.ztf_QueryPool{null} ** gDataBufferCount;

const pSkyBoxImageFileNames = [_][]const u8{ "Skybox_right1.tex",  "Skybox_left2.tex",  "Skybox_top3.tex",
                                        "Skybox_bottom4.tex", "Skybox_front5.tex", "Skybox_back6.tex" };

var gFrameTimeDraw = ZtfFont.ztf_FontDrawDesc{};

// Generate sky box vertex buffer
const gSkyBoxPoints = [_]f32{
    10.0,  -10.0, -10.0, 6.0, // -z
    -10.0, -10.0, -10.0, 6.0,   -10.0, 10.0,  -10.0, 6.0,   -10.0, 10.0,
    -10.0, 6.0,   10.0,  10.0,  -10.0, 6.0,   10.0,  -10.0, -10.0, 6.0,

    -10.0, -10.0, 10.0,  2.0, //-x
    -10.0, -10.0, -10.0, 2.0,   -10.0, 10.0,  -10.0, 2.0,   -10.0, 10.0,
    -10.0, 2.0,   -10.0, 10.0,  10.0,  2.0,   -10.0, -10.0, 10.0,  2.0,

    10.0,  -10.0, -10.0, 1.0, //+x
    10.0,  -10.0, 10.0,  1.0,   10.0,  10.0,  10.0,  1.0,   10.0,  10.0,
    10.0,  1.0,   10.0,  10.0,  -10.0, 1.0,   10.0,  -10.0, -10.0, 1.0,

    -10.0, -10.0, 10.0,  5.0, // +z
    -10.0, 10.0,  10.0,  5.0,   10.0,  10.0,  10.0,  5.0,   10.0,  10.0,
    10.0,  5.0,   10.0,  -10.0, 10.0,  5.0,   -10.0, -10.0, 10.0,  5.0,

    -10.0, 10.0,  -10.0, 3.0, //+y
    10.0,  10.0,  -10.0, 3.0,   10.0,  10.0,  10.0,  3.0,   10.0,  10.0,
    10.0,  3.0,   -10.0, 10.0,  10.0,  3.0,   -10.0, 10.0,  -10.0, 3.0,

    10.0,  -10.0, 10.0,  4.0, //-y
    10.0,  -10.0, -10.0, 4.0,   -10.0, -10.0, -10.0, 4.0,   -10.0, -10.0,
    -10.0, 4.0,   -10.0, -10.0, 10.0,  4.0,   10.0,  -10.0, 10.0,  4.0,
};

var gPipelineStatsCharArray : [2048]u8 = [_]u8{0} ** 2048;
var gPipelineStatsCharArraySlice = gPipelineStatsCharArray[0..2047 :0];
var gPipelineStats : BString = undefined;

const gWindowTestScripts : [][]const u8 = .{ "TestFullScreen.lua", "TestCenteredWindow.lua", "TestNonCenteredWindow.lua", "TestBorderless.lua" };

fn reloadRequest(_ : ?*anyopaque) callconv(.C) void
{
    const reload = ztf_ReloadDesc{ .mType = ZtfOS.ZTF_RELOAD_TYPE_SHADER };
    ZtfOS.ztf_requestReload(&reload);
}

pub export fn ztf_appInit(pApp: ?*ztf_App) callconv(.C) bool
{
	gpa = .{};
    global_alloc = gpa.allocator();

	const window_desc = ZtfApp.ztf_getWindowDesc(pApp);
	ZtfExt.init(null);
	ZtfExt.LOGF(ZtfLog.ztf_eINFO, "ztf_appInit", .{});

	const pSystemFileIO = ZtfFS.ztf_getSystemFileIO();
	ZtfFS.ztf_fsSetPathForResourceDir(pSystemFileIO, ZtfFS.ZTF_RM_CONTENT, ZtfFS.ZTF_RD_SHADER_BINARIES, "CompiledShaders");
	ZtfFS.ztf_fsSetPathForResourceDir(pSystemFileIO, ZtfFS.ZTF_RM_CONTENT, ZtfFS.ZTF_RD_TEXTURES, "Textures");
	ZtfFS.ztf_fsSetPathForResourceDir(pSystemFileIO, ZtfFS.ZTF_RM_CONTENT, ZtfFS.ZTF_RD_FONTS, "Fonts");
	ZtfFS.ztf_fsSetPathForResourceDir(pSystemFileIO, ZtfFS.ZTF_RM_DEBUG, ZtfFS.ZTF_RD_SCREENSHOTS, "Screenshots");
	ZtfFS.ztf_fsSetPathForResourceDir(pSystemFileIO, ZtfFS.ZTF_RM_CONTENT, ZtfFS.ZTF_RD_SCRIPTS, "Scripts");
	ZtfFS.ztf_fsSetPathForResourceDir(pSystemFileIO, ZtfFS.ZTF_RM_DEBUG, ZtfFS.ZTF_RD_DEBUG, "Debug");

	const settings = ZtfGfx.ztf_RendererDesc{
		.mD3D11Supported = true,
		.mGLESSupported = true,
	};

	ZtfGfx.ztf_initRenderer(ztf_appGetName(pApp), &settings, &pRendererOpt);

	if(pRendererOpt == null)
	{
		ZtfExt.LOGF(ZtfLog.ztf_eERROR, "Renderer failed to initialise.", .{});
		return false;
	}
	pRenderer = pRendererOpt.?;

	if (ZtfGfx.ztf_getGPUSettings_mPipelineStatsQueries(&pRenderer.*.pGpu.*.mSettings) != 0)
	{
		const poolDesc = ZtfGfx.ztf_QueryPoolDesc{
			.mQueryCount = 3,
			.mType = ZtfGfx.ZTF_QUERY_TYPE_PIPELINE_STATISTICS,
		};
		for (0..gDataBufferCount) |i| {
			ZtfGfx.ztf_addQueryPool(pRenderer, &poolDesc, &pPipelineStatsQueryPool[i]);
		}
	}

	var queue_desc = ZtfGfx.ztf_QueueDesc{
		.mType = ZtfGfx.ZTF_QUEUE_TYPE_GRAPHICS,
		.mFlag = ZtfGfx.ZTF_QUEUE_FLAG_INIT_MICROPROFILE,
	};
	ZtfGfx.ztf_addQueue(pRenderer,  &queue_desc, @ptrCast(&pGraphicsQueue));

	const cmd_ring_desc = RingBuffer.GPUCmdRingDesc{
		.pQueue = pGraphicsQueue,
		.mPoolCount = gDataBufferCount,
		.mCmdPerPoolCount = 1,
		.mAddSyncPrimitives = true,
	};
	RingBuffer.addGpuCmdRing(pRenderer, &cmd_ring_desc, &gGraphicsCmdRing) catch |err| @panic(@errorName(err));

	ZtfGfx.ztf_addSemaphore(pRenderer, &pImageAcquiredSemaphore);
	ZtfRL.ztf_initResourceLoaderInterface(@ptrCast(pRenderer), null);

	//Skybox textures
	for(0..6) |i|
	{
		var textureDesc = ZtfRL.ztf_TextureLoadDesc{
			.pFileName = @ptrCast(pSkyBoxImageFileNames[i]),
			.ppTexture = @ptrCast(&pSkyBoxTextures[i]),
			// Textures representing color should be stored in SRGB or HDR format
			.mCreationFlag = ZtfRL.ZTF_TEXTURE_CREATION_FLAG_SRGB,
		};
		_ = &textureDesc;
		ZtfRL.ztf_addResource2(&textureDesc, null);
	}

	//Sampler
	const samplerDesc = ZtfGfx.ztf_SamplerDesc{
		.mMinFilter = ZtfGfx.ZTF_FILTER_LINEAR,
		.mMagFilter = ZtfGfx.ZTF_FILTER_LINEAR,
		.mMipMapMode = ZtfGfx.ZTF_MIPMAP_MODE_NEAREST,
		.mAddressU = ZtfGfx.ZTF_ADDRESS_MODE_CLAMP_TO_EDGE,
		.mAddressV = ZtfGfx.ZTF_ADDRESS_MODE_CLAMP_TO_EDGE,
		.mAddressW = ZtfGfx.ZTF_ADDRESS_MODE_CLAMP_TO_EDGE,
	};
	ZtfGfx.ztf_addSampler(pRenderer, &samplerDesc, &pSamplerSkyBox);

	//Skybox Vertex Buffer
	const skyBoxDataSize : u64 = 4 * 6 * 6 * @sizeOf(f32);
	var skyboxVbDesc = ZtfRL.ztf_BufferLoadDesc{
		.mDesc = .{
			.mDescriptors = ZtfGfx.ZTF_DESCRIPTOR_TYPE_VERTEX_BUFFER,
			.mMemoryUsage = ZtfGfx.ZTF_RESOURCE_MEMORY_USAGE_GPU_ONLY,
			.mSize = skyBoxDataSize,
		},
		.pData = &gSkyBoxPoints,
		.ppBuffer = @ptrCast(&pSkyBoxVertexBuffer),
	};
	ZtfRL.ztf_addResource(@ptrCast(&skyboxVbDesc), null);

	//Uniform Buffers
	var ubDesc = ZtfRL.ztf_BufferLoadDesc{
		.mDesc = .{
			.mDescriptors = ZtfGfx.ZTF_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
			.mMemoryUsage = ZtfGfx.ZTF_RESOURCE_MEMORY_USAGE_CPU_TO_GPU,
			.mFlags = ZtfGfx.ZTF_BUFFER_CREATION_FLAG_PERSISTENT_MAP_BIT,
		},
		.pData = null,
	};
	for (0..gDataBufferCount) |i|
	{
		ubDesc.mDesc.pName = "ProjViewUniformBuffer";
		ubDesc.mDesc.mSize = @sizeOf(UniformBlock_C);
		ubDesc.ppBuffer = @ptrCast(&pProjViewUniformBuffer[i]);
		ZtfRL.ztf_addResource(&ubDesc, null);
		ubDesc.mDesc.pName = "SkyboxUniformBuffer";
		ubDesc.mDesc.mSize = @sizeOf(UniformBlockSky_C);
		ubDesc.ppBuffer = @ptrCast(&pSkyboxUniformBuffer[i]);
		ZtfRL.ztf_addResource(&ubDesc, null);
	}

	// Load fonts
	var font : ZtfFont.ztf_FontDesc = ZtfFont.ztf_getDefaultFontDesc();
	font.pFontPath = "TitilliumText/TitilliumText-Bold.otf";
	ZtfFont.ztf_fntDefineFonts(&font, 1, &gFontID);

	//Font System
	var fontSystemDesc : ZtfFont.ztf_FontSystemDesc = ZtfFont.ztf_getDefaultFontSystemDesc();
	fontSystemDesc.pRenderer = @ptrCast(pRenderer);
	if (!ZtfFont.ztf_initFontSystem(&fontSystemDesc))
	{
		ZtfExt.LOGF(ZtfLog.ztf_eERROR, "Font System failed to initialise.", .{});
		return false;
	}

	// Initialize Forge User Interface Rendering
	var uiRenderDesc = ZtfUI.ztf_defaultInitUserInterfaceDesc();
	//ZtfUI.ztf_defaultInitUserInterfaceDesc(&uiRenderDesc);
	uiRenderDesc.pRenderer = @ptrCast(pRenderer);
	ZtfUI.ztf_initUserInterface(&uiRenderDesc);

 	// Initialize micro profiler and its UI.
	const app_settings = ZtfApp.ztf_getAppSettings(pApp);
	var profiler = ZtfProfiler.ztf_ProfilerDesc{
		.pRenderer = @ptrCast(pRenderer),
		.mWidthUI = @intCast(app_settings.*.mWidth),
		.mHeightUI = @intCast(app_settings.*.mHeight),
	};
	ZtfProfiler.ztf_initProfiler(&profiler);
	gGpuProfileToken = ZtfProfiler.ztf_addGpuProfiler(@ptrCast(pRenderer), @ptrCast(pGraphicsQueue), "Graphics");

	// GUI
	var guiDesc = ZtfUI.ztf_UIComponentDesc{};
	ZtfUI.ztf_defaultInitUIComponentDesc(&guiDesc);
	guiDesc.mStartPosition = ZtfUI.ztf_Float2{.x = @as(f32, @floatFromInt(app_settings.*.mWidth)) * 0.01, .y = @as(f32, @floatFromInt(app_settings.*.mHeight)) * 0.2};
	ZtfUI.ztf_uiCreateComponent(ztf_appGetName(pApp), &guiDesc, &pGuiWindow);

	var vertexLayoutWidget = ZtfUI.ztf_SliderUintWidget{};
	ZtfUI.ztf_defaultInitSliderUintWidget(&vertexLayoutWidget);
	vertexLayoutWidget.mMin = 0;
	vertexLayoutWidget.mMax = 1;
	vertexLayoutWidget.mStep = 1;
	vertexLayoutWidget.pData = &gSphereLayoutType;

	const pVLw = ZtfUI.ztf_uiCreateComponentWidget(pGuiWindow, "Vertex Layout", &vertexLayoutWidget, ZtfUI.ZTF_WIDGET_TYPE_SLIDER_UINT, true);
	ZtfUI.ztf_uiSetWidgetOnEditedCallback(pVLw, null, reloadRequest);

	const staticLocal = struct
	{
		var color = ZtfMath.ztf_Float4{ .x = 1.0, .y = 1.0, .z = 1.0, .w = 1.0 };
	};

	gPipelineStats = ZtfExt.bfromarr(gPipelineStatsCharArraySlice);

	if (ZtfGfx.ztf_getGPUSettings_mPipelineStatsQueries(&pRenderer.*.pGpu.*.mSettings) != 0)
	{
		const statsWidget = ZtfUI.ztf_DynamicTextWidget
		{
			.pText = @ptrCast(&gPipelineStats),
			.pColor = @ptrCast(&staticLocal.color),
		};
		_ = ZtfUI.ztf_uiCreateComponentWidget(pGuiWindow, "Pipeline Stats", &statsWidget,  ZtfUI.ZTF_WIDGET_TYPE_DYNAMIC_TEXT, true);
	}

	ZtfRL.ztf_waitForAllResourceLoads();

	//Input System
	var input_desc = ZtfInput.ztf_InputSystemDesc{
		.pRenderer = @ptrCast(pRenderer),
		.pWindow =  @ptrCast(window_desc),
		.pJoystickTexture = "circlepad.tex",
	};
	_ = &input_desc;
	if (!ZtfInput.ztf_initInputSystem(&input_desc))
	{
		ZtfExt.LOGF(ZtfLog.ztf_eERROR, "Input System failed to initialise.", .{});
		return false;
	}

	// Setup planets (Rotation speeds are relative to Earth's, some values randomly given)
	// Sun
	gPlanetInfoData[0].mParentIndex = 0;
	gPlanetInfoData[0].mYOrbitSpeed = 0.0; // Earth years for one orbit
	gPlanetInfoData[0].mZOrbitSpeed = 0.0;
	gPlanetInfoData[0].mRotationSpeed = 24.0; // Earth days for one rotation
	gPlanetInfoData[0].mTranslationMat = zmath.identity();
	gPlanetInfoData[0].mScaleMat = zmath.scalingV(zmath.f32x4s(10.0));
	gPlanetInfoData[0].mColor = Vec4{0.97, 0.38, 0.09, 0.0};
	gPlanetInfoData[0].mMorphingSpeed = 0.2;

	// Mercury
	gPlanetInfoData[1].mParentIndex = 0;
	gPlanetInfoData[1].mYOrbitSpeed = 0.5;
	gPlanetInfoData[1].mZOrbitSpeed = 0.0;
	gPlanetInfoData[1].mRotationSpeed = 58.7;
	gPlanetInfoData[1].mTranslationMat = zmath.translationV(Vec4{10.0, 0.0, 0.0, 0.0});
	gPlanetInfoData[1].mScaleMat = zmath.scalingV(zmath.f32x4s(1.0));
	gPlanetInfoData[1].mColor = Vec4{0.45, 0.07, 0.006, 1.0};
	gPlanetInfoData[1].mMorphingSpeed = 5.0;

	// Venus
	gPlanetInfoData[2].mParentIndex = 0;
	gPlanetInfoData[2].mYOrbitSpeed = 0.8;
	gPlanetInfoData[2].mZOrbitSpeed = 0.0;
	gPlanetInfoData[2].mRotationSpeed = 243.0;
	gPlanetInfoData[2].mTranslationMat = zmath.translationV(Vec4{20.0, 0.0, 5.0, 0.0});
	gPlanetInfoData[2].mScaleMat = zmath.scalingV(zmath.f32x4s(2.0));
	gPlanetInfoData[2].mColor = Vec4{0.6, 0.32, 0.006, 1.0};
	gPlanetInfoData[2].mMorphingSpeed = 1.0;

	// Earth
	gPlanetInfoData[3].mParentIndex = 0;
	gPlanetInfoData[3].mYOrbitSpeed = 1.0;
	gPlanetInfoData[3].mZOrbitSpeed = 0.0;
	gPlanetInfoData[3].mRotationSpeed = 1.0;
	gPlanetInfoData[3].mTranslationMat = zmath.translationV(Vec4{30.0, 0.0, 0.0, 0.0});
	gPlanetInfoData[3].mScaleMat = zmath.scalingV(zmath.f32x4s(4.0));
	gPlanetInfoData[3].mColor = Vec4{0.07, 0.028, 0.61, 1.0};
	gPlanetInfoData[3].mMorphingSpeed = 1.0;

	// Mars
	gPlanetInfoData[4].mParentIndex = 0;
	gPlanetInfoData[4].mYOrbitSpeed = 2.0;
	gPlanetInfoData[4].mZOrbitSpeed = 0.0;
	gPlanetInfoData[4].mRotationSpeed = 1.1;
	gPlanetInfoData[4].mTranslationMat = zmath.translationV(Vec4{40.0, 0.0, 0.0, 0.0});
	gPlanetInfoData[4].mScaleMat = zmath.scalingV(zmath.f32x4s(3.0));
	gPlanetInfoData[4].mColor = Vec4{0.79, 0.07, 0.006, 1.0};
	gPlanetInfoData[4].mMorphingSpeed = 1.0;

	// Jupiter
	gPlanetInfoData[5].mParentIndex = 0;
	gPlanetInfoData[5].mYOrbitSpeed = 11.0;
	gPlanetInfoData[5].mZOrbitSpeed = 0.0;
	gPlanetInfoData[5].mRotationSpeed = 0.4;
	gPlanetInfoData[5].mTranslationMat = zmath.translationV(Vec4{50.0, 0.0, 0.0, 0.0});
	gPlanetInfoData[5].mScaleMat = zmath.scalingV(zmath.f32x4s(8.0));
	gPlanetInfoData[5].mColor = Vec4{0.32, 0.13, 0.13, 1.0};
	gPlanetInfoData[5].mMorphingSpeed = 6.0;

	// Saturn
	gPlanetInfoData[6].mParentIndex = 0;
	gPlanetInfoData[6].mYOrbitSpeed = 29.4;
	gPlanetInfoData[6].mZOrbitSpeed = 0.0;
	gPlanetInfoData[6].mRotationSpeed = 0.5;
	gPlanetInfoData[6].mTranslationMat = zmath.translationV(Vec4{60.0, 0.0, 0.0, 0.0});
	gPlanetInfoData[6].mScaleMat = zmath.scalingV(zmath.f32x4s(6.0));
	gPlanetInfoData[6].mColor = Vec4{0.45, 0.45, 0.21, 1.0};
	gPlanetInfoData[6].mMorphingSpeed = 1.0;

	// Uranus
	gPlanetInfoData[7].mParentIndex = 0;
	gPlanetInfoData[7].mYOrbitSpeed = 84.07;
	gPlanetInfoData[7].mZOrbitSpeed = 0.0;
	gPlanetInfoData[7].mRotationSpeed = 0.8;
	gPlanetInfoData[7].mTranslationMat = zmath.translationV(Vec4{70.0, 0.0, 0.0, 0.0});
	gPlanetInfoData[7].mScaleMat = zmath.scalingV(zmath.f32x4s(7.0));
	gPlanetInfoData[7].mColor = Vec4{0.13, 0.13, 0.32, 1.0};
	gPlanetInfoData[7].mMorphingSpeed = 1.0;

	// Neptune
	gPlanetInfoData[8].mParentIndex = 0;
	gPlanetInfoData[8].mYOrbitSpeed = 164.81;
	gPlanetInfoData[8].mZOrbitSpeed = 0.0;
	gPlanetInfoData[8].mRotationSpeed = 0.9;
	gPlanetInfoData[8].mTranslationMat = zmath.translationV(Vec4{80.0, 0.0, 0.0, 0.0});
	gPlanetInfoData[8].mScaleMat = zmath.scalingV(zmath.f32x4s(8.0));
	gPlanetInfoData[8].mColor = Vec4{0.21, 0.028, 0.79, 1.0};
	gPlanetInfoData[8].mMorphingSpeed = 1.0;

	// Pluto - Not a planet XDD
	gPlanetInfoData[9].mParentIndex = 0;
	gPlanetInfoData[9].mYOrbitSpeed = 247.7;
	gPlanetInfoData[9].mZOrbitSpeed = 1.0;
	gPlanetInfoData[9].mRotationSpeed = 7.0;
	gPlanetInfoData[9].mTranslationMat = zmath.translationV(Vec4{90.0, 0.0, 0.0, 0.0});
	gPlanetInfoData[9].mScaleMat = zmath.scalingV(zmath.f32x4s(1.0));
	gPlanetInfoData[9].mColor = Vec4{0.45, 0.21, 0.21, 1.0};
	gPlanetInfoData[9].mMorphingSpeed = 1.0;

	// Moon
	gPlanetInfoData[10].mParentIndex = 3;
	gPlanetInfoData[10].mYOrbitSpeed = 1.0;
	gPlanetInfoData[10].mZOrbitSpeed = 200.0;
	gPlanetInfoData[10].mRotationSpeed = 27.0;
	gPlanetInfoData[10].mTranslationMat = zmath.translationV(Vec4{5.0, 0.0, 0.0, 0.0});
	gPlanetInfoData[10].mScaleMat = zmath.scalingV(zmath.f32x4s(1.0));
	gPlanetInfoData[10].mColor = Vec4{0.07, 0.07, 0.13, 1.0};
	gPlanetInfoData[10].mMorphingSpeed = 1.0;

	var cmp = ZtfCC.ztf_cameraMotionParameters_default();
	cmp.maxSpeed = 160.0;
	cmp.acceleration = 600.0;
	cmp.braking = 200.0;

	const camPos = ZtfMath.make_vec3( 48.0, 48.0, 20.0);
	const lookAt = ZtfMath.make_vec3( 0.0, 0.0, 0.0 );

	pCameraController = ZtfCC.ztf_initFpsCameraController(@ptrCast(&camPos), @ptrCast(&lookAt));
	ZtfCC.ztf_setMotionParameters(pCameraController, &cmp);

	//TODO input actions

	gFrameIndex = 0;

	return true;
}

fn rendererExit(_: ?*ztf_App) void
{
	if(pRendererOpt == null)
	{
		return;
	}

	ZtfCC.ztf_exitCameraController(pCameraController);

	ZtfInput.ztf_exitInputSystem();
	
	ZtfProfiler.ztf_exitProfiler();
	
	ZtfUI.ztf_exitUserInterface();

	ZtfFont.ztf_exitFontSystem();

	for (0..gDataBufferCount) |i|
	{
		ZtfRL.ztf_removeResource(@ptrCast(pProjViewUniformBuffer[i]));
		ZtfRL.ztf_removeResource(@ptrCast(pSkyboxUniformBuffer[i]));
	}

	ZtfRL.ztf_removeResource(@ptrCast(pSkyBoxVertexBuffer));

	ZtfGfx.ztf_removeSampler(pRenderer, pSamplerSkyBox);

	for(0..6) |i|
	{
		ZtfRL.ztf_removeResource2(@ptrCast(pSkyBoxTextures[i]));
	}

	ZtfRL.ztf_exitResourceLoaderInterface(@ptrCast(pRenderer));

	ZtfGfx.ztf_removeSemaphore(pRenderer, pImageAcquiredSemaphore);

	RingBuffer.removeGpuCmdRing(pRenderer, &gGraphicsCmdRing) catch |err| @panic(@errorName(err));

	ZtfGfx.ztf_removeQueue(pRenderer, pGraphicsQueue);

	for (0..gDataBufferCount) |i| {

		if (ZtfGfx.ztf_getGPUSettings_mPipelineStatsQueries(&pRenderer.*.pGpu.*.mSettings) != 0)
		{
			ZtfGfx.ztf_removeQueryPool(pRenderer, pPipelineStatsQueryPool[i]);
		}
	}

	ZtfGfx.ztf_exitRenderer(pRenderer);
	pRenderer = undefined;
}

pub export fn ztf_appExit(ztf_app: ?*ztf_App) callconv(.C) void
{
	rendererExit(ztf_app);

	ZtfExt.LOGF(ZtfLog.ztf_eINFO, "ztf_appExit", .{});
	ZtfExt.deinit();

	const deinit_status = gpa.deinit();
	if (deinit_status == .leak)
	{
		@panic("Memory leak on exit.");
	}
}

pub export fn ztf_appLoad(pApp: ?*ztf_App, pReloadDesc: [*c]ZtfRL.ztf_ReloadDesc) callconv(.C) bool
{
	const app_settings = ZtfApp.ztf_getAppSettings(pApp);
	const window_desc = ZtfApp.ztf_getWindowDesc(pApp);

	if (pReloadDesc.*.mType & ZtfRL.ZTF_RELOAD_TYPE_SHADER != 0)
	{
		//Add shaders
		{
			const skyShader = ZtfRL.ztf_ShaderLoadDesc{
				.mStages = .{
					ZtfRL.ztf_ShaderStageLoadDesc{
						.pFileName = "skybox.vert",
					},
					ZtfRL.ztf_ShaderStageLoadDesc{
						.pFileName ="skybox.frag",
					},
					.{},
					.{},
					.{},
					.{},
				},
			};

			const basicShader = ZtfRL.ztf_ShaderLoadDesc{
				.mStages = .{
					ZtfRL.ztf_ShaderStageLoadDesc{
						.pFileName = "basic.vert",
					},
					ZtfRL.ztf_ShaderStageLoadDesc{
						.pFileName ="basic.frag",
					},
					.{},
					.{},
					.{},
					.{},
				},
			};

			ZtfRL.ztf_addShader(@ptrCast(pRenderer), @ptrCast(&skyShader), @ptrCast(&pSkyBoxDrawShader));
			ZtfRL.ztf_addShader(@ptrCast(pRenderer), @ptrCast(&basicShader), @ptrCast(&pSphereShader));
		}

		//add RootSignatures;
		{
			const shaders = [_]?*ZtfGfx.ztf_Shader{
				pSphereShader,
				pSkyBoxDrawShader,
			};
			const shadersCount = shaders.len;

			const pStaticSamplers = [_][]const u8{"uSampler0"};
			const rootDesc = ZtfGfx.ztf_RootSignatureDesc{
				.mStaticSamplerCount = 1,
				.ppStaticSamplerNames = @ptrCast(@constCast(&pStaticSamplers[0])),
				.ppStaticSamplers = &pSamplerSkyBox,
				.mShaderCount = shadersCount,
				.ppShaders = @constCast(&shaders),
			};
			ZtfGfx.ztf_addRootSignature(pRenderer, &rootDesc, &pRootSignature);
		}

		//add DescriptorSets
		{
			const desc = ZtfGfx.ztf_DescriptorSetDesc{
				.pRootSignature = pRootSignature,
				.mUpdateFrequency = ZtfGfx.ZTF_DESCRIPTOR_UPDATE_FREQ_NONE,
				.mMaxSets = 1
			};
			ZtfGfx.ztf_addDescriptorSet(pRenderer, &desc, &pDescriptorSetTexture);
			const desc2 = ZtfGfx.ztf_DescriptorSetDesc{
				.pRootSignature = pRootSignature,
				.mUpdateFrequency = ZtfGfx.ZTF_DESCRIPTOR_UPDATE_FREQ_PER_FRAME,
				.mMaxSets = gDataBufferCount * 2
			};
			ZtfGfx.ztf_addDescriptorSet(pRenderer, &desc2, &pDescriptorSetUniforms);
		}
	}

	if (pReloadDesc.*.mType & (ZtfRL.ZTF_RELOAD_TYPE_RESIZE | ZtfRL.ZTF_RELOAD_TYPE_RENDERTARGET) != 0)
	{
		//add swapchain
		{
			var swapChainDesc = ZtfGfx.ztf_SwapChainDesc{
				.mWindowHandle = @bitCast(window_desc.*.handle),
				.mPresentQueueCount = 1,
				.ppPresentQueues = &pGraphicsQueue,
				.mWidth = @intCast(app_settings.*.mWidth),
				.mHeight = @intCast(app_settings.*.mHeight),
				.mImageCount = ZtfGfx.ztf_getRecommendedSwapchainImageCount(pRenderer, @ptrCast(&window_desc.*.handle)),
				.mColorSpace = ZtfGfx.ZTF_COLOR_SPACE_SDR_SRGB,
				.mEnableVsync = app_settings.*.mVSyncEnabled,
				.mFlags = ZtfGfx.ZTF_SWAP_CHAIN_CREATION_FLAG_ENABLE_FOVEATED_RENDERING_VR,
			};
			
			swapChainDesc.mColorFormat = ZtfGfx.ztf_getSupportedSwapchainFormat(pRenderer, &swapChainDesc, ZtfGfx.ZTF_COLOR_SPACE_SDR_SRGB);
		
			ZtfGfx.ztf_addSwapChain(pRenderer, &swapChainDesc, &pSwapChain);
			if(pSwapChain == null)
			{
				ZtfExt.LOGF(ZtfLog.ztf_eERROR, "Swapchain failed to initialise.", .{});
				return false;
			}
		}

		//add depth buffer
		{
			const depthRT = ZtfGfx.ztf_RenderTargetDesc{
				.mArraySize = 1,
				.mClearValue = .{ .unnamed_1 = .{.depth = 0.0, .stencil = 0,}, },
				.mDepth = 1,
				.mFormat = ZtfGfx.TinyImageFormat_D32_SFLOAT,
				.mStartState = ZtfGfx.ZTF_RESOURCE_STATE_DEPTH_WRITE,
				.mHeight = @intCast(app_settings.*.mHeight),
				.mSampleCount = ZtfGfx.ZTF_SAMPLE_COUNT_1,
				.mSampleQuality = 0,
				.mWidth = @intCast(app_settings.*.mWidth),
				.mFlags = ZtfGfx.ZTF_TEXTURE_CREATION_FLAG_ON_TILE | ZtfGfx.ZTF_TEXTURE_CREATION_FLAG_VR_MULTIVIEW,
			};
			ZtfGfx.ztf_addRenderTarget(pRenderer, &depthRT, &pDepthBuffer);
			if(pDepthBuffer == null)
			{
				ZtfExt.LOGF(ZtfLog.ztf_eERROR, "Depth Buffer failed to initialise.", .{});
				return false;
			}
		}
	}

	if (pReloadDesc.*.mType & (ZtfRL.ZTF_RELOAD_TYPE_SHADER | ZtfRL.ZTF_RELOAD_TYPE_RENDERTARGET) != 0)
	{
		generate_complex_mesh();
		
		var rasterizerStateDesc = ZtfGfx.ztf_RasterizerStateDesc{
			.mCullMode = ZtfGfx.ZTF_CULL_MODE_NONE,
		};

        var sphereRasterizerStateDesc = ZtfGfx.ztf_RasterizerStateDesc{
			.mCullMode = ZtfGfx.ZTF_CULL_MODE_FRONT,
		};

        var depthStateDesc = ZtfGfx.ztf_DepthStateDesc{
			.mDepthTest = true,
			.mDepthWrite = true,
			.mDepthFunc = ZtfGfx.ZTF_CMP_GEQUAL,
		};

        var desc = ZtfGfx.ztf_PipelineDesc{
			.mType = ZtfGfx.ZTF_PIPELINE_TYPE_GRAPHICS,
			.unnamed_0 = .{ .mGraphicsDesc = .{
				.mPrimitiveTopo = ZtfGfx.ZTF_PRIMITIVE_TOPO_TRI_LIST,
				.mRenderTargetCount = 1,
				.pDepthState = &depthStateDesc,
				.pColorFormats = &(pSwapChain.?.ppRenderTargets[0].*.mFormat),
				.mSampleCount = pSwapChain.?.ppRenderTargets[0].*.mSampleCount,
				.mDepthStencilFormat = pDepthBuffer.?.mFormat,
				.pRootSignature = pRootSignature,
				.pShaderProgram = pSphereShader,
				.pVertexLayout = &gSphereVertexLayout,
				.pRasterizerState = &sphereRasterizerStateDesc,
				.mVRFoveatedRendering = true,
			},},
		};
		desc.unnamed_0.mGraphicsDesc.mSampleQuality = ZtfGfx.ztf_getRenderTarget_mSampleQuality(pSwapChain.?.ppRenderTargets[0]);
        ZtfGfx.ztf_addPipeline(pRenderer, &desc, &pSpherePipeline);

        // layout and pipeline for skybox draw
        var vertexLayout = ZtfGfx.ztf_VertexLayout{
			.mBindingCount = 1,
			.mAttribCount = 1,
		};
		vertexLayout.mBindings[0].mStride = @sizeOf(ZtfMath.ztf_Float4);
        vertexLayout.mAttribs[0].mSemantic = ZtfGfx.ZTF_SEMANTIC_POSITION;
        vertexLayout.mAttribs[0].mFormat = ZtfGfx.TinyImageFormat_R32G32B32A32_SFLOAT;
        vertexLayout.mAttribs[0].mBinding = 0;
        vertexLayout.mAttribs[0].mLocation = 0;
        vertexLayout.mAttribs[0].mOffset = 0;
        desc.unnamed_0.mGraphicsDesc.pVertexLayout = &vertexLayout;

        desc.unnamed_0.mGraphicsDesc.pDepthState = null;
        desc.unnamed_0.mGraphicsDesc.pRasterizerState = &rasterizerStateDesc;
        desc.unnamed_0.mGraphicsDesc.pShaderProgram = pSkyBoxDrawShader; //-V519
        ZtfGfx.ztf_addPipeline(pRenderer, &desc, &pSkyBoxDrawPipeline);
	}

	//prepareDescriptorSets();
	{
		{
			// Prepare descriptor sets
			var params : [6]ZtfGfx.ztf_DescriptorData = [_]ZtfGfx.ztf_DescriptorData{ ZtfGfx.ztf_DescriptorData{} } ** 6;
			params[0].pName = "RightText";
			params[0].unnamed_1.ppTextures = &pSkyBoxTextures[0];
			params[1].pName = "LeftText";
			params[1].unnamed_1.ppTextures = &pSkyBoxTextures[1];
			params[2].pName = "TopText";
			params[2].unnamed_1.ppTextures = &pSkyBoxTextures[2];
			params[3].pName = "BotText";
			params[3].unnamed_1.ppTextures = &pSkyBoxTextures[3];
			params[4].pName = "FrontText";
			params[4].unnamed_1.ppTextures = &pSkyBoxTextures[4];
			params[5].pName = "BackText";
			params[5].unnamed_1.ppTextures = &pSkyBoxTextures[5];
			ZtfGfx.ztf_updateDescriptorSet(pRenderer, 0, pDescriptorSetTexture, 6, &params);
		}

        for (0..gDataBufferCount) |i|
        {
            var params : [1]ZtfGfx.ztf_DescriptorData = .{
				.{
					.pName = "uniformBlock",
					.unnamed_1 = .{.ppBuffers = &pSkyboxUniformBuffer[i],},
				}, 
			};
            ZtfGfx.ztf_updateDescriptorSet(pRenderer, @as(u32, @intCast(i * 2 + 0)), pDescriptorSetUniforms, 1, &params);

            params[0].pName = "uniformBlock";
            params[0].unnamed_1.ppBuffers = &pProjViewUniformBuffer[i];
            ZtfGfx.ztf_updateDescriptorSet(pRenderer, @as(u32, @intCast(i * 2 + 1)), pDescriptorSetUniforms, 1, &params);
        }
	}

	return true;
}

pub export fn ztf_appUnload(_: ?*ztf_App, pReloadDesc: [*c]ztf_ReloadDesc) callconv(.C) void
{
	ZtfGfx.ztf_waitQueueIdle(pGraphicsQueue);

	if (pReloadDesc.*.mType & (ZtfRL.ZTF_RELOAD_TYPE_SHADER | ZtfRL.ZTF_RELOAD_TYPE_RENDERTARGET) != 0)
	{
		ZtfGfx.ztf_removePipeline(pRenderer, pSkyBoxDrawPipeline);
        ZtfGfx.ztf_removePipeline(pRenderer, pSpherePipeline);
		ZtfRL.ztf_removeResource(@ptrCast(pSphereVertexBuffer));
		ZtfRL.ztf_removeResource(@ptrCast(pSphereIndexBuffer));
	}

	if (pReloadDesc.*.mType & (ZtfRL.ZTF_RELOAD_TYPE_RESIZE | ZtfRL.ZTF_RELOAD_TYPE_RENDERTARGET) != 0)
	{
		ZtfGfx.ztf_removeSwapChain(pRenderer, pSwapChain);
		ZtfGfx.ztf_removeRenderTarget(pRenderer, pDepthBuffer);
	}

	if (pReloadDesc.*.mType & ZtfRL.ZTF_RELOAD_TYPE_SHADER != 0)
	{
		//remove DescriptorSets
		{
			ZtfGfx.ztf_removeDescriptorSet(pRenderer, pDescriptorSetTexture);
			ZtfGfx.ztf_removeDescriptorSet(pRenderer, pDescriptorSetUniforms);
		}

		//Remove RootSignatures;
		{
			ZtfGfx.ztf_removeRootSignature(@ptrCast(pRenderer), pRootSignature);
		}

		//Remove shaders
		{
			ZtfRL.ztf_removeShader(@ptrCast(pRenderer), @ptrCast(pSphereShader));
			ZtfRL.ztf_removeShader(@ptrCast(pRenderer), @ptrCast(pSkyBoxDrawShader));
		}
	}
}

pub export fn ztf_appUpdate(pApp: ?*ztf_App, deltaTime: f32) callconv(.C) void
{
	const app_settings = ZtfApp.ztf_getAppSettings(pApp);

	ZtfCC.ztf_update(pCameraController, deltaTime);

	const static = struct {
		var currentTime : f32 = 0.0;
	};

	// Scene Update
	static.currentTime += deltaTime * 1000.0;

	// update camera with time
	const viewMat = ZtfCC.ztf_getViewMatrix(pCameraController);

	const aspectInverse = @as(f32, @floatFromInt(app_settings.*.mHeight)) / @as(f32, @floatFromInt(app_settings.*.mWidth));
	const horizontal_fov = std.math.pi / 2.0;
	const projMat : ZtfCC.ZTF_CameraMatrix = ZtfCC.ztf_perspectiveReverseZ(horizontal_fov, aspectInverse, 0.1, 1000.0);

	gUniformData.mProjectView = ZtfCC.ztf_camera_matrix_mul_mat(&projMat, &viewMat);

	// point light parameters
	gUniformData.mLightPosition = [_]f32{0, 0, 0};
	gUniformData.mLightColor = [_]f32{0.9, 0.9, 0.7}; // Pale Yellow
}

pub export fn ztf_appDraw(pApp: ?*ztf_App) callconv(.C) void
{
	const app_settings = ZtfApp.ztf_getAppSettings(pApp);
	const settings_vsync_enabled = app_settings.*.mVSyncEnabled;
	const swapchain_vsync_enabled = ZtfGfx.ztf_getSwapChain_mEnableVsync(pSwapChain) != 0;
	if(swapchain_vsync_enabled != settings_vsync_enabled)
	{
		ZtfGfx.ztf_waitQueueIdle(pGraphicsQueue);
		ZtfGfx.ztf_toggleVSync(pRenderer, &pSwapChain);
	}

	var swapchainImageIndex : u32 = 0;
	ZtfGfx.ztf_acquireNextImage(pRenderer, pSwapChain, pImageAcquiredSemaphore, null, &swapchainImageIndex);
	
	//const pRenderTarget 
	const pRenderTarget = pSwapChain.?.ppRenderTargets[swapchainImageIndex];
	var elem = RingBuffer.getNextGpuCmdRingElement(&gGraphicsCmdRing, true, 1) catch |err| @panic(@errorName(err));

	// Stall if CPU is running "gDataBufferCount" frames ahead of GPU
	var fenceStatus : ZtfGfx.ztf_FenceStatus = 0;
	ZtfGfx.ztf_getFenceStatus(pRenderer, elem.pFence, &fenceStatus);
	if (fenceStatus == ZtfGfx.ZTF_FENCE_STATUS_INCOMPLETE)
	{
		ZtfGfx.ztf_waitForFences(pRenderer, 1, &elem.pFence);
	}

	// Update uniform buffers
	var viewProjCbv = ZtfRL.ztf_BufferUpdateDesc{ .pBuffer = @ptrCast(pProjViewUniformBuffer[gFrameIndex]), };
	ZtfRL.ztf_beginUpdateResource(&viewProjCbv);
	_ = std.zig.c_builtins.__builtin_memcpy(viewProjCbv.pMappedData, &gUniformData, @sizeOf(@TypeOf(gUniformData)));
	ZtfRL.ztf_endUpdateResource(&viewProjCbv);

	var skyboxViewProjCbv = ZtfRL.ztf_BufferUpdateDesc{ .pBuffer = @ptrCast(pSkyboxUniformBuffer[gFrameIndex]), };
	ZtfRL.ztf_beginUpdateResource(&skyboxViewProjCbv);
	_ = std.zig.c_builtins.__builtin_memcpy(skyboxViewProjCbv.pMappedData, &gUniformDataSky, @sizeOf(@TypeOf(gUniformDataSky)));
	ZtfRL.ztf_endUpdateResource(&skyboxViewProjCbv);

	// Reset cmd pool for this frame
	ZtfGfx.ztf_resetCmdPool(pRenderer, elem.pCmdPool);
	var pipelineStatsQueries = ZtfGfx.ztf_getGPUSettings_mPipelineStatsQueries(&pRenderer.*.pGpu.*.mSettings);
	if (pipelineStatsQueries != 0)
	{
		var data3D = ZtfGfx.ztf_QueryData{};
		var data2D = ZtfGfx.ztf_QueryData{};
		ZtfGfx.ztf_getQueryData(pRenderer, pPipelineStatsQueryPool[gFrameIndex], 0, &data3D);
		ZtfGfx.ztf_getQueryData(pRenderer, pPipelineStatsQueryPool[gFrameIndex], 1, &data2D);
		//const fmt_msg = \\\n
		//	\\Pipeline Stats 3D:\n
		//	\\    VS invocations:      %u\n
		//	\\    PS invocations:      %u\n
		//	\\    Clipper invocations: %u\n
		//	\\    IA primitives:       %u\n
		//	\\    Clipper primitives:  %u\n
		//	\\\n
		//	\\Pipeline Stats 2D UI:\n
		//	\\    VS invocations:      %u\n
		//	\\    PS invocations:      %u\n
		//	\\    Clipper invocations: %u\n
		//	\\    IA primitives:       %u\n
		//	\\    Clipper primitives:  %u\n
		//;
//
		//const data3DPipeStats = &data3D.unnamed_0.unnamed_0.mPipelineStats;
		//const data2DPipeStats = &data3D.unnamed_0.unnamed_0.mPipelineStats;

		//const formatted_msg = std.fmt.printf()
		//_ = ZtfExt.bformat(&gPipelineStats,
		//		fmt_msg,
		//		.{data3DPipeStats.*.mVSInvocations, data3DPipeStats.*.mPSInvocations, data3DPipeStats.*.mCInvocations,
		//		data3DPipeStats.*.mIAPrimitives, data3DPipeStats.*.mCPrimitives, data2DPipeStats.*.mVSInvocations,
		//		data2DPipeStats.*.mPSInvocations, data2DPipeStats.*.mCInvocations, data2DPipeStats.*.mIAPrimitives,
		//		data2DPipeStats.*.mCPrimitives});
	}

	const cmd = elem.pCmds[0];
	ZtfGfx.ztf_beginCmd(cmd);

	ZtfProfiler.ztf_cmdBeginGpuFrameProfile(@ptrCast(cmd), gGpuProfileToken, true);
	pipelineStatsQueries = ZtfGfx.ztf_getGPUSettings_mPipelineStatsQueries(&pRenderer.*.pGpu.*.mSettings);
	if (pipelineStatsQueries != 0)
	{
		ZtfGfx.ztf_cmdResetQuery(cmd, pPipelineStatsQueryPool[gFrameIndex], 0, 2);
		var queryDesc = ZtfGfx.ztf_QueryDesc{ .mIndex = 0, };
		ZtfGfx.ztf_cmdBeginQuery(cmd, pPipelineStatsQueryPool[gFrameIndex], &queryDesc);
	}

	var barriers = [_]ZtfGfx.ztf_RenderTargetBarrier{
		ZtfGfx.ztf_RenderTargetBarrier{
			.pRenderTarget = pRenderTarget,
			.mCurrentState = ZtfGfx.ZTF_RESOURCE_STATE_PRESENT,
			.mNewState = ZtfGfx.ZTF_RESOURCE_STATE_RENDER_TARGET,
		},
	};
	ZtfGfx.ztf_cmdResourceBarrier(cmd, 0, null, 0, null, 1, &barriers);

	_ = ZtfProfiler.ztf_cmdBeginGpuTimestampQuery(@ptrCast(cmd), gGpuProfileToken, "Draw Skybox/Planets", true);

	// simply record the screen cleaning command
	var bindRenderTargets = ZtfGfx.ztf_BindRenderTargetsDesc{
		.mRenderTargetCount = 1,
		.mDepthStencil = ZtfGfx.ztf_BindDepthTargetDesc{
			.pDepthStencil = pDepthBuffer,
			.mLoadAction = ZtfGfx.ZTF_LOAD_ACTION_CLEAR
		},
	};
	bindRenderTargets.mRenderTargets[0] = ZtfGfx.ztf_BindRenderTargetDesc{
		.pRenderTarget = pRenderTarget,
		.mLoadAction = ZtfGfx.ZTF_LOAD_ACTION_CLEAR
	};

	const rtarget_width = ZtfGfx.ztf_getRenderTarget_mWidth(pRenderTarget);
	const rtarget_height = ZtfGfx.ztf_getRenderTarget_mHeight(pRenderTarget);
	ZtfGfx.ztf_cmdBindRenderTargets(cmd, &bindRenderTargets);
	ZtfGfx.ztf_cmdSetViewport(cmd, 0.0, 0.0, @floatFromInt(rtarget_width), @floatFromInt(rtarget_height), 0.0, 1.0);
	ZtfGfx.ztf_cmdSetScissor(cmd, 0, 0, rtarget_width, rtarget_height);

	const skyboxVbStride : u32 = @as(u32, @sizeOf(f32) * 4);

	_ = ZtfProfiler.ztf_cmdBeginGpuTimestampQuery(@ptrCast(cmd), gGpuProfileToken, "Draw Skybox", true);
	ZtfGfx.ztf_cmdSetViewport(cmd, 0.0, 0.0, @floatFromInt(rtarget_width), @floatFromInt(rtarget_height), 1.0, 1.0);
	ZtfGfx.ztf_cmdBindPipeline(cmd, pSkyBoxDrawPipeline);
	ZtfGfx.ztf_cmdBindDescriptorSet(cmd, 0, pDescriptorSetTexture);
	ZtfGfx.ztf_cmdBindDescriptorSet(cmd, gFrameIndex * 2 + 0, pDescriptorSetUniforms);
	ZtfGfx.ztf_cmdBindVertexBuffer(cmd, 1, &pSkyBoxVertexBuffer, &skyboxVbStride, null);
	ZtfGfx.ztf_cmdDraw(cmd, 36, 0);
	ZtfGfx.ztf_cmdSetViewport(cmd, 0.0, 0.0, @floatFromInt(rtarget_width), @floatFromInt(rtarget_height), 0.0, 1.0);
	ZtfProfiler.ztf_cmdEndGpuTimestampQuery(@ptrCast(cmd), gGpuProfileToken);

	_ = ZtfProfiler.ztf_cmdBeginGpuTimestampQuery(@ptrCast(cmd), gGpuProfileToken, "Draw Planets", true);

	ZtfGfx.ztf_cmdBindPipeline(cmd, pSpherePipeline);
	ZtfGfx.ztf_cmdBindDescriptorSet(cmd, gFrameIndex * 2 + 1, pDescriptorSetUniforms);
	ZtfGfx.ztf_cmdBindVertexBuffer(cmd, 1, &pSphereVertexBuffer, &gSphereVertexLayout.mBindings[0].mStride, null);
	ZtfGfx.ztf_cmdBindIndexBuffer(cmd, pSphereIndexBuffer, ZtfGfx.ZTF_INDEX_TYPE_UINT16, 0);

	ZtfGfx.ztf_cmdDrawIndexedInstanced(cmd, gSphereIndexCount, 0, gNumPlanets, 0, 0);
	ZtfProfiler.ztf_cmdEndGpuTimestampQuery(@ptrCast(cmd), gGpuProfileToken);
	ZtfProfiler.ztf_cmdEndGpuTimestampQuery(@ptrCast(cmd), gGpuProfileToken); // Draw Skybox/Planets
	ZtfGfx.ztf_cmdBindRenderTargets(cmd, null);

	if (pipelineStatsQueries != 0)
	{
		var queryDesc = ZtfGfx.ztf_QueryDesc{ .mIndex = 0 };
		ZtfGfx.ztf_cmdEndQuery(cmd, pPipelineStatsQueryPool[gFrameIndex], &queryDesc);
		//queryDesc.mIndex = 1;
		//ZtfGfx.ztf_cmdBeginQuery(cmd, pPipelineStatsQueryPool[gFrameIndex], &queryDesc);
	}

	ZtfGfx.ztf_cmdBindRenderTargets(cmd, null);

	barriers[0] = ZtfGfx.ztf_RenderTargetBarrier{
			.pRenderTarget = pRenderTarget,
			.mCurrentState = ZtfGfx.ZTF_RESOURCE_STATE_RENDER_TARGET,
			.mNewState = ZtfGfx.ZTF_RESOURCE_STATE_PRESENT,
	};
	ZtfGfx.ztf_cmdResourceBarrier(cmd, 0, null, 0, null, 1, &barriers);

	ZtfProfiler.ztf_cmdEndGpuFrameProfile(@ptrCast(cmd), gGpuProfileToken);

	ZtfGfx.ztf_endCmd(cmd);

	var flushUpdateDesc = ZtfRL.ztf_FlushResourceUpdateDesc{};
	flushUpdateDesc.mNodeIndex = 0;
	ZtfRL.ztf_flushResourceUpdates(&flushUpdateDesc);
	var waitSemaphores = [2][*c]ZtfGfx.ztf_Semaphore{ @ptrCast(flushUpdateDesc.pOutSubmittedSemaphore), pImageAcquiredSemaphore };
	_ = &waitSemaphores;

	var submitDesc = ZtfGfx.ztf_QueueSubmitDesc{};
	submitDesc.mCmdCount = 1;
	submitDesc.mSignalSemaphoreCount = 1;
	submitDesc.mWaitSemaphoreCount = waitSemaphores.len;
	submitDesc.ppCmds = @constCast(&cmd);
	submitDesc.ppSignalSemaphores = @constCast(&elem.pSemaphore);
	submitDesc.ppWaitSemaphores =  @constCast(&waitSemaphores);
	submitDesc.pSignalFence = elem.pFence;
	ZtfGfx.ztf_queueSubmit(pGraphicsQueue, &submitDesc);

	var presentDesc = ZtfGfx.ztf_QueuePresentDesc{};
	presentDesc.mIndex = @intCast(swapchainImageIndex);
	presentDesc.mWaitSemaphoreCount = 1;
	presentDesc.pSwapChain = pSwapChain;
	presentDesc.ppWaitSemaphores = @constCast(&elem.pSemaphore);
	presentDesc.mSubmitDone = true;

	ZtfGfx.ztf_queuePresent(pGraphicsQueue, &presentDesc);
	ZtfProfiler.ztf_flipProfiler();

	gFrameIndex = (gFrameIndex + 1) % gDataBufferCount;
}

pub export fn ztf_appGetName(_: ?*ztf_App) callconv(.C) [*c]const u8
{
	return "01_TransformationsZig";
}

pub extern fn main(argc: c_int, argv: **const c_char) c_int;

pub fn compute_normal(src : [*c]f32, dst : [*c]f32) void
{
    const len = std.zig.c_builtins.__builtin_sqrtf(src[0] * src[0] + src[1] * src[1] + src[2] * src[2]);
    if (len == 0)
    {
        dst[0] = 0;
        dst[1] = 0;
        dst[2] = 0;
    }
    else
    {
        dst[0] = src[0] / len;
        dst[1] = src[1] / len;
        dst[2] = src[2] / len;
    }
}

pub fn generate_complex_mesh() void
{
	gSphereVertexLayout = .{};

	// number of vertices on a quad side, must be >= 2
	const DETAIL_LEVEL : comptime_int = 64;

    // static here to prevent stack overflow
	const static = struct {
		const float_bufftype = [6][DETAIL_LEVEL][DETAIL_LEVEL][3]f32;
		const color_bufftype = [6][DETAIL_LEVEL][DETAIL_LEVEL][3]u8;
		const indices_bufftype = [6][DETAIL_LEVEL - 1][DETAIL_LEVEL - 1][6]u16;
		var verts : float_bufftype = std.mem.zeroes(float_bufftype);
		var sqNormals : float_bufftype = std.mem.zeroes(float_bufftype);
		var sphNormals : float_bufftype = std.mem.zeroes(float_bufftype);	
		var sqColors : color_bufftype = std.mem.zeroes(color_bufftype);
		var spColors : color_bufftype = std.mem.zeroes(color_bufftype);
		var indices : indices_bufftype = std.mem.zeroes(indices_bufftype);

		pub fn vid(vx: usize, vy: usize, o: usize) usize
		{
			return (o + (vx)*DETAIL_LEVEL + (vy));
		}
	};

    for (0..6) |i|
    {
        for (0..DETAIL_LEVEL) |x|
        {
            for (0..DETAIL_LEVEL) |y|
            {
                var vert = &static.verts[i][x][y];
                var sqNorm = &static.sqNormals[i][x][y];

                sqNorm[0] = 0;
                sqNorm[1] = 0;
                sqNorm[2] = 0;

                const fx = 2 * (@as(f32, @floatFromInt(x)) / @as(f32, @floatFromInt(DETAIL_LEVEL - 1))) - 1;
                const fy = 2 * (@as(f32, @floatFromInt(y)) / @as(f32,  @floatFromInt(DETAIL_LEVEL - 1))) - 1;

                switch (i)
                {
                	0 => {
						vert[0] = -1;
						vert[1] = fx;
						vert[2] = fy;
						sqNorm[0] = -1;
					},
                	1 => {
						vert[0] = 1;
						vert[1] = -fx;
						vert[2] = fy;
						sqNorm[0] = 1;
					},
					2 => {
						vert[0] = -fx;
						vert[1] = fy;
						vert[2] = 1;
						sqNorm[0] = 1;
					},
					3 => {
						vert[0] = fx;
						vert[1] = fy;
						vert[2] = -1;
						sqNorm[0] = -1;
					},
					4 => {
						vert[0] = fx;
						vert[1] = 1;
						vert[2] = fy;
						sqNorm[0] = 1;
					},
					5 => {
						vert[0] = -fx;
						vert[1] = -1;
						vert[2] = fy;
						sqNorm[0] = -1;
					},
					else => unreachable,
                }

                compute_normal(&vert[0], &static.sphNormals[i][x][y][0]);
            }
        }
    }

	var rand_impl = std.Random.DefaultPrng.init(0);

    for (0..6) |i|
    {
        for (0..DETAIL_LEVEL) |x|
        {
            const spColorTemplate = [3]u8{
                rand_impl.random().int(u8),
                rand_impl.random().int(u8),
                rand_impl.random().int(u8),
            };

            const rx = 1 - zmath.abs((@as(f32, @floatFromInt(x)) / DETAIL_LEVEL) * 2 - 1);

            for (0..DETAIL_LEVEL) |y|
            {
                const ry = 1 - zmath.abs((@as(f32, @floatFromInt(y)) / DETAIL_LEVEL) * 2 - 1);
                const close_ratio : u32 = @intFromFloat(rx * ry * 255);

                var sq_color : []u8 = &static.sqColors[i][x][y];
                var sp_color : []u8 = &static.spColors[i][x][y];

                sq_color[0] = @intCast((rand_impl.random().int(u8) * close_ratio) / 255);
                sq_color[1] = @intCast((rand_impl.random().int(u8) * close_ratio) / 255);
                sq_color[2] = @intCast((rand_impl.random().int(u8) * close_ratio) / 255);

                sp_color[0] = @intCast((spColorTemplate[0] * close_ratio) / 255);
                sp_color[1] = @intCast((spColorTemplate[1] * close_ratio) / 255);
                sp_color[2] = @intCast((spColorTemplate[2] * close_ratio) / 255);
            }
        }
    }

    for (0..6) |i|
    {
        const o = DETAIL_LEVEL * DETAIL_LEVEL * i;
        for (0..DETAIL_LEVEL-1) |x|
        {
            for (0..DETAIL_LEVEL-1) |y|
            {
                const quadIndices : []u16 = &static.indices[i][x][y];

                quadIndices[0] = @truncate(static.vid(x, y, o));
                quadIndices[1] = @truncate(static.vid(x, y + 1, o));
                quadIndices[2] = @truncate(static.vid(x + 1, y + 1, o));
                quadIndices[3] = @truncate(static.vid(x + 1, y + 1, o));
                quadIndices[4] = @truncate(static.vid(x + 1, y, o));
                quadIndices[5] = @truncate(static.vid(x, y, o));
            }
        }
    }

	var bufferData : []u8 = undefined;
	const vertexCount : u32 = @sizeOf(@TypeOf(static.verts)) / 12;
	var bufferSize : usize = undefined;

	gSphereVertexLayout.mBindingCount = 1;

	switch (gSphereLayoutType)
	{
		1 =>
		{
			//  0-12 sq positions,
			// 16-28 sq normals
			// 32-34 sq colors
			// 36-40 sp colors
			// 48-62 sp positions
			// 64-76 sp normals

			gSphereVertexLayout.mBindings[0].mStride = 80;
			const vsize : usize = vertexCount * gSphereVertexLayout.mBindings[0].mStride;
			bufferSize = vsize;
			bufferData = global_alloc.alloc(u8, bufferSize) catch |err| @panic(@errorName(err));

			add_attribute(&gSphereVertexLayout, ZtfGfx.ZTF_SEMANTIC_POSITION, ZtfGfx.TinyImageFormat_R32G32B32_SFLOAT, 0);
			add_attribute(&gSphereVertexLayout, ZtfGfx.ZTF_SEMANTIC_NORMAL, ZtfGfx.TinyImageFormat_R32G32B32_SFLOAT, 16);
			add_attribute(&gSphereVertexLayout, ZtfGfx.ZTF_SEMANTIC_TEXCOORD1, ZtfGfx.TinyImageFormat_R32G32B32_SFLOAT, 48);
			add_attribute(&gSphereVertexLayout, ZtfGfx.ZTF_SEMANTIC_TEXCOORD3, ZtfGfx.TinyImageFormat_R32G32B32_SFLOAT, 64);
			add_attribute(&gSphereVertexLayout, ZtfGfx.ZTF_SEMANTIC_TEXCOORD0, ZtfGfx.TinyImageFormat_R8G8B8A8_UNORM, 32);
			add_attribute(&gSphereVertexLayout, ZtfGfx.ZTF_SEMANTIC_TEXCOORD2, ZtfGfx.TinyImageFormat_R8G8B8A8_UNORM, 36);

			copy_attribute(&gSphereVertexLayout, @ptrCast(bufferData.ptr), 0, 12, vertexCount, @ptrCast(&static.verts));
			copy_attribute(&gSphereVertexLayout, @ptrCast(bufferData.ptr), 16, 12, vertexCount, @ptrCast(&static.sqNormals));
			copy_attribute(&gSphereVertexLayout, @ptrCast(bufferData.ptr), 36, 3, vertexCount, @ptrCast(&static.spColors));
			copy_attribute(&gSphereVertexLayout, @ptrCast(bufferData.ptr), 32, 3, vertexCount, @ptrCast(&static.sqColors));
			copy_attribute(&gSphereVertexLayout, @ptrCast(bufferData.ptr), 48, 12, vertexCount, @ptrCast(&static.sphNormals));
			copy_attribute(&gSphereVertexLayout, @ptrCast(bufferData.ptr), 64, 12, vertexCount, @ptrCast(&static.sphNormals));
		},
		else =>
		{
			//  0-12 sq positions,
			// 12-16 sq colors
			// 16-28 sq normals
			// 28-32 sp colors
			// 32-44 sp positions + sp normals

			gSphereVertexLayout.mBindings[0].mStride = 44;
			const vsize : usize = vertexCount * gSphereVertexLayout.mBindings[0].mStride;
			bufferSize = vsize;
			bufferData =  global_alloc.alloc(u8, bufferSize) catch |err| @panic(@errorName(err));

			add_attribute(&gSphereVertexLayout, ZtfGfx.ZTF_SEMANTIC_POSITION, ZtfGfx.TinyImageFormat_R32G32B32_SFLOAT, 0);
			add_attribute(&gSphereVertexLayout, ZtfGfx.ZTF_SEMANTIC_NORMAL, ZtfGfx.TinyImageFormat_R32G32B32_SFLOAT, 16);
			add_attribute(&gSphereVertexLayout, ZtfGfx.ZTF_SEMANTIC_TEXCOORD1, ZtfGfx.TinyImageFormat_R32G32B32_SFLOAT, 32);
			add_attribute(&gSphereVertexLayout, ZtfGfx.ZTF_SEMANTIC_TEXCOORD3, ZtfGfx.TinyImageFormat_R32G32B32_SFLOAT, 32);
			add_attribute(&gSphereVertexLayout, ZtfGfx.ZTF_SEMANTIC_TEXCOORD0, ZtfGfx.TinyImageFormat_R8G8B8A8_UNORM, 12);
			add_attribute(&gSphereVertexLayout, ZtfGfx.ZTF_SEMANTIC_TEXCOORD2, ZtfGfx.TinyImageFormat_R8G8B8A8_UNORM, 28);

			copy_attribute(&gSphereVertexLayout, @ptrCast(bufferData.ptr), 0, 12, vertexCount, @ptrCast(&static.verts));
			copy_attribute(&gSphereVertexLayout, @ptrCast(bufferData.ptr), 12, 3, vertexCount, @ptrCast(&static.sqColors));
			copy_attribute(&gSphereVertexLayout, @ptrCast(bufferData.ptr), 16, 12, vertexCount, @ptrCast(&static.sqNormals));
			copy_attribute(&gSphereVertexLayout, @ptrCast(bufferData.ptr), 28, 3, vertexCount, @ptrCast(&static.spColors));
			copy_attribute(&gSphereVertexLayout, @ptrCast(bufferData.ptr), 32, 12, vertexCount, @ptrCast(&static.sphNormals));
		},
	}

	gSphereIndexCount = @sizeOf(@TypeOf(static.indices)) / @sizeOf(u16);

	const sphereVbDesc = ZtfRL.ztf_BufferLoadDesc{
		.mDesc = .{
			.mDescriptors = ZtfRL.ZTF_DESCRIPTOR_TYPE_VERTEX_BUFFER,
			.mMemoryUsage = ZtfRL.ZTF_RESOURCE_MEMORY_USAGE_GPU_ONLY,
			.mSize = bufferSize,
		},
		.pData = bufferData.ptr,
		.ppBuffer = @ptrCast(&pSphereVertexBuffer),
	};
	ZtfRL.ztf_addResource(@constCast(&sphereVbDesc), null);

	const sphereIbDesc = ZtfRL.ztf_BufferLoadDesc{
		.mDesc = .{
			.mDescriptors = ZtfRL.ZTF_DESCRIPTOR_TYPE_INDEX_BUFFER,
			.mMemoryUsage = ZtfRL.ZTF_RESOURCE_MEMORY_USAGE_GPU_ONLY,
			.mSize = @sizeOf(@TypeOf(static.indices)),
		},
		.pData = bufferData.ptr,
		.ppBuffer = @ptrCast(&pSphereIndexBuffer),
	};
	ZtfRL.ztf_addResource(@constCast(&sphereIbDesc), null);

	ZtfRL.ztf_waitForAllResourceLoads();

	global_alloc.free(bufferData);
}

pub fn add_attribute(layout: *ZtfGfx.ztf_VertexLayout, semantic: ZtfGfx.ztf_ShaderSemantic, format: ZtfGfx.TinyImageFormat, offset: u32) void
{
    const n_attr = layout.*.mAttribCount;
	layout.*.mAttribCount += 1;

    const attr : *ZtfGfx.ztf_VertexAttrib = &(layout.*.mAttribs[n_attr]);

    attr.*.mSemantic = semantic;
    attr.*.mFormat = format;
    attr.*.mBinding = 0;
    attr.*.mLocation = n_attr;
    attr.*.mOffset = offset;
}

pub fn copy_attribute(layout: *ZtfGfx.ztf_VertexLayout, buffer_data: *void, offset: u32, size: u32, vcount: u32, data: *void) void
{
    var dst_data : [*c]u8 = @ptrCast(buffer_data);
    var src_data : [*c]u8 = @ptrCast(data);
    for (0..vcount) |_|
    {
        _ = std.zig.c_builtins.__builtin_memcpy(dst_data + offset, src_data, size);
        dst_data += layout.*.mBindings[0].mStride;
        src_data += size;
    }
}

//pub fn main() !void {
//	const mybuf = RingBuffer.GPURingBuffer
//	{
//		.pRenderer = null,
//    	.pBuffer = null,
//    	.mBufferAlignment = 0,
//    	.mMaxBufferSize = 0,
//    	.mCurrentBufferOffset = 0,
//	};
//	_ = &mybuf;
//}