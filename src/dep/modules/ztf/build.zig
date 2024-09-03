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
	.{ .srcPath = "glue/bstring_c.cpp",					.headerName = "bstring_c.h",			.outputName = "ZtfBString", 			.outputFileName = "ZtfBString.zig", },
	.{ .srcPath = "glue/IProfiler_c.cpp",				.headerName = "IProfiler_c.h",			.outputName = "ZtfProfiler", 			.outputFileName = "ZtfProfiler.zig", },
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

	for (ztf_headers) |h| 
	{
		ztf.addCSourceFile(.{
			.file = .{ .path = h.srcPath},
			.flags = &.{
				"-Wno-unused-command-line-argument",
				windowsFlag,
			},
		});

		const header_src_path = try std.fs.path.join(b.allocator, &.{ "glue", h.headerName});
		defer b.allocator.free(header_src_path);
		ztf.installHeader(header_src_path, header_src_path);
	}
	b.installArtifact(ztf);

	var translate_ztf_step = b.step("translate_ztf", "");
	b.getInstallStep().dependOn(translate_ztf_step);

	const ztf_cpp_include = b.addModule("ztf_cpp_include", .{
		.target = target,
        .optimize = optimize,
		.root_source_file = .{ .path = b.pathFromRoot("include_cpp")},
	});
	_ = &ztf_cpp_include;

	const translate_fixup_exe = b.addExecutable(.{
        .name = "translate_fixup_exe",
		.target = target,
        .optimize = optimize,
        .root_source_file = .{ .path = "append_file.zig"},
    });

	const h = HeaderInfo{
		.srcPath = "",
		.headerName = "ztf.h",
		.outputName = "Ztf",
		.outputFileName = "Ztf.zig",
	};
	const header_src_path = try std.fs.path.join(b.allocator, &.{ "glue", h.headerName});
	defer b.allocator.free(header_src_path);
	const translateCOfHeader = b.addTranslateC(.{
		.root_source_file = .{ .path = header_src_path },
		.target = target,
		.optimize = optimize,
	});
	if(target.result.os.tag == .windows)
	{
		translateCOfHeader.defineCMacroRaw("_WINDOWS=");
	}
	translateCOfHeader.step.dependOn(&ztf.step);
	translateCOfHeader.step.dependOn(&translate_fixup_exe.step);

	const zig_file_output_path_no_ext = try std.fs.path.join(b.allocator,&.{ "ZTF/", h.outputName});
	defer b.allocator.free(zig_file_output_path_no_ext);
	const zig_file_output_path = try std.mem.concat(b.allocator, u8, &.{zig_file_output_path_no_ext, ".zig"});
	defer b.allocator.free(zig_file_output_path);
	const zig_file_name = try std.mem.concat(b.allocator, u8, &.{h.outputName, ".zig"});
	defer b.allocator.free(zig_file_name);

	const translate_fixup_run = b.addRunArtifact(translate_fixup_exe);
	_ = translate_fixup_run.addFileArg(translateCOfHeader.getOutput());
	//zig_file_name
	const copied_translate = translate_fixup_run.addOutputFileArg(h.outputFileName);
	translate_fixup_run.step.dependOn(&translateCOfHeader.step);

	const installFile = b.addInstallFile(copied_translate, zig_file_output_path);
	const translated_module = b.addModule(h.outputName, .{
		.target = target,
		.optimize = optimize,
		.root_source_file = copied_translate,
	});
	_ = &translated_module;

	const ztf_module = b.addModule("ztf", .{
		.target = target,
		.optimize = optimize,
		.root_source_file = copied_translate,
	});
	_ = &ztf_module;

	installFile.step.dependOn(&translate_fixup_run.step);
	translate_ztf_step.dependOn(&installFile.step);
	translate_ztf_step.dependOn(&translate_fixup_run.step);

	{
		const api_files_to_verify = [_][]const u8{
			"../../../../dep/ztf/src/dep/common/tfalias/Common_3/Graphics/Interfaces/IGraphics.h",
			"../../../../dep/ztf/src/dep/common/tfalias/Common_3/Graphics/Interfaces/IRay.h",
			"../../../../dep/ztf/src/dep/common/tfalias/Common_3/Application/Interfaces/IApp.h",
			"../../../../dep/ztf/src/dep/common/tfalias/Common_3/Application/Interfaces/ICameraController.h",
			"../../../../dep/ztf/src/dep/common/tfalias/Common_3/Application/Interfaces/IFont.h",
			"../../../../dep/ztf/src/dep/common/tfalias/Common_3/Application/Interfaces/IInput.h",
			"../../../../dep/ztf/src/dep/common/tfalias/Common_3/Application/Interfaces/IMiddleware.h",
			"../../../../dep/ztf/src/dep/common/tfalias/Common_3/Application/Interfaces/IProfiler.h",
			"../../../../dep/ztf/src/dep/common/tfalias/Common_3/Application/Interfaces/IScreenshot.h",
			"../../../../dep/ztf/src/dep/common/tfalias/Common_3/Application/Interfaces/IUI.h",
			"../../../../dep/ztf/src/dep/common/tfalias/Common_3/OS/Interfaces/IOperatingSystem.h",
			"../../../../dep/ztf/src/dep/common/tfalias/Common_3/Renderer/Interfaces/IVisibilityBuffer.h",
			"../../../../dep/ztf/src/dep/common/tfalias/Common_3/Resources/ResourceLoader/Interfaces/IResourceLoader.h",
			"../../../../dep/ztf/src/dep/common/tfalias/Common_3/Utilities/Interfaces/ITime.h",
			"../../../../dep/ztf/src/dep/common/tfalias/Common_3/Utilities/Interfaces/IFileSystem.h",
			"../../../../dep/ztf/src/dep/common/tfalias/Common_3/Utilities/Interfaces/ILog.h",
			"../../../../dep/ztf/src/dep/common/tfalias/Common_3/Utilities/Interfaces/IMemory.h",
			"../../../../dep/ztf/src/dep/common/tfalias/Common_3/Utilities/Interfaces/IThread.h",
		};

		const capi_verifier = b.addSystemCommand(&.{
			"toolchain/bin/CAPID_V.exe"
		});

		for(api_files_to_verify) |input_filename|
		{
			_ = capi_verifier.addPrefixedFileArg("inputFile=", .{ .path = input_filename} );
		}

		const clang_args = [_][]const u8{
			"clang_arg=--include-directory=../../../../dep/ztf/src/dep/common/tfalias/Common_3/Application/Interfaces",
			"clang_arg=-target",
			"clang_arg=x86_64-pc-windows-msvc",
			"clang_arg=-D_WINDOWS",
			"clang_arg=-x",
			"clang_arg=c++",
			"clang_arg=-D_CRT_USE_BUILTIN_OFFSETOF",
		};
		for(clang_args) |clang_arg|
		{
			_ = capi_verifier.addArg(clang_arg);
		}

		const assert_filename = "ztf_bind_verify_1_57.cpp";
		const generated_assert_file = capi_verifier.addPrefixedOutputFileArg("outputFile=", assert_filename);
		const install_generated_file = b.addInstallFile(generated_assert_file, "assert_file/"++assert_filename);

		const generate_verifier_step = b.step("generate_verifier", "Generate a source file full of assertions for the current version.");
		generate_verifier_step.dependOn(&capi_verifier.step);
		generate_verifier_step.dependOn(&install_generated_file.step);
	
		const verify_step = b.step("verify", "Compile the verifier files.");

		const assertion_object = b.addObject(.{
			.name = "main",
			.target = target,
			.optimize = optimize,
		});
		assertion_object.addCSourceFile(.{
			.file = .{ .path = "verify/ztf_bind_verify.cpp" },
			.flags = &.{
				"--include-directory=../../../../dep/ztf/src/dep/common/tfalias",
				"-Wno-unused-command-line-argument",
				"-Werror=return-type",
				"-std=c++20",
			}
		});
		assertion_object.linkLibC();
		verify_step.dependOn(&assertion_object.step);
	}
}