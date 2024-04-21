const std = @import("std");
const alias_build_util = @import("alias_build_util");

const BuildError = error{CouldNotResolveBuildDir};

pub fn build(b: *std.Build) !void {
    const target = b.standardTargetOptions(.{});
    const optimization = b.standardOptimizeOption(.{});

	const build_file = @src().file;
	const build_dir = std.fs.path.dirname(build_file) orelse return BuildError.CouldNotResolveBuildDir;

    const exe = b.addExecutable(.{
        .name = "main",
        .target = target,
        .optimize = optimization,
    });
    exe.linkLibC();

	var alias_src_dir = try alias_build_util.getAliasSrcDirectory(b.allocator);
	defer alias_src_dir.close();

    const hello_world_src_dir = try std.fs.path.join(b.allocator, &.{alias_src_dir.str, "demo/hello_world"});
	defer b.allocator.free(hello_world_src_dir);

	const file_sub_paths : []const []const u8 = &.{
		"main.cpp"
	};

	var relative_src_paths = std.ArrayList([]const u8).init(b.allocator);
	defer {
		for(relative_src_paths.items) |ele|
		{
			b.allocator.free(ele);
		}
	}
	for (file_sub_paths) |pt| {
		const abs_path = try std.fs.path.join(b.allocator, &.{hello_world_src_dir, pt});
		try relative_src_paths.append(try std.fs.path.relative(b.allocator, build_dir, abs_path));
	}

    exe.addCSourceFiles(.{
        .files = relative_src_paths.items,
        .flags = &.{},
    });

    b.installArtifact(exe);
}