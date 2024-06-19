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
const ZtfMath = Ztf.math;
const ZtfCC = Ztf.camera_controller;
const ZtfGfx = Ztf.gfx;
const ZtfFont = Ztf.font;
const ZtfBString = Ztf.BString;
const BString = ZtfBString.bstring;

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

var pRenderer : ?*ZtfGfx.ztf_Renderer = null;

var pGraphicsQueue : ?*ZtfGfx.ztf_Queue = null;
var gGraphicsCmdRing = RingBuffer.GpuCmdRing{};

var pSwapChain : ?*ZtfGfx.SwapChain = null;
var pDepthBuffer : ?*ZtfGfx.RenderTarget = null;
var pImageAcquiredSemaphore : ?*ZtfGfx.Semaphore = null;

var pSphereShader : ?*ZtfGfx.Shader = null;
var pSphereVertexBuffer : ?*ZtfGfx.Buffer = null;
var pSphereIndexBuffer : ?*ZtfGfx.Buffer = null;
var gSphereIndexCount : u32 = 0;
var pSpherePipeline : ?*ZtfGfx.Pipeline = null;
var gSphereVertexLayout : ?*ZtfGfx.VertexLayout = null;
var gSphereLayoutType : u32 = 0;

var pSkyBoxDrawShader : ?*ZtfGfx.Shader = null;
var pSkyBoxVertexBuffer : ?*ZtfGfx.Buffer = null;
var pSkyBoxDrawPipeline : ?*ZtfGfx.Pipeline = null;
var pRootSignature : ?*ZtfGfx.RootSignature = null;
var pSamplerSkyBox : ?*ZtfGfx.Sampler = null;
var pSkyBoxTextures : [6]?*ZtfGfx.Texture = null ** 6;
var pDescriptorSetTexture : ?*ZtfGfx.DescriptorSet = null;
var pDescriptorSetUniforms : ?*ZtfGfx.DescriptorSet = null;

var pProjViewUniformBuffer : [gDataBufferCount]?*ZtfGfx.Buffer = null ** gDataBufferCount;
var pSkyboxUniformBuffer : [gDataBufferCount]?*ZtfGfx.Buffer = null ** gDataBufferCount;

var gFrameIndex : u32 = 0;
//var gGpuProfileToken : ProfileToken = PROFILE_INVALID_TOKEN;

var gNumberOfSpherePoints : i32 = 0;
var gUniformData = UniformBlock_C{};
var gUniformDataSky = UniformBlockSky_C{};
var gPlanetInfoData = [gNumPlanets]PlanetInfoStruct;

var pCameraController : ?*ZtfCC.ztf_ICameraController = null;

var pGuiWindow : ?*ZtfUI.ztf_UIComponent = null;

var gFontID : u32 = 0;

var pPipelineStatsQueryPool : [gDataBufferCount]?*ZtfGfx.ztf_QueryPool = null ** gDataBufferCount;

var pSkyBoxImageFileNames : [][]const u8 = .{ "Skybox_right1.tex",  "Skybox_left2.tex",  "Skybox_top3.tex",
                                        "Skybox_bottom4.tex", "Skybox_front5.tex", "Skybox_back6.tex" };

var gFrameTimeDraw = ZtfFont.ztf_FontDrawDesc{};

// Generate sky box vertex buffer
const gSkyBoxPoints = []f32{
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

export fn ztf_appInit(_: ?*ztf_App) bool
{
	std.debug.print("ztf_appInit\n", .{});
	return true;
}

export fn ztf_appExit(_: ?*ztf_App) void
{
	std.debug.print("ztf_appExit\n", .{});
}

export fn ztf_appLoad(_: ?*ztf_App, _: [*c]ztf_ReloadDesc) bool
{
	return true;
}

export fn ztf_appUnload(_: ?*ztf_App, _: [*c]ztf_ReloadDesc) void
{

}

export fn ztf_appUpdate(_: ?*ztf_App, _: f32) void
{

}

export fn ztf_appDraw(_: ?*ztf_App) void
{

}

export fn ztf_appGetName(_: ?*ztf_App) [*c]const u8
{
	return "01_TransformationsZig";
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