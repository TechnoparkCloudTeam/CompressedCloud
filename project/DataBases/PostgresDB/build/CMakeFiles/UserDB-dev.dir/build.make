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
CMAKE_SOURCE_DIR = /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/DataBases/PostgresDB

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/DataBases/PostgresDB/build

# Include any dependencies generated for this target.
include CMakeFiles/UserDB-dev.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/UserDB-dev.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/UserDB-dev.dir/flags.make

CMakeFiles/UserDB-dev.dir/Base/src/PostgreSQLDB.cpp.o: CMakeFiles/UserDB-dev.dir/flags.make
CMakeFiles/UserDB-dev.dir/Base/src/PostgreSQLDB.cpp.o: ../Base/src/PostgreSQLDB.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/DataBases/PostgresDB/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/UserDB-dev.dir/Base/src/PostgreSQLDB.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UserDB-dev.dir/Base/src/PostgreSQLDB.cpp.o -c /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/DataBases/PostgresDB/Base/src/PostgreSQLDB.cpp

CMakeFiles/UserDB-dev.dir/Base/src/PostgreSQLDB.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UserDB-dev.dir/Base/src/PostgreSQLDB.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/DataBases/PostgresDB/Base/src/PostgreSQLDB.cpp > CMakeFiles/UserDB-dev.dir/Base/src/PostgreSQLDB.cpp.i

CMakeFiles/UserDB-dev.dir/Base/src/PostgreSQLDB.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UserDB-dev.dir/Base/src/PostgreSQLDB.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/DataBases/PostgresDB/Base/src/PostgreSQLDB.cpp -o CMakeFiles/UserDB-dev.dir/Base/src/PostgreSQLDB.cpp.s

CMakeFiles/UserDB-dev.dir/UserDB/src/UserDB.cpp.o: CMakeFiles/UserDB-dev.dir/flags.make
CMakeFiles/UserDB-dev.dir/UserDB/src/UserDB.cpp.o: ../UserDB/src/UserDB.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/DataBases/PostgresDB/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/UserDB-dev.dir/UserDB/src/UserDB.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UserDB-dev.dir/UserDB/src/UserDB.cpp.o -c /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/DataBases/PostgresDB/UserDB/src/UserDB.cpp

CMakeFiles/UserDB-dev.dir/UserDB/src/UserDB.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UserDB-dev.dir/UserDB/src/UserDB.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/DataBases/PostgresDB/UserDB/src/UserDB.cpp > CMakeFiles/UserDB-dev.dir/UserDB/src/UserDB.cpp.i

CMakeFiles/UserDB-dev.dir/UserDB/src/UserDB.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UserDB-dev.dir/UserDB/src/UserDB.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/DataBases/PostgresDB/UserDB/src/UserDB.cpp -o CMakeFiles/UserDB-dev.dir/UserDB/src/UserDB.cpp.s

# Object files for target UserDB-dev
UserDB__dev_OBJECTS = \
"CMakeFiles/UserDB-dev.dir/Base/src/PostgreSQLDB.cpp.o" \
"CMakeFiles/UserDB-dev.dir/UserDB/src/UserDB.cpp.o"

# External object files for target UserDB-dev
UserDB__dev_EXTERNAL_OBJECTS =

libUserDB-dev.so: CMakeFiles/UserDB-dev.dir/Base/src/PostgreSQLDB.cpp.o
libUserDB-dev.so: CMakeFiles/UserDB-dev.dir/UserDB/src/UserDB.cpp.o
libUserDB-dev.so: CMakeFiles/UserDB-dev.dir/build.make
libUserDB-dev.so: /usr/lib/x86_64-linux-gnu/libpq.so
libUserDB-dev.so: /usr/lib/x86_64-linux-gnu/libboost_log.so.1.71.0
libUserDB-dev.so: /usr/lib/x86_64-linux-gnu/libboost_chrono.so.1.71.0
libUserDB-dev.so: /usr/lib/x86_64-linux-gnu/libboost_date_time.so.1.71.0
libUserDB-dev.so: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.71.0
libUserDB-dev.so: /usr/lib/x86_64-linux-gnu/libboost_regex.so.1.71.0
libUserDB-dev.so: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.71.0
libUserDB-dev.so: /usr/lib/x86_64-linux-gnu/libboost_atomic.so.1.71.0
libUserDB-dev.so: CMakeFiles/UserDB-dev.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/DataBases/PostgresDB/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library libUserDB-dev.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/UserDB-dev.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/UserDB-dev.dir/build: libUserDB-dev.so

.PHONY : CMakeFiles/UserDB-dev.dir/build

CMakeFiles/UserDB-dev.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/UserDB-dev.dir/cmake_clean.cmake
.PHONY : CMakeFiles/UserDB-dev.dir/clean

CMakeFiles/UserDB-dev.dir/depend:
	cd /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/DataBases/PostgresDB/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/DataBases/PostgresDB /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/DataBases/PostgresDB /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/DataBases/PostgresDB/build /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/DataBases/PostgresDB/build /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/DataBases/PostgresDB/build/CMakeFiles/UserDB-dev.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/UserDB-dev.dir/depend

