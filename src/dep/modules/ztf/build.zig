const std = @import("std");
const unicode = std.unicode;
const tfalias = @import("tfalias");

pub const HeaderInfo = struct {
	srcPath: []const u8,
	headerName: []const u8,
	outputName: []const u8,
	outputFileName: []const u8,
};

pub const ztf_headers = [_]HeaderInfo{
	.{ .srcPath = "glue/MathTypes_glue.cpp",			.headerName = "MathTypes_glue.h",		.outputName = "ZtfMathTypes", 			.outputFileName = "ZtfMathTypes.zig",},
	.{ .srcPath = "glue/ICameraController_c.cpp",		.headerName = "ICameraController_c.h",	.outputName = "ZtfCameraController", 	.outputFileName = "ZtfCameraController.zig", },
	.{ .srcPath = "glue/IFont_c.cpp",					.headerName = "IFont_c.h",				.outputName = "ZtfFont", 				.outputFileName = "ZtfFont.zig", },
	.{ .srcPath = "glue/IOperatingSystem_c.cpp",		.headerName = "IOperatingSystem_c.h",	.outputName = "ZtfOperatingSystem", 	.outputFileName = "ZtfOperatingSystem.zig", },
	.{ .srcPath = "glue/IGraphics_c.cpp",				.headerName = "IGraphics_c.h",			.outputName = "ZtfGraphics", 			.outputFileName = "ZtfGraphics.zig", },
	.{ .srcPath = "glue/GraphicsConfig_c.cpp",			.headerName = "GraphicsConfig_c.h",		.outputName = "ZtfGraphicsConfig", 		.outputFileName = "ZtfGraphicsConfig.zig", },
	.{ .srcPath = "glue/ILog_c.cpp",					.headerName = "ILog_c.h",				.outputName = "ZtfLog", 				.outputFileName = "ZtfLog.zig", },
	.{ .srcPath = "glue/IMemory_c.cpp",					.headerName = "IMemory_c.h",			.outputName = "ZtfMemory", 				.outputFileName = "ZtfMemory.zig", },
	.{ .srcPath = "glue/IThread_c.cpp",					.headerName = "IThread_c.h",			.outputName = "ZtfThread", 				.outputFileName = "ZtfThread.zig", },
	.{ .srcPath = "glue/IFileSystem_c.cpp",				.headerName = "IFileSystem_c.h",		.outputName = "ZtfFileSystem", 			.outputFileName = "ZtfFileSystem.zig", },
	.{ .srcPath = "glue/IResourceLoader_c.cpp",			.headerName = "IResourceLoader_c.h",	.outputName = "ZtfResourceLoader", 		.outputFileName = "ZtfResourceLoader.zig", },
	.{ .srcPath = "glue/IApp_c.cpp",					.headerName = "IApp_c.h",				.outputName = "ZtfApp", 				.outputFileName = "ZtfApp.zig", },
	.{ .srcPath = "glue/IInput_c.cpp",					.headerName = "IInput_c.h",				.outputName = "ZtfInput", 				.outputFileName = "ZtfInput.zig", },
	.{ .srcPath = "glue/IUI_c.cpp",						.headerName = "IUI_c.h",				.outputName = "ZtfUI", 					.outputFileName = "ZtfUI.zig", },
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
	ztf.addIncludePath(.{ .path = "../../../../dep/ztf/src/dep/common/tfalias/Common_3/Application/Interfaces" });
    ztf.addIncludePath(.{ .path = "../../../../dep/ztf/src/dep/common/tfalias/Common_3/Application/Interfaces" });

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

	const translate_fixup_exe = b.addExecutable(.{
        .name = "translate_fixup_exe",
		.target = target,
        .optimize = optimize,
        .root_source_file = .{ .path = "append_file.zig"},
    });

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
		translateCOfHeader.step.dependOn(&translate_fixup_exe.step);

		const zig_file_output_path_no_ext = try std.fs.path.join(b.allocator,&.{ "ZTF/", h.outputName});
		defer b.allocator.free(zig_file_output_path_no_ext);
		const zig_file_output_path = try std.mem.concat(b.allocator, u8, &.{zig_file_output_path_no_ext, ".zig"});
		defer b.allocator.free(zig_file_output_path);
		const zig_file_name = try std.mem.concat(b.allocator, u8, &.{h.outputName, ".zig"});
		defer b.allocator.free(zig_file_name);

		//const translate_fixup_wf = b.addWriteFiles();
		//const copied_translate = translate_fixup_wf.addCopyFile(translateCOfHeader.getOutput(), zig_file_output_path);
		//translate_fixup_wf.step.dependOn(&translateCOfHeader.step);

    	const translate_fixup_run = b.addRunArtifact(translate_fixup_exe);
		_ = translate_fixup_run.addFileArg(translateCOfHeader.getOutput());
		//_ = translate_fixup_run.addFileArg(copied_translate);
		//zig_file_name
		const copied_translate = translate_fixup_run.addOutputFileArg(h.outputFileName);
		//const copied_translate = translateCOfHeader.getOutput();
		translate_fixup_run.step.dependOn(&translateCOfHeader.step);

		//const translate_fixup_wf = b.addWriteFiles();
		//translate_fixup_wf.addCopyFileToSource(generated_protocol_file, "src/protocol.zig");
		//wf.step.dependOn(&translateCOfHeader.step);

		//const update_protocol_step = b.step("update-protocol", "update src/protocol.zig to latest");
		//update_protocol_step.dependOn(&wf.step);

		//const installFile = b.addInstallFile(copied_translate, zig_file_output_path);
		const translated_module = b.addModule(h.outputName, .{
			.target = target,
			.optimize = optimize,
			.root_source_file = copied_translate,
		});

		//translateCOfHeader.addModule(h.outputName);
		ztf_module.addImport(h.outputName, translated_module);	

		//installFile.step.dependOn(&translate_fixup_run.step);
		//translate_ztf_step.dependOn(&installFile.step);
		translate_ztf_step.dependOn(&translate_fixup_run.step);
	}
}