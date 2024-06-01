const std = @import("std");
const tfalias = @import("tfalias");

pub fn build(b: *std.Build) !void
{
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

	const tfalias_lib = b.dependency("tfalias", .{
        .target = target,
        .optimize = optimize,
    });

	b.installArtifact(tfalias_lib.artifact("tfalias_os"));
	b.installArtifact(tfalias_lib.artifact("tfalias_renderer"));
	b.installArtifact(tfalias_lib.artifact("tfalias_gainput"));
	b.installArtifact(tfalias_lib.artifact("tfalias_spirvtools"));

	const ztf_glue = b.addStaticLibrary(.{
        .name = "ztf_glue",
        .target = target,
        .optimize = optimize,
    });

	const windowsFlag = if(target.result.os.tag == .windows) "-D_WINDOWS" else "";

    ztf_glue.linkLibC();
    // zforge_cpp.linkLibCpp();
	ztf_glue.addIncludePath(.{ .path = "../../../../dep/ztf/src/dep/common/tfalias/Common_3/Application/Interfaces" });
    ztf_glue.addIncludePath(.{ .path = "../../../../dep/ztf/src/dep/common/tfalias/Common_3/Application/Interfaces" });
    
	//ztf_glue.addIncludePath(.{ .path = "../../../../dep/ztf/src/dep/common/tfalias/Common_3/Graphics/Interfaces" });
    //ztf_glue.addIncludePath(.{ .path = "../../../../dep/ztf/src/dep/common/tfalias/Common_3/Resources/ResourceLoader/Interfaces" });
    //ztf_glue.addIncludePath(.{ .path = "../../../../dep/ztf/src/dep/common/tfalias/Common_3/Utilities/Interfaces" });
    //ztf_glue.addIncludePath(.{ .path = "../../../../dep/ztf/src/dep/common/tfalias/Common_3/Utilities/Log" });
    ztf_glue.addCSourceFiles(.{
        .files = &.{
			"glue/MathTypes_glue.cpp",
			"glue/ICameraController_c.cpp",
            "glue/IFont_c.cpp",
			"glue/IOperatingSystem_c.cpp",
            "glue/IGraphics_c.cpp",
			"glue/GraphicsConfig_c.cpp",
			"glue/ILog_c.cpp",

			"glue/IMemory_c.cpp",
			"glue/IThread_c.cpp",
			"glue/IFileSystem_c.cpp",
			//"glue/IResourceLoader_c.cpp",
        },
		.flags = &.{
			"-Wno-unused-command-line-argument",
			//"-Wno-everything",
			windowsFlag
		}
    });

	b.installArtifact(ztf_glue);

	const ztf = b.createModule(.{
        .target = target,
        .optimize = optimize,
        .root_source_file = .{ .path = "bindings/ITF.zig" },
    });
	_= &ztf;

	const ztf_zig = b.addStaticLibrary(.{
        .name = "ztf_zig",
        .target = target,
        .optimize = optimize,
		.root_source_file = .{ .path = "bindings/ITF.zig" },
    });
	_= &ztf_zig;
	b.installArtifact(ztf_zig);
}