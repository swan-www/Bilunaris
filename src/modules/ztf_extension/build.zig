const std = @import("std");
const fmt = std.fmt;
const ztf = @import("ztf");

pub fn build(b: *std.Build) !void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

	const ztf_pkg = b.dependency("ztf", .{
		.target = target,
		.optimize = optimize
	});

    const ztf_ext_module = b.addModule("ztf_extension", .{
		.target = target,
        .optimize = optimize,
		.root_source_file = .{ .path = "ztf_ext.zig"},
	});
	ztf_ext_module.addImport("ztf", ztf_pkg.module("ztf"));
}