CMAKE_MINIMUM_REQUIRED(VERSION 3.16)
PROJECT(LocalDB)

SET(CMAKE_CXX_STANDARD 20)

INCLUDE_DIRECTORIES(include)

ADD_LIBRARY(localdblib STATIC
        src/LocalDB.cpp
        src/ChunkDB.cpp
        src/UserDB.cpp
        src/FileDB.cpp
        src/DeviceDB.cpp
        )
ADD_EXECUTABLE(LocalDB main.cpp)
