#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/Application/Interfaces/IUI.h"

#define ZTF_BLOCK_CONFIG_INCLUDE
#include "IUI_c.h"
#undef ZTF_BLOCK_CONFIG_INCLUDE

#ifdef __cplusplus
extern "C"
{
#endif

    ZTF_C_API void ztf_initUserInterface(ztf_UserInterfaceDesc* pDesc)
    {
        initUserInterface((UserInterfaceDesc*) pDesc);
    }
    ZTF_C_API void ztf_exitUserInterface()
    {
        exitUserInterface();
    }

    ZTF_C_API void ztf_loadUserInterface(const ztf_UserInterfaceLoadDesc* pDesc)
    {
        loadUserInterface((const UserInterfaceLoadDesc*) pDesc);
    }

    ZTF_C_API void ztf_unloadUserInterface(uint32_t unloadType)
    {
        unloadUserInterface(unloadType);
    }

    ZTF_C_API void ztf_cmdDrawUserInterface(ztf_Cmd* pCmd, ztf_UserInterfaceDrawData* pUIDrawData)
    {
        cmdDrawUserInterface((Cmd*) pCmd, (UserInterfaceDrawData*) pUIDrawData);
    }

    ZTF_C_API void ztf_uiSetCollapsingHeaderWidgetCollapsed(ztf_CollapsingHeaderWidget* pWidget, bool collapsed)
    {
        uiSetCollapsingHeaderWidgetCollapsed((CollapsingHeaderWidget*) pWidget, collapsed);
    }

    /// Create an independent set of widgets which can be dynamically added to a UI Component
    ZTF_C_API ztf_UIWidget* ztf_uiCreateDynamicWidgets(ztf_DynamicUIWidgets* pDynamicUI, const char* pLabel, const void* pWidget, ztf_WidgetType type)
    {
        return (ztf_UIWidget*)uiCreateDynamicWidgets((DynamicUIWidgets*) pDynamicUI, pLabel, pWidget, (WidgetType)type);
    }

    /// Free memory associated with a set of dynamic UI widgets
    ZTF_C_API void ztf_uiDestroyDynamicWidgets(ztf_DynamicUIWidgets* pDynamicUI)
    {
        uiDestroyDynamicWidgets((DynamicUIWidgets*) pDynamicUI);
    }

    /// Add an existing set of dynamic widgets to an existing UI Component
    ZTF_C_API void ztf_uiShowDynamicWidgets(const ztf_DynamicUIWidgets* pDynamicUI, ztf_UIComponent* pGui)
    {
        uiShowDynamicWidgets((const DynamicUIWidgets*) pDynamicUI, (UIComponent*) pGui);
    }

    /// Remove an existing set of dynamic widgets from an existing UI Component
    ZTF_C_API void ztf_uiHideDynamicWidgets(const ztf_DynamicUIWidgets* pDynamicUI, ztf_UIComponent* pGui)
    {
        uiHideDynamicWidgets((const DynamicUIWidgets*) pDynamicUI, (UIComponent*) pGui);
    }

    /****************************************************************************/
    // MARK: - UI Component Public Functions
    /****************************************************************************/

    /// Create a UI Component "window" to which Widgets can be added
    /// User is NOT responsible for freeing this memory at application exit
    ZTF_C_API void ztf_uiCreateComponent(const char* pTitle, const ztf_UIComponentDesc* pDesc, ztf_UIComponent** ppGuiComponent)
    {
        UIComponentDesc compDesc{};
        compDesc.mStartPosition = vec2{pDesc->mStartPosition.x, pDesc->mStartPosition.y};
        compDesc.mStartSize     = vec2{pDesc->mStartSize.x, pDesc->mStartSize.y};
        compDesc.mFontID        = pDesc->mFontID;
        compDesc.mFontSize      = pDesc->mFontSize;

        uiCreateComponent(pTitle, &compDesc, (UIComponent**)ppGuiComponent);
    }

    /// Free memory associated with a UI Component "window"
    /// Only necessary for replacement purposes. UI Component memory will be freed internally on exit
    ZTF_C_API void ztf_uiDestroyComponent(ztf_UIComponent* pGui)
    {
        uiDestroyComponent((UIComponent*) pGui);
    }

    /// Set whether or not a given UI Component is active and visible on the screen
    ZTF_C_API void ztf_uiSetComponentActive(ztf_UIComponent* pGuiComponent, bool active)
    {
        uiSetComponentActive((UIComponent*) pGuiComponent, active);
    }

    /// Create a Widget to be assigned to a given UI Component
    /// User is NOT responsible for freeing this memory at application exit
    ZTF_C_API ztf_UIWidget* ztf_uiCreateComponentWidget(ztf_UIComponent* pGui, const char* pLabel, const void* pWidget, ztf_WidgetType type, bool clone)
    {
        return (ztf_UIWidget*)uiCreateComponentWidget((UIComponent*) pGui, pLabel, pWidget, (WidgetType)type, clone);
    }

    /// Destroy and free memory associated with a Widget
    /// Only necessary for replacement purposes. UI Widget memory will be freed internally on exit
    ZTF_C_API void ztf_uiDestroyComponentWidget(ztf_UIComponent* pGui, ztf_UIWidget* pWidget)
    {
        uiDestroyComponentWidget((UIComponent*) pGui, (UIWidget*) pWidget);
    }

    /// Destroy and free memory associated with all Widgets in a given UI Component
    /// Only necessary for replacement purposes. UI Widget memory will be freed internally on exit
    ZTF_C_API void ztf_uiDestroyAllComponentWidgets(ztf_UIComponent* pGui)
    {
        uiDestroyAllComponentWidgets((UIComponent*) pGui);
    }

    /****************************************************************************/
    // MARK: - Safe UI Component and Widget Setter Functions
    /****************************************************************************/

    // NOTE: These functions exist to protect scope against null-pointer derefs
    // on UI Component and Widget handles if this functionality still exists in
    // app code while the UI Master Switch is disabled.

    /// Assign "GuiComponentFlags" enum values to a given UI Component
    ZTF_C_API void ztf_uiSetComponentFlags(ztf_UIComponent* pGui, int32_t flags)
    {
        uiSetComponentFlags((UIComponent*) pGui, flags);
    }

    /// Set whether or not a given Widget is intended to be "deferrred"
    ZTF_C_API void ztf_uiSetWidgetDeferred(ztf_UIWidget* pWidget, bool deferred)
    {
        uiSetWidgetDeferred((UIWidget*) pWidget, deferred);
    }

    /// Assign Widget callback function (pointer to a function which takes and returns void)
    /// Will be called when Widget is hovered, usable, and not blocked by anything
    ZTF_C_API void ztf_uiSetWidgetOnHoverCallback(ztf_UIWidget* pWidget, void* pUserData, ztf_WidgetCallback callback)
    {
        uiSetWidgetOnHoverCallback((UIWidget*) pWidget, pUserData, (WidgetCallback) callback);
    }

    /// Assign Widget callback function (pointer to a function which takes and returns void)
    /// Will be called when Widget is currently active (ex. button being held)
    ZTF_C_API void ztf_uiSetWidgetOnActiveCallback(ztf_UIWidget* pWidget, void* pUserData, ztf_WidgetCallback callback)
    {
        uiSetWidgetOnActiveCallback((UIWidget*)pWidget, pUserData, (WidgetCallback)callback);
    }

    /// Assign Widget callback function (pointer to a function which takes and returns void)
    /// Will be called when Widget is currently focused (for keyboard/gamepad nav)
    ZTF_C_API void ztf_uiSetWidgetOnFocusCallback(ztf_UIWidget* pWidget, void* pUserData, ztf_WidgetCallback callback)
    {
        uiSetWidgetOnFocusCallback((UIWidget*) pWidget, pUserData, (WidgetCallback) callback);
    }

    /// Assign Widget callback function (pointer to a function which takes and returns void)
    /// Will be called when Widget just changed its underlying value or was pressed
    ZTF_C_API void ztf_uiSetWidgetOnEditedCallback(ztf_UIWidget* pWidget, void* pUserData, ztf_WidgetCallback callback)
    {
        uiSetWidgetOnEditedCallback((UIWidget*) pWidget, pUserData, (WidgetCallback) callback);
    }

    /// Assign Widget callback function (pointer to a function which takes and returns void)
    /// Will be called when Widget is made inactive from an active state
    ZTF_C_API void ztf_uiSetWidgetOnDeactivatedCallback(ztf_UIWidget* pWidget, void* pUserData, ztf_WidgetCallback callback)
    {
        uiSetWidgetOnDeactivatedCallback((UIWidget*) pWidget, pUserData, (WidgetCallback) callback);
    }

    /// Assign Widget callback function (pointer to a function which takes and returns void)
    /// Will be called when Widget is made inactive from an active state and its underlying value has changed
    ZTF_C_API void ztf_uiSetWidgetOnDeactivatedAfterEditCallback(ztf_UIWidget* pWidget, void* pUserData, ztf_WidgetCallback callback)
    {
        uiSetWidgetOnDeactivatedAfterEditCallback((UIWidget*) pWidget, pUserData, (WidgetCallback) callback);
    }

    /// Set whether or not a given UI Widget should be on the sameline than the previous one
    ZTF_C_API void ztf_uiSetSameLine(ztf_UIWidget* pGuiComponent, bool sameLine)
    {
        uiSetSameLine((UIWidget*) pGuiComponent, sameLine);
    }

    /****************************************************************************/
    // MARK: - Other User Interface Functionality
    /****************************************************************************/

    /// Returns whether or not the UI is currently "focused" by the cursor
    ZTF_C_API bool ztf_uiIsFocused()
    {
        return uiIsFocused();
    }

    /// Callback function to share any type of input data w/ ImGUI.
    ZTF_C_API void ztf_uiOnInput(uint32_t actionId, bool buttonPress, const ztf_Float2* pMousePos, const ztf_Float2* pStick)
    {
        uiOnInput(actionId, buttonPress, (const float2*) pMousePos, (const float2*) pStick);
    }

    /// Callback function to share text entry data w/ ImGUI
    ZTF_C_API void ztf_uiOnText(const wchar_t* pText)
    {
        uiOnText(pText);
    }

    /// Returns value associated with UI preparedness to accept text entry data
    /// 0 -> Not pressed, 1 -> Digits Only keyboard, 2 -> Full Keyboard (Chars + Digits)
    ZTF_C_API uint8_t ztf_uiWantTextInput()
    {
        return uiWantTextInput();
    }

    /// Toggle UI rendering, input processing still works (used to hide UI components while taking screenshots)
    ZTF_C_API void ztf_uiToggleRendering(bool enabled)
    {
        uiToggleRendering(enabled);
    }

    /// Returns whether or not UI rendering is currently enabled (see uiToggleRendering)
    ZTF_C_API bool ztf_uiIsRenderingEnabled()
    {
        return uiIsRenderingEnabled();
    }

    /// Creates a UserInterfaceDrawData* which can be passed to cmdDrawUserInterface(Cmd* pCmd, UserInterfaceDrawData* pUIDrawData) explicitly.
    /// It's the caller's responsibility to call removeUIDrawData(...) when done.
    ZTF_C_API ztf_UserInterfaceDrawData* ztf_addUIDrawData()
    {
        return (ztf_UserInterfaceDrawData*)ztf_addUIDrawData();
    }

    /// Populates a UserInterfaceDrawData* with current frame draw data so that it can be passed to cmdDrawUserInterface(Cmd* pCmd,
    /// UserInterfaceDrawData* pUIDrawData) at a later time.
    ZTF_C_API void ztf_uiPopulateDrawData(ztf_UserInterfaceDrawData* pUIDrawData)
    {
        uiPopulateDrawData((UserInterfaceDrawData*) pUIDrawData);
    }

    /// Removes a UserInterfaceDrawData*.  It should not be reused after this point.
    ZTF_C_API void ztf_removeUIDrawData(ztf_UserInterfaceDrawData* pUIDrawData)
    {
        removeUIDrawData((UserInterfaceDrawData*) pUIDrawData);
    }

#ifdef __cplusplus
}
#endif