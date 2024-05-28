const ztf_os = @import("IOperatingSystem");
const ztf_math = @import("MathTypes");
const ztf_camera_controller = @import("ICameraController");

//BEGIN ztf_os aliases
pub const ReloadType = ztf_os.ReloadType;
//END ztf_os aliases

//BEGIN ztf_math aliases
pub const Float2 = ztf_math.Float2;
pub const Matrix4 = ztf_math.Matrix4;
pub const Int2 = ztf_math.Int2;
//END ztf_math aliases

//BEGIN ztf_os aliases
pub const CameraMatrix = ztf_camera_controller.CameraMatrix;
//END ztf_os aliases

pub const struct_Renderer = opaque {};
pub const Renderer = struct_Renderer;
pub const struct_Cmd = opaque {};
pub const Cmd = struct_Cmd;
pub const struct_RenderTarget = opaque {};
pub const RenderTarget = struct_RenderTarget;
pub const struct_PipelineCache = opaque {};
pub const PipelineCache = struct_PipelineCache;
pub const struct_ztf_FontSystemDesc = extern struct {
    pRenderer: ?*Renderer = null,
    mFontstashRingSizeBytes: u32 = 1024 * 1024,
};
pub const FontSystemDesc = struct_ztf_FontSystemDesc;
pub const struct_ztf_FontSystemLoadDesc = extern struct {
    pCache: ?*PipelineCache = @import("std").mem.zeroes(?*PipelineCache),
    mLoadType: ReloadType = @import("std").mem.zeroes(ReloadType),
    mColorFormat: u32 = @import("std").mem.zeroes(u32),
    mDepthFormat: u32 = @import("std").mem.zeroes(u32),
    mWidth: u32 = @import("std").mem.zeroes(u32),
    mHeight: u32 = @import("std").mem.zeroes(u32),
    mCullMode: u32 = @import("std").mem.zeroes(u32),
    mDepthCompareMode: u32 = @import("std").mem.zeroes(u32),
};
pub const FontSystemLoadDesc = struct_ztf_FontSystemLoadDesc;
pub const struct_ztf_FontDesc = extern struct {
    pFontName: [*c]const u8 = "default",
    pFontPath: [*c]const u8 = null,
    pFontPassword: [*c]const u8 = null,
};
pub const FontDesc = struct_ztf_FontDesc;
pub const struct_ztf_FontDrawDesc = extern struct {
    pText: [*c]const u8 = null,
    mFontID: u32 = 0,
    mFontColor: u32 = 0xFFFFFFFF,
    mFontSize: f32 = 16.0,
    mFontSpacing: f32 = 0.0,
    mFontBlur: f32 = 0.0,
};
pub const FontDrawDesc = struct_ztf_FontDrawDesc;
pub extern fn initFontSystem(pDesc: [*c]FontSystemDesc) bool;
pub extern fn exitFontSystem(...) void;
pub extern fn loadFontSystem(pDesc: [*c]const FontSystemLoadDesc) void;
pub extern fn unloadFontSystem(unloadType: ReloadType) void;
pub extern fn cmdDrawTextWithFont(pCmd: ?*Cmd, screenCoordsInPx: ?*Float2, pDrawDesc: [*c]const FontDrawDesc) void;
pub extern fn cmdDrawWorldSpaceTextWithFont(pCmd: ?*Cmd, pMatWorld: ?*const Matrix4, pMatProjView: ?*const CameraMatrix, pDrawDesc: [*c]const FontDrawDesc) void;
pub extern fn cmdDrawDebugFontAtlas(pCmd: ?*Cmd, screenCoordsInPx: ?*Float2) void;
pub extern fn fntDefineFonts(pDescs: [*c]const FontDesc, count: u32, pOutIDs: [*c]u32) void;
pub extern fn fntGetFontAtlasSize(...) ?*Int2;
pub extern fn fntResetFontAtlas(newAtlasSize: ?*const Int2) void;
pub extern fn fntExpandAtlas(additionalSize: ?*const Int2) void;
pub extern fn fntMeasureFontText(pText: [*c]const u8, pDrawDesc: [*c]const FontDrawDesc) ?*Float2;