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
	return initGuiCameraController(*static_cast<Vector3 const*>(startPosition), *static_cast<Vector3 const*>(startLookAt));
}

/// \c initFpsCameraController does basic FPS-style god mode navigation; tf_free-look is constrained
/// to about +/- 88 degrees and WASD translates in the camera's local XZ plane.
ZTF_C_API ICameraController* ztf_initFpsCameraController(const ztf_Vector3* startPosition, const ztf_Vector3* startLookAt)
{
	return initFpsCameraController(*static_cast<Vector3 const*>(startPosition), *static_cast<Vector3 const*>(startLookAt));
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

ZTF_C_API ztf_Matrix4* ztf_getViewMatrix(ICameraController const* pCamera)
{
	return new Matrix4(pCamera->getViewMatrix());
}
ZTF_C_API ztf_Vector3* ztf_getViewPosition(ICameraController const* pCamera)
{
	return new Vector3(pCamera->getViewPosition());
}
ZTF_C_API ztf_Vector2* ztf_getRotationXY(ICameraController const* pCamera)
{
	return new Vector2(pCamera->getRotationXY());
}
ZTF_C_API void ztf_moveTo(ICameraController* pCamera, ztf_Vector3 const* location)
{
	pCamera->moveTo(*static_cast<Vector3 const*>(location));
}
ZTF_C_API void ztf_lookAt(ICameraController* pCamera, ztf_Vector3 const* lookAt)
{
	pCamera->lookAt(*static_cast<Vector3 const*>(lookAt));
}
ZTF_C_API void ztf_setViewRotationXY(ICameraController* pCamera, ztf_Vector2 const* v)
{
	pCamera->setViewRotationXY(*static_cast<Vector2 const*>(v));
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
ZTF_C_API CameraMatrix* ztf_camera_matrix_new()
{
	return new CameraMatrix();
}
ZTF_C_API void ztf_camera_matrix_destroy(CameraMatrix* pCameraMatrix) 
{
	if(pCameraMatrix)
	{
		delete pCameraMatrix;
	}
}

ZTF_C_API void ztf_camera_matrix_assign(CameraMatrix* pCameraMatrix, CameraMatrix const* rhs)
{
	(*pCameraMatrix) = (*rhs);
}
ZTF_C_API CameraMatrix* ztf_camera_matrix_mul_mat(CameraMatrix const* pCameraMatrix, ztf_Matrix4 const* mat)
{
	return new CameraMatrix(pCameraMatrix->operator*(*static_cast<Matrix4 const*>(mat)));
}
ZTF_C_API CameraMatrix* ztf_camera_matrix_mul_cam_mat(CameraMatrix const* pCameraMatrix, CameraMatrix const* mat)
{
	return new CameraMatrix(pCameraMatrix->operator*(*mat));
}

// Returns the camera matrix or the left eye matrix on VR platforms.
ZTF_C_API ztf_Matrix4* ztf_getPrimaryMatrix(CameraMatrix const* pCameraMatrix)
{
	return new Matrix4(pCameraMatrix->getPrimaryMatrix());
}

// Applies offsets to the projection matrices (useful when needing to jitter the camera for techniques like TAA)
ZTF_C_API void ztf_applyProjectionSampleOffset(CameraMatrix* pCameraMatrix, float xOffset, float yOffset)
{
	pCameraMatrix->applyProjectionSampleOffset(xOffset, yOffset);
}

ZTF_C_API CameraMatrix* ztf_inverse(const CameraMatrix* mat)
{
	return new CameraMatrix(CameraMatrix::inverse(*mat));
}

ZTF_C_API CameraMatrix* ztf_transpose(const CameraMatrix* mat)
{
	return new CameraMatrix(CameraMatrix::transpose(*mat));
}

ZTF_C_API CameraMatrix* ztf_perspective(float fovxRadians, float aspectInverse, float zNear, float zFar)
{
	return new CameraMatrix(CameraMatrix::perspective(fovxRadians, aspectInverse, zNear, zFar));
}

ZTF_C_API CameraMatrix* ztf_perspectiveReverseZ(float fovxRadians, float aspectInverse, float zNear, float zFar)
{
	return new CameraMatrix(CameraMatrix::perspectiveReverseZ(fovxRadians, aspectInverse, zNear, zFar));
}

ZTF_C_API CameraMatrix* ztf_orthographic(float left, float right, float bottom, float top, float zNear, float zFar)
{
	return new CameraMatrix(CameraMatrix::orthographic(left, right, bottom, top, zNear, zFar));
}

ZTF_C_API CameraMatrix* ztf_identity()
{
	return new CameraMatrix(CameraMatrix::identity());
}

ZTF_C_API void ztf_extractFrustumClipPlanes(const CameraMatrix* vp, ztf_Vector4* rcp, ztf_Vector4* lcp, ztf_Vector4* tcp, ztf_Vector4* bcp, ztf_Vector4* fcp, ztf_Vector4* ncp, bool const normalizePlanes)
{
	CameraMatrix::extractFrustumClipPlanes(*vp, *static_cast<Vector4*>(rcp), *static_cast<Vector4*>(lcp), *static_cast<Vector4*>(tcp), *static_cast<Vector4*>(bcp), *static_cast<Vector4*>(fcp), *static_cast<Vector4*>(ncp), normalizePlanes);
}

//END CameraMatrix

#ifdef __cplusplus
}
#endif