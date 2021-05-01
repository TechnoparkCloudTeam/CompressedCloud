cmake_minimum_required(VERSION 3.16)
project(Watcher)

set(CMAKE_CXX_STANDARD 20)

INCLUDE_DIRECTORIES(include)


add_executable(Watcher src/Watcher.cpp main.cpp)
