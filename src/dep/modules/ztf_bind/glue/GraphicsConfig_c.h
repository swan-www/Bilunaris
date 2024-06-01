#pragma once

#include <stdint.h>
#include <stdlib.h> 

#include "ztf_bind_common.h"

#ifdef __cplusplus
extern "C"
{
#endif

#ifndef ZTF_BLOCK_GRAPHICS_CONFIG_INCLUDE

#define FORGE_RENDERER_CONFIG_H

#pragma warning(push, 0)

#define D3D11_NO_HELPERS

#if defined(_WINDOWS)
#ifndef _WINDOWS7
#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/Graphics/Direct3D12/Direct3D12Config.h"
#endif
#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/Graphics/Vulkan/VulkanConfig.h"
#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/Graphics/Direct3D11/Direct3D11Config.h"
#elif defined(XBOX)
#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/Graphics/Direct3D12/Direct3D12Config.h"
#elif defined(__APPLE__)
#define METAL
#elif defined(__ANDROID__)
#ifndef QUEST_VR
#define GLES
#endif
#ifdef ARCH_ARM64
#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/Graphics/Vulkan/VulkanConfig.h"
#endif
#elif defined(NX64)
#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/Graphics/Vulkan/VulkanConfig.h"
#elif defined(__linux__)
#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/Graphics/Vulkan/VulkanConfig.h"
#endif

#pragma warning(pop)

#undef FORGE_RENDERER_CONFIG_H

#if (defined(DIRECT3D12) + defined(DIRECT3D11) + defined(VULKAN) + defined(GLES) + defined(METAL) + defined(ORBIS) + defined(PROSPERO) + \
     defined(NX64)) == 0
#error "No rendering API defined"
#elif (defined(DIRECT3D12) + defined(DIRECT3D11) + defined(VULKAN) + defined(GLES) + defined(METAL) + defined(ORBIS) + defined(PROSPERO) + \
       defined(NX64)) > 1
#define ZTF_USE_MULTIPLE_RENDER_APIS
#endif

#endif //ZTF_BLOCK_GRAPHICS_CONFIG_INCLUDE

// ------------------------------- gpu configuration rules ------------------------------- //

typedef struct ztf_GPUSettings ztf_GPUSettings;
typedef struct ztf_GPUCapBits ztf_GPUCapBits;

typedef struct ztf_ExtendedSettings
{
    uint32_t     mNumSettings;
    uint32_t*    pSettings;
    const char** ppSettingNames;
} ztf_ExtendedSettings;

typedef enum ztf_GPUPresetLevel
{
    ZTF_GPU_PRESET_NONE = 0,
    ZTF_GPU_PRESET_OFFICE,  // This means unsupported
    ZTF_GPU_PRESET_VERYLOW, // Mostly for mobile GPU
    ZTF_GPU_PRESET_LOW,
    ZTF_GPU_PRESET_MEDIUM,
    ZTF_GPU_PRESET_HIGH,
    ZTF_GPU_PRESET_ULTRA,
    ZTF_GPU_PRESET_COUNT
} ztf_GPUPresetLevel;

// read gpu.cfg and store all its content in specific structures
ZTF_C_API void ztf_addGPUConfigurationRules(ztf_ExtendedSettings* pExtendedSettings);

// free all specific gpu.cfg structures
ZTF_C_API void ztf_removeGPUConfigurationRules();

// set default value, samplerAnisotropySupported, graphicsQueueSupported, primitiveID
ZTF_C_API void ztf_setDefaultGPUSettings(struct ztf_GPUSettings* pGpuSettings);

// selects best gpu depending on the gpu comparison rules stored in gpu.cfg
ZTF_C_API uint32_t ztf_util_select_best_gpu(struct ztf_GPUSettings* availableSettings, uint32_t gpuCount);

// reads the gpu data and sets the preset level of all available gpu's
ZTF_C_API ztf_GPUPresetLevel ztf_getDefaultPresetLevel();
ZTF_C_API ztf_GPUPresetLevel ztf_getGPUPresetLevel(uint32_t vendorId, uint32_t modelId, const char* vendorName, const char* modelName);

// apply the configuration rules stored in gpu.cfg to to a single GPUSettings
ZTF_C_API void ztf_applyGPUConfigurationRules(struct ztf_GPUSettings* pGpuSettings, struct ztf_GPUCapBits* pCapBits);

// apply the user extended configuration rules stored in gpu.cfg to the ExtendedSetting structure
ZTF_C_API void ztf_setupExtendedSettings(ztf_ExtendedSettings* pExtendedSettings, const struct ztf_GPUSettings* pGpuSettings);

// return if the the GPUSettings validate the current driver rejection rules
ZTF_C_API bool ztf_checkDriverRejectionSettings(const struct ztf_GPUSettings* pGpuSettings);

// ------ utilities ------
ZTF_C_API const char*    ztf_presetLevelToString(ztf_GPUPresetLevel preset);
ZTF_C_API ztf_GPUPresetLevel ztf_stringToPresetLevel(const char* presetLevel);
ZTF_C_API bool           ztf_gpuVendorEquals(uint32_t vendorId, const char* vendorName);
ZTF_C_API const char*    ztf_getGPUVendorName(uint32_t modelId);
ZTF_C_API uint32_t       ztf_getGPUVendorID(const char* vendorName);

#ifdef __cplusplus
}
#endif