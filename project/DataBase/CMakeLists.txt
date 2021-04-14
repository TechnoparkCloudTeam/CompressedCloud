cmake_minimum_required(VERSION 3.16)
project(DataBase)

set(CMAKE_CXX_STANDARD 20)

ADD_SUBDIRECTORY(FileStorage)
ADD_SUBDIRECTORY(MetaDataBase)

add_executable(DataBase main.cpp)

