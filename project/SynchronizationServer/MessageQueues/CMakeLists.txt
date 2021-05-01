cmake_minimum_required(VERSION 3.16)

project(MessageQueues)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)
include_directories(../Sessions/SessionOnServer/include)

add_executable(MessageQueues src/MessageQueues.cpp main.cpp)
