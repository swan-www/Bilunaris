#pragma once
#include <stdint.h>

#include "ztf_bind_common.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef void ztf_Int2;
typedef void ztf_Float2;

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
ZTF_C_API ztf_Float2*	ztf_float2_new(float const* in_float_array);
ZTF_C_API void 		ztf_float2_delete(ztf_Float2* in_float2);

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

/*
typedef float* vec2_glue;
typedef float* vec3_glue;
typedef float* vec4_glue;

typedef int32_t* ivec2_glue;
typedef int32_t* ivec3_glue;
typedef int32_t* ivec4_glue;

typedef uint32_t* uvec2_glue;
typedef uint32_t* uvec3_glue;
typedef uint32_t* uvec4_glue;

struct mat2_glue
{
	vec2_glue row0;
	vec2_glue row1;
};

struct mat3_glue
{
	vec3_glue row0;
	vec3_glue row1;
	vec3_glue row2;
};

struct mat4_glue
{
	vec4_glue row0;
	vec4_glue row1;
	vec4_glue row2;
	vec4_glue row3;
};

// Stores the elements of in_glue to in_vec. in_glue must be aligned to 4 bytes.
void store_vec2_glue(vec2_glue in_glue, const vec2& in_vec);
// Stores the elements of in_glue to in_vec. in_glue must be aligned to 4 bytes.
void store_vec3_glue(vec3_glue in_glue, const vec3& in_vec);
// Stores the elements of in_glue to in_vec. in_glue must be aligned to 4 bytes.
void store_vec4_glue(vec4_glue in_glue, const vec4& in_vec);
// Stores the elements of in_glue to in_vec. in_glue must be aligned to 4 bytes.
void store_ivec2_glue(ivec2_glue in_glue, const ivec2& in_vec);
// Stores the elements of in_glue to in_vec. in_glue must be aligned to 4 bytes.
void store_ivec3_glue(ivec3_glue in_glue, const ivec3& in_vec);
// Stores the elements of in_glue to in_vec. in_glue must be aligned to 4 bytes.
void store_ivec4_glue(ivec4_glue in_glue, const ivec4& in_vec);
// Stores the elements of in_glue to in_vec. in_glue must be aligned to 4 bytes.
void store_uvec2_glue(uvec2_glue in_glue, const uvec2& in_vec);
// Stores the elements of in_glue to in_vec. in_glue must be aligned to 4 bytes.
void store_uvec3_glue(uvec3_glue in_glue, const uvec3& in_vec);
// Stores the elements of in_glue to in_vec. in_glue must be aligned to 4 bytes.
void store_uvec4_glue(uvec4_glue in_glue, const uvec4& in_vec);
// Stores the elements of in_glue to in_vec. in_glue must be aligned to 16 bytes.
void store_mat2_glue(mat2_glue in_glue, const mat2& in_mat);
// Stores the elements of in_glue to in_vec. in_glue must be aligned to 16 bytes.
void store_mat3_glue(mat3_glue in_glue, const mat3& in_mat);
// Stores the elements of in_glue to in_vec. in_glue must be aligned to 16 bytes.
void store_mat4_glue(mat4_glue in_glue, const mat4& in_mat);

// Loads the elements of in_vec to in_glue. in_glue must be aligned to 4 bytes.
void load_vec2_glue(const vec2_glue in_glue, vec2& in_vec);
// Loads the elements of in_vec to in_glue. in_glue must be aligned to 4 bytes.
void load_vec3_glue(const vec3_glue in_glue, vec3& in_vec);
// Loads the elements of in_vec to in_glue. in_glue must be aligned to 4 bytes.
void load_vec4_glue(const vec4_glue in_glue, vec4& in_vec);
// Loads the elements of in_vec to in_glue. in_glue must be aligned to 4 bytes.
void load_ivec2_glue(const ivec2_glue in_glue, ivec2& in_vec);
// Loads the elements of in_vec to in_glue. in_glue must be aligned to 4 bytes.
void load_ivec3_glue(const ivec3_glue in_glue, ivec3& in_vec);
// Loads the elements of in_vec to in_glue. in_glue must be aligned to 4 bytes.
void load_ivec4_glue(const ivec4_glue in_glue, ivec4& in_vec);
// Loads the elements of in_vec to in_glue. in_glue must be aligned to 4 bytes.
void load_uvec2_glue(const uvec2_glue in_glue, uvec2& in_vec);
// Loads the elements of in_vec to in_glue. in_glue must be aligned to 4 bytes.
void load_uvec3_glue(const uvec3_glue in_glue, uvec3& in_vec);
// Loads the elements of in_vec to in_glue. in_glue must be aligned to 4 bytes.
void load_uvec4_glue(const uvec4_glue in_glue, uvec4& in_vec);
// Loads the elements of in_vec to in_glue. in_glue must be aligned to 16 bytes.
void load_mat2_glue(const mat2_glue in_glue, mat2& in_mat);
// Loads the elements of in_vec to in_glue. in_glue must be aligned to 16 bytes.
void load_mat3_glue(const mat3_glue in_glue, mat3& in_mat);
// Loads the elements of in_vec to in_glue. in_glue must be aligned to 16 bytes.
void load_mat4_glue(const mat4_glue in_glue, mat4& in_mat);
*/