const std = @import("std");

const maxReadBytes = 1024 * 1024 * 100;

pub fn main() !void {
    var arena_state = std.heap.ArenaAllocator.init(std.heap.page_allocator);
    defer arena_state.deinit();
    const arena = arena_state.allocator();

    const args = try std.process.argsAlloc(arena);

    if (args.len != 3) fatal("wrong number of arguments", .{}, 5);

    const input_file_path = args[1];
	const output_file_path = args[2];
	
	std.debug.print("FIXUP FILE: {s}\n", .{output_file_path});

    var input_file = std.fs.cwd().createFile(input_file_path, .{.read = true, .truncate = false}) catch |err| {
        fatal("unable to open '{s}': {s}", .{ input_file_path, @errorName(err) }, 6);
    };
    defer input_file.close();

	var output_file = std.fs.cwd().createFile(output_file_path, .{}) catch |err| {
        fatal("unable to open '{s}': {s}", .{ output_file_path, @errorName(err) }, 7);
    };
    defer output_file.close();

	const inputData = try input_file.readToEndAlloc(arena, maxReadBytes);
	defer arena.free(inputData);

	try output_file.writeAll(inputData);
    try output_file.writeAll(
        \\pub fn struct_DECLSPEC_UUID(comptime _: type) type {
		\\	return struct {};
		\\}
    );
    return std.process.cleanExit();
}

fn fatal(comptime format: []const u8, args: anytype, exitcode: u8) noreturn {
    std.debug.print(format, args);
    std.process.exit(exitcode);
}