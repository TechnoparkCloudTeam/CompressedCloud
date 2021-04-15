cmake_minimum_required(VERSION 3.16)
project(ClientServerCommunication)

set(CMAKE_CXX_STANDARD 20)

INCLUDE_DIRECTORIES(include)


add_executable(ClientServerCommunication src/ClientServerCommunication.cpp main.cpp)

