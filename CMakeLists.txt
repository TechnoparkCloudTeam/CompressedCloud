cmake_minimum_required(VERSION 3.16)

project(asio)

set(CMAKE_CXX_STANDARD 20)



include_directories(message/include)

add_executable(testMSG client/testMessage.cpp)


