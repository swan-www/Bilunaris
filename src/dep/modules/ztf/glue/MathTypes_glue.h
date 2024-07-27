#pragma once
#include <stdint.h>
#include <stdalign.h>

#include "ztf_bind_common.h"

#ifdef __cplusplus
extern "C"
{
#endif

#if defined(_MSC_VER)
    // Visual Studio (MS compiler)
    #define ZTF_VECTORMATH_ALIGNED(type)      __declspec(align(16)) type
    #define ZTF_VECTORMATH_ALIGNED_TYPE_PRE   __declspec(align(16))
    #define ZTF_VECTORMATH_ALIGNED_TYPE_POST  /* nothing */
#elif defined(__GNUC__)
    // GCC or Clang
    #define ZTF_VECTORMATH_ALIGNED(type)      type __attribute__((aligned(16)))
    #define ZTF_VECTORMATH_ALIGNED_TYPE_PRE   /* nothing */
    #define ZTF_VECTORMATH_ALIGNED_TYPE_POST  __attribute__((aligned(16)))
#else
    // Unknown compiler
    #error "Define ZTF_VECTORMATH_ALIGNED for your compiler or platform!"
#endif

#if defined(XBOX)
#elif defined(_WINDOWS)
#include <xmmintrin.h>
#include <emmintrin.h>
typedef __m64 ztf_vec_f64;
typedef __m128 ztf_vec_f128;
typedef __m128i ztf_vec_i128;
typedef __m128d ztf_vec_d128;
#elif defined(TARGET_IOS)
#elif defined(__APPLE__)
#elif defined(__ANDROID__)
#elif defined(__linux__)
#elif defined(NX64)
#elif defined(ORBIS)
#elif defined(PROSPERO)
#endif

typedef unsigned int uint;

struct ztf_Float2 { float x, y; };
typedef struct ztf_Float2 ztf_Float2;
struct ztf_Float3 { float x, y, z; };
typedef struct ztf_Float3 ztf_Float3;
struct ztf_Float4 { float x, y, z, w; };
typedef struct ztf_Float4 ztf_Float4;

typedef ztf_Float2 ztf_Vector2;

ZTF_VECTORMATH_ALIGNED_TYPE_PRE struct ztf_Vector3 { alignas(16) ztf_vec_f128 mVec128; } ZTF_VECTORMATH_ALIGNED_TYPE_POST;
typedef struct ztf_Vector3 ztf_Vector3;
ZTF_VECTORMATH_ALIGNED_TYPE_PRE struct ztf_Vector4 { alignas(16) ztf_vec_f128 mVec128; } ZTF_VECTORMATH_ALIGNED_TYPE_POST;
typedef struct ztf_Vector4 ztf_Vector4;

ZTF_VECTORMATH_ALIGNED_TYPE_PRE struct ztf_Vector3d { alignas(16) ztf_vec_d128 mVec128; } ZTF_VECTORMATH_ALIGNED_TYPE_POST;
typedef struct ztf_Vector3d ztf_Vector3d;
ZTF_VECTORMATH_ALIGNED_TYPE_PRE struct ztf_Vector4d { alignas(16) ztf_vec_d128 mVec128; } ZTF_VECTORMATH_ALIGNED_TYPE_POST;
typedef struct ztf_Vector4d ztf_Vector4d;

typedef struct ztf_IVector2{ int x, y; } ztf_IVector2;
ZTF_VECTORMATH_ALIGNED_TYPE_PRE struct ztf_IVector3 { alignas(16) ztf_vec_i128 mVec128; } ZTF_VECTORMATH_ALIGNED_TYPE_POST;
typedef struct ztf_IVector3 ztf_IVector3;
ZTF_VECTORMATH_ALIGNED_TYPE_PRE struct ztf_IVector4 { alignas(16) ztf_vec_i128 mVec128; } ZTF_VECTORMATH_ALIGNED_TYPE_POST;
typedef struct ztf_IVector4 ztf_IVector4;

typedef struct ztf_UVector2{ unsigned int x, y; } ztf_UVector2;
ZTF_VECTORMATH_ALIGNED_TYPE_PRE struct ztf_UVector3 { alignas(16) ztf_vec_f128 mVec128; } ZTF_VECTORMATH_ALIGNED_TYPE_POST;
typedef struct ztf_UVector3 ztf_UVector3;
ZTF_VECTORMATH_ALIGNED_TYPE_PRE struct ztf_UVector4 { alignas(16) ztf_vec_f128 mVec128; } ZTF_VECTORMATH_ALIGNED_TYPE_POST;
typedef struct ztf_UVector4 ztf_UVector4;

typedef ztf_IVector2 ztf_Int2;

ZTF_VECTORMATH_ALIGNED_TYPE_PRE struct ztf_Matrix3 {
	ztf_Vector3 mCol0;
    ztf_Vector3 mCol1;
    ztf_Vector3 mCol2;
} ZTF_VECTORMATH_ALIGNED_TYPE_POST;
typedef struct ztf_Matrix3 ztf_Matrix3;

ZTF_VECTORMATH_ALIGNED_TYPE_PRE struct ztf_Matrix4 {
	ztf_Vector4 mCol0;
    ztf_Vector4 mCol1;
    ztf_Vector4 mCol2;
    ztf_Vector4 mCol3;
} ZTF_VECTORMATH_ALIGNED_TYPE_POST;
typedef struct ztf_Matrix4 ztf_Matrix4;

ZTF_VECTORMATH_ALIGNED_TYPE_PRE struct ztf_Matrix3d {
	ztf_Vector3d mCol0;
    ztf_Vector3d mCol1;
    ztf_Vector3d mCol2;
} ZTF_VECTORMATH_ALIGNED_TYPE_POST;
typedef struct ztf_Matrix3d ztf_Matrix3d;

ZTF_VECTORMATH_ALIGNED_TYPE_PRE struct ztf_Matrix4d {
	ztf_Vector4d mCol0;
    ztf_Vector4d mCol1;
    ztf_Vector4d mCol2;
    ztf_Vector4d mCol3;
} ZTF_VECTORMATH_ALIGNED_TYPE_POST;
typedef struct ztf_Matrix4d ztf_Matrix4d;

ztf_Vector3 make_vec3(float x, float y, float z);
ztf_Vector4 make_vec4(float x, float y, float z, float w);
ztf_Vector3d make_vec3d(double x, double y, double z);
ztf_Vector4d make_vec4d(double x, double y, double z, double w);
ztf_IVector3 make_ivec3(int32_t x, int32_t y, int32_t z);
ztf_IVector4 make_ivec4(int32_t x, int32_t y, int32_t z, int32_t w);
ztf_UVector3 make_uvec3(uint32_t x, uint32_t y, uint32_t z);
ztf_UVector4 make_uvec4(uint32_t x, uint32_t y, uint32_t z, uint32_t w);

ztf_Matrix3 mat3_identity();
ztf_Matrix4 mat4_identity();
ztf_Matrix3d mat3d_identity();
ztf_Matrix4d mat4d_identity();

void mat4_set_translation(ztf_Matrix4* mat, const ztf_Vector3* translation);
ztf_Vector3 mat4_get_translation(const ztf_Matrix4* mat);

#ifdef __cplusplus
}
#endif