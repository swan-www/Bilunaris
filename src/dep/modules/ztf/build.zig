const std = @import("std");
const tfalias = @import("tfalias");

pub const HeaderInfo = struct {
	srcPath: []const u8,
	headerName: []const u8,
	outputName: []const u8,
};

pub const ztf_headers = [_]HeaderInfo{
	.{ .srcPath = "glue/MathTypes_glue.cpp",			.headerName = "MathTypes_glue.h",		.outputName = "ZtfMathTypes", },
	.{ .srcPath = "glue/ICameraController_c.cpp",		.headerName = "ICameraController_c.h",	.outputName = "ZtfCameraController", },
	.{ .srcPath = "glue/IFont_c.cpp",					.headerName = "IFont_c.h",				.outputName = "ZtfFont", },
	.{ .srcPath = "glue/IOperatingSystem_c.cpp",		.headerName = "IOperatingSystem_c.h",	.outputName = "ZtfOperatingSystem", },
	.{ .srcPath = "glue/IGraphics_c.cpp",				.headerName = "IGraphics_c.h",			.outputName = "ZtfGraphics", },
	.{ .srcPath = "glue/GraphicsConfig_c.cpp",			.headerName = "GraphicsConfig_c.h",		.outputName = "ZtfGraphicsConfig", },
	.{ .srcPath = "glue/ILog_c.cpp",					.headerName = "ILog_c.h",				.outputName = "ZtfLog", },
	.{ .srcPath = "glue/IMemory_c.cpp",					.headerName = "IMemory_c.h",			.outputName = "ZtfMemory", },
	.{ .srcPath = "glue/IThread_c.cpp",					.headerName = "IThread_c.h",			.outputName = "ZtfThread", },
	.{ .srcPath = "glue/IFileSystem_c.cpp",				.headerName = "IFileSystem_c.h",		.outputName = "ZtfFileSystem", },
	.{ .srcPath = "glue/IResourceLoader_c.cpp",			.headerName = "IResourceLoader_c.h",	.outputName = "ZtfResourceLoader", },
	.{ .srcPath = "glue/IApp_c.cpp",					.headerName = "IApp_c.h",				.outputName = "ZtfApp", },
	.{ .srcPath = "glue/IInput_c.cpp",					.headerName = "IInput_c.h",				.outputName = "ZtfInput", },
	.{ .srcPath = "glue/IUI_c.cpp",						.headerName = "IUI_c.h",				.outputName = "ZtfUI", },
};

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

	const ztf = b.addStaticLibrary(.{
        .name = "ztf",
        .target = target,
        .optimize = optimize,
    });

	const windowsFlag = if(target.result.os.tag == .windows) "-D_WINDOWS" else "";

    ztf.linkLibC();
    // zforge_cpp.linkLibCpp();
	ztf.addIncludePath(.{ .path = "../../../../dep/ztf/src/dep/common/tfalias/Common_3/Application/Interfaces" });
    ztf.addIncludePath(.{ .path = "../../../../dep/ztf/src/dep/common/tfalias/Common_3/Application/Interfaces" });
    
    //ztf_glue.addCSourceFiles(.{
    //    .files = &.{
	//		"glue/MathTypes_glue.cpp",
	//		"glue/ICameraController_c.cpp",
    //        "glue/IFont_c.cpp",
	//		"glue/IOperatingSystem_c.cpp",
    //        "glue/IGraphics_c.cpp",
	//		"glue/GraphicsConfig_c.cpp",
	//		"glue/ILog_c.cpp",
	//		"glue/IMemory_c.cpp",
	//		"glue/IThread_c.cpp",
	//		"glue/IFileSystem_c.cpp",
	//		"glue/IResourceLoader_c.cpp",
	//		"glue/IApp_c.cpp",
	//		"glue/IInput_c.cpp",
	//		"glue/IUI_c.cpp",
    //    },
	//	.flags = &.{
	//		"-Wno-unused-command-line-argument",
	//		//"-Wno-everything",
	//		windowsFlag
	//	}
    //});

	for (ztf_headers) |h| 
	{
		ztf.addCSourceFile(.{
			.file = .{ .path = h.srcPath},
			.flags = &.{
				"-Wno-unused-command-line-argument",
				//"-Wno-everything",
				windowsFlag
			},
		});

		const header_src_path = try std.fs.path.join(b.allocator, &.{ "glue", h.headerName});
		defer b.allocator.free(header_src_path);
		ztf.installHeader(header_src_path, header_src_path);
	}
	b.installArtifact(ztf);

	var translate_ztf_step = b.step("translate_ztf", "");
	b.getInstallStep().dependOn(translate_ztf_step);

	const ztf_module = b.addModule("ztf", .{
		.target = target,
        .optimize = optimize,
		.root_source_file = .{ .path = "ztf.zig"},
	});
	_ = &ztf_module;

	const ztf_zig = b.addStaticLibrary(.{
        .name = "ztf_zig",
        .target = target,
        .optimize = optimize,
		.root_source_file = .{ .path = "ztf.zig"},
    });
	_ = &ztf_zig;

	for (ztf_headers) |h|
	{
		const header_src_path = try std.fs.path.join(b.allocator, &.{ "glue", h.headerName});
		defer b.allocator.free(header_src_path);
		const translateCOfHeader = b.addTranslateC(.{
			.root_source_file = .{ .path = header_src_path },
			.target = target,
        	.optimize = optimize,
		});
		translateCOfHeader.defineCMacroRaw("_WINDOWS=");
		translateCOfHeader.step.dependOn(&ztf.step);

		const zig_file_output_path_no_ext = try std.fs.path.join(b.allocator,&.{ "ZTF/", h.outputName});
		defer b.allocator.free(zig_file_output_path_no_ext);
		const zig_file_output_path = try std.mem.concat(b.allocator, u8, &.{zig_file_output_path_no_ext, ".zig"});
		defer b.allocator.free(zig_file_output_path);

		const installFile = b.addInstallFile(translateCOfHeader.getOutput(), zig_file_output_path);
		_ = translateCOfHeader.addModule(h.outputName);

		installFile.step.dependOn(&translateCOfHeader.step);
		translate_ztf_step.dependOn(&installFile.step);	
	}
}