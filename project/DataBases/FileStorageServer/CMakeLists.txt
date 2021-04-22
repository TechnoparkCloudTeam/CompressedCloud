CMAKE_MINIMUM_REQUIRED(VERSION 3.16)
PROJECT(FileStorageServer)

SET(CMAKE_CXX_STANDARD 20)

INCLUDE_DIRECTORIES(include)

ADD_LIBRARY(filestoragelib STATIC
        src/FileStorage.cpp
        )
ADD_EXECUTABLE(FileStorageServer main.cpp)
