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
CMAKE_SOURCE_DIR = /home/ilya/TechnoParkProjects/CompressedCloud/Client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ilya/TechnoParkProjects/CompressedCloud/Client/build

# Include any dependencies generated for this target.
include CMakeFiles/Client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Client.dir/flags.make

message.pb.h: /home/ilya/TechnoParkProjects/CompressedCloud/Server/ServerSynch/message.proto
message.pb.h: /usr/bin/protoc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ilya/TechnoParkProjects/CompressedCloud/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Running cpp protocol buffer compiler on ../Server/ServerSynch/message.proto"
	/usr/bin/protoc --cpp_out /home/ilya/TechnoParkProjects/CompressedCloud/Client/build -I /home/ilya/TechnoParkProjects/CompressedCloud/Server/ServerSynch /home/ilya/TechnoParkProjects/CompressedCloud/Server/ServerSynch/message.proto

message.pb.cc: message.pb.h
	@$(CMAKE_COMMAND) -E touch_nocreate message.pb.cc

CMakeFiles/Client.dir/main.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/TechnoParkProjects/CompressedCloud/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Client.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/main.cpp.o -c /home/ilya/TechnoParkProjects/CompressedCloud/Client/main.cpp

CMakeFiles/Client.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/TechnoParkProjects/CompressedCloud/Client/main.cpp > CMakeFiles/Client.dir/main.cpp.i

CMakeFiles/Client.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/TechnoParkProjects/CompressedCloud/Client/main.cpp -o CMakeFiles/Client.dir/main.cpp.s

CMakeFiles/Client.dir/home/ilya/TechnoParkProjects/CompressedCloud/DataBases/LocalDB/src/LocalDB.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/home/ilya/TechnoParkProjects/CompressedCloud/DataBases/LocalDB/src/LocalDB.cpp.o: /home/ilya/TechnoParkProjects/CompressedCloud/DataBases/LocalDB/src/LocalDB.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/TechnoParkProjects/CompressedCloud/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Client.dir/home/ilya/TechnoParkProjects/CompressedCloud/DataBases/LocalDB/src/LocalDB.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/home/ilya/TechnoParkProjects/CompressedCloud/DataBases/LocalDB/src/LocalDB.cpp.o -c /home/ilya/TechnoParkProjects/CompressedCloud/DataBases/LocalDB/src/LocalDB.cpp

CMakeFiles/Client.dir/home/ilya/TechnoParkProjects/CompressedCloud/DataBases/LocalDB/src/LocalDB.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/home/ilya/TechnoParkProjects/CompressedCloud/DataBases/LocalDB/src/LocalDB.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/TechnoParkProjects/CompressedCloud/DataBases/LocalDB/src/LocalDB.cpp > CMakeFiles/Client.dir/home/ilya/TechnoParkProjects/CompressedCloud/DataBases/LocalDB/src/LocalDB.cpp.i

CMakeFiles/Client.dir/home/ilya/TechnoParkProjects/CompressedCloud/DataBases/LocalDB/src/LocalDB.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/home/ilya/TechnoParkProjects/CompressedCloud/DataBases/LocalDB/src/LocalDB.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/TechnoParkProjects/CompressedCloud/DataBases/LocalDB/src/LocalDB.cpp -o CMakeFiles/Client.dir/home/ilya/TechnoParkProjects/CompressedCloud/DataBases/LocalDB/src/LocalDB.cpp.s

CMakeFiles/Client.dir/ProgramInterface/src/ProgramInterface.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/ProgramInterface/src/ProgramInterface.cpp.o: ../ProgramInterface/src/ProgramInterface.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/TechnoParkProjects/CompressedCloud/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Client.dir/ProgramInterface/src/ProgramInterface.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/ProgramInterface/src/ProgramInterface.cpp.o -c /home/ilya/TechnoParkProjects/CompressedCloud/Client/ProgramInterface/src/ProgramInterface.cpp

CMakeFiles/Client.dir/ProgramInterface/src/ProgramInterface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/ProgramInterface/src/ProgramInterface.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/TechnoParkProjects/CompressedCloud/Client/ProgramInterface/src/ProgramInterface.cpp > CMakeFiles/Client.dir/ProgramInterface/src/ProgramInterface.cpp.i

CMakeFiles/Client.dir/ProgramInterface/src/ProgramInterface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/ProgramInterface/src/ProgramInterface.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/TechnoParkProjects/CompressedCloud/Client/ProgramInterface/src/ProgramInterface.cpp -o CMakeFiles/Client.dir/ProgramInterface/src/ProgramInterface.cpp.s

CMakeFiles/Client.dir/Application/src/Application.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/Application/src/Application.cpp.o: ../Application/src/Application.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/TechnoParkProjects/CompressedCloud/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Client.dir/Application/src/Application.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/Application/src/Application.cpp.o -c /home/ilya/TechnoParkProjects/CompressedCloud/Client/Application/src/Application.cpp

CMakeFiles/Client.dir/Application/src/Application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/Application/src/Application.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/TechnoParkProjects/CompressedCloud/Client/Application/src/Application.cpp > CMakeFiles/Client.dir/Application/src/Application.cpp.i

CMakeFiles/Client.dir/Application/src/Application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/Application/src/Application.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/TechnoParkProjects/CompressedCloud/Client/Application/src/Application.cpp -o CMakeFiles/Client.dir/Application/src/Application.cpp.s

CMakeFiles/Client.dir/Indexer/src/Indexer.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/Indexer/src/Indexer.cpp.o: ../Indexer/src/Indexer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/TechnoParkProjects/CompressedCloud/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Client.dir/Indexer/src/Indexer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/Indexer/src/Indexer.cpp.o -c /home/ilya/TechnoParkProjects/CompressedCloud/Client/Indexer/src/Indexer.cpp

CMakeFiles/Client.dir/Indexer/src/Indexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/Indexer/src/Indexer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/TechnoParkProjects/CompressedCloud/Client/Indexer/src/Indexer.cpp > CMakeFiles/Client.dir/Indexer/src/Indexer.cpp.i

CMakeFiles/Client.dir/Indexer/src/Indexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/Indexer/src/Indexer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/TechnoParkProjects/CompressedCloud/Client/Indexer/src/Indexer.cpp -o CMakeFiles/Client.dir/Indexer/src/Indexer.cpp.s

CMakeFiles/Client.dir/home/ilya/TechnoParkProjects/CompressedCloud/Server/ServerFileStorage/fileStorageWorker/src/FileStorageWorker.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/home/ilya/TechnoParkProjects/CompressedCloud/Server/ServerFileStorage/fileStorageWorker/src/FileStorageWorker.cpp.o: /home/ilya/TechnoParkProjects/CompressedCloud/Server/ServerFileStorage/fileStorageWorker/src/FileStorageWorker.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/TechnoParkProjects/CompressedCloud/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Client.dir/home/ilya/TechnoParkProjects/CompressedCloud/Server/ServerFileStorage/fileStorageWorker/src/FileStorageWorker.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/home/ilya/TechnoParkProjects/CompressedCloud/Server/ServerFileStorage/fileStorageWorker/src/FileStorageWorker.cpp.o -c /home/ilya/TechnoParkProjects/CompressedCloud/Server/ServerFileStorage/fileStorageWorker/src/FileStorageWorker.cpp

CMakeFiles/Client.dir/home/ilya/TechnoParkProjects/CompressedCloud/Server/ServerFileStorage/fileStorageWorker/src/FileStorageWorker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/home/ilya/TechnoParkProjects/CompressedCloud/Server/ServerFileStorage/fileStorageWorker/src/FileStorageWorker.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/TechnoParkProjects/CompressedCloud/Server/ServerFileStorage/fileStorageWorker/src/FileStorageWorker.cpp > CMakeFiles/Client.dir/home/ilya/TechnoParkProjects/CompressedCloud/Server/ServerFileStorage/fileStorageWorker/src/FileStorageWorker.cpp.i

CMakeFiles/Client.dir/home/ilya/TechnoParkProjects/CompressedCloud/Server/ServerFileStorage/fileStorageWorker/src/FileStorageWorker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/home/ilya/TechnoParkProjects/CompressedCloud/Server/ServerFileStorage/fileStorageWorker/src/FileStorageWorker.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/TechnoParkProjects/CompressedCloud/Server/ServerFileStorage/fileStorageWorker/src/FileStorageWorker.cpp -o CMakeFiles/Client.dir/home/ilya/TechnoParkProjects/CompressedCloud/Server/ServerFileStorage/fileStorageWorker/src/FileStorageWorker.cpp.s

CMakeFiles/Client.dir/home/ilya/TechnoParkProjects/CompressedCloud/Server/ClientNetwork/src/ClientNetwork.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/home/ilya/TechnoParkProjects/CompressedCloud/Server/ClientNetwork/src/ClientNetwork.cpp.o: /home/ilya/TechnoParkProjects/CompressedCloud/Server/ClientNetwork/src/ClientNetwork.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/TechnoParkProjects/CompressedCloud/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Client.dir/home/ilya/TechnoParkProjects/CompressedCloud/Server/ClientNetwork/src/ClientNetwork.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/home/ilya/TechnoParkProjects/CompressedCloud/Server/ClientNetwork/src/ClientNetwork.cpp.o -c /home/ilya/TechnoParkProjects/CompressedCloud/Server/ClientNetwork/src/ClientNetwork.cpp

CMakeFiles/Client.dir/home/ilya/TechnoParkProjects/CompressedCloud/Server/ClientNetwork/src/ClientNetwork.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/home/ilya/TechnoParkProjects/CompressedCloud/Server/ClientNetwork/src/ClientNetwork.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/TechnoParkProjects/CompressedCloud/Server/ClientNetwork/src/ClientNetwork.cpp > CMakeFiles/Client.dir/home/ilya/TechnoParkProjects/CompressedCloud/Server/ClientNetwork/src/ClientNetwork.cpp.i

CMakeFiles/Client.dir/home/ilya/TechnoParkProjects/CompressedCloud/Server/ClientNetwork/src/ClientNetwork.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/home/ilya/TechnoParkProjects/CompressedCloud/Server/ClientNetwork/src/ClientNetwork.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/TechnoParkProjects/CompressedCloud/Server/ClientNetwork/src/ClientNetwork.cpp -o CMakeFiles/Client.dir/home/ilya/TechnoParkProjects/CompressedCloud/Server/ClientNetwork/src/ClientNetwork.cpp.s

CMakeFiles/Client.dir/Watcher/src/FileSysEvent.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/Watcher/src/FileSysEvent.cpp.o: ../Watcher/src/FileSysEvent.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/TechnoParkProjects/CompressedCloud/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Client.dir/Watcher/src/FileSysEvent.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/Watcher/src/FileSysEvent.cpp.o -c /home/ilya/TechnoParkProjects/CompressedCloud/Client/Watcher/src/FileSysEvent.cpp

CMakeFiles/Client.dir/Watcher/src/FileSysEvent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/Watcher/src/FileSysEvent.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/TechnoParkProjects/CompressedCloud/Client/Watcher/src/FileSysEvent.cpp > CMakeFiles/Client.dir/Watcher/src/FileSysEvent.cpp.i

CMakeFiles/Client.dir/Watcher/src/FileSysEvent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/Watcher/src/FileSysEvent.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/TechnoParkProjects/CompressedCloud/Client/Watcher/src/FileSysEvent.cpp -o CMakeFiles/Client.dir/Watcher/src/FileSysEvent.cpp.s

CMakeFiles/Client.dir/Watcher/src/Watcher.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/Watcher/src/Watcher.cpp.o: ../Watcher/src/Watcher.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/TechnoParkProjects/CompressedCloud/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Client.dir/Watcher/src/Watcher.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/Watcher/src/Watcher.cpp.o -c /home/ilya/TechnoParkProjects/CompressedCloud/Client/Watcher/src/Watcher.cpp

CMakeFiles/Client.dir/Watcher/src/Watcher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/Watcher/src/Watcher.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/TechnoParkProjects/CompressedCloud/Client/Watcher/src/Watcher.cpp > CMakeFiles/Client.dir/Watcher/src/Watcher.cpp.i

CMakeFiles/Client.dir/Watcher/src/Watcher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/Watcher/src/Watcher.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/TechnoParkProjects/CompressedCloud/Client/Watcher/src/Watcher.cpp -o CMakeFiles/Client.dir/Watcher/src/Watcher.cpp.s

CMakeFiles/Client.dir/Watcher/src/WatcherMessage.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/Watcher/src/WatcherMessage.cpp.o: ../Watcher/src/WatcherMessage.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/TechnoParkProjects/CompressedCloud/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Client.dir/Watcher/src/WatcherMessage.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/Watcher/src/WatcherMessage.cpp.o -c /home/ilya/TechnoParkProjects/CompressedCloud/Client/Watcher/src/WatcherMessage.cpp

CMakeFiles/Client.dir/Watcher/src/WatcherMessage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/Watcher/src/WatcherMessage.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/TechnoParkProjects/CompressedCloud/Client/Watcher/src/WatcherMessage.cpp > CMakeFiles/Client.dir/Watcher/src/WatcherMessage.cpp.i

CMakeFiles/Client.dir/Watcher/src/WatcherMessage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/Watcher/src/WatcherMessage.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/TechnoParkProjects/CompressedCloud/Client/Watcher/src/WatcherMessage.cpp -o CMakeFiles/Client.dir/Watcher/src/WatcherMessage.cpp.s

CMakeFiles/Client.dir/Watcher/src/WatcherNotification.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/Watcher/src/WatcherNotification.cpp.o: ../Watcher/src/WatcherNotification.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/TechnoParkProjects/CompressedCloud/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Client.dir/Watcher/src/WatcherNotification.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/Watcher/src/WatcherNotification.cpp.o -c /home/ilya/TechnoParkProjects/CompressedCloud/Client/Watcher/src/WatcherNotification.cpp

CMakeFiles/Client.dir/Watcher/src/WatcherNotification.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/Watcher/src/WatcherNotification.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/TechnoParkProjects/CompressedCloud/Client/Watcher/src/WatcherNotification.cpp > CMakeFiles/Client.dir/Watcher/src/WatcherNotification.cpp.i

CMakeFiles/Client.dir/Watcher/src/WatcherNotification.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/Watcher/src/WatcherNotification.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/TechnoParkProjects/CompressedCloud/Client/Watcher/src/WatcherNotification.cpp -o CMakeFiles/Client.dir/Watcher/src/WatcherNotification.cpp.s

CMakeFiles/Client.dir/Watcher/src/WatcherNotifierBuilder.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/Watcher/src/WatcherNotifierBuilder.cpp.o: ../Watcher/src/WatcherNotifierBuilder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/TechnoParkProjects/CompressedCloud/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/Client.dir/Watcher/src/WatcherNotifierBuilder.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/Watcher/src/WatcherNotifierBuilder.cpp.o -c /home/ilya/TechnoParkProjects/CompressedCloud/Client/Watcher/src/WatcherNotifierBuilder.cpp

CMakeFiles/Client.dir/Watcher/src/WatcherNotifierBuilder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/Watcher/src/WatcherNotifierBuilder.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/TechnoParkProjects/CompressedCloud/Client/Watcher/src/WatcherNotifierBuilder.cpp > CMakeFiles/Client.dir/Watcher/src/WatcherNotifierBuilder.cpp.i

CMakeFiles/Client.dir/Watcher/src/WatcherNotifierBuilder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/Watcher/src/WatcherNotifierBuilder.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/TechnoParkProjects/CompressedCloud/Client/Watcher/src/WatcherNotifierBuilder.cpp -o CMakeFiles/Client.dir/Watcher/src/WatcherNotifierBuilder.cpp.s

CMakeFiles/Client.dir/message.pb.cc.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/message.pb.cc.o: message.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/TechnoParkProjects/CompressedCloud/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/Client.dir/message.pb.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/message.pb.cc.o -c /home/ilya/TechnoParkProjects/CompressedCloud/Client/build/message.pb.cc

CMakeFiles/Client.dir/message.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/message.pb.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/TechnoParkProjects/CompressedCloud/Client/build/message.pb.cc > CMakeFiles/Client.dir/message.pb.cc.i

CMakeFiles/Client.dir/message.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/message.pb.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/TechnoParkProjects/CompressedCloud/Client/build/message.pb.cc -o CMakeFiles/Client.dir/message.pb.cc.s

# Object files for target Client
Client_OBJECTS = \
"CMakeFiles/Client.dir/main.cpp.o" \
"CMakeFiles/Client.dir/home/ilya/TechnoParkProjects/CompressedCloud/DataBases/LocalDB/src/LocalDB.cpp.o" \
"CMakeFiles/Client.dir/ProgramInterface/src/ProgramInterface.cpp.o" \
"CMakeFiles/Client.dir/Application/src/Application.cpp.o" \
"CMakeFiles/Client.dir/Indexer/src/Indexer.cpp.o" \
"CMakeFiles/Client.dir/home/ilya/TechnoParkProjects/CompressedCloud/Server/ServerFileStorage/fileStorageWorker/src/FileStorageWorker.cpp.o" \
"CMakeFiles/Client.dir/home/ilya/TechnoParkProjects/CompressedCloud/Server/ClientNetwork/src/ClientNetwork.cpp.o" \
"CMakeFiles/Client.dir/Watcher/src/FileSysEvent.cpp.o" \
"CMakeFiles/Client.dir/Watcher/src/Watcher.cpp.o" \
"CMakeFiles/Client.dir/Watcher/src/WatcherMessage.cpp.o" \
"CMakeFiles/Client.dir/Watcher/src/WatcherNotification.cpp.o" \
"CMakeFiles/Client.dir/Watcher/src/WatcherNotifierBuilder.cpp.o" \
"CMakeFiles/Client.dir/message.pb.cc.o"

# External object files for target Client
Client_EXTERNAL_OBJECTS =

Client: CMakeFiles/Client.dir/main.cpp.o
Client: CMakeFiles/Client.dir/home/ilya/TechnoParkProjects/CompressedCloud/DataBases/LocalDB/src/LocalDB.cpp.o
Client: CMakeFiles/Client.dir/ProgramInterface/src/ProgramInterface.cpp.o
Client: CMakeFiles/Client.dir/Application/src/Application.cpp.o
Client: CMakeFiles/Client.dir/Indexer/src/Indexer.cpp.o
Client: CMakeFiles/Client.dir/home/ilya/TechnoParkProjects/CompressedCloud/Server/ServerFileStorage/fileStorageWorker/src/FileStorageWorker.cpp.o
Client: CMakeFiles/Client.dir/home/ilya/TechnoParkProjects/CompressedCloud/Server/ClientNetwork/src/ClientNetwork.cpp.o
Client: CMakeFiles/Client.dir/Watcher/src/FileSysEvent.cpp.o
Client: CMakeFiles/Client.dir/Watcher/src/Watcher.cpp.o
Client: CMakeFiles/Client.dir/Watcher/src/WatcherMessage.cpp.o
Client: CMakeFiles/Client.dir/Watcher/src/WatcherNotification.cpp.o
Client: CMakeFiles/Client.dir/Watcher/src/WatcherNotifierBuilder.cpp.o
Client: CMakeFiles/Client.dir/message.pb.cc.o
Client: CMakeFiles/Client.dir/build.make
Client: /usr/lib/x86_64-linux-gnu/libsqlite3.so
Client: /usr/lib/x86_64-linux-gnu/libboost_log.a
Client: /usr/lib/x86_64-linux-gnu/libprotobuf.so
Client: /usr/lib/x86_64-linux-gnu/libboost_chrono.a
Client: /usr/lib/x86_64-linux-gnu/libboost_date_time.a
Client: /usr/lib/x86_64-linux-gnu/libboost_filesystem.a
Client: /usr/lib/x86_64-linux-gnu/libboost_regex.a
Client: /usr/lib/x86_64-linux-gnu/libboost_thread.a
Client: /usr/lib/x86_64-linux-gnu/libboost_atomic.a
Client: CMakeFiles/Client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ilya/TechnoParkProjects/CompressedCloud/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX executable Client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Client.dir/build: Client

.PHONY : CMakeFiles/Client.dir/build

CMakeFiles/Client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Client.dir/clean

CMakeFiles/Client.dir/depend: message.pb.h
CMakeFiles/Client.dir/depend: message.pb.cc
	cd /home/ilya/TechnoParkProjects/CompressedCloud/Client/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ilya/TechnoParkProjects/CompressedCloud/Client /home/ilya/TechnoParkProjects/CompressedCloud/Client /home/ilya/TechnoParkProjects/CompressedCloud/Client/build /home/ilya/TechnoParkProjects/CompressedCloud/Client/build /home/ilya/TechnoParkProjects/CompressedCloud/Client/build/CMakeFiles/Client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Client.dir/depend
