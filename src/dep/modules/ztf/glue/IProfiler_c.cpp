#include "IProfiler_c.h"

#ifdef __cplusplus
#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/Application/Interfaces/IProfiler.h"
#endif

#define ZTF_BLOCK_CONFIG_INCLUDE
//#include "IOperatingSystem_c.h"
//#include "ILog_c.h"
//#include "IThread_c.h"
//#include "IApp_c.h"
//#include "GraphicsConfig_c.h"
#undef ZTF_BLOCK_CONFIG_INCLUDE

// Must be called before adding any profiling
ZTF_C_API void ztf_initProfiler(ztf_ProfilerDesc* pDesc)
{
	initProfiler((ProfilerDesc*) pDesc);
}

// Call on application exit
ZTF_C_API void ztf_exitProfiler()
{
	exitProfiler();
}

// Call once per frame to update profiler
ZTF_C_API void ztf_flipProfiler()
{
	flipProfiler();
}

// Set amount of frames before aggregation
ZTF_C_API void ztf_setAggregateFrames(uint32_t nFrames)
{
	setAggregateFrames(nFrames);
}

// Dump profile data to "profile-(date).html" of recorded frames, until a maximum amount of frames
ZTF_C_API void ztf_dumpProfileData(const char* appName, uint32_t nMaxFrames)
{
	dumpProfileData(appName, nMaxFrames);
}

// Dump benchmark data to "benchmark-(data).txt" of recorded frames
ZTF_C_API void ztf_dumpBenchmarkData(ztf_AppSettings* pSettings, const char* outFilename, const char* appName)
{
	dumpBenchmarkData((IApp::Settings*) pSettings, outFilename, appName);
}

//------ Profiler UI Widget --------//

// Call once per frame before AppUI.Draw, draw requested Gpu profiler timers
// Returns text dimensions so caller can align other UI elements
ZTF_C_API ztf_Float2 ztf_cmdDrawGpuProfile(ztf_Cmd* pCmd, ztf_Float2 screenCoordsInPx, ztf_ProfileToken nProfileToken, ztf_FontDrawDesc* pDrawDesc)
{
	float2 result = cmdDrawGpuProfile((Cmd*) pCmd, float2{screenCoordsInPx.x, screenCoordsInPx.y}, (ProfileToken)nProfileToken, (FontDrawDesc*)pDrawDesc);
	return ztf_Float2{result.x, result.y};
}

// Call once per frame before AppUI.Draw, draw requested Cpu profile time
// Returns text dimensions so caller can align other UI elements
ZTF_C_API ztf_Float2 ztf_cmdDrawCpuProfile(ztf_Cmd* pCmd, ztf_Float2 screenCoordsInPx, ztf_FontDrawDesc* pDrawDesc)
{
	float2 result = cmdDrawCpuProfile((Cmd*) pCmd, float2{screenCoordsInPx.x, screenCoordsInPx.y}, (FontDrawDesc*) pDrawDesc);
}

// Toggle profiler display on/off.
ZTF_C_API void ztf_toggleProfilerUI(bool active)
{
	toggleProfilerUI(active);
}

// Toggle profiler menu display on/off.
ZTF_C_API void ztf_toggleProfilerMenuUI(bool active)
{
	toggleProfilerMenuUI(active);
}

// Toggle profiler display on/off. Includes system information. Used when taking screenshots.
ZTF_C_API void ztf_toggleProfilerDrawing(bool active)
{
	toggleProfilerDrawing(active);
}

//------ Gpu profiler ------------//

// Call only after initProfiler(), for manually adding Gpu Profilers
ZTF_C_API ztf_ProfileToken ztf_addGpuProfiler(ztf_Renderer* pRenderer, ztf_Queue* pQueue, const char* pProfilerName)
{
	return addGpuProfiler((Renderer*) pRenderer, (Queue*) pQueue, pProfilerName);
}

// Call only before exitProfiler(), for manually removing Gpu Profilers
ZTF_C_API void ztf_removeGpuProfiler(ztf_ProfileToken nProfileToken)
{
	removeGpuProfiler((ProfileToken) nProfileToken);
}

// Must be called before any call to cmdBeginGpuTimestampQuery
// Preferred time to call this function is right after calling beginCmd
ZTF_C_API void ztf_cmdBeginGpuFrameProfile(ztf_Cmd* pCmd, ztf_ProfileToken nProfileToken, bool bUseMarker)
{
	cmdBeginGpuFrameProfile((Cmd*) pCmd, (ProfileToken)nProfileToken, bUseMarker);
}

// Must be called after all gpu profiles are finished.
// This function cannot be called inside a render pass (cmdBeginRender-cmdEndRender)
// Preferred time to call this function is right before calling endCmd
ZTF_C_API void ztf_cmdEndGpuFrameProfile(ztf_Cmd* pCmd, ztf_ProfileToken nProfileToken)
{
	cmdEndGpuFrameProfile((Cmd*) pCmd, (ProfileToken) nProfileToken);
}

ZTF_C_API ztf_ProfileToken ztf_cmdBeginGpuTimestampQuery(ztf_Cmd* pCmd, ztf_ProfileToken nProfileToken, const char* pName, bool bUseMarker = true)
{
	return cmdBeginGpuTimestampQuery((Cmd*) pCmd, (ProfileToken) nProfileToken, pName, bUseMarker);
}

ZTF_C_API void ztf_cmdEndGpuTimestampQuery(ztf_Cmd* pCmd, ztf_ProfileToken nProfileToken)
{
	cmdEndGpuTimestampQuery((Cmd*) pCmd, (ProfileToken)nProfileToken);
}

// Gpu times in milliseconds
ZTF_C_API float ztf_getGpuProfileTime(ztf_ProfileToken nProfileToken)
{
	return getGpuProfileTime((ProfileToken) nProfileToken);
}
ZTF_C_API float ztf_getGpuProfileAvgTime(ztf_ProfileToken nProfileToken)
{
	return getGpuProfileAvgTime((ProfileToken) nProfileToken);
}
ZTF_C_API float ztf_getGpuProfileMinTime(ztf_ProfileToken nProfileToken)
{
	return getGpuProfileMinTime((ProfileToken) nProfileToken);
}
ZTF_C_API float ztf_getGpuProfileMaxTime(ztf_ProfileToken nProfileToken)
{
	return getGpuProfileMaxTime((ProfileToken) nProfileToken);
}

ZTF_C_API uint64_t ztf_getGpuProfileTicksPerSecond(ztf_ProfileToken nProfileToken)
{
	return getGpuProfileTicksPerSecond((ProfileToken) nProfileToken);
}

//------ Cpu profiler ------------//

ZTF_C_API uint64_t ztf_cpuProfileEnter(ztf_ProfileToken nToken)
{
	return cpuProfileEnter((ProfileToken) nToken);
}

ZTF_C_API void ztf_cpuProfileLeave(ztf_ProfileToken nToken, uint64_t nTick)
{
	cpuProfileLeave((ProfileToken) nToken, nTick);
}

ZTF_C_API ztf_ProfileToken ztf_getCpuProfileToken(const char* pGroup, const char* pName, uint32_t nColor)
{
	return getCpuProfileToken(pGroup, pName, nColor);
}

// Cpu times in milliseconds
FORGE_API float ztf_getCpuProfileTime(const char* pGroup, const char* pName, ztf_ThreadID* pThreadID)
{
	return getCpuProfileTime(pGroup, pName, (ThreadID*)pThreadID);
}
FORGE_API float ztf_getCpuProfileAvgTime(const char* pGroup, const char* pName, ztf_ThreadID* pThreadID)
{
	return getCpuProfileAvgTime(pGroup, pName, (ThreadID*)pThreadID);
}
FORGE_API float ztf_getCpuProfileMinTime(const char* pGroup, const char* pName, ztf_ThreadID* pThreadID)
{
	return getCpuProfileMinTime(pGroup, pName, (ThreadID*)pThreadID);
}
FORGE_API float ztf_getCpuProfileMaxTime(const char* pGroup, const char* pName, ztf_ThreadID* pThreadID)
{
	return getCpuProfileMaxTime(pGroup, pName, (ThreadID*)pThreadID);
}

FORGE_API float ztf_getCpuFrameTime()
{
	return getCpuFrameTime();
}
FORGE_API float ztf_getCpuAvgFrameTime()
{
	return getCpuAvgFrameTime();
}

FORGE_API float ztf_getCpuMinFrameTime()
{
	return getCpuMinFrameTime();
}

FORGE_API float ztf_getCpuMaxFrameTime()
{
	return getCpuMaxFrameTime();
}