const std = @import("std");
const zmath = @import("zmath");

const ztf = @import("ztf");
const lun_render = @import("lun_render");

const ztf_ui = ztf.ui;
const ztf_math = ztf.math;
const ztf_cc = ztf.camera_controller;
const ztf_gfx = ztf.gfx;

const Mat4 = zmath.Mat;
const Vec4 = zmath.Vec;

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
    mGeometryWeight : [MAX_PLANETS]ztf_math.ztf_Float4,

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

const GPURingBuffer = lun_render.ringbuffer.GPURingBuffer;

//const pRenderer : *ztf_gfx.ztf_Renderer = NULL;
//
//const pGraphicsQueue : *ztf_gfx.ztf_Queue = NULL;
//GpuCmdRing gGraphicsCmdRing = {};
//
//SwapChain*    pSwapChain = NULL;
//RenderTarget* pDepthBuffer = NULL;
//Semaphore*    pImageAcquiredSemaphore = NULL;
//
//Shader*      pSphereShader = NULL;
//Buffer*      pSphereVertexBuffer = NULL;
//Buffer*      pSphereIndexBuffer = NULL;
//uint32_t     gSphereIndexCount = 0;
//Pipeline*    pSpherePipeline = NULL;
//VertexLayout gSphereVertexLayout = {};
//uint32_t     gSphereLayoutType = 0;
//
//Shader*        pSkyBoxDrawShader = NULL;
//Buffer*        pSkyBoxVertexBuffer = NULL;
//Pipeline*      pSkyBoxDrawPipeline = NULL;
//RootSignature* pRootSignature = NULL;
//Sampler*       pSamplerSkyBox = NULL;
//Texture*       pSkyBoxTextures[6];
//DescriptorSet* pDescriptorSetTexture = { NULL };
//DescriptorSet* pDescriptorSetUniforms = { NULL };
//
//Buffer* pProjViewUniformBuffer[gDataBufferCount] = { NULL };
//Buffer* pSkyboxUniformBuffer[gDataBufferCount] = { NULL };
//
//uint32_t     gFrameIndex = 0;
//ProfileToken gGpuProfileToken = PROFILE_INVALID_TOKEN;
//
//int              gNumberOfSpherePoints;
//UniformBlock     gUniformData;
//UniformBlockSky  gUniformDataSky;
//PlanetInfoStruct gPlanetInfoData[gNumPlanets];
//
//ICameraController* pCameraController = NULL;
//
//UIComponent* pGuiWindow = NULL;
//
//uint32_t gFontID = 0;
//
//QueryPool* pPipelineStatsQueryPool[gDataBufferCount] = {};
//
//const char* pSkyBoxImageFileNames[] = { "Skybox_right1.tex",  "Skybox_left2.tex",  "Skybox_top3.tex",
//                                        "Skybox_bottom4.tex", "Skybox_front5.tex", "Skybox_back6.tex" };
//
//FontDrawDesc gFrameTimeDraw;

pub fn main() !void {
	const mybuf = GPURingBuffer
	{
		.pRenderer = null,
    	.pBuffer = null,
    	.mBufferAlignment = 0,
    	.mMaxBufferSize = 0,
    	.mCurrentBufferOffset = 0,
	};
	_ = &mybuf;
}