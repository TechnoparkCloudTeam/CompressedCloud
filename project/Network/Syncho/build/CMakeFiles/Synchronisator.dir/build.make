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
CMAKE_SOURCE_DIR = /home/lyalyashechka/TP/c_c++/project/Cloud/project/Network/Syncho

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lyalyashechka/TP/c_c++/project/Cloud/project/Network/Syncho/build

# Include any dependencies generated for this target.
include CMakeFiles/Synchronisator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Synchronisator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Synchronisator.dir/flags.make

CMakeFiles/Synchronisator.dir/src/Synchronisator.cpp.o: CMakeFiles/Synchronisator.dir/flags.make
CMakeFiles/Synchronisator.dir/src/Synchronisator.cpp.o: ../src/Synchronisator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lyalyashechka/TP/c_c++/project/Cloud/project/Network/Syncho/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Synchronisator.dir/src/Synchronisator.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Synchronisator.dir/src/Synchronisator.cpp.o -c /home/lyalyashechka/TP/c_c++/project/Cloud/project/Network/Syncho/src/Synchronisator.cpp

CMakeFiles/Synchronisator.dir/src/Synchronisator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Synchronisator.dir/src/Synchronisator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lyalyashechka/TP/c_c++/project/Cloud/project/Network/Syncho/src/Synchronisator.cpp > CMakeFiles/Synchronisator.dir/src/Synchronisator.cpp.i

CMakeFiles/Synchronisator.dir/src/Synchronisator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Synchronisator.dir/src/Synchronisator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lyalyashechka/TP/c_c++/project/Cloud/project/Network/Syncho/src/Synchronisator.cpp -o CMakeFiles/Synchronisator.dir/src/Synchronisator.cpp.s

CMakeFiles/Synchronisator.dir/main.cpp.o: CMakeFiles/Synchronisator.dir/flags.make
CMakeFiles/Synchronisator.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lyalyashechka/TP/c_c++/project/Cloud/project/Network/Syncho/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Synchronisator.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Synchronisator.dir/main.cpp.o -c /home/lyalyashechka/TP/c_c++/project/Cloud/project/Network/Syncho/main.cpp

CMakeFiles/Synchronisator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Synchronisator.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lyalyashechka/TP/c_c++/project/Cloud/project/Network/Syncho/main.cpp > CMakeFiles/Synchronisator.dir/main.cpp.i

CMakeFiles/Synchronisator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Synchronisator.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lyalyashechka/TP/c_c++/project/Cloud/project/Network/Syncho/main.cpp -o CMakeFiles/Synchronisator.dir/main.cpp.s

# Object files for target Synchronisator
Synchronisator_OBJECTS = \
"CMakeFiles/Synchronisator.dir/src/Synchronisator.cpp.o" \
"CMakeFiles/Synchronisator.dir/main.cpp.o"

# External object files for target Synchronisator
Synchronisator_EXTERNAL_OBJECTS =

Synchronisator: CMakeFiles/Synchronisator.dir/src/Synchronisator.cpp.o
Synchronisator: CMakeFiles/Synchronisator.dir/main.cpp.o
Synchronisator: CMakeFiles/Synchronisator.dir/build.make
Synchronisator: CMakeFiles/Synchronisator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lyalyashechka/TP/c_c++/project/Cloud/project/Network/Syncho/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Synchronisator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Synchronisator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Synchronisator.dir/build: Synchronisator

.PHONY : CMakeFiles/Synchronisator.dir/build

CMakeFiles/Synchronisator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Synchronisator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Synchronisator.dir/clean

CMakeFiles/Synchronisator.dir/depend:
	cd /home/lyalyashechka/TP/c_c++/project/Cloud/project/Network/Syncho/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lyalyashechka/TP/c_c++/project/Cloud/project/Network/Syncho /home/lyalyashechka/TP/c_c++/project/Cloud/project/Network/Syncho /home/lyalyashechka/TP/c_c++/project/Cloud/project/Network/Syncho/build /home/lyalyashechka/TP/c_c++/project/Cloud/project/Network/Syncho/build /home/lyalyashechka/TP/c_c++/project/Cloud/project/Network/Syncho/build/CMakeFiles/Synchronisator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Synchronisator.dir/depend

