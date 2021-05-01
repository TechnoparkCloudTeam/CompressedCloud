cmake_minimum_required(VERSION 3.16)
project(DataBases)

set(CMAKE_CXX_STANDARD 20)

ADD_SUBDIRECTORY(LocalDB)
ADD_SUBDIRECTORY(FileStorageServer)
ADD_SUBDIRECTORY(DataBase)
ADD_SUBDIRECTORY(Tests)
INCLUDE_DIRECTORIES(LocalDB/include)
INCLUDE_DIRECTORIES(FileStorageServer/include)
INCLUDE_DIRECTORIES(DataBase/include)
ADD_LIBRARY(alldblib STATIC
        LocalDB/src/LocalDB.cpp
        LocalDB/src/ChunkDB.cpp
        LocalDB/src/UserDB.cpp
        LocalDB/src/FileDB.cpp
        LocalDB/src/DeviceDB.cpp
        FileStorageServer/src/FileStorage.cpp
        DataBase/src/UserInfoDB.cpp
        DataBase/src/PostgresDB.cpp
        DataBase/src/MetaDB.cpp
        DataBase/src/Commands.cpp)
add_executable(DataBases main.cpp)
