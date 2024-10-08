#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/Utilities/Interfaces/ILog.h"
#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/Utilities/Log/Log.h"
#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/Utilities/Interfaces/IThread.h"

#define ZTF_BLOCK_CONFIG_INCLUDE
#include "ILog_c.h"
#undef ZTF_BLOCK_CONFIG_INCLUDE

#include <stdarg.h>

#ifdef __cplusplus
extern "C"
{
#endif


ZTF_C_API void ztf_initLog(const char* appName, ztf_LogLevel level)
{
    initLog(appName, (LogLevel)level);
}

ZTF_C_API void ztf_exitLog(void)
{
    exitLog();
}

ZTF_C_API void ztf_addLogFile(const char* filename, ztf_FileMode file_mode, ztf_LogLevel log_level)
{
    addLogFile(filename, (FileMode)file_mode, (LogLevel)log_level);
}

ZTF_C_API void ztf_addLogCallback(const char* id, uint32_t log_level, void* user_data, ztf_LogCallbackFn callback, ztf_LogCloseFn close,
                                ztf_LogFlushFn flush)
{
    addLogCallback(id, log_level, user_data, (LogCallbackFn)callback, (LogCloseFn)close, (LogFlushFn)flush);
}


ZTF_C_API void ztf_writeLogVaList(uint32_t level, const char* filename, int line_number, const char* message, va_list args)
{
    writeLogVaList(level, filename, line_number, message, args);
}

//+V576, function:writeLog, format_arg:4, ellipsis_arg:5
ZTF_C_API void ztf_writeLog(uint32_t level, const char* filename, int line_number, const char* message, ...)
{
    va_list args;
    va_start(args, message);
    writeLogVaList(level, filename, line_number, message, args);
    va_end(args);
}

//+V576, function:writeRawLog, format_arg:3, ellipsis_arg:4
ZTF_C_API void ztf_writeRawLog(uint32_t level, bool error, const char* message, ...)
{
    va_list args;
    va_start(args, message);
    writeRawLogVaList(level, error, message, args);
    va_end(args);
}

//+V576, function:_FailedAssert, format_arg:4, ellipsis_arg:5
ZTF_C_API void ztf_FailedAssert(const char* file, int line, const char* statement, const char* msg, ...)
{
    va_list args;
    va_start(args, msg);
    _FailedAssertVaList(file, line, statement, msg, args);
    va_end(args);
}

ZTF_C_API struct ztf_HumanReadableValue ztf_humanReadableSSize(ssize_t size)
{
    HumanReadableValue val = humanReadableSSize(size);
    ztf_HumanReadableValue copiedVal = *(ztf_HumanReadableValue*)&val;
    return copiedVal;
}

ZTF_C_API struct ztf_HumanReadableValue ztf_humanReadableTimeD(double nanoseconds)
{
    HumanReadableValue val = humanReadableTimeD(nanoseconds);
    ztf_HumanReadableValue copiedVal = *(ztf_HumanReadableValue*)&val;
    return copiedVal;
}

ZTF_C_API void ztf_EnableInteractiveMode(bool isInteractivenMode)
{
    _EnableInteractiveMode(isInteractivenMode);
}

ZTF_C_API bool ztf_IsInteractiveMode(void)
{
    return _IsInteractiveMode();
}


ZTF_C_API void ztf_FailedAssertImpl(const char* file, int line, const char* statement, const char* message)
{
    _FailedAssertImpl(file, line, statement, message);
}

//+V576, function:_OutputDebugString, format_arg:1, ellipsis_arg:2
ZTF_C_API void ztf_OutputDebugString(const char* str, ...)
{
    va_list arglist;
    va_start(arglist, str);
    ztf_OutputDebugStringV(str, arglist);
    va_end(arglist);
}

ZTF_C_API void ztf_OutputDebugStringV(const char* str, va_list args)
{
    _OutputDebugStringV(str, args);
}


ZTF_C_API void ztf_PrintUnicode(const char* str, bool error)
{
    _PrintUnicode(str, error);
}

#ifdef __cplusplus
} // extern "C"
#endif