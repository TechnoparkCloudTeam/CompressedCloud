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
CMAKE_SOURCE_DIR = /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/build

# Include any dependencies generated for this target.
include CMakeFiles/serverS.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/serverS.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/serverS.dir/flags.make

message.pb.h: ../ServerSync/message.proto
message.pb.h: /usr/bin/protoc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Running cpp protocol buffer compiler on ServerSync/message.proto"
	/usr/bin/protoc --cpp_out /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/build -I /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/ServerSync /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/ServerSync/message.proto

message.pb.cc: message.pb.h
	@$(CMAKE_COMMAND) -E touch_nocreate message.pb.cc

CMakeFiles/serverS.dir/ServerSync/main.cpp.o: CMakeFiles/serverS.dir/flags.make
CMakeFiles/serverS.dir/ServerSync/main.cpp.o: ../ServerSync/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/serverS.dir/ServerSync/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serverS.dir/ServerSync/main.cpp.o -c /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/ServerSync/main.cpp

CMakeFiles/serverS.dir/ServerSync/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverS.dir/ServerSync/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/ServerSync/main.cpp > CMakeFiles/serverS.dir/ServerSync/main.cpp.i

CMakeFiles/serverS.dir/ServerSync/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverS.dir/ServerSync/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/ServerSync/main.cpp -o CMakeFiles/serverS.dir/ServerSync/main.cpp.s

CMakeFiles/serverS.dir/ServerSync/server/src/server.cpp.o: CMakeFiles/serverS.dir/flags.make
CMakeFiles/serverS.dir/ServerSync/server/src/server.cpp.o: ../ServerSync/server/src/server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/serverS.dir/ServerSync/server/src/server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serverS.dir/ServerSync/server/src/server.cpp.o -c /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/ServerSync/server/src/server.cpp

CMakeFiles/serverS.dir/ServerSync/server/src/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverS.dir/ServerSync/server/src/server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/ServerSync/server/src/server.cpp > CMakeFiles/serverS.dir/ServerSync/server/src/server.cpp.i

CMakeFiles/serverS.dir/ServerSync/server/src/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverS.dir/ServerSync/server/src/server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/ServerSync/server/src/server.cpp -o CMakeFiles/serverS.dir/ServerSync/server/src/server.cpp.s

CMakeFiles/serverS.dir/ServerSync/connection/src/connection.cpp.o: CMakeFiles/serverS.dir/flags.make
CMakeFiles/serverS.dir/ServerSync/connection/src/connection.cpp.o: ../ServerSync/connection/src/connection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/serverS.dir/ServerSync/connection/src/connection.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serverS.dir/ServerSync/connection/src/connection.cpp.o -c /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/ServerSync/connection/src/connection.cpp

CMakeFiles/serverS.dir/ServerSync/connection/src/connection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverS.dir/ServerSync/connection/src/connection.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/ServerSync/connection/src/connection.cpp > CMakeFiles/serverS.dir/ServerSync/connection/src/connection.cpp.i

CMakeFiles/serverS.dir/ServerSync/connection/src/connection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverS.dir/ServerSync/connection/src/connection.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/ServerSync/connection/src/connection.cpp -o CMakeFiles/serverS.dir/ServerSync/connection/src/connection.cpp.s

CMakeFiles/serverS.dir/ServerSync/fileStorageWorker/src/FileStorageWorker.cpp.o: CMakeFiles/serverS.dir/flags.make
CMakeFiles/serverS.dir/ServerSync/fileStorageWorker/src/FileStorageWorker.cpp.o: ../ServerSync/fileStorageWorker/src/FileStorageWorker.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/serverS.dir/ServerSync/fileStorageWorker/src/FileStorageWorker.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serverS.dir/ServerSync/fileStorageWorker/src/FileStorageWorker.cpp.o -c /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/ServerSync/fileStorageWorker/src/FileStorageWorker.cpp

CMakeFiles/serverS.dir/ServerSync/fileStorageWorker/src/FileStorageWorker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverS.dir/ServerSync/fileStorageWorker/src/FileStorageWorker.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/ServerSync/fileStorageWorker/src/FileStorageWorker.cpp > CMakeFiles/serverS.dir/ServerSync/fileStorageWorker/src/FileStorageWorker.cpp.i

CMakeFiles/serverS.dir/ServerSync/fileStorageWorker/src/FileStorageWorker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverS.dir/ServerSync/fileStorageWorker/src/FileStorageWorker.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/ServerSync/fileStorageWorker/src/FileStorageWorker.cpp -o CMakeFiles/serverS.dir/ServerSync/fileStorageWorker/src/FileStorageWorker.cpp.s

CMakeFiles/serverS.dir/DataBases/PostgresDB/Base/src/PostgreSQLDB.cpp.o: CMakeFiles/serverS.dir/flags.make
CMakeFiles/serverS.dir/DataBases/PostgresDB/Base/src/PostgreSQLDB.cpp.o: ../DataBases/PostgresDB/Base/src/PostgreSQLDB.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/serverS.dir/DataBases/PostgresDB/Base/src/PostgreSQLDB.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serverS.dir/DataBases/PostgresDB/Base/src/PostgreSQLDB.cpp.o -c /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/DataBases/PostgresDB/Base/src/PostgreSQLDB.cpp

CMakeFiles/serverS.dir/DataBases/PostgresDB/Base/src/PostgreSQLDB.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverS.dir/DataBases/PostgresDB/Base/src/PostgreSQLDB.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/DataBases/PostgresDB/Base/src/PostgreSQLDB.cpp > CMakeFiles/serverS.dir/DataBases/PostgresDB/Base/src/PostgreSQLDB.cpp.i

CMakeFiles/serverS.dir/DataBases/PostgresDB/Base/src/PostgreSQLDB.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverS.dir/DataBases/PostgresDB/Base/src/PostgreSQLDB.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/DataBases/PostgresDB/Base/src/PostgreSQLDB.cpp -o CMakeFiles/serverS.dir/DataBases/PostgresDB/Base/src/PostgreSQLDB.cpp.s

CMakeFiles/serverS.dir/DataBases/PostgresDB/MetaDB/src/MetaDB.cpp.o: CMakeFiles/serverS.dir/flags.make
CMakeFiles/serverS.dir/DataBases/PostgresDB/MetaDB/src/MetaDB.cpp.o: ../DataBases/PostgresDB/MetaDB/src/MetaDB.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/serverS.dir/DataBases/PostgresDB/MetaDB/src/MetaDB.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serverS.dir/DataBases/PostgresDB/MetaDB/src/MetaDB.cpp.o -c /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/DataBases/PostgresDB/MetaDB/src/MetaDB.cpp

CMakeFiles/serverS.dir/DataBases/PostgresDB/MetaDB/src/MetaDB.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverS.dir/DataBases/PostgresDB/MetaDB/src/MetaDB.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/DataBases/PostgresDB/MetaDB/src/MetaDB.cpp > CMakeFiles/serverS.dir/DataBases/PostgresDB/MetaDB/src/MetaDB.cpp.i

CMakeFiles/serverS.dir/DataBases/PostgresDB/MetaDB/src/MetaDB.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverS.dir/DataBases/PostgresDB/MetaDB/src/MetaDB.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/DataBases/PostgresDB/MetaDB/src/MetaDB.cpp -o CMakeFiles/serverS.dir/DataBases/PostgresDB/MetaDB/src/MetaDB.cpp.s

CMakeFiles/serverS.dir/DataBases/PostgresDB/UserDB/src/UserDB.cpp.o: CMakeFiles/serverS.dir/flags.make
CMakeFiles/serverS.dir/DataBases/PostgresDB/UserDB/src/UserDB.cpp.o: ../DataBases/PostgresDB/UserDB/src/UserDB.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/serverS.dir/DataBases/PostgresDB/UserDB/src/UserDB.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serverS.dir/DataBases/PostgresDB/UserDB/src/UserDB.cpp.o -c /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/DataBases/PostgresDB/UserDB/src/UserDB.cpp

CMakeFiles/serverS.dir/DataBases/PostgresDB/UserDB/src/UserDB.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverS.dir/DataBases/PostgresDB/UserDB/src/UserDB.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/DataBases/PostgresDB/UserDB/src/UserDB.cpp > CMakeFiles/serverS.dir/DataBases/PostgresDB/UserDB/src/UserDB.cpp.i

CMakeFiles/serverS.dir/DataBases/PostgresDB/UserDB/src/UserDB.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverS.dir/DataBases/PostgresDB/UserDB/src/UserDB.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/DataBases/PostgresDB/UserDB/src/UserDB.cpp -o CMakeFiles/serverS.dir/DataBases/PostgresDB/UserDB/src/UserDB.cpp.s

CMakeFiles/serverS.dir/message.pb.cc.o: CMakeFiles/serverS.dir/flags.make
CMakeFiles/serverS.dir/message.pb.cc.o: message.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/serverS.dir/message.pb.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serverS.dir/message.pb.cc.o -c /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/build/message.pb.cc

CMakeFiles/serverS.dir/message.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverS.dir/message.pb.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/build/message.pb.cc > CMakeFiles/serverS.dir/message.pb.cc.i

CMakeFiles/serverS.dir/message.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverS.dir/message.pb.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/build/message.pb.cc -o CMakeFiles/serverS.dir/message.pb.cc.s

# Object files for target serverS
serverS_OBJECTS = \
"CMakeFiles/serverS.dir/ServerSync/main.cpp.o" \
"CMakeFiles/serverS.dir/ServerSync/server/src/server.cpp.o" \
"CMakeFiles/serverS.dir/ServerSync/connection/src/connection.cpp.o" \
"CMakeFiles/serverS.dir/ServerSync/fileStorageWorker/src/FileStorageWorker.cpp.o" \
"CMakeFiles/serverS.dir/DataBases/PostgresDB/Base/src/PostgreSQLDB.cpp.o" \
"CMakeFiles/serverS.dir/DataBases/PostgresDB/MetaDB/src/MetaDB.cpp.o" \
"CMakeFiles/serverS.dir/DataBases/PostgresDB/UserDB/src/UserDB.cpp.o" \
"CMakeFiles/serverS.dir/message.pb.cc.o"

# External object files for target serverS
serverS_EXTERNAL_OBJECTS =

serverS: CMakeFiles/serverS.dir/ServerSync/main.cpp.o
serverS: CMakeFiles/serverS.dir/ServerSync/server/src/server.cpp.o
serverS: CMakeFiles/serverS.dir/ServerSync/connection/src/connection.cpp.o
serverS: CMakeFiles/serverS.dir/ServerSync/fileStorageWorker/src/FileStorageWorker.cpp.o
serverS: CMakeFiles/serverS.dir/DataBases/PostgresDB/Base/src/PostgreSQLDB.cpp.o
serverS: CMakeFiles/serverS.dir/DataBases/PostgresDB/MetaDB/src/MetaDB.cpp.o
serverS: CMakeFiles/serverS.dir/DataBases/PostgresDB/UserDB/src/UserDB.cpp.o
serverS: CMakeFiles/serverS.dir/message.pb.cc.o
serverS: CMakeFiles/serverS.dir/build.make
serverS: /usr/lib/x86_64-linux-gnu/libboost_system.a
serverS: /usr/lib/x86_64-linux-gnu/libboost_thread.a
serverS: /usr/lib/x86_64-linux-gnu/libprotobuf.so
serverS: /usr/lib/x86_64-linux-gnu/libpq.so
serverS: /usr/lib/x86_64-linux-gnu/libboost_atomic.a
serverS: CMakeFiles/serverS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable serverS"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/serverS.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/serverS.dir/build: serverS

.PHONY : CMakeFiles/serverS.dir/build

CMakeFiles/serverS.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/serverS.dir/cmake_clean.cmake
.PHONY : CMakeFiles/serverS.dir/clean

CMakeFiles/serverS.dir/depend: message.pb.h
CMakeFiles/serverS.dir/depend: message.pb.cc
	cd /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/build /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/build /home/lyalyashechka/TP/c_c++/gitMAIN/CompressedCloud/project/build/CMakeFiles/serverS.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/serverS.dir/depend

