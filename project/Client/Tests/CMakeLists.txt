
cmake_minimum_required(VERSION 3.16)
project(Client_test)
set(CMAKE_CXX_STANDARD 20)
INCLUDE_DIRECTORIES(../ProgramInterface/include)
INCLUDE_DIRECTORIES(../Chunker/include)
INCLUDE_DIRECTORIES(../Watcher/include)
INCLUDE_DIRECTORIES(../CommunicateWithServer/include)
ADD_LIBRARY(client STATIC
        ../Watcher/src/Watcher.cpp
        ../ProgramInterface/src/ProgramInterface.cpp
        ../Chunker/src/Chunker.cpp
        ../CommunicateWithServer/src/ClientServerCommunication.cpp)


enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIR})
message(${GTEST_LIBRARIES})
add_executable(tests client_tests.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES} -lpthread)
target_link_libraries(tests client)
