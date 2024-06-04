#pragma once
#include <stdint.h>

#include "ztf_bind_common.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct ztf_Float2 { float x, y; } ztf_Float2;
typedef struct ztf_Float3 { float x, y, z; } ztf_Float3;
typedef struct ztf_Float4 { float x, y, z, w; } ztf_Float4;

typedef void ztf_Int2;

typedef void ztf_Vector2;
typedef void ztf_Vector3;
typedef void ztf_Vector4;

typedef void ztf_IVector2;
typedef void ztf_IVector3;
typedef void ztf_IVector4;

typedef void ztf_UVector2;
typedef void ztf_UVector3;
typedef void ztf_UVector4;

typedef void ztf_Matrix2;
typedef void ztf_Matrix3;
typedef void ztf_Matrix4;

ZTF_C_API ztf_Int2* ztf_int2_new(int const* in_int_array);
ZTF_C_API void 		ztf_int2_delete(ztf_Int2* in_float2);

ZTF_C_API ztf_Vector2* 	ztf_vec2_new(float const * in_float_array);
ZTF_C_API void 		ztf_vec2_delete(ztf_Vector2* in_vec2);
ZTF_C_API ztf_Vector3* 	ztf_vec3_new(float const * in_float_array);
ZTF_C_API void 		ztf_vec3_delete(ztf_Vector3* in_vec3);
ZTF_C_API ztf_Vector4* 	ztf_vec4_new(float const * in_float_array);
ZTF_C_API void 		ztf_vec4_delete(ztf_Vector4* in_vec4);

ZTF_C_API ztf_IVector2* ztf_ivec2_new(int32_t const* in_int_array);
ZTF_C_API void 		ztf_ivec2_delete(ztf_IVector2* in_ivec2);
ZTF_C_API ztf_IVector3* ztf_ivec3_new(int32_t const* in_int_array);
ZTF_C_API void 		ztf_ivec3_delete(ztf_IVector3* in_ivec3);
ZTF_C_API ztf_IVector4* ztf_ivec4_new(int32_t const* in_int_array);
ZTF_C_API void 		ztf_ivec4_delete(ztf_IVector4* in_ivec4);

ZTF_C_API ztf_UVector2* ztf_uvec2_new(uint32_t const* in_uint_array);
ZTF_C_API void 		ztf_uvec2_delete(ztf_UVector2* in_uvec2);
ZTF_C_API ztf_UVector3* ztf_uvec3_new(uint32_t const* in_uint_array);
ZTF_C_API void 		ztf_uvec3_delete(ztf_UVector3* in_uvec3);
ZTF_C_API ztf_UVector4* ztf_uvec4_new(uint32_t const* in_uint_array);
ZTF_C_API void 		ztf_uvec4_delete(ztf_UVector4* in_uvec4);

ZTF_C_API ztf_Matrix2* 	ztf_mat2_new(float const* in_float_array);
ZTF_C_API void 		ztf_mat2_delete(ztf_Matrix2* in_mat2);
ZTF_C_API ztf_Matrix3* 	ztf_mat3_new(float const* in_float_array);
ZTF_C_API void 		ztf_mat3_delete(ztf_Matrix3* in_mat3);
ZTF_C_API ztf_Matrix4* 	ztf_mat4_new(float const* in_float_array);
ZTF_C_API void 		ztf_mat4_delete(ztf_Matrix4* in_mat4);

#ifdef __cplusplus
}
#endif