# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ilyanyrkov/CompressedCloud/project/Client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ilyanyrkov/CompressedCloud/project/Client/build

# Include any dependencies generated for this target.
include Tests/CMakeFiles/tests.dir/depend.make

# Include the progress variables for this target.
include Tests/CMakeFiles/tests.dir/progress.make

# Include the compile flags for this target's objects.
include Tests/CMakeFiles/tests.dir/flags.make

Tests/CMakeFiles/tests.dir/client_tests.cpp.o: Tests/CMakeFiles/tests.dir/flags.make
Tests/CMakeFiles/tests.dir/client_tests.cpp.o: ../Tests/client_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilyanyrkov/CompressedCloud/project/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Tests/CMakeFiles/tests.dir/client_tests.cpp.o"
	cd /home/ilyanyrkov/CompressedCloud/project/Client/build/Tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/client_tests.cpp.o -c /home/ilyanyrkov/CompressedCloud/project/Client/Tests/client_tests.cpp

Tests/CMakeFiles/tests.dir/client_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/client_tests.cpp.i"
	cd /home/ilyanyrkov/CompressedCloud/project/Client/build/Tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilyanyrkov/CompressedCloud/project/Client/Tests/client_tests.cpp > CMakeFiles/tests.dir/client_tests.cpp.i

Tests/CMakeFiles/tests.dir/client_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/client_tests.cpp.s"
	cd /home/ilyanyrkov/CompressedCloud/project/Client/build/Tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilyanyrkov/CompressedCloud/project/Client/Tests/client_tests.cpp -o CMakeFiles/tests.dir/client_tests.cpp.s

# Object files for target tests
tests_OBJECTS = \
"CMakeFiles/tests.dir/client_tests.cpp.o"

# External object files for target tests
tests_EXTERNAL_OBJECTS =

Tests/tests: Tests/CMakeFiles/tests.dir/client_tests.cpp.o
Tests/tests: Tests/CMakeFiles/tests.dir/build.make
Tests/tests: /usr/lib/x86_64-linux-gnu/libgtest.a
Tests/tests: Tests/libclient.so
Tests/tests: Tests/CMakeFiles/tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ilyanyrkov/CompressedCloud/project/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tests"
	cd /home/ilyanyrkov/CompressedCloud/project/Client/build/Tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Tests/CMakeFiles/tests.dir/build: Tests/tests

.PHONY : Tests/CMakeFiles/tests.dir/build

Tests/CMakeFiles/tests.dir/clean:
	cd /home/ilyanyrkov/CompressedCloud/project/Client/build/Tests && $(CMAKE_COMMAND) -P CMakeFiles/tests.dir/cmake_clean.cmake
.PHONY : Tests/CMakeFiles/tests.dir/clean

Tests/CMakeFiles/tests.dir/depend:
	cd /home/ilyanyrkov/CompressedCloud/project/Client/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ilyanyrkov/CompressedCloud/project/Client /home/ilyanyrkov/CompressedCloud/project/Client/Tests /home/ilyanyrkov/CompressedCloud/project/Client/build /home/ilyanyrkov/CompressedCloud/project/Client/build/Tests /home/ilyanyrkov/CompressedCloud/project/Client/build/Tests/CMakeFiles/tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Tests/CMakeFiles/tests.dir/depend

