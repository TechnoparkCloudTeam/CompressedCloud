cmake_minimum_required(VERSION 3.16)
project(Application)
set(CMAKE_CXX_STANDARD 20)

INCLUDE_DIRECTORIES(Application)


add_executable(Application src/Application.cpp main.cpp)

