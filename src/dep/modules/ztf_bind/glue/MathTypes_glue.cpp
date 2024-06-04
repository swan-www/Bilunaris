#include <new>

#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/Utilities/Math/MathTypes.h"
#include "MathTypes_glue.h"

extern "C"
{

ztf_Int2* ztf_int2_new(int const* in_int_array)
{
	if(!in_int_array)
	{
		return nullptr;
	}
	return (ztf_Int2*)new int2(in_int_array[0], in_int_array[1]);
}
void ztf_int2_delete(ztf_Int2* in_int2) { if(in_int2){ delete static_cast<int2*>(in_int2); } }

ztf_Float2* ztf_float2_new(float const* in_float_array)
{
	if(!in_float_array)
	{
		return nullptr;
	}
	return new ztf_Float2{in_float_array[0], in_float_array[1]};
}

void ztf_float2_delete(ztf_Float2* in_float2) { if(in_float2){ delete static_cast<ztf_Float2*>(in_float2); } }

ztf_Vector2* ztf_vec2_new(float const * in_float_array)
{
	if(!in_float_array)
	{
		return nullptr;
	}
	return new Vector2(in_float_array[0], in_float_array[1]);
}

void 		ztf_vec2_delete(ztf_Vector2* in_vec2) { if(in_vec2){ delete static_cast<Vector2*>(in_vec2); } }
ztf_Vector3* 	ztf_vec3_new(float const * in_float_array)
{
	if(!in_float_array)
	{
		return nullptr;
	}
	return new Vector3(in_float_array[0], in_float_array[1], in_float_array[2]);
}
void 		ztf_vec3_delete(ztf_Vector3* in_vec3) { if(in_vec3){ delete static_cast<Vector3*>(in_vec3); } }
ztf_Vector4* 	ztf_vec4_new(float const * in_float_array)
{
	if(!in_float_array)
	{
		return nullptr;
	}
	return new Vector4(in_float_array[0], in_float_array[1], in_float_array[2], in_float_array[3]);
}
void 		ztf_vec4_delete(ztf_Vector4* in_vec4) { if(in_vec4){ delete static_cast<Vector4*>(in_vec4); } }

ztf_IVector2* 	ztf_ivec2_new(int32_t const* in_int_array)
{
	if(!in_int_array)
	{
		return nullptr;
	}
	return new IVector2(in_int_array[0], in_int_array[1]);
}
void 		ztf_ivec2_delete(ztf_IVector2* in_ivec2) { if(in_ivec2){ delete static_cast<IVector2*>(in_ivec2); } }
ztf_IVector3* 	ztf_ivec3_new(int32_t const* in_int_array)
{
	if(!in_int_array)
	{
		return nullptr;
	}
	return new IVector3(in_int_array[0], in_int_array[1], in_int_array[2]);
}
void 		ztf_ivec3_delete(ztf_IVector3* in_ivec3) { if(in_ivec3){ delete static_cast<IVector3*>(in_ivec3); } }
ztf_IVector4* 	ztf_ivec4_new(int32_t const* in_int_array)
{
	if(!in_int_array)
	{
		return nullptr;
	}
	return new IVector4(in_int_array[0], in_int_array[1], in_int_array[2], in_int_array[3]);
}
void 		ztf_ivec4_delete(ztf_IVector4* in_ivec4) { if(in_ivec4){ delete static_cast<IVector4*>(in_ivec4); } }

ztf_UVector2* 	ztf_uvec2_new(uint32_t const* in_uint_array)
{
	if(!in_uint_array)
	{
		return nullptr;
	}
	return new UVector2(in_uint_array[0], in_uint_array[1]);
}
void 		ztf_uvec2_delete(ztf_UVector2* in_uvec2) { if(in_uvec2){ delete static_cast<UVector2*>(in_uvec2); } }
ztf_UVector3* 	ztf_uvec3_new(uint32_t const* in_uint_array)
{
	if(!in_uint_array)
	{
		return nullptr;
	}
	return new UVector3(in_uint_array[0], in_uint_array[1], in_uint_array[2]);
}
void 		ztf_uvec3_delete(ztf_UVector3* in_uvec3) { if(in_uvec3){ delete static_cast<UVector3*>(in_uvec3); } }
ztf_UVector4* 	ztf_uvec4_new(uint32_t const* in_uint_array)
{
	if(!in_uint_array)
	{
		return nullptr;
	}
	return new UVector4(in_uint_array[0], in_uint_array[1], in_uint_array[2], in_uint_array[3]);
}
void 		ztf_uvec4_delete(ztf_UVector4* in_uvec4) { if(in_uvec4){ delete static_cast<UVector4*>(in_uvec4); } }

ztf_Matrix2* 	ztf_mat2_new(float const* in_float_array)
{
	if(!in_float_array)
	{
		return nullptr;
	}
	return new Matrix2
	(
		Vector2(in_float_array[0], in_float_array[1]),
		Vector2(in_float_array[2], in_float_array[3])
	);
}
void 		ztf_mat2_delete(ztf_Matrix2* in_mat2) { if(in_mat2){ delete static_cast<Matrix2*>(in_mat2); } }
ztf_Matrix3* 	ztf_mat3_new(float const* in_float_array)
{
	if(!in_float_array)
	{
		return nullptr;
	}
	return new Matrix3
	(
		Vector3(in_float_array[0], in_float_array[1], in_float_array[2]),
		Vector3(in_float_array[3], in_float_array[4], in_float_array[5]),
		Vector3(in_float_array[6], in_float_array[7], in_float_array[8])
	);
}
void 		ztf_mat3_delete(ztf_Matrix3* in_mat3) { if(in_mat3){ delete static_cast<Matrix3*>(in_mat3); } }
ztf_Matrix4* 	ztf_mat4_new(float const* in_float_array)
{
	if(!in_float_array)
	{
		return nullptr;
	}
	return new Matrix4
	(
		Vector4(in_float_array[0],	in_float_array[1],	in_float_array[2],	in_float_array[3]),
		Vector4(in_float_array[4],	in_float_array[5],	in_float_array[6],	in_float_array[7]),
		Vector4(in_float_array[8],	in_float_array[9],	in_float_array[10], in_float_array[11]),
		Vector4(in_float_array[12], in_float_array[13], in_float_array[14], in_float_array[15])
	);
}
void 		ztf_mat4_delete(ztf_Matrix4* in_mat4) { if(in_mat4){ delete static_cast<Matrix4*>(in_mat4); } }

}//extern "C"

/*
void store_vec2_glue(vec2_glue in_glue, const vec2& in_vec)
{
	in_glue[0] = in_vec.getX();
	in_glue[1] = in_vec.getY();
}

void store_vec3_glue(vec3_glue in_glue, const vec3& in_vec)
{
	store3PtrU(in_vec, in_glue);
}

void store_vec4_glue(vec4_glue in_glue, const vec4& in_vec)
{
	storePtrU(in_vec, in_glue);
}

void store_ivec2_glue(ivec2_glue in_glue, const ivec2& in_vec)
{
	Store2PtrU(in_vec, in_glue);
}

void store_ivec3_glue(ivec3_glue in_glue, const ivec3& in_vec)
{
	Store3PtrU(in_vec, in_glue);
}

void store_ivec4_glue(ivec4_glue in_glue, const ivec4& in_vec)
{
	StorePtrU(in_vec, in_glue);
}

void store_uvec2_glue(uvec2_glue in_glue, const uvec2& in_vec)
{
	in_glue[0] = in_vec.getX();
	in_glue[1] = in_vec.getY();
}

void store_uvec3_glue(uvec3_glue in_glue, const uvec3& in_vec)
{
	in_glue[0] = in_vec.getX();
	in_glue[1] = in_vec.getY();
	in_glue[2] = in_vec.getZ();
}

void store_uvec4_glue(uvec4_glue in_glue, const uvec4& in_vec)
{
	in_glue[0] = in_vec.getX();
	in_glue[1] = in_vec.getY();
	in_glue[2] = in_vec.getZ();
	in_glue[3] = in_vec.getW();
}

void store_mat2_glue(mat2_glue in_glue, const mat2& in_mat)
{
	{
		in_glue.row0[0] = in_mat.getCol(0).getX();
		in_glue.row0[1] = in_mat.getCol(1).getX();
	}

	{
		in_glue.row1[0] = in_mat.getCol(0).getY();
		in_glue.row1[1] = in_mat.getCol(1).getY();
	}
}

void store_mat3_glue(mat3_glue in_glue, const mat3& in_mat)
{
	{
		in_glue.row0[0] = in_mat.getCol(0).getX();
		in_glue.row0[1] = in_mat.getCol(1).getX();
		in_glue.row0[2] = in_mat.getCol(2).getX();
	}

	{
		in_glue.row1[0] = in_mat.getCol(0).getY();
		in_glue.row1[1] = in_mat.getCol(1).getY();
		in_glue.row1[2] = in_mat.getCol(2).getY();
	}

	{
		in_glue.row2[0] = in_mat.getCol(0).getZ();
		in_glue.row2[1] = in_mat.getCol(1).getZ();
		in_glue.row2[2] = in_mat.getCol(2).getZ();
	}
}

void store_mat4_glue(mat4_glue in_glue, const mat4& in_mat)
{
	{
		in_glue.row0[0] = in_mat.getCol(0).getX();
		in_glue.row0[1] = in_mat.getCol(1).getX();
		in_glue.row0[2] = in_mat.getCol(2).getX();
		in_glue.row0[3] = in_mat.getCol(3).getX();
	}

	{
		in_glue.row1[0] = in_mat.getCol(0).getY();
		in_glue.row1[1] = in_mat.getCol(1).getY();
		in_glue.row1[2] = in_mat.getCol(2).getY();
		in_glue.row0[3] = in_mat.getCol(3).getY();
	}

	{
		in_glue.row2[0] = in_mat.getCol(0).getZ();
		in_glue.row2[1] = in_mat.getCol(1).getZ();
		in_glue.row2[2] = in_mat.getCol(2).getZ();
		in_glue.row2[3] = in_mat.getCol(3).getZ();
	}

	{
		in_glue.row3[0] = in_mat.getCol(0).getW();
		in_glue.row3[1] = in_mat.getCol(1).getW();
		in_glue.row3[2] = in_mat.getCol(2).getW();
		in_glue.row3[3] = in_mat.getCol(3).getW();
	}
}


void load_vec2_glue(const vec2_glue in_glue, vec2& in_vec)
{
	in_vec = vec2(in_glue[0], in_glue[1]);
}

void load_vec3_glue(const vec3_glue in_glue, vec3& in_vec)
{
	in_vec = vec3(in_glue[0], in_glue[1], in_glue[2]);
}

void load_vec4_glue(const vec4_glue in_glue, vec4& in_vec)
{
	in_vec = vec4(in_glue[0], in_glue[1], in_glue[2], in_glue[3]);
}

void load_ivec2_glue(const ivec2_glue in_glue, ivec2& in_vec)
{
	in_vec = ivec2(in_glue[0], in_glue[1]);
}

void load_ivec3_glue(const ivec3_glue in_glue, ivec3& in_vec)
{
	in_vec = ivec3(in_glue[0], in_glue[1], in_glue[2]);
}

void load_ivec4_glue(const ivec4_glue in_glue, ivec4& in_vec)
{
	in_vec = ivec4(in_glue[0], in_glue[1], in_glue[2], in_glue[3]);
}

void load_uvec2_glue(const uvec2_glue in_glue, uvec2& in_vec)
{
	in_vec = uvec2(in_glue[0], in_glue[1]);
}

void load_uvec3_glue(const uvec3_glue in_glue, uvec3& in_vec)
{
	in_vec = uvec3(in_glue[0], in_glue[1], in_glue[2]);
}

void load_uvec4_glue(const uvec4_glue in_glue, uvec4& in_vec)
{
	in_vec = uvec4(in_glue[0], in_glue[1], in_glue[2], in_glue[3]);
}

void load_mat2_glue(const mat2_glue in_glue, mat2& in_mat)
{
	in_mat = mat2(	in_glue.row0[0], in_glue.row0[1]
					, in_glue.row1[0], in_glue.row1[1]
	);
}

void load_mat3_glue(const mat3_glue in_glue, mat3& in_mat)
{
	in_mat.setCol0(vec3(in_glue.row0[0], in_glue.row1[0], in_glue.row2[0]));
	in_mat.setCol1(vec3(in_glue.row0[1], in_glue.row1[1], in_glue.row2[1]));
	in_mat.setCol2(vec3(in_glue.row0[2], in_glue.row1[2], in_glue.row2[2]));
}

void load_mat4_glue(const mat4_glue in_glue, mat4& in_mat)
{
	in_mat.setCol0(vec4(in_glue.row0[0], in_glue.row1[0], in_glue.row2[0], in_glue.row3[0]));
	in_mat.setCol1(vec4(in_glue.row0[1], in_glue.row1[1], in_glue.row2[1], in_glue.row3[1]));
	in_mat.setCol2(vec4(in_glue.row0[2], in_glue.row1[2], in_glue.row2[2], in_glue.row3[2]));
	in_mat.setCol3(vec4(in_glue.row0[3], in_glue.row1[3], in_glue.row2[3], in_glue.row3[3]));
}
*/