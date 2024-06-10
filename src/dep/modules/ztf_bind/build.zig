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
		"MathTypes_glue.h",
		"ICameraController_c.h",
		"IFont_c.h",
		"IOperatingSystem_c.h",
		"IGraphics_c.h",
		"GraphicsConfig_c.h",
		"ILog_c.h",
		"IMemory_c.h",
		"IThread_c.h",
		"IFileSystem_c.h",
		"IResourceLoader_c.h",
		"IApp_c.h",
		"IInput_c.h",
		"IUI_c.h",
	};

	for (ztf_glue_headers) |h| 
	{
		const header_src_path = try std.fs.path.join(b.allocator, &.{ "glue", h});
		defer b.allocator.free(header_src_path);
		ztf_glue.installHeader(header_src_path, header_src_path);
	}
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
		const header_src_path = try std.fs.path.join(b.allocator, &.{ "glue", h});
		defer b.allocator.free(header_src_path);
		const translateCOfHeader = b.addTranslateC(.{
			.root_source_file = .{ .path = header_src_path },
			.target = target,
        	.optimize = optimize,
		});
		translateCOfHeader.defineCMacroRaw("_WINDOWS=");
		translateCOfHeader.step.dependOn(&ztf_glue.step);

		const header_name_no_ext = std.fs.path.stem(h);
		const zig_file_output_path_no_ext = try std.fs.path.join(b.allocator,&.{ "ZTF/", header_name_no_ext});
		defer b.allocator.free(zig_file_output_path_no_ext);
		const zig_file_output_path = try std.mem.concat(b.allocator, u8, &.{zig_file_output_path_no_ext, ".zig"});
		defer b.allocator.free(zig_file_output_path);

		const installFile = b.addInstallFile(translateCOfHeader.getOutput(), zig_file_output_path);
		installFile.step.dependOn(&translateCOfHeader.step);
		translate_ztf_step.dependOn(&installFile.step);	
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