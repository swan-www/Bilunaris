//Has to go first so it can override some windows defines
#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/Application/Config.h"

#include "IFont_c.h"

#include <assert.h>

#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/Application/Interfaces/IFont.h"
#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/Utilities/Math/MathTypes.h"

#ifdef __cplusplus
extern "C"
{
#endif

ZTF_C_API bool ztf_initFontSystem(ztf_FontSystemDesc* pDesc)
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

ZTF_C_API void ztf_cmdDrawTextWithFont(Cmd* pCmd, ztf_Float2* screenCoordsInPx, const ztf_FontDrawDesc* pDrawDesc)
{
	cmdDrawTextWithFont(pCmd, *static_cast<float2*>(screenCoordsInPx), (const FontDrawDesc*)(pDrawDesc));
}

ZTF_C_API void ztf_cmdDrawWorldSpaceTextWithFont(Cmd* pCmd, const ztf_Matrix4* pMatWorld, const CameraMatrix* pMatProjView, const ztf_FontDrawDesc* pDrawDesc)
{
	cmdDrawWorldSpaceTextWithFont(pCmd, static_cast<const Matrix4*>(pMatWorld), pMatProjView, (const FontDrawDesc*)(pDrawDesc));
}
ZTF_C_API void ztf_cmdDrawDebugFontAtlas(Cmd* pCmd, ztf_Float2* screenCoordsInPx)
{
	cmdDrawDebugFontAtlas(pCmd, *static_cast<const float2*>(screenCoordsInPx));
}

ZTF_C_API void ztf_fntDefineFonts(const ztf_FontDesc* pDescs, uint32_t count, uint32_t* pOutIDs)
{
	fntDefineFonts((const FontDesc*)pDescs, count, pOutIDs);
}

ZTF_C_API ztf_Int2* ztf_fntGetFontAtlasSize()
{
	int2 atlasSize = fntGetFontAtlasSize();
	return new int2(atlasSize);
}

ZTF_C_API void ztf_fntResetFontAtlas(ztf_Int2 const* newAtlasSize)
{
	fntResetFontAtlas(*static_cast<int2 const*>(newAtlasSize));
}

ZTF_C_API void ztf_fntExpandAtlas(ztf_Int2 const* additionalSize)
{
	fntExpandAtlas(*static_cast<int2 const*>(additionalSize));
}

ZTF_C_API ztf_Float2* ztf_fntMeasureFontText(const char* pText, const ztf_FontDrawDesc* pDrawDesc)
{
	return new float2(fntMeasureFontText(pText, (const FontDrawDesc*)(pDrawDesc)));
}

#ifdef __cplusplus
}
#endif