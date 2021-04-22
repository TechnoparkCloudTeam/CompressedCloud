cmake_minimum_required(VERSION 3.16)

project(Synchronizator)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)
include_directories(../MessageQueues/include)

add_executable(Synchronizator src/Synchronizator.cpp main.cpp)
