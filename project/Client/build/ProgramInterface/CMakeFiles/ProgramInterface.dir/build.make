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
CMAKE_SOURCE_DIR = "/home/lyalyashechka/TP/c_c++/Project main/project/Client"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/lyalyashechka/TP/c_c++/Project main/project/Client/build"

# Include any dependencies generated for this target.
include ProgramInterface/CMakeFiles/ProgramInterface.dir/depend.make

# Include the progress variables for this target.
include ProgramInterface/CMakeFiles/ProgramInterface.dir/progress.make

# Include the compile flags for this target's objects.
include ProgramInterface/CMakeFiles/ProgramInterface.dir/flags.make

ProgramInterface/CMakeFiles/ProgramInterface.dir/src/ProgramInterface.cpp.o: ProgramInterface/CMakeFiles/ProgramInterface.dir/flags.make
ProgramInterface/CMakeFiles/ProgramInterface.dir/src/ProgramInterface.cpp.o: ../ProgramInterface/src/ProgramInterface.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/lyalyashechka/TP/c_c++/Project main/project/Client/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ProgramInterface/CMakeFiles/ProgramInterface.dir/src/ProgramInterface.cpp.o"
	cd "/home/lyalyashechka/TP/c_c++/Project main/project/Client/build/ProgramInterface" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ProgramInterface.dir/src/ProgramInterface.cpp.o -c "/home/lyalyashechka/TP/c_c++/Project main/project/Client/ProgramInterface/src/ProgramInterface.cpp"

ProgramInterface/CMakeFiles/ProgramInterface.dir/src/ProgramInterface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProgramInterface.dir/src/ProgramInterface.cpp.i"
	cd "/home/lyalyashechka/TP/c_c++/Project main/project/Client/build/ProgramInterface" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/lyalyashechka/TP/c_c++/Project main/project/Client/ProgramInterface/src/ProgramInterface.cpp" > CMakeFiles/ProgramInterface.dir/src/ProgramInterface.cpp.i

ProgramInterface/CMakeFiles/ProgramInterface.dir/src/ProgramInterface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProgramInterface.dir/src/ProgramInterface.cpp.s"
	cd "/home/lyalyashechka/TP/c_c++/Project main/project/Client/build/ProgramInterface" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/lyalyashechka/TP/c_c++/Project main/project/Client/ProgramInterface/src/ProgramInterface.cpp" -o CMakeFiles/ProgramInterface.dir/src/ProgramInterface.cpp.s

ProgramInterface/CMakeFiles/ProgramInterface.dir/main.cpp.o: ProgramInterface/CMakeFiles/ProgramInterface.dir/flags.make
ProgramInterface/CMakeFiles/ProgramInterface.dir/main.cpp.o: ../ProgramInterface/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/lyalyashechka/TP/c_c++/Project main/project/Client/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object ProgramInterface/CMakeFiles/ProgramInterface.dir/main.cpp.o"
	cd "/home/lyalyashechka/TP/c_c++/Project main/project/Client/build/ProgramInterface" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ProgramInterface.dir/main.cpp.o -c "/home/lyalyashechka/TP/c_c++/Project main/project/Client/ProgramInterface/main.cpp"

ProgramInterface/CMakeFiles/ProgramInterface.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProgramInterface.dir/main.cpp.i"
	cd "/home/lyalyashechka/TP/c_c++/Project main/project/Client/build/ProgramInterface" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/lyalyashechka/TP/c_c++/Project main/project/Client/ProgramInterface/main.cpp" > CMakeFiles/ProgramInterface.dir/main.cpp.i

ProgramInterface/CMakeFiles/ProgramInterface.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProgramInterface.dir/main.cpp.s"
	cd "/home/lyalyashechka/TP/c_c++/Project main/project/Client/build/ProgramInterface" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/lyalyashechka/TP/c_c++/Project main/project/Client/ProgramInterface/main.cpp" -o CMakeFiles/ProgramInterface.dir/main.cpp.s

# Object files for target ProgramInterface
ProgramInterface_OBJECTS = \
"CMakeFiles/ProgramInterface.dir/src/ProgramInterface.cpp.o" \
"CMakeFiles/ProgramInterface.dir/main.cpp.o"

# External object files for target ProgramInterface
ProgramInterface_EXTERNAL_OBJECTS =

ProgramInterface/ProgramInterface: ProgramInterface/CMakeFiles/ProgramInterface.dir/src/ProgramInterface.cpp.o
ProgramInterface/ProgramInterface: ProgramInterface/CMakeFiles/ProgramInterface.dir/main.cpp.o
ProgramInterface/ProgramInterface: ProgramInterface/CMakeFiles/ProgramInterface.dir/build.make
ProgramInterface/ProgramInterface: ProgramInterface/CMakeFiles/ProgramInterface.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/lyalyashechka/TP/c_c++/Project main/project/Client/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ProgramInterface"
	cd "/home/lyalyashechka/TP/c_c++/Project main/project/Client/build/ProgramInterface" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ProgramInterface.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ProgramInterface/CMakeFiles/ProgramInterface.dir/build: ProgramInterface/ProgramInterface

.PHONY : ProgramInterface/CMakeFiles/ProgramInterface.dir/build

ProgramInterface/CMakeFiles/ProgramInterface.dir/clean:
	cd "/home/lyalyashechka/TP/c_c++/Project main/project/Client/build/ProgramInterface" && $(CMAKE_COMMAND) -P CMakeFiles/ProgramInterface.dir/cmake_clean.cmake
.PHONY : ProgramInterface/CMakeFiles/ProgramInterface.dir/clean

ProgramInterface/CMakeFiles/ProgramInterface.dir/depend:
	cd "/home/lyalyashechka/TP/c_c++/Project main/project/Client/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/lyalyashechka/TP/c_c++/Project main/project/Client" "/home/lyalyashechka/TP/c_c++/Project main/project/Client/ProgramInterface" "/home/lyalyashechka/TP/c_c++/Project main/project/Client/build" "/home/lyalyashechka/TP/c_c++/Project main/project/Client/build/ProgramInterface" "/home/lyalyashechka/TP/c_c++/Project main/project/Client/build/ProgramInterface/CMakeFiles/ProgramInterface.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : ProgramInterface/CMakeFiles/ProgramInterface.dir/depend
