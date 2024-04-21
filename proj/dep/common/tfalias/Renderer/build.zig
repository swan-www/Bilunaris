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
        .name = "tfalias_renderer",
        .target = target,
        .optimize = optimize
    });
    statlib.linkLibC();

	const file_sub_paths_cpp : []const []const u8 = &.{
		"/Common_3/Graphics/CommonShaderReflection.cpp",
		"/Common_3/Graphics/Direct3D11/Direct3D11.cpp" ,
		"/Common_3/Graphics/Direct3D11/Direct3D11ShaderReflection.cpp" ,
		"/Common_3/Graphics/Direct3D12/Direct3D12.cpp" ,
		"/Common_3/Graphics/Direct3D12/Direct3D12Hooks.cpp" ,
		"/Common_3/Graphics/Direct3D12/Direct3D12Raytracing.cpp" ,
		"/Common_3/Graphics/Direct3D12/Direct3D12ShaderReflection.cpp" ,
		"/Common_3/Graphics/GraphicsConfig.cpp" ,
		"/Common_3/Graphics/PickRenderingApi.cpp" ,
		"/Common_3/Graphics/Vulkan/Vulkan.cpp" ,
		"/Common_3/Graphics/Vulkan/VulkanRaytracing.cpp" ,
		"/Common_3/Graphics/Vulkan/VulkanShaderReflection.cpp" ,
		"/Common_3/Renderer/VisibilityBuffer/VisibilityBuffer.cpp" ,
		"/Common_3/Resources/ResourceLoader/ResourceLoader.cpp" ,
		"/Common_3/Tools/ReloadServer/ReloadClient.cpp" ,
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

	const file_sub_paths_c : []const []const u8 = &.{
		"Common_3/Tools/Network/Network.c"
	};

	try alias_build_util.addCSourceFiles(
		b,
		statlib,
		file_sub_paths_c,
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

    const tfalias_renderer_statlib = try build_as_lib(b, target, optimize);
	b.installArtifact(tfalias_renderer_statlib);
}