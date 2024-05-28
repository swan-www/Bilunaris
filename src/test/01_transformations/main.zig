const std = @import("std");
const ztf = @import("ztf_bind");
const zmath = @import("zmath");

const Mat = zmath.Mat;
const Vec = zmath.Vec;

/// Demo structures
const PlanetInfoStruct = struct
{
    translation_mat: Mat,
    scale_mat: Mat,
    shared_mat: Mat, // Matrix to pass down to children
    color: Vec,
    parent_index: i32,
    y_orbit_speed: f32, // Rotation speed around parent
    z_orbit_speed: f32,
    rotation_speed: f32, // Rotation speed around self
    morphing_speed: f32, // Speed of morphing betwee cube and sphere
};

const UniformBlock = struct
{
    CameraMatrix mProjectView;
    mat4         mToWorldMat[MAX_PLANETS];
    vec4         mColor[MAX_PLANETS];
    float        mGeometryWeight[MAX_PLANETS][4];

    // Point Light Information
    vec3 mLightPosition;
    vec3 mLightColor;
};

pub fn main() !void {

}