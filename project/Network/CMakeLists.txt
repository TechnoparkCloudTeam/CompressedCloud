cmake_minimum_required(VERSION 3.16)
project(DataBase)

set(CMAKE_CXX_STANDARD 20)

ADD_SUBDIRECTORY(CommunicateWithUser)
ADD_SUBDIRECTORY(Syncho)

add_executable(Network main.cpp)

