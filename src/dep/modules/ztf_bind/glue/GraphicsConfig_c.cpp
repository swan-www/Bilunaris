#include "GraphicsConfig_c.h"

#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/Graphics/GraphicsConfig.h"

#ifdef __cplusplus
extern "C"
{
#endif

// read gpu.cfg and store all its content in specific structures
ZTF_C_API void ztf_addGPUConfigurationRules(ztf_ExtendedSettings* pExtendedSettings)
{
	addGPUConfigurationRules((ExtendedSettings*)pExtendedSettings);
}

// free all specific gpu.cfg structures
ZTF_C_API void ztf_removeGPUConfigurationRules()
{
	removeGPUConfigurationRules();
}

// set default value, samplerAnisotropySupported, graphicsQueueSupported, primitiveID
ZTF_C_API void ztf_setDefaultGPUSettings(struct ztf_GPUSettings* pGpuSettings)
{
	setDefaultGPUSettings((struct GPUSettings*) pGpuSettings);
}

// selects best gpu depending on the gpu comparison rules stored in gpu.cfg
ZTF_C_API uint32_t ztf_util_select_best_gpu(struct ztf_GPUSettings* availableSettings, uint32_t gpuCount)
{
	return util_select_best_gpu((struct GPUSettings*) availableSettings, gpuCount);
}

// reads the gpu data and sets the preset level of all available gpu's
ZTF_C_API ztf_GPUPresetLevel ztf_getDefaultPresetLevel()
{
	return (ztf_GPUPresetLevel)getDefaultPresetLevel();
}
ZTF_C_API ztf_GPUPresetLevel ztf_getGPUPresetLevel(uint32_t vendorId, uint32_t modelId, const char* vendorName, const char* modelName)
{
	return (ztf_GPUPresetLevel)getGPUPresetLevel(vendorId, modelId, vendorName, modelName);
}

// apply the configuration rules stored in gpu.cfg to to a single GPUSettings
ZTF_C_API void ztf_applyGPUConfigurationRules(struct ztf_GPUSettings* pGpuSettings, struct ztf_GPUCapBits* pCapBits)
{
	applyGPUConfigurationRules((struct GPUSettings*) pGpuSettings, (struct ztf_GPUCapBits*) pCapBits);
}

// apply the user extended configuration rules stored in gpu.cfg to the ExtendedSetting structure
ZTF_C_API void ztf_setupExtendedSettings(ztf_ExtendedSettings* pExtendedSettings, const struct ztf_GPUSettings* pGpuSettings)
{
	setupExtendedSettings((ztf_ExtendedSettings*)pExtendedSettings, (const struct ztf_GPUSettings*)pGpuSettings)
}

// return if the the GPUSettings validate the current driver rejection rules
ZTF_C_API bool ztf_checkDriverRejectionSettings(const struct ztf_GPUSettings* pGpuSettings)
{
	return checkDriverRejectionSettings((const struct ztf_GPUSettings*) pGpuSettings);
}

// ------ utilities ------
ZTF_C_API const char*    ztf_presetLevelToString(ztf_GPUPresetLevel preset)
{
	return presetLevelToString((ztf_GPUPresetLevel)preset);
}
ZTF_C_API ztf_GPUPresetLevel ztf_stringToPresetLevel(const char* presetLevel)
{
	return (ztf_GPUPresetLevel)stringToPresetLevel(presetLevel)
}
ZTF_C_API bool           ztf_gpuVendorEquals(uint32_t vendorId, const char* vendorName)
{
	return gpuVendorEquals(vendorId, vendorName)
}
ZTF_C_API const char*    ztf_getGPUVendorName(uint32_t modelId)
{
	return getGPUVendorName(modelId);
}
ZTF_C_API uint32_t       ztf_getGPUVendorID(const char* vendorName)
{
	return getGPUVendorID(vendorName);
}

#ifdef __cplusplus
}
#endif