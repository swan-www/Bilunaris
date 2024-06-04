#pragma once
#include <stdbool.h> 
#include <stdint.h>

#ifdef __cplusplus
#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/Application/Interfaces/IApp.h"
#endif

#include "ztf_bind_common.h"
#include "IOperatingSystem_c.h"

#ifdef __cplusplus
class ztf_App;

extern "C"
{
#else
typedef struct ztf_App ztf_App;
#endif

typedef struct ztf_AppSettings
{
    /// Window width
    int32_t mWidth = -1;
    /// Window height
    int32_t mHeight = -1;
    /// monitor index
    int32_t mMonitorIndex = -1;
    /// x position for window
    int32_t mWindowX = 0;
    /// y position for window
    int32_t mWindowY = 0;
    /// Set to true if fullscreen mode has been requested
    bool    mFullScreen = false;
    /// Set to true if app wants to use an external window
    bool    mExternalWindow = false;
    /// Drag to resize enabled
    bool    mDragToResize = true;
    /// Border less window
    bool    mBorderlessWindow = false;
    /// Set to true if oversize windows requested
    bool    mAllowedOverSizeWindows = false;
    /// if settings is already initiazlied we don't fill when opening window
    bool    mInitialized = false;
    /// if requested to quit the application
    bool    mQuit = false;
    /// if benchmarking mode is enabled
    bool    mBenchmarking = false;
    /// if the window is positioned in the center of the screen
    bool    mCentered = true;
    /// if the window is focused or in foreground
    bool    mFocused = true;
    /// Force lowDPI settings for this window
    bool    mForceLowDPI = false;
    /// if the platform user interface is visible
    bool    mShowPlatformUI = true;

#ifdef __ANDROID__
    bool mVSyncEnabled = true;
#else
    bool mVSyncEnabled = false;
#endif

#if defined(TARGET_IOS)
    bool    mShowStatusBar = false;
    float   mContentScaleFactor = 0.f;
    // Use to set iPhone's/Ipad target display refresh rate.
    int32_t mMaxDisplayRefreshRate = -1;
#endif
} ztf_AppSettings;

//IApp functions
ZTF_C_API extern bool ztf_appInit(ztf_App* pApp);
ZTF_C_API extern void ztf_appExit(ztf_App* pApp);
ZTF_C_API extern bool ztf_appLoad(ztf_App* pApp, ztf_ReloadDesc* pReloadDesc);
ZTF_C_API extern void ztf_appUnload(ztf_App* pApp, ztf_ReloadDesc* pReloadDesc);
ZTF_C_API extern void ztf_appUpdate(ztf_App* pApp, float deltaTime);
ZTF_C_API extern void ztf_appDraw(ztf_App* pApp);
ZTF_C_API extern const char* ztf_appGetName(ztf_App* pApp);

//IApp access
ZTF_C_API ztf_AppSettings* ztf_getAppSettings(ztf_App* pApp);
ZTF_C_API ztf_WindowDesc* ztf_getWindowDesc(ztf_App* pApp);
ZTF_C_API const char* ztf_getCommandLine(ztf_App* pApp);
ZTF_C_API int ztf_getArgC(ztf_App* pApp);
ZTF_C_API const char** ztf_getArgV(ztf_App* pApp);

#ifdef __cplusplus
class ztf_App : public IApp
{
    virtual bool Init() override
    {
        return ztf_appInit(this);
    }
    virtual void Exit() override
    {
        return ztf_appExit(this);
    }

    virtual bool Load(ReloadDesc* pReloadDesc) override
    {
        return ztf_appLoad(this, (ztf_ReloadDesc*)pReloadDesc);
    }
    virtual void Unload(ReloadDesc* pReloadDesc) override
    {
        ztf_appUnload(this, (ztf_ReloadDesc*)pReloadDesc);
    }

    virtual void Update(float deltaTime) override
    {
        ztf_appUpdate(this, deltaTime);
    }
    virtual void Draw() override
    {
        ztf_appDraw(this);
    }

    virtual const char* GetName() override
    {
        return ztf_appGetName(this);
    }
};

}
#endif