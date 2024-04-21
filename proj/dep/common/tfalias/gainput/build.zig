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
        .name = "tfalias_gainput",
        .target = target,
        .optimize = optimize
    });
    statlib.linkLibC();

	const gainput_include_dir = try std.fs.path.join(b.allocator, &.{tf_alias_dir.str, "Common_3/Application/ThirdParty/OpenSource/gainput/lib/include"});
	defer b.allocator.free(gainput_include_dir);
	statlib.addIncludePath(.{.path = gainput_include_dir});

	const file_sub_paths_cpp : []const []const u8 = &.{
		"/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/GainputAllocator.cpp",
		"/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/GainputInputDeltaState.cpp",
		"/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/GainputInputDevice.cpp",
		"/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/GainputInputManager.cpp",
		"/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/GainputInputMap.cpp",
		"/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/GainputInputState.cpp",
		"/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/GainputMapFilters.cpp",
		"/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/builtin/GainputInputDeviceBuiltIn.cpp",
		"/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/dev/GainputDev.cpp",
		"/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/dev/GainputMemoryStream.cpp",
		"/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/gainput.cpp",
		"/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/gestures/GainputButtonStickGesture.cpp",
		"/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/gestures/GainputDoubleClickGesture.cpp",
		"/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/gestures/GainputHoldGesture.cpp",
		"/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/gestures/GainputPinchGesture.cpp",
		"/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/gestures/GainputRotateGesture.cpp",
		"/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/gestures/GainputSimultaneouslyDownGesture.cpp",
		"/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/gestures/GainputTapGesture.cpp",
		"/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/keyboard/GainputInputDeviceKeyboard.cpp",
		"/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/mouse/GainputInputDeviceMouse.cpp",
		"/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/pad/GainputInputDevicePad.cpp",
		"/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/recorder/GainputInputPlayer.cpp",
		"/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/recorder/GainputInputRecorder.cpp",
		"/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/recorder/GainputInputRecording.cpp",
		"/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/touch/GainputInputDeviceTouch.cpp",
		"/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/hid/GainputHID.cpp",
		"/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/hid/GainputHIDWhitelist.cpp",
		"/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/hid/hidparsers/HIDParserPS4Controller.cpp",
		"/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/hid/hidparsers/HIDParserPS5Controller.cpp",
		"/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/hid/hidparsers/HIDParserSwitchController.cpp",
	};

	try alias_build_util.addCSourceFiles(
		b,
		statlib,
		file_sub_paths_cpp,
		tf_alias_dir.str,
		&.{
			"-Wno-unused-command-line-argument",
			"-Wno-enum-compare",
			"-Wno-unused-value",
            "-fno-sanitize=undefined"
		}
	);

	const file_sub_paths_c : []const []const u8 = &.{
		"/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/hidapi/windows/hid.c",	
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

    const tfalias_gainput_statlib = try build_as_lib(b, target, optimize);
	b.installArtifact(tfalias_gainput_statlib);
}