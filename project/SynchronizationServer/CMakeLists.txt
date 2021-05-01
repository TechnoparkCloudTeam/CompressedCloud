cmake_minimum_required(VERSION 3.16)

project(SynchronizationServer)

set(CMAKE_CXX_STANDARD 20)

ADD_SUBDIRECTORY(Sessions/SessionOnServer)
ADD_SUBDIRECTORY(Sessions/ClientNetwork)
ADD_SUBDIRECTORY(MessageQueues)
ADD_SUBDIRECTORY(Server)
ADD_SUBDIRECTORY(Synchronizator)
ADD_SUBDIRECTORY(tests)

INCLUDE_DIRECTORIES(Sessions/SessionOnServer/include)
INCLUDE_DIRECTORIES(Sessions/ClientNetwork/include)
INCLUDE_DIRECTORIES(MessageQueues/include)
INCLUDE_DIRECTORIES(Server/include)
INCLUDE_DIRECTORIES(Synchronizator/include)


ADD_LIBRARY(serverlib STATIC
    Sessions/SessionOnServer/src/ClientSession.cpp
    Sessions/ClientNetwork/src/ClientNetwork.cpp
    MessageQueues/src/MessageQueues.cpp
    Synchronizator/src/Synchronizator.cpp
    Server/src/Server.cpp)



add_executable(servers main.cpp)
