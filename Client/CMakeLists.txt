cmake_minimum_required(VERSION 3.16)
project(Client)

set(CMAKE_CXX_STANDARD 20)

ADD_SUBDIRECTORY(Watcher)
ADD_SUBDIRECTORY(ProgramInterface)
ADD_SUBDIRECTORY(Chunker)

INCLUDE_DIRECTORIES(ProgramInterface/include)
INCLUDE_DIRECTORIES(Chunker/include)
INCLUDE_DIRECTORIES(Watcher/include)
ADD_LIBRARY(clientlib STATIC
        Watcher/src/Watcher.cpp
        ProgramInterface/src/ProgramInterface.cpp
        Chunker/src/Chunker.cpp)

add_executable(Client main.cpp)

