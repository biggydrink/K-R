# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.6

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\JetBrains\CLion 2016.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\JetBrains\CLion 2016.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Andrew\Projects\CProjects\K&R_Exercises\ex3-4"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Andrew\Projects\CProjects\K&R_Exercises\ex3-4\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/ex3_4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ex3_4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ex3_4.dir/flags.make

CMakeFiles/ex3_4.dir/main.c.obj: CMakeFiles/ex3_4.dir/flags.make
CMakeFiles/ex3_4.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Andrew\Projects\CProjects\K&R_Exercises\ex3-4\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ex3_4.dir/main.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-6~1.0-P\mingw32\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ex3_4.dir\main.c.obj   -c "C:\Users\Andrew\Projects\CProjects\K&R_Exercises\ex3-4\main.c"

CMakeFiles/ex3_4.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ex3_4.dir/main.c.i"
	C:\PROGRA~2\MINGW-~1\I686-6~1.0-P\mingw32\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Andrew\Projects\CProjects\K&R_Exercises\ex3-4\main.c" > CMakeFiles\ex3_4.dir\main.c.i

CMakeFiles/ex3_4.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ex3_4.dir/main.c.s"
	C:\PROGRA~2\MINGW-~1\I686-6~1.0-P\mingw32\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Andrew\Projects\CProjects\K&R_Exercises\ex3-4\main.c" -o CMakeFiles\ex3_4.dir\main.c.s

CMakeFiles/ex3_4.dir/main.c.obj.requires:

.PHONY : CMakeFiles/ex3_4.dir/main.c.obj.requires

CMakeFiles/ex3_4.dir/main.c.obj.provides: CMakeFiles/ex3_4.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\ex3_4.dir\build.make CMakeFiles/ex3_4.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/ex3_4.dir/main.c.obj.provides

CMakeFiles/ex3_4.dir/main.c.obj.provides.build: CMakeFiles/ex3_4.dir/main.c.obj


# Object files for target ex3_4
ex3_4_OBJECTS = \
"CMakeFiles/ex3_4.dir/main.c.obj"

# External object files for target ex3_4
ex3_4_EXTERNAL_OBJECTS =

ex3_4.exe: CMakeFiles/ex3_4.dir/main.c.obj
ex3_4.exe: CMakeFiles/ex3_4.dir/build.make
ex3_4.exe: CMakeFiles/ex3_4.dir/linklibs.rsp
ex3_4.exe: CMakeFiles/ex3_4.dir/objects1.rsp
ex3_4.exe: CMakeFiles/ex3_4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Andrew\Projects\CProjects\K&R_Exercises\ex3-4\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ex3_4.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ex3_4.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ex3_4.dir/build: ex3_4.exe

.PHONY : CMakeFiles/ex3_4.dir/build

CMakeFiles/ex3_4.dir/requires: CMakeFiles/ex3_4.dir/main.c.obj.requires

.PHONY : CMakeFiles/ex3_4.dir/requires

CMakeFiles/ex3_4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ex3_4.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ex3_4.dir/clean

CMakeFiles/ex3_4.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Andrew\Projects\CProjects\K&R_Exercises\ex3-4" "C:\Users\Andrew\Projects\CProjects\K&R_Exercises\ex3-4" "C:\Users\Andrew\Projects\CProjects\K&R_Exercises\ex3-4\cmake-build-debug" "C:\Users\Andrew\Projects\CProjects\K&R_Exercises\ex3-4\cmake-build-debug" "C:\Users\Andrew\Projects\CProjects\K&R_Exercises\ex3-4\cmake-build-debug\CMakeFiles\ex3_4.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ex3_4.dir/depend
