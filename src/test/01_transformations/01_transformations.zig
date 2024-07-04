const std = @import("std");
const zmath = @import("zmath");

const Mat4 = zmath.Mat;
const Vec4 = zmath.Vec;

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
const ZtfBString = Ztf.BString;
const BString = ZtfBString.bstring;
const ZtfRL = Ztf.resource_loader;

usingnamespace ZtfGfx;

const LunRender = @import("lun_render");

const RingBuffer = LunRender.ringbuffer;

const ZtfExt = @import("ztf_ext");

const MAX_PLANETS = 20;
const QUEST_VR : bool = false;
const CameraMatrix_C =
switch(QUEST_VR){
	true => extern struct
	{
		mLeftEye : Mat4,
		mRightEye : Mat4,
	},
	false => extern struct
	{
		mCamera : Mat4
	},
};

const PlanetInfoStruct = struct
{
	mTranslationMat : Mat4,
    mScaleMat : Mat4,
    mSharedMat : Mat4, // Matrix to pass down to children
	mColor : Vec4,
	mParentIndex : u32,
    mYOrbitSpeed : f32, // Rotation speed around parent
    mZOrbitSpeed : f32,
    mRotationSpeed : f32, // Rotation speed around self
    mMorphingSpeed : f32, // Speed of morphing betwee cube and sphere
};

const UniformBlock_C = extern struct
{
    mProjectView : CameraMatrix_C,
    mToWorldMat : [MAX_PLANETS]Mat4,
    mColor : [MAX_PLANETS]Vec4,
    mGeometryWeight : [MAX_PLANETS]ZtfMath.ztf_Float4,

    // Point Light Information
    mLightPosition : @Vector(3, f32),
    mLightColor : @Vector(3, f32),
};

const UniformBlockSky_C = extern struct
{
	mProjectView : CameraMatrix_C,
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
var gSphereVertexLayout : ?*ZtfGfx.ztf_VertexLayout = null;
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
//var gGpuProfileToken : ProfileToken = PROFILE_INVALID_TOKEN;

var gNumberOfSpherePoints : i32 = 0;
var gUniformData = UniformBlock_C{};
var gUniformDataSky = UniformBlockSky_C{};
var gPlanetInfoData = [gNumPlanets]PlanetInfoStruct;

var pCameraController : ?*ZtfCC.ztf_ICameraController = null;

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

var gPipelineStatsCharArray : [2048]u8 = 0;
var gPipelineStats : BString = ZtfExt.bfromarr(gPipelineStatsCharArray);

const gWindowTestScripts : [][]const u8 = .{ "TestFullScreen.lua", "TestCenteredWindow.lua", "TestNonCenteredWindow.lua", "TestBorderless.lua" };

fn reloadRequest(_ : *anyopaque) void
{
    const reload = ztf_ReloadDesc{ .mType = ZtfOS.ZTF_RELOAD_TYPE_SHADER };
    ZtfOS.ztf_requestReload(&reload);
}

pub export fn ztf_appInit(pApp: ?*ztf_App) callconv(.C) bool
{
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

	//Input System
	var input_desc = ZtfInput.ztf_InputSystemDesc{
		.pRenderer = @ptrCast(pRenderer),
		.pWindow =  @ptrCast(window_desc),
		.pJoystickTexture = "circlepad.tex",
	};
	_ = &input_desc;
	if (!ZtfInput.ztf_initInputSystem(&input_desc)) return false;

	return true;
}

fn rendererExit(_: ?*ztf_App) void
{
	if(pRendererOpt == null)
	{
		return;
	}

	ZtfInput.ztf_exitInputSystem();

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
}

pub export fn ztf_appLoad(_: ?*ztf_App, _: [*c]ztf_ReloadDesc) callconv(.C) bool
{
	return true;
}

pub export fn ztf_appUnload(_: ?*ztf_App, _: [*c]ztf_ReloadDesc) callconv(.C) void
{

}

pub export fn ztf_appUpdate(_: ?*ztf_App, _: f32) callconv(.C) void
{

}

pub export fn ztf_appDraw(_: ?*ztf_App) callconv(.C) void
{

}

pub export fn ztf_appGetName(_: ?*ztf_App) callconv(.C) [*c]const u8
{
	return "01_TransformationsZig";
}

pub extern fn main(argc: c_int, argv: **const c_char) c_int;

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