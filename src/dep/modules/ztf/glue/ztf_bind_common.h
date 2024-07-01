#pragma once

#define ZTF_C_API
#define ZTF_C_RENDERER_API

#define ZTF_BITFIELD_DOT_ACCESS(TARGET) .##TARGET

#define ZTF_BITFIELD_SETGET_DECLARE(ClassName, FlagName, UnderlyingType)\
UnderlyingType ztf_get##ClassName##_##FlagName(const ztf_##ClassName * pStruct);\
void ztf_set##ClassName##_##FlagName(ztf_##ClassName * pStruct, UnderlyingType pValue);

#define ZTF_BITFIELD_SETGET_DEFINE(ClassName, BitfieldName, FlagName, UnderlyingType, Offset, Width)\
\
	const UnderlyingType ztf_##ClassName##_##FlagName##_Mask = ((((UnderlyingType)1 << (UnderlyingType)Width)-(UnderlyingType)1) << (UnderlyingType)Offset);\
	UnderlyingType ztf_get##ClassName##_##FlagName(const ztf_##ClassName * pStruct)\
	{\
		return (pStruct->BitfieldName & ztf_##ClassName##_##FlagName##_Mask) >> Offset;\
	}\
\
	void ztf_set##ClassName##_##FlagName(ztf_##ClassName * pStruct, UnderlyingType pValue)\
	{\
		const UnderlyingType cleared = pStruct->BitfieldName & (~ ztf_##ClassName##_##FlagName##_Mask);\
		pStruct->BitfieldName = (cleared | (pValue << Offset));\
	}

#define ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(ClassName, BitfieldName, BitfieldAccessPrefix, FlagName, UnderlyingType, Offset, Width)\
\
	const UnderlyingType ztf_##ClassName##_##FlagName##_Mask = ((((UnderlyingType)1 << (UnderlyingType)Width)-(UnderlyingType)1) << (UnderlyingType)Offset);\
	UnderlyingType ztf_get##ClassName##_##FlagName(const ztf_##ClassName * pStruct)\
	{\
		return pStruct->BitfieldAccessPrefix.BitfieldName & ztf_##ClassName##_##FlagName##_Mask;\
	}\
\
	void ztf_set##ClassName##_##FlagName(ztf_##ClassName * pStruct, UnderlyingType pValue)\
	{\
		const UnderlyingType cleared = pStruct->BitfieldAccessPrefix.BitfieldName & (~ ztf_##ClassName##_##FlagName##_Mask);\
		pStruct->BitfieldAccessPrefix.BitfieldName = (cleared | (pValue << Offset));\
	}