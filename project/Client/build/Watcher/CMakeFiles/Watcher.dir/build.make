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
CMAKE_SOURCE_DIR = /home/ilya/TechnoparkProjects/CompressedCloud/project/Client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ilya/TechnoparkProjects/CompressedCloud/project/Client/build

# Include any dependencies generated for this target.
include Watcher/CMakeFiles/Watcher.dir/depend.make

# Include the progress variables for this target.
include Watcher/CMakeFiles/Watcher.dir/progress.make

# Include the compile flags for this target's objects.
include Watcher/CMakeFiles/Watcher.dir/flags.make

Watcher/CMakeFiles/Watcher.dir/src/Watcher.cpp.o: Watcher/CMakeFiles/Watcher.dir/flags.make
Watcher/CMakeFiles/Watcher.dir/src/Watcher.cpp.o: ../Watcher/src/Watcher.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/TechnoparkProjects/CompressedCloud/project/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Watcher/CMakeFiles/Watcher.dir/src/Watcher.cpp.o"
	cd /home/ilya/TechnoparkProjects/CompressedCloud/project/Client/build/Watcher && /bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Watcher.dir/src/Watcher.cpp.o -c /home/ilya/TechnoparkProjects/CompressedCloud/project/Client/Watcher/src/Watcher.cpp

Watcher/CMakeFiles/Watcher.dir/src/Watcher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Watcher.dir/src/Watcher.cpp.i"
	cd /home/ilya/TechnoparkProjects/CompressedCloud/project/Client/build/Watcher && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/TechnoparkProjects/CompressedCloud/project/Client/Watcher/src/Watcher.cpp > CMakeFiles/Watcher.dir/src/Watcher.cpp.i

Watcher/CMakeFiles/Watcher.dir/src/Watcher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Watcher.dir/src/Watcher.cpp.s"
	cd /home/ilya/TechnoparkProjects/CompressedCloud/project/Client/build/Watcher && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/TechnoparkProjects/CompressedCloud/project/Client/Watcher/src/Watcher.cpp -o CMakeFiles/Watcher.dir/src/Watcher.cpp.s

Watcher/CMakeFiles/Watcher.dir/main.cpp.o: Watcher/CMakeFiles/Watcher.dir/flags.make
Watcher/CMakeFiles/Watcher.dir/main.cpp.o: ../Watcher/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/TechnoparkProjects/CompressedCloud/project/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Watcher/CMakeFiles/Watcher.dir/main.cpp.o"
	cd /home/ilya/TechnoparkProjects/CompressedCloud/project/Client/build/Watcher && /bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Watcher.dir/main.cpp.o -c /home/ilya/TechnoparkProjects/CompressedCloud/project/Client/Watcher/main.cpp

Watcher/CMakeFiles/Watcher.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Watcher.dir/main.cpp.i"
	cd /home/ilya/TechnoparkProjects/CompressedCloud/project/Client/build/Watcher && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/TechnoparkProjects/CompressedCloud/project/Client/Watcher/main.cpp > CMakeFiles/Watcher.dir/main.cpp.i

Watcher/CMakeFiles/Watcher.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Watcher.dir/main.cpp.s"
	cd /home/ilya/TechnoparkProjects/CompressedCloud/project/Client/build/Watcher && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/TechnoparkProjects/CompressedCloud/project/Client/Watcher/main.cpp -o CMakeFiles/Watcher.dir/main.cpp.s

# Object files for target Watcher
Watcher_OBJECTS = \
"CMakeFiles/Watcher.dir/src/Watcher.cpp.o" \
"CMakeFiles/Watcher.dir/main.cpp.o"

# External object files for target Watcher
Watcher_EXTERNAL_OBJECTS =

Watcher/Watcher: Watcher/CMakeFiles/Watcher.dir/src/Watcher.cpp.o
Watcher/Watcher: Watcher/CMakeFiles/Watcher.dir/main.cpp.o
Watcher/Watcher: Watcher/CMakeFiles/Watcher.dir/build.make
Watcher/Watcher: Watcher/CMakeFiles/Watcher.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ilya/TechnoparkProjects/CompressedCloud/project/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Watcher"
	cd /home/ilya/TechnoparkProjects/CompressedCloud/project/Client/build/Watcher && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Watcher.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Watcher/CMakeFiles/Watcher.dir/build: Watcher/Watcher

.PHONY : Watcher/CMakeFiles/Watcher.dir/build

Watcher/CMakeFiles/Watcher.dir/clean:
	cd /home/ilya/TechnoparkProjects/CompressedCloud/project/Client/build/Watcher && $(CMAKE_COMMAND) -P CMakeFiles/Watcher.dir/cmake_clean.cmake
.PHONY : Watcher/CMakeFiles/Watcher.dir/clean

Watcher/CMakeFiles/Watcher.dir/depend:
	cd /home/ilya/TechnoparkProjects/CompressedCloud/project/Client/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ilya/TechnoparkProjects/CompressedCloud/project/Client /home/ilya/TechnoparkProjects/CompressedCloud/project/Client/Watcher /home/ilya/TechnoparkProjects/CompressedCloud/project/Client/build /home/ilya/TechnoparkProjects/CompressedCloud/project/Client/build/Watcher /home/ilya/TechnoparkProjects/CompressedCloud/project/Client/build/Watcher/CMakeFiles/Watcher.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Watcher/CMakeFiles/Watcher.dir/depend

