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
CMAKE_SOURCE_DIR = /home/lida/Compressed_cloud/CompressedCloud/project/DataBase

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lida/Compressed_cloud/CompressedCloud/project/DataBase/build

# Include any dependencies generated for this target.
include FileStorage/CMakeFiles/FileStorage.dir/depend.make

# Include the progress variables for this target.
include FileStorage/CMakeFiles/FileStorage.dir/progress.make

# Include the compile flags for this target's objects.
include FileStorage/CMakeFiles/FileStorage.dir/flags.make

FileStorage/CMakeFiles/FileStorage.dir/src/FileStorage.cpp.o: FileStorage/CMakeFiles/FileStorage.dir/flags.make
FileStorage/CMakeFiles/FileStorage.dir/src/FileStorage.cpp.o: ../FileStorage/src/FileStorage.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lida/Compressed_cloud/CompressedCloud/project/DataBase/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object FileStorage/CMakeFiles/FileStorage.dir/src/FileStorage.cpp.o"
	cd /home/lida/Compressed_cloud/CompressedCloud/project/DataBase/build/FileStorage && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FileStorage.dir/src/FileStorage.cpp.o -c /home/lida/Compressed_cloud/CompressedCloud/project/DataBase/FileStorage/src/FileStorage.cpp

FileStorage/CMakeFiles/FileStorage.dir/src/FileStorage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FileStorage.dir/src/FileStorage.cpp.i"
	cd /home/lida/Compressed_cloud/CompressedCloud/project/DataBase/build/FileStorage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lida/Compressed_cloud/CompressedCloud/project/DataBase/FileStorage/src/FileStorage.cpp > CMakeFiles/FileStorage.dir/src/FileStorage.cpp.i

FileStorage/CMakeFiles/FileStorage.dir/src/FileStorage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FileStorage.dir/src/FileStorage.cpp.s"
	cd /home/lida/Compressed_cloud/CompressedCloud/project/DataBase/build/FileStorage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lida/Compressed_cloud/CompressedCloud/project/DataBase/FileStorage/src/FileStorage.cpp -o CMakeFiles/FileStorage.dir/src/FileStorage.cpp.s

FileStorage/CMakeFiles/FileStorage.dir/main.cpp.o: FileStorage/CMakeFiles/FileStorage.dir/flags.make
FileStorage/CMakeFiles/FileStorage.dir/main.cpp.o: ../FileStorage/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lida/Compressed_cloud/CompressedCloud/project/DataBase/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object FileStorage/CMakeFiles/FileStorage.dir/main.cpp.o"
	cd /home/lida/Compressed_cloud/CompressedCloud/project/DataBase/build/FileStorage && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FileStorage.dir/main.cpp.o -c /home/lida/Compressed_cloud/CompressedCloud/project/DataBase/FileStorage/main.cpp

FileStorage/CMakeFiles/FileStorage.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FileStorage.dir/main.cpp.i"
	cd /home/lida/Compressed_cloud/CompressedCloud/project/DataBase/build/FileStorage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lida/Compressed_cloud/CompressedCloud/project/DataBase/FileStorage/main.cpp > CMakeFiles/FileStorage.dir/main.cpp.i

FileStorage/CMakeFiles/FileStorage.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FileStorage.dir/main.cpp.s"
	cd /home/lida/Compressed_cloud/CompressedCloud/project/DataBase/build/FileStorage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lida/Compressed_cloud/CompressedCloud/project/DataBase/FileStorage/main.cpp -o CMakeFiles/FileStorage.dir/main.cpp.s

# Object files for target FileStorage
FileStorage_OBJECTS = \
"CMakeFiles/FileStorage.dir/src/FileStorage.cpp.o" \
"CMakeFiles/FileStorage.dir/main.cpp.o"

# External object files for target FileStorage
FileStorage_EXTERNAL_OBJECTS =

FileStorage/FileStorage: FileStorage/CMakeFiles/FileStorage.dir/src/FileStorage.cpp.o
FileStorage/FileStorage: FileStorage/CMakeFiles/FileStorage.dir/main.cpp.o
FileStorage/FileStorage: FileStorage/CMakeFiles/FileStorage.dir/build.make
FileStorage/FileStorage: FileStorage/CMakeFiles/FileStorage.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lida/Compressed_cloud/CompressedCloud/project/DataBase/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable FileStorage"
	cd /home/lida/Compressed_cloud/CompressedCloud/project/DataBase/build/FileStorage && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FileStorage.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
FileStorage/CMakeFiles/FileStorage.dir/build: FileStorage/FileStorage

.PHONY : FileStorage/CMakeFiles/FileStorage.dir/build

FileStorage/CMakeFiles/FileStorage.dir/clean:
	cd /home/lida/Compressed_cloud/CompressedCloud/project/DataBase/build/FileStorage && $(CMAKE_COMMAND) -P CMakeFiles/FileStorage.dir/cmake_clean.cmake
.PHONY : FileStorage/CMakeFiles/FileStorage.dir/clean

FileStorage/CMakeFiles/FileStorage.dir/depend:
	cd /home/lida/Compressed_cloud/CompressedCloud/project/DataBase/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lida/Compressed_cloud/CompressedCloud/project/DataBase /home/lida/Compressed_cloud/CompressedCloud/project/DataBase/FileStorage /home/lida/Compressed_cloud/CompressedCloud/project/DataBase/build /home/lida/Compressed_cloud/CompressedCloud/project/DataBase/build/FileStorage /home/lida/Compressed_cloud/CompressedCloud/project/DataBase/build/FileStorage/CMakeFiles/FileStorage.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : FileStorage/CMakeFiles/FileStorage.dir/depend

