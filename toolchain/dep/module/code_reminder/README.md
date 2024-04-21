# code_reminder
Zig package for opt-in conditional reminders that are triggered during build or compilation.
Made against `Zig 0.12.0-dev.3522+b88ae8dbd` (2024-04-03).

# Usage

Examples for buildtime and comptime code reminders here: https://github.com/swan-www/code_reminder_examples

Add `code_reminder` as a dependency to your `build.zig.zon`
```
.{
    .name = "my_example_project",
    .version = "1.0.0",
    .minimum_zig_version = "0.12.0",
    .dependencies = .{
        .code_reminder = .{
			.url = "https://github.com/swan-www/code_reminder/archive/refs/tags/v1.0.0.tar.gz",
			.hash = "1220caec7bf1b2cf992b5443703c8df904488477a96395acca3cf339f2cb9ef55513",
        },
    },
    .paths = .{""},
}
```

## buildtime
Import `code_reminder` (and its corresponding build) into your `build.zig`
```
const code_reminder_build = @import("code_reminder");
const code_reminder = code_reminder_build.code_reminder;
```

Define some reminder types `const CodeReminderAsError = error{ MyTodoBuildUtil, Foo, Bar };`.


Define `CodeReminder` structs for each of your types, example definition below. Note we use an `init` function as we need to pass `CodeReminderOptions` into the `.buildInit` for each `CodeReminder`. When we call `.buildInit` we pass in an optional `proposal_id` and a required `error` type that identifies the reminder.
```
const CodeReminders = struct {
    MyTodoBuildUtil: code_reminder.CodeReminder,
    Foo: code_reminder.CodeReminder,
    Bar: code_reminder.CodeReminder,

    pub fn init(options: code_reminder.CodeReminderOptions) CodeReminders {
        return .{
            .MyTodoBuildUtil = code_reminder.CodeReminder.buildInit(options, null, CodeReminderAsError.MyTodoBuildUtil),
            .Foo = code_reminder.CodeReminder.buildInit(options, 12345, CodeReminderAsError.Foo),
            .Bar = code_reminder.CodeReminder.buildInit(options, null, CodeReminderAsError.Bar),
        };
    }
};
```

In your `build` function, setup the build options, and then initialise your CodeReminders using the returned options.
```
const build_opt_return = code_reminder_build.addCodeRemindersToBuildOptions(b, null);
const build_code_reminders = CodeReminders.init(build_opt_return.options);
```

Pass the initialised CodeReminders to any of your build utility functions that want to make a reminder, e.g. `foo(b, &build_code_reminders);`
```
fn foo(b: *std.Build, cr: *const CodeReminders) void {
    _ = &b;
    cr.Foo.buildCheck(b, @src(), "foo has been deprecated");
}
```

Add a code reminder by calling `.buildCheck` on the reminder you want to trigger, supplying the src location and a reminder message: `cr.Foo.buildCheck(b, @src(), "foo has been deprecated");`

## comptime
Import `code_reminder` into your `build.zig` (note that importing here means we are actually importing the `build.zig` from the `code_reminder` module)
```
const code_reminder_build = @import("code_reminder");
```

Pass your `std.Build.Step.Compile`, e.g. your exe or lib, to the `importModule` function to make the imports available to the project code:
```
const exe = b.addExecutable(.{
    .name = "main",
    .target = target,
    .optimize = optimize,
    .root_source_file = .{ .path = "main.zig" },
});
_ = code_reminder_build.importModule(b, exe);
```

Then, in your project code (in this case `main.zig`) you want to import the following. `module_code_reminder` is just convention for aggregating the other modules (there's only one for now). `code_reminder_options` imports the build-generated options definitions.
```
const module_code_reminder = @import("module_code_reminder");
const code_reminder = module_code_reminder.code_reminder;
const code_reminder_options = @import("code_reminder_options");
```

Define some reminder types `const CodeReminderAsError = error{ Foo, Bar };`.


Define `CodeReminder` structs for each of your types, example definition below. When we call `.comptimeInit` we pass in an optional `proposal_id` and a required `error` type that identifies the reminder.
```
const CodeReminders = struct {
    const Foo = code_reminder.CodeReminder.comptimeInit(code_reminder_options, 12345, CodeReminderAsError.Foo);
    const Bar = code_reminder.CodeReminder.comptimeInit(code_reminder_options, null, CodeReminderAsError.Bar);
};
```

Then simply call a `.comptimeCheck` in a comptime block of your code, using the `CodeReminder` you want to trigger. Note that the reminder will likely be skipped if your function is not used, as it won't get compiled.
```
fn fooFunc() void {
    comptime {
        CodeReminders.Foo.comptimeCheck(@src(), "fooFunc has been deprecated");
    }
}
```

## Triggering the reminders
By default, your builds should remain unchanged, no extra output or errors during build or compilation.

Using the following build arguments will cause reminders to trigger that match the error name:

`zig build -DenableCodeRemindersByName=Foo`


Using the following build arguments will cause reminders to trigger that match the proposal number:

`zig build -DenableCodeRemindersByProposalNumber=12345`


These options can accept multiple arguments e.g.

`zig build "-DenableCodeRemindersByName=MyTodoBuildUtil,Foo,Bar"`

- Example output for a buildtime check:
```
warning: CodeReminder:{MyTodoBuildUtil} with proposal_id {N/A} triggered at D:\devspace\code_reminder_examples\code_reminder_example_buildtime\build.zig:23:38 -- "Replace this function with 'newBuildUtilFunctionToUse'"
warning: CodeReminder:{Foo} with proposal_id {12345} triggered at D:\devspace\code_reminder_examples\code_reminder_example_buildtime\build.zig:35:26 -- "foo has been deprecated"
```

- Example output for a comptime check (note that it won't end compilation, but it will ultimately result in a compilation failure, as that is the behaviour of `@compileLog`)
```
:88:17: error: found compile log statement
                @compileLog(
                ^~~~~~~~~~~

Compile Log Output:
@as(*const [113:0]u8, "CodeReminder: reminder{Foo} with proposal_id {12345} triggered at main.zig:15:41 -- \"fooFunc has been deprecated\"")
```
