//Has to go first so it can override some windows defines
#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/Application/Config.h"

#include "IOperatingSystem_c.h"

#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/OS/Interfaces/IOperatingSystem.h"

#ifdef __cplusplus
extern "C"
{
#endif

ZTF_C_API int ztf_getRectWidth(const ztf_RectDesc* rect)
{
	return getRectWidth((const RectDesc*)rect);
}

ZTF_C_API int ztf_getRectHeight(const ztf_RectDesc* rect)
{
	return getRectHeight((const RectDesc*)rect);
}

// Window handling
ZTF_C_API void ztf_openWindow(const char* app_name, ztf_WindowDesc* winDesc)
{
	openWindow(app_name, (WindowDesc*)winDesc);
}

ZTF_C_API void ztf_closeWindow(ztf_WindowDesc* winDesc)
{
	closeWindow((WindowDesc*)winDesc);
}

ZTF_C_API void ztf_setWindowRect(ztf_WindowDesc* winDesc, const ztf_RectDesc* rect)
{
	setWindowRect((WindowDesc*)winDesc, (const RectDesc*)rect);
}

ZTF_C_API void ztf_setWindowSize(ztf_WindowDesc* winDesc, unsigned width, unsigned height)
{
	setWindowSize((WindowDesc*)winDesc, width, height);
}

ZTF_C_API void ztf_setWindowed(ztf_WindowDesc* winDesc, unsigned width, unsigned height)
{
	setWindowed((WindowDesc*)winDesc, width, height);
}

ZTF_C_API void ztf_setBorderless(ztf_WindowDesc* winDesc, unsigned width, unsigned height)
{
	setBorderless((WindowDesc*)winDesc, width, height);
}

ZTF_C_API void ztf_setFullscreen(ztf_WindowDesc* winDesc)
{
	setFullscreen((WindowDesc*)winDesc);
}

ZTF_C_API void ztf_showWindow(ztf_WindowDesc* winDesc)
{
	showWindow((WindowDesc*)winDesc);
}

ZTF_C_API void ztf_hideWindow(ztf_WindowDesc* winDesc)
{
	hideWindow((WindowDesc*)winDesc);
}

ZTF_C_API void ztf_maximizeWindow(ztf_WindowDesc* winDesc)
{
	maximizeWindow((WindowDesc*)winDesc);
}

ZTF_C_API void ztf_minimizeWindow(ztf_WindowDesc* winDesc)
{
	minimizeWindow((WindowDesc*)winDesc);
}

ZTF_C_API void ztf_centerWindow(ztf_WindowDesc* winDesc)
{
	centerWindow((WindowDesc*)winDesc);
}

ZTF_C_API void ztf_captureCursor(ztf_WindowDesc* winDesc, bool bEnable)
{
	captureCursor((WindowDesc*)winDesc, bEnable);
}

// Mouse and cursor handling
ZTF_C_API void* ztf_createCursor(const char* path)
{
	return createCursor(path);
}

ZTF_C_API void ztf_setCursor(void* cursor)
{
	setCursor(cursor);
}

ZTF_C_API void ztf_showCursor(void)
{
	showCursor();
}

ZTF_C_API void ztf_hideCursor(void)
{
	hideCursor();
}

ZTF_C_API bool ztf_isCursorInsideTrackingArea(void)
{
	return isCursorInsideTrackingArea();
}

ZTF_C_API void ztf_setMousePositionRelative(const ztf_WindowDesc* winDesc, int32_t x, int32_t y)
{
	setMousePositionRelative((const WindowDesc*)winDesc, x, y);
}

ZTF_C_API void ztf_setMousePositionAbsolute(int32_t x, int32_t y)
{
	setMousePositionAbsolute(x, y);
}

ZTF_C_API void ztf_getRecommendedResolution(ztf_RectDesc* rect)
{
	getRecommendedResolution((RectDesc*)rect);
}

ZTF_C_API void ztf_getRecommendedWindowRect(ztf_WindowDesc* winDesc, ztf_RectDesc* rect)
{
	getRecommendedWindowRect((WindowDesc*)winDesc, (RectDesc*)rect);
}

// Sets video mode for specified display
ZTF_C_API void ztf_setResolution(const ztf_MonitorDesc* pMonitor, const ztf_Resolution* pRes)
{
	setResolution((MonitorDesc*)pMonitor, (const Resolution*)pRes);
}

ZTF_C_API ztf_MonitorDesc* ztf_getMonitor(uint32_t index)
{
	return (ztf_MonitorDesc*)getMonitor(index);
}

ZTF_C_API uint32_t ztf_getMonitorCount(void)
{
	return getMonitorCount();
}

ZTF_C_API uint32_t ztf_getActiveMonitorIdx(void)
{
	return getActiveMonitorIdx();
}

// pArray pointer to array with at least 2 elements(x,y)
ZTF_C_API void ztf_getMonitorDpiScale(uint32_t monitorIndex, float dpiScale[2])
{
	getMonitorDpiScale(monitorIndex, dpiScale);
}

ZTF_C_API bool ztf_getResolutionSupport(const ztf_MonitorDesc* pMonitor, const ztf_Resolution* pRes)
{
	return getResolutionSupport((const MonitorDesc*)pMonitor, (const Resolution*)pRes);
}

ZTF_C_API ztf_ThermalStatus ztf_getThermalStatus(void)
{
	return (ztf_ThermalStatus)getThermalStatus();
}

ZTF_C_API const char* ztf_getThermalStatusString(ztf_ThermalStatus thermalStatus)
{
	return getThermalStatusString((ThermalStatus)thermalStatus);
}

#if defined(_WINDOWS) || defined(__ANDROID__)
ZTF_C_API void ztf_requestReset(const ztf_ResetDesc* pResetDesc)
{
	requestReset((const ResetDesc*)pResetDesc);
}
#endif

ZTF_C_API ztf_OSInfo* ztf_getOsInfo(void)
{
	return (ztf_OSInfo*)getOsInfo();
}

//------------------------------------------------------------------------
// PLATFORM LAYER
//------------------------------------------------------------------------

ZTF_C_API void ztf_requestReload(const ztf_ReloadDesc* pReloadDesc)
{
	requestReload((const ReloadDesc*)pReloadDesc);
}

// API functions
ZTF_C_API void ztf_requestShutdown(void)
{
	requestShutdown();
}

typedef void (*ztf_errorMessagePopupCallbackFn)(void);
ZTF_C_API void ztf_errorMessagePopup(const char* title, const char* msg, ztf_WindowHandle* windowHandle, ztf_errorMessagePopupCallbackFn callback)
{
	errorMessagePopup(title, msg, (WindowHandle*)windowHandle, (errorMessagePopupCallbackFn)callback);
}

// Custom processing of OS pipe messages
typedef int32_t(*ztf_CustomMessageProcessor)(ztf_WindowDesc* pWindow, void* msg);
ZTF_C_API void ztf_setCustomMessageProcessor(ztf_CustomMessageProcessor proc)
{
	setCustomMessageProcessor((CustomMessageProcessor)proc);
}

/// @param stdOutFile The file to which the output of the command should be written. May be NULL.
ZTF_C_API int ztf_systemRun(const char* command, const char** arguments, size_t argumentCount, const char* stdOutFile)
{
	systemRun(command, arguments, argumentCount, stdOutFile);
}

#ifdef __cplusplus
}
#endif