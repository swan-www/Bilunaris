#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/Application/Interfaces/IInput.h"
#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/OS/Interfaces/IOperatingSystem.h"
#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/Utilities/Math/MathTypes.h"

#include "IInput_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

ZTF_C_API bool ztf_initInputSystem(ztf_InputSystemDesc* pDesc)
{
    return initInputSystem((InputSystemDesc*) pDesc);
}

ZTF_C_API void ztf_exitInputSystem()
{
    exitInputSystem();
}
ZTF_C_API void ztf_updateInputSystem(float deltaTime, uint32_t width, uint32_t height)
{
    updateInputSystem(deltaTime, width, height);
}

// Input action (callbacks) functionalities //////////////////
/* Adds a new action (callback) for a specific (or all) device target(s)
 * If INPUT_ACTION_MAPPING_TARGET_ALL is specified, an action will be mapped for all device targets
 * that have the action ID specified in pDesc.
 */
ZTF_C_API void ztf_addInputAction(const ztf_InputActionDesc* pDesc, const ztf_InputActionMappingDeviceTarget actionMappingTarget)
{
    addInputAction((const InputActionDesc*) pDesc, (const InputActionMappingDeviceTarget)actionMappingTarget);
}
ZTF_C_API void ztf_removeInputAction(const ztf_InputActionDesc* pDesc, const ztf_InputActionMappingDeviceTarget actionMappingTarget)
{
    removeInputAction((const InputActionDesc*) pDesc, (const InputActionMappingDeviceTarget) actionMappingTarget);
}
ZTF_C_API void ztf_setGlobalInputAction(const ztf_GlobalInputActionDesc* pDesc)
{
    setGlobalInputAction((const GlobalInputActionDesc*) pDesc);
}
//////////////////////////////////////////////////////////////

// Input action mappings functionalities /////////////////////
/* Adds new action mappings for a specific (or all) device target(s)
 * Takes in an array of ActionMappingDesc
 * Note: this will clear all current action mappings, including any callbacks.
 */
ZTF_C_API void ztf_addActionMappings(ztf_ActionMappingDesc* const actionMappings, const uint32_t numActions, const ztf_InputActionMappingDeviceTarget actionMappingTarget)
{
    addActionMappings((ActionMappingDesc* const) actionMappings, numActions, (const InputActionMappingDeviceTarget) actionMappingTarget);
}

/* Removes currently active action mappings
 * Note: this will clear any callbacks that were added for any action mapping being cleared.
 */
ZTF_C_API void ztf_removeActionMappings(const ztf_InputActionMappingDeviceTarget actionMappingTarget)
{
    removeActionMappings((const InputActionMappingDeviceTarget) actionMappingTarget);
}

/* Adds default TF action mappings
 * Note: this will clear all current action mappings, including any callbacks.
 */
ZTF_C_API void ztf_addDefaultActionMappings()
{
    addDefaultActionMappings();
}
//////////////////////////////////////////////////////////////

ZTF_C_API bool ztf_setEnableCaptureInput(bool enable)
{
    return setEnableCaptureInput(enable);
}

/// Used to enable/disable text input for non-keyboard setups (virtual keyboards for console/mobile, ...)
ZTF_C_API void ztf_setVirtualKeyboard(uint32_t type)
{
    setVirtualKeyboard(type);
}

ZTF_C_API void ztf_setDeadZone(unsigned int controllerIndex, float deadZoneSize)
{
    setDeadZone(controllerIndex, deadZoneSize);
}
ZTF_C_API void ztf_setLEDColor(int gamePadIndex, uint8_t r, uint8_t g, uint8_t b)
{
    setLEDColor(gamePadIndex, r, g, b);
}

// if gamepad index == BUILTIN_DEVICE_HAPTICS it will try to set rumble on the actual device
// in the case of iOS and iphones that would mean the actual phone vibrates
ZTF_C_API bool ztf_setRumbleEffect(int gamePadIndex, float left_motor, float right_motor, uint32_t duration_ms)
{
    return setRumbleEffect(gamePadIndex, left_motor, right_motor, duration_ms);
}

ZTF_C_API const char* ztf_getGamePadName(int gamePadIndex)
{
    return getGamePadName(gamePadIndex);
}
ZTF_C_API bool        ztf_gamePadConnected(int gamePadIndex)
{
    return gamePadConnected(gamePadIndex);
}
ZTF_C_API void        ztf_setOnDeviceChangeCallBack(void (*onDeviceChnageCallBack)(const char* name, bool added, int gamePadIndex))
{
    setOnDeviceChangeCallBack(onDeviceChnageCallBack);
}

#ifdef __cplusplus
}
#endif