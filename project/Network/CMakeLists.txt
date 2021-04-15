
cmake_minimum_required(VERSION 3.16)
project(Network)

set(CMAKE_CXX_STANDARD 20)

ADD_SUBDIRECTORY(CommunicateWithUser)
ADD_SUBDIRECTORY(Syncho)
ADD_SUBDIRECTORY(Tests)
INCLUDE_DIRECTORIES(CommunicateWithUser/include)
INCLUDE_DIRECTORIES(Syncho/include)
ADD_LIBRARY(networklib STATIC
        CommunicateWithUser/src/UserAccess.cpp
        CommunicateWithUser/src/RequestsProcessor.cpp
        Syncho/src/Synchronisator.cpp)

add_executable(Network main.cpp)
