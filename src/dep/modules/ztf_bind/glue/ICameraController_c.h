#pragma once
#include <stdbool.h> 

#include "ztf_bind_common.h"
#include "MathTypes_glue.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct ICameraController ICameraController;
typedef struct CameraMatrix CameraMatrix;

typedef struct ZTF_CameraMotionParameters
{
	float maxSpeed;
	float acceleration;	
	float braking;		
	float movementSpeed;
	float rotationSpeed;
} ZTF_CameraMotionParameters;

ZTF_C_API ZTF_CameraMotionParameters ztf_cameraMotionParameters_default();

/// \c initGuiCameraController assumes that the camera is not rotated around the look direction;
/// in its matrix, \c Z points at \c startLookAt and \c X is horizontal.
ZTF_C_API ICameraController* ztf_initGuiCameraController(const ztf_Vector3* startPosition, const ztf_Vector3* startLookAt);

/// \c initFpsCameraController does basic FPS-style god mode navigation; tf_free-look is constrained
/// to about +/- 88 degrees and WASD translates in the camera's local XZ plane.
ZTF_C_API ICameraController* ztf_initFpsCameraController(const ztf_Vector3* startPosition, const ztf_Vector3* startLookAt);

ZTF_C_API void ztf_exitCameraController(ICameraController* pCamera);

//BEGIN ICameraController

ZTF_C_API void ztf_setMotionParameters(ICameraController* pCamera, ZTF_CameraMotionParameters const* motionParams);
ZTF_C_API void ztf_update(ICameraController* pCamera, float deltaTime);

// there are also implicit dependencies on the keyboard state.

ZTF_C_API ztf_Matrix4* ztf_getViewMatrix(ICameraController const* pCamera);
ZTF_C_API ztf_Vector3* ztf_getViewPosition(ICameraController const* pCamera);
ZTF_C_API ztf_Vector2* ztf_getRotationXY(ICameraController const* pCamera);
ZTF_C_API void ztf_moveTo(ICameraController* pCamera, ztf_Vector3 const* location);
ZTF_C_API void ztf_lookAt(ICameraController* pCamera, ztf_Vector3 const* lookAt);
ZTF_C_API void ztf_setViewRotationXY(ICameraController* pCamera, ztf_Vector2 const* v);
ZTF_C_API void ztf_resetView(ICameraController* pCamera);

ZTF_C_API void ztf_onMove(ICameraController* pCamera, ztf_Float2 vec);
ZTF_C_API void ztf_onRotate(ICameraController* pCamera, ztf_Float2 vec);
ZTF_C_API void ztf_onZoom(ICameraController* pCamera, ztf_Float2 vec);

//END ICameraController

//BEGIN CameraMatrix
ZTF_C_API CameraMatrix* ztf_camera_matrix_new();
ZTF_C_API void ztf_camera_matrix_destroy(CameraMatrix* pCameraMatrix);

ZTF_C_API void ztf_camera_matrix_assign(CameraMatrix* pCameraMatrix, CameraMatrix const* rhs);
ZTF_C_API CameraMatrix* ztf_camera_matrix_mul_mat(CameraMatrix const* pCameraMatrix, ztf_Matrix4 const* mat);
ZTF_C_API CameraMatrix* ztf_camera_matrix_mul_cam_mat(CameraMatrix const* pCameraMatrix, CameraMatrix const* mat);

// Returns the camera matrix or the left eye matrix on VR platforms.
ZTF_C_API ztf_Matrix4* ztf_getPrimaryMatrix(CameraMatrix const* pCameraMatrix);

// Applies offsets to the projection matrices (useful when needing to jitter the camera for techniques like TAA)
ZTF_C_API void ztf_applyProjectionSampleOffset(CameraMatrix* pCameraMatrix, float xOffset, float yOffset);

ZTF_C_API CameraMatrix * ztf_inverse(const CameraMatrix* mat);
ZTF_C_API CameraMatrix * ztf_transpose(const CameraMatrix* mat);
ZTF_C_API CameraMatrix * ztf_perspective(float fovxRadians, float aspectInverse, float zNear, float zFar);
ZTF_C_API CameraMatrix * ztf_perspectiveReverseZ(float fovxRadians, float aspectInverse, float zNear, float zFar);
ZTF_C_API CameraMatrix * ztf_orthographic(float left, float right, float bottom, float top, float zNear, float zFar);
ZTF_C_API CameraMatrix * ztf_identity();
ZTF_C_API void ztf_extractFrustumClipPlanes(const CameraMatrix* vp, ztf_Vector4* rcp, ztf_Vector4* lcp, ztf_Vector4* tcp, ztf_Vector4* bcp, ztf_Vector4* fcp, ztf_Vector4* ncp, bool const normalizePlanes);
//END CameraMatrix

#ifdef __cplusplus
}
#endif