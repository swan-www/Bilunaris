#pragma once
#include <stdbool.h> 
#include <stdint.h>

#include "ztf_bind_common.h"

#include "Config_c.h"
#include "MathTypes_glue.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct ztf_UserInterfaceDrawData ztf_UserInterfaceDrawData;

typedef struct ztf_Renderer      ztf_Renderer;
typedef struct ztf_Cmd           ztf_Cmd;
typedef struct ztf_RenderTarget  ztf_RenderTarget;
typedef struct ztf_PipelineCache ztf_PipelineCache;

#define ZTF_MAX_LABEL_STR_LENGTH  128
#define ZTF_MAX_FORMAT_STR_LENGTH 30
#define ZTF_MAX_TITLE_STR_LENGTH  128

/****************************************************************************/
// MARK: - UI Widget Data Structures
/****************************************************************************/
typedef void (*ztf_WidgetCallback)(void* pUserData);
typedef void (*ztf_WindowCallback)(void* pUserData);

typedef struct ztf_bstring {
    int mlen;
    int slen;
    unsigned char* data;
}ztf_bstring;

typedef enum ztf_WidgetType
{
    ZTF_WIDGET_TYPE_COLLAPSING_HEADER,
    ZTF_WIDGET_TYPE_DEBUG_TEXTURES,
    ZTF_WIDGET_TYPE_LABEL,
    ZTF_WIDGET_TYPE_COLOR_LABEL,
    ZTF_WIDGET_TYPE_HORIZONTAL_SPACE,
    ZTF_WIDGET_TYPE_SEPARATOR,
    ZTF_WIDGET_TYPE_VERTICAL_SEPARATOR,
    ZTF_WIDGET_TYPE_BUTTON,
    ZTF_WIDGET_TYPE_SLIDER_FLOAT,
    ZTF_WIDGET_TYPE_SLIDER_FLOAT2,
    ZTF_WIDGET_TYPE_SLIDER_FLOAT3,
    ZTF_WIDGET_TYPE_SLIDER_FLOAT4,
    ZTF_WIDGET_TYPE_SLIDER_INT,
    ZTF_WIDGET_TYPE_SLIDER_UINT,
    ZTF_WIDGET_TYPE_RADIO_BUTTON,
    ZTF_WIDGET_TYPE_CHECKBOX,
    ZTF_WIDGET_TYPE_ONE_LINE_CHECKBOX,
    ZTF_WIDGET_TYPE_CURSOR_LOCATION,
    ZTF_WIDGET_TYPE_DROPDOWN,
    ZTF_WIDGET_TYPE_COLUMN,
    ZTF_WIDGET_TYPE_PROGRESS_BAR,
    ZTF_WIDGET_TYPE_COLOR_SLIDER,
    ZTF_WIDGET_TYPE_HISTOGRAM,
    ZTF_WIDGET_TYPE_PLOT_LINES,
    ZTF_WIDGET_TYPE_COLOR_PICKER,
    ZTF_WIDGET_TYPE_COLOR3_PICKER,
    ZTF_WIDGET_TYPE_TEXTBOX,
    ZTF_WIDGET_TYPE_DYNAMIC_TEXT,
    ZTF_WIDGET_TYPE_FILLED_RECT,
    ZTF_WIDGET_TYPE_DRAW_TEXT,
    ZTF_WIDGET_TYPE_DRAW_TOOLTIP,
    ZTF_WIDGET_TYPE_DRAW_LINE,
    ZTF_WIDGET_TYPE_DRAW_CURVE,
    ZTF_WIDGET_TYPE_CUSTOM
} ztf_WidgetType;

typedef struct ztf_UIWidget
{
    ztf_WidgetType mType = {};     // Type of the underlying widget
    void* pWidget = NULL; // Underlying widget

    void* pOnHoverUserData = NULL;
    ztf_WidgetCallback pOnHover = NULL; // Widget is hovered, usable, and not blocked by anything.
    void* pOnActiveUserData = NULL;
    ztf_WidgetCallback pOnActive = NULL; // Widget is currently active (ex. button being held)
    void* pOnFocusUserData = NULL;
    ztf_WidgetCallback pOnFocus = NULL; // Widget is currently focused (for keyboard/gamepad nav)
    void* pOnEditedUserData = NULL;
    ztf_WidgetCallback pOnEdited = NULL; // Widget just changed its underlying value or was pressed.
    void* pOnDeactivatedUserData = NULL;
    ztf_WidgetCallback pOnDeactivated = NULL; // Widget was just made inactive from an active state.  This is useful for undo/redo patterns.
    void* pOnDeactivatedAfterEditUserData = NULL;
    ztf_WidgetCallback pOnDeactivatedAfterEdit = NULL; // Widget was just made inactive from an active state and changed its underlying value.
                                                   // This is useful for undo/redo patterns.

    char mLabel[ZTF_MAX_LABEL_STR_LENGTH]{};

    // Set this to process deferred callbacks that may cause global program state changes.
    bool mDeferred = false;

    bool mHovered = false;
    bool mActive = false;
    bool mFocused = false;
    bool mEdited = false;
    bool mDeactivated = false;
    bool mDeactivatedAfterEdit = false;
    bool mSameLine = false;

    // Stores the screen space position of the widget
    ztf_Float2 mDisplayPosition;
} ztf_UIWidget;

typedef struct ztf_CollapsingHeaderWidget
{
    // array of UIWidget*
    ztf_UIWidget** pGroupedWidgets = NULL;
    uint32_t   mWidgetsCount = 0;
    bool       mCollapsed = false;
    bool       mPreviousCollapsed = false;
    bool       mDefaultOpen = false;
    bool       mHeaderIsVisible = true;
} ztf_CollapsingHeaderWidget;

typedef struct ztf_ColumnWidget
{
    // array of UIWidget*
    ztf_UIWidget** pPerColumnWidgets = NULL;
    uint32_t   mWidgetsCount = 0;
} ztf_ColumnWidget;

typedef struct ztf_Texture ztf_Texture;

typedef struct ztf_DebugTexturesWidget
{
    // C Array of const Texture*
    const struct ztf_Texture* const* pTextures = NULL;
    uint32_t                     mTexturesCount = 0;
    ztf_Float2                  mTextureDisplaySize = ztf_Float2{512.f, 512.f};

} ztf_DebugTexturesWidget;

typedef struct ztf_LabelWidget ztf_LabelWidget;

typedef struct ztf_ColorLabelWidget
{
    ztf_Float4 mColor = ztf_Float4{0.f, 0.f, 0.f, 0.f};
} ztf_ColorLabelWidget;

typedef struct ztf_HorizontalSpaceWidget ztf_HorizontalSpaceWidget;

typedef struct ztf_SeparatorWidget ztf_SeparatorWidget;

typedef struct ztf_VerticalSeparatorWidget
{
    uint32_t mLineCount = 0;
} ztf_VerticalSeparatorWidget;

typedef struct ztf_ButtonWidget ztf_ButtonWidget;

typedef struct ztf_SliderFloatWidget
{
    char   mFormat[ZTF_MAX_FORMAT_STR_LENGTH] = {"%.3f"};
    float* pData = NULL;
    float  mMin = 0.f;
    float  mMax = 0.f;
    float  mStep = 0.01f;
} ztf_SliderFloatWidget;

typedef struct Sztf_liderFloat2Widget
{
    char    mFormat[ZTF_MAX_FORMAT_STR_LENGTH] = {"%.3f"};
    ztf_Float2* pData = NULL;
    ztf_Float2  mMin = ztf_Float2{0.f, 0.f};
    ztf_Float2  mMax = ztf_Float2{0.f, 0.f};
    ztf_Float2  mStep = ztf_Float2{0.01f, 0.01f};
} ztf_SliderFloat2Widget;

typedef struct ztf_SliderFloat3Widget
{
    char    mFormat[ZTF_MAX_FORMAT_STR_LENGTH] = {"%.3f"};
    ztf_Float3* pData = NULL;
    ztf_Float3  mMin = ztf_Float3{0.f, 0.f, 0.f};
    ztf_Float3  mMax = ztf_Float3{0.f, 0.f, 0.f};
    ztf_Float3  mStep = ztf_Float3{0.01f, 0.01f, 0.01f};
} ztf_SliderFloat3Widget;

typedef struct ztf_SliderFloat4Widget
{
    char    mFormat[MAX_FORMAT_STR_LENGTH] = {"%.3f"};
    ztf_Float4* pData = NULL;
    ztf_Float4  mMin = ztf_Float4{0.f, 0.f, 0.f, 0.f};
    ztf_Float4  mMax = ztf_Float4{0.f, 0.f, 0.f, 0.f};
    ztf_Float4  mStep = ztf_Float4{0.01f, 0.01f, 0.01f, 0.01f};
} ztf_SliderFloat4Widget;

typedef struct ztf_SliderIntWidget
{
    char     mFormat[ZTF_MAX_FORMAT_STR_LENGTH] = {"%d"};
    int32_t* pData = NULL;
    int32_t  mMin = 0;
    int32_t  mMax = 0;
    int32_t  mStep = 1;
} ztf_SliderIntWidget;

typedef struct ztf_SliderUintWidget
{
    char      mFormat[ZTF_MAX_FORMAT_STR_LENGTH] = {"%u"};
    uint32_t* pData = NULL;
    uint32_t  mMin = 0;
    uint32_t  mMax = 0;
    uint32_t  mStep = 1;
} ztf_SliderUintWidget;

typedef struct ztf_RadioButtonWidget
{
    int32_t* pData = NULL;
    int32_t  mRadioId = 0;
} ztf_RadioButtonWidget;

typedef struct ztf_CheckboxWidget
{
    bool* pData = NULL;
} ztf_CheckboxWidget;

typedef struct ztf_OneLineCheckboxWidget
{
    bool* pData = NULL;
    ztf_Float4 mColor = ztf_Float4{0.f, 0.f, 0.f, 0.f};
} ztf_OneLineCheckboxWidget;

typedef struct ztf_CursorLocationWidget
{
    ztf_Float2 mLocation = ztf_Float2{0.f, 0.f};
} ztf_CursorLocationWidget;

typedef struct ztf_DropdownWidget
{
    uint32_t* pData = NULL;
    // pNames is a C array of size mCount
    const char* const* pNames = NULL;
    uint32_t           mCount = 0;
} ztf_DropdownWidget;

typedef struct ztf_ProgressBarWidget
{
    size_t* pData = NULL;
    size_t  mMaxProgress = 0;
} ztf_ProgressBarWidget;

typedef struct ztf_ColorSliderWidget
{
    ztf_Float4* pData = NULL;
} ztf_ColorSliderWidget;

typedef struct ztf_HistogramWidget
{
    float* pValues = NULL;
    uint32_t    mCount = 0;
    float* mMinScale = NULL;
    float* mMaxScale = NULL;
    ztf_Float2  mHistogramSize = ztf_Float2{0.f, 0.f};
    const char* mHistogramTitle = NULL;
} ztf_HistogramWidget;

typedef struct ztf_PlotLinesWidget
{
    float* mValues = NULL;
    uint32_t    mNumValues = 0;
    float* mScaleMin = NULL;
    float* mScaleMax = NULL;
    ztf_Float2* mPlotScale = NULL;
    const char* mTitle = NULL;
} ztf_PlotLinesWidget;

typedef struct ztf_ColorPickerWidget
{
    ztf_Float4* pData = NULL;
} ztf_ColorPickerWidget;

typedef struct ztf_Color3PickerWidget
{
    ztf_Float3* pData = NULL;
} ztf_Color3PickerWidget;

typedef enum ztf_UITextFlags
{
    ZTF_UI_TEXT_ENABLE_RESIZE = 0x1,
    ZTF_UI_TEXT_AUTOSELECT_ALL = 0x2
} ztf_TextFlags;

typedef void (*ztf_TextboxCallback)(bool* keysDown);

typedef struct ztf_TextboxWidget
{
    ztf_bstring* pText = NULL;
    unsigned char   mFlags = ZTF_UI_TEXT_AUTOSELECT_ALL;
    ztf_TextboxCallback pCallback = NULL;
} ztf_TextboxWidget;

typedef struct ztf_DynamicTextWidget
{
    ztf_bstring* pText = NULL;
    ztf_Float4* pColor = NULL;
    unsigned char mFlags = 0;
} ztf_DynamicTextWidget;

typedef struct ztf_FilledRectWidget
{
    ztf_Float2 mPos = ztf_Float2{0.f, 0.f};
    ztf_Float2 mScale = ztf_Float2{0.f, 0.f};
    ztf_Float4 mColor = ztf_Float4{0.f, 0.f, 0.f, 0.f};
} ztf_FilledRectWidget;

typedef struct ztf_DrawTextWidget
{
    ztf_Float2 mPos = ztf_Float2{0.f, 0.f};
    ztf_Float4 mColor = ztf_Float4{0.f, 0.f, 0.f, 0.f};
} ztf_DrawTextWidget;

typedef struct ztf_DrawTooltipWidget
{
    bool* mShowTooltip = NULL;
    char* mText = NULL;
} ztf_DrawTooltipWidget;

typedef struct ztf_DrawLineWidget
{
    ztf_Float2 mPos1 = ztf_Float2{0.f, 0.f};
    ztf_Float2 mPos2 = ztf_Float2{0.f, 0.f};
    ztf_Float4 mColor = ztf_Float4{0.f, 0.f, 0.f, 0.f};
    bool   mAddItem = false;
} ztf_DrawLineWidget;

typedef struct ztf_DrawCurveWidget
{
    ztf_Float2* mPos = NULL;
    uint32_t mNumPoints = 0;
    float    mThickness = 0.f;
    ztf_Float4   mColor = ztf_Float4{0.f, 0.f, 0.f, 0.f};
} ztf_DrawCurveWidget;

typedef struct ztf_CustomWidget
{
    void* pUserData;
    ztf_WidgetCallback pCallback;
    ztf_WidgetCallback pDestroyCallback;
} ztf_CustomWidget;

/****************************************************************************/
// MARK: - UI Component Data Structures
/****************************************************************************/

typedef enum ztf_GuiComponentFlags
{
    ZTF_GUI_COMPONENT_FLAGS_NONE = 0,
    ZTF_GUI_COMPONENT_FLAGS_NO_TITLE_BAR = 1 << 0,          // Disable title-bar
    ZTF_GUI_COMPONENT_FLAGS_NO_RESIZE = 1 << 1,             // Disable user resizing
    ZTF_GUI_COMPONENT_FLAGS_NO_MOVE = 1 << 2,               // Disable user moving the window
    ZTF_GUI_COMPONENT_FLAGS_NO_SCROLLBAR = 1 << 3,          // Disable scrollbars (window can still scroll with mouse or programatically)
    ZTF_GUI_COMPONENT_FLAGS_NO_COLLAPSE = 1 << 4,           // Disable user collapsing window by double-clicking on it
    ZTF_GUI_COMPONENT_FLAGS_ALWAYS_AUTO_RESIZE = 1 << 5,    // Resize every window to its content every frame
    ZTF_GUI_COMPONENT_FLAGS_NO_INPUTS = 1 << 6,             // Disable catching mouse or keyboard inputs, hovering test with pass through.
    ZTF_GUI_COMPONENT_FLAGS_MEMU_BAR = 1 << 7,              // Has a menu-bar
    ZTF_GUI_COMPONENT_FLAGS_HORIZONTAL_SCROLLBAR = 1 << 8,  // Allow horizontal scrollbar to appear (off by default).
    ZTF_GUI_COMPONENT_FLAGS_NO_FOCUS_ON_APPEARING = 1 << 9, // Disable taking focus when transitioning from hidden to visible state
    ZTF_GUI_COMPONENT_FLAGS_NO_BRING_TO_FRONT_ON_FOCUS =
    1 << 10, // Disable bringing window to front when taking focus (e.g. clicking on it or programatically giving it focus)
    ZTF_GUI_COMPONENT_FLAGS_ALWAYS_VERTICAL_SCROLLBAR = 1 << 11,   // Always show vertical scrollbar (even if ContentSize.y < Size.y)
    ZTF_GUI_COMPONENT_FLAGS_ALWAYS_HORIZONTAL_SCROLLBAR = 1 << 12, // Always show horizontal scrollbar (even if ContentSize.x < Size.x)
    ZTF_GUI_COMPONENT_FLAGS_ALWAYS_USE_WINDOW_PADDING = 1 << 13,   // Ensure child windows without border uses style.WindowPadding (ignored by
                                                               // default for non-bordered child windows, because more convenient)
    ZTF_GUI_COMPONENT_FLAGS_NO_NAV_INPUT = 1 << 14,                // No gamepad/keyboard navigation within the window
    ZTF_GUI_COMPONENT_FLAGS_NO_NAV_FOCUS =
    1 << 15, // No focusing toward this window with gamepad/keyboard navigation (e.g. skipped by CTRL+TAB)
    ZTF_GUI_COMPONENT_FLAGS_START_COLLAPSED = 1 << 16,
    ZTF_GUI_COMPONENT_FLAGS_NO_DOCKING = 1 << 17
} ztf_GuiComponentFlags;

typedef struct ztf_UIComponentDesc
{
    ztf_Float2 mStartPosition = ztf_Float2{0.0f, 150.0f};
    ztf_Float2 mStartSize = ztf_Float2{600.0f, 550.0f};

    uint32_t mFontID = 0;
    float    mFontSize = 16.0f;
} ztf_UIComponentDesc;

typedef struct ztf_UIComponent
{
    //(UIWidget*)[dyn_size]
    ztf_UIWidget** mWidgets = NULL;
    //(bool)[dyn_size]
    bool* mWidgetsClone = NULL;
    void* pUserData = NULL;

    // Contextual menus when right clicking the title bar
    char const* const* mContextualMenuLabels = NULL;
    ztf_WidgetCallback const* mContextualMenuCallbacks = NULL;
    size_t                mContextualMenuCount = 0;
    ztf_Float4            mInitialWindowRect = ztf_Float4{0.f, 0.f, 0.f, 0.f};
    ztf_Float4            mCurrentWindowRect = ztf_Float4{0.f, 0.f, 0.f, 0.f};
    char                  mTitle[MAX_TITLE_STR_LENGTH] = {0};
    uintptr_t             pFont = 0;
    uint32_t              mFontTextureIndex = 0;
    float                 mAlpha = 0.f;

    // defaults to GUI_COMPONENT_FLAGS_ALWAYS_AUTO_RESIZE
    // on mobile, GUI_COMPONENT_FLAGS_START_COLLAPSED is also set
    int32_t mFlags = 0;

    bool mActive = false;

    // UI Component settings that can be modified at runtime by the client.
    bool mHasCloseButton = false;

    // Custom callbacks for raw driver API calls
    ztf_WindowCallback pPreProcessCallback = NULL;
    ztf_WindowCallback pPostProcessCallback = NULL;
} ztf_UIComponent;

/****************************************************************************/
// MARK: - Dynamic UI Widget Data Structures
/****************************************************************************/

typedef struct ztf_DynamicUIWidgets
{
    // stb_ds array of UIWidget*
    ztf_UIWidget** mDynamicProperties = NULL;
} ztf_DynamicUIWidgets;

/****************************************************************************/
// MARK: - Forge User Interface Data Structures
/****************************************************************************/

typedef struct ztf_UserInterfaceDesc
{
    ztf_Renderer* pRenderer = NULL;
    ztf_PipelineCache* pCache = NULL;
    char const* mSettingsFilename = nullptr;

    uint32_t mMaxDynamicUIUpdatesPerBatch = 20u;
    uint32_t mMaxUIFonts = 10u;

    uint32_t mFrameCount = 2u;
    bool     mEnableDocking = false;
    bool     mEnableRemoteUI = true;
} ztf_UserInterfaceDesc;

typedef struct ztf_UserInterfaceLoadDesc
{
    ztf_PipelineCache* pCache;
    uint32_t       mLoadType;    // enum ReloadType
    uint32_t       mColorFormat; // enum TinyImageFormat
    uint32_t       mWidth;
    uint32_t       mHeight;
    uint32_t       mDisplayWidth;
    uint32_t       mDisplayHeight;
} ztf_UserInterfaceLoadDesc;

typedef struct ztf_UserInterfaceDrawCommand
{
    ztf_Float4   mClipRect;
    uint64_t mTextureId;
    uint32_t mVertexOffset;
    uint32_t mIndexOffset;
    uint32_t mVertexCount;
    uint32_t mIndexCount;
    uint32_t mElemCount;
} ztf_UserInterfaceDrawElement;

typedef struct ztf_UserInterfaceDrawData
{
    uint32_t                  mVertexCount;
    uint32_t                  mIndexCount;
    uint32_t                  mVertexSize;
    uint32_t                  mIndexSize;
    ztf_Float2                    mDisplayPos;
    ztf_Float2                    mDisplaySize;
    uint32_t                  mNumDrawCommands;
    unsigned char* mVertexBufferData;
    unsigned char* mIndexBufferData;
    ztf_UserInterfaceDrawCommand* mDrawCommands;
} ztf_UserInterfaceDrawData;


/****************************************************************************/
// MARK: - Application Life Cycle
/****************************************************************************/

/// Initializes the Forge Rendering objects associated with the User Interface
/// The Forge's User Interface makes use of ImGUI
/// To be called at application initialization time by the App Layer
ZTF_C_API void ztf_initUserInterface(ztf_UserInterfaceDesc* pDesc);

/// Frees Forge Rendering objects and memory associated with the User Interface
/// To be called at application shutdown time by the App Layer
ZTF_C_API void ztf_exitUserInterface();

/// Creates graphics pipelines associated with the User Interface
/// To be called at application load time by the App Layer
ZTF_C_API void ztf_loadUserInterface(const ztf_UserInterfaceLoadDesc* pDesc);

/// Destroys graphics pipelines associated with the User Interface
/// To be called at application unload time by the App Layer
ZTF_C_API void ztf_unloadUserInterface(uint32_t unloadType);

/// Renders defined ImGUI components and widgets using The Forge's Renderer
/// This function also handles rendering the Forge Profiler's UI Window.
/// If pUIDrawData* is NULL, the current ImGUI state will be used, otherwise the passed in draw data will be used.
/// Due to the nature of ImGUI not being thread safe, this call must be made on the main thread if pUIDrawData* is kept NULL.
ZTF_C_API void ztf_cmdDrawUserInterface(ztf_Cmd* pCmd, ztf_UserInterfaceDrawData* pUIDrawData = NULL);

/****************************************************************************/
// MARK: - Collapsing Header Widget Public Functions
/****************************************************************************/

/// Set whether or not a given Collapsing Header widget is currently collapsed
ZTF_C_API void ztf_uiSetCollapsingHeaderWidgetCollapsed(ztf_CollapsingHeaderWidget* pWidget, bool collapsed);

/****************************************************************************/
// MARK: - Dynamic Widget Public Functions
/****************************************************************************/

/// Create an independent set of widgets which can be dynamically added to a UI Component
ZTF_C_API ztf_UIWidget* ztf_uiCreateDynamicWidgets(ztf_DynamicUIWidgets* pDynamicUI, const char* pLabel, const void* pWidget, ztf_WidgetType type);

/// Free memory associated with a set of dynamic UI widgets
ZTF_C_API void ztf_uiDestroyDynamicWidgets(ztf_DynamicUIWidgets* pDynamicUI);

/// Add an existing set of dynamic widgets to an existing UI Component
ZTF_C_API void ztf_uiShowDynamicWidgets(const ztf_DynamicUIWidgets* pDynamicUI, ztf_UIComponent* pGui);

/// Remove an existing set of dynamic widgets from an existing UI Component
ZTF_C_API void ztf_uiHideDynamicWidgets(const ztf_DynamicUIWidgets* pDynamicUI, ztf_UIComponent* pGui);

/****************************************************************************/
// MARK: - UI Component Public Functions
/****************************************************************************/

/// Create a UI Component "window" to which Widgets can be added
/// User is NOT responsible for freeing this memory at application exit
ZTF_C_API void ztf_uiCreateComponent(const char* pTitle, const ztf_UIComponentDesc* pDesc, ztf_UIComponent** ppGuiComponent);

/// Free memory associated with a UI Component "window"
/// Only necessary for replacement purposes. UI Component memory will be freed internally on exit
ZTF_C_API void ztf_uiDestroyComponent(ztf_UIComponent* pGui);

/// Set whether or not a given UI Component is active and visible on the screen
ZTF_C_API void ztf_uiSetComponentActive(ztf_UIComponent* pGuiComponent, bool active);

/// Create a Widget to be assigned to a given UI Component
/// User is NOT responsible for freeing this memory at application exit
ZTF_C_API ztf_UIWidget* ztf_uiCreateComponentWidget(ztf_UIComponent* pGui, const char* pLabel, const void* pWidget, ztf_WidgetType type, //-V1071
                                            bool clone = true);

/// Destroy and free memory associated with a Widget
/// Only necessary for replacement purposes. UI Widget memory will be freed internally on exit
ZTF_C_API void ztf_uiDestroyComponentWidget(ztf_UIComponent* pGui, ztf_UIWidget* pWidget);

/// Destroy and free memory associated with all Widgets in a given UI Component
/// Only necessary for replacement purposes. UI Widget memory will be freed internally on exit
ZTF_C_API void ztf_uiDestroyAllComponentWidgets(ztf_UIComponent* pGui);

/****************************************************************************/
// MARK: - Safe UI Component and Widget Setter Functions
/****************************************************************************/

// NOTE: These functions exist to protect scope against null-pointer derefs
// on UI Component and Widget handles if this functionality still exists in
// app code while the UI Master Switch is disabled.

/// Assign "GuiComponentFlags" enum values to a given UI Component
ZTF_C_API void ztf_uiSetComponentFlags(ztf_UIComponent* pGui, int32_t flags);

/// Set whether or not a given Widget is intended to be "deferrred"
ZTF_C_API void ztf_uiSetWidgetDeferred(ztf_UIWidget* pWidget, bool deferred);

/// Assign Widget callback function (pointer to a function which takes and returns void)
/// Will be called when Widget is hovered, usable, and not blocked by anything
ZTF_C_API void ztf_uiSetWidgetOnHoverCallback(ztf_UIWidget* pWidget, void* pUserData, ztf_WidgetCallback callback);

/// Assign Widget callback function (pointer to a function which takes and returns void)
/// Will be called when Widget is currently active (ex. button being held)
ZTF_C_API void ztf_uiSetWidgetOnActiveCallback(ztf_UIWidget* pWidget, void* pUserData, ztf_WidgetCallback callback);

/// Assign Widget callback function (pointer to a function which takes and returns void)
/// Will be called when Widget is currently focused (for keyboard/gamepad nav)
ZTF_C_API void ztf_uiSetWidgetOnFocusCallback(ztf_UIWidget* pWidget, void* pUserData, ztf_WidgetCallback callback);

/// Assign Widget callback function (pointer to a function which takes and returns void)
/// Will be called when Widget just changed its underlying value or was pressed
ZTF_C_API void ztf_uiSetWidgetOnEditedCallback(ztf_UIWidget* pWidget, void* pUserData, ztf_WidgetCallback callback);

/// Assign Widget callback function (pointer to a function which takes and returns void)
/// Will be called when Widget is made inactive from an active state
ZTF_C_API void ztf_uiSetWidgetOnDeactivatedCallback(ztf_UIWidget* pWidget, void* pUserData, ztf_WidgetCallback callback);

/// Assign Widget callback function (pointer to a function which takes and returns void)
/// Will be called when Widget is made inactive from an active state and its underlying value has changed
ZTF_C_API void ztf_uiSetWidgetOnDeactivatedAfterEditCallback(ztf_UIWidget* pWidget, void* pUserData, ztf_WidgetCallback callback);

/// Set whether or not a given UI Widget should be on the sameline than the previous one
ZTF_C_API void ztf_uiSetSameLine(ztf_UIWidget* pGuiComponent, bool sameLine);

/****************************************************************************/
// MARK: - Other User Interface Functionality
/****************************************************************************/

/// Returns whether or not the UI is currently "focused" by the cursor
ZTF_C_API bool ztf_uiIsFocused();

/// Callback function to share any type of input data w/ ImGUI.
ZTF_C_API void ztf_uiOnInput(uint32_t actionId, bool buttonPress, const ztf_Float2* pMousePos, const ztf_Float2* pStick);

/// Callback function to share text entry data w/ ImGUI
ZTF_C_API void ztf_uiOnText(const wchar_t* pText);

/// Returns value associated with UI preparedness to accept text entry data
/// 0 -> Not pressed, 1 -> Digits Only keyboard, 2 -> Full Keyboard (Chars + Digits)
ZTF_C_API uint8_t ztf_uiWantTextInput();

/// Toggle UI rendering, input processing still works (used to hide UI components while taking screenshots)
ZTF_C_API void ztf_uiToggleRendering(bool enabled);

/// Returns whether or not UI rendering is currently enabled (see uiToggleRendering)
ZTF_C_API bool ztf_uiIsRenderingEnabled();

/// Creates a UserInterfaceDrawData* which can be passed to cmdDrawUserInterface(Cmd* pCmd, UserInterfaceDrawData* pUIDrawData) explicitly.
/// It's the caller's responsibility to call removeUIDrawData(...) when done.
ZTF_C_API ztf_UserInterfaceDrawData* ztf_addUIDrawData();

/// Populates a UserInterfaceDrawData* with current frame draw data so that it can be passed to cmdDrawUserInterface(Cmd* pCmd,
/// UserInterfaceDrawData* pUIDrawData) at a later time.
ZTF_C_API void ztf_uiPopulateDrawData(ztf_UserInterfaceDrawData* pUIDrawData);

/// Removes a UserInterfaceDrawData*.  It should not be reused after this point.
ZTF_C_API void ztf_removeUIDrawData(ztf_UserInterfaceDrawData* pUIDrawData);

#ifdef __cplusplus
}
#endif