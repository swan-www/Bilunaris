const std = @import("std");
const code_reminder_build = @import("code_reminder");
const code_reminder = code_reminder_build.code_reminder;

pub const CodeReminderErrors = error
{
	SrcBuiltinFileConsistency
};

pub const CodeReminders = struct
{
	SrcBuiltinFileConsistency: code_reminder.CodeReminder,

	pub fn init(options: code_reminder.CodeReminderOptions) CodeReminders
	{
		return  .{
			.SrcBuiltinFileConsistency = code_reminder.CodeReminder.buildInit(options, 19570, CodeReminderErrors.SrcBuiltinFileConsistency),
		};
	}
};

const Detail = struct
{
    path_to_this_file : [:0]const u8,
    directory_of_this_file : []const u8,

    pub fn getPathToThisFile() [:0]const u8
    {
        return @src().file;
    }

    pub fn getDirOfThisFile() []const u8
    {
        const pttf = getPathToThisFile();
        return std.fs.path.dirname(pttf) orelse unreachable;
    }
};

const detail = Detail
{
    .path_to_this_file = Detail.getPathToThisFile(),
    .directory_of_this_file = Detail.getDirOfThisFile(),
};

pub const Dir = struct
{
	dir_handle: std.fs.Dir,
	str: []const u8,
	str_alloc: ?std.mem.Allocator,

	pub fn close(self: *Dir) void
	{
		self.dir_handle.close();
		if(self.str_alloc) |alloc|
		{
			alloc.free(self.str);
		}
	}

	pub fn openFile(self: Dir, allocator: std.mem.Allocator, sub_path: []const u8, flags: File.OpenFlags) !File
	{
		const joined_path = try self.dir_handle.realpathAlloc(allocator, sub_path);
		errdefer allocator.free(joined_path);

		const file_handle = try self.dir_handle.openFile(sub_path, flags);
		errdefer file_handle.close();
		
		return File{.file_handle = file_handle, .str = joined_path, .str_alloc = allocator};
	}
};

pub const File = struct
{
	file_handle: std.fs.File,
	str: []const u8,
	str_alloc: ?std.mem.Allocator,

	const OpenFlags = std.fs.File.OpenFlags;

	pub fn open(allocator: std.mem.Allocator, path: []const u8, flags: File.OpenFlags) !File
	{
		const file_handle = try std.fs.openFileAbsolute(path, flags);
		errdefer file_handle.close();

		const duped_path_str = try std.mem.Allocator.dupe(allocator, u8, path);
		errdefer allocator.free(duped_path_str);
		
		return File{.file_handle = file_handle, .str = duped_path_str, .str_alloc = allocator};
	}

	pub fn close(self: File) void
	{
		self.file_handle.close();
		if(self.str_alloc) |alloc|
		{
			alloc.free(self.str);
		}
	}
};

pub fn buildAbsolutePathAndGetDirectory(
	allocator : std.mem.Allocator,
	path_segments: []const []const u8,
	dir_options: ?std.fs.Dir.OpenDirOptions,
) !Dir
{
	const joined_path = try std.fs.path.join(
        allocator, 
        path_segments
    );
	errdefer allocator.free(joined_path);

	const dir = try std.fs.openDirAbsolute(joined_path, dir_options orelse .{.access_sub_paths = true});
	errdefer dir.close;

	return Dir{.dir_handle = dir, .str = joined_path, .str_alloc = allocator};
}

pub fn getDirAsSubpathFromDir(
	dir : Dir,
	allocator : std.mem.Allocator,
	sub_path: []const u8,
	dir_options: ?std.fs.Dir.OpenDirOptions,
) !Dir
{
	const joined_path = try dir.dir_handle.realpathAlloc(allocator, sub_path);
	errdefer allocator.free(joined_path);

	const subdir = try std.fs.openDirAbsolute(joined_path, dir_options orelse .{.access_sub_paths = true});
	return Dir{.dir_handle = subdir, .str = joined_path, .str_alloc = allocator};
}

fn getDirNameFromDir(dir: std.fs.Dir, allocator: std.mem.Allocator) ![]u8
{
	return dir.realpathAlloc(allocator, ".");
}

//Caller owns the allocation
pub fn getAliasRootDirectory(allocator : std.mem.Allocator) !Dir
{
    const resolvedPath = try std.fs.path.resolve(
        allocator, 
        &.{
            detail.directory_of_this_file,
            "../../../.."
        }
    );
	defer allocator.free(resolvedPath);

	return buildAbsolutePathAndGetDirectory(allocator, &.{resolvedPath}, null);
}

//Caller owns the allocation
pub fn getAliasSrcDirectory(allocator : std.mem.Allocator) !Dir
{
    var root_dir = try getAliasRootDirectory(allocator);
	defer root_dir.close();
	return getDirAsSubpathFromDir(root_dir, allocator, "src", null);	
}

//Caller owns the allocation
pub fn getAliasProjDirectory(allocator : std.mem.Allocator) !Dir
{
	var root_dir = try getAliasRootDirectory(allocator);
	defer root_dir.close();
	return getDirAsSubpathFromDir(root_dir, allocator, "proj", null);	
}

//Caller owns the allocation
pub fn getAliasLibDirectory(allocator : std.mem.Allocator) !Dir
{
	var root_dir = try getAliasRootDirectory(allocator);
	defer root_dir.close();
	return getDirAsSubpathFromDir(root_dir, allocator, "lib", null);	
}

//Caller owns the allocation
pub fn getAliasTFLibDirectory(
	b: *std.Build,
	target: *const std.Build.ResolvedTarget,
	optimization: std.builtin.OptimizeMode
) !Dir
{
	const optimization_substring = switch(optimization)
    {
        std.builtin.OptimizeMode.Debug => "Debug",
        else => "Release"
    };

 	const cpu_arch = target.result.cpu.arch;
    const os_name = target.result.os.tag;
    const abi = target.result.abi;

	var alias_lib_directory = try getAliasLibDirectory(b.allocator);
	defer alias_lib_directory.close();
    const target_substring = try std.fmt.allocPrint(b.allocator, "{s}-{s}-{s}", .{@tagName(cpu_arch), @tagName(os_name), @tagName(abi)});
	defer b.allocator.free(target_substring);
	const alias_tflib_directory = try std.fs.path.join(b.allocator, &.{alias_lib_directory.str, optimization_substring, target_substring, "tfalias"});
	defer b.allocator.free(alias_tflib_directory);

	return buildAbsolutePathAndGetDirectory(b.allocator, &.{alias_tflib_directory}, null);
}

//Caller owns the allocation
pub fn getTFAliasDirectory(allocator : std.mem.Allocator) !Dir
{
    var src_dir = try getAliasSrcDirectory(allocator);
	defer src_dir.close();
	return getDirAsSubpathFromDir(src_dir, allocator, "dep/common/tfalias", null);
}

pub fn addCSourceFiles(
	b: *std.Build,
	add_to: *std.Build.Step.Compile,
	file_sub_paths: []const []const u8,
	file_base_path: []const u8,
	flags: []const []const u8,
) !void
{
	var relative_src_paths = std.ArrayList([]const u8).init(b.allocator);
	defer {
		for(relative_src_paths.items) |ele|
		{
			b.allocator.free(ele);
		}
		relative_src_paths.deinit();
	}
	for (file_sub_paths) |pt| {
		const abs_path = try std.fs.path.join(b.allocator, &.{file_base_path, pt});
		try relative_src_paths.append(try std.fs.path.relative(b.allocator, b.build_root.path.?, abs_path));
	}

	add_to.addCSourceFiles(.{
        .files = relative_src_paths.items,
        .flags = flags,
    });
}

test "alias_root_dir" {
	const allocator = std.testing.allocator;
	var alias_root_dir = try getAliasRootDirectory(allocator);
	defer alias_root_dir.close();
}

test "alias_src_dir" {
	const allocator = std.testing.allocator;
	var  alias_src_dir = try getAliasSrcDirectory(allocator);
	defer alias_src_dir.close();
}

test "alias_proj_dir" {
	const allocator = std.testing.allocator;
	var alias_proj_dir = try getAliasProjDirectory(allocator);
	defer alias_proj_dir.close();
}

test "tfalias_dir" {
	const allocator = std.testing.allocator;
	var tfalias_dir = try getTFAliasDirectory(allocator);
	defer tfalias_dir.close();
}

pub fn build(b: *std.Build) !void
{
	const build_opt_return = code_reminder_build.addCodeRemindersToBuildOptions(b, null);
	const code_reminders = CodeReminders.init(build_opt_return.options);
	code_reminders.SrcBuiltinFileConsistency.buildCheck(b, @src(), "Complete the tests above when @src() has consistent behaviour.");

    const allocator = b.allocator;

	{
		var alias_root_dir = try getAliasRootDirectory(allocator);
		defer alias_root_dir.close();
		std.log.info("alias_root_dir: {s}", .{alias_root_dir.str});
	}

	{
		var alias_src_dir = try getAliasSrcDirectory(allocator);
		defer alias_src_dir.close();
		std.log.info("alias_src_dir: {s}", .{alias_src_dir.str});
	}

	{
		var alias_proj_dir = try getAliasProjDirectory(allocator);
		defer alias_proj_dir.close();
		std.log.info("alias_proj_dir: {s}", .{alias_proj_dir.str});
	}

	{
		var tfalias_dir = try getTFAliasDirectory(allocator);
		defer tfalias_dir.close();
		std.log.info("tfalias_dir: {s}", .{tfalias_dir.str}); 
	}
}