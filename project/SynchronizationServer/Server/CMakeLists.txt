cmake_minimum_required(VERSION 3.16)

project(Server)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)
include_directories(../Synchronizator/include)
include_directories(../MessageQueues/include)

add_executable(Server src/Server.cpp main.cpp)
