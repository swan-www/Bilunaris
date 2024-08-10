#pragma once

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>

#include "ztf_bind_common.h"

#include "Config_c.h"
#include "IFileSystem_c.h"

#ifndef FILENAME_NAME_LENGTH_LOG
#define FILENAME_NAME_LENGTH_LOG 23
#endif

#ifndef INDENTATION_SIZE_LOG
#define INDENTATION_SIZE_LOG 4
#endif

#ifndef LEVELS_LOG
#define LEVELS_LOG 6
#endif

#define CONCAT_STR_LOG_IMPL(a, b) a##b
#define CONCAT_STR_LOG(a, b)      CONCAT_STR_LOG_IMPL(a, b)

#ifndef ANONIMOUS_VARIABLE_LOG
#define ANONIMOUS_VARIABLE_LOG(str) CONCAT_STR_LOG(str, __LINE__)
#endif

#ifdef __cplusplus
extern "C"
{
#endif

// If you add more levels don't forget to change LOG_LEVELS macro to the actual number of levels
typedef enum ztf_LogLevel
{
    ztf_eNONE = 0,
    ztf_eRAW = 1,
    ztf_eDEBUG = 2,
    ztf_eINFO = 4,
    ztf_eWARNING = 8,
    ztf_eERROR = 16,
    ztf_eALL = ~0
} ztf_LogLevel;

typedef void (*ztf_LogCallbackFn)(void* user_data, const char* message);
typedef void (*ztf_LogCloseFn)(void* user_data);
typedef void (*ztf_LogFlushFn)(void* user_data);

// Initialization/Exit functions are thread unsafe
// appName   used to create appName.log. Pass NULL to disable
// level     mask of LogLevel bits. Log is ignored if its level is missing in mask. Use eALL to enable full log
ZTF_C_API void ztf_initLog(const char* appName, ztf_LogLevel level);
ZTF_C_API void ztf_exitLog(void);

ZTF_C_API void ztf_addLogFile(const char* filename, ztf_FileMode file_mode, ztf_LogLevel log_level);
ZTF_C_API void ztf_addLogCallback(const char* id, uint32_t log_level, void* user_data, ztf_LogCallbackFn callback, ztf_LogCloseFn close,
                                ztf_LogFlushFn flush);

ZTF_C_API void ztf_writeLogVaList(uint32_t level, const char* filename, int line_number, const char* message, va_list args);
//+V576, function:writeLog, format_arg:4, ellipsis_arg:5
ZTF_C_API void ztf_writeLog(uint32_t level, const char* filename, int line_number, const char* message, ...);
//+V576, function:writeRawLog, format_arg:3, ellipsis_arg:4
ZTF_C_API void ztf_writeRawLog(uint32_t level, bool error, const char* message, ...);

//+V576, function:_FailedAssert, format_arg:4, ellipsis_arg:5
ZTF_C_API void ztf_FailedAssert(const char* file, int line, const char* statement, const char* msg, ...);

// Usage:
// puts(humanReadableTime(ns).str);
// printf("%s\n", humanReadableTime(ms * 1000).str);
// humanReadableSize(9238412498).str;
struct ztf_HumanReadableValue
{
    char str[16];
};
ZTF_C_API struct ztf_HumanReadableValue ztf_humanReadableSSize(ssize_t size);
ZTF_C_API struct ztf_HumanReadableValue ztf_humanReadableTimeD(double nanoseconds);

static inline struct ztf_HumanReadableValue ztf_humanReadableSize(size_t size) {
    return ztf_humanReadableSSize((ssize_t)size);
}
static inline struct ztf_HumanReadableValue ztf_humanReadableTime(int64_t nanoseconds) {
    return ztf_humanReadableTimeD((double)nanoseconds);
}

ZTF_C_API void ztf_EnableInteractiveMode(bool isInteractivenMode);
ZTF_C_API bool ztf_IsInteractiveMode(void);

ZTF_C_API void ztf_FailedAssertImpl(const char* file, int line, const char* statement, const char* message);
//+V576, function:_OutputDebugString, format_arg:1, ellipsis_arg:2
ZTF_C_API void ztf_OutputDebugString(const char* str, ...);
ZTF_C_API void ztf_OutputDebugStringV(const char* str, va_list args);

ZTF_C_API void ztf_PrintUnicode(const char* str, bool error);

#ifdef __cplusplus
} // extern "C"
#endif