#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/Utilities/Interfaces/IMemory.h"

#define ZTF_BLOCK_CONFIG_INCLUDE
#include "IMemory_c.h"
#undef ZTF_BLOCK_CONFIG_INCLUDE

#ifdef __cplusplus
extern "C"
{
#endif
    // appName is used to create dump file, pass NULL to avoid it
ZTF_C_API bool ztf_initMemAlloc(const char* appName)
{
    return initMemAlloc(appName);
}

ZTF_C_API void ztf_exitMemAlloc(void)
{
    exitMemAlloc();
}

#ifdef ZTF_ENABLE_MEMORY_TRACKING
ZTF_C_API MemoryStatistics ztf_memGetStatistics(void)
{
    return memGetStatistics();
}
#endif

ZTF_C_API void* ztf_malloc_internal(size_t size, const char* f, int l, const char* sf)
{
    return tf_malloc_internal(size, f, l, sf);
}
ZTF_C_API void* ztf_memalign_internal(size_t align, size_t size, const char* f, int l, const char* sf)
{
    return tf_memalign_internal(align, size, f, l, sf);
}
ZTF_C_API void* ztf_calloc_internal(size_t count, size_t size, const char* f, int l, const char* sf)
{
    return tf_calloc_internal(count, size, f, l, sf);
}
ZTF_C_API void* ztf_calloc_memalign_internal(size_t count, size_t align, size_t size, const char* f, int l, const char* sf)
{
    return tf_calloc_memalign_internal(count, align, size, f, l, sf);
}
ZTF_C_API void* ztf_realloc_internal(void* ptr, size_t size, const char* f, int l, const char* sf)
{
    return tf_realloc_internal(ptr, size, f, l, sf);
}
ZTF_C_API void  ztf_free_internal(void* ptr, const char* f, int l, const char* sf)
{
    return tf_free_internal(ptr, f, l, sf);
}

#ifdef __cplusplus
} // extern "C"
#endif