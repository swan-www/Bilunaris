// auto generated by c2z
// #include <new>

#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/Utilities/Log/Log.h"

extern "C" void _1_initLog_(const char* appName, LogLevel level) { ::initLog(appName, level); }
extern "C" void _1_exitLog_() { ::exitLog(); }
extern "C" void _1_addLogFile_(const char* filename, FileMode file_mode, LogLevel log_level)
{
    ::addLogFile(filename, file_mode, log_level);
}
extern "C" void _1_addLogCallback_(const char* id, uint32_t log_level, void* user_data, LogCallbackFn callback, LogCloseFn close,
                                   LogFlushFn flush)
{
    ::addLogCallback(id, log_level, user_data, callback, close, flush);
}
extern "C" void _1_writeLogVaList_(uint32_t level, const char* filename, int line_number, const char* message, va_list args)
{
    ::writeLogVaList(level, filename, line_number, message, args);
}
extern "C" struct HumanReadableValue _1_humanReadableSSize_(ssize_t size) { return ::humanReadableSSize(size); }
extern "C" struct HumanReadableValue _1_humanReadableTimeD_(double nanoseconds) { return ::humanReadableTimeD(nanoseconds); }
