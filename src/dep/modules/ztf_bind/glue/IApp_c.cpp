#include "IApp_c.h"

#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/OS/Interfaces/IOperatingSystem.h"
#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/Application/Interfaces/IApp.h"

#ifdef __cplusplus
extern "C"
{
#endif

ZTF_C_API void ztf_defaultInitAppSettings(ztf_AppSettings* pAppSettings)
{
    memset(pAppSettings, 0, sizeof(ztf_AppSettings));
    /// Window width
    pAppSettings->mWidth = -1;
    /// Window height
    pAppSettings->mHeight = -1;
    /// monitor index
    pAppSettings->mMonitorIndex = -1;
    /// x position for window
    pAppSettings->mWindowX = 0;
    /// y position for window
    pAppSettings->mWindowY = 0;
    /// Set to true if fullscreen mode has been requested
    pAppSettings->mFullScreen = false;
    /// Set to true if app wants to use an external window
    pAppSettings->mExternalWindow = false;
    /// Drag to resize enabled
    pAppSettings->mDragToResize = true;
    /// Border less window
    pAppSettings->mBorderlessWindow = false;
    /// Set to true if oversize windows requested
    pAppSettings->mAllowedOverSizeWindows = false;
    /// if settings is already initiazlied we don't fill when opening window
    pAppSettings->mInitialized = false;
    /// if requested to quit the application
    pAppSettings->mQuit = false;
    /// if benchmarking mode is enabled
    pAppSettings->mBenchmarking = false;
    /// if the window is positioned in the center of the screen
    pAppSettings->mCentered = true;
    /// if the window is focused or in foreground
    pAppSettings->mFocused = true;
    /// Force lowDPI settings for this window
    pAppSettings->mForceLowDPI = false;
    /// if the platform user interface is visible
    pAppSettings->mShowPlatformUI = true;

#ifdef __ANDROID__
    pAppSettings->mVSyncEnabled = true;
#else
    pAppSettings->mVSyncEnabled = false;
#endif

#if defined(TARGET_IOS)
    pAppSettings->mShowStatusBar = false;
    pAppSettings->mContentScaleFactor = 0.f;
    // Use to set iPhone's/Ipad target display refresh rate.
    pAppSettings->mMaxDisplayRefreshRate = -1;
#endif
}

//IApp access
ZTF_C_API ztf_AppSettings* ztf_getAppSettings(ztf_App* pApp)
{
	return (ztf_AppSettings*)&pApp->mSettings;
}
ZTF_C_API ztf_WindowDesc* ztf_getWindowDesc(ztf_App* pApp)
{
	return (ztf_WindowDesc*)pApp->pWindow;
}
ZTF_C_API const char* ztf_getCommandLine(ztf_App* pApp)
{
	return pApp->pCommandLine;
}
ZTF_C_API int ztf_getArgC(ztf_App* pApp)
{
	return pApp->argc;
}
ZTF_C_API const char** ztf_getArgV(ztf_App* pApp)
{
	return pApp->argv;
}

#ifdef __cplusplus
}
#endif