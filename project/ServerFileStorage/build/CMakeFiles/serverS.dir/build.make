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
CMAKE_SOURCE_DIR = /home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerFileStorage

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerFileStorage/build

# Include any dependencies generated for this target.
include CMakeFiles/serverS.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/serverS.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/serverS.dir/flags.make

message.pb.h: ../message.proto
message.pb.h: /usr/bin/protoc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerFileStorage/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Running cpp protocol buffer compiler on message.proto"
	/usr/bin/protoc --cpp_out /home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerFileStorage/build -I /home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerFileStorage /home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerFileStorage/message.proto

message.pb.cc: message.pb.h
	@$(CMAKE_COMMAND) -E touch_nocreate message.pb.cc

CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/main.cpp.o: CMakeFiles/serverS.dir/flags.make
CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/main.cpp.o: /home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerFileStorage/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/main.cpp.o -c /home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/main.cpp

CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/main.cpp > CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/main.cpp.i

CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/main.cpp -o CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/main.cpp.s

CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/server/src/server.cpp.o: CMakeFiles/serverS.dir/flags.make
CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/server/src/server.cpp.o: /home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/server/src/server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerFileStorage/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/server/src/server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/server/src/server.cpp.o -c /home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/server/src/server.cpp

CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/server/src/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/server/src/server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/server/src/server.cpp > CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/server/src/server.cpp.i

CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/server/src/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/server/src/server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/server/src/server.cpp -o CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/server/src/server.cpp.s

CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/connection/src/connection.cpp.o: CMakeFiles/serverS.dir/flags.make
CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/connection/src/connection.cpp.o: /home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/connection/src/connection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerFileStorage/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/connection/src/connection.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/connection/src/connection.cpp.o -c /home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/connection/src/connection.cpp

CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/connection/src/connection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/connection/src/connection.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/connection/src/connection.cpp > CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/connection/src/connection.cpp.i

CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/connection/src/connection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/connection/src/connection.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/connection/src/connection.cpp -o CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/connection/src/connection.cpp.s

CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/fileStorageWorker/src/FileStorageWorker.cpp.o: CMakeFiles/serverS.dir/flags.make
CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/fileStorageWorker/src/FileStorageWorker.cpp.o: /home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/fileStorageWorker/src/FileStorageWorker.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerFileStorage/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/fileStorageWorker/src/FileStorageWorker.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/fileStorageWorker/src/FileStorageWorker.cpp.o -c /home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/fileStorageWorker/src/FileStorageWorker.cpp

CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/fileStorageWorker/src/FileStorageWorker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/fileStorageWorker/src/FileStorageWorker.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/fileStorageWorker/src/FileStorageWorker.cpp > CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/fileStorageWorker/src/FileStorageWorker.cpp.i

CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/fileStorageWorker/src/FileStorageWorker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/fileStorageWorker/src/FileStorageWorker.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/fileStorageWorker/src/FileStorageWorker.cpp -o CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/fileStorageWorker/src/FileStorageWorker.cpp.s

CMakeFiles/serverS.dir/message.pb.cc.o: CMakeFiles/serverS.dir/flags.make
CMakeFiles/serverS.dir/message.pb.cc.o: message.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerFileStorage/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/serverS.dir/message.pb.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serverS.dir/message.pb.cc.o -c /home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerFileStorage/build/message.pb.cc

CMakeFiles/serverS.dir/message.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverS.dir/message.pb.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerFileStorage/build/message.pb.cc > CMakeFiles/serverS.dir/message.pb.cc.i

CMakeFiles/serverS.dir/message.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverS.dir/message.pb.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerFileStorage/build/message.pb.cc -o CMakeFiles/serverS.dir/message.pb.cc.s

# Object files for target serverS
serverS_OBJECTS = \
"CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/main.cpp.o" \
"CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/server/src/server.cpp.o" \
"CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/connection/src/connection.cpp.o" \
"CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/fileStorageWorker/src/FileStorageWorker.cpp.o" \
"CMakeFiles/serverS.dir/message.pb.cc.o"

# External object files for target serverS
serverS_EXTERNAL_OBJECTS =

serverS: CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/main.cpp.o
serverS: CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/server/src/server.cpp.o
serverS: CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/connection/src/connection.cpp.o
serverS: CMakeFiles/serverS.dir/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerSync/fileStorageWorker/src/FileStorageWorker.cpp.o
serverS: CMakeFiles/serverS.dir/message.pb.cc.o
serverS: CMakeFiles/serverS.dir/build.make
serverS: /usr/lib/x86_64-linux-gnu/libboost_system.a
serverS: /usr/lib/x86_64-linux-gnu/libboost_thread.a
serverS: /usr/lib/x86_64-linux-gnu/libprotobuf.so
serverS: /usr/lib/x86_64-linux-gnu/libboost_atomic.a
serverS: CMakeFiles/serverS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerFileStorage/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable serverS"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/serverS.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/serverS.dir/build: serverS

.PHONY : CMakeFiles/serverS.dir/build

CMakeFiles/serverS.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/serverS.dir/cmake_clean.cmake
.PHONY : CMakeFiles/serverS.dir/clean

CMakeFiles/serverS.dir/depend: message.pb.h
CMakeFiles/serverS.dir/depend: message.pb.cc
	cd /home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerFileStorage/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerFileStorage /home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerFileStorage /home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerFileStorage/build /home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerFileStorage/build /home/lyalyashechka/TP/c_c++/cloudgitmain/CompressedCloud/project/ServerFileStorage/build/CMakeFiles/serverS.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/serverS.dir/depend
