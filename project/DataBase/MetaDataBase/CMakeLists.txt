cmake_minimum_required(VERSION 3.16)
project(MetaDataBase)
set(CMAKE_CXX_STANDARD 20)

INCLUDE_DIRECTORIES(include)


add_executable(MetaDataBase src/MetaDataBase.cpp main.cpp)

