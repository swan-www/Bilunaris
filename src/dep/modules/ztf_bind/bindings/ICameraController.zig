const ztf_math = @import("MathTypes");

pub const struct_ICameraController = opaque {};
pub const ICameraController = struct_ICameraController;
pub const struct_CameraMatrix = opaque {};
pub const CameraMatrix = struct_CameraMatrix;
pub const struct_ZTF_CameraMotionParameters = extern struct {
    maxSpeed: f32 = 160.0,
    acceleration: f32 = 600.0,
    braking: f32 = 200.0,
    movementSpeed: f32 = 1.0,
    rotationSpeed: f32 = 1.0,
};
pub const ZTF_CameraMotionParameters = struct_ZTF_CameraMotionParameters;
pub extern fn ztf_cameraMotionParameters_default(...) ZTF_CameraMotionParameters;
pub extern fn ztf_initGuiCameraController(startPosition: ?*const ztf_math.Vector3, startLookAt: ?*const ztf_math.Vector3) ?*ICameraController;
pub extern fn ztf_initFpsCameraController(startPosition: ?*const ztf_math.Vector3, startLookAt: ?*const ztf_math.Vector3) ?*ICameraController;
pub extern fn ztf_exitCameraController(pCamera: ?*ICameraController) void;
pub extern fn ztf_setMotionParameters(pCamera: ?*ICameraController, motionParams: [*c]const ZTF_CameraMotionParameters) void;
pub extern fn ztf_update(pCamera: ?*ICameraController, deltaTime: f32) void;
pub extern fn ztf_getViewMatrix(pCamera: ?*const ICameraController) ?*ztf_math.Matrix4;
pub extern fn ztf_getViewPosition(pCamera: ?*const ICameraController) ?*ztf_math.Vector3;
pub extern fn ztf_getRotationXY(pCamera: ?*const ICameraController) ?*ztf_math.Vector2;
pub extern fn ztf_moveTo(pCamera: ?*ICameraController, location: ?*const ztf_math.Vector3) void;
pub extern fn ztf_lookAt(pCamera: ?*ICameraController, lookAt: ?*const ztf_math.Vector3) void;
pub extern fn ztf_setViewRotationXY(pCamera: ?*ICameraController, v: ?*const ztf_math.Vector2) void;
pub extern fn ztf_resetView(pCamera: ?*ICameraController) void;
pub extern fn ztf_onMove(pCamera: ?*ICameraController, vec: ?*const ztf_math.Float2) void;
pub extern fn ztf_onRotate(pCamera: ?*ICameraController, vec: ?*const ztf_math.Float2) void;
pub extern fn ztf_onZoom(pCamera: ?*ICameraController, vec: ?*const ztf_math.Float2) void;
pub extern fn ztf_camera_matrix_new(...) ?*CameraMatrix;
pub extern fn ztf_camera_matrix_destroy(pCameraMatrix: ?*CameraMatrix) void;
pub extern fn ztf_camera_matrix_assign(pCameraMatrix: ?*CameraMatrix, rhs: ?*const CameraMatrix) void;
pub extern fn ztf_camera_matrix_mul_mat(pCameraMatrix: ?*const CameraMatrix, mat: ?*const ztf_math.Matrix4) ?*CameraMatrix;
pub extern fn ztf_camera_matrix_mul_cam_mat(pCameraMatrix: ?*const CameraMatrix, mat: ?*const CameraMatrix) ?*CameraMatrix;
pub extern fn ztf_getPrimaryMatrix(pCameraMatrix: ?*const CameraMatrix) ?*ztf_math.Matrix4;
pub extern fn ztf_applyProjectionSampleOffset(pCameraMatrix: ?*CameraMatrix, xOffset: f32, yOffset: f32) void;
pub extern fn ztf_inverse(mat: ?*const CameraMatrix) ?*CameraMatrix;
pub extern fn ztf_transpose(mat: ?*const CameraMatrix) ?*CameraMatrix;
pub extern fn ztf_perspective(fovxRadians: f32, aspectInverse: f32, zNear: f32, zFar: f32) ?*CameraMatrix;
pub extern fn ztf_perspectiveReverseZ(fovxRadians: f32, aspectInverse: f32, zNear: f32, zFar: f32) ?*CameraMatrix;
pub extern fn ztf_orthographic(left: f32, right: f32, bottom: f32, top: f32, zNear: f32, zFar: f32) ?*CameraMatrix;
pub extern fn ztf_identity(...) ?*CameraMatrix;
pub extern fn ztf_extractFrustumClipPlanes(vp: ?*const CameraMatrix, rcp: ?*ztf_math.Vector4, lcp: ?*ztf_math.Vector4, tcp: ?*ztf_math.Vector4, bcp: ?*ztf_math.Vector4, fcp: ?*ztf_math.Vector4, ncp: ?*ztf_math.Vector4, normalizePlanes: bool) void;