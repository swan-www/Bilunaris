#include <new>

#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/Utilities/Math/MathTypes.h"
#include "MathTypes_glue.h"

ztf_Vector3 make_vec3(float x, float y, float z)
{
	vec3 temp(x, y ,z);
	return *(ztf_Vector3*)&temp;
}

ztf_Vector4 make_vec4(float x, float y, float z, float w)
{
	vec4 temp(x, y ,z, w);
	return *(ztf_Vector4*)&temp;
}

ztf_Vector3d make_vec3d(double x, double y, double z)
{
	vec3d temp(x, y ,z);
	return *(ztf_Vector3d*)&temp;
}

ztf_Vector4d make_vec4d(double x, double y, double z, double w)
{
	vec4d temp(x, y ,z, w);
	return *(ztf_Vector4d*)&temp;
}

ztf_IVector3 make_ivec3(int32_t x, int32_t y, int32_t z)
{
	ivec3 temp(x, y ,z);
	return *(ztf_IVector3*)&temp;
}

ztf_IVector4 make_ivec4(int32_t x, int32_t y, int32_t z, int32_t w)
{
	ivec4 temp(x, y ,z, w);
	return *(ztf_IVector4*)&temp;
}

ztf_UVector3 make_uvec3(uint32_t x, uint32_t y, uint32_t z)
{
	uvec3 temp(x, y ,z);
	return *(ztf_UVector3*)&temp;
}

ztf_UVector4 make_uvec4(uint32_t x, uint32_t y, uint32_t z, uint32_t w)
{
	uvec4 temp(x, y ,z, w);
	return *(ztf_UVector4*)&temp;
}

ztf_Matrix3 mat3_identity()
{
	mat3 temp(
		vec3(1.0f, 0.0f, 0.0f),
		vec3(0.0f, 1.0f, 0.0f),
		vec3(0.0f, 0.0f, 1.0f)
	);
	return *(ztf_Matrix3*)&temp;
}

ztf_Matrix4 mat4_identity()
{
	mat4 temp(
		vec4(1.0f, 0.0f, 0.0f, 0.0f),
		vec4(0.0f, 1.0f, 0.0f, 0.0f),
		vec4(0.0f, 0.0f, 1.0f, 0.0f),
		vec4(0.0f, 0.0f, 0.0f, 1.0f)
	);
	return *(ztf_Matrix4*)&temp;
}

ztf_Matrix3d mat3d_identity()
{
	mat3d temp(
		vec3d(1.0, 0.0, 0.0),
		vec3d(0.0, 1.0, 0.0),
		vec3d(0.0, 0.0, 1.0)
	);
	return *(ztf_Matrix3d*)&temp;
}

ztf_Matrix4d mat4d_identity()
{
	mat4d temp(
		vec4d(1.0, 0.0, 0.0, 0.0),
		vec4d(0.0, 1.0, 0.0, 0.0),
		vec4d(0.0, 0.0, 1.0, 0.0),
		vec4d(0.0, 0.0, 0.0, 1.0)
	);
	return *(ztf_Matrix4d*)&temp;
}

ztf_Matrix4 mat4_from_translation(const ztf_Vector3* translation)
{
	mat4 temp = mat4::translation(*(const vec3*)translation);
	return *(ztf_Matrix4*)&temp;
}

ztf_Matrix4 mat4_from_scale(const ztf_Vector3* scale)
{
	mat4 temp = mat4::scale(*(const vec3*)scale);
	return *(ztf_Matrix4*)&temp;
}

ztf_Matrix4 mat4_from_rotationXYZ(const ztf_Vector3* radiansXYZ)
{
	mat4 temp = mat4::rotationZYX(*(const vec3*)radiansXYZ);
	return *(ztf_Matrix4*)&temp;
}

void mat4_mul(const ztf_Matrix4* lhs, const ztf_Matrix4* rhs, ztf_Matrix4* out_mat)
{
	const mat4* lhsCast = (mat4*)lhs;
	const mat4* rhsCast = (mat4*)rhs;
	mat4* outMatCast = (mat4*)out_mat;
	*outMatCast = (*lhsCast) * (*rhsCast);
}

void mat4_set_translation(ztf_Matrix4* mat, const ztf_Vector3* translation)
{
	mat4* matCast = (mat4*)mat;
	matCast->setTranslation(*(vec3*)translation);
}

ztf_Vector3 mat4_get_translation(const ztf_Matrix4* mat)
{
	mat4* matCast = (mat4*)mat;
	vec3 result = matCast->getTranslation();
	return *(const ztf_Vector3*)&result;
}
