#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/Utilities/Interfaces/IThread.h"

#define ZTF_BLOCK_CONFIG_INCLUDE
#include "IThread_c.h"
#undef ZTF_BLOCK_CONFIG_INCLUDE

#ifdef __cplusplus
extern "C"
{
#endif

ZTF_C_API void ztf_callOnce(ztf_CallOnceGuard* pGuard, ztf_CallOnceFn pFn)
{
    callOnce((CallOnceGuard*) pGuard, (CallOnceFn) pFn);
}

ZTF_C_API bool ztf_initMutex(ztf_Mutex* pMutex)
{
    return initMutex((Mutex*) pMutex);
}

ZTF_C_API void ztf_destroyMutex(ztf_Mutex* pMutex)
{
    destroyMutex((Mutex*) pMutex);
}

ZTF_C_API void ztf_acquireMutex(ztf_Mutex* pMutex)
{
    acquireMutex((Mutex*) pMutex);
}

ZTF_C_API bool ztf_tryAcquireMutex(ztf_Mutex* pMutex)
{
    return tryAcquireMutex((Mutex*) pMutex);
}

ZTF_C_API void ztf_releaseMutex(ztf_Mutex* pMutex)
{
    releaseMutex((Mutex*) pMutex);
}


ZTF_C_API bool ztf_initConditionVariable(ztf_ConditionVariable* cv)
{
    return initConditionVariable((ConditionVariable*) cv);
}

ZTF_C_API void ztf_destroyConditionVariable(ztf_ConditionVariable* cv)
{
    destroyConditionVariable((ConditionVariable*) cv);
}


ZTF_C_API void ztf_waitConditionVariable(ztf_ConditionVariable* cv, ztf_Mutex* pMutex, uint32_t msTimeout)
{
    waitConditionVariable((ConditionVariable*) cv, (Mutex*) pMutex, msTimeout);
}

ZTF_C_API void ztf_wakeOneConditionVariable(ztf_ConditionVariable* cv)
{
    wakeOneConditionVariable((ConditionVariable*) cv);
}

ZTF_C_API void ztf_wakeAllConditionVariable(ztf_ConditionVariable* cv)
{
    wakeAllConditionVariable((ConditionVariable*) cv);
}


ZTF_C_API void ztf_setCpuAffinity(struct ztf_ThreadDesc* desc, uint64_t cpuId)
{
    setCpuAffinity((ThreadDesc*) desc, cpuId);
}


ZTF_C_API bool ztf_initThread(ztf_ThreadDesc* pItem, ztf_ThreadHandle* pHandle)
{
    return initThread((ThreadDesc*) pItem, (ThreadHandle*) pHandle);
}

ZTF_C_API void ztf_joinThread(ztf_ThreadHandle handle)
{
    joinThread((ThreadHandle) handle);
}

ZTF_C_API void ztf_detachThread(ztf_ThreadHandle handle)
{
    detachThread((ThreadHandle) handle);
}


ZTF_C_API void ztf_setMainThread(void)
{
    setMainThread();
}

ZTF_C_API ztf_ThreadID ztf_getCurrentThreadID(void)
{
    return (ztf_ThreadID)getCurrentThreadID();
}

ZTF_C_API void ztf_getCurrentThreadName(char* buffer, int buffer_size)
{
    getCurrentThreadName(buffer, buffer_size);
}

ZTF_C_API void ztf_setCurrentThreadName(const char* name)
{
    setCurrentThreadName(name);
}

ZTF_C_API bool ztf_isMainThread(void)
{
    return isMainThread();
}

ZTF_C_API void ztf_threadSleep(unsigned mSec)
{
    threadSleep(mSec);
}

ZTF_C_API unsigned int ztf_getNumCPUCores(void)
{
    return getNumCPUCores();
}


// Performance metrics functions
#if defined(ENABLE_THREAD_PERFORMANCE_STATS)
ZTF_C_API int ztf_initPerformanceStats(ztf_PerformanceStatsFlags flags)
{
    return initPerformanceStats((PerformanceStatsFlags) flags);
}

ZTF_C_API void ztf_updatePerformanceStats(void)
{
    updatePerformanceStats();
}

ZTF_C_API ztf_PerformanceStats ztf_getPerformanceStats(void)
{
    PerformanceStats ps = getPerformanceStats();
    ztf_PerformanceStats zps = *(ztf_PerformanceStats*)&ps;
    return zps;
}

ZTF_C_API void ztf_exitPerformanceStats(void)
{
    exitPerformanceStats();
}

#else
ZTF_C_API int              ztf_initPerformanceStats(ztf_PerformanceStatsFlags flags){return 0;}
ZTF_C_API void             ztf_updatePerformanceStats(void){}
ZTF_C_API ztf_PerformanceStats ztf_getPerformanceStats(void){return 0;}
ZTF_C_API void             ztf_exitPerformanceStats(void){}
#endif

#ifdef __cplusplus
} // extern "C"
#endif