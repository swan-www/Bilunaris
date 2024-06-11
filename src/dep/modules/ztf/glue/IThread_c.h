#pragma once

#include "ztf_bind_common.h"

#include "Config_c.h"

#include "IOperatingSystem_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

#if defined(_WINDOWS) || defined(XBOX)
	typedef unsigned long ztf_ThreadID;
#define ZTF_THREAD_ID_MAX ULONG_MAX
#define ZTF_THREAD_ID_MIN ((unsigned long)0)
#else
#include <pthread.h>
#if !defined(NX64)
#if !defined(__APPLE__) || defined(TARGET_IOS)
	typedef uint32_t ztf_ThreadID;
#endif
#define ZTF_THREAD_ID_MAX UINT32_MAX
#define ZTF_THREAD_ID_MIN ((uint32_t)0)
#endif // !NX64

#endif

#define ZTF_INVALID_THREAD_ID 0

#if defined(_WINDOWS) || defined(XBOX)
#if !defined(ZTF_THREAD_LOCAL)
#define ZTF_THREAD_LOCAL __declspec(thread)
#endif
#define ZTF_INIT_CALL_ONCE_GUARD INIT_ONCE_STATIC_INIT
	typedef INIT_ONCE ztf_CallOnceGuard;
#else
#if !defined(THREAD_LOCAL)
#define ZTF_THREAD_LOCAL __thread
#endif
#define ZTF_INIT_CALL_ONCE_GUARD PTHREAD_ONCE_INIT
	typedef pthread_once_t ztf_CallOnceGuard;
#endif

	// Max thread name should be 15 + null character
#ifndef ZTF_MAX_THREAD_NAME_LENGTH
#define ZTF_MAX_THREAD_NAME_LENGTH 31
#endif

#define ZTF_TIMEOUT_INFINITE UINT32_MAX

typedef void (*ztf_CallOnceFn)(void);
/*
    * Brief:
    *   Guaranties that CallOnceFn will be called once in a thread-safe way.
    * Notes:
    *   CallOnceGuard has to be a pointer to a global variable initialized with INIT_CALL_ONCE_GUARD
    */
ZTF_C_API void ztf_callOnce(ztf_CallOnceGuard* pGuard, ztf_CallOnceFn pFn);

/// Operating system mutual exclusion primitive.
typedef struct ztf_Mutex
{
#if defined(_WINDOWS) || defined(XBOX)
    CRITICAL_SECTION mHandle;
#elif defined(NX64)
    MutexTypeNX             mMutexPlatformNX;
    uint32_t                mSpinCount;
#else
    pthread_mutex_t pHandle;
    uint32_t        mSpinCount;
#endif
} ztf_Mutex;

#define ZTF_MUTEX_DEFAULT_SPIN_COUNT 1500

ZTF_C_API bool ztf_initMutex(ztf_Mutex* pMutex);
ZTF_C_API void ztf_destroyMutex(ztf_Mutex* pMutex);

ZTF_C_API void ztf_acquireMutex(ztf_Mutex* pMutex);
ZTF_C_API bool ztf_tryAcquireMutex(ztf_Mutex* pMutex);
ZTF_C_API void ztf_releaseMutex(ztf_Mutex* pMutex);

typedef struct ztf_ConditionVariable
{
#if defined(_WINDOWS) || defined(XBOX)
    void* pHandle;
#elif defined(NX64)
    ConditionVariableTypeNX mCondPlatformNX;
#else
    pthread_cond_t  pHandle;
#endif
} ztf_ConditionVariable;

ZTF_C_API bool ztf_initConditionVariable(ztf_ConditionVariable* cv);
ZTF_C_API void ztf_destroyConditionVariable(ztf_ConditionVariable* cv);

ZTF_C_API void ztf_waitConditionVariable(ztf_ConditionVariable* cv, ztf_Mutex* pMutex, uint32_t msTimeout);
ZTF_C_API void ztf_wakeOneConditionVariable(ztf_ConditionVariable* cv);
ZTF_C_API void ztf_wakeAllConditionVariable(ztf_ConditionVariable* cv);

typedef void (*ztf_ThreadFunction)(void*);

/// Work queue item.
typedef struct ztf_ThreadDesc
{
    /// Work item description and thread index (Main thread => 0)
    ztf_ThreadFunction pFunc;
    void* pData;
    char           mThreadName[ZTF_MAX_THREAD_NAME_LENGTH];

    // Affinity is a bit mask. It tells on which CPU thread can run.
    // Maximum supported number of bits is 1024.
    // Use 'setCpuAffinity()' helper function repeatedly for convenience
    bool     setAffinityMask;
    uint64_t affinityMask[16];
} ztf_ThreadDesc;

ZTF_C_API void ztf_setCpuAffinity(struct ztf_ThreadDesc* desc, uint64_t cpuId);

#if defined(_WINDOWS) || defined(XBOX)
typedef void* ztf_ThreadHandle;
#elif !defined(NX64)
typedef pthread_t ztf_ThreadHandle;
#endif

ZTF_C_API bool ztf_initThread(ztf_ThreadDesc* pItem, ztf_ThreadHandle* pHandle);
ZTF_C_API void ztf_joinThread(ztf_ThreadHandle handle);
ZTF_C_API void ztf_detachThread(ztf_ThreadHandle handle);

ZTF_C_API void         ztf_setMainThread(void);
ZTF_C_API ztf_ThreadID ztf_getCurrentThreadID(void);
ZTF_C_API void         ztf_getCurrentThreadName(char* buffer, int buffer_size);
ZTF_C_API void         ztf_setCurrentThreadName(const char* name);
ZTF_C_API bool         ztf_isMainThread(void);
ZTF_C_API void         ztf_threadSleep(unsigned mSec);
ZTF_C_API unsigned int ztf_getNumCPUCores(void);

// Performance metrics functions
#if defined(ENABLE_THREAD_PERFORMANCE_STATS)
#define ZTF_MAX_PERFORMANCE_STATS_CORES 64

typedef struct ztf_PerformanceStats
{
    float mCoreUsagePercentage[ZTF_MAX_PERFORMANCE_STATS_CORES];
} ztf_PerformanceStats;

typedef enum ztf_PerformanceStatsFlags
{
    ZTF_PERFORMANCE_STATS_FLAG_CORE_USAGE_PERCENTAGE = 0x0,
} ztf_PerformanceStatsFlags;

ZTF_C_API int              ztf_initPerformanceStats(ztf_PerformanceStatsFlags flags);
ZTF_C_API void             ztf_updatePerformanceStats(void);
ZTF_C_API ztf_PerformanceStats ztf_getPerformanceStats(void);
ZTF_C_API void             ztf_exitPerformanceStats(void);
#endif

#ifdef __cplusplus
} // extern "C"
#endif