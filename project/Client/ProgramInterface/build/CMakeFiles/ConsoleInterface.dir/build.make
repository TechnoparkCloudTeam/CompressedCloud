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
CMAKE_SOURCE_DIR = /home/lyalyashechka/TP/c_c++/project/Cloud/project/Client/ConsoleInterface

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lyalyashechka/TP/c_c++/project/Cloud/project/Client/ConsoleInterface/build

# Include any dependencies generated for this target.
include CMakeFiles/ConsoleInterface.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ConsoleInterface.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ConsoleInterface.dir/flags.make

CMakeFiles/ConsoleInterface.dir/src/ConsoleInterface.cpp.o: CMakeFiles/ConsoleInterface.dir/flags.make
CMakeFiles/ConsoleInterface.dir/src/ConsoleInterface.cpp.o: ../src/ConsoleInterface.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lyalyashechka/TP/c_c++/project/Cloud/project/Client/ConsoleInterface/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ConsoleInterface.dir/src/ConsoleInterface.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ConsoleInterface.dir/src/ConsoleInterface.cpp.o -c /home/lyalyashechka/TP/c_c++/project/Cloud/project/Client/ConsoleInterface/src/ConsoleInterface.cpp

CMakeFiles/ConsoleInterface.dir/src/ConsoleInterface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ConsoleInterface.dir/src/ConsoleInterface.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lyalyashechka/TP/c_c++/project/Cloud/project/Client/ConsoleInterface/src/ConsoleInterface.cpp > CMakeFiles/ConsoleInterface.dir/src/ConsoleInterface.cpp.i

CMakeFiles/ConsoleInterface.dir/src/ConsoleInterface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ConsoleInterface.dir/src/ConsoleInterface.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lyalyashechka/TP/c_c++/project/Cloud/project/Client/ConsoleInterface/src/ConsoleInterface.cpp -o CMakeFiles/ConsoleInterface.dir/src/ConsoleInterface.cpp.s

CMakeFiles/ConsoleInterface.dir/main.cpp.o: CMakeFiles/ConsoleInterface.dir/flags.make
CMakeFiles/ConsoleInterface.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lyalyashechka/TP/c_c++/project/Cloud/project/Client/ConsoleInterface/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ConsoleInterface.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ConsoleInterface.dir/main.cpp.o -c /home/lyalyashechka/TP/c_c++/project/Cloud/project/Client/ConsoleInterface/main.cpp

CMakeFiles/ConsoleInterface.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ConsoleInterface.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lyalyashechka/TP/c_c++/project/Cloud/project/Client/ConsoleInterface/main.cpp > CMakeFiles/ConsoleInterface.dir/main.cpp.i

CMakeFiles/ConsoleInterface.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ConsoleInterface.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lyalyashechka/TP/c_c++/project/Cloud/project/Client/ConsoleInterface/main.cpp -o CMakeFiles/ConsoleInterface.dir/main.cpp.s

# Object files for target ConsoleInterface
ConsoleInterface_OBJECTS = \
"CMakeFiles/ConsoleInterface.dir/src/ConsoleInterface.cpp.o" \
"CMakeFiles/ConsoleInterface.dir/main.cpp.o"

# External object files for target ConsoleInterface
ConsoleInterface_EXTERNAL_OBJECTS =

ConsoleInterface: CMakeFiles/ConsoleInterface.dir/src/ConsoleInterface.cpp.o
ConsoleInterface: CMakeFiles/ConsoleInterface.dir/main.cpp.o
ConsoleInterface: CMakeFiles/ConsoleInterface.dir/build.make
ConsoleInterface: CMakeFiles/ConsoleInterface.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lyalyashechka/TP/c_c++/project/Cloud/project/Client/ConsoleInterface/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ConsoleInterface"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ConsoleInterface.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ConsoleInterface.dir/build: ConsoleInterface

.PHONY : CMakeFiles/ConsoleInterface.dir/build

CMakeFiles/ConsoleInterface.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ConsoleInterface.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ConsoleInterface.dir/clean

CMakeFiles/ConsoleInterface.dir/depend:
	cd /home/lyalyashechka/TP/c_c++/project/Cloud/project/Client/ConsoleInterface/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lyalyashechka/TP/c_c++/project/Cloud/project/Client/ConsoleInterface /home/lyalyashechka/TP/c_c++/project/Cloud/project/Client/ConsoleInterface /home/lyalyashechka/TP/c_c++/project/Cloud/project/Client/ConsoleInterface/build /home/lyalyashechka/TP/c_c++/project/Cloud/project/Client/ConsoleInterface/build /home/lyalyashechka/TP/c_c++/project/Cloud/project/Client/ConsoleInterface/build/CMakeFiles/ConsoleInterface.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ConsoleInterface.dir/depend

