//BEGIN Windows defines
pub const struct_HWND__ = extern struct {
    unused: c_int = @import("std").mem.zeroes(c_int),
};
pub const HWND = [*c]struct_HWND__;
pub const wchar_t = c_ushort;
pub const WCHAR = wchar_t;
//END Windows defines

pub const WM_WINDOWED: c_int = 0;
pub const WM_FULLSCREEN: c_int = 1;
pub const WM_BORDERLESS: c_int = 2;
pub const enum_ztf_WindowMode = c_int;
pub const WindowMode = enum_ztf_WindowMode;
pub const struct_ztf_RectDesc = extern struct {
    left: i32 = @import("std").mem.zeroes(i32),
    top: i32 = @import("std").mem.zeroes(i32),
    right: i32 = @import("std").mem.zeroes(i32),
    bottom: i32 = @import("std").mem.zeroes(i32),
};
pub const RectDesc = struct_ztf_RectDesc;
pub const WINDOW_HANDLE_TYPE_UNKNOWN: c_int = 0;
pub const WINDOW_HANDLE_TYPE_WIN32: c_int = 1;
pub const WINDOW_HANDLE_TYPE_XLIB: c_int = 2;
pub const WINDOW_HANDLE_TYPE_XCB: c_int = 3;
pub const WINDOW_HANDLE_TYPE_WAYLAND: c_int = 4;
pub const WINDOW_HANDLE_TYPE_ANDROID: c_int = 5;
pub const WINDOW_HANDLE_TYPE_VI_NN: c_int = 6;
pub const enum_ztf_WindowHandleType = c_int;
pub const WindowHandleType = enum_ztf_WindowHandleType;
pub const struct_ztf_WindowHandle = extern struct {
    type: WindowHandleType = @import("std").mem.zeroes(WindowHandleType),
    window: HWND = @import("std").mem.zeroes(HWND),
};
pub const WindowHandle = struct_ztf_WindowHandle;
pub const struct_ztf_WindowDesc = extern struct {
    handle: WindowHandle = @import("std").mem.zeroes(WindowHandle),
    windowedRect: RectDesc = @import("std").mem.zeroes(RectDesc),
    fullscreenRect: RectDesc = @import("std").mem.zeroes(RectDesc),
    clientRect: RectDesc = @import("std").mem.zeroes(RectDesc),
    windowsFlags: u32 = @import("std").mem.zeroes(u32),
    fullScreen: bool = @import("std").mem.zeroes(bool),
    cursorCaptured: bool = @import("std").mem.zeroes(bool),
    iconified: bool = @import("std").mem.zeroes(bool),
    maximized: bool = @import("std").mem.zeroes(bool),
    minimized: bool = @import("std").mem.zeroes(bool),
    hide: bool = @import("std").mem.zeroes(bool),
    noresizeFrame: bool = @import("std").mem.zeroes(bool),
    borderlessWindow: bool = @import("std").mem.zeroes(bool),
    overrideDefaultPosition: bool = @import("std").mem.zeroes(bool),
    centered: bool = @import("std").mem.zeroes(bool),
    forceLowDPI: bool = @import("std").mem.zeroes(bool),
    mWindowMode: i32 = @import("std").mem.zeroes(i32),
    pCurRes: [32]i32 = @import("std").mem.zeroes([32]i32),
    pLastRes: [32]i32 = @import("std").mem.zeroes([32]i32),
    mWndX: i32 = @import("std").mem.zeroes(i32),
    mWndY: i32 = @import("std").mem.zeroes(i32),
    mWndW: i32 = @import("std").mem.zeroes(i32),
    mWndH: i32 = @import("std").mem.zeroes(i32),
    mCursorHidden: bool = @import("std").mem.zeroes(bool),
    mCursorInsideWindow: i32 = @import("std").mem.zeroes(i32),
    mCursorCaptured: bool = @import("std").mem.zeroes(bool),
    mMinimizeRequested: bool = @import("std").mem.zeroes(bool),
};
pub const WindowDesc = struct_ztf_WindowDesc;
pub const struct_ztf_Resolution = extern struct {
    mWidth: u32 = @import("std").mem.zeroes(u32),
    mHeight: u32 = @import("std").mem.zeroes(u32),
};
pub const Resolution = struct_ztf_Resolution;
pub const struct_ztf_MonitorDesc = extern struct {
    monitorRect: RectDesc = @import("std").mem.zeroes(RectDesc),
    workRect: RectDesc = @import("std").mem.zeroes(RectDesc),
    dpi: [2]c_uint = @import("std").mem.zeroes([2]c_uint),
    physicalSize: [2]c_uint = @import("std").mem.zeroes([2]c_uint),
    adapterName: [32]WCHAR = @import("std").mem.zeroes([32]WCHAR),
    displayName: [32]WCHAR = @import("std").mem.zeroes([32]WCHAR),
    publicAdapterName: [128]WCHAR = @import("std").mem.zeroes([128]WCHAR),
    publicDisplayName: [128]WCHAR = @import("std").mem.zeroes([128]WCHAR),
    resolutions: [*c]Resolution = @import("std").mem.zeroes([*c]Resolution),
    defaultResolution: Resolution = @import("std").mem.zeroes(Resolution),
    modesPruned: bool = @import("std").mem.zeroes(bool),
    modeChanged: bool = @import("std").mem.zeroes(bool),
};
pub const MonitorDesc = struct_ztf_MonitorDesc;
pub const THERMAL_STATUS_MIN: c_int = -2;
pub const THERMAL_STATUS_NOT_SUPPORTED: c_int = -2;
pub const THERMAL_STATUS_ERROR: c_int = -1;
pub const THERMAL_STATUS_NONE: c_int = 0;
pub const THERMAL_STATUS_LIGHT: c_int = 1;
pub const THERMAL_STATUS_MODERATE: c_int = 2;
pub const THERMAL_STATUS_SEVERE: c_int = 3;
pub const THERMAL_STATUS_CRITICAL: c_int = 4;
pub const THERMAL_STATUS_EMERGENCY: c_int = 5;
pub const THERMAL_STATUS_SHUTDOWN: c_int = 6;
pub const THERMAL_STATUS_MAX: c_int = 7;
pub const enum_ztf_ThermalStatus = c_int;
pub const ThermalStatus = enum_ztf_ThermalStatus;
pub const RESET_TYPE_NONE: c_int = 0;
pub const RESET_TYPE_API_SWITCH: c_int = 1;
pub const RESET_TYPE_GRAPHIC_CARD_SWITCH: c_int = 2;
pub const RESET_TYPE_DEVICE_LOST: c_int = 4;
pub const RESET_TYPE_GPU_MODE_SWITCH: c_int = 8;
pub const enum_ztf_ResetType = c_int;
pub const ResetType = enum_ztf_ResetType;
pub const struct_ztf_ResetDesc = extern struct {
    mType: ResetType = @import("std").mem.zeroes(ResetType),
};
pub const ResetDesc = struct_ztf_ResetDesc;
pub const RELOAD_TYPE_RESIZE: c_int = 1;
pub const RELOAD_TYPE_SHADER: c_int = 2;
pub const RELOAD_TYPE_RENDERTARGET: c_int = 4;
pub const RELOAD_TYPE_ALL: c_int = -1;
pub const RELOAD_TYPE_COUNT: c_int = 3;
pub const enum_ztf_ReloadType = c_int;
pub const ReloadType = enum_ztf_ReloadType;
pub const struct_ztf_ReloadDesc = extern struct {
    mType: ReloadType = @import("std").mem.zeroes(ReloadType),
};
pub const ReloadDesc = struct_ztf_ReloadDesc;
pub const struct_ztf_OSInfo = extern struct {
    osName: [256]u8 = @import("std").mem.zeroes([256]u8),
    osVersion: [256]u8 = @import("std").mem.zeroes([256]u8),
    osDeviceName: [256]u8 = @import("std").mem.zeroes([256]u8),
};
pub const OSInfo = struct_ztf_OSInfo;
pub extern fn getRectWidth(rect: [*c]const RectDesc) c_int;
pub extern fn getRectHeight(rect: [*c]const RectDesc) c_int;
pub extern fn openWindow(app_name: [*c]const u8, winDesc: [*c]WindowDesc) void;
pub extern fn closeWindow(winDesc: [*c]WindowDesc) void;
pub extern fn setWindowRect(winDesc: [*c]WindowDesc, rect: [*c]const RectDesc) void;
pub extern fn setWindowSize(winDesc: [*c]WindowDesc, width: c_uint, height: c_uint) void;
pub extern fn setWindowed(winDesc: [*c]WindowDesc, width: c_uint, height: c_uint) void;
pub extern fn setBorderless(winDesc: [*c]WindowDesc, width: c_uint, height: c_uint) void;
pub extern fn setFullscreen(winDesc: [*c]WindowDesc) void;
pub extern fn showWindow(winDesc: [*c]WindowDesc) void;
pub extern fn hideWindow(winDesc: [*c]WindowDesc) void;
pub extern fn maximizeWindow(winDesc: [*c]WindowDesc) void;
pub extern fn minimizeWindow(winDesc: [*c]WindowDesc) void;
pub extern fn centerWindow(winDesc: [*c]WindowDesc) void;
pub extern fn captureCursor(winDesc: [*c]WindowDesc, bEnable: bool) void;
pub extern fn createCursor(path: [*c]const u8) ?*anyopaque;
pub extern fn setCursor(cursor: ?*anyopaque) void;
pub extern fn showCursor() void;
pub extern fn hideCursor() void;
pub extern fn isCursorInsideTrackingArea() bool;
pub extern fn setMousePositionRelative(winDesc: [*c]const WindowDesc, x: i32, y: i32) void;
pub extern fn setMousePositionAbsolute(x: i32, y: i32) void;
pub extern fn getRecommendedResolution(rect: [*c]RectDesc) void;
pub extern fn getRecommendedWindowRect(winDesc: [*c]WindowDesc, rect: [*c]RectDesc) void;
pub extern fn setResolution(pMonitor: [*c]const MonitorDesc, pRes: [*c]const Resolution) void;
pub extern fn getMonitor(index: u32) [*c]MonitorDesc;
pub extern fn getMonitorCount() u32;
pub extern fn getActiveMonitorIdx() u32;
pub extern fn getMonitorDpiScale(monitorIndex: u32, dpiScale: [*c]f32) void;
pub extern fn getResolutionSupport(pMonitor: [*c]const MonitorDesc, pRes: [*c]const Resolution) bool;
pub extern fn getThermalStatus() ThermalStatus;
pub extern fn getThermalStatusString(thermalStatus: ThermalStatus) [*c]const u8;
pub extern fn requestReset(pResetDesc: [*c]const ResetDesc) void;
pub extern fn getOsInfo() [*c]OSInfo;
pub extern fn requestReload(pReloadDesc: [*c]const ReloadDesc) void;
pub extern fn requestShutdown() void;
pub const errorMessagePopupCallbackFn = ?*const fn () callconv(.C) void;
pub extern fn errorMessagePopup(title: [*c]const u8, msg: [*c]const u8, windowHandle: [*c]WindowHandle, callback: errorMessagePopupCallbackFn) void;
pub const CustomMessageProcessor = ?*const fn ([*c]WindowDesc, ?*anyopaque) callconv(.C) i32;
pub extern fn setCustomMessageProcessor(proc: CustomMessageProcessor) void;
pub extern fn systemRun(command: [*c]const u8, arguments: [*c][*c]const u8, argumentCount: usize, stdOutFile: [*c]const u8) c_int;