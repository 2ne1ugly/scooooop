# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /nfs/2018/m/mchi/.brew/Cellar/cmake/3.14.4/bin/cmake

# The command to remove a file.
RM = /nfs/2018/m/mchi/.brew/Cellar/cmake/3.14.4/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3

# Include any dependencies generated for this target.
include tests/CMakeFiles/title.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/title.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/title.dir/flags.make

tests/CMakeFiles/title.dir/title.c.o: tests/CMakeFiles/title.dir/flags.make
tests/CMakeFiles/title.dir/title.c.o: tests/title.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/title.dir/title.c.o"
	cd /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/tests && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/title.dir/title.c.o   -c /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/tests/title.c

tests/CMakeFiles/title.dir/title.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/title.dir/title.c.i"
	cd /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/tests && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/tests/title.c > CMakeFiles/title.dir/title.c.i

tests/CMakeFiles/title.dir/title.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/title.dir/title.c.s"
	cd /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/tests && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/tests/title.c -o CMakeFiles/title.dir/title.c.s

tests/CMakeFiles/title.dir/__/deps/glad_gl.c.o: tests/CMakeFiles/title.dir/flags.make
tests/CMakeFiles/title.dir/__/deps/glad_gl.c.o: deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/CMakeFiles/title.dir/__/deps/glad_gl.c.o"
	cd /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/tests && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/title.dir/__/deps/glad_gl.c.o   -c /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/deps/glad_gl.c

tests/CMakeFiles/title.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/title.dir/__/deps/glad_gl.c.i"
	cd /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/tests && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/deps/glad_gl.c > CMakeFiles/title.dir/__/deps/glad_gl.c.i

tests/CMakeFiles/title.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/title.dir/__/deps/glad_gl.c.s"
	cd /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/tests && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/deps/glad_gl.c -o CMakeFiles/title.dir/__/deps/glad_gl.c.s

# Object files for target title
title_OBJECTS = \
"CMakeFiles/title.dir/title.c.o" \
"CMakeFiles/title.dir/__/deps/glad_gl.c.o"

# External object files for target title
title_EXTERNAL_OBJECTS =

tests/title.app/Contents/MacOS/title: tests/CMakeFiles/title.dir/title.c.o
tests/title.app/Contents/MacOS/title: tests/CMakeFiles/title.dir/__/deps/glad_gl.c.o
tests/title.app/Contents/MacOS/title: tests/CMakeFiles/title.dir/build.make
tests/title.app/Contents/MacOS/title: src/libglfw3.a
tests/title.app/Contents/MacOS/title: tests/CMakeFiles/title.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable title.app/Contents/MacOS/title"
	cd /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/title.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/title.dir/build: tests/title.app/Contents/MacOS/title

.PHONY : tests/CMakeFiles/title.dir/build

tests/CMakeFiles/title.dir/clean:
	cd /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/tests && $(CMAKE_COMMAND) -P CMakeFiles/title.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/title.dir/clean

tests/CMakeFiles/title.dir/depend:
	cd /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3 /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/tests /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3 /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/tests /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/tests/CMakeFiles/title.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/title.dir/depend
