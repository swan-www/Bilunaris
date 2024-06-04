#include "IApp_c.h"

#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/OS/Interfaces/IOperatingSystem.h"
#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/Application/Interfaces/IApp.h"

#ifdef __cplusplus
extern "C"
{
#endif

//IApp access
ZTF_C_API ztf_AppSettings* ztf_getAppSettings(ztf_App* pApp)
{
	return (ztf_AppSettings*)&pApp->mSettings;
}
ZTF_C_API ztf_WindowDesc* ztf_getWindowDesc(ztf_App* pApp)
{
	return (ztf_WindowDesc*)pApp->pWindow;
}
ZTF_C_API const char* ztf_getCommandLine(ztf_App* pApp)
{
	return pApp->pCommandLine;
}
ZTF_C_API int ztf_getArgC(ztf_App* pApp)
{
	return pApp->argc;
}
ZTF_C_API const char** ztf_getArgV(ztf_App* pApp)
{
	return pApp->argv;
}

#ifdef __cplusplus
}
#endif