const std = @import("std");
const fmt = std.fmt;
const c_builtin = std.zig.c_builtins;
const ztf = @import("ztf");
const ZtfBString = Ztf.BString;
const BString = ZtfBString.bstring;

pub fn bfromarr(array: [*c]u8) BString
{
	return BString{
		.mlen = std.mem.len(array),
		.slen = c_builtin.__builtin_strlen(array),
		.data = array,
	};
}

pub fn bemptyfromarr(array: [*c]u8) BString
{
	const original_len = std.mem.len(array);
	array[0] = 0;

	return BString{
		.mlen = original_len,
		.slen = c_builtin.__builtin_strlen(array),
		.data = array,
	};
}

pub fn bempty() BString
{
	return BString{
		.mlen = 1,
		.slen = 0,
		.data = ZtfBString.gEmptyStringBuffer,
	};
}