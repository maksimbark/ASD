# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/maksimbarkalov/Documents/C_Projects/ASD/inversions

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/maksimbarkalov/Documents/C_Projects/ASD/inversions/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/inversions.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/inversions.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/inversions.dir/flags.make

CMakeFiles/inversions.dir/main.cpp.o: CMakeFiles/inversions.dir/flags.make
CMakeFiles/inversions.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maksimbarkalov/Documents/C_Projects/ASD/inversions/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/inversions.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/inversions.dir/main.cpp.o -c /Users/maksimbarkalov/Documents/C_Projects/ASD/inversions/main.cpp

CMakeFiles/inversions.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/inversions.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maksimbarkalov/Documents/C_Projects/ASD/inversions/main.cpp > CMakeFiles/inversions.dir/main.cpp.i

CMakeFiles/inversions.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/inversions.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maksimbarkalov/Documents/C_Projects/ASD/inversions/main.cpp -o CMakeFiles/inversions.dir/main.cpp.s

CMakeFiles/inversions.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/inversions.dir/main.cpp.o.requires

CMakeFiles/inversions.dir/main.cpp.o.provides: CMakeFiles/inversions.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/inversions.dir/build.make CMakeFiles/inversions.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/inversions.dir/main.cpp.o.provides

CMakeFiles/inversions.dir/main.cpp.o.provides.build: CMakeFiles/inversions.dir/main.cpp.o


# Object files for target inversions
inversions_OBJECTS = \
"CMakeFiles/inversions.dir/main.cpp.o"

# External object files for target inversions
inversions_EXTERNAL_OBJECTS =

inversions: CMakeFiles/inversions.dir/main.cpp.o
inversions: CMakeFiles/inversions.dir/build.make
inversions: CMakeFiles/inversions.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/maksimbarkalov/Documents/C_Projects/ASD/inversions/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable inversions"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/inversions.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/inversions.dir/build: inversions

.PHONY : CMakeFiles/inversions.dir/build

CMakeFiles/inversions.dir/requires: CMakeFiles/inversions.dir/main.cpp.o.requires

.PHONY : CMakeFiles/inversions.dir/requires

CMakeFiles/inversions.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/inversions.dir/cmake_clean.cmake
.PHONY : CMakeFiles/inversions.dir/clean

CMakeFiles/inversions.dir/depend:
	cd /Users/maksimbarkalov/Documents/C_Projects/ASD/inversions/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/maksimbarkalov/Documents/C_Projects/ASD/inversions /Users/maksimbarkalov/Documents/C_Projects/ASD/inversions /Users/maksimbarkalov/Documents/C_Projects/ASD/inversions/cmake-build-debug /Users/maksimbarkalov/Documents/C_Projects/ASD/inversions/cmake-build-debug /Users/maksimbarkalov/Documents/C_Projects/ASD/inversions/cmake-build-debug/CMakeFiles/inversions.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/inversions.dir/depend

