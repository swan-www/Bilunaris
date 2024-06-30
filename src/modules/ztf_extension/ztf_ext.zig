const std = @import("std");
const c_builtin = std.zig.c_builtins;
const ztf = @import("ztf");
const ZtfBString = ztf.bstring;
const BString = ZtfBString.bstring;

const ZtfLog= ztf.log;
const LogLevel = ZtfLog.ztf_LogLevel;
const LogFileMode = ZtfLog.ztf_LogFileMode;

const is_dbg = (std.builtin.mode == std.builtin.Mode.Debug);

const static = struct {
	threadlocal var isInitialized = false;

	threadlocal var bufferMem: [4000]u8 = undefined;
	pub threadlocal var bufferFixedAllocator : std.heap.FixedBufferAllocator = undefined;
	pub threadlocal var bufferAllocator : std.mem.Allocator = undefined;

	threadlocal var symbolMem: [8000]u8 = undefined;
	pub threadlocal var symbolFixedAllocator : std.heap.FixedBufferAllocator = undefined;
	pub threadlocal var symbolAllocator : std.mem.Allocator = undefined;

	pub fn init(optional_allocator : ?*std.mem.Allocator) void
	{
		if(isInitialized)
		{
			return;
		}

		bufferFixedAllocator = std.heap.FixedBufferAllocator.init(&bufferMem);
		bufferAllocator = if(optional_allocator) |al| al.* else bufferFixedAllocator.allocator();

		symbolFixedAllocator = std.heap.FixedBufferAllocator.init(&symbolMem);
		symbolAllocator = if(optional_allocator) |al| al.* else symbolFixedAllocator.allocator();

		isInitialized = true;
	}

	pub fn deinit() void
	{
		if(!isInitialized)
		{
			return;
		}

		isInitialized = false;
	}
};

pub fn init(optional_allocator : ?*std.mem.Allocator) void
{
	static.init(optional_allocator);
}

pub fn deinit() void
{
	static.deinit();
}

pub const SourceLocation = struct {
    file: [:0]const u8,
	file_allocated : bool,
    fn_name: [:0]const u8,
	fn_name_allocated : bool,
    line: u32,
    column: u32,
	allocator: ?*std.mem.Allocator,

	pub fn free(self: SourceLocation) void
	{
		if(self.allocator) |al|
		{
			if(self.file_allocated)
			{
				al.*.free(self.file);
			}

			if(self.fn_name_allocated)
			{
				al.*.free(self.fn_name);
			}
		}
	}
};

const fallbackSourceLocation = SourceLocation{
		.file = "<null>",
		.file_allocated = false,
		.fn_name = "<null>",
		.fn_name_allocated = false,
		.line = 0,
		.column = 0,
		.allocator = null,
};

pub fn debugAddressInfo(address : usize) !SourceLocation
{
	const debug_info = try std.debug.getSelfDebugInfo();
	const module_debug_info = try debug_info.getModuleForAddress(address);
	const symbol_info = try module_debug_info.getSymbolAtAddress(static.symbolAllocator, address);
	const line_info = symbol_info.line_info;

	var fileName : []u8 = undefined;

	var fnName = try static.symbolAllocator.alloc(u8, symbol_info.symbol_name.len + 1);
	fnName[symbol_info.symbol_name.len] = 0;
	errdefer static.symbolAllocator.free(fnName);
	@memcpy(fnName[0..symbol_info.symbol_name.len], symbol_info.symbol_name);

	if(line_info) |li|
	{
		fileName = try static.symbolAllocator.alloc(u8, li.file_name.len + 1);
		fileName[li.file_name.len] = 0;
		errdefer static.symbolAllocator.free(fileName);
		@memcpy(fileName[0..li.file_name.len], li.file_name);
	}

	return .{
		.file = if(line_info) |_| fileName[0..fileName.len-1 :0] else fallbackSourceLocation.file,
		.file_allocated = if(line_info) |_| true else false,
		.fn_name = fnName[0..fnName.len-1 :0],
		.fn_name_allocated = true,
		.line = if(line_info) |li| @truncate(li.line) else fallbackSourceLocation.line,
		.column = if(line_info) |li| @truncate(li.column) else fallbackSourceLocation.column,
		.allocator = &static.symbolAllocator,
	};
}

fn WriteLogWrapper(log_level : LogLevel, msg : [*c]const u8, source_loc : SourceLocation) void
{
	_ = &log_level;
	_ = &msg;
	_ = &source_loc;
	ZtfLog.ztf_writeLog(@intCast(log_level), source_loc.file, @intCast(source_loc.line), msg);
}

fn LOGFInternal(log_level : LogLevel, address : usize, comptime fmt: []const u8, args: anytype) void
{
	const allocRequired = std.fmt.count(fmt, args);

	if(allocRequired > 0)
	{
		const source_loc = debugAddressInfo(address) catch fallbackSourceLocation;
		defer source_loc.free();

		const buffer = static.bufferAllocator.alloc(u8, allocRequired) catch
		{
			ZtfLog.ztf_writeLog(ZtfLog.ztf_eERROR, source_loc.file, @intCast(source_loc.line),
				"Log message of size '%i' exceeded allocation limit.'", @as(c_int, @intCast(allocRequired)));
			return;
		};
		defer static.bufferAllocator.free(buffer);

		const formattedMessage = std.fmt.bufPrint(buffer, fmt, args) catch
		{
			return;
		};
		WriteLogWrapper(log_level, formattedMessage.ptr, source_loc);
	}
}

pub noinline fn LOG(log_level : LogLevel, comptime msg: []const u8) void
{
	const return_address = @returnAddress();
	LOGFInternal(log_level, return_address, msg, .{});
}

pub noinline fn LOGF(log_level : LogLevel, comptime fmt: []const u8, args: anytype) callconv(.Unspecified) void
{
	const return_address = @returnAddress();
	LOGFInternal(log_level, return_address, fmt, args);
}

pub noinline fn LOG_IF(log_level : LogLevel, condition : bool, comptime fmt: []const u8, args: anytype) void
{
	if(!condition)
	{
		return;
	}

	const return_address = @returnAddress();
	LOGFInternal(log_level, return_address, fmt, args);
}

pub noinline fn DLOGF(log_level : LogLevel, comptime fmt: []const u8, args: anytype) void
{
	if(is_dbg)
	{
		return;
	}

	const return_address = @returnAddress();
	LOGFInternal(log_level, return_address, fmt, args);
}

pub noinline fn DLOG_IF(log_level : LogLevel, condition : bool, comptime fmt: []const u8, args: anytype) void
{
	if(is_dbg)
	{
		return;
	}

	if(!condition)
	{
		return;
	}

	const return_address = @returnAddress();
	LOGFInternal(log_level, return_address, fmt, args);
}

pub inline fn bfromarr(array: [*c]u8) BString
{
	return BString{
		.mlen = std.mem.len(array),
		.slen = c_builtin.__builtin_strlen(array),
		.data = array,
	};
}

pub inline fn bemptyfromarr(array: [*c]u8) BString
{
	const original_len = std.mem.len(array);
	array[0] = 0;

	return BString{
		.mlen = original_len,
		.slen = c_builtin.__builtin_strlen(array),
		.data = array,
	};
}

pub inline fn bempty() BString
{
	return BString{
		.mlen = 1,
		.slen = 0,
		.data = ZtfBString.gEmptyStringBuffer,
	};
}