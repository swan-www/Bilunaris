//Has to go first so it can override some windows defines
#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/Application/Config.h"

#define ZTF_BLOCK_CONFIG_INCLUDE
#include "IFont_c.h"
#undef ZTF_BLOCK_CONFIG_INCLUDE

#include <assert.h>

#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/Application/Interfaces/IFont.h"
#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/Utilities/Math/MathTypes.h"

#ifdef __cplusplus
extern "C"
{
#endif

ZTF_C_API ztf_FontSystemDesc ztf_getDefaultFontSystemDesc()
{
	ztf_FontSystemDesc default_desc{};
	default_desc.mFontstashRingSizeBytes = 1024 * 1024;
	return default_desc;
}

ZTF_C_API ztf_FontDesc ztf_getDefaultFontDesc()
{
	ztf_FontDesc default_font_desc{};
	default_font_desc.pFontName = "default";
	return default_font_desc;
}

ZTF_C_API ztf_FontDrawDesc ztf_getDefaultFontDrawDesc()
{
	ztf_FontDrawDesc default_font_draw_desc{};
	default_font_draw_desc.mFontColor = 0xffffffff;
	default_font_draw_desc.mFontSize = 16.0f;
	return default_font_draw_desc;
}

ZTF_C_API bool ztf_initFontSystem(ztf_FontSystemDesc *pDesc)
{
	return initFontSystem((FontSystemDesc*)(pDesc));
}

ZTF_C_API void ztf_exitFontSystem()
{
	exitFontSystem();
}

ZTF_C_API void ztf_loadFontSystem(const ztf_FontSystemLoadDesc* pDesc)
{
	loadFontSystem((const FontSystemLoadDesc*)(pDesc));
}

ZTF_C_API void ztf_unloadFontSystem(ztf_ReloadType unloadType)
{
	ReloadType mappedType = ReloadType::RELOAD_TYPE_ALL;
	assert(false); //TODO
	unloadFontSystem(mappedType);
}

ZTF_C_API void ztf_cmdDrawTextWithFont(Cmd* pCmd, ztf_Float2 screenCoordsInPx, const ztf_FontDrawDesc* pDrawDesc)
{
	cmdDrawTextWithFont(pCmd, float2{screenCoordsInPx.x, screenCoordsInPx.y}, (const FontDrawDesc*)(pDrawDesc));
}

ZTF_C_API void ztf_cmdDrawWorldSpaceTextWithFont(Cmd* pCmd, const ztf_Matrix4* pMatWorld, const ZTF_CameraMatrix* pMatProjView, const ztf_FontDrawDesc* pDrawDesc)
{
	cmdDrawWorldSpaceTextWithFont(pCmd, (const Matrix4*)(pMatWorld), (const CameraMatrix*)pMatProjView, (const FontDrawDesc*)(pDrawDesc));
}
ZTF_C_API void ztf_cmdDrawDebugFontAtlas(Cmd* pCmd, ztf_Float2 screenCoordsInPx)
{
	cmdDrawDebugFontAtlas(pCmd, float2{screenCoordsInPx.x, screenCoordsInPx.y});
}

ZTF_C_API void ztf_fntDefineFonts(const ztf_FontDesc* pDescs, uint32_t count, uint32_t* pOutIDs)
{
	fntDefineFonts((const FontDesc*)pDescs, count, pOutIDs);
}

ZTF_C_API ztf_Int2 ztf_fntGetFontAtlasSize()
{
	ztf_Int2 dst{};
	int2 src = fntGetFontAtlasSize();
	static_assert(sizeof(dst) == sizeof(src));
	memcpy(&dst, &src, sizeof(dst));
	return dst;
}

ZTF_C_API void ztf_fntResetFontAtlas(ztf_Int2 const* newAtlasSize)
{
	fntResetFontAtlas(*(int2 const*)(newAtlasSize));
}

ZTF_C_API void ztf_fntExpandAtlas(ztf_Int2 const* additionalSize)
{
	fntExpandAtlas(*(int2 const*)(additionalSize));
}

ZTF_C_API ztf_Float2 ztf_fntMeasureFontText(const char* pText, const ztf_FontDrawDesc* pDrawDesc)
{
	float2 val = fntMeasureFontText(pText, (const FontDrawDesc*)(pDrawDesc));
	return ztf_Float2{val.x, val.y};
}

#ifdef __cplusplus
}
#endif