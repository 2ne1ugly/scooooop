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
include tests/CMakeFiles/vulkan.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/vulkan.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/vulkan.dir/flags.make

tests/CMakeFiles/vulkan.dir/vulkan.c.o: tests/CMakeFiles/vulkan.dir/flags.make
tests/CMakeFiles/vulkan.dir/vulkan.c.o: tests/vulkan.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/vulkan.dir/vulkan.c.o"
	cd /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/tests && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/vulkan.dir/vulkan.c.o   -c /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/tests/vulkan.c

tests/CMakeFiles/vulkan.dir/vulkan.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/vulkan.dir/vulkan.c.i"
	cd /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/tests && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/tests/vulkan.c > CMakeFiles/vulkan.dir/vulkan.c.i

tests/CMakeFiles/vulkan.dir/vulkan.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/vulkan.dir/vulkan.c.s"
	cd /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/tests && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/tests/vulkan.c -o CMakeFiles/vulkan.dir/vulkan.c.s

tests/CMakeFiles/vulkan.dir/__/deps/glad_vulkan.c.o: tests/CMakeFiles/vulkan.dir/flags.make
tests/CMakeFiles/vulkan.dir/__/deps/glad_vulkan.c.o: deps/glad_vulkan.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/CMakeFiles/vulkan.dir/__/deps/glad_vulkan.c.o"
	cd /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/tests && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/vulkan.dir/__/deps/glad_vulkan.c.o   -c /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/deps/glad_vulkan.c

tests/CMakeFiles/vulkan.dir/__/deps/glad_vulkan.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/vulkan.dir/__/deps/glad_vulkan.c.i"
	cd /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/tests && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/deps/glad_vulkan.c > CMakeFiles/vulkan.dir/__/deps/glad_vulkan.c.i

tests/CMakeFiles/vulkan.dir/__/deps/glad_vulkan.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/vulkan.dir/__/deps/glad_vulkan.c.s"
	cd /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/tests && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/deps/glad_vulkan.c -o CMakeFiles/vulkan.dir/__/deps/glad_vulkan.c.s

# Object files for target vulkan
vulkan_OBJECTS = \
"CMakeFiles/vulkan.dir/vulkan.c.o" \
"CMakeFiles/vulkan.dir/__/deps/glad_vulkan.c.o"

# External object files for target vulkan
vulkan_EXTERNAL_OBJECTS =

tests/vulkan: tests/CMakeFiles/vulkan.dir/vulkan.c.o
tests/vulkan: tests/CMakeFiles/vulkan.dir/__/deps/glad_vulkan.c.o
tests/vulkan: tests/CMakeFiles/vulkan.dir/build.make
tests/vulkan: src/libglfw3.a
tests/vulkan: tests/CMakeFiles/vulkan.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable vulkan"
	cd /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vulkan.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/vulkan.dir/build: tests/vulkan

.PHONY : tests/CMakeFiles/vulkan.dir/build

tests/CMakeFiles/vulkan.dir/clean:
	cd /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/tests && $(CMAKE_COMMAND) -P CMakeFiles/vulkan.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/vulkan.dir/clean

tests/CMakeFiles/vulkan.dir/depend:
	cd /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3 /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/tests /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3 /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/tests /nfs/2018/m/mchi/projects/ParticleSystem/lib/glfw-3.3/tests/CMakeFiles/vulkan.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/vulkan.dir/depend

