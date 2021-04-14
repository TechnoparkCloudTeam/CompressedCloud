cmake_minimum_required(VERSION 3.16)
project(DataBase)

set(CMAKE_CXX_STANDARD 20)

ADD_SUBDIRECTORY(FileStorage)
ADD_SUBDIRECTORY(MetaDataBase)
INCLUDE_DIRECTORIES(FileStorage/include)
INCLUDE_DIRECTORIES(MetaDataBase/include)
ADD_LIBRARY(network STATIC
        FileStorage/src/FileStorage.cpp
        MetaDataBase/src/MetaDataBase.cpp)

add_executable(DataBase main.cpp)
