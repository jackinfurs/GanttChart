# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\dynam\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.8836.42\bin\cmake\win\x64\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\dynam\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.8836.42\bin\cmake\win\x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\dynam\CLionProjects\BOAssignment2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\dynam\CLionProjects\BOAssignment2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BOAssignment2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/BOAssignment2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/BOAssignment2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BOAssignment2.dir/flags.make

CMakeFiles/BOAssignment2.dir/main.c.obj: CMakeFiles/BOAssignment2.dir/flags.make
CMakeFiles/BOAssignment2.dir/main.c.obj: C:/Users/dynam/CLionProjects/BOAssignment2/main.c
CMakeFiles/BOAssignment2.dir/main.c.obj: CMakeFiles/BOAssignment2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\dynam\CLionProjects\BOAssignment2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/BOAssignment2.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/BOAssignment2.dir/main.c.obj -MF CMakeFiles\BOAssignment2.dir\main.c.obj.d -o CMakeFiles\BOAssignment2.dir\main.c.obj -c C:\Users\dynam\CLionProjects\BOAssignment2\main.c

CMakeFiles/BOAssignment2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BOAssignment2.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\dynam\CLionProjects\BOAssignment2\main.c > CMakeFiles\BOAssignment2.dir\main.c.i

CMakeFiles/BOAssignment2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BOAssignment2.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\dynam\CLionProjects\BOAssignment2\main.c -o CMakeFiles\BOAssignment2.dir\main.c.s

CMakeFiles/BOAssignment2.dir/chart.c.obj: CMakeFiles/BOAssignment2.dir/flags.make
CMakeFiles/BOAssignment2.dir/chart.c.obj: C:/Users/dynam/CLionProjects/BOAssignment2/chart.c
CMakeFiles/BOAssignment2.dir/chart.c.obj: CMakeFiles/BOAssignment2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\dynam\CLionProjects\BOAssignment2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/BOAssignment2.dir/chart.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/BOAssignment2.dir/chart.c.obj -MF CMakeFiles\BOAssignment2.dir\chart.c.obj.d -o CMakeFiles\BOAssignment2.dir\chart.c.obj -c C:\Users\dynam\CLionProjects\BOAssignment2\chart.c

CMakeFiles/BOAssignment2.dir/chart.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BOAssignment2.dir/chart.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\dynam\CLionProjects\BOAssignment2\chart.c > CMakeFiles\BOAssignment2.dir\chart.c.i

CMakeFiles/BOAssignment2.dir/chart.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BOAssignment2.dir/chart.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\dynam\CLionProjects\BOAssignment2\chart.c -o CMakeFiles\BOAssignment2.dir\chart.c.s

# Object files for target BOAssignment2
BOAssignment2_OBJECTS = \
"CMakeFiles/BOAssignment2.dir/main.c.obj" \
"CMakeFiles/BOAssignment2.dir/chart.c.obj"

# External object files for target BOAssignment2
BOAssignment2_EXTERNAL_OBJECTS =

BOAssignment2.exe: CMakeFiles/BOAssignment2.dir/main.c.obj
BOAssignment2.exe: CMakeFiles/BOAssignment2.dir/chart.c.obj
BOAssignment2.exe: CMakeFiles/BOAssignment2.dir/build.make
BOAssignment2.exe: CMakeFiles/BOAssignment2.dir/linklibs.rsp
BOAssignment2.exe: CMakeFiles/BOAssignment2.dir/objects1.rsp
BOAssignment2.exe: CMakeFiles/BOAssignment2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\dynam\CLionProjects\BOAssignment2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable BOAssignment2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\BOAssignment2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BOAssignment2.dir/build: BOAssignment2.exe
.PHONY : CMakeFiles/BOAssignment2.dir/build

CMakeFiles/BOAssignment2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\BOAssignment2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/BOAssignment2.dir/clean

CMakeFiles/BOAssignment2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\dynam\CLionProjects\BOAssignment2 C:\Users\dynam\CLionProjects\BOAssignment2 C:\Users\dynam\CLionProjects\BOAssignment2\cmake-build-debug C:\Users\dynam\CLionProjects\BOAssignment2\cmake-build-debug C:\Users\dynam\CLionProjects\BOAssignment2\cmake-build-debug\CMakeFiles\BOAssignment2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BOAssignment2.dir/depend

