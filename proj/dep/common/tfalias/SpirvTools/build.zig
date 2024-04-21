const std = @import("std");
const alias_build_util = @import("alias_build_util");

const BuildError = error{CouldNotResolveBuildDir};

pub fn build_as_lib(
	b: *std.Build,
	target: std.Build.ResolvedTarget,
	optimize: std.builtin.OptimizeMode,
) !*std.Build.Step.Compile 
{
	var tf_alias_dir = try alias_build_util.getTFAliasDirectory(b.allocator);
	defer tf_alias_dir.close();

    const statlib = b.addStaticLibrary
    (.{
        .name = "tfalias_spirvtools",
        .target = target,
        .optimize = optimize
    });
    statlib.linkLibC();

	const spirvtools_include_dir = try std.fs.path.join(b.allocator, &.{tf_alias_dir.str, "Common_3/Application/ThirdParty/OpenSource/gainput/lib/include"});
	defer b.allocator.free(spirvtools_include_dir);
	statlib.addIncludePath(.{.path = spirvtools_include_dir});

	const file_sub_paths_cpp : []const []const u8 = &.{
		"/Common_3/Graphics/ThirdParty/OpenSource/SPIRV_Cross/SpirvTools.cpp",
		"/Common_3/Graphics/ThirdParty/OpenSource/SPIRV_Cross/spirv_cfg.cpp",
		"/Common_3/Graphics/ThirdParty/OpenSource/SPIRV_Cross/spirv_cpp.cpp",
		"/Common_3/Graphics/ThirdParty/OpenSource/SPIRV_Cross/spirv_cross.cpp",
		"/Common_3/Graphics/ThirdParty/OpenSource/SPIRV_Cross/spirv_cross_parsed_ir.cpp",
		"/Common_3/Graphics/ThirdParty/OpenSource/SPIRV_Cross/spirv_cross_util.cpp",
		"/Common_3/Graphics/ThirdParty/OpenSource/SPIRV_Cross/spirv_glsl.cpp",
		"/Common_3/Graphics/ThirdParty/OpenSource/SPIRV_Cross/spirv_hlsl.cpp",
		"/Common_3/Graphics/ThirdParty/OpenSource/SPIRV_Cross/spirv_msl.cpp",
		"/Common_3/Graphics/ThirdParty/OpenSource/SPIRV_Cross/spirv_parser.cpp",
		"/Common_3/Graphics/ThirdParty/OpenSource/SPIRV_Cross/spirv_reflect.cpp",
	};

	try alias_build_util.addCSourceFiles(
		b,
		statlib,
		file_sub_paths_cpp,
		tf_alias_dir.str,
		&.{
			"-Wno-unused-command-line-argument",
            "-fno-sanitize=undefined"
		}
	);

    return statlib;
}

pub fn build(b: *std.Build) !void
{
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const tfalias_spirvtools_statlib = try build_as_lib(b, target, optimize);
	b.installArtifact(tfalias_spirvtools_statlib);
}