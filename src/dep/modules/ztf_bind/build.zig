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
			"glue/IResourceLoader_c.cpp",
			"glue/IApp_c.cpp",
			"glue/IInput_c.cpp",
			"glue/IUI_c.cpp",
        },
		.flags = &.{
			"-Wno-unused-command-line-argument",
			//"-Wno-everything",
			windowsFlag
		}
    });

	const ztf_glue_headers = [_][]const u8{
		"glue/MathTypes_glue.h",
		"glue/ICameraController_c.h",
		"glue/IFont_c.h",
		"glue/IOperatingSystem_c.h",
		"glue/IGraphics_c.h",
		"glue/GraphicsConfig_c.h",
		"glue/ILog_c.h",
		"glue/IMemory_c.h",
		"glue/IThread_c.h",
		"glue/IFileSystem_c.h",
		"glue/IResourceLoader_c.h",
		"glue/IApp_c.h",
		"glue/IInput_c.h",
		"glue/IUI_c.h",
	};

	for (ztf_glue_headers) |h| ztf_glue.installHeader(h, h);
	b.installArtifact(ztf_glue);

	var translate_ztf_step = b.step("translate_ztf", "");
	b.getInstallStep().dependOn(translate_ztf_step);

	const ztf_zig = b.addStaticLibrary(.{
        .name = "ztf_zig",
        .target = target,
        .optimize = optimize,
    });
	_ = &ztf_zig;

	for (ztf_glue_headers) |h|
	{
		const translateCOfHeader = b.addTranslateC(.{
			.root_source_file = .{ .path = h },
			.target = target,
        	.optimize = optimize,
		});
		translateCOfHeader.step.dependOn(&ztf_glue.step);

		const translatedHeaderModule = b.createModule(.{
			.target = target,
			.optimize = optimize,
			.root_source_file = translateCOfHeader.getOutput(),
		});
		_ = &translatedHeaderModule;
		//ztf_zig.installHeader(src_path: []const u8, dest_rel_path: []const u8)

		translate_ztf_step.dependOn(&translateCOfHeader.step);
	}
	
	//const ztf = b.createModule(.{
    //    .target = target,
    //    .optimize = optimize,
    //    .root_source_file = .{ .path = "bindings/ITF.zig" },
    //});
	//_= &ztf;
//
	//const ztf_zig = b.addStaticLibrary(.{
    //    .name = "ztf_zig",
    //    .target = target,
    //    .optimize = optimize,
	//	.root_source_file = .{ .path = "bindings/ITF.zig" },
    //});
	//_= &ztf_zig;
	//b.installArtifact(ztf_zig);

}