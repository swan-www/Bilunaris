const std = @import("std");
const fmt = std.fmt;
const alias_build_util = @import("alias");
const tfalias = @import("tfalias");
const ztf = @import("ztf");

const BuildError = error{CouldNotResolveBuildDir};

pub fn build(b: *std.Build) !void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const exe = b.addExecutable(.{
        .name = "main",
        .target = target,
        .optimize = optimize,
		.root_source_file = .{ .path = "../../../src/test/01_transformations/main.zig" },
    });
    exe.linkLibC();
	b.installArtifact(exe);

	var tfalias_dir = try alias_build_util.getTFAliasDirectory(b.allocator);
	defer tfalias_dir.close();

	const tfalias_example_directory = try std.fs.path.join(b.allocator, &.{tfalias_dir.str, "Examples_3/Unit_Tests/src/01_Transformations"});
	defer b.allocator.free(tfalias_example_directory);
	const ztf_build = b.dependency("ztf", .{
        .target = target,
        .optimize = optimize,
    });

	const ztf_pkg = b.dependency("ztf", .{
			.target = target,
			.optimize = optimize
	});
	
	exe.root_module.addImport("ztf", ztf_pkg.module("ztf"));
	for (ztf.ztf_headers) |h| 
	{
		exe.root_module.addImport(h.outputName, ztf_pkg.module(h.outputName));
	}

	exe.linkLibrary(ztf_build.artifact("tfalias_gainput"));
	exe.linkLibrary(ztf_build.artifact("tfalias_os"));
	exe.linkLibrary(ztf_build.artifact("tfalias_renderer"));
	exe.linkLibrary(ztf_build.artifact("tfalias_spirvtools"));
	exe.linkLibrary(ztf_build.artifact("ztf"));
	//Links required engine dependency libs, and installs required shared libraries.
	try tfalias.linkRequiredLibs(b, &target, optimize, exe);

	const compile_shaders_step = b.step("compile-shaders", "Compiles the shaders associated with this application");
	b.getInstallStep().dependOn(compile_shaders_step);

	const tfalias_example_shader_directory = try std.fs.path.join(b.allocator, &.{tfalias_example_directory, "Shaders"});
	defer b.allocator.free(tfalias_example_shader_directory);

	const tfalias_os_font_shader_dir = try std.fs.path.join(b.allocator, &.{tfalias_dir.str, "Common_3/Application/Fonts/Shaders"});
	defer b.allocator.free(tfalias_os_font_shader_dir);

	const tfalias_os_ui_shader_dir = try std.fs.path.join(b.allocator, &.{tfalias_dir.str, "Common_3/Application/UI/Shaders"});
	defer b.allocator.free(tfalias_os_ui_shader_dir);

	const tfalias_os_animation_shader_dir = try std.fs.path.join(b.allocator, &.{tfalias_dir.str, "Common_3/Resources/AnimationSystem/Animation/Shaders"});
	defer b.allocator.free(tfalias_os_animation_shader_dir);

	const tfalias_os_panini_projection_shader_dir = try std.fs.path.join(b.allocator, &.{tfalias_dir.str, "Middleware_3/PaniniProjection/Shaders"});
	defer b.allocator.free(tfalias_os_panini_projection_shader_dir);

	const shader_comp_entry : []const tfalias.ShaderCompEntry = &.{
		.{ .source_base_path = tfalias_example_shader_directory, .subpath = "FSL/ShaderList.fsl"},
		.{ .source_base_path = tfalias_os_font_shader_dir, .subpath = "FSL/Fonts_ShaderList.fsl"},
		.{ .source_base_path = tfalias_os_ui_shader_dir, .subpath = "FSL/UI_ShaderList.fsl"},
		.{ .source_base_path = tfalias_os_animation_shader_dir, .subpath = "FSL/Animation_ShaderList.fsl"},
		.{ .source_base_path = tfalias_os_panini_projection_shader_dir, .subpath = "FSL/Panini_ShaderList.fsl"},
	};

	const intermediate_directory = try std.fs.path.join(b.allocator, &.{b.cache_root.path.?, "shader_intermediate"});
	defer b.allocator.free(intermediate_directory);

	try tfalias.compileShaders(
		.{
			.b = b,
			.step = compile_shaders_step,
			.shader_files = shader_comp_entry,
			.gfx_sdk_langs = &.{"VULKAN", "DIRECT3D11", "DIRECT3D12"},
			.output_intermediate_dir = intermediate_directory,
			.output_raw_sub_dir = "Shaders",
			.output_bin_sub_dir = "CompiledShaders",
			.max_output_bytes = 2000000,
			.code_reminder_opt = null,
		}
	);

	const copy_resources_step = b.step("copy-resources", "Copies the resources associated with this application to the output directory.");
	b.getInstallStep().dependOn(copy_resources_step);

	const tfalias_unit_test_resources_directory = try std.fs.path.join(b.allocator, &.{tfalias_dir.str, "Examples_3/Unit_Tests/UnitTestResources"});
	defer b.allocator.free(tfalias_unit_test_resources_directory);

	const Kind = std.fs.File.Kind;

	const resource_copy_targets : []const tfalias.CopyResourceTarget = &.{
		.{ .kind = Kind.file, .source_path_relative = "Textures/dds/Skybox_front5.tex", .output_subpath = "Textures/Skybox_front5.tex", .source_path_base = tfalias_unit_test_resources_directory},
		.{ .kind = Kind.file, .source_path_relative = "Textures/dds/Skybox_left2.tex", .output_subpath = "Textures/Skybox_left2.tex", .source_path_base = tfalias_unit_test_resources_directory},
		.{ .kind = Kind.file, .source_path_relative = "Textures/dds/Skybox_right1.tex", .output_subpath = "Textures/Skybox_right1.tex", .source_path_base = tfalias_unit_test_resources_directory},
		.{ .kind = Kind.file, .source_path_relative = "Textures/dds/Skybox_top3.tex", .output_subpath = "Textures/Skybox_top3.tex", .source_path_base = tfalias_unit_test_resources_directory},
		.{ .kind = Kind.file, .source_path_relative = "Textures/dds/Skybox_back6.tex", .output_subpath = "Textures/Skybox_back6.tex", .source_path_base = tfalias_unit_test_resources_directory},
		.{ .kind = Kind.file, .source_path_relative = "Textures/dds/Skybox_bottom4.tex", .output_subpath = "Textures/Skybox_bottom4.tex", .source_path_base = tfalias_unit_test_resources_directory},

		.{ .kind = Kind.file, .source_path_relative = "Textures/dds/circlepad.tex", .output_subpath = "Textures/circlepad.tex", .source_path_base = tfalias_unit_test_resources_directory},

		.{ .kind = Kind.directory, .source_path_relative = "Fonts", .output_subpath = "Fonts", .include_extensions = &.{".ttf"}, .source_path_base = tfalias_unit_test_resources_directory},
		.{ .kind = Kind.directory, .source_path_relative = "Fonts", .output_subpath = "Fonts", .include_extensions = &.{".otf"}, .source_path_base = tfalias_unit_test_resources_directory},

		.{ .kind = Kind.directory, .source_path_relative = "Scripts", .output_subpath = "Scripts", .include_extensions = &.{".lua"}, .source_path_base = tfalias_unit_test_resources_directory},

		.{ .kind = Kind.file, .source_path_relative = "Common_3/OS/Windows/pc_gpu.data", .output_subpath = "GPUCfg/gpu.data", .source_path_base = tfalias_dir.str},
		.{ .kind = Kind.file, .source_path_relative = "GPUCfg/gpu.cfg", .output_subpath = "GPUCfg/gpu.cfg", .source_path_base = tfalias_example_directory},
	};

	try tfalias.copyResources(.{
		.b = b,
		.step = compile_shaders_step,
		.resource_targets = resource_copy_targets,
	});
}