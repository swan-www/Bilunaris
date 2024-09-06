const std = @import("std");
const fmt = std.fmt;
const ztf = @import("ztf");
const alias_build_util = ztf.alias_build_util;

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
		.root_source_file = alias_build_util.lazy_from_path("ztf_ext.zig", b),
	});
	ztf_ext_module.addImport("ztf", ztf_pkg.module("ztf"));
}