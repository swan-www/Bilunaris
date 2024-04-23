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

    ztf_glue.linkLibC();
    // zforge_cpp.linkLibCpp();
    //ztf_glue.addIncludePath(.{ .path = "../../../../dep/ztf/src/dep/common/tfalias/Common_3/Application/Interfaces" });
    //ztf_glue.addIncludePath(.{ .path = "../../../../dep/ztf/src/dep/common/tfalias/Common_3/Graphics/Interfaces" });
    //ztf_glue.addIncludePath(.{ .path = "../../../../dep/ztf/src/dep/common/tfalias/Common_3/Resources/ResourceLoader/Interfaces" });
    //ztf_glue.addIncludePath(.{ .path = "../../../../dep/ztf/src/dep/common/tfalias/Common_3/Utilities/Interfaces" });
    //ztf_glue.addIncludePath(.{ .path = "../../../../dep/ztf/src/dep/common/tfalias/Common_3/Utilities/Log" });
    ztf_glue.addCSourceFiles(.{
        .files = &.{
            "glue/IFont_glue.cpp",
            "glue/IGraphics_glue.cpp",
            "glue/IResourceLoader_glue.cpp",
            "glue/IFileSystem_glue.cpp",
            "glue/ILog_glue.cpp",
            "glue/IMemory_glue.cpp",
            "glue/Log_glue.cpp",
        },
		.flags = &.{
			"-Wno-unused-command-line-argument",
		}
    });

	b.installArtifact(ztf_glue);

	const ztf = b.createModule(.{
        .target = target,
        .optimize = optimize,
        .root_source_file = .{ .path = "bindings/ITF.zig" },
    });
	_= &ztf;
}