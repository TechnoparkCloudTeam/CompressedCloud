cmake_minimum_required(VERSION 3.16)
project(Indexer)
set(CMAKE_CXX_STANDARD 20)

INCLUDE_DIRECTORIES(include)


add_executable(Indexer src/Indexer.cpp main.cpp)

