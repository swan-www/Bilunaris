#include "ICameraController_c.h"
#include "MathTypes_glue.h"

#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/Application/Interfaces/ICameraController.h"

#ifdef __cplusplus
extern "C"
{
#endif

ZTF_C_API ZTF_CameraMotionParameters ztf_cameraMotionParameters_default()
{
	return ZTF_CameraMotionParameters
	{
		.maxSpeed = 160.0f,
		.acceleration = 600.0f,
		.braking = 200.0f,
		.movementSpeed = 1.0f,
		.rotationSpeed = 1.0f
	};
}

/// \c initGuiCameraController assumes that the camera is not rotated around the look direction;
/// in its matrix, \c Z points at \c startLookAt and \c X is horizontal.
ZTF_C_API ICameraController* ztf_initGuiCameraController(const ztf_Vector3* startPosition, const ztf_Vector3* startLookAt)
{
	return initGuiCameraController(*(Vector3 const*)(startPosition), *(Vector3 const*)(startLookAt));
}

/// \c initFpsCameraController does basic FPS-style god mode navigation; tf_free-look is constrained
/// to about +/- 88 degrees and WASD translates in the camera's local XZ plane.
ZTF_C_API ICameraController* ztf_initFpsCameraController(const ztf_Vector3* startPosition, const ztf_Vector3* startLookAt)
{
	return initFpsCameraController(*(Vector3 const*)(startPosition), *(Vector3 const*)(startLookAt));
}

ZTF_C_API void ztf_exitCameraController(ICameraController* pCamera)
{
	exitCameraController(pCamera);
}

//BEGIN ICameraController

ZTF_C_API void ztf_setMotionParameters(ICameraController* pCamera, const ZTF_CameraMotionParameters* motionParams)
{
	CameraMotionParameters camMotionParams{};
	camMotionParams.maxSpeed		= motionParams->maxSpeed;
	camMotionParams.acceleration	= motionParams->acceleration;
	camMotionParams.braking			= motionParams->braking;
	camMotionParams.movementSpeed	= motionParams->movementSpeed;
	camMotionParams.rotationSpeed	= motionParams->rotationSpeed;

	pCamera->setMotionParameters(camMotionParams);
}

ZTF_C_API void ztf_update(ICameraController* pCamera, float deltaTime)
{
	pCamera->update(deltaTime);
}

// there are also implicit dependencies on the keyboard state.

ZTF_C_API ztf_Matrix4 ztf_getViewMatrix(ICameraController const* pCamera)
{
	Matrix4 src = pCamera->getViewMatrix();
	ztf_Matrix4 dst{};
	static_assert(sizeof(dst) == sizeof(src));
	memcpy(&dst, &src, sizeof(dst));
	return dst;
}
ZTF_C_API ztf_Vector3 ztf_getViewPosition(ICameraController const* pCamera)
{
	Vector3 src = pCamera->getViewPosition();
	ztf_Vector3 dst{};
	static_assert(sizeof(dst) == sizeof(src));
	memcpy(&dst, &src, sizeof(dst));
	return dst;
}
ZTF_C_API ztf_Vector2 ztf_getRotationXY(ICameraController const* pCamera)
{
	Vector2 src = pCamera->getRotationXY();
	ztf_Vector2 dst{};
	static_assert(sizeof(dst) == sizeof(src));
	memcpy(&dst, &src, sizeof(dst));
	return dst;
}
ZTF_C_API void ztf_moveTo(ICameraController* pCamera, ztf_Vector3 const* location)
{
	pCamera->moveTo(*(Vector3 const*)(location));
}
ZTF_C_API void ztf_lookAt(ICameraController* pCamera, ztf_Vector3 const* lookAt)
{
	pCamera->lookAt(*(Vector3 const*)(lookAt));
}
ZTF_C_API void ztf_setViewRotationXY(ICameraController* pCamera, ztf_Vector2 const* v)
{
	pCamera->setViewRotationXY(*(Vector2 const*)(v));
}
ZTF_C_API void ztf_resetView(ICameraController* pCamera)
{
	pCamera->resetView();
}

ZTF_C_API void ztf_onMove(ICameraController* pCamera, ztf_Float2 vec)
{
	pCamera->onMove(float2{vec.x, vec.y});
}

ZTF_C_API void ztf_onRotate(ICameraController* pCamera, ztf_Float2 vec)
{
	pCamera->onRotate(float2{vec.x, vec.y});
}

ZTF_C_API void ztf_onZoom(ICameraController* pCamera, ztf_Float2 vec)
{
	pCamera->onZoom(float2{vec.x, vec.y});
}
//END ICameraController

//BEGIN CameraMatrix

ZTF_C_API ZTF_CameraMatrix ztf_camera_matrix_mul_mat(ZTF_CameraMatrix const* pCameraMatrix, ztf_Matrix4 const* mat)
{
	ZTF_CameraMatrix dst{};
	CameraMatrix src =  ((CameraMatrix const*)pCameraMatrix)->operator*(*(Matrix4 const*)(mat));
	static_assert(sizeof(dst) == sizeof(src));
	memcpy(&dst, &src, sizeof(CameraMatrix));
	return dst;

}
ZTF_C_API ZTF_CameraMatrix ztf_camera_matrix_mul_cam_mat(ZTF_CameraMatrix const* pCameraMatrix, ZTF_CameraMatrix const* mat)
{
	ZTF_CameraMatrix dst{};
	CameraMatrix src =  ((CameraMatrix const*)pCameraMatrix)->operator*(*(CameraMatrix const*)(mat));
	static_assert(sizeof(dst) == sizeof(src));
	memcpy(&dst, &src, sizeof(CameraMatrix));
	return dst;
}

// Returns the camera matrix or the left eye matrix on VR platforms.
ZTF_C_API ztf_Matrix4 ztf_getPrimaryMatrix(ZTF_CameraMatrix const* pCameraMatrix)
{
	Matrix4 src = ((CameraMatrix const*)pCameraMatrix)->getPrimaryMatrix();
	ztf_Matrix4 dst{};
	static_assert(sizeof(dst) == sizeof(src));
	memcpy(&dst, &src, sizeof(dst));
	return dst;
}

// Applies offsets to the projection matrices (useful when needing to jitter the camera for techniques like TAA)
ZTF_C_API void ztf_applyProjectionSampleOffset(ZTF_CameraMatrix* pCameraMatrix, float xOffset, float yOffset)
{
	((CameraMatrix*)pCameraMatrix)->applyProjectionSampleOffset(xOffset, yOffset);
}

ZTF_C_API ZTF_CameraMatrix ztf_inverse(const ZTF_CameraMatrix* mat)
{
	ZTF_CameraMatrix dst{};
	CameraMatrix src = CameraMatrix::inverse((*(CameraMatrix const*)mat));
	static_assert(sizeof(dst) == sizeof(src));
	memcpy(&dst, &src, sizeof(CameraMatrix));
	return dst;
}

ZTF_C_API ZTF_CameraMatrix ztf_transpose(const ZTF_CameraMatrix* mat)
{
	ZTF_CameraMatrix dst{};
	CameraMatrix src = CameraMatrix::transpose((*(CameraMatrix const*)mat));
	static_assert(sizeof(dst) == sizeof(src));
	memcpy(&dst, &src, sizeof(CameraMatrix));
	return dst;
}

ZTF_C_API ZTF_CameraMatrix ztf_perspective(float fovxRadians, float aspectInverse, float zNear, float zFar)
{
	ZTF_CameraMatrix dst{};
	CameraMatrix src = CameraMatrix::perspective(fovxRadians, aspectInverse, zNear, zFar);
	static_assert(sizeof(dst) == sizeof(src));
	memcpy(&dst, &src, sizeof(CameraMatrix));
	return dst;
}

ZTF_C_API ZTF_CameraMatrix ztf_perspectiveReverseZ(float fovxRadians, float aspectInverse, float zNear, float zFar)
{
	ZTF_CameraMatrix dst{};
	CameraMatrix src = CameraMatrix::perspectiveReverseZ(fovxRadians, aspectInverse, zNear, zFar);
	static_assert(sizeof(dst) == sizeof(src));
	memcpy(&dst, &src, sizeof(CameraMatrix));
	return dst;
}

ZTF_C_API ZTF_CameraMatrix ztf_orthographic(float left, float right, float bottom, float top, float zNear, float zFar)
{
	ZTF_CameraMatrix dst{};
	CameraMatrix src = CameraMatrix::orthographic(left, right, bottom, top, zNear, zFar);
	static_assert(sizeof(dst) == sizeof(src));
	memcpy(&dst, &src, sizeof(CameraMatrix));
	return dst;
}

ZTF_C_API ZTF_CameraMatrix ztf_identity()
{
	ZTF_CameraMatrix dst{};
	CameraMatrix src = CameraMatrix::identity();
	static_assert(sizeof(dst) == sizeof(src));
	memcpy(&dst, &src, sizeof(CameraMatrix));
	return dst;
}

ZTF_C_API void ztf_extractFrustumClipPlanes(const ZTF_CameraMatrix* vp, ztf_Vector4* rcp, ztf_Vector4* lcp, ztf_Vector4* tcp, ztf_Vector4* bcp, ztf_Vector4* fcp, ztf_Vector4* ncp, bool const normalizePlanes)
{
	CameraMatrix::extractFrustumClipPlanes(*(CameraMatrix const*)vp, *(Vector4*)(rcp), *(Vector4*)(lcp), *(Vector4*)(tcp), *(Vector4*)(bcp), *(Vector4*)(fcp), *(Vector4*)(ncp), normalizePlanes);
}

//END CameraMatrix

#ifdef __cplusplus
}
#endif