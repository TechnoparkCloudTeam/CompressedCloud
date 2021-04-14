cmake_minimum_required(VERSION 3.16)
project(CommunicationWithUser)
set(CMAKE_CXX_STANDARD 20)

INCLUDE_DIRECTORIES(include)


add_executable(CommunicationWithUser src/RequestsProcessor.cpp src/UserAccess main.cpp)

