cmake_minimum_required(VERSION 3.16)
project(Synchronisator)
set(CMAKE_CXX_STANDARD 20)

INCLUDE_DIRECTORIES(include)


add_executable(Synchronisator src/Synchronisator.cpp main.cpp)

