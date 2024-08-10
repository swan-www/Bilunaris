#pragma once
#include <stdbool.h> 
#include <stdint.h>

#include "ztf_bind_common.h"
#include "IThread_c.h"

#include "MathTypes_glue.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef uint64_t ztf_ProfileToken;
#define ZTF_PROFILE_INVALID_TOKEN (uint64_t) - 1

typedef struct ztf_Cmd ztf_Cmd;
typedef struct ztf_Renderer ztf_Renderer;
typedef struct ztf_Queue ztf_Queue;
typedef struct ztf_FontDrawDesc ztf_FontDrawDesc;
typedef struct ztf_UserInterface ztf_UserInterface;
typedef struct ztf_ProfilerDesc ztf_ProfilerDesc;
typedef struct ztf_AppSettings ztf_AppSettings;
typedef struct ztf_Float2 ztf_Float2;

typedef struct ztf_ProfilerDesc
{
    ztf_Renderer* pRenderer;
    ztf_Queue**   ppQueues;

    const char**  ppProfilerNames;
    ztf_ProfileToken* pProfileTokens;

    uint32_t mGpuProfilerCount;
    uint32_t mWidthUI;
    uint32_t mHeightUI;
} ztf_ProfilerDesc;

// Must be called before adding any profiling
ZTF_C_API void ztf_initProfiler(ztf_ProfilerDesc* pDesc);

// Call on application exit
ZTF_C_API void ztf_exitProfiler();

// Call once per frame to update profiler
ZTF_C_API void ztf_flipProfiler();

// Set amount of frames before aggregation
ZTF_C_API void ztf_setAggregateFrames(uint32_t nFrames);

// Dump profile data to "profile-(date).html" of recorded frames, until a maximum amount of frames
ZTF_C_API void ztf_dumpProfileData(const char* appName, uint32_t nMaxFrames);

// Dump benchmark data to "benchmark-(data).txt" of recorded frames
ZTF_C_API void ztf_dumpBenchmarkData(ztf_AppSettings* pSettings, const char* outFilename, const char* appName);

//------ Profiler UI Widget --------//

// Call once per frame before AppUI.Draw, draw requested Gpu profiler timers
// Returns text dimensions so caller can align other UI elements
ZTF_C_API ztf_Float2 ztf_cmdDrawGpuProfile(ztf_Cmd* pCmd, ztf_Float2 screenCoordsInPx, ztf_ProfileToken nProfileToken, ztf_FontDrawDesc* pDrawDesc);

// Call once per frame before AppUI.Draw, draw requested Cpu profile time
// Returns text dimensions so caller can align other UI elements
ZTF_C_API ztf_Float2 ztf_cmdDrawCpuProfile(ztf_Cmd* pCmd, ztf_Float2 screenCoordsInPx, ztf_FontDrawDesc* pDrawDesc);

// Toggle profiler display on/off.
ZTF_C_API void ztf_toggleProfilerUI(bool active);

// Toggle profiler menu display on/off.
ZTF_C_API void ztf_toggleProfilerMenuUI(bool active);

// Toggle profiler display on/off. Includes system information. Used when taking screenshots.
ZTF_C_API void ztf_toggleProfilerDrawing(bool active);

//------ Gpu profiler ------------//

// Call only after initProfiler(), for manually adding Gpu Profilers
ZTF_C_API ztf_ProfileToken ztf_addGpuProfiler(ztf_Renderer* pRenderer, ztf_Queue* pQueue, const char* pProfilerName);

// Call only before exitProfiler(), for manually removing Gpu Profilers
ZTF_C_API void ztf_removeGpuProfiler(ztf_ProfileToken nProfileToken);

// Must be called before any call to cmdBeginGpuTimestampQuery
// Preferred time to call this function is right after calling beginCmd
ZTF_C_API void ztf_cmdBeginGpuFrameProfile(ztf_Cmd* pCmd, ztf_ProfileToken nProfileToken, bool bUseMarker);

// Must be called after all gpu profiles are finished.
// This function cannot be called inside a render pass (cmdBeginRender-cmdEndRender)
// Preferred time to call this function is right before calling endCmd
ZTF_C_API void ztf_cmdEndGpuFrameProfile(ztf_Cmd* pCmd, ztf_ProfileToken nProfileToken);

ZTF_C_API ztf_ProfileToken ztf_cmdBeginGpuTimestampQuery(ztf_Cmd* pCmd, ztf_ProfileToken nProfileToken, const char* pName, bool bUseMarker);

ZTF_C_API void ztf_cmdEndGpuTimestampQuery(ztf_Cmd* pCmd, ztf_ProfileToken nProfileToken);

// Gpu times in milliseconds
ZTF_C_API float ztf_getGpuProfileTime(ztf_ProfileToken nProfileToken);
ZTF_C_API float ztf_getGpuProfileAvgTime(ztf_ProfileToken nProfileToken);
ZTF_C_API float ztf_getGpuProfileMinTime(ztf_ProfileToken nProfileToken);
ZTF_C_API float ztf_getGpuProfileMaxTime(ztf_ProfileToken nProfileToken);

ZTF_C_API uint64_t ztf_getGpuProfileTicksPerSecond(ztf_ProfileToken nProfileToken);

//------ Cpu profiler ------------//

ZTF_C_API uint64_t ztf_cpuProfileEnter(ztf_ProfileToken nToken);

ZTF_C_API void ztf_cpuProfileLeave(ztf_ProfileToken nToken, uint64_t nTick);

ZTF_C_API ztf_ProfileToken ztf_getCpuProfileToken(const char* pGroup, const char* pName, uint32_t nColor);

// Cpu times in milliseconds
ZTF_C_API float ztf_getCpuProfileTime(const char* pGroup, const char* pName, ztf_ThreadID* pThreadID);
ZTF_C_API float ztf_getCpuProfileAvgTime(const char* pGroup, const char* pName, ztf_ThreadID* pThreadID);
ZTF_C_API float ztf_getCpuProfileMinTime(const char* pGroup, const char* pName, ztf_ThreadID* pThreadID);
ZTF_C_API float ztf_getCpuProfileMaxTime(const char* pGroup, const char* pName, ztf_ThreadID* pThreadID);

ZTF_C_API float ztf_getCpuFrameTime();
ZTF_C_API float ztf_getCpuAvgFrameTime();
ZTF_C_API float ztf_getCpuMinFrameTime();
ZTF_C_API float ztf_getCpuMaxFrameTime();

#ifdef __cplusplus
}
#endif