#pragma once

#include <stdint.h>
#include <stdbool.h> 

#include "ztf_bind_common.h"
#include "ICameraController_c.h"
#include "IOperatingSystem_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct Renderer Renderer;
typedef struct Cmd Cmd;
typedef struct RenderTarget RenderTarget;
typedef struct PipelineCache PipelineCache;

/****************************************************************************/
// MARK: - Public Font System Structs
/****************************************************************************/

/// Creation information for initializing Forge Rendering for fonts and text
typedef struct ztf_FontSystemDesc
{

	Renderer*	pRenderer /*= NULL*/;
	uint32_t    mFontstashRingSizeBytes /*= 1024 * 1024*/;
} ztf_FontSystemDesc;

ZTF_C_API ztf_FontSystemDesc ztf_getDefaultFontSystemDesc();

typedef struct ztf_FontSystemLoadDesc
{
	PipelineCache*	pCache;
	ztf_ReloadType	mLoadType;
	uint32_t        mColorFormat;  // enum TinyImageFormat
	uint32_t        mDepthFormat;  // enum TinyImageFormat
	uint32_t        mWidth;
	uint32_t        mHeight;
	uint32_t		mCullMode; // enum CullMode
	uint32_t		mDepthCompareMode; // enum CompareMode
} ztf_FontSystemLoadDesc;

/// Creation information for loading a font from a file using The Forge
typedef struct ztf_FontDesc
{

	const char* pFontName /*= "default"*/;
	const char* pFontPath /*= NULL*/;
	const char* pFontPassword /*= NULL*/;

} ztf_FontDesc;

ZTF_C_API ztf_FontDesc ztf_getDefaultFontDesc();

/// Aggregation of information necessary for drawing text with The Forge
typedef struct ztf_FontDrawDesc
{

	const char* pText /*= NULL*/;

	uint32_t      mFontID /*= 0*/;
	// Provided color should be A8B8G8R8_SRGB
	uint32_t      mFontColor /*= 0xffffffff*/;
	float         mFontSize /*= 16.0f*/;
	float         mFontSpacing /*= 0.0f*/;
	float         mFontBlur /*= 0.0f*/;

} ztf_FontDrawDesc;

ZTF_C_API ztf_FontDrawDesc ztf_getDefaultFontDrawDesc();

/****************************************************************************/
// MARK: - Application Life Cycle 
/****************************************************************************/

/// Initializes Forge Rendering objects associated with Font Rendering
/// To be called at application initialization time by the App Layer
ZTF_C_API bool ztf_initFontSystem(ztf_FontSystemDesc* pDesc);

/// Frees Forge Rendering objects and memory associated with Font Rendering
/// To be called at application shutdown time by the App Layer
ZTF_C_API void ztf_exitFontSystem();

/// Loads Font Rendering resources depending on FontSystemLoadDesc::mLoadType
/// To be called at application load time by the App Layer
ZTF_C_API void ztf_loadFontSystem(const ztf_FontSystemLoadDesc* pDesc);

/// Unloads Font Rendering resources depending on FontSystemLoadDesc::mLoadType
/// To be called at application unload time by the App Layer
ZTF_C_API void ztf_unloadFontSystem(ztf_ReloadType unloadType);

/// Renders UI-style text to the screen using a loaded font w/ The Forge
/// This function will assert if Font Rendering has not been initialized
ZTF_C_API void ztf_cmdDrawTextWithFont(Cmd* pCmd, ztf_Float2 screenCoordsInPx, const ztf_FontDrawDesc* pDrawDesc);

/// Renders text as an object in the world using a loaded font w/ The Forge
/// This function will assert if Font Rendering has not been initialized
ZTF_C_API void ztf_cmdDrawWorldSpaceTextWithFont(Cmd* pCmd, const ztf_Matrix4* pMatWorld, const ZTF_CameraMatrix* pMatProjView, const ztf_FontDrawDesc* pDrawDesc);

/// Debugging feature - draws the contents of the internal font atlas
ZTF_C_API void ztf_cmdDrawDebugFontAtlas(Cmd* pCmd, ztf_Float2 screenCoordsInPx);

/****************************************************************************/
// MARK: - Other Font System Functionality
/****************************************************************************/

/// Loads an array of fonts from files and returns an array of their ID handles
ZTF_C_API void ztf_fntDefineFonts(const ztf_FontDesc* pDescs, uint32_t count, uint32_t* pOutIDs);

/// Get current font atlas size
ZTF_C_API ztf_Int2 ztf_fntGetFontAtlasSize();

/// Clear all data from the font atlas and resize it to provide size. Pass zero to keep the current size.
ZTF_C_API void ztf_fntResetFontAtlas(ztf_Int2 const* newAtlasSize);

/// Expands the font atlas size by given size without clearing the contents
ZTF_C_API void ztf_fntExpandAtlas(ztf_Int2 const* additionalSize);

/// Returns the bounds of text that would be drawn to supplied specification
ZTF_C_API ztf_Float2 ztf_fntMeasureFontText(const char* pText, const ztf_FontDrawDesc* pDrawDesc);

#ifdef __cplusplus
}
#endif