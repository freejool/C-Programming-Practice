# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/sxing/OneDrive/2020_2/C/5#"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/sxing/OneDrive/2020_2/C/5#/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/5_.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/5_.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/5_.dir/flags.make

CMakeFiles/5_.dir/main.c.o: CMakeFiles/5_.dir/flags.make
CMakeFiles/5_.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/sxing/OneDrive/2020_2/C/5#/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/5_.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/5_.dir/main.c.o -c "/Users/sxing/OneDrive/2020_2/C/5#/main.c"

CMakeFiles/5_.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/5_.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/sxing/OneDrive/2020_2/C/5#/main.c" > CMakeFiles/5_.dir/main.c.i

CMakeFiles/5_.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/5_.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/sxing/OneDrive/2020_2/C/5#/main.c" -o CMakeFiles/5_.dir/main.c.s

# Object files for target 5_
5__OBJECTS = \
"CMakeFiles/5_.dir/main.c.o"

# External object files for target 5_
5__EXTERNAL_OBJECTS =

5_: CMakeFiles/5_.dir/main.c.o
5_: CMakeFiles/5_.dir/build.make
5_: CMakeFiles/5_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/sxing/OneDrive/2020_2/C/5#/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 5_"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/5_.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/5_.dir/build: 5_

.PHONY : CMakeFiles/5_.dir/build

CMakeFiles/5_.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/5_.dir/cmake_clean.cmake
.PHONY : CMakeFiles/5_.dir/clean

CMakeFiles/5_.dir/depend:
	cd "/Users/sxing/OneDrive/2020_2/C/5#/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/sxing/OneDrive/2020_2/C/5#" "/Users/sxing/OneDrive/2020_2/C/5#" "/Users/sxing/OneDrive/2020_2/C/5#/cmake-build-debug" "/Users/sxing/OneDrive/2020_2/C/5#/cmake-build-debug" "/Users/sxing/OneDrive/2020_2/C/5#/cmake-build-debug/CMakeFiles/5_.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/5_.dir/depend

