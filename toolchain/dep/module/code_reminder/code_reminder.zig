const std = @import("std");

pub const CodeReminderOptions = struct {
    enableCodeRemindersByName: ?[]const u8,
    enableCodeRemindersByProposalNumber: ?[]const u8,
};

pub const CodeReminder = struct {
    proposal_number: ?u32,
    reminder_id: anyerror, //We use anyerror so that any new library can come along and define code reminders,
    //and use this struct
    reminder_name: []const u8,
    is_enabled: bool,

    fn isCodeReminderEnabledCommon(
        code_reminder_options: anytype,
        comptime proposal_number_opt: ?u32,
        comptime reminder_id: anyerror,
    ) bool {
        const error_name = @errorName(reminder_id);
        if (code_reminder_options.enableCodeRemindersByName) |enabled_reminder_names| {
            var name_itr = std.mem.tokenizeScalar(u8, enabled_reminder_names, ',');
            while (name_itr.next()) |name| {
                if (std.mem.eql(u8, name, "*")) return true; //Wildcard
                if (std.mem.eql(u8, name, error_name)) return true;
            }
        }

        if (proposal_number_opt) |number| {
            if (code_reminder_options.enableCodeRemindersByProposalNumber) |enabledProposalNumbers| {
                var num_itr = std.mem.tokenizeScalar(u8, enabledProposalNumbers, ',');
                while (num_itr.next()) |number_as_str| {
                    if (std.mem.eql(u8, number_as_str, "*")) return true; //Wildcard
                    const proposal_as_number = std.fmt.parseInt(u32, number_as_str, 10) catch continue;
                    if (proposal_as_number == number) return true;
                }
            }
        }

        return false;
    }

    fn isCodeReminderEnabledComptime(
        comptime code_reminder_options: anytype,
        comptime proposal_number_opt: ?u32,
        comptime reminder_id: anyerror,
    ) bool {
        comptime {
            return isCodeReminderEnabledCommon(code_reminder_options, proposal_number_opt, reminder_id);
        }
    }

    fn isCodeReminderEnabledBuildTime(
        code_reminder_options: CodeReminderOptions,
        comptime proposal_number_opt: ?u32,
        comptime reminder_id: anyerror,
    ) bool {
        return isCodeReminderEnabledCommon(code_reminder_options, proposal_number_opt, reminder_id);
    }

    pub fn comptimeInit(comptime code_reminder_options: anytype, comptime in_proposal_number: ?u32, comptime in_reminder_id: anyerror) CodeReminder {
        comptime {
            return .{
                .proposal_number = in_proposal_number,
                .reminder_id = in_reminder_id,
                .reminder_name = @errorName(in_reminder_id),
                .is_enabled = isCodeReminderEnabledComptime(code_reminder_options, in_proposal_number, in_reminder_id),
            };
        }
    }

    pub fn buildInit(in_options: CodeReminderOptions, comptime in_proposal_number: ?u32, comptime in_reminder_id: anyerror) CodeReminder {
        return .{
            .proposal_number = in_proposal_number,
            .reminder_id = in_reminder_id,
            .reminder_name = @errorName(in_reminder_id),
            .is_enabled = isCodeReminderEnabledBuildTime(in_options, in_proposal_number, in_reminder_id),
        };
    }

    pub fn comptimeCheck(comptime self: CodeReminder, comptime source_loc: std.builtin.SourceLocation, comptime opt_message: ?[]const u8) void {
        comptime {
            if (self.is_enabled) {
                const proposal_number = if (self.proposal_number) |number| std.fmt.comptimePrint("{}", .{number}) else "N/A";
                const line_number = std.fmt.comptimePrint("{}", .{source_loc.line});
                const col_number = std.fmt.comptimePrint("{}", .{source_loc.column});

                @compileLog(
					"CodeReminder: reminder{"
					++ @errorName(self.reminder_id)
					++ "} with proposal_id {"
					++ proposal_number
					++ "} triggered at "
					++ source_loc.file
					++ ":" ++ line_number
					++ ":" ++ col_number
					++ " -- \""
					++ (opt_message orelse "")
					++ "\""
				);
            }
        }
    }

	fn buildCheckInner(self: CodeReminder, b: *std.Build, comptime source_loc: std.builtin.SourceLocation, opt_message: ?[]const u8) !void {
		if (self.is_enabled) {
			const na_str = "N/A";
			var prop_num_str: []u8 = try b.allocator.dupe(u8, na_str);
			defer if (!std.mem.eql(u8, prop_num_str, na_str)) b.allocator.free(prop_num_str);

			if (self.proposal_number) |number| {
				prop_num_str = try std.fmt.allocPrint(b.allocator, "{}", .{number});
			}

			const line_num_str = std.fmt.comptimePrint("{}", .{source_loc.line});
			const column_num_str = std.fmt.comptimePrint("{}", .{source_loc.column});

			const err_str = try std.mem.concat(
				b.allocator,
				u8,
				&.{
					"CodeReminder:{",
					self.reminder_name,
					"} with proposal_id {",
					prop_num_str,
					"} triggered at ",
					source_loc.file,
					":", line_num_str,
					":", column_num_str,
					" -- \"",
					opt_message orelse "",
					"\"" 
				}
			);
			std.log.warn("{s}", .{err_str});
		}
	}

    pub fn buildCheck(self: CodeReminder, b: *std.Build, comptime source_loc: std.builtin.SourceLocation, opt_message: ?[]const u8) void {
		buildCheckInner(self, b, source_loc, opt_message) catch |err| std.debug.panic("CodeReminder.buildCheck encountered error: {s}", .{@errorName(err)});
    }
};
