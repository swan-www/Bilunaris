# C and Zig bindings for TheForge

There's 3 repos, Bilunaris is the "topmost" one, the others are referenced as git submodules:
* Bilunaris (01_transformations + C and Zig bindings)
* ZigTheForge (this is just the zig build system support for TheForge) [https://github.com/swan-www/ZigTheForge](https://github.com/swan-www/ZigTheForge)
* TheForge-ZigMod (this is a fork of TheForge with very minor modifications to better support the other two repos) [https://github.com/swan-www/TheForge-ZigMod](https://github.com/swan-www/TheForge-ZigMod)

Make sure you run the appropriate git commands to retrieve all the submodules when/after you clone Bilunaris.

the `build.zig` for `01_transformations` is under `proj/test/01_transformations/build.zig`
In order to build the only things that should need doing is running the prebuild bat file in TheForge itself to grab the art files, downloading the zig compiler, and then running `zig.exe build --summary all -Dtarget=x86_64-windows-msvc -Doptimize=Debug` while current working directory is `proj/test/01_transformations`.

The zig source for 01_transformations is here:
`src/test/01_transformations/01_transformations.zig`

The C bindings are located here:
`src/dep/modules/ztf/glue`

The zig bindings are created as part of the build process, and generated a file called `Ztf.zig`. You can see how this is referenced in the `build.zig` file for `01_transformations`.
This should support Zig v0.12 to v0.13, and the fork of the TheForge version used was just updated to 1.58 (holding off 1.59 for now).

The built binary and resources should end up in a `zig-out` folder in the same directory as the `build.zig` file. Running this executable should run the `01_transformations` demo. If you wish to debug, I recommend using [The Rad Debugger](https://github.com/EpicGamesExt/raddebugger).
