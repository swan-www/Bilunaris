const std = @import("std");
const RndGen = std.rand.DefaultPrng;

const Ztf = @import("ztf");
const LunRender = @import("lun_render");
const RingBuffer = LunRender.ringbuffer;
const ZtfExt = @import("ztf_ext");

const MAX_PLANETS = 20;

var gpa : std.heap.GeneralPurposeAllocator(.{.safety = true, .thread_safe = true}) = undefined;
var global_alloc : std.mem.Allocator = undefined;

const PlanetInfoStruct = struct
{
	mTranslationMat : Ztf.ztf_Matrix4 = std.mem.zeroes(Ztf.ztf_Matrix4),
    mScaleMat : Ztf.ztf_Matrix4 = std.mem.zeroes(Ztf.ztf_Matrix4),
    mSharedMat : Ztf.ztf_Matrix4 = std.mem.zeroes(Ztf.ztf_Matrix4), // Matrix to pass down to children
	mColor : Ztf.ztf_Vector4 = std.mem.zeroes(Ztf.ztf_Vector4),
	mParentIndex : u32 = 0,
    mYOrbitSpeed : f32 = 0.0, // Rotation speed around parent
    mZOrbitSpeed : f32 = 0.0,
    mRotationSpeed : f32 = 0.0, // Rotation speed around self
    mMorphingSpeed : f32 = 0.0, // Speed of morphing betwee cube and sphere
};

const UniformBlock_C = extern struct
{
    mProjectView : Ztf.ZTF_CameraMatrix = std.mem.zeroes(Ztf.ZTF_CameraMatrix),
    mToWorldMat : [MAX_PLANETS]Ztf.ztf_Matrix4 = std.mem.zeroes([MAX_PLANETS]Ztf.ztf_Matrix4),
    mColor : [MAX_PLANETS]Ztf.ztf_Vector4 = std.mem.zeroes([MAX_PLANETS]Ztf.ztf_Vector4),
    //mGeometryWeight : [MAX_PLANETS]Ztf.ztf_Float4 = std.mem.zeroes([MAX_PLANETS]Ztf.ztf_Float4),
	mGeometryWeight : [MAX_PLANETS][4]f32 = std.mem.zeroes([MAX_PLANETS][4]f32),

    // Point Light Information
    mLightPosition : Ztf.ztf_Vector3 = std.mem.zeroes(Ztf.ztf_Vector3),
    mLightColor :Ztf.ztf_Vector3 = std.mem.zeroes(Ztf.ztf_Vector3),
};

const UniformBlockSky_C = extern struct
{
	mProjectView : Ztf.ZTF_CameraMatrix = std.mem.zeroes(Ztf.ZTF_CameraMatrix),
};

// But we only need Two sets of resources (one in flight and one being used on CPU)
const gDataBufferCount : u32 = 2;
const gNumPlanets : c_uint = 11;     // Sun, Mercury -> Neptune, Pluto, Moon
const gTimeOffset : c_uint = 600000; // For visually better starting locations
const gRotSelfScale : f32 = 0.0004;
const gRotOrbitYScale : f32 = 0.001;
const gRotOrbitZScale : f32 = 0.00001;

var GPURingBuffer = RingBuffer.GPURingBuffer{};

var pRenderer : *Ztf.ztf_Renderer = undefined;
var pRendererOpt : ?*Ztf.ztf_Renderer = null;

var pGraphicsQueue : ?*Ztf.ztf_Queue = null;
var gGraphicsCmdRing = RingBuffer.GpuCmdRing{};

var pSwapChain : ?*Ztf.ztf_SwapChain = null;
var pDepthBuffer : ?*Ztf.ztf_RenderTarget = null;
var pImageAcquiredSemaphore : ?*Ztf.ztf_Semaphore = null;

var pSphereShader : ?*Ztf.ztf_Shader = null;
var pSphereVertexBuffer : ?*Ztf.ztf_Buffer = null;
var pSphereIndexBuffer : ?*Ztf.ztf_Buffer = null;
var gSphereIndexCount : u32 = 0;
var pSpherePipeline : ?*Ztf.ztf_Pipeline = null;
var gSphereVertexLayout = Ztf.ztf_VertexLayout{};
var gSphereLayoutType : u32 = 0;

var pSkyBoxDrawShader : ?*Ztf.ztf_Shader = null;
var pSkyBoxVertexBuffer : ?*Ztf.ztf_Buffer = null;
var pSkyBoxDrawPipeline : ?*Ztf.ztf_Pipeline = null;
var pRootSignature : ?*Ztf.ztf_RootSignature = null;
var pSamplerSkyBox : ?*Ztf.ztf_Sampler = null;
var pSkyBoxTextures : [6]?*Ztf.ztf_Texture = [_]?*Ztf.ztf_Texture{null} ** 6;
var pDescriptorSetTexture : ?*Ztf.ztf_DescriptorSet = null;
var pDescriptorSetUniforms : ?*Ztf.ztf_DescriptorSet = null;

var pProjViewUniformBuffer : [gDataBufferCount]?*Ztf.ztf_Buffer = [_]?*Ztf.ztf_Buffer{null} ** gDataBufferCount;
var pSkyboxUniformBuffer : [gDataBufferCount]?*Ztf.ztf_Buffer = [_]?*Ztf.ztf_Buffer{null} ** gDataBufferCount;

var gFrameIndex : u32 = 0;
var gGpuProfileToken : Ztf.ztf_ProfileToken = Ztf.ZTF_PROFILE_INVALID_TOKEN;

var gNumberOfSpherePoints : i32 = 0;
var gUniformData = UniformBlock_C{};
var gUniformDataSky = UniformBlockSky_C{};
var gPlanetInfoData : [gNumPlanets]PlanetInfoStruct = .{PlanetInfoStruct{}} ** gNumPlanets;

var pCameraController : ?*Ztf.ICameraController = null;

var pGuiWindow : ?*Ztf.ztf_UIComponent = null;

var gFontID : u32 = 0;

var pPipelineStatsQueryPool : [gDataBufferCount]?*Ztf.ztf_QueryPool = [_]?*Ztf.ztf_QueryPool{null} ** gDataBufferCount;

const pSkyBoxImageFileNames = [_][]const u8{ "Skybox_right1.tex",  "Skybox_left2.tex",  "Skybox_top3.tex",
                                        "Skybox_bottom4.tex", "Skybox_front5.tex", "Skybox_back6.tex" };

var gFrameTimeDraw = Ztf.ztf_FontDrawDesc{};

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
var gPipelineStats : Ztf.bstring = undefined;

const gWindowTestScripts : [][]const u8 = .{ "TestFullScreen.lua", "TestCenteredWindow.lua", "TestNonCenteredWindow.lua", "TestBorderless.lua" };

fn reloadRequest(_ : ?*anyopaque) callconv(.C) void
{
    const reload = Ztf.ztf_ReloadDesc{ .mType = Ztf.ZTF_RELOAD_TYPE_SHADER };
    Ztf.ztf_requestReload(&reload);
}

pub export fn ztf_appInit(pApp: ?*Ztf.ztf_App) callconv(.C) bool
{
	gpa = .{};
    global_alloc = gpa.allocator();

	const window_desc = Ztf.ztf_getWindowDesc(pApp);
	ZtfExt.init(null);
	ZtfExt.LOGF(Ztf.ztf_eINFO, "ztf_appInit", .{});

	const pSystemFileIO = Ztf.ztf_getSystemFileIO();
	Ztf.ztf_fsSetPathForResourceDir(pSystemFileIO, Ztf.ZTF_RM_CONTENT, Ztf.ZTF_RD_SHADER_BINARIES, "CompiledShaders");
	Ztf.ztf_fsSetPathForResourceDir(pSystemFileIO, Ztf.ZTF_RM_CONTENT, Ztf.ZTF_RD_TEXTURES, "Textures");
	Ztf.ztf_fsSetPathForResourceDir(pSystemFileIO, Ztf.ZTF_RM_CONTENT, Ztf.ZTF_RD_FONTS, "Fonts");
	Ztf.ztf_fsSetPathForResourceDir(pSystemFileIO, Ztf.ZTF_RM_DEBUG, Ztf.ZTF_RD_SCREENSHOTS, "Screenshots");
	Ztf.ztf_fsSetPathForResourceDir(pSystemFileIO, Ztf.ZTF_RM_CONTENT, Ztf.ZTF_RD_SCRIPTS, "Scripts");
	Ztf.ztf_fsSetPathForResourceDir(pSystemFileIO, Ztf.ZTF_RM_DEBUG, Ztf.ZTF_RD_DEBUG, "Debug");

	const settings = Ztf.ztf_RendererDesc{
		.mD3D11Supported = true,
		.mGLESSupported = true,
	};

	Ztf.ztf_initRenderer(ztf_appGetName(pApp), &settings, &pRendererOpt);

	if(pRendererOpt == null)
	{
		ZtfExt.LOGF(Ztf.ztf_eERROR, "Renderer failed to initialise.", .{});
		return false;
	}
	pRenderer = pRendererOpt.?;

	if (Ztf.ztf_getGPUSettings_mPipelineStatsQueries(&pRenderer.*.pGpu.*.mSettings) != 0)
	{
		const poolDesc = Ztf.ztf_QueryPoolDesc{
			.mQueryCount = 3,
			.mType = Ztf.ZTF_QUERY_TYPE_PIPELINE_STATISTICS,
		};
		for (0..gDataBufferCount) |i| {
			Ztf.ztf_addQueryPool(pRenderer, &poolDesc, &pPipelineStatsQueryPool[i]);
		}
	}

	var queue_desc = Ztf.ztf_QueueDesc{
		.mType = Ztf.ZTF_QUEUE_TYPE_GRAPHICS,
		.mFlag = Ztf.ZTF_QUEUE_FLAG_INIT_MICROPROFILE,
	};
	Ztf.ztf_addQueue(pRenderer,  &queue_desc, @ptrCast(&pGraphicsQueue));

	const cmd_ring_desc = RingBuffer.GPUCmdRingDesc{
		.pQueue = pGraphicsQueue,
		.mPoolCount = gDataBufferCount,
		.mCmdPerPoolCount = 1,
		.mAddSyncPrimitives = true,
	};
	RingBuffer.addGpuCmdRing(pRenderer, &cmd_ring_desc, &gGraphicsCmdRing) catch |err| @panic(@errorName(err));

	Ztf.ztf_addSemaphore(pRenderer, &pImageAcquiredSemaphore);
	Ztf.ztf_initResourceLoaderInterface(@ptrCast(pRenderer), null);

	//Skybox textures
	for(0..6) |i|
	{
		var textureDesc = Ztf.ztf_TextureLoadDesc{
			.pFileName = @ptrCast(pSkyBoxImageFileNames[i]),
			.ppTexture = @ptrCast(&pSkyBoxTextures[i]),
			// Textures representing color should be stored in SRGB or HDR format
			.mCreationFlag = Ztf.ZTF_TEXTURE_CREATION_FLAG_SRGB,
		};
		_ = &textureDesc;
		Ztf.ztf_addResource2(&textureDesc, null);
	}

	//Sampler
	const samplerDesc = Ztf.ztf_SamplerDesc{
		.mMinFilter = Ztf.ZTF_FILTER_LINEAR,
		.mMagFilter = Ztf.ZTF_FILTER_LINEAR,
		.mMipMapMode = Ztf.ZTF_MIPMAP_MODE_NEAREST,
		.mAddressU = Ztf.ZTF_ADDRESS_MODE_CLAMP_TO_EDGE,
		.mAddressV = Ztf.ZTF_ADDRESS_MODE_CLAMP_TO_EDGE,
		.mAddressW = Ztf.ZTF_ADDRESS_MODE_CLAMP_TO_EDGE,
	};
	Ztf.ztf_addSampler(pRenderer, &samplerDesc, &pSamplerSkyBox);

	//Skybox Vertex Buffer
	const skyBoxDataSize : u64 = 4 * 6 * 6 * @sizeOf(f32);
	var skyboxVbDesc = Ztf.ztf_BufferLoadDesc{
		.mDesc = .{
			.mDescriptors = Ztf.ZTF_DESCRIPTOR_TYPE_VERTEX_BUFFER,
			.mMemoryUsage = Ztf.ZTF_RESOURCE_MEMORY_USAGE_GPU_ONLY,
			.mSize = skyBoxDataSize,
		},
		.pData = &gSkyBoxPoints,
		.ppBuffer = @ptrCast(&pSkyBoxVertexBuffer),
	};
	Ztf.ztf_addResource(@ptrCast(&skyboxVbDesc), null);

	//Uniform Buffers
	var ubDesc = Ztf.ztf_BufferLoadDesc{
		.mDesc = .{
			.mDescriptors = Ztf.ZTF_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
			.mMemoryUsage = Ztf.ZTF_RESOURCE_MEMORY_USAGE_CPU_TO_GPU,
			.mFlags = Ztf.ZTF_BUFFER_CREATION_FLAG_PERSISTENT_MAP_BIT,
		},
		.pData = null,
	};
	for (0..gDataBufferCount) |i|
	{
		ubDesc.mDesc.pName = "ProjViewUniformBuffer";
		ubDesc.mDesc.mSize = @sizeOf(UniformBlock_C);
		ubDesc.ppBuffer = @ptrCast(&pProjViewUniformBuffer[i]);
		Ztf.ztf_addResource(&ubDesc, null);
		ubDesc.mDesc.pName = "SkyboxUniformBuffer";
		ubDesc.mDesc.mSize = @sizeOf(UniformBlockSky_C);
		ubDesc.ppBuffer = @ptrCast(&pSkyboxUniformBuffer[i]);
		Ztf.ztf_addResource(&ubDesc, null);
	}

	// Load fonts
	var font : Ztf.ztf_FontDesc = Ztf.ztf_getDefaultFontDesc();
	font.pFontPath = "TitilliumText/TitilliumText-Bold.otf";
	Ztf.ztf_fntDefineFonts(&font, 1, &gFontID);

	//Font System
	var fontSystemDesc : Ztf.ztf_FontSystemDesc = Ztf.ztf_getDefaultFontSystemDesc();
	fontSystemDesc.pRenderer = @ptrCast(pRenderer);
	if (!Ztf.ztf_initFontSystem(&fontSystemDesc))
	{
		ZtfExt.LOGF(Ztf.ztf_eERROR, "Font System failed to initialise.", .{});
		return false;
	}

	// Initialize Forge User Interface Rendering
	var uiRenderDesc = Ztf.ztf_defaultInitUserInterfaceDesc();
	uiRenderDesc.pRenderer = @ptrCast(pRenderer);
	Ztf.ztf_initUserInterface(&uiRenderDesc);

 	// Initialize micro profiler and its UI.
	const app_settings = Ztf.ztf_getAppSettings(pApp);
	var profiler = Ztf.ztf_ProfilerDesc{
		.pRenderer = @ptrCast(pRenderer),
		.mWidthUI = @intCast(app_settings.*.mWidth),
		.mHeightUI = @intCast(app_settings.*.mHeight),
	};
	Ztf.ztf_initProfiler(&profiler);
	gGpuProfileToken = Ztf.ztf_addGpuProfiler(@ptrCast(pRenderer), @ptrCast(pGraphicsQueue), "Graphics");

	// GUI
	var guiDesc = Ztf.ztf_UIComponentDesc{};
	Ztf.ztf_defaultInitUIComponentDesc(&guiDesc);
	guiDesc.mStartPosition = Ztf.ztf_Float2{.x = @as(f32, @floatFromInt(app_settings.*.mWidth)) * 0.01, .y = @as(f32, @floatFromInt(app_settings.*.mHeight)) * 0.2};
	Ztf.ztf_uiCreateComponent(ztf_appGetName(pApp), &guiDesc, &pGuiWindow);

	var vertexLayoutWidget = Ztf.ztf_SliderUintWidget{};
	Ztf.ztf_defaultInitSliderUintWidget(&vertexLayoutWidget);
	vertexLayoutWidget.mMin = 0;
	vertexLayoutWidget.mMax = 1;
	vertexLayoutWidget.mStep = 1;
	vertexLayoutWidget.pData = &gSphereLayoutType;

	const pVLw = Ztf.ztf_uiCreateComponentWidget(pGuiWindow, "Vertex Layout", &vertexLayoutWidget, Ztf.ZTF_WIDGET_TYPE_SLIDER_UINT, true);
	Ztf.ztf_uiSetWidgetOnEditedCallback(pVLw, null, reloadRequest);

	const staticLocal = struct
	{
		var color = Ztf.ztf_Float4{ .x = 1.0, .y = 1.0, .z = 1.0, .w = 1.0 };
	};

	gPipelineStats = ZtfExt.bfromarr(gPipelineStatsCharArraySlice);

	if (Ztf.ztf_getGPUSettings_mPipelineStatsQueries(&pRenderer.*.pGpu.*.mSettings) != 0)
	{
		const statsWidget = Ztf.ztf_DynamicTextWidget
		{
			.pText = @ptrCast(&gPipelineStats),
			.pColor = @ptrCast(&staticLocal.color),
		};
		_ = Ztf.ztf_uiCreateComponentWidget(pGuiWindow, "Pipeline Stats", &statsWidget,  Ztf.ZTF_WIDGET_TYPE_DYNAMIC_TEXT, true);
	}

	Ztf.ztf_waitForAllResourceLoads();

	// Setup planets (Rotation speeds are relative to Earth's, some values randomly given)
	// Sun
	gPlanetInfoData[0].mParentIndex = 0;
	gPlanetInfoData[0].mYOrbitSpeed = 0.0; // Earth years for one orbit
	gPlanetInfoData[0].mZOrbitSpeed = 0.0;
	gPlanetInfoData[0].mRotationSpeed = 24.0; // Earth days for one rotation
	gPlanetInfoData[0].mTranslationMat = Ztf.mat4_identity();
	var scale = Ztf.make_vec3(10.0, 10.0, 10.0);
	gPlanetInfoData[0].mScaleMat = Ztf.mat4_from_scale(&scale);
	gPlanetInfoData[0].mColor = Ztf.make_vec4(0.97, 0.38, 0.09, 0.0);
	gPlanetInfoData[0].mMorphingSpeed = 0.2;

	// Mercury
	gPlanetInfoData[1].mParentIndex = 0;
	gPlanetInfoData[1].mYOrbitSpeed = 0.5;
	gPlanetInfoData[1].mZOrbitSpeed = 0.0;
	gPlanetInfoData[1].mRotationSpeed = 58.7;
	gPlanetInfoData[1].mTranslationMat = Ztf.mat4_identity();
	var translation = Ztf.make_vec3(10.0, 0.0, 0.0);
	Ztf.mat4_set_translation(&gPlanetInfoData[1].mTranslationMat, &translation);
	scale = Ztf.make_vec3(1.0, 1.0, 1.0);
	gPlanetInfoData[1].mScaleMat = Ztf.mat4_from_scale(&scale);
	gPlanetInfoData[1].mColor =Ztf.make_vec4(0.45, 0.07, 0.006, 1.0);
	gPlanetInfoData[1].mMorphingSpeed = 5.0;

	// Venus
	gPlanetInfoData[2].mParentIndex = 0;
	gPlanetInfoData[2].mYOrbitSpeed = 0.8;
	gPlanetInfoData[2].mZOrbitSpeed = 0.0;
	gPlanetInfoData[2].mRotationSpeed = 243.0;
	gPlanetInfoData[2].mTranslationMat = Ztf.mat4_identity();
	translation = Ztf.make_vec3(20.0, 0.0, 5.0);
	Ztf.mat4_set_translation(&gPlanetInfoData[2].mTranslationMat, &translation);
	scale = Ztf.make_vec3(2.0, 2.0, 2.0);
	gPlanetInfoData[2].mScaleMat = Ztf.mat4_from_scale(&scale);
	gPlanetInfoData[2].mColor = Ztf.make_vec4(0.6, 0.32, 0.006, 1.0);
	gPlanetInfoData[2].mMorphingSpeed = 1.0;

	// Earth
	gPlanetInfoData[3].mParentIndex = 0;
	gPlanetInfoData[3].mYOrbitSpeed = 1.0;
	gPlanetInfoData[3].mZOrbitSpeed = 0.0;
	gPlanetInfoData[3].mRotationSpeed = 1.0;
	gPlanetInfoData[3].mTranslationMat = Ztf.mat4_identity();
	translation = Ztf.make_vec3(30.0, 0.0, 0.0);
	Ztf.mat4_set_translation(&gPlanetInfoData[3].mTranslationMat, &translation);
	scale = Ztf.make_vec3(4.0, 4.0, 4.0);
	gPlanetInfoData[3].mScaleMat = Ztf.mat4_from_scale(&scale);
	gPlanetInfoData[3].mColor = Ztf.make_vec4(0.07, 0.028, 0.61, 1.0);
	gPlanetInfoData[3].mMorphingSpeed = 1.0;

	// Mars
	gPlanetInfoData[4].mParentIndex = 0;
	gPlanetInfoData[4].mYOrbitSpeed = 2.0;
	gPlanetInfoData[4].mZOrbitSpeed = 0.0;
	gPlanetInfoData[4].mRotationSpeed = 1.1;
	gPlanetInfoData[4].mTranslationMat = Ztf.mat4_identity();
	translation = Ztf.make_vec3(40.0, 0.0, 0.0);
	Ztf.mat4_set_translation(&gPlanetInfoData[4].mTranslationMat, &translation);
	scale = Ztf.make_vec3(3.0, 3.0, 3.0);
	gPlanetInfoData[4].mScaleMat = Ztf.mat4_from_scale(&scale);
	gPlanetInfoData[4].mColor = Ztf.make_vec4(0.79, 0.07, 0.006, 1.0);
	gPlanetInfoData[4].mMorphingSpeed = 1.0;

	// Jupiter
	gPlanetInfoData[5].mParentIndex = 0;
	gPlanetInfoData[5].mYOrbitSpeed = 11.0;
	gPlanetInfoData[5].mZOrbitSpeed = 0.0;
	gPlanetInfoData[5].mRotationSpeed = 0.4;
	gPlanetInfoData[5].mTranslationMat = Ztf.mat4_identity();
	translation = Ztf.make_vec3(50.0, 0.0, 0.0);
	Ztf.mat4_set_translation(&gPlanetInfoData[5].mTranslationMat, &translation);
	scale = Ztf.make_vec3(8.0, 8.0, 8.0);
	gPlanetInfoData[5].mScaleMat = Ztf.mat4_from_scale(&scale);
	gPlanetInfoData[5].mColor = Ztf.make_vec4(0.32, 0.13, 0.13, 1.0);
	gPlanetInfoData[5].mMorphingSpeed = 6.0;

	// Saturn
	gPlanetInfoData[6].mParentIndex = 0;
	gPlanetInfoData[6].mYOrbitSpeed = 29.4;
	gPlanetInfoData[6].mZOrbitSpeed = 0.0;
	gPlanetInfoData[6].mRotationSpeed = 0.5;
	gPlanetInfoData[6].mTranslationMat = Ztf.mat4_identity();
	translation = Ztf.make_vec3(60.0, 0.0, 0.0);
	Ztf.mat4_set_translation(&gPlanetInfoData[6].mTranslationMat, &translation);
	scale = Ztf.make_vec3(6.0, 6.0, 6.0);
	gPlanetInfoData[6].mScaleMat = Ztf.mat4_from_scale(&scale);
	gPlanetInfoData[6].mColor = Ztf.make_vec4(0.45, 0.45, 0.21, 1.0);
	gPlanetInfoData[6].mMorphingSpeed = 1.0;

	// Uranus
	gPlanetInfoData[7].mParentIndex = 0;
	gPlanetInfoData[7].mYOrbitSpeed = 84.07;
	gPlanetInfoData[7].mZOrbitSpeed = 0.0;
	gPlanetInfoData[7].mRotationSpeed = 0.8;
	gPlanetInfoData[7].mTranslationMat = Ztf.mat4_identity();
	translation = Ztf.make_vec3(70.0, 0.0, 0.0);
	Ztf.mat4_set_translation(&gPlanetInfoData[7].mTranslationMat, &translation);
	scale = Ztf.make_vec3(7.0, 7.0, 7.0);
	gPlanetInfoData[7].mScaleMat = Ztf.mat4_from_scale(&scale);
	gPlanetInfoData[7].mColor = Ztf.make_vec4(0.13, 0.13, 0.32, 1.0);
	gPlanetInfoData[7].mMorphingSpeed = 1.0;

	// Neptune
	gPlanetInfoData[8].mParentIndex = 0;
	gPlanetInfoData[8].mYOrbitSpeed = 164.81;
	gPlanetInfoData[8].mZOrbitSpeed = 0.0;
	gPlanetInfoData[8].mRotationSpeed = 0.9;
	gPlanetInfoData[8].mTranslationMat = Ztf.mat4_identity();
	translation = Ztf.make_vec3(80.0, 0.0, 0.0);
	Ztf.mat4_set_translation(&gPlanetInfoData[8].mTranslationMat, &translation);
	scale = Ztf.make_vec3(8.0, 8.0, 8.0);
	gPlanetInfoData[8].mScaleMat = Ztf.mat4_from_scale(&scale);
	gPlanetInfoData[8].mColor = Ztf.make_vec4(0.21, 0.028, 0.79, 1.0);
	gPlanetInfoData[8].mMorphingSpeed = 1.0;

	// Pluto - Not a planet XDD
	gPlanetInfoData[9].mParentIndex = 0;
	gPlanetInfoData[9].mYOrbitSpeed = 247.7;
	gPlanetInfoData[9].mZOrbitSpeed = 1.0;
	gPlanetInfoData[9].mRotationSpeed = 7.0;
	gPlanetInfoData[9].mTranslationMat = Ztf.mat4_identity();
	translation = Ztf.make_vec3(90.0, 0.0, 0.0);
	Ztf.mat4_set_translation(&gPlanetInfoData[9].mTranslationMat, &translation);
	scale = Ztf.make_vec3(1.0, 1.0, 1.0);
	gPlanetInfoData[9].mScaleMat = Ztf.mat4_from_scale(&scale);
	gPlanetInfoData[9].mColor = Ztf.make_vec4(0.45, 0.21, 0.21, 1.0);
	gPlanetInfoData[9].mMorphingSpeed = 1.0;

	// Moon
	gPlanetInfoData[10].mParentIndex = 3;
	gPlanetInfoData[10].mYOrbitSpeed = 1.0;
	gPlanetInfoData[10].mZOrbitSpeed = 200.0;
	gPlanetInfoData[10].mRotationSpeed = 27.0;
	gPlanetInfoData[10].mTranslationMat = Ztf.mat4_identity();
	translation = Ztf.make_vec3(5.0, 0.0, 0.0);
	Ztf.mat4_set_translation(&gPlanetInfoData[10].mTranslationMat, &translation);
	scale = Ztf.make_vec3(1.0, 1.0, 1.0);
	gPlanetInfoData[10].mScaleMat = Ztf.mat4_from_scale(&scale);
	gPlanetInfoData[10].mColor =Ztf.make_vec4(0.07, 0.07, 0.13, 1.0);
	gPlanetInfoData[10].mMorphingSpeed = 1.0;

	var cmp = Ztf.ztf_cameraMotionParameters_default();
	cmp.maxSpeed = 160.0;
	cmp.acceleration = 600.0;
	cmp.braking = 200.0;

	const camPos = Ztf.make_vec3( 48.0, 48.0, 20.0);
	const lookAt = Ztf.make_vec3( 0.0, 0.0, 0.0 );

	pCameraController = Ztf.ztf_initFpsCameraController(@ptrCast(&camPos), @ptrCast(&lookAt));
	Ztf.ztf_setMotionParameters(pCameraController, &cmp);

	//TODO input actions
	var inputDesc = Ztf.ztf_InputSystemDesc{
		.pRenderer = @ptrCast(pRenderer),
		.pWindow = @ptrCast(window_desc),
		.pJoystickTexture = "circlepad.tex",
	};
	if (!Ztf.ztf_initInputSystem(&inputDesc))
		return false;	
	// App Actions
	
	//Dump profile data
	const DumpProfileDataLambda = struct {
		pub fn Do(ctx: [*c]Ztf.ztf_InputActionContext) callconv(.C) bool
		{
			Ztf.ztf_dumpProfileData(@as(*Ztf.ztf_Renderer, @alignCast(@ptrCast(ctx.*.pUserData))).*.pName, 64);
			return true;
		}
	};
	const dumpProfileActionDesc = Ztf.ztf_InputActionDesc{
		.mActionId = Ztf.ZTF_DUMP_PROFILE_DATA,
		.pFunction = DumpProfileDataLambda.Do,
		.pUserData = pRenderer,
	};
	Ztf.ztf_addInputAction(&dumpProfileActionDesc, Ztf.ZTF_INPUT_ACTION_MAPPING_TARGET_ALL);
	
	//toggle fullscreen
	const ToggleFullscreenLambda = struct {
		pub fn Do(ctx: [*c]Ztf.ztf_InputActionContext) callconv(.C) bool
		{
			const app = @as(*Ztf.ztf_App, @alignCast(@ptrCast(ctx.*.pUserData)));
			const winDesc = Ztf.ztf_getWindowDesc(app);
			if (winDesc.*.fullScreen)
			{
				const clientRec = @as(*const Ztf.ztf_RectDesc, @ptrCast(&winDesc.*.clientRect));
	
				if (winDesc.*.borderlessWindow)
					Ztf.ztf_setBorderless(winDesc, @intCast(Ztf.ztf_getRectWidth(clientRec)), @intCast(Ztf.ztf_getRectHeight(clientRec)))
					else Ztf.ztf_setWindowed(winDesc, @intCast(Ztf.ztf_getRectWidth(clientRec)), @intCast(Ztf.ztf_getRectHeight(clientRec)));
			}
			else
			{
				Ztf.ztf_setFullscreen(winDesc);
			}
			return true;
		}
	};
	const toggleFullscreenActionDesc = Ztf.ztf_InputActionDesc{
		.mActionId = Ztf.ZTF_TOGGLE_FULLSCREEN,
		.pFunction = ToggleFullscreenLambda.Do,
		.pUserData = pApp,
	};
	Ztf.ztf_addInputAction(&toggleFullscreenActionDesc, Ztf.ZTF_INPUT_ACTION_MAPPING_TARGET_ALL);
	
	//Exit app
	const ExitLambda = struct {
		pub fn Do(_: [*c]Ztf.ztf_InputActionContext) callconv(.C) bool
		{
			Ztf.ztf_requestShutdown();
			return true;
		}
	};
	const exitActionDesc = Ztf.ztf_InputActionDesc{
		.mActionId = Ztf.ZTF_TOGGLE_FULLSCREEN,
		.pFunction = ExitLambda.Do,
		.pUserData = null,
	};
	Ztf.ztf_addInputAction(&exitActionDesc, Ztf.ZTF_INPUT_ACTION_MAPPING_TARGET_ALL);
	
	//Capture input
	const CaptureInputLambda = struct {
		pub fn Do(ctx: [*c]Ztf.ztf_InputActionContext) callconv(.C) bool
		{
			_ = Ztf.ztf_setEnableCaptureInput((!Ztf.ztf_uiIsFocused()) and Ztf.ZTF_INPUT_ACTION_PHASE_CANCELED != ctx.*.mPhase);
			return true;
		}
	};
	const captureInputActionDesc = Ztf.ztf_InputActionDesc{
		.mActionId = Ztf.ZTF_CAPTURE_INPUT,
		.pFunction = CaptureInputLambda.Do,
		.pUserData = null,
	};
	Ztf.ztf_addInputAction(&captureInputActionDesc, Ztf.ZTF_INPUT_ACTION_MAPPING_TARGET_ALL);
	
	//Camera input
	const OnCameraInputLambda = struct {
		pub fn Do(ctx: [*c]Ztf.ztf_InputActionContext, action: Ztf.ztf_DefaultInputAction) callconv(.C) bool
		{
			if (ctx.*.pCaptured != null and ctx.*.pCaptured.*)
	        {
	            const delta = if (Ztf.ztf_uiIsFocused()) Ztf.ztf_Float2{.x = 0.0, .y = 0.0} else ctx.*.unnamed_0.mFloat2;
	            switch (action)
	            {
					Ztf.ZTF_ROTATE_CAMERA => Ztf.ztf_onRotate(pCameraController, @bitCast(delta)),
					Ztf.ZTF_TRANSLATE_CAMERA =>  Ztf.ztf_onMove(pCameraController, @bitCast(delta)),
					Ztf.ZTF_TRANSLATE_CAMERA_VERTICAL =>  Ztf.ztf_onMoveY(pCameraController, delta.x),
					else => unreachable,
	            }
	        }
	        return true;
		}
	};
	
	//Camera Rotate
	const CameraRotateLambda = struct {
		pub fn Do(ctx: [*c]Ztf.ztf_InputActionContext) callconv(.C) bool
		{
			return OnCameraInputLambda.Do(ctx, Ztf.ZTF_ROTATE_CAMERA);
		}
	};
	const cameraRotateActionDesc = Ztf.ztf_InputActionDesc{
		.mActionId = Ztf.ZTF_ROTATE_CAMERA,
		.pFunction = CameraRotateLambda.Do,
		.pUserData = null,
	};
	Ztf.ztf_addInputAction(&cameraRotateActionDesc, Ztf.ZTF_INPUT_ACTION_MAPPING_TARGET_ALL);
	
	//Camera Translate
	const CameraTranslateLambda = struct {
		pub fn Do(ctx: [*c]Ztf.ztf_InputActionContext) callconv(.C) bool
		{
			return OnCameraInputLambda.Do(ctx, Ztf.ZTF_TRANSLATE_CAMERA);
		}
	};
	const cameraTranslateActionDesc = Ztf.ztf_InputActionDesc{
		.mActionId = Ztf.ZTF_TRANSLATE_CAMERA,
		.pFunction = CameraTranslateLambda.Do,
		.pUserData = null,
	};
	Ztf.ztf_addInputAction(&cameraTranslateActionDesc, Ztf.ZTF_INPUT_ACTION_MAPPING_TARGET_ALL);
	
	//Camera Translate Vertical
	const CameraTranslateVerticalLambda = struct {
		pub fn Do(ctx: [*c]Ztf.ztf_InputActionContext) callconv(.C) bool
		{
			return OnCameraInputLambda.Do(ctx, Ztf.ZTF_TRANSLATE_CAMERA_VERTICAL);
		}
	};
	const cameraTranslateVerticalActionDesc = Ztf.ztf_InputActionDesc{
		.mActionId = Ztf.ZTF_TRANSLATE_CAMERA_VERTICAL,
		.pFunction = CameraTranslateVerticalLambda.Do,
		.pUserData = null,
	};
	Ztf.ztf_addInputAction(&cameraTranslateVerticalActionDesc, Ztf.ZTF_INPUT_ACTION_MAPPING_TARGET_ALL);
	
	//Reset Camera
	const ResetCameraLambda = struct {
		pub fn Do(_: [*c]Ztf.ztf_InputActionContext) callconv(.C) bool
		{
			if (Ztf.ztf_uiWantTextInput() != 0)
				Ztf.ztf_resetView(pCameraController);
			return true;
		}
	};
	const resetCameraActionDesc = Ztf.ztf_InputActionDesc{
		.mActionId = Ztf.ZTF_RESET_CAMERA,
		.pFunction = ResetCameraLambda.Do,
		.pUserData = null,
	};
	Ztf.ztf_addInputAction(&resetCameraActionDesc, Ztf.ZTF_INPUT_ACTION_MAPPING_TARGET_ALL);

	//Any button action
	const OnAnyInputLambda = struct {
		pub fn Do(ctx: [*c]Ztf.ztf_InputActionContext) callconv(.C) bool
		{
			if (ctx.*.mActionId > Ztf.ZTF_UI_ACTION_START_ID_)
            {
                Ztf.ztf_uiOnInput(ctx.*.mActionId, ctx.*.unnamed_0.mBool, @ptrCast(ctx.*.pPosition), @ptrCast(&ctx.*.unnamed_0.mFloat2));
            }

            return true;
		}
	};
	const anyButtonActionDesc = Ztf.ztf_GlobalInputActionDesc{
		.mGlobalInputActionType = Ztf.ZTF_ANY_BUTTON_ACTION,
		.pFunction = OnAnyInputLambda.Do,
		.pUserData = null,
	};
	Ztf.ztf_setGlobalInputAction(&anyButtonActionDesc);

	gFrameIndex = 0;

	return true;
}

fn rendererExit(_: ?*Ztf.ztf_App) void
{
	if(pRendererOpt == null)
	{
		return;
	}
	
	Ztf.ztf_exitInputSystem();

	Ztf.ztf_exitCameraController(pCameraController);
	
	Ztf.ztf_exitProfiler();
	
	Ztf.ztf_exitUserInterface();

	Ztf.ztf_exitFontSystem();

	for (0..gDataBufferCount) |i|
	{
		Ztf.ztf_removeResource(@ptrCast(pProjViewUniformBuffer[i]));
		Ztf.ztf_removeResource(@ptrCast(pSkyboxUniformBuffer[i]));
	}

	Ztf.ztf_removeResource(@ptrCast(pSkyBoxVertexBuffer));

	Ztf.ztf_removeSampler(pRenderer, pSamplerSkyBox);

	for(0..6) |i|
	{
		Ztf.ztf_removeResource2(@ptrCast(pSkyBoxTextures[i]));
	}

	Ztf.ztf_exitResourceLoaderInterface(@ptrCast(pRenderer));

	Ztf.ztf_removeSemaphore(pRenderer, pImageAcquiredSemaphore);

	RingBuffer.removeGpuCmdRing(pRenderer, &gGraphicsCmdRing) catch |err| @panic(@errorName(err));

	Ztf.ztf_removeQueue(pRenderer, pGraphicsQueue);

	for (0..gDataBufferCount) |i| {

		if (Ztf.ztf_getGPUSettings_mPipelineStatsQueries(&pRenderer.*.pGpu.*.mSettings) != 0)
		{
			Ztf.ztf_removeQueryPool(pRenderer, pPipelineStatsQueryPool[i]);
		}
	}

	Ztf.ztf_exitRenderer(pRenderer);
	pRenderer = undefined;
	pRendererOpt = null;
}

pub export fn ztf_appExit(ztf_App: ?*Ztf.ztf_App) callconv(.C) void
{
	rendererExit(ztf_App);

	ZtfExt.LOGF(Ztf.ztf_eINFO, "ztf_appExit", .{});
	ZtfExt.deinit();

	const deinit_status = gpa.deinit();
	if (deinit_status == .leak)
	{
		@panic("Memory leak on exit.");
	}
}

pub export fn ztf_appLoad(pApp: ?*Ztf.ztf_App, pReloadDesc: [*c]Ztf.ztf_ReloadDesc) callconv(.C) bool
{
	const app_settings = Ztf.ztf_getAppSettings(pApp);
	const window_desc = Ztf.ztf_getWindowDesc(pApp);

	if (pReloadDesc.*.mType & Ztf.ZTF_RELOAD_TYPE_SHADER != 0)
	{
		//Add shaders
		{
			const skyShader = Ztf.ztf_ShaderLoadDesc{
				.mStages = .{
					Ztf.ztf_ShaderStageLoadDesc{
						.pFileName = "skybox.vert",
					},
					Ztf.ztf_ShaderStageLoadDesc{
						.pFileName ="skybox.frag",
					},
					.{},
					.{},
					.{},
					.{},
				},
			};

			const basicShader = Ztf.ztf_ShaderLoadDesc{
				.mStages = .{
					Ztf.ztf_ShaderStageLoadDesc{
						.pFileName = "basic.vert",
					},
					Ztf.ztf_ShaderStageLoadDesc{
						.pFileName ="basic.frag",
					},
					.{},
					.{},
					.{},
					.{},
				},
			};

			Ztf.ztf_addShader(@ptrCast(pRenderer), @ptrCast(&skyShader), @ptrCast(&pSkyBoxDrawShader));
			Ztf.ztf_addShader(@ptrCast(pRenderer), @ptrCast(&basicShader), @ptrCast(&pSphereShader));
		}

		//add RootSignatures;
		{
			const shaders = [_]?*Ztf.ztf_Shader{
				pSphereShader,
				pSkyBoxDrawShader,
			};
			const shadersCount = shaders.len;

			const pStaticSamplers = [_][]const u8{"uSampler0"};
			const rootDesc = Ztf.ztf_RootSignatureDesc{
				.mStaticSamplerCount = 1,
				.ppStaticSamplerNames = @ptrCast(@constCast(&pStaticSamplers[0])),
				.ppStaticSamplers = &pSamplerSkyBox,
				.mShaderCount = shadersCount,
				.ppShaders = @constCast(&shaders),
			};
			Ztf.ztf_addRootSignature(pRenderer, &rootDesc, &pRootSignature);
		}

		//add DescriptorSets
		{
			const desc = Ztf.ztf_DescriptorSetDesc{
				.pRootSignature = pRootSignature,
				.mUpdateFrequency = Ztf.ZTF_DESCRIPTOR_UPDATE_FREQ_NONE,
				.mMaxSets = 1
			};
			Ztf.ztf_addDescriptorSet(pRenderer, &desc, &pDescriptorSetTexture);
			const desc2 = Ztf.ztf_DescriptorSetDesc{
				.pRootSignature = pRootSignature,
				.mUpdateFrequency = Ztf.ZTF_DESCRIPTOR_UPDATE_FREQ_PER_FRAME,
				.mMaxSets = gDataBufferCount * 2
			};
			Ztf.ztf_addDescriptorSet(pRenderer, &desc2, &pDescriptorSetUniforms);
		}
	}

	if (pReloadDesc.*.mType & (Ztf.ZTF_RELOAD_TYPE_RESIZE | Ztf.ZTF_RELOAD_TYPE_RENDERTARGET) != 0)
	{
		//add swapchain
		{
			var swapChainDesc = Ztf.ztf_SwapChainDesc{
				.mWindowHandle = @bitCast(window_desc.*.handle),
				.mPresentQueueCount = 1,
				.ppPresentQueues = &pGraphicsQueue,
				.mWidth = @intCast(app_settings.*.mWidth),
				.mHeight = @intCast(app_settings.*.mHeight),
				.mImageCount = Ztf.ztf_getRecommendedSwapchainImageCount(pRenderer, @ptrCast(&window_desc.*.handle)),
				.mColorSpace = Ztf.ZTF_COLOR_SPACE_SDR_SRGB,
				.mEnableVsync = app_settings.*.mVSyncEnabled,
				.mFlags = Ztf.ZTF_SWAP_CHAIN_CREATION_FLAG_ENABLE_FOVEATED_RENDERING_VR,
			};
			
			swapChainDesc.mColorFormat = Ztf.ztf_getSupportedSwapchainFormat(pRenderer, &swapChainDesc, Ztf.ZTF_COLOR_SPACE_SDR_SRGB);
		
			Ztf.ztf_addSwapChain(pRenderer, &swapChainDesc, &pSwapChain);
			if(pSwapChain == null)
			{
				ZtfExt.LOGF(Ztf.ztf_eERROR, "Swapchain failed to initialise.", .{});
				return false;
			}
		}

		//add depth buffer
		{
			const depthRT = Ztf.ztf_RenderTargetDesc{
				.mArraySize = 1,
				.mClearValue = .{ .unnamed_1 = .{.depth = 0.0, .stencil = 0,}, },
				.mDepth = 1,
				.mFormat = Ztf.TinyImageFormat_D32_SFLOAT,
				.mStartState = Ztf.ZTF_RESOURCE_STATE_DEPTH_WRITE,
				.mHeight = @intCast(app_settings.*.mHeight),
				.mSampleCount = Ztf.ZTF_SAMPLE_COUNT_1,
				.mSampleQuality = 0,
				.mWidth = @intCast(app_settings.*.mWidth),
				.mFlags = Ztf.ZTF_TEXTURE_CREATION_FLAG_ON_TILE | Ztf.ZTF_TEXTURE_CREATION_FLAG_VR_MULTIVIEW,
			};
			Ztf.ztf_addRenderTarget(pRenderer, &depthRT, &pDepthBuffer);
			if(pDepthBuffer == null)
			{
				ZtfExt.LOGF(Ztf.ztf_eERROR, "Depth Buffer failed to initialise.", .{});
				return false;
			}
		}
	}

	if (pReloadDesc.*.mType & (Ztf.ZTF_RELOAD_TYPE_SHADER | Ztf.ZTF_RELOAD_TYPE_RENDERTARGET) != 0)
	{
		generate_complex_mesh();
		
		var rasterizerStateDesc = Ztf.ztf_RasterizerStateDesc{
			.mCullMode = Ztf.ZTF_CULL_MODE_NONE,
		};

        var sphereRasterizerStateDesc = Ztf.ztf_RasterizerStateDesc{
			.mCullMode = Ztf.ZTF_CULL_MODE_FRONT,
		};

        var depthStateDesc = Ztf.ztf_DepthStateDesc{
			.mDepthTest = true,
			.mDepthWrite = true,
			.mDepthFunc = Ztf.ZTF_CMP_GEQUAL,
		};

        var desc = Ztf.ztf_PipelineDesc{
			.mType = Ztf.ZTF_PIPELINE_TYPE_GRAPHICS,
			.unnamed_0 = .{ .mGraphicsDesc = .{
				.mPrimitiveTopo = Ztf.ZTF_PRIMITIVE_TOPO_TRI_LIST,
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
		desc.unnamed_0.mGraphicsDesc.mSampleQuality = Ztf.ztf_getRenderTarget_mSampleQuality(pSwapChain.?.ppRenderTargets[0]);
        Ztf.ztf_addPipeline(pRenderer, &desc, &pSpherePipeline);

        // layout and pipeline for skybox draw
        var vertexLayout = Ztf.ztf_VertexLayout{
			.mBindingCount = 1,
			.mAttribCount = 1,
		};
		vertexLayout.mBindings[0].mStride = @sizeOf(Ztf.ztf_Float4);
        vertexLayout.mAttribs[0].mSemantic = Ztf.ZTF_SEMANTIC_POSITION;
        vertexLayout.mAttribs[0].mFormat = Ztf.TinyImageFormat_R32G32B32A32_SFLOAT;
        vertexLayout.mAttribs[0].mBinding = 0;
        vertexLayout.mAttribs[0].mLocation = 0;
        vertexLayout.mAttribs[0].mOffset = 0;
        desc.unnamed_0.mGraphicsDesc.pVertexLayout = &vertexLayout;

        desc.unnamed_0.mGraphicsDesc.pDepthState = null;
        desc.unnamed_0.mGraphicsDesc.pRasterizerState = &rasterizerStateDesc;
        desc.unnamed_0.mGraphicsDesc.pShaderProgram = pSkyBoxDrawShader; //-V519
        Ztf.ztf_addPipeline(pRenderer, &desc, &pSkyBoxDrawPipeline);
	}

	//prepareDescriptorSets();
	{
		{
			// Prepare descriptor sets
			var params : [6]Ztf.ztf_DescriptorData = [_]Ztf.ztf_DescriptorData{ Ztf.ztf_DescriptorData{} } ** 6;
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
			Ztf.ztf_updateDescriptorSet(pRenderer, 0, pDescriptorSetTexture, 6, &params);
		}

        for (0..gDataBufferCount) |i|
        {
            var params : [1]Ztf.ztf_DescriptorData = .{
				.{
					.pName = "uniformBlock",
					.unnamed_1 = .{.ppBuffers = &pSkyboxUniformBuffer[i],},
				}, 
			};
            Ztf.ztf_updateDescriptorSet(pRenderer, @as(u32, @intCast(i * 2 + 0)), pDescriptorSetUniforms, 1, &params);

            params[0].pName = "uniformBlock";
            params[0].unnamed_1.ppBuffers = &pProjViewUniformBuffer[i];
            Ztf.ztf_updateDescriptorSet(pRenderer, @as(u32, @intCast(i * 2 + 1)), pDescriptorSetUniforms, 1, &params);
        }
	}

	const uiLoad = Ztf.ztf_UserInterfaceLoadDesc{
		.mColorFormat = @intCast(pSwapChain.?.ppRenderTargets[0].*.mFormat),
		.mHeight = @intCast(app_settings.*.mHeight),
		.mWidth = @intCast(app_settings.*.mWidth),
		.mLoadType = @bitCast(pReloadDesc.*.mType),
	};
	Ztf.ztf_loadUserInterface(&uiLoad);

	const fontLoad = Ztf.ztf_FontSystemLoadDesc{
		.mColorFormat = @intCast(pSwapChain.?.ppRenderTargets[0].*.mFormat),
		.mHeight = @intCast(app_settings.*.mHeight),
		.mWidth = @intCast(app_settings.*.mWidth),
		.mLoadType = @bitCast(pReloadDesc.*.mType),
	};
	Ztf.ztf_loadFontSystem(&fontLoad);

	return true;
}

pub export fn ztf_appUnload(_: ?*Ztf.ztf_App, pReloadDesc: [*c]Ztf.ztf_ReloadDesc) callconv(.C) void
{
	Ztf.ztf_waitQueueIdle(pGraphicsQueue);

	Ztf.ztf_unloadFontSystem(@bitCast(pReloadDesc.*.mType));
	Ztf.ztf_unloadUserInterface(@bitCast(pReloadDesc.*.mType));

	if (pReloadDesc.*.mType & (Ztf.ZTF_RELOAD_TYPE_SHADER | Ztf.ZTF_RELOAD_TYPE_RENDERTARGET) != 0)
	{
		Ztf.ztf_removePipeline(pRenderer, pSkyBoxDrawPipeline);
        Ztf.ztf_removePipeline(pRenderer, pSpherePipeline);
		Ztf.ztf_removeResource(@ptrCast(pSphereVertexBuffer));
		Ztf.ztf_removeResource(@ptrCast(pSphereIndexBuffer));
	}

	if (pReloadDesc.*.mType & (Ztf.ZTF_RELOAD_TYPE_RESIZE | Ztf.ZTF_RELOAD_TYPE_RENDERTARGET) != 0)
	{
		Ztf.ztf_removeSwapChain(pRenderer, pSwapChain);
		Ztf.ztf_removeRenderTarget(pRenderer, pDepthBuffer);
	}

	if (pReloadDesc.*.mType & Ztf.ZTF_RELOAD_TYPE_SHADER != 0)
	{
		//remove DescriptorSets
		{
			Ztf.ztf_removeDescriptorSet(pRenderer, pDescriptorSetTexture);
			Ztf.ztf_removeDescriptorSet(pRenderer, pDescriptorSetUniforms);
		}

		//Remove RootSignatures;
		{
			Ztf.ztf_removeRootSignature(@ptrCast(pRenderer), pRootSignature);
		}

		//Remove shaders
		{
			Ztf.ztf_removeShader(@ptrCast(pRenderer), @ptrCast(pSphereShader));
			Ztf.ztf_removeShader(@ptrCast(pRenderer), @ptrCast(pSkyBoxDrawShader));
		}
	}
}

pub export fn ztf_appUpdate(pApp: ?*Ztf.ztf_App, deltaTime: f32) callconv(.C) void
{
	const app_settings = Ztf.ztf_getAppSettings(pApp);

	Ztf.ztf_updateInputSystem(deltaTime, @intCast(app_settings.*.mWidth), @intCast(app_settings.*.mHeight));

	Ztf.ztf_update(pCameraController, deltaTime);

	const static = struct {
		var currentTime : f32 = 0.0;
	};

	// Scene Update
	static.currentTime += (deltaTime * 1000.0);

	// update camera with time
	var viewMat = Ztf.ztf_getViewMatrix(pCameraController);

	const aspectInverse = @as(f32, @floatFromInt(app_settings.*.mHeight)) / @as(f32, @floatFromInt(app_settings.*.mWidth));
	const horizontal_fov = std.math.pi / 2.0;
	const projMat : Ztf.ZTF_CameraMatrix = Ztf.ztf_perspectiveReverseZ(horizontal_fov, aspectInverse, 0.1, 1000.0);

	gUniformData.mProjectView = Ztf.ztf_camera_matrix_mul_mat(&projMat, &viewMat);

	// point light parameters
	gUniformData.mLightPosition = Ztf.make_vec3(0.0, 0.0, 0.0);
	gUniformData.mLightColor = Ztf.make_vec3(0.9, 0.9, 0.7); // Pale Yellow

	for(0..gNumPlanets) |i|
	{
		var rotSelf = Ztf.mat4_identity();
		var rotOrbitY = Ztf.mat4_identity();
		var rotOrbitZ = Ztf.mat4_identity();
		var trans = Ztf.mat4_identity();
		var scale = Ztf.mat4_identity();
		var parentMat = Ztf.mat4_identity();

		if (gPlanetInfoData[i].mRotationSpeed > 0.0)
			rotSelf = Ztf.mat4_from_rotationXYZ(&Ztf.make_vec3(0.0, gRotSelfScale * (static.currentTime + gTimeOffset) / gPlanetInfoData[i].mRotationSpeed, 0.0));
		if (gPlanetInfoData[i].mYOrbitSpeed > 0.0)
			rotOrbitY = Ztf.mat4_from_rotationXYZ(&Ztf.make_vec3(0.0, gRotOrbitYScale * (static.currentTime + gTimeOffset) / gPlanetInfoData[i].mYOrbitSpeed, 0.0));
		if (gPlanetInfoData[i].mZOrbitSpeed > 0.0)
			rotOrbitZ = Ztf.mat4_from_rotationXYZ(&Ztf.make_vec3(0.0, 0.0, gRotOrbitZScale * (static.currentTime + gTimeOffset) / gPlanetInfoData[i].mZOrbitSpeed));
		if (gPlanetInfoData[i].mParentIndex > 0)
			parentMat = gPlanetInfoData[gPlanetInfoData[i].mParentIndex].mSharedMat;

		trans = gPlanetInfoData[i].mTranslationMat;
		scale = gPlanetInfoData[i].mScaleMat;

		scale.mCol0.mVec128[0] /= 2;
		scale.mCol1.mVec128[1] /= 2;
		scale.mCol2.mVec128[2] /= 2;

		Ztf.mat4_mul(&parentMat, &rotOrbitY, &gPlanetInfoData[i].mSharedMat);
		Ztf.mat4_mul(&gPlanetInfoData[i].mSharedMat, &trans, &gPlanetInfoData[i].mSharedMat);

		Ztf.mat4_mul(&parentMat, &rotOrbitY, &gUniformData.mToWorldMat[i]);
		Ztf.mat4_mul(&gUniformData.mToWorldMat[i], &rotOrbitZ, &gUniformData.mToWorldMat[i]);
		Ztf.mat4_mul(&gUniformData.mToWorldMat[i], &trans, &gUniformData.mToWorldMat[i]);
		Ztf.mat4_mul(&gUniformData.mToWorldMat[i], &rotSelf, &gUniformData.mToWorldMat[i]);
		Ztf.mat4_mul(&gUniformData.mToWorldMat[i], &scale, &gUniformData.mToWorldMat[i]);
		
		gUniformData.mColor[i] = gPlanetInfoData[i].mColor;

		var phase : f32 = 0.0;
		const phaseFraction = std.math.modf(static.currentTime * gPlanetInfoData[i].mMorphingSpeed / 2000.0);
		if (phaseFraction.fpart > 0.5)
		{
			phase = 2.0 - phaseFraction.fpart * 2.0;
		}
		else
		{
			phase = phaseFraction.fpart * 2.0;
		}

		gUniformData.mGeometryWeight[i][0] = phase;
	}

	const debugView = &gUniformData;
	_ = &debugView;

	const translation = Ztf.make_vec3(0.0, 0.0, 0.0);
	Ztf.mat4_set_translation( @ptrCast(&viewMat), @ptrCast(&translation));
	gUniformDataSky = UniformBlockSky_C{};
	gUniformDataSky.mProjectView = Ztf.ztf_camera_matrix_mul_mat(&projMat, &viewMat);
}

pub export fn ztf_appDraw(pApp: ?*Ztf.ztf_App) callconv(.C) void
{
	const app_settings = Ztf.ztf_getAppSettings(pApp);
	const settings_vsync_enabled = app_settings.*.mVSyncEnabled;
	const swapchain_vsync_enabled = Ztf.ztf_getSwapChain_mEnableVsync(pSwapChain) != 0;
	if(swapchain_vsync_enabled != settings_vsync_enabled)
	{
		Ztf.ztf_waitQueueIdle(pGraphicsQueue);
		Ztf.ztf_toggleVSync(pRenderer, &pSwapChain);
	}

	var swapchainImageIndex : u32 = 0;
	Ztf.ztf_acquireNextImage(pRenderer, pSwapChain, pImageAcquiredSemaphore, null, &swapchainImageIndex);
	
	//const pRenderTarget 
	const pRenderTarget = pSwapChain.?.ppRenderTargets[swapchainImageIndex];
	var elem = RingBuffer.getNextGpuCmdRingElement(&gGraphicsCmdRing, true, 1) catch |err| @panic(@errorName(err));

	// Stall if CPU is running "gDataBufferCount" frames ahead of GPU
	var fenceStatus : Ztf.ztf_FenceStatus = 0;
	Ztf.ztf_getFenceStatus(pRenderer, elem.pFence, &fenceStatus);
	if (fenceStatus == Ztf.ZTF_FENCE_STATUS_INCOMPLETE)
	{
		Ztf.ztf_waitForFences(pRenderer, 1, &elem.pFence);
	}

	// Update uniform buffers
	var viewProjCbv = Ztf.ztf_BufferUpdateDesc{ .pBuffer = @ptrCast(pProjViewUniformBuffer[gFrameIndex]), };
	Ztf.ztf_beginUpdateResource(&viewProjCbv);
	const uniformDataView : *UniformBlock_C = @alignCast(@ptrCast(viewProjCbv.pMappedData));
	uniformDataView.* = gUniformData;
	Ztf.ztf_endUpdateResource(&viewProjCbv);

	var skyboxViewProjCbv = Ztf.ztf_BufferUpdateDesc{ .pBuffer =  @alignCast(@ptrCast(pSkyboxUniformBuffer[gFrameIndex])), };
	Ztf.ztf_beginUpdateResource(&skyboxViewProjCbv);
	const uniformDataSkyView : *UniformBlockSky_C = @alignCast(@ptrCast(skyboxViewProjCbv.pMappedData));
	uniformDataSkyView.* = gUniformDataSky;
	Ztf.ztf_endUpdateResource(&skyboxViewProjCbv);

	// Reset cmd pool for this frame
	Ztf.ztf_resetCmdPool(pRenderer, elem.pCmdPool);
	var pipelineStatsQueries = Ztf.ztf_getGPUSettings_mPipelineStatsQueries(&pRenderer.*.pGpu.*.mSettings);
	if (pipelineStatsQueries != 0)
	{
		var data3D = Ztf.ztf_QueryData{};
		var data2D = Ztf.ztf_QueryData{};
		Ztf.ztf_getQueryData(pRenderer, pPipelineStatsQueryPool[gFrameIndex], 0, &data3D);
		Ztf.ztf_getQueryData(pRenderer, pPipelineStatsQueryPool[gFrameIndex], 1, &data2D);
		const fmt_msg = \\
			\\Pipeline Stats 3D:
			\\    VS invocations:      {d}
			\\    PS invocations:      {d}
			\\    Clipper invocations: {d}
			\\    IA primitives:       {d}
			\\    Clipper primitives:  {d}
			\\
			\\Pipeline Stats 2D UI:
			\\    VS invocations:      {d}
			\\    PS invocations:      {d}
			\\    Clipper invocations: {d}
			\\    IA primitives:       {d}
			\\    Clipper primitives:  {d}
		;

		const data3DPipeStats = &data3D.unnamed_0.unnamed_0.mPipelineStats;
		const data2DPipeStats = &data3D.unnamed_0.unnamed_0.mPipelineStats;

		const result = std.fmt.bufPrint(
			gPipelineStatsCharArraySlice,
			fmt_msg,
			.{
				data3DPipeStats.*.mVSInvocations,
				data3DPipeStats.*.mPSInvocations,
				data3DPipeStats.*.mCInvocations,
				data3DPipeStats.*.mIAPrimitives,
				data3DPipeStats.*.mCPrimitives,

				data2DPipeStats.*.mVSInvocations,
				data2DPipeStats.*.mPSInvocations,
				data2DPipeStats.*.mCInvocations,
				data2DPipeStats.*.mIAPrimitives,
				data2DPipeStats.*.mCPrimitives
			}
		);
		_ = &result;
	}

	const cmd = elem.pCmds[0];
	Ztf.ztf_beginCmd(cmd);

	Ztf.ztf_cmdBeginGpuFrameProfile(@ptrCast(cmd), gGpuProfileToken, true);
	pipelineStatsQueries = Ztf.ztf_getGPUSettings_mPipelineStatsQueries(&pRenderer.*.pGpu.*.mSettings);
	if (pipelineStatsQueries != 0)
	{
		Ztf.ztf_cmdResetQuery(cmd, pPipelineStatsQueryPool[gFrameIndex], 0, 2);
		var queryDesc = Ztf.ztf_QueryDesc{ .mIndex = 0, };
		Ztf.ztf_cmdBeginQuery(cmd, pPipelineStatsQueryPool[gFrameIndex], &queryDesc);
	}

	var barriers = [_]Ztf.ztf_RenderTargetBarrier{
		Ztf.ztf_RenderTargetBarrier{
			.pRenderTarget = pRenderTarget,
			.mCurrentState = Ztf.ZTF_RESOURCE_STATE_PRESENT,
			.mNewState = Ztf.ZTF_RESOURCE_STATE_RENDER_TARGET,
		},
	};
	Ztf.ztf_cmdResourceBarrier(cmd, 0, null, 0, null, 1, &barriers);

	_ = Ztf.ztf_cmdBeginGpuTimestampQuery(@ptrCast(cmd), gGpuProfileToken, "Draw Skybox/Planets", true);

	// simply record the screen cleaning command
	var bindRenderTargets = Ztf.ztf_BindRenderTargetsDesc{
		.mRenderTargetCount = 1,
		.mDepthStencil = Ztf.ztf_BindDepthTargetDesc{
			.pDepthStencil = pDepthBuffer,
			.mLoadAction = Ztf.ZTF_LOAD_ACTION_CLEAR
		},
	};
	bindRenderTargets.mRenderTargets[0] = Ztf.ztf_BindRenderTargetDesc{
		.pRenderTarget = pRenderTarget,
		.mLoadAction = Ztf.ZTF_LOAD_ACTION_CLEAR
	};

	const rtarget_width = Ztf.ztf_getRenderTarget_mWidth(pRenderTarget);
	const rtarget_height = Ztf.ztf_getRenderTarget_mHeight(pRenderTarget);
	Ztf.ztf_cmdBindRenderTargets(cmd, &bindRenderTargets);
	Ztf.ztf_cmdSetViewport(cmd, 0.0, 0.0, @floatFromInt(rtarget_width), @floatFromInt(rtarget_height), 0.0, 1.0);
	Ztf.ztf_cmdSetScissor(cmd, 0, 0, rtarget_width, rtarget_height);

	const skyboxVbStride : u32 = @as(u32, @sizeOf(f32) * 4);

	_ = Ztf.ztf_cmdBeginGpuTimestampQuery(@ptrCast(cmd), gGpuProfileToken, "Draw Skybox", true);
	Ztf.ztf_cmdSetViewport(cmd, 0.0, 0.0, @floatFromInt(rtarget_width), @floatFromInt(rtarget_height), 1.0, 1.0);
	Ztf.ztf_cmdBindPipeline(cmd, pSkyBoxDrawPipeline);
	Ztf.ztf_cmdBindDescriptorSet(cmd, 0, pDescriptorSetTexture);
	Ztf.ztf_cmdBindDescriptorSet(cmd, gFrameIndex * 2 + 0, pDescriptorSetUniforms);
	Ztf.ztf_cmdBindVertexBuffer(cmd, 1, &pSkyBoxVertexBuffer, &skyboxVbStride, null);
	Ztf.ztf_cmdDraw(cmd, 36, 0);
	Ztf.ztf_cmdSetViewport(cmd, 0.0, 0.0, @floatFromInt(rtarget_width), @floatFromInt(rtarget_height), 0.0, 1.0);
	Ztf.ztf_cmdEndGpuTimestampQuery(@ptrCast(cmd), gGpuProfileToken);

	_ = Ztf.ztf_cmdBeginGpuTimestampQuery(@ptrCast(cmd), gGpuProfileToken, "Draw Planets", true);

	Ztf.ztf_cmdBindPipeline(cmd, pSpherePipeline);
	Ztf.ztf_cmdBindDescriptorSet(cmd, gFrameIndex * 2 + 1, pDescriptorSetUniforms);
	Ztf.ztf_cmdBindVertexBuffer(cmd, 1, &pSphereVertexBuffer, &gSphereVertexLayout.mBindings[0].mStride, null);
	Ztf.ztf_cmdBindIndexBuffer(cmd, pSphereIndexBuffer, Ztf.ZTF_INDEX_TYPE_UINT16, 0);

	Ztf.ztf_cmdDrawIndexedInstanced(cmd, gSphereIndexCount, 0, gNumPlanets, 0, 0);
	Ztf.ztf_cmdEndGpuTimestampQuery(@ptrCast(cmd), gGpuProfileToken);
	Ztf.ztf_cmdEndGpuTimestampQuery(@ptrCast(cmd), gGpuProfileToken); // Draw Skybox/Planets
	Ztf.ztf_cmdBindRenderTargets(cmd, null);

	if (pipelineStatsQueries != 0)
	{
		var queryDesc = Ztf.ztf_QueryDesc{ .mIndex = 0 };
		Ztf.ztf_cmdEndQuery(cmd, pPipelineStatsQueryPool[gFrameIndex], &queryDesc);
		queryDesc.mIndex = 1;
		Ztf.ztf_cmdBeginQuery(cmd, pPipelineStatsQueryPool[gFrameIndex], &queryDesc);
	}

	_ = Ztf.ztf_cmdBeginGpuTimestampQuery(@ptrCast(cmd), gGpuProfileToken, "Draw UI", true);
	bindRenderTargets = Ztf.ztf_BindRenderTargetsDesc{
		.mRenderTargetCount = 1,
		.mDepthStencil = Ztf.ztf_BindDepthTargetDesc{
			.pDepthStencil = null,
			.mLoadAction = Ztf.ZTF_LOAD_ACTION_DONTCARE
		},
	};
	bindRenderTargets.mRenderTargets[0] = Ztf.ztf_BindRenderTargetDesc{
		.pRenderTarget = pRenderTarget,
		.mLoadAction = Ztf.ZTF_LOAD_ACTION_LOAD
	};
	Ztf.ztf_cmdBindRenderTargets(cmd, &bindRenderTargets);

	gFrameTimeDraw.mFontColor = 0xff00ffff;
	gFrameTimeDraw.mFontSize = 18.0;
	gFrameTimeDraw.mFontID = gFontID;
	const txtSizePx = Ztf.ztf_cmdDrawCpuProfile(@ptrCast(cmd), Ztf.ztf_Float2{.x=8.0, .y=15.0}, @ptrCast(&gFrameTimeDraw));
	_ = Ztf.ztf_cmdDrawGpuProfile(@ptrCast(cmd), Ztf.ztf_Float2{.x=8.0, .y=txtSizePx.y + 75.0}, gGpuProfileToken, @ptrCast(&gFrameTimeDraw));

	Ztf.ztf_cmdDrawUserInterface(@ptrCast(cmd), null);
	Ztf.ztf_cmdEndGpuTimestampQuery(@ptrCast(cmd), gGpuProfileToken);
    Ztf.ztf_cmdBindRenderTargets(cmd, null);

	barriers[0] = Ztf.ztf_RenderTargetBarrier{
			.pRenderTarget = pRenderTarget,
			.mCurrentState = Ztf.ZTF_RESOURCE_STATE_RENDER_TARGET,
			.mNewState = Ztf.ZTF_RESOURCE_STATE_PRESENT,
	};
	Ztf.ztf_cmdResourceBarrier(cmd, 0, null, 0, null, 1, &barriers);

	Ztf.ztf_cmdEndGpuFrameProfile(@ptrCast(cmd), gGpuProfileToken);

	if (pipelineStatsQueries != 0)
	{
		var queryDesc = Ztf.ztf_QueryDesc{ .mIndex = 1 };
		Ztf.ztf_cmdEndQuery(cmd, pPipelineStatsQueryPool[gFrameIndex], &queryDesc);
		Ztf.ztf_cmdResolveQuery(cmd, pPipelineStatsQueryPool[gFrameIndex], 0, 2);
	}

	Ztf.ztf_endCmd(cmd);

	var flushUpdateDesc = Ztf.ztf_FlushResourceUpdateDesc{};
	flushUpdateDesc.mNodeIndex = 0;
	Ztf.ztf_flushResourceUpdates(&flushUpdateDesc);
	var waitSemaphores = [2][*c]Ztf.ztf_Semaphore{ @ptrCast(flushUpdateDesc.pOutSubmittedSemaphore), pImageAcquiredSemaphore };
	_ = &waitSemaphores;

	var submitDesc = Ztf.ztf_QueueSubmitDesc{};
	submitDesc.mCmdCount = 1;
	submitDesc.mSignalSemaphoreCount = 1;
	submitDesc.mWaitSemaphoreCount = waitSemaphores.len;
	submitDesc.ppCmds = @constCast(&cmd);
	submitDesc.ppSignalSemaphores = @constCast(&elem.pSemaphore);
	submitDesc.ppWaitSemaphores =  @constCast(&waitSemaphores);
	submitDesc.pSignalFence = elem.pFence;
	Ztf.ztf_queueSubmit(pGraphicsQueue, &submitDesc);

	var presentDesc = Ztf.ztf_QueuePresentDesc{};
	presentDesc.mIndex = @intCast(swapchainImageIndex);
	presentDesc.mWaitSemaphoreCount = 1;
	presentDesc.pSwapChain = pSwapChain;
	presentDesc.ppWaitSemaphores = @constCast(&elem.pSemaphore);
	presentDesc.mSubmitDone = true;

	Ztf.ztf_queuePresent(pGraphicsQueue, &presentDesc);
	Ztf.ztf_flipProfiler();

	gFrameIndex = (gFrameIndex + 1) % gDataBufferCount;
}

pub export fn ztf_appGetName(_: ?*Ztf.ztf_App) callconv(.C) [*c]const u8
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

            const rx = 1 - @abs((@as(f32, @floatFromInt(x)) / DETAIL_LEVEL) * 2 - 1);

            for (0..DETAIL_LEVEL) |y|
            {
                const ry = 1 - @abs((@as(f32, @floatFromInt(y)) / DETAIL_LEVEL) * 2 - 1);
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

			add_attribute(&gSphereVertexLayout, Ztf.ZTF_SEMANTIC_POSITION, Ztf.TinyImageFormat_R32G32B32_SFLOAT, 0);
			add_attribute(&gSphereVertexLayout, Ztf.ZTF_SEMANTIC_NORMAL, Ztf.TinyImageFormat_R32G32B32_SFLOAT, 16);
			add_attribute(&gSphereVertexLayout, Ztf.ZTF_SEMANTIC_TEXCOORD1, Ztf.TinyImageFormat_R32G32B32_SFLOAT, 48);
			add_attribute(&gSphereVertexLayout, Ztf.ZTF_SEMANTIC_TEXCOORD3, Ztf.TinyImageFormat_R32G32B32_SFLOAT, 64);
			add_attribute(&gSphereVertexLayout, Ztf.ZTF_SEMANTIC_TEXCOORD0, Ztf.TinyImageFormat_R8G8B8A8_UNORM, 32);
			add_attribute(&gSphereVertexLayout, Ztf.ZTF_SEMANTIC_TEXCOORD2, Ztf.TinyImageFormat_R8G8B8A8_UNORM, 36);

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

			add_attribute(&gSphereVertexLayout, Ztf.ZTF_SEMANTIC_POSITION, Ztf.TinyImageFormat_R32G32B32_SFLOAT, 0);
			add_attribute(&gSphereVertexLayout, Ztf.ZTF_SEMANTIC_NORMAL, Ztf.TinyImageFormat_R32G32B32_SFLOAT, 16);
			add_attribute(&gSphereVertexLayout, Ztf.ZTF_SEMANTIC_TEXCOORD1, Ztf.TinyImageFormat_R32G32B32_SFLOAT, 32);
			add_attribute(&gSphereVertexLayout, Ztf.ZTF_SEMANTIC_TEXCOORD3, Ztf.TinyImageFormat_R32G32B32_SFLOAT, 32);
			add_attribute(&gSphereVertexLayout, Ztf.ZTF_SEMANTIC_TEXCOORD0, Ztf.TinyImageFormat_R8G8B8A8_UNORM, 12);
			add_attribute(&gSphereVertexLayout, Ztf.ZTF_SEMANTIC_TEXCOORD2, Ztf.TinyImageFormat_R8G8B8A8_UNORM, 28);

			copy_attribute(&gSphereVertexLayout, @ptrCast(bufferData.ptr), 0, 12, vertexCount, @ptrCast(&static.verts));
			copy_attribute(&gSphereVertexLayout, @ptrCast(bufferData.ptr), 12, 3, vertexCount, @ptrCast(&static.sqColors));
			copy_attribute(&gSphereVertexLayout, @ptrCast(bufferData.ptr), 16, 12, vertexCount, @ptrCast(&static.sqNormals));
			copy_attribute(&gSphereVertexLayout, @ptrCast(bufferData.ptr), 28, 3, vertexCount, @ptrCast(&static.spColors));
			copy_attribute(&gSphereVertexLayout, @ptrCast(bufferData.ptr), 32, 12, vertexCount, @ptrCast(&static.sphNormals));
		},
	}

	gSphereIndexCount = @sizeOf(@TypeOf(static.indices)) / @sizeOf(u16);

	const sphereVbDesc = Ztf.ztf_BufferLoadDesc{
		.mDesc = .{
			.mDescriptors = Ztf.ZTF_DESCRIPTOR_TYPE_VERTEX_BUFFER,
			.mMemoryUsage = Ztf.ZTF_RESOURCE_MEMORY_USAGE_GPU_ONLY,
			.mSize = bufferSize,
		},
		.pData = bufferData.ptr,
		.ppBuffer = @ptrCast(&pSphereVertexBuffer),
	};
	Ztf.ztf_addResource(@constCast(&sphereVbDesc), null);

	const sphereIbDesc = Ztf.ztf_BufferLoadDesc{
		.mDesc = .{
			.mDescriptors = Ztf.ZTF_DESCRIPTOR_TYPE_INDEX_BUFFER,
			.mMemoryUsage = Ztf.ZTF_RESOURCE_MEMORY_USAGE_GPU_ONLY,
			.mSize = @sizeOf(@TypeOf(static.indices)),
		},
		.pData = &static.indices,
		.ppBuffer = @ptrCast(&pSphereIndexBuffer),
	};
	Ztf.ztf_addResource(@constCast(&sphereIbDesc), null);

	Ztf.ztf_waitForAllResourceLoads();

	global_alloc.free(bufferData);
}

pub fn add_attribute(layout: *Ztf.ztf_VertexLayout, semantic: Ztf.ztf_ShaderSemantic, format: Ztf.TinyImageFormat, offset: u32) void
{
    const n_attr = layout.*.mAttribCount;
	layout.*.mAttribCount += 1;

    const attr : *Ztf.ztf_VertexAttrib = &(layout.*.mAttribs[n_attr]);

    attr.*.mSemantic = semantic;
    attr.*.mFormat = format;
    attr.*.mBinding = 0;
    attr.*.mLocation = n_attr;
    attr.*.mOffset = offset;
}

pub fn copy_attribute(layout: *Ztf.ztf_VertexLayout, buffer_data: *void, offset: u32, size: u32, vcount: u32, data: *void) void
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