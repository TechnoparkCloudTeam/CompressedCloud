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
CMAKE_SOURCE_DIR = /home/lida/CloudProject/CompressedCloud/project/DataBases/PostgresDB

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lida/CloudProject/CompressedCloud/project/DataBases/PostgresDB/build

# Include any dependencies generated for this target.
include CMakeFiles/PostgresDB.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PostgresDB.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PostgresDB.dir/flags.make

CMakeFiles/PostgresDB.dir/main.cpp.o: CMakeFiles/PostgresDB.dir/flags.make
CMakeFiles/PostgresDB.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lida/CloudProject/CompressedCloud/project/DataBases/PostgresDB/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PostgresDB.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PostgresDB.dir/main.cpp.o -c /home/lida/CloudProject/CompressedCloud/project/DataBases/PostgresDB/main.cpp

CMakeFiles/PostgresDB.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PostgresDB.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lida/CloudProject/CompressedCloud/project/DataBases/PostgresDB/main.cpp > CMakeFiles/PostgresDB.dir/main.cpp.i

CMakeFiles/PostgresDB.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PostgresDB.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lida/CloudProject/CompressedCloud/project/DataBases/PostgresDB/main.cpp -o CMakeFiles/PostgresDB.dir/main.cpp.s

CMakeFiles/PostgresDB.dir/Base/src/PostgreSQLDB.cpp.o: CMakeFiles/PostgresDB.dir/flags.make
CMakeFiles/PostgresDB.dir/Base/src/PostgreSQLDB.cpp.o: ../Base/src/PostgreSQLDB.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lida/CloudProject/CompressedCloud/project/DataBases/PostgresDB/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PostgresDB.dir/Base/src/PostgreSQLDB.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PostgresDB.dir/Base/src/PostgreSQLDB.cpp.o -c /home/lida/CloudProject/CompressedCloud/project/DataBases/PostgresDB/Base/src/PostgreSQLDB.cpp

CMakeFiles/PostgresDB.dir/Base/src/PostgreSQLDB.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PostgresDB.dir/Base/src/PostgreSQLDB.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lida/CloudProject/CompressedCloud/project/DataBases/PostgresDB/Base/src/PostgreSQLDB.cpp > CMakeFiles/PostgresDB.dir/Base/src/PostgreSQLDB.cpp.i

CMakeFiles/PostgresDB.dir/Base/src/PostgreSQLDB.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PostgresDB.dir/Base/src/PostgreSQLDB.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lida/CloudProject/CompressedCloud/project/DataBases/PostgresDB/Base/src/PostgreSQLDB.cpp -o CMakeFiles/PostgresDB.dir/Base/src/PostgreSQLDB.cpp.s

CMakeFiles/PostgresDB.dir/MetaDB/src/MetaDB.cpp.o: CMakeFiles/PostgresDB.dir/flags.make
CMakeFiles/PostgresDB.dir/MetaDB/src/MetaDB.cpp.o: ../MetaDB/src/MetaDB.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lida/CloudProject/CompressedCloud/project/DataBases/PostgresDB/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/PostgresDB.dir/MetaDB/src/MetaDB.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PostgresDB.dir/MetaDB/src/MetaDB.cpp.o -c /home/lida/CloudProject/CompressedCloud/project/DataBases/PostgresDB/MetaDB/src/MetaDB.cpp

CMakeFiles/PostgresDB.dir/MetaDB/src/MetaDB.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PostgresDB.dir/MetaDB/src/MetaDB.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lida/CloudProject/CompressedCloud/project/DataBases/PostgresDB/MetaDB/src/MetaDB.cpp > CMakeFiles/PostgresDB.dir/MetaDB/src/MetaDB.cpp.i

CMakeFiles/PostgresDB.dir/MetaDB/src/MetaDB.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PostgresDB.dir/MetaDB/src/MetaDB.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lida/CloudProject/CompressedCloud/project/DataBases/PostgresDB/MetaDB/src/MetaDB.cpp -o CMakeFiles/PostgresDB.dir/MetaDB/src/MetaDB.cpp.s

CMakeFiles/PostgresDB.dir/UserDB/src/UserDB.cpp.o: CMakeFiles/PostgresDB.dir/flags.make
CMakeFiles/PostgresDB.dir/UserDB/src/UserDB.cpp.o: ../UserDB/src/UserDB.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lida/CloudProject/CompressedCloud/project/DataBases/PostgresDB/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/PostgresDB.dir/UserDB/src/UserDB.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PostgresDB.dir/UserDB/src/UserDB.cpp.o -c /home/lida/CloudProject/CompressedCloud/project/DataBases/PostgresDB/UserDB/src/UserDB.cpp

CMakeFiles/PostgresDB.dir/UserDB/src/UserDB.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PostgresDB.dir/UserDB/src/UserDB.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lida/CloudProject/CompressedCloud/project/DataBases/PostgresDB/UserDB/src/UserDB.cpp > CMakeFiles/PostgresDB.dir/UserDB/src/UserDB.cpp.i

CMakeFiles/PostgresDB.dir/UserDB/src/UserDB.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PostgresDB.dir/UserDB/src/UserDB.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lida/CloudProject/CompressedCloud/project/DataBases/PostgresDB/UserDB/src/UserDB.cpp -o CMakeFiles/PostgresDB.dir/UserDB/src/UserDB.cpp.s

# Object files for target PostgresDB
PostgresDB_OBJECTS = \
"CMakeFiles/PostgresDB.dir/main.cpp.o" \
"CMakeFiles/PostgresDB.dir/Base/src/PostgreSQLDB.cpp.o" \
"CMakeFiles/PostgresDB.dir/MetaDB/src/MetaDB.cpp.o" \
"CMakeFiles/PostgresDB.dir/UserDB/src/UserDB.cpp.o"

# External object files for target PostgresDB
PostgresDB_EXTERNAL_OBJECTS =

PostgresDB: CMakeFiles/PostgresDB.dir/main.cpp.o
PostgresDB: CMakeFiles/PostgresDB.dir/Base/src/PostgreSQLDB.cpp.o
PostgresDB: CMakeFiles/PostgresDB.dir/MetaDB/src/MetaDB.cpp.o
PostgresDB: CMakeFiles/PostgresDB.dir/UserDB/src/UserDB.cpp.o
PostgresDB: CMakeFiles/PostgresDB.dir/build.make
PostgresDB: /usr/lib/x86_64-linux-gnu/libpq.so
PostgresDB: CMakeFiles/PostgresDB.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lida/CloudProject/CompressedCloud/project/DataBases/PostgresDB/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable PostgresDB"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PostgresDB.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PostgresDB.dir/build: PostgresDB

.PHONY : CMakeFiles/PostgresDB.dir/build

CMakeFiles/PostgresDB.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PostgresDB.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PostgresDB.dir/clean

CMakeFiles/PostgresDB.dir/depend:
	cd /home/lida/CloudProject/CompressedCloud/project/DataBases/PostgresDB/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lida/CloudProject/CompressedCloud/project/DataBases/PostgresDB /home/lida/CloudProject/CompressedCloud/project/DataBases/PostgresDB /home/lida/CloudProject/CompressedCloud/project/DataBases/PostgresDB/build /home/lida/CloudProject/CompressedCloud/project/DataBases/PostgresDB/build /home/lida/CloudProject/CompressedCloud/project/DataBases/PostgresDB/build/CMakeFiles/PostgresDB.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PostgresDB.dir/depend

