#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "ztf_bind_common.h"

#include "Config_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define ZTF_KB (1024)
#define ZTF_MB (1024 * ZTF_KB)
#define ZTF_GB (1024 * ZTF_MB)

#ifdef ZTF_ENABLE_MEMORY_TRACKING
    typedef struct ztf_MemoryStatistics
    {
        uint32_t totalReportedMemory;
        uint32_t totalActualMemory;
        uint32_t peakReportedMemory;
        uint32_t peakActualMemory;
        uint32_t accumulatedReportedMemory;
        uint32_t accumulatedActualMemory;
        uint32_t accumulatedAllocUnitCount;
        uint32_t totalAllocUnitCount;
        uint32_t peakAllocUnitCount;
    } ztf_MemoryStatistics;
#endif

#ifdef __cplusplus
    extern "C"
    {
#endif
        // appName is used to create dump file, pass NULL to avoid it
        ZTF_C_API bool ztf_initMemAlloc(const char* appName);
        ZTF_C_API void ztf_exitMemAlloc(void);

#ifdef ZTF_ENABLE_MEMORY_TRACKING
        ZTF_C_API MemoryStatistics ztf_memGetStatistics(void);
#endif

        ZTF_C_API void* ztf_malloc_internal(size_t size, const char* f, int l, const char* sf);
        ZTF_C_API void* ztf_memalign_internal(size_t align, size_t size, const char* f, int l, const char* sf);
        ZTF_C_API void* ztf_calloc_internal(size_t count, size_t size, const char* f, int l, const char* sf);
        ZTF_C_API void* ztf_calloc_memalign_internal(size_t count, size_t align, size_t size, const char* f, int l, const char* sf);
        ZTF_C_API void* ztf_realloc_internal(void* ptr, size_t size, const char* f, int l, const char* sf);
        ZTF_C_API void  ztf_free_internal(void* ptr, const char* f, int l, const char* sf);

#ifdef __cplusplus
} // extern "C"
#endif

#ifndef tf_malloc
#define tf_malloc(size) ztf_malloc_internal(size, __FILE__, __LINE__, __FUNCTION__)
#endif
#ifndef tf_memalign
#define tf_memalign(align, size) ztf_memalign_internal(align, size, __FILE__, __LINE__, __FUNCTION__)
#endif
#ifndef tf_calloc
#define tf_calloc(count, size) ztf_calloc_internal(count, size, __FILE__, __LINE__, __FUNCTION__)
#endif
#ifndef tf_calloc_memalign
#define tf_calloc_memalign(count, align, size) ztf_calloc_memalign_internal(count, align, size, __FILE__, __LINE__, __FUNCTION__)
#endif
#ifndef tf_realloc
#define tf_realloc(ptr, size) ztf_realloc_internal(ptr, size, __FILE__, __LINE__, __FUNCTION__)
#endif
#ifndef tf_free
#define tf_free(ptr) ztf_free_internal(ptr, __FILE__, __LINE__, __FUNCTION__)
#endif

#ifdef __cplusplus
}
#endif