#pragma once
#include <stdbool.h> 
#include <stdint.h>

#include "ztf_bind_common.h"

#include "IOperatingSystem_c.h"
#include "MathTypes_glue.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct ztf_Renderer ztf_Renderer;

const uint32_t ZTF_MAX_INPUT_GAMEPADS = 4;
const uint32_t ZTF_MAX_INPUT_MULTI_TOUCHES = 8;
const uint32_t ZTF_MAX_INPUT_ACTIONS = 256;
const int32_t  ZTF_BUILTIN_DEVICE_HAPTICS = -1000;

typedef enum ztf_GamepadButton
{
    ZTF_GAMEPAD_BUTTON_LEFT_STICK_X,
    ZTF_GAMEPAD_BUTTON_LEFT_STICK_Y,
    ZTF_GAMEPAD_BUTTON_RIGHT_STICK_X,
    ZTF_GAMEPAD_BUTTON_RIGHT_STICK_Y,
    ZTF_GAMEPAD_BUTTON_AXIS_4, // L2/Left trigger
    ZTF_GAMEPAD_BUTTON_AXIS_5, // R2/Right trigger
    ZTF_GAMEPAD_BUTTON_AXIS_6,
    ZTF_GAMEPAD_BUTTON_AXIS_7,
    ZTF_GAMEPAD_BUTTON_AXIS_8,
    ZTF_GAMEPAD_BUTTON_AXIS_9,
    ZTF_GAMEPAD_BUTTON_AXIS_10,
    ZTF_GAMEPAD_BUTTON_AXIS_11,
    ZTF_GAMEPAD_BUTTON_AXIS_12,
    ZTF_GAMEPAD_BUTTON_AXIS_13,
    ZTF_GAMEPAD_BUTTON_AXIS_14,
    ZTF_GAMEPAD_BUTTON_AXIS_15,
    ZTF_GAMEPAD_BUTTON_AXIS_16,
    ZTF_GAMEPAD_BUTTON_AXIS_17,
    ZTF_GAMEPAD_BUTTON_AXIS_18,
    ZTF_GAMEPAD_BUTTON_AXIS_19,
    ZTF_GAMEPAD_BUTTON_AXIS_20,
    ZTF_GAMEPAD_BUTTON_AXIS_21,
    ZTF_GAMEPAD_BUTTON_AXIS_22,
    ZTF_GAMEPAD_BUTTON_AXIS_23,
    ZTF_GAMEPAD_BUTTON_AXIS_24,
    ZTF_GAMEPAD_BUTTON_AXIS_25,
    ZTF_GAMEPAD_BUTTON_AXIS_26,
    ZTF_GAMEPAD_BUTTON_AXIS_27,
    ZTF_GAMEPAD_BUTTON_AXIS_28,
    ZTF_GAMEPAD_BUTTON_AXIS_29,
    ZTF_GAMEPAD_BUTTON_AXIS_30,
    ZTF_GAMEPAD_BUTTON_AXIS_31,
    ZTF_GAMEPAD_BUTTON_ACCELERATION_X,
    ZTF_GAMEPAD_BUTTON_ACCELERATION_Y,
    ZTF_GAMEPAD_BUTTON_ACCELERATION_Z,
    ZTF_GAMEPAD_BUTTON_GRAVITY_X,
    ZTF_GAMEPAD_BUTTON_GRAVITY_Y,
    ZTF_GAMEPAD_BUTTON_GRAVITY_Z,
    ZTF_GAMEPAD_BUTTON_GYROSCOPE_X,
    ZTF_GAMEPAD_BUTTON_GYROSCOPE_Y,
    ZTF_GAMEPAD_BUTTON_GYROSCOPE_Z,
    ZTF_GAMEPAD_BUTTON_MAGNETIC_FIELD_X,
    ZTF_GAMEPAD_BUTTON_MAGNETIC_FIELD_Y,
    ZTF_GAMEPAD_BUTTON_MAGNETIC_FIELD_Z,
    ZTF_GAMEPAD_BUTTON_START,
    ZTF_GAMEPAD_BUTTON_AXIS_COUNT_ = ZTF_GAMEPAD_BUTTON_START,
    ZTF_GAMEPAD_BUTTON_SELECT,
    ZTF_GAMEPAD_BUTTON_LEFT,
    ZTF_GAMEPAD_BUTTON_RIGHT,
    ZTF_GAMEPAD_BUTTON_UP,
    ZTF_GAMEPAD_BUTTON_DOWN,
    ZTF_GAMEPAD_BUTTON_A, // Cross
    ZTF_GAMEPAD_BUTTON_B, // Circle
    ZTF_GAMEPAD_BUTTON_X, // Square
    ZTF_GAMEPAD_BUTTON_Y, // Triangle
    ZTF_GAMEPAD_BUTTON_L1,
    ZTF_GAMEPAD_BUTTON_R1,
    ZTF_GAMEPAD_BUTTON_L2,
    ZTF_GAMEPAD_BUTTON_R2,
    ZTF_GAMEPAD_BUTTON_L3,   // Left thumb
    ZTF_GAMEPAD_BUTTON_R3,   // Right thumb
    ZTF_GAMEPAD_BUTTON_HOME, // PS button
    ZTF_GAMEPAD_BUTTON_17,
    ZTF_GAMEPAD_BUTTON_18,
    ZTF_GAMEPAD_BUTTON_19,
    ZTF_GAMEPAD_BUTTON_20,
    ZTF_GAMEPAD_BUTTON_21,
    ZTF_GAMEPAD_BUTTON_22,
    ZTF_GAMEPAD_BUTTON_23,
    ZTF_GAMEPAD_BUTTON_24,
    ZTF_GAMEPAD_BUTTON_25,
    ZTF_GAMEPAD_BUTTON_26,
    ZTF_GAMEPAD_BUTTON_27,
    ZTF_GAMEPAD_BUTTON_28,
    ZTF_GAMEPAD_BUTTON_29,
    ZTF_GAMEPAD_BUTTON_30,
    ZTF_GAMEPAD_BUTTON_31,
    ZTF_GAMEPAD_BUTTON_MAX_,
    ZTF_GAMEPAD_BUTTON_COUNT_ = ZTF_GAMEPAD_BUTTON_MAX_ - ZTF_GAMEPAD_BUTTON_AXIS_COUNT_
} ztf_GamepadButton;

// Keyboard (gainput::Key)
typedef enum ztf_KeyboardButton
{
    ZTF_KEYBOARD_BUTTON_INVALID = -1,
    ZTF_KEYBOARD_BUTTON_ESCAPE,
    ZTF_KEYBOARD_BUTTON_F1,
    ZTF_KEYBOARD_BUTTON_F2,
    ZTF_KEYBOARD_BUTTON_F3,
    ZTF_KEYBOARD_BUTTON_F4,
    ZTF_KEYBOARD_BUTTON_F5,
    ZTF_KEYBOARD_BUTTON_F6,
    ZTF_KEYBOARD_BUTTON_F7,
    ZTF_KEYBOARD_BUTTON_F8,
    ZTF_KEYBOARD_BUTTON_F9,
    ZTF_KEYBOARD_BUTTON_F10,
    ZTF_KEYBOARD_BUTTON_F11,
    ZTF_KEYBOARD_BUTTON_F12,
    ZTF_KEYBOARD_BUTTON_F13,
    ZTF_KEYBOARD_BUTTON_F14,
    ZTF_KEYBOARD_BUTTON_F15,
    ZTF_KEYBOARD_BUTTON_F16,
    ZTF_KEYBOARD_BUTTON_F17,
    ZTF_KEYBOARD_BUTTON_F18,
    ZTF_KEYBOARD_BUTTON_F19,
    ZTF_KEYBOARD_BUTTON_PRINT,
    ZTF_KEYBOARD_BUTTON_SCROLL_LOCK,
    ZTF_KEYBOARD_BUTTON_BREAK,

    ZTF_KEYBOARD_BUTTON_SPACE = 0x0020,

    ZTF_KEYBOARD_BUTTON_APOSTROPHE = 0x0027,
    ZTF_KEYBOARD_BUTTON_COMMA = 0x002c,
    ZTF_KEYBOARD_BUTTON_MINUS = 0x002d,
    ZTF_KEYBOARD_BUTTON_PERIOD = 0x002e,
    ZTF_KEYBOARD_BUTTON_SLASH = 0x002f,

    ZTF_KEYBOARD_BUTTON_0 = 0x0030,
    ZTF_KEYBOARD_BUTTON_1 = 0x0031,
    ZTF_KEYBOARD_BUTTON_2 = 0x0032,
    ZTF_KEYBOARD_BUTTON_3 = 0x0033,
    ZTF_KEYBOARD_BUTTON_4 = 0x0034,
    ZTF_KEYBOARD_BUTTON_5 = 0x0035,
    ZTF_KEYBOARD_BUTTON_6 = 0x0036,
    ZTF_KEYBOARD_BUTTON_7 = 0x0037,
    ZTF_KEYBOARD_BUTTON_8 = 0x0038,
    ZTF_KEYBOARD_BUTTON_9 = 0x0039,

    ZTF_KEYBOARD_BUTTON_SEMICOLON = 0x003b,
    ZTF_KEYBOARD_BUTTON_LESS = 0x003c,
    ZTF_KEYBOARD_BUTTON_EQUAL = 0x003d,

    ZTF_KEYBOARD_BUTTON_A = 0x0041,
    ZTF_KEYBOARD_BUTTON_B = 0x0042,
    ZTF_KEYBOARD_BUTTON_C = 0x0043,
    ZTF_KEYBOARD_BUTTON_D = 0x0044,
    ZTF_KEYBOARD_BUTTON_E = 0x0045,
    ZTF_KEYBOARD_BUTTON_F = 0x0046,
    ZTF_KEYBOARD_BUTTON_G = 0x0047,
    ZTF_KEYBOARD_BUTTON_H = 0x0048,
    ZTF_KEYBOARD_BUTTON_I = 0x0049,
    ZTF_KEYBOARD_BUTTON_J = 0x004a,
    ZTF_KEYBOARD_BUTTON_K = 0x004b,
    ZTF_KEYBOARD_BUTTON_L = 0x004c,
    ZTF_KEYBOARD_BUTTON_M = 0x004d,
    ZTF_KEYBOARD_BUTTON_N = 0x004e,
    ZTF_KEYBOARD_BUTTON_O = 0x004f,
    ZTF_KEYBOARD_BUTTON_P = 0x0050,
    ZTF_KEYBOARD_BUTTON_Q = 0x0051,
    ZTF_KEYBOARD_BUTTON_R = 0x0052,
    ZTF_KEYBOARD_BUTTON_S = 0x0053,
    ZTF_KEYBOARD_BUTTON_T = 0x0054,
    ZTF_KEYBOARD_BUTTON_U = 0x0055,
    ZTF_KEYBOARD_BUTTON_V = 0x0056,
    ZTF_KEYBOARD_BUTTON_W = 0x0057,
    ZTF_KEYBOARD_BUTTON_X = 0x0058,
    ZTF_KEYBOARD_BUTTON_Y = 0x0059,
    ZTF_KEYBOARD_BUTTON_Z = 0x005a,

    ZTF_KEYBOARD_BUTTON_BRACKET_LEFT = 0x005b,
    ZTF_KEYBOARD_BUTTON_BACKSLASH = 0x005c,
    ZTF_KEYBOARD_BUTTON_BRACKET_RIGHT = 0x005d,

    ZTF_KEYBOARD_BUTTON_GRAVE = 0x0060,

    ZTF_KEYBOARD_BUTTON_LEFT,
    ZTF_KEYBOARD_BUTTON_RIGHT,
    ZTF_KEYBOARD_BUTTON_UP,
    ZTF_KEYBOARD_BUTTON_DOWN,
    ZTF_KEYBOARD_BUTTON_INSERT,
    ZTF_KEYBOARD_BUTTON_HOME,
    ZTF_KEYBOARD_BUTTON_DELETE,
    ZTF_KEYBOARD_BUTTON_END,
    ZTF_KEYBOARD_BUTTON_PAGE_UP,
    ZTF_KEYBOARD_BUTTON_PAGE_DOWN,

    ZTF_KEYBOARD_BUTTON_NUM_LOCK,
    ZTF_KEYBOARD_BUTTON_KP_EQUAL,
    ZTF_KEYBOARD_BUTTON_KP_DIVIDE,
    ZTF_KEYBOARD_BUTTON_KP_MULTIPLY,
    ZTF_KEYBOARD_BUTTON_KP_SUBTRACT,
    ZTF_KEYBOARD_BUTTON_KP_ADD,
    ZTF_KEYBOARD_BUTTON_KP_ENTER,
    ZTF_KEYBOARD_BUTTON_KP_INSERT,    // 0
    ZTF_KEYBOARD_BUTTON_KP_END,       // 1
    ZTF_KEYBOARD_BUTTON_KP_DOWN,      // 2
    ZTF_KEYBOARD_BUTTON_KP_PAGE_DOWN, // 3
    ZTF_KEYBOARD_BUTTON_KP_LEFT,      // 4
    ZTF_KEYBOARD_BUTTON_KP_BEGIN,     // 5
    ZTF_KEYBOARD_BUTTON_KP_RIGHT,     // 6
    ZTF_KEYBOARD_BUTTON_KP_HOME,      // 7
    ZTF_KEYBOARD_BUTTON_KP_UP,        // 8
    ZTF_KEYBOARD_BUTTON_KP_PAGE_UP,   // 9
    ZTF_KEYBOARD_BUTTON_KP_DELETE,    // ,

    ZTF_KEYBOARD_BUTTON_BACK_SPACE,
    ZTF_KEYBOARD_BUTTON_TAB,
    ZTF_KEYBOARD_BUTTON_RETURN,
    ZTF_KEYBOARD_BUTTON_CAPS_LOCK,
    ZTF_KEYBOARD_BUTTON_SHIFT_L,
    ZTF_KEYBOARD_BUTTON_CTRL_L,
    ZTF_KEYBOARD_BUTTON_SUPER_L,
    ZTF_KEYBOARD_BUTTON_ALT_L,
    ZTF_KEYBOARD_BUTTON_ALT_R,
    ZTF_KEYBOARD_BUTTON_SUPER_R,
    ZTF_KEYBOARD_BUTTON_MENU,
    ZTF_KEYBOARD_BUTTON_CTRL_R,
    ZTF_KEYBOARD_BUTTON_SHIFT_R,

    ZTF_KEYBOARD_BUTTON_BACK,
    ZTF_KEYBOARD_BUTTON_SOFT_LEFT,
    ZTF_KEYBOARD_BUTTON_SOFT_RIGHT,
    ZTF_KEYBOARD_BUTTON_CALL,
    ZTF_KEYBOARD_BUTTON_END_CALL,
    ZTF_KEYBOARD_BUTTON_START,
    ZTF_KEYBOARD_BUTTON_POUND,
    ZTF_KEYBOARD_BUTTON_DPAD_CENTER,
    ZTF_KEYBOARD_BUTTON_VOLUME_UP,
    ZTF_KEYBOARD_BUTTON_VOLUME_DOWN,
    ZTF_KEYBOARD_BUTTON_POWER,
    ZTF_KEYBOARD_BUTTON_CAMERA,
    ZTF_KEYBOARD_BUTTON_CLEAR,
    ZTF_KEYBOARD_BUTTON_SYMBOL,
    ZTF_KEYBOARD_BUTTON_EXPLORER,
    ZTF_KEYBOARD_BUTTON_ENVELOPE,
    ZTF_KEYBOARD_BUTTON_EQUALS,
    ZTF_KEYBOARD_BUTTON_AT,
    ZTF_KEYBOARD_BUTTON_HEADSET_HOOK,
    ZTF_KEYBOARD_BUTTON_FOCUS,
    ZTF_KEYBOARD_BUTTON_PLUS,
    ZTF_KEYBOARD_BUTTON_NOTIFICATION,
    ZTF_KEYBOARD_BUTTON_SEARCH,
    ZTF_KEYBOARD_BUTTON_MEDIA_PLAY_PAUSE,
    ZTF_KEYBOARD_BUTTON_MEDIA_STOP,
    ZTF_KEYBOARD_BUTTON_MEDIA_NEXT,
    ZTF_KEYBOARD_BUTTON_MEDIA_PREVIOUS,
    ZTF_KEYBOARD_BUTTON_MEDIA_REWIND,
    ZTF_KEYBOARD_BUTTON_MEDIA_FAST_FORWARD,
    ZTF_KEYBOARD_BUTTON_MUTE,
    ZTF_KEYBOARD_BUTTON_PICT_SYMBOLS,
    ZTF_KEYBOARD_BUTTON_SWITCH_CHARSET,

    ZTF_KEYBOARD_BUTTON_FORWARD,
    ZTF_KEYBOARD_BUTTON_EXTRA1,
    ZTF_KEYBOARD_BUTTON_EXTRA2,
    ZTF_KEYBOARD_BUTTON_EXTRA3,
    ZTF_KEYBOARD_BUTTON_EXTRA4,
    ZTF_KEYBOARD_BUTTON_EXTRA5,
    ZTF_KEYBOARD_BUTTON_EXTRA6,
    ZTF_KEYBOARD_BUTTON_FN,

    ZTF_KEYBOARD_BUTTON_CIRCUM_FLEX,
    ZTF_KEYBOARD_BUTTON_S_SHARP,
    ZTF_KEYBOARD_BUTTON_ACUTE,
    ZTF_KEYBOARD_BUTTON_ALT_GR,
    ZTF_KEYBOARD_BUTTON_NUMBER_SIGN,
    ZTF_KEYBOARD_BUTTON_U_DIAERESIS,
    ZTF_KEYBOARD_BUTTON_A_DIAERESIS,
    ZTF_KEYBOARD_BUTTON_O_DIAERESIS,
    ZTF_KEYBOARD_BUTTON_SECTION,
    ZTF_KEYBOARD_BUTTON_A_RING,
    ZTF_KEYBOARD_BUTTON_DIAERESIS,
    ZTF_KEYBOARD_BUTTON_TWO_SUPERIOR,
    ZTF_KEYBOARD_BUTTON_RIGHT_PARENTHESIS,
    ZTF_KEYBOARD_BUTTON_DOLLAR,
    ZTF_KEYBOARD_BUTTON_U_GRAVE,
    ZTF_KEYBOARD_BUTTON_ASTERISK,
    ZTF_KEYBOARD_BUTTON_COLON,
    ZTF_KEYBOARD_BUTTON_EXCLAM,

    ZTF_KEYBOARD_BUTTON_BRACE_LEFT,
    ZTF_KEYBOARD_BUTTON_BRACE_RIGHT,
    ZTF_KEYBOARD_BUTTON_SYS_RQ,

    ZTF_KEYBOARD_BUTTON_COUNT_
} ztf_KeyboardButton;

// Keyboard (gainput::MouseButton)
typedef enum ztf_MouseButton
{
    ZTF_MOUSE_BUTTON_0 = 0,
    ZTF_MOUSE_BUTTON_LEFT = ZTF_MOUSE_BUTTON_0,
    ZTF_MOUSE_BUTTON_1,
    ZTF_MOUSE_BUTTON_MIDDLE = ZTF_MOUSE_BUTTON_1,
    ZTF_MOUSE_BUTTON_2,
    ZTF_MOUSE_BUTTON_RIGHT = ZTF_MOUSE_BUTTON_2,
    ZTF_MOUSE_BUTTON_3,
    ZTF_MOUSE_BUTTON_WHEEL_UP = ZTF_MOUSE_BUTTON_3,
    ZTF_MOUSE_BUTTON_4,
    ZTF_MOUSE_BUTTON_WHEEL_DOWN = ZTF_MOUSE_BUTTON_4,
    ZTF_MOUSE_BUTTON_5,
    ZTF_MOUSE_BUTTON_6,
    ZTF_MOUSE_BUTTON_7,
    ZTF_MOUSE_BUTTON_8,
    ZTF_MOUSE_BUTTON_9,
    ZTF_MOUSE_BUTTON_10,
    ZTF_MOUSE_BUTTON_11,
    ZTF_MOUSE_BUTTON_12,
    ZTF_MOUSE_BUTTON_13,
    ZTF_MOUSE_BUTTON_14,
    ZTF_MOUSE_BUTTON_15,
    ZTF_MOUSE_BUTTON_16,
    ZTF_MOUSE_BUTTON_17,
    ZTF_MOUSE_BUTTON_18,
    ZTF_MOUSE_BUTTON_19,
    ZTF_MOUSE_BUTTON_20,
    ZTF_MOUSE_BUTTON_MAX = ZTF_MOUSE_BUTTON_20,
    ZTF_MOUSE_BUTTON_COUNT,
    ZTF_MOUSE_BUTTON_AXIS_X = ZTF_MOUSE_BUTTON_COUNT,
    ZTF_MOUSE_BUTTON_AXIS_Y,
    ZTF_MOUSE_BUTTON_COUNT_,
    ZTF_MOUSE_BUTTON_AXIS_COUNT = ZTF_MOUSE_BUTTON_COUNT_ - ZTF_MOUSE_BUTTON_AXIS_X
} ztf_MouseButton;

// Touch axises, used together with the touch finger index to derive gainput::TouchButton
typedef enum ztf_TouchButton
{
    ZTF_TOUCH_BUTTON_NONE,
    ZTF_TOUCH_AXIS_X,
    ZTF_TOUCH_AXIS_Y,
} ztf_TouchButton;

typedef enum ztf_TouchGesture
{
    ZTF_TOUCH_GESTURE_TAP,
    ZTF_TOUCH_GESTURE_PAN,
    ZTF_TOUCH_GESTURE_DOUBLE_TAP,
    ZTF_TOUCH_GESTURE_SWIPE,
    ZTF_TOUCH_GESTURE_PINCH,
    ZTF_TOUCH_GESTURE_ROTATE,
    ZTF_TOUCH_GESTURE_LONG_PRESS
} ztf_TouchGesture;

// Area of the screen that will trigger a virtual joystick
typedef enum ztf_TouchScreenArea
{
    ZTF_AREA_LEFT = 0,
    ZTF_AREA_RIGHT,
    ZTF_AREA_FULL,
} ztf_TouchScreenArea;

// The type of action mapping
typedef enum ztf_InputActionMappingType
{
    // A normal action mapping (ex. exit action -> esc button)
    ZTF_INPUT_ACTION_MAPPING_NORMAL = 0,
    // A composite action mapping (ex. camera translate action -> DA/WS mapping to stick axis X & Y)
    ZTF_INPUT_ACTION_MAPPING_COMPOSITE,
    // A combo action mapping (ex. full screen action -> alt+enter)
    ZTF_INPUT_ACTION_MAPPING_COMBO,
    // A touch gesture (ex. tap, pinch, pan, etc...)
    ZTF_INPUT_ACTION_MAPPING_TOUCH_GESTURE,
    // A touch virtual joystick
    ZTF_INPUT_ACTION_MAPPING_TOUCH_VIRTUAL_JOYSTICK
} ztf_InputActionMappingType;

// Action mapping device target.
// Defines which kind of device the actions mapping should target
typedef enum ztf_InputActionMappingDeviceTarget
{
    ZTF_INPUT_ACTION_MAPPING_TARGET_ALL = 0,
    ZTF_INPUT_ACTION_MAPPING_TARGET_CONTROLLER, // Supported action mapping type: INPUT_ACTION_MAPPING_NORMAL, INPUT_ACTION_MAPPING_COMPOSITE,
                                            // INPUT_ACTION_MAPPING_COMBO
    ZTF_INPUT_ACTION_MAPPING_TARGET_KEYBOARD,   // Supported action mapping type: INPUT_ACTION_MAPPING_NORMAL, INPUT_ACTION_MAPPING_COMPOSITE,
                                            // INPUT_ACTION_MAPPING_COMBO
    ZTF_INPUT_ACTION_MAPPING_TARGET_MOUSE,      // Supported action mapping type: INPUT_ACTION_MAPPING_NORMAL, INPUT_ACTION_MAPPING_COMPOSITE,
                                            // INPUT_ACTION_MAPPING_COMBO
    ZTF_INPUT_ACTION_MAPPING_TARGET_TOUCH,      // Supported action mapping type: INPUT_ACTION_MAPPING_NORMAL (for basic touch detection),
                                            // INPUT_ACTION_MAPPING_TOUCH_GESTURE, INPUT_ACTION_MAPPING_TOUCH_VIRTUAL_JOYSTICK
} ztf_InputActionMappingDeviceTarget;

// An action mapping description.  Used to define action mappings to be provided to the input system.
typedef struct ztf_ActionMappingDesc
{ //-V802 : Very user-facing struct, and order is highly important to convenience
    // The type of the action mapping
    ztf_InputActionMappingType mActionMappingType = ZTF_INPUT_ACTION_MAPPING_NORMAL;

    // Type of device this action targets
    // NOTE: cannot be INPUT_ACTION_MAPPING_TARGET_ALL.  This will cause an assertion in addActionMappings(...).
    ztf_InputActionMappingDeviceTarget mActionMappingDeviceTarget = ZTF_INPUT_ACTION_MAPPING_TARGET_CONTROLLER;

    // A unique ID associated with the action.
    uint32_t mActionId = UINT_MAX;

    // Device buttons that triggers the action (from the GamepadButton/KeyboardButton/MouseButton/TouchGesture enums)
    // For INPUT_ACTION_MAPPING_NORMAL, only the first element will be used (unless it's targetting touch device.  mDeviceButtons will not
    // be used but any touch will act as a "button" press). For INPUT_ACTION_MAPPING_COMPOSITE, all four elements will be used to map 2 axes
    // (element 0->+X, 1->-X, 2->+Y, 3->-Y) For INPUT_ACTION_MAPPING_COMBO, the first two elements will be used (element 0 is the button to
    // hold, element 1 causes the action to trigger)
    int32_t mDeviceButtons[4] = {0};

    // Used for axis buttons
    // For example, if targetting the left joystick, and we want to handle both the x and y axes,
    // then mDeviceButtons[0] should be the start axis (GAMEPAD_BUTTON_LEFT_STICK_X), and mNumAxis should be 2.
    // mNumAxis should be either 1 or 2 when targetting an axis button.
    uint8_t mNumAxis = 1;
    uint8_t mDelta = 1; // always use delta by default for axis (absolute pos is always provided in the ctx anyway)

    // User id associated with the action (relevant for controller and touch inputs to track fingers)
    uint8_t mUserId = 0;

    // Used with INPUT_ACTION_MAPPING_TOUCH_VIRTUAL_JOYSTICK to tune virtual joystick behavior
    float mDeadzone = 20.f;
    float mOutsideRadius = 200.f;
    float mScale = 1.f; // Scales the values from this action mapping for virtual joysticks and mice.

    // Used with INPUT_ACTION_MAPPING_TOUCH_VIRTUAL_JOYSTICK and TOUCH_AXIS mappings
    ztf_TouchScreenArea mTouchScreenArea = ZTF_AREA_LEFT;

    bool mScaleByDT = false;
    // INPUT_ACTION_MAPPING_COMPOSITE normally maps to 4 elements (2 axes) (element 0->+X, 1->-X, 2->+Y, 3->-Y)
    // Set this to `true` to make INPUT_ACTION_MAPPING_COMPOSITE map to only 2 elements (1 axis) (element 0->+X, 1->-X)
    bool mCompositeUseSingleAxis = false;
} ztf_ActionMappingDesc;

// UI System reserved input action mapping IDs
// These are reserved action mapping IDs used to drive the UI system
typedef enum ztf_UISystemInputAction
{
    ZTF_UI_ACTION_START_ID_ = ZTF_MAX_INPUT_ACTIONS - 64, // Reserve last 64 actions for UI action mappings

    // Keyboard specific buttons
    ZTF_UI_ACTION_KEY_TAB,
    ZTF_UI_ACTION_KEY_LEFT_ARROW,
    ZTF_UI_ACTION_KEY_RIGHT_ARROW,
    ZTF_UI_ACTION_KEY_UP_ARROW,
    ZTF_UI_ACTION_KEY_DOWN_ARROW,
    ZTF_UI_ACTION_KEY_PAGE_UP,
    ZTF_UI_ACTION_KEY_PAGE_DOWN,
    ZTF_UI_ACTION_KEY_HOME,
    ZTF_UI_ACTION_KEY_END,
    ZTF_UI_ACTION_KEY_INSERT,
    ZTF_UI_ACTION_KEY_DELETE,
    ZTF_UI_ACTION_KEY_BACK_SPACE,
    ZTF_UI_ACTION_KEY_SPACE,
    ZTF_UI_ACTION_KEY_ENTER,
    ZTF_UI_ACTION_KEY_ESCAPE,
    ZTF_UI_ACTION_KEY_CONTROL_L,
    ZTF_UI_ACTION_KEY_CONTROL_R,
    ZTF_UI_ACTION_KEY_SHIFT_L,
    ZTF_UI_ACTION_KEY_SHIFT_R,
    ZTF_UI_ACTION_KEY_ALT_L,
    ZTF_UI_ACTION_KEY_ALT_R,
    ZTF_UI_ACTION_KEY_SUPER_L,
    ZTF_UI_ACTION_KEY_SUPER_R,
    ZTF_UI_ACTION_KEY_A, // for select all (ctrl+a)
    ZTF_UI_ACTION_KEY_C, // for copy (ctrl+c)
    ZTF_UI_ACTION_KEY_V, // for paste (ctrl+v)
    ZTF_UI_ACTION_KEY_X, // for cut (ctrl+x)
    ZTF_UI_ACTION_KEY_Y, // for redo (ctrl+y)
    ZTF_UI_ACTION_KEY_Z, // for undo (ctrl+z)
    ZTF_UI_ACTION_KEY_F2,

    // Mouse specific buttons
    ZTF_UI_ACTION_MOUSE_LEFT,
    ZTF_UI_ACTION_MOUSE_RIGHT,
    ZTF_UI_ACTION_MOUSE_MIDDLE,
    ZTF_UI_ACTION_MOUSE_SCROLL_UP,
    ZTF_UI_ACTION_MOUSE_SCROLL_DOWN,
    ZTF_UI_ACTION_MOUSE_MOVE,

    // Navigation
    ZTF_UI_ACTION_NAV_TOGGLE_UI, // toggles the user interface					// e.g. R3 (PS4), RSB (Xbox), Right stick Press (Switch) F1
                                // (Keyboard)
    ZTF_UI_ACTION_NAV_ACTIVATE, // activate / open / toggle / tweak value       // e.g. Cross  (PS4), A (Xbox), A (Switch), Space (Keyboard)
    ZTF_UI_ACTION_NAV_CANCEL, // cancel / close / exit                        // e.g. Circle (PS4), B (Xbox), B (Switch), Escape (Keyboard)
    ZTF_UI_ACTION_NAV_INPUT,  // text input / on-screen keyboard              // e.g. Triang.(PS4), Y (Xbox), X (Switch), Return (Keyboard)
    ZTF_UI_ACTION_NAV_MENU,   // tap: toggle menu / hold: focus, move, resize // e.g. Square (PS4), X (Xbox), Y (Switch), Alt (Keyboard)
    ZTF_UI_ACTION_NAV_TWEAK_WINDOW_LEFT, // move / tweak / resize window (w/ PadMenu)    // e.g. D-pad Left/Right/Up/Down (Gamepads), Arrow
                                        // keys (Keyboard)
    ZTF_UI_ACTION_NAV_TWEAK_WINDOW_RIGHT,
    ZTF_UI_ACTION_NAV_TWEAK_WINDOW_UP,
    ZTF_UI_ACTION_NAV_TWEAK_WINDOW_DOWN,
    ZTF_UI_ACTION_NAV_SCROLL_MOVE_WINDOW, // scroll / move window (w/ PadMenu)                // e.g. Left Analog Stick Left/Right/Up/Down
    ZTF_UI_ACTION_NAV_FOCUS_PREV, // previous window (w/ PadMenu)                             // e.g. L1 or L2 (PS4), LB or LT (Xbox), L or
                                // ZL (Switch)
    ZTF_UI_ACTION_NAV_FOCUS_NEXT, // next window (w/ PadMenu)                                 // e.g. R1 or R2 (PS4), RB or RT (Xbox), R or
                                // ZL (Switch)
    ZTF_UI_ACTION_NAV_TWEAK_SLOW, // slower tweaks                                            // e.g. L1 or L2 (PS4), LB or LT (Xbox), L or
                                // ZL (Switch)
    ZTF_UI_ACTION_NAV_TWEAK_FAST, // faster tweaks                                            // e.g. R1 or R2 (PS4), RB or RT (Xbox), R or
                                // ZL (Switch)
    ZTF_UI_ACTION_NAV_HIDE_UI_TOGGLE, // Hides / Shows the UI while still processing inputs ..// e.g. L3 (PS4), LSB (Xbox), Left stick Press
                                    // (Switch) F3 (Keyboard)
} ztf_UISystemInputAction;

typedef enum ztf_DefaultInputAction
{
    // Default actions for unit-tests
    ZTF_TRANSLATE_CAMERA = 0,      // Left joystick | Composite for keyboard (DA/WS)
    ZTF_TRANSLATE_CAMERA_VERTICAL, // Down/Up - Left/Right triggers | Q/E on keyboard
    ZTF_ROTATE_CAMERA,             // Right joystick | Composite for keyboard (LJ/IK)
    ZTF_CAPTURE_INPUT,             // Left click
    ZTF_RESET_CAMERA,              // Y/TRIANGLE | Left mouse button | Spacebar
    ZTF_DUMP_PROFILE_DATA,         // Combo for controllers (start+B/Circle) | F3
    ZTF_TOGGLE_FULLSCREEN,         // KB only combo: alt+enter
    ZTF_RELOAD_SHADERS,            // KB only combo: STRG-S
    ZTF_EXIT,                      // Esc

    // Default actions for UI
    ZTF_UI_KEY_TAB = ztf_UISystemInputAction::ZTF_UI_ACTION_KEY_TAB,
    ZTF_UI_KEY_LEFT_ARROW = ztf_UISystemInputAction::ZTF_UI_ACTION_KEY_LEFT_ARROW,
    ZTF_UI_KEY_RIGHT_ARROW = ztf_UISystemInputAction::ZTF_UI_ACTION_KEY_RIGHT_ARROW,
    ZTF_UI_KEY_UP_ARROW = ztf_UISystemInputAction::ZTF_UI_ACTION_KEY_UP_ARROW,
    ZTF_UI_KEY_DOWN_ARROW = ztf_UISystemInputAction::ZTF_UI_ACTION_KEY_DOWN_ARROW,
    ZTF_UI_KEY_PAGE_UP = ztf_UISystemInputAction::ZTF_UI_ACTION_KEY_PAGE_UP,
    ZTF_UI_KEY_PAGE_DOWN = ztf_UISystemInputAction::ZTF_UI_ACTION_KEY_PAGE_DOWN,
    ZTF_UI_KEY_HOME = ztf_UISystemInputAction::ZTF_UI_ACTION_KEY_HOME,
    ZTF_UI_KEY_END = ztf_UISystemInputAction::ZTF_UI_ACTION_KEY_END,
    ZTF_UI_KEY_INSERT = ztf_UISystemInputAction::ZTF_UI_ACTION_KEY_INSERT,
    ZTF_UI_KEY_DELETE = ztf_UISystemInputAction::ZTF_UI_ACTION_KEY_DELETE,
    ZTF_UI_KEY_BACK_SPACE = ztf_UISystemInputAction::ZTF_UI_ACTION_KEY_BACK_SPACE,
    ZTF_UI_KEY_SPACE = ztf_UISystemInputAction::ZTF_UI_ACTION_KEY_SPACE,
    ZTF_UI_KEY_ENTER = ztf_UISystemInputAction::ZTF_UI_ACTION_KEY_ENTER,
    ZTF_UI_KEY_ESCAPE = ztf_UISystemInputAction::ZTF_UI_ACTION_KEY_ESCAPE,
    ZTF_UI_KEY_CONTROL_L = ztf_UISystemInputAction::ZTF_UI_ACTION_KEY_CONTROL_L,
    ZTF_UI_KEY_CONTROL_R = ztf_UISystemInputAction::ZTF_UI_ACTION_KEY_CONTROL_R,
    ZTF_UI_KEY_SHIFT_L = ztf_UISystemInputAction::ZTF_UI_ACTION_KEY_SHIFT_L,
    ZTF_UI_KEY_SHIFT_R = ztf_UISystemInputAction::ZTF_UI_ACTION_KEY_SHIFT_R,
    ZTF_UI_KEY_ALT_L = ztf_UISystemInputAction::ZTF_UI_ACTION_KEY_ALT_L,
    ZTF_UI_KEY_ALT_R = ztf_UISystemInputAction::ZTF_UI_ACTION_KEY_ALT_R,
    ZTF_UI_KEY_SUPER_L = ztf_UISystemInputAction::ZTF_UI_ACTION_KEY_SUPER_L,
    ZTF_UI_KEY_SUPER_R = ztf_UISystemInputAction::ZTF_UI_ACTION_KEY_SUPER_R,
    ZTF_UI_KEY_A = ztf_UISystemInputAction::ZTF_UI_ACTION_KEY_A,
    ZTF_UI_KEY_C = ztf_UISystemInputAction::ZTF_UI_ACTION_KEY_C,
    ZTF_UI_KEY_V = ztf_UISystemInputAction::ZTF_UI_ACTION_KEY_V,
    ZTF_UI_KEY_X = ztf_UISystemInputAction::ZTF_UI_ACTION_KEY_X,
    ZTF_UI_KEY_Y = ztf_UISystemInputAction::ZTF_UI_ACTION_KEY_Y,
    ZTF_UI_KEY_Z = ztf_UISystemInputAction::ZTF_UI_ACTION_KEY_Z,
    ZTF_UI_KEY_F2 = ztf_UISystemInputAction::ZTF_UI_ACTION_KEY_F2,

    // Mouse specific buttons
    ZTF_UI_MOUSE_LEFT = ztf_UISystemInputAction::ZTF_UI_ACTION_MOUSE_LEFT,
    ZTF_UI_MOUSE_RIGHT = ztf_UISystemInputAction::ZTF_UI_ACTION_MOUSE_RIGHT,
    ZTF_UI_MOUSE_MIDDLE = ztf_UISystemInputAction::ZTF_UI_ACTION_MOUSE_MIDDLE,
    ZTF_UI_MOUSE_SCROLL_UP = ztf_UISystemInputAction::ZTF_UI_ACTION_MOUSE_SCROLL_UP,
    ZTF_UI_MOUSE_SCROLL_DOWN = ztf_UISystemInputAction::ZTF_UI_ACTION_MOUSE_SCROLL_DOWN,

    // Navigation
    ZTF_UI_NAV_TOGGLE_UI = ztf_UISystemInputAction::ZTF_UI_ACTION_NAV_TOGGLE_UI,
    ZTF_UI_NAV_ACTIVATE = ztf_UISystemInputAction::ZTF_UI_ACTION_NAV_ACTIVATE,
    ZTF_UI_NAV_CANCEL = ztf_UISystemInputAction::ZTF_UI_ACTION_NAV_CANCEL,
    ZTF_UI_NAV_INPUT = ztf_UISystemInputAction::ZTF_UI_ACTION_NAV_INPUT,
    ZTF_UI_NAV_MENU = ztf_UISystemInputAction::ZTF_UI_ACTION_NAV_MENU,
    ZTF_UI_NAV_TWEAK_WINDOW_LEFT = ztf_UISystemInputAction::ZTF_UI_ACTION_NAV_TWEAK_WINDOW_LEFT,
    ZTF_UI_NAV_TWEAK_WINDOW_RIGHT = ztf_UISystemInputAction::ZTF_UI_ACTION_NAV_TWEAK_WINDOW_RIGHT,
    ZTF_UI_NAV_TWEAK_WINDOW_UP = ztf_UISystemInputAction::ZTF_UI_ACTION_NAV_TWEAK_WINDOW_UP,
    ZTF_UI_NAV_TWEAK_WINDOW_DOWN = ztf_UISystemInputAction::ZTF_UI_ACTION_NAV_TWEAK_WINDOW_DOWN,
    ZTF_UI_NAV_SCROLL_MOVE_WINDOW = ztf_UISystemInputAction::ZTF_UI_ACTION_NAV_SCROLL_MOVE_WINDOW,
    ZTF_UI_NAV_FOCUS_PREV = ztf_UISystemInputAction::ZTF_UI_ACTION_NAV_FOCUS_PREV,
    ZTF_UI_NAV_FOCUS_NEXT = ztf_UISystemInputAction::ZTF_UI_ACTION_NAV_FOCUS_NEXT,
    ZTF_UI_NAV_TWEAK_SLOW = ztf_UISystemInputAction::ZTF_UI_ACTION_NAV_TWEAK_SLOW,
    ZTF_UI_NAV_TWEAK_FAST = ztf_UISystemInputAction::ZTF_UI_ACTION_NAV_TWEAK_FAST
} ztf_DefaultInputAction;

typedef enum ztf_InputDeviceType
{
    ZTF_INPUT_DEVICE_INVALID = 0,
    ZTF_INPUT_DEVICE_GAMEPAD,
    ZTF_INPUT_DEVICE_TOUCH,
    ZTF_INPUT_DEVICE_KEYBOARD,
    ZTF_INPUT_DEVICE_MOUSE,
} ztf_InputDeviceType;

typedef enum ztf_InputActionPhase
{
    /// Action is initiated
    ZTF_INPUT_ACTION_PHASE_STARTED = 0,
    /// Example: mouse delta changed, key pressed, ...
    ZTF_INPUT_ACTION_PHASE_UPDATED,
    /// Example: mouse delta changed, key pressed, ...
    ZTF_INPUT_ACTION_PHASE_ENDED,
    /// Example: left mouse button was pressed and now released, gesture was started but got canceled
    ZTF_INPUT_ACTION_PHASE_CANCELED,
} ztf_InputActionPhase;

typedef struct ztf_InputActionContext
{
    void* pUserData = NULL;
    /// Indices of fingers for detected gesture
    int32_t mFingerIndices[ZTF_MAX_INPUT_MULTI_TOUCHES] = {0};
    union
    {
        /// Gesture input
        ztf_Float4  mFloat4;
        /// 3D input (gyroscope, ...)
        ztf_Float3  mFloat3;
        /// 2D input (mouse position, delta, composite input (wasd), gamepad stick, joystick, ...)
        ztf_Float2  mFloat2;
        /// 1D input (composite input (ws), gamepad left trigger, ...)
        float    mFloat;
        /// Button input (mouse left button, keyboard keys, ...)
        bool     mBool;
        /// Text input
        wchar_t* pText;
    };

    ztf_Float2* pPosition = NULL;
    const bool* pCaptured = NULL;
    int32_t     mScrollValue = 0;
    uint32_t    mActionId = UINT_MAX;
    /// What phase is the action currently in
    uint8_t     mPhase = ZTF_INPUT_ACTION_PHASE_ENDED;
    uint8_t     mDeviceType = ZTF_INPUT_DEVICE_INVALID;
    /// User management (which user does this action apply to)
    uint8_t     mUserId = 0u;
} ztf_InputActionContext;

typedef bool (*ztf_InputActionCallback)(ztf_InputActionContext* pContext);

typedef struct ztf_InputActionDesc
{ //-V802 : Very user-facing struct, and order is highly important to convenience
    /// Action ID
    uint32_t            mActionId = UINT_MAX;
    /// Callback when an action is initiated, performed or canceled
    ztf_InputActionCallback pFunction = NULL;
    /// User data which will be assigned to InputActionContext::pUserData when calling pFunction
    void* pUserData = NULL;
    /// User management (which user does this action apply to)
    uint8_t             mUserId = 0u;
} ztf_InputActionDesc;

typedef enum ztf_GlobalInputActionType
{
    // Triggered when any action mapping of a button is triggered
    ZTF_ANY_BUTTON_ACTION = 0,
    // Used for processing text from keyboard or virtual keyboard
    ZTF_TEXT
} ztf_GlobalInputActionType;

// Global actions
// These are handled differently than actions from an action mapping.
typedef struct ztf_GlobalInputActionDesc
{
    ztf_GlobalInputActionType mGlobalInputActionType = ZTF_ANY_BUTTON_ACTION;

    /// Callback when an action is initiated, performed or canceled
    ztf_InputActionCallback pFunction = NULL;
    /// User data which will be assigned to InputActionContext::pUserData when calling pFunction
    void* pUserData = NULL;
} ztf_GlobalInputActionDesc;

typedef struct ztf_InputSystemDesc
{
    ztf_Renderer* pRenderer = NULL;
    ztf_WindowDesc* pWindow = NULL;

    const char* pJoystickTexture = NULL; // Keep this variable NULL to not show any joysticks on touch devices
} ztf_InputSystemDesc;

ZTF_C_API bool ztf_initInputSystem(ztf_InputSystemDesc* pDesc);
ZTF_C_API void ztf_exitInputSystem();
ZTF_C_API void ztf_updateInputSystem(float deltaTime, uint32_t width, uint32_t height);

// Input action (callbacks) functionalities //////////////////
/* Adds a new action (callback) for a specific (or all) device target(s)
 * If INPUT_ACTION_MAPPING_TARGET_ALL is specified, an action will be mapped for all device targets
 * that have the action ID specified in pDesc.
 */
ZTF_C_API void ztf_addInputAction(const ztf_InputActionDesc* pDesc,
                              const ztf_InputActionMappingDeviceTarget actionMappingTarget = ZTF_INPUT_ACTION_MAPPING_TARGET_ALL);
ZTF_C_API void ztf_removeInputAction(const ztf_InputActionDesc* pDesc,
                                 const ztf_InputActionMappingDeviceTarget actionMappingTarget = ZTF_INPUT_ACTION_MAPPING_TARGET_ALL);
ZTF_C_API void ztf_setGlobalInputAction(const ztf_GlobalInputActionDesc* pDesc);
//////////////////////////////////////////////////////////////

// Input action mappings functionalities /////////////////////
/* Adds new action mappings for a specific (or all) device target(s)
 * Takes in an array of ActionMappingDesc
 * Note: this will clear all current action mappings, including any callbacks.
 */
ZTF_C_API void ztf_addActionMappings(ztf_ActionMappingDesc* const actionMappings, const uint32_t numActions,
                                 const ztf_InputActionMappingDeviceTarget actionMappingTarget);

/* Removes currently active action mappings
 * Note: this will clear any callbacks that were added for any action mapping being cleared.
 */
ZTF_C_API void ztf_removeActionMappings(const ztf_InputActionMappingDeviceTarget actionMappingTarget);

/* Adds default TF action mappings
 * Note: this will clear all current action mappings, including any callbacks.
 */
ZTF_C_API void ztf_addDefaultActionMappings();
//////////////////////////////////////////////////////////////

ZTF_C_API bool ztf_setEnableCaptureInput(bool enable);

/// Used to enable/disable text input for non-keyboard setups (virtual keyboards for console/mobile, ...)
ZTF_C_API void ztf_setVirtualKeyboard(uint32_t type);

ZTF_C_API void ztf_setDeadZone(unsigned int controllerIndex, float deadZoneSize);
ZTF_C_API void ztf_setLEDColor(int gamePadIndex, uint8_t r, uint8_t g, uint8_t b);

// if gamepad index == BUILTIN_DEVICE_HAPTICS it will try to set rumble on the actual device
// in the case of iOS and iphones that would mean the actual phone vibrates
ZTF_C_API bool ztf_setRumbleEffect(int gamePadIndex, float left_motor, float right_motor, uint32_t duration_ms);

ZTF_C_API const char* ztf_getGamePadName(int gamePadIndex);
ZTF_C_API bool        ztf_gamePadConnected(int gamePadIndex);
ZTF_C_API void        ztf_setOnDeviceChangeCallBack(void (*onDeviceChnageCallBack)(const char* name, bool added, int gamePadIndex));

#ifdef __cplusplus
}
#endif