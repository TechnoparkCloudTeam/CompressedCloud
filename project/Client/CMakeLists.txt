cmake_minimum_required(VERSION 3.16)
project(Client)

set(CMAKE_CXX_STANDARD 14)

ADD_SUBDIRECTORY(Watcher)
ADD_SUBDIRECTORY(ProgramInterface)
ADD_SUBDIRECTORY(Chunker)
ADD_SUBDIRECTORY(CommunicateWithServer)

add_executable(Client main.cpp)

