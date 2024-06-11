#pragma once

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>

// For time related functions such as getting localtime
#include <float.h>
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <time.h>

#if defined(_WINDOWS) || defined(XBOX)
#include <stdlib.h>
#include <sys/stat.h>
#include <windows.h>
#endif

#if defined(FORGE_DEBUG) && (defined(_WINDOWS) || (defined(__linux__) && !defined(__ANDROID__)) || defined(__APPLE__))
#define WINDOW_DETAILS 1
#include "../../Utilities/ThirdParty/OpenSource/bstrlib/bstrlib.h"
#else
#define WINDOW_DETAILS 0
#endif

#include "ztf_bind_common.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define ZTF_MAX_MONITOR_COUNT 32

typedef enum ztf_WindowMode
{
    ZTF_WM_WINDOWED,
    ZTF_WM_FULLSCREEN,
    ZTF_WM_BORDERLESS
} ztf_WindowMode;

typedef struct ztf_RectDesc
{
    int32_t left;
    int32_t top;
    int32_t right;
    int32_t bottom;
} ztf_RectDesc;

typedef enum ztf_WindowHandleType
{
    ZTF_WINDOW_HANDLE_TYPE_UNKNOWN,
    ZTF_WINDOW_HANDLE_TYPE_WIN32,
    ZTF_WINDOW_HANDLE_TYPE_XLIB,
    ZTF_WINDOW_HANDLE_TYPE_XCB,
    ZTF_WINDOW_HANDLE_TYPE_WAYLAND,
    ZTF_WINDOW_HANDLE_TYPE_ANDROID,
    ZTF_WINDOW_HANDLE_TYPE_VI_NN,
} ztf_WindowHandleType;

typedef struct ztf_WindowHandle
{
    ztf_WindowHandleType type;

#if defined(_WIN32)
    HWND window;
#elif defined(ANDROID)
    ANativeWindow* window;
    ANativeActivity* activity;
    AConfiguration* configuration;
#elif defined(__APPLE__) || defined(NX64) || defined(ORBIS) || defined(PROSPERO)
    void* window;
#elif defined(VK_USE_PLATFORM_XCB_KHR)
    xcb_connection_t* connection;
    xcb_window_t             window;
    xcb_screen_t* screen;
    xcb_intern_atom_reply_t* atom_wm_delete_window;
#elif defined(VK_USE_PLATFORM_XLIB_KHR) || defined(VK_USE_PLATFORM_WAYLAND_KHR)
    union
    {
#if defined(VK_USE_PLATFORM_XLIB_KHR)
        struct
        {
            Display* display;
            Window   window;
            Atom     xlib_wm_delete_window;
            Colormap colormap;
        };
#endif
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
        struct
        {
            struct wl_display* wl_display;
            struct wl_surface* wl_surface;
        };
#endif
    };
#endif
} ztf_WindowHandle;

typedef struct ztf_WindowDesc
{
    ztf_WindowHandle handle;
    ztf_RectDesc     windowedRect;
    ztf_RectDesc     fullscreenRect;
    ztf_RectDesc     clientRect;
    uint32_t     windowsFlags;
    bool         fullScreen;
    bool         cursorCaptured;
    bool         iconified;
    bool         maximized;
    bool         minimized;
    bool         hide;
    bool         noresizeFrame;
    bool         borderlessWindow;
    bool         overrideDefaultPosition;
    bool         centered;
    bool         forceLowDPI;

    int32_t mWindowMode;

    int32_t pCurRes[ZTF_MAX_MONITOR_COUNT];
    int32_t pLastRes[ZTF_MAX_MONITOR_COUNT];

    int32_t mWndX;
    int32_t mWndY;
    int32_t mWndW;
    int32_t mWndH;

    bool    mCursorHidden;
    int32_t mCursorInsideWindow;
    bool    mCursorCaptured;
    bool    mMinimizeRequested;

#if WINDOW_DETAILS
    bstring pWindowedRectLabel;
    bstring pFullscreenRectLabel;
    bstring pClientRectLabel;
    bstring pWndLabel;

    bstring pFullscreenLabel;
    bstring pCursorCapturedLabel;
    bstring pIconifiedLabel;
    bstring pMaximizedLabel;
    bstring pMinimizedLabel;
    bstring pNoResizeFrameLabel;
    bstring pBorderlessWindowLabel;
    bstring pOverrideDefaultPositionLabel;
    bstring pCenteredLabel;
    bstring pForceLowDPILabel;
    bstring pWindowModeLabel;
#endif

} ztf_WindowDesc;

typedef struct ztf_Resolution
{
    uint32_t mWidth;
    uint32_t mHeight;
} ztf_Resolution;

// Monitor data
//
typedef struct
{
    ztf_RectDesc     monitorRect;
    ztf_RectDesc     workRect;
    unsigned int dpi[2];
    unsigned int physicalSize[2];
    // This size matches the static size of DISPLAY_DEVICE.DeviceName
#if defined(_WINDOWS) || defined(XBOX)
    WCHAR adapterName[32];
    WCHAR displayName[32];
    WCHAR publicAdapterName[128];
    WCHAR publicDisplayName[128];
#elif defined(__APPLE__)
#if defined(TARGET_IOS)
#else
    CGDirectDisplayID displayID;
    char              publicAdapterName[64];
    char              publicDisplayName[64];
#endif
#elif defined(__linux__) && !defined(__ANDROID__)
    Screen* screen;
    char    adapterName[32];
    char    displayName[32];
    char    publicAdapterName[64];
    char    publicDisplayName[64];
#else
    char                     adapterName[32];
    char                     displayName[32];
    char                     publicAdapterName[64];
    char                     publicDisplayName[64];
#endif
    // stb_ds array of Resolutions
    ztf_Resolution* resolutions;
    ztf_Resolution  defaultResolution;
    bool        modesPruned;
    bool        modeChanged;
} ztf_MonitorDesc;

typedef enum ztf_ThermalStatus
{
    ZTF_THERMAL_STATUS_MIN = -2,

    ZTF_THERMAL_STATUS_NOT_SUPPORTED = -2, // Current platform/device/build doesn't support ThermalStatus queries
    ZTF_THERMAL_STATUS_ERROR = -1,         // There was an error retrieving thermal status

    // Note: These enum names are taken from Android, we might want to rename them or create our own
    ZTF_THERMAL_STATUS_NONE = 0,     // Means we didn't get any thermal status data yet (maybe device doesn't support it)
    ZTF_THERMAL_STATUS_LIGHT = 1,    // iOS Nominal
    ZTF_THERMAL_STATUS_MODERATE = 2, // iOS Fair
    ZTF_THERMAL_STATUS_SEVERE = 3,   // iOS Serious
    ZTF_THERMAL_STATUS_CRITICAL = 4, // iOS Critical
    ZTF_THERMAL_STATUS_EMERGENCY = 5,
    ZTF_THERMAL_STATUS_SHUTDOWN = 6,

    ZTF_THERMAL_STATUS_MAX,
} ztf_ThermalStatus;

// Reset
#if defined(_WINDOWS) || defined(__ANDROID__)
typedef enum ztf_ResetType
{
    ZTF_RESET_TYPE_NONE = 0,
    ZTF_RESET_TYPE_API_SWITCH = 0x1,
    ZTF_RESET_TYPE_GRAPHIC_CARD_SWITCH = 0x2,
#if defined(_WINDOWS)
    ZTF_RESET_TYPE_DEVICE_LOST = 0x4,
    ZTF_RESET_TYPE_GPU_MODE_SWITCH = 0x8,
#endif
} ztf_ResetType;

typedef struct ztf_ResetDesc
{
    ztf_ResetType mType;
} ztf_ResetDesc;
#endif

// Reload
typedef enum ztf_ReloadType
{
    ZTF_RELOAD_TYPE_RESIZE = 0x1,
    ZTF_RELOAD_TYPE_SHADER = 0x2,
    ZTF_RELOAD_TYPE_RENDERTARGET = 0x4,
    ZTF_RELOAD_TYPE_ALL = UINT32_MAX,
    ZTF_RELOAD_TYPE_COUNT = 3,
} ztf_ReloadType;

typedef struct ztf_ReloadDesc
{
    ztf_ReloadType mType;
} ztf_ReloadDesc;

typedef struct ztf_OSInfo
{
    char osName[256];
    char osVersion[256];
    char osDeviceName[256];
} ztf_OSInfo;

ZTF_C_API int ztf_getRectWidth(const ztf_RectDesc* rect);
ZTF_C_API int ztf_getRectHeight(const ztf_RectDesc* rect);

// Window handling
ZTF_C_API void ztf_openWindow(const char* app_name, ztf_WindowDesc* winDesc);
ZTF_C_API void ztf_closeWindow(ztf_WindowDesc* winDesc);
ZTF_C_API void ztf_setWindowRect(ztf_WindowDesc* winDesc, const ztf_RectDesc* rect);
ZTF_C_API void ztf_setWindowSize(ztf_WindowDesc* winDesc, unsigned width, unsigned height);
ZTF_C_API void ztf_setWindowed(ztf_WindowDesc* winDesc, unsigned width, unsigned height);
ZTF_C_API void ztf_setBorderless(ztf_WindowDesc* winDesc, unsigned width, unsigned height);
ZTF_C_API void ztf_setFullscreen(ztf_WindowDesc* winDesc);
ZTF_C_API void ztf_showWindow(ztf_WindowDesc* winDesc);
ZTF_C_API void ztf_hideWindow(ztf_WindowDesc* winDesc);
ZTF_C_API void ztf_maximizeWindow(ztf_WindowDesc* winDesc);
ZTF_C_API void ztf_minimizeWindow(ztf_WindowDesc* winDesc);
ZTF_C_API void ztf_centerWindow(ztf_WindowDesc* winDesc);
ZTF_C_API void ztf_captureCursor(ztf_WindowDesc* winDesc, bool bEnable);

// Mouse and cursor handling
ZTF_C_API void* ztf_createCursor(const char* path);
ZTF_C_API void ztf_setCursor(void* cursor);
ZTF_C_API void ztf_showCursor(void);
ZTF_C_API void ztf_hideCursor(void);
ZTF_C_API bool ztf_isCursorInsideTrackingArea(void);
ZTF_C_API void ztf_setMousePositionRelative(const ztf_WindowDesc* winDesc, int32_t x, int32_t y);
ZTF_C_API void ztf_setMousePositionAbsolute(int32_t x, int32_t y);

ZTF_C_API void ztf_getRecommendedResolution(ztf_RectDesc* rect);
ZTF_C_API void ztf_getRecommendedWindowRect(ztf_WindowDesc* winDesc, ztf_RectDesc* rect);
// Sets video mode for specified display
ZTF_C_API void setResolution(const ztf_MonitorDesc* pMonitor, const ztf_Resolution* pRes);

ZTF_C_API ztf_MonitorDesc* ztf_getMonitor(uint32_t index);
ZTF_C_API uint32_t     ztf_getMonitorCount(void);
ZTF_C_API uint32_t     ztf_getActiveMonitorIdx(void);
// pArray pointer to array with at least 2 elements(x,y)
ZTF_C_API void         ztf_getMonitorDpiScale(uint32_t monitorIndex, float dpiScale[2]);

ZTF_C_API bool ztf_getResolutionSupport(const ztf_MonitorDesc* pMonitor, const ztf_Resolution* pRes);

ZTF_C_API ztf_ThermalStatus ztf_getThermalStatus(void);
ZTF_C_API const char* ztf_getThermalStatusString(ztf_ThermalStatus thermalStatus);

#if defined(_WINDOWS) || defined(__ANDROID__)
ZTF_C_API void ztf_requestReset(const ztf_ResetDesc* pResetDesc);
#endif

ZTF_C_API ztf_OSInfo* ztf_getOsInfo(void);

//------------------------------------------------------------------------
// PLATFORM LAYER
//------------------------------------------------------------------------

ZTF_C_API void ztf_requestReload(const ztf_ReloadDesc* pReloadDesc);

// API functions
ZTF_C_API void ztf_requestShutdown(void);
typedef void (*ztf_errorMessagePopupCallbackFn)(void);
ZTF_C_API void ztf_errorMessagePopup(const char* title, const char* msg, ztf_WindowHandle* windowHandle, ztf_errorMessagePopupCallbackFn callback);

// Custom processing of OS pipe messages
typedef int32_t(*ztf_CustomMessageProcessor)(ztf_WindowDesc* pWindow, void* msg);
ZTF_C_API void ztf_setCustomMessageProcessor(ztf_CustomMessageProcessor proc);

/// @param stdOutFile The file to which the output of the command should be written. May be NULL.
ZTF_C_API int ztf_systemRun(const char* command, const char** arguments, size_t argumentCount, const char* stdOutFile);

#ifdef __cplusplus
}
#endif