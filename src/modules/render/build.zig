const std = @import("std");
const fmt = std.fmt;
const ztf = @import("ztf");

const BuildError = error{CouldNotResolveBuildDir};

pub fn build(b: *std.Build) !void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

	const ztf_pkg = b.dependency("ztf", .{
		.target = target,
		.optimize = optimize
	});

    const lun_render_module = b.addModule("lun_render", .{
		.target = target,
        .optimize = optimize,
		.root_source_file = .{ .path = "lun_render.zig"},
	});
	lun_render_module.addImport("ztf", ztf_pkg.module("ztf"));
}