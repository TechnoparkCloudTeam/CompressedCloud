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
include CMakeFiles/clientlib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/clientlib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/clientlib.dir/flags.make

CMakeFiles/clientlib.dir/Watcher/src/Watcher.cpp.o: CMakeFiles/clientlib.dir/flags.make
CMakeFiles/clientlib.dir/Watcher/src/Watcher.cpp.o: ../Watcher/src/Watcher.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/TechnoparkProjects/CompressedCloud/project/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/clientlib.dir/Watcher/src/Watcher.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/clientlib.dir/Watcher/src/Watcher.cpp.o -c /home/ilya/TechnoparkProjects/CompressedCloud/project/Client/Watcher/src/Watcher.cpp

CMakeFiles/clientlib.dir/Watcher/src/Watcher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/clientlib.dir/Watcher/src/Watcher.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/TechnoparkProjects/CompressedCloud/project/Client/Watcher/src/Watcher.cpp > CMakeFiles/clientlib.dir/Watcher/src/Watcher.cpp.i

CMakeFiles/clientlib.dir/Watcher/src/Watcher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/clientlib.dir/Watcher/src/Watcher.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/TechnoparkProjects/CompressedCloud/project/Client/Watcher/src/Watcher.cpp -o CMakeFiles/clientlib.dir/Watcher/src/Watcher.cpp.s

CMakeFiles/clientlib.dir/ProgramInterface/src/ProgramInterface.cpp.o: CMakeFiles/clientlib.dir/flags.make
CMakeFiles/clientlib.dir/ProgramInterface/src/ProgramInterface.cpp.o: ../ProgramInterface/src/ProgramInterface.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/TechnoparkProjects/CompressedCloud/project/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/clientlib.dir/ProgramInterface/src/ProgramInterface.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/clientlib.dir/ProgramInterface/src/ProgramInterface.cpp.o -c /home/ilya/TechnoparkProjects/CompressedCloud/project/Client/ProgramInterface/src/ProgramInterface.cpp

CMakeFiles/clientlib.dir/ProgramInterface/src/ProgramInterface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/clientlib.dir/ProgramInterface/src/ProgramInterface.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/TechnoparkProjects/CompressedCloud/project/Client/ProgramInterface/src/ProgramInterface.cpp > CMakeFiles/clientlib.dir/ProgramInterface/src/ProgramInterface.cpp.i

CMakeFiles/clientlib.dir/ProgramInterface/src/ProgramInterface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/clientlib.dir/ProgramInterface/src/ProgramInterface.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/TechnoparkProjects/CompressedCloud/project/Client/ProgramInterface/src/ProgramInterface.cpp -o CMakeFiles/clientlib.dir/ProgramInterface/src/ProgramInterface.cpp.s

CMakeFiles/clientlib.dir/Application/src/Application.cpp.o: CMakeFiles/clientlib.dir/flags.make
CMakeFiles/clientlib.dir/Application/src/Application.cpp.o: ../Application/src/Application.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/TechnoparkProjects/CompressedCloud/project/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/clientlib.dir/Application/src/Application.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/clientlib.dir/Application/src/Application.cpp.o -c /home/ilya/TechnoparkProjects/CompressedCloud/project/Client/Application/src/Application.cpp

CMakeFiles/clientlib.dir/Application/src/Application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/clientlib.dir/Application/src/Application.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/TechnoparkProjects/CompressedCloud/project/Client/Application/src/Application.cpp > CMakeFiles/clientlib.dir/Application/src/Application.cpp.i

CMakeFiles/clientlib.dir/Application/src/Application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/clientlib.dir/Application/src/Application.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/TechnoparkProjects/CompressedCloud/project/Client/Application/src/Application.cpp -o CMakeFiles/clientlib.dir/Application/src/Application.cpp.s

CMakeFiles/clientlib.dir/Indexer/src/Indexer.cpp.o: CMakeFiles/clientlib.dir/flags.make
CMakeFiles/clientlib.dir/Indexer/src/Indexer.cpp.o: ../Indexer/src/Indexer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/TechnoparkProjects/CompressedCloud/project/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/clientlib.dir/Indexer/src/Indexer.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/clientlib.dir/Indexer/src/Indexer.cpp.o -c /home/ilya/TechnoparkProjects/CompressedCloud/project/Client/Indexer/src/Indexer.cpp

CMakeFiles/clientlib.dir/Indexer/src/Indexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/clientlib.dir/Indexer/src/Indexer.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/TechnoparkProjects/CompressedCloud/project/Client/Indexer/src/Indexer.cpp > CMakeFiles/clientlib.dir/Indexer/src/Indexer.cpp.i

CMakeFiles/clientlib.dir/Indexer/src/Indexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/clientlib.dir/Indexer/src/Indexer.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/TechnoparkProjects/CompressedCloud/project/Client/Indexer/src/Indexer.cpp -o CMakeFiles/clientlib.dir/Indexer/src/Indexer.cpp.s

# Object files for target clientlib
clientlib_OBJECTS = \
"CMakeFiles/clientlib.dir/Watcher/src/Watcher.cpp.o" \
"CMakeFiles/clientlib.dir/ProgramInterface/src/ProgramInterface.cpp.o" \
"CMakeFiles/clientlib.dir/Application/src/Application.cpp.o" \
"CMakeFiles/clientlib.dir/Indexer/src/Indexer.cpp.o"

# External object files for target clientlib
clientlib_EXTERNAL_OBJECTS =

libclientlib.a: CMakeFiles/clientlib.dir/Watcher/src/Watcher.cpp.o
libclientlib.a: CMakeFiles/clientlib.dir/ProgramInterface/src/ProgramInterface.cpp.o
libclientlib.a: CMakeFiles/clientlib.dir/Application/src/Application.cpp.o
libclientlib.a: CMakeFiles/clientlib.dir/Indexer/src/Indexer.cpp.o
libclientlib.a: CMakeFiles/clientlib.dir/build.make
libclientlib.a: CMakeFiles/clientlib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ilya/TechnoparkProjects/CompressedCloud/project/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libclientlib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/clientlib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/clientlib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/clientlib.dir/build: libclientlib.a

.PHONY : CMakeFiles/clientlib.dir/build

CMakeFiles/clientlib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/clientlib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/clientlib.dir/clean

CMakeFiles/clientlib.dir/depend:
	cd /home/ilya/TechnoparkProjects/CompressedCloud/project/Client/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ilya/TechnoparkProjects/CompressedCloud/project/Client /home/ilya/TechnoparkProjects/CompressedCloud/project/Client /home/ilya/TechnoparkProjects/CompressedCloud/project/Client/build /home/ilya/TechnoparkProjects/CompressedCloud/project/Client/build /home/ilya/TechnoparkProjects/CompressedCloud/project/Client/build/CMakeFiles/clientlib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/clientlib.dir/depend

