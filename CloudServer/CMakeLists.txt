cmake_minimum_required(VERSION 3.16)

project(CloudServer)

set(CMAKE_CXX_STANDARD 20)

INCLUDE_DIRECTORIES(../SynchronizationServer/Sessions/ClientNetwork/include)
INCLUDE_DIRECTORIES(../SynchronizationServer/Sessions/SessionOnServer/include)

INCLUDE_DIRECTORIES(include)


ADD_LIBRARY(serverCloudlib STATIC
    src/FileStorageServer.cpp
    ../SynchronizationServer/Sessions/SessionOnServer/src/ClientSession.cpp
    ../SynchronizationServer/Sessions/ClientNetwork/src/ClientNetwork.cpp
)



add_executable(servercloud main.cpp)
