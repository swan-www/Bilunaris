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
        .name = "tfalias_os",
        .target = target,
        .optimize = optimize
    });
    statlib.linkLibC();

	const file_sub_paths_cpp : []const []const u8 = &.{
		"/Common_3/Application/CameraController.cpp",
        "/Common_3/Application/InputSystem.cpp",
        "/Common_3/Application/Profiler/GpuProfiler.cpp",
        "/Common_3/Application/Profiler/ProfilerBase.cpp",
        "/Common_3/Application/RemoteControl.cpp",
        "/Common_3/Application/Screenshot.cpp",
        "/Common_3/Application/ThirdParty/OpenSource/imgui/imgui.cpp",
        "/Common_3/Application/ThirdParty/OpenSource/imgui/imgui_demo.cpp",
        "/Common_3/Application/ThirdParty/OpenSource/imgui/imgui_draw.cpp",
        "/Common_3/Application/ThirdParty/OpenSource/imgui/imgui_widgets.cpp",
        "/Common_3/Application/ThirdParty/OpenSource/imgui/imgui_tables.cpp",
        "/Common_3/Application/UI/UI.cpp",
        "/Common_3/Game/Scripting/LuaManager.cpp",
        "/Common_3/Game/Scripting/LuaManagerImpl.cpp",
        "/Common_3/Game/Scripting/LuaSystem.cpp",
        "/Common_3/Application/Fonts/FontSystem.cpp",
        "/Common_3/Application/Fonts/stbtt.cpp",
        "/Common_3/OS/CPUConfig.cpp",
        "/Common_3/OS/WindowSystem/WindowSystem.cpp",
        "/Common_3/Utilities/ThirdParty/OpenSource/rmem/src/rmem_get_module_info.cpp",
        "/Common_3/Utilities/ThirdParty/OpenSource/rmem/src/rmem_hook.cpp",
        "/Common_3/Utilities/ThirdParty/OpenSource/rmem/src/rmem_lib.cpp",
        "/Common_3/OS/Windows/WindowsBase.cpp",
        "/Common_3/OS/Windows/WindowsFileSystem.cpp",
        "/Common_3/OS/Windows/WindowsStackTraceDump.cpp",
        "/Common_3/OS/Windows/WindowsWindow.cpp",
        "/Common_3/Resources/AnimationSystem/Animation/AnimatedObject.cpp",
        "/Common_3/Resources/AnimationSystem/Animation/Animation.cpp",
        "/Common_3/Resources/AnimationSystem/Animation/Clip.cpp",
        "/Common_3/Resources/AnimationSystem/Animation/ClipController.cpp",
        "/Common_3/Resources/AnimationSystem/Animation/ClipMask.cpp",
        "/Common_3/Resources/AnimationSystem/Animation/Rig.cpp",
        "/Common_3/Resources/AnimationSystem/Animation/SkeletonBatcher.cpp",
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
		"/Common_3/OS/Windows/WindowsThread.c",
        "/Common_3/OS/Windows/WindowsTime.c",
        "/Common_3/OS/Windows/WindowsLog.c",
		"/Common_3/Utilities/ThirdParty/OpenSource/zstd/common/debug.c",
        "/Common_3/Utilities/ThirdParty/OpenSource/zstd/common/entropy_common.c",
        "/Common_3/Utilities/ThirdParty/OpenSource/zstd/common/error_private.c",
        "/Common_3/Utilities/ThirdParty/OpenSource/zstd/common/fse_decompress.c",
        "/Common_3/Utilities/ThirdParty/OpenSource/zstd/common/pool.c",
        "/Common_3/Utilities/ThirdParty/OpenSource/zstd/common/threading.c",
        "/Common_3/Utilities/ThirdParty/OpenSource/zstd/common/xxhash.c",
        "/Common_3/Utilities/ThirdParty/OpenSource/zstd/common/zstd_common.c",
        "/Common_3/Utilities/ThirdParty/OpenSource/zstd/decompress/huf_decompress.c",
        "/Common_3/Utilities/ThirdParty/OpenSource/zstd/decompress/zstd_ddict.c",
        "/Common_3/Utilities/ThirdParty/OpenSource/zstd/decompress/zstd_decompress.c",
        "/Common_3/Utilities/ThirdParty/OpenSource/zstd/decompress/zstd_decompress_block.c",
        "/Common_3/Utilities/Threading/ThreadSystem.c",
        "/Common_3/Utilities/Timer.c",
		"/Common_3/Utilities/FileSystem/FileSystem.c",
        "/Common_3/Utilities/FileSystem/SystemRun.c",
        "/Common_3/Utilities/Log/Log.c",
        "/Common_3/Utilities/Math/Algorithms.c",
        "/Common_3/Utilities/Math/StbDs.c",
        "/Common_3/Utilities/MemoryTracking/MemoryTracking.c",
        "/Common_3/Utilities/ThirdParty/OpenSource/bstrlib/bstrlib.c",
        "/Common_3/Utilities/ThirdParty/OpenSource/lz4/lz4.c",
		"/Common_3/OS/ThirdParty/OpenSource/cpu_features/src/impl_x86_windows.c",
		"/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lapi.c",
        "/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lauxlib.c",
        "/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lbaselib.c",
        "/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lbitlib.c",
        "/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lcode.c",
        "/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lcorolib.c",
        "/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lctype.c",
        "/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/ldblib.c",
        "/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/ldebug.c",
        "/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/ldo.c",
        "/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/ldump.c",
        "/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lfunc.c",
        "/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lgc.c",
        "/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/linit.c",
        "/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/liolib.c",
        "/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/llex.c",
        "/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lmathlib.c",
        "/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lmem.c",
        "/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/loadlib.c",
        "/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lobject.c",
        "/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lopcodes.c",
        "/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/loslib.c",
        "/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lparser.c",
        "/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lstate.c",
        "/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lstring.c",
        "/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lstrlib.c",
        "/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/ltable.c",
        "/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/ltablib.c",
        "/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/ltm.c",
        "/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lundump.c",
        "/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lutf8lib.c",
        "/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lvm.c",
        "/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lzio.c",
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

    const tfalias_os_statlib = try build_as_lib(b, target, optimize);
	b.installArtifact(tfalias_os_statlib);
}