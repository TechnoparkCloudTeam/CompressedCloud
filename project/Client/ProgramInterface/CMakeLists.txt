cmake_minimum_required(VERSION 3.16)
project(ProgramInterface)

set(CMAKE_CXX_STANDARD 20)

INCLUDE_DIRECTORIES(include)


add_executable(ProgramInterface src/ProgramInterface.cpp main.cpp)
