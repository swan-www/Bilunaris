const std = @import("std");
const alias_build_util = @import("alias_build_util");
const code_reminder_build = @import("code_reminder");
const code_reminder = code_reminder_build.code_reminder;

//Type shortening
const Dir = alias_build_util.Dir;
const File = alias_build_util.File;

pub const CodeReminderErrors = error
{
	AllowReturningErrorWithValue
};

pub const CodeReminders = struct
{
	AllowReturningErrorWithValue: code_reminder.CodeReminder,

	pub fn init(options: code_reminder.CodeReminderOptions) CodeReminders
	{
		return  .{
			.AllowReturningErrorWithValue = code_reminder.CodeReminder.buildInit(options, 2647, CodeReminderErrors.AllowReturningErrorWithValue),
		};
	}
};

const GetPathErrors = error{ OutOfMemory, NotFound, PathTooLong, PlatformNotSupported } || std.mem.Allocator.Error;

const SDKDescription = struct
{
    path: []const u8,
    version: []const u8,

    pub fn free(self: *const SDKDescription, allocator: std.mem.Allocator) void
    {
        allocator.free(self.path);
        allocator.free(self.version);
    }
};

//Caller owns the field's results
pub fn getWinSDKDesc(host : std.Target, allocator : std.mem.Allocator) GetPathErrors!SDKDescription
{
    const WinFunc = struct
    {
        pub fn getWinSDKDesc(in_allocator : std.mem.Allocator) GetPathErrors!SDKDescription
        {
            const win_sdk = try std.zig.WindowsSdk.find(in_allocator);
            defer win_sdk.free(in_allocator);

            var sdk_desc : SDKDescription = .{ .path = &.{}, .version = &.{}};

            if(win_sdk.windows10sdk) |sdk|
            {
                sdk_desc.path = try in_allocator.dupe(u8, sdk.path);
                errdefer { in_allocator.free(sdk_desc.path); }
                sdk_desc.version = try in_allocator.dupe(u8, sdk.version);
                errdefer { in_allocator.free(sdk_desc.version); }

                return sdk_desc;
            }
            else if(win_sdk.windows10sdk) |sdk|
            {
                sdk_desc.path = try in_allocator.dupe(u8, sdk.path);
                errdefer { in_allocator.free(sdk_desc.path); }
                sdk_desc.version = try in_allocator.dupe(u8, sdk.version);
                errdefer { in_allocator.free(sdk_desc.version); }

               return sdk_desc;
            }
            else
            {
                return GetPathErrors.NotFound;
            }
        }
    };

    switch(host.os.tag)
    {
        .windows => return WinFunc.getWinSDKDesc(allocator),
        else => return GetPathErrors.PlatformNotSupported
    }
}

pub fn getFXCDir(host : std.Target, allocator : std.mem.Allocator) !Dir
{
    const WinFunc = struct
    {
        pub fn getFXCDir(in_host : std.Target, in_allocator : std.mem.Allocator) !Dir
        {
            const win_sdk_desc = try getWinSDKDesc(in_host, in_allocator);
            defer win_sdk_desc.free(in_allocator);       

			return alias_build_util.buildAbsolutePathAndGetDirectory(
				in_allocator,
				&.{
					win_sdk_desc.path,
					"bin",
					win_sdk_desc.version,
					switch(in_host.cpu.arch)
                    {
                        .x86_64 => "x64",
                        else => return GetPathErrors.PlatformNotSupported
                    }
				},
				null
			);
        }
    };

    switch(host.os.tag)
    {
        .windows => return WinFunc.getFXCDir(host, allocator),
        else => return GetPathErrors.PlatformNotSupported
    }
}

pub fn getDXCDir(host: std.Target, allocator : std.mem.Allocator) !Dir
{
    const WinFunc = struct
    {
        pub fn getDXCDir(in_host: std.Target,in_allocator : std.mem.Allocator) !Dir
        {
			const dxc_sub_path = try std.mem.join(
                in_allocator,
				"",
                &.{
                    "Common_3/Graphics/ThirdParty/OpenSource/DirectXShaderCompiler/bin/",
                    switch(in_host.cpu.arch)
                    {
                        .x86_64 => "x64",
                        else => return GetPathErrors.PlatformNotSupported
                    },
                }
            );
			defer in_allocator.free(dxc_sub_path);

			var tfalias_dir = try alias_build_util.getTFAliasDirectory(in_allocator);
			defer tfalias_dir.close();

			return alias_build_util.getDirAsSubpathFromDir(tfalias_dir, in_allocator, dxc_sub_path, null);
        }
    };

    switch(host.os.tag)
    {
        .windows => return WinFunc.getDXCDir(host, allocator),
        else => return GetPathErrors.PlatformNotSupported
    }
}

pub fn getPythonExecutableFile(allocator : std.mem.Allocator) !File
{
    var tfalias_dir = try alias_build_util.getTFAliasDirectory(allocator);
	defer tfalias_dir.close();
	var python_exe_dir = try alias_build_util.getDirAsSubpathFromDir(tfalias_dir, allocator, "Tools/python-3.6.0-embed-amd64/", null);
	defer python_exe_dir.close();
	return python_exe_dir.openFile(allocator, "python.exe", .{});
}

pub fn getFSLDir(allocator : std.mem.Allocator) !Dir
{
	var tfalias_dir = try alias_build_util.getTFAliasDirectory(allocator);
	defer tfalias_dir.close();
	return alias_build_util.getDirAsSubpathFromDir(tfalias_dir, allocator, "Common_3/Tools/ForgeShadingLanguage", null);
}

pub fn getFSLPyFile(allocator : std.mem.Allocator) !File
{
	var fsl_dir = try getFSLDir(allocator);
	defer fsl_dir.close();
	return fsl_dir.openFile(allocator, "fsl.py", .{});
}

pub const ShaderCompEntry = struct {
	source_base_path: []const u8,
	subpath: []const u8,
};

const CompileShadersOptions = struct
{
    b: *std.Build,
	step: *std.Build.Step,
    shader_files: []const ShaderCompEntry,
    gfx_sdk_langs: []const []const u8,
    output_intermediate_dir: []const u8,
	output_raw_sub_dir: []const u8,
	output_bin_sub_dir: []const u8,
	max_output_bytes: usize,
	code_reminder_opt: ?code_reminder.CodeReminderOptions,
};

pub fn compileShaders(options: CompileShadersOptions) !void
{
	var fxc_dir = try getFXCDir(options.b.host.result, options.b.allocator);
    defer fxc_dir.close();
    var dxc_dir = try getDXCDir(options.b.host.result, options.b.allocator);
   	defer dxc_dir.close();

    var python_exe = try getPythonExecutableFile(options.b.allocator);
    defer python_exe.close();
    const language_string = try std.mem.join(options.b.allocator, " ", options.gfx_sdk_langs);
    defer options.b.allocator.free(language_string);

	var fsl_py_file = try getFSLPyFile(options.b.allocator);
	defer fsl_py_file.close();

	const intermediate_shader_raw_directory = try std.fs.path.join(options.b.allocator, &.{options.output_intermediate_dir, options.output_raw_sub_dir});
	defer options.b.allocator.free(intermediate_shader_raw_directory);

	const intermediate_shader_bin_directory = try std.fs.path.join(options.b.allocator, &.{options.output_intermediate_dir, options.output_bin_sub_dir});
	defer options.b.allocator.free(intermediate_shader_bin_directory);

    for(options.shader_files) |shader_file|
    {
		const copy_shader_raw_to_output = options.b.addInstallDirectory(.{
			.source_dir = .{ .path = intermediate_shader_raw_directory },
			.install_subdir = options.output_raw_sub_dir,
			.install_dir = .{
				.bin = void{},
			},
		});

		options.step.dependOn(&copy_shader_raw_to_output.step);

		const copy_shader_binary_to_output = options.b.addInstallDirectory(.{
			.source_dir = .{ .path = intermediate_shader_bin_directory },
			.install_subdir = options.output_bin_sub_dir,
			.install_dir = .{
				.bin = void{},
			},
			.exclude_extensions = &.{".json"},
		});

		options.step.dependOn(&copy_shader_binary_to_output.step);

		const abs_shader_path = try std.fs.path.join(options.b.allocator, &.{shader_file.source_base_path, shader_file.subpath});
		defer options.b.allocator.free(abs_shader_path);
		const relative_shader_path = try std.fs.path.relative(options.b.allocator, options.b.build_root.path.?, abs_shader_path);
		defer options.b.allocator.free(relative_shader_path);

		const argv = &.{
                python_exe.str,
                fsl_py_file.str,
                relative_shader_path,
                "--destination",
                intermediate_shader_raw_directory,
                "--binaryDestination",
                intermediate_shader_bin_directory,
                "--language",
                language_string,
                "--incremental",
                "--compile",
                "--verbose",
				"--reloadServerPort",
				"6543",
				"--cache-args"
		};

		const fsl_py_run = options.b.addSystemCommand(argv);
		fsl_py_run.setEnvironmentVariable("FSL_COMPILER_FXC", fxc_dir.str);
		fsl_py_run.setEnvironmentVariable("FSL_COMPILER_DXC", dxc_dir.str);

		var shader_file_handle = try alias_build_util.File.open(
			options.b.allocator,
			abs_shader_path,
			.{},
		);
		defer shader_file_handle.close();

		const shader_directory_str = std.fs.path.dirname(shader_file_handle.str) orelse return GetPathErrors.NotFound;
		var shader_directory = try alias_build_util.buildAbsolutePathAndGetDirectory(options.b.allocator, &.{shader_directory_str}, .{.access_sub_paths = true, .iterate = true});
		defer shader_directory.close();

		var shader_compile_deps = std.ArrayList([]const u8).init(options.b.allocator);

		var iter = shader_directory.dir_handle.iterate();
		while(try iter.next()) |dir_content|
		{
			if(dir_content.kind != std.fs.File.Kind.file)
			{
				continue;
			}

			const dir_content_abs = try std.fs.path.join(options.b.allocator, &.{shader_directory.str, dir_content.name});
			defer options.b.allocator.free(dir_content_abs);

			if(!std.fs.path.isAbsolute(dir_content_abs))
			{
				std.debug.panic("Expected absolute path, found {s}", .{dir_content_abs});
			}

			const dir_content_relative = try std.fs.path.relative(options.b.allocator, options.b.build_root.path.?, dir_content_abs);
			defer options.b.allocator.free(dir_content_relative);

			try shader_compile_deps.append(dir_content_relative);
		}

		fsl_py_run.extra_file_dependencies = shader_compile_deps.items;

		copy_shader_binary_to_output.step.dependOn(&fsl_py_run.step);
		copy_shader_raw_to_output.step.dependOn(&fsl_py_run.step);
    }
}

pub const CopyResourceTarget = struct
{
	kind: std.fs.File.Kind,
	source_path_base: []const u8,
	source_path_relative: []const u8,
	output_subpath: []const u8,
	exclude_extensions: []const []const u8 = &.{},
	include_extensions: ?[]const []const u8 = null,
};

pub const CopyResourcesOptions = struct
{
    b: *std.Build,
	step: *std.Build.Step,
    resource_targets: []const CopyResourceTarget
};

pub const CopyResourcesError = error{IncorrectKind, UnsupportedKind};

pub fn copyResources(options: CopyResourcesOptions) !void
{
	const Implementation = struct {
		pub fn copyFile(b: *std.Build, in_resource_target: CopyResourceTarget) !*std.Build.Step
		{
			const abs_source_path = try std.fs.path.join(b.allocator, &.{in_resource_target.source_path_base, in_resource_target.source_path_relative});	

			if(in_resource_target.kind != std.fs.File.Kind.file)
			{
				return CopyResourcesError.IncorrectKind;
			}

			return &b.addInstallFileWithDir(
				std.Build.LazyPath{ .path = abs_source_path },
				std.Build.InstallDir{ .bin = void{}, },
				in_resource_target.output_subpath,
			).step;
		}

		pub fn copyDir(b: *std.Build, in_resource_target: CopyResourceTarget) !*std.Build.Step
		{
			const abs_source_path = try std.fs.path.join(b.allocator, &.{in_resource_target.source_path_base, in_resource_target.source_path_relative});	

			if(in_resource_target.kind != std.fs.File.Kind.directory)
			{
				return CopyResourcesError.IncorrectKind;
			}

			return &b.addInstallDirectory(.{
				.source_dir = .{ .path = abs_source_path },
				.install_subdir = in_resource_target.output_subpath,				
				.include_extensions = in_resource_target.include_extensions,
				.exclude_extensions = in_resource_target.exclude_extensions,
				.install_dir = .{
					.bin = void{},
				},
			}).step;
		}
	};

	for (options.resource_targets) |ele|
	{
		const copy_step = try switch(ele.kind)
		{
			std.fs.File.Kind.file => Implementation.copyFile(options.b, ele),
			std.fs.File.Kind.directory => Implementation.copyDir(options.b, ele),
			else => CopyResourcesError.UnsupportedKind,
		};

		options.step.dependOn(copy_step);
	}
}

const LinkError = error{UnsupportedTargetPlatform};

pub fn linkRequiredLibs(
	b: *std.Build,
	target: *const std.Build.ResolvedTarget,
	optimization: std.builtin.OptimizeMode,
	link_to: *std.Build.Step.Compile,
) !void
{
	const Implementation = struct{

		pub fn linkWindows(
			in_b: *std.Build,
			in_target: *const std.Build.ResolvedTarget,
			in_optimization: std.builtin.OptimizeMode,
			in_link_to: *std.Build.Step.Compile,
		) !void
		{
			_ = &in_optimization;
			const link_static_lib_options = std.Build.Module.LinkSystemLibraryOptions{.needed = true, .preferred_link_mode = .static};
			var tf_alias_dir = try alias_build_util.getTFAliasDirectory(in_b.allocator);
			defer tf_alias_dir.close();

			in_link_to.linkSystemLibrary2("Xinput9_1_0", link_static_lib_options);
			in_link_to.linkSystemLibrary2("ws2_32", link_static_lib_options);
			in_link_to.linkSystemLibrary2("gdi32", link_static_lib_options);
			in_link_to.linkSystemLibrary2("kernel32", link_static_lib_options);
			in_link_to.linkSystemLibrary2("winspool", link_static_lib_options);
			in_link_to.linkSystemLibrary2("comdlg32", link_static_lib_options);
			in_link_to.linkSystemLibrary2("advapi32", link_static_lib_options);
			in_link_to.linkSystemLibrary2("shell32", link_static_lib_options);
			in_link_to.linkSystemLibrary2("ole32", link_static_lib_options);
			in_link_to.linkSystemLibrary2("oleaut32", link_static_lib_options);
			in_link_to.linkSystemLibrary2("uuid", link_static_lib_options);
			in_link_to.linkSystemLibrary2("odbc32", link_static_lib_options);
			in_link_to.linkSystemLibrary2("odbccp32", link_static_lib_options);

			{
				const ags_archive_filename = try std.mem.join(in_b.allocator, "", &.{"amd_ags_x64", in_target.result.staticLibSuffix()});
				defer in_b.allocator.free(ags_archive_filename);
				const ags_archive_path = try std.fs.path.join(in_b.allocator, &[_][]const u8{tf_alias_dir.str, "Common_3/Graphics/ThirdParty/OpenSource/ags/ags_lib/lib", ags_archive_filename});
				defer in_b.allocator.free(ags_archive_path);
				in_link_to.addObjectFile(std.Build.LazyPath{.path = ags_archive_path});
			}

			{
				const nvapi_archive_filename = try std.mem.join(in_b.allocator, "", &.{"nvapi64", in_target.result.staticLibSuffix()});
				defer in_b.allocator.free(nvapi_archive_filename);
				const nvapi_archive_path = try std.fs.path.join(in_b.allocator, &[_][]const u8{tf_alias_dir.str, "Common_3/Graphics/ThirdParty/OpenSource/nvapi/amd64", nvapi_archive_filename});
				defer in_b.allocator.free(nvapi_archive_path);
				in_link_to.addObjectFile(std.Build.LazyPath{.path = nvapi_archive_path});
			}

			{
				const dxcompiler_archive_filename = try std.mem.join(in_b.allocator, "", &.{"dxcompiler", in_target.result.staticLibSuffix()});
				defer in_b.allocator.free(dxcompiler_archive_filename);
				const dxcompiler_archive_path = try std.fs.path.join(in_b.allocator, &[_][]const u8{tf_alias_dir.str, "Common_3/Graphics/ThirdParty/OpenSource/DirectXShaderCompiler/lib/x64", dxcompiler_archive_filename});
				defer in_b.allocator.free(dxcompiler_archive_path);
				in_link_to.addObjectFile(std.Build.LazyPath{.path = dxcompiler_archive_path});
			}

			{
				const winpixeventruntime_archive_filename = try std.mem.join(in_b.allocator, "", &.{"WinPixEventRuntime", in_target.result.staticLibSuffix()});
				defer in_b.allocator.free(winpixeventruntime_archive_filename);
				const winpixeventruntime_archive_path = try std.fs.path.join(in_b.allocator, &[_][]const u8{tf_alias_dir.str, "Common_3/OS/ThirdParty/OpenSource/winpixeventruntime/bin", winpixeventruntime_archive_filename});
				defer in_b.allocator.free(winpixeventruntime_archive_path);
				in_link_to.addObjectFile(std.Build.LazyPath{.path = winpixeventruntime_archive_path});
			}

			{
				const winpix_shared_lib_filename = try std.mem.join(in_b.allocator, "", &.{"WinPixEventRuntime", in_target.result.dynamicLibSuffix()});
				defer in_b.allocator.free(winpix_shared_lib_filename);
				const winpix_shared_lib_path = try std.fs.path.join(in_b.allocator, &[_][]const u8{
					tf_alias_dir.str,
					"Common_3/OS/ThirdParty/OpenSource/winpixeventruntime/bin",
					winpix_shared_lib_filename
				});
				defer in_b.allocator.free(winpix_shared_lib_path);

				const winpix_shared_lib_path_relative = try std.fs.path.relative(in_b.allocator, in_b.build_root.path.?, winpix_shared_lib_path);
				defer in_b.allocator.free(winpix_shared_lib_path_relative);

				in_b.installBinFile(winpix_shared_lib_path_relative, winpix_shared_lib_filename);
			}

			{
				const ags_shared_lib_filename = try std.mem.join(in_b.allocator, "", &.{"amd_ags_x64", in_target.result.dynamicLibSuffix()});
				defer in_b.allocator.free(ags_shared_lib_filename);
				const ags_shared_lib_path = try std.fs.path.join(in_b.allocator, &[_][]const u8{
					tf_alias_dir.str,
					"Common_3/Graphics/ThirdParty/OpenSource/ags/ags_lib/lib",
					ags_shared_lib_filename
				});
				defer in_b.allocator.free(ags_shared_lib_path);
				const ags_shared_lib_path_relative = try std.fs.path.relative(in_b.allocator, in_b.build_root.path.?, ags_shared_lib_path);
				defer in_b.allocator.free(ags_shared_lib_path_relative);

				in_b.installBinFile(ags_shared_lib_path_relative, ags_shared_lib_filename);
			}

			{
				const dxil_shared_lib_filename = try std.mem.join(in_b.allocator, "", &.{"dxil", in_target.result.dynamicLibSuffix()});
				defer in_b.allocator.free(dxil_shared_lib_filename);
				const dxil_shared_lib_path = try std.fs.path.join(in_b.allocator, &[_][]const u8{
					tf_alias_dir.str,
					"Common_3/Graphics/ThirdParty/OpenSource/DirectXShaderCompiler/bin/x64",
					dxil_shared_lib_filename
				});
				defer in_b.allocator.free(dxil_shared_lib_path);
				const dxil_shared_lib_path_relative = try std.fs.path.relative(in_b.allocator, in_b.build_root.path.?, dxil_shared_lib_path);
				defer in_b.allocator.free(dxil_shared_lib_path_relative);

				in_b.installBinFile(dxil_shared_lib_path_relative, dxil_shared_lib_filename);
			}

			{
				const dxcompiler_shared_lib_filename = try std.mem.join(in_b.allocator, "", &.{"dxcompiler", in_target.result.dynamicLibSuffix()});
				defer in_b.allocator.free(dxcompiler_shared_lib_filename);
				const dxcompiler_shared_lib_path = try std.fs.path.join(in_b.allocator, &[_][]const u8{
					tf_alias_dir.str,
					"Common_3/Graphics/ThirdParty/OpenSource/DirectXShaderCompiler/bin/x64",
					dxcompiler_shared_lib_filename
				});
				defer in_b.allocator.free(dxcompiler_shared_lib_path);
				const dxcompiler_shared_lib_path_relative = try std.fs.path.relative(in_b.allocator, in_b.build_root.path.?, dxcompiler_shared_lib_path);
				defer in_b.allocator.free(dxcompiler_shared_lib_path_relative);

				in_b.installBinFile(dxcompiler_shared_lib_path_relative, dxcompiler_shared_lib_filename);
			}
		}
	};

	return switch(target.result.os.tag)
	{
		.windows => Implementation.linkWindows(b, target, optimization, link_to),
		else => LinkError.UnsupportedTargetPlatform,
	};
}

pub fn build(b: *std.Build) !void
{
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const tfalias_os = b.dependency("tfalias_os", .{
        .target = target,
        .optimize = optimize,
    });
	b.installArtifact(tfalias_os.artifact("tfalias_os"));

	const tfalias_renderer = b.dependency("tfalias_renderer", .{
        .target = target,
        .optimize = optimize,
    });
	b.installArtifact(tfalias_renderer.artifact("tfalias_renderer"));

	const tfalias_gainput = b.dependency("tfalias_gainput", .{
        .target = target,
        .optimize = optimize,
    });
	b.installArtifact(tfalias_gainput.artifact("tfalias_gainput"));

	const tfalias_spirvtools = b.dependency("tfalias_spirvtools", .{
        .target = target,
        .optimize = optimize,
    });
	b.installArtifact(tfalias_spirvtools.artifact("tfalias_spirvtools"));
}