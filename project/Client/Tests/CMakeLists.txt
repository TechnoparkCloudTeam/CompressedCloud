
cmake_minimum_required(VERSION 3.16)
project(Client_test)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-pthread -fpic")
 
add_compile_options(-fPIC)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fpic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpic")

INCLUDE_DIRECTORIES(../ProgramInterface/include)
INCLUDE_DIRECTORIES(../Chunker/include)
INCLUDE_DIRECTORIES(../Watcher/include)
INCLUDE_DIRECTORIES(../CommunicateWithServer/include)
INCLUDE_DIRECTORIES(../../Network/CommunicateWithUser/include)
INCLUDE_DIRECTORIES(../../Network/Syncho/include)
ADD_LIBRARY(client SHARED
        ../Watcher/src/Watcher.cpp
        ../ProgramInterface/src/ProgramInterface.cpp
        ../Chunker/src/Chunker.cpp
        ../CommunicateWithServer/src/ClientServerCommunication.cpp)
ADD_LIBRARY(network STATIC
	../../Network/CommunicateWithUser/src/UserAccess.cpp
	../../Network/CommunicateWithUser/src/RequestsProcessor.cpp
	../../Network/Syncho/src/Synchronisator.cpp)

enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIR})
message(${GTEST_LIBRARIES})
add_executable(tests client_tests.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES} ${GMOCK_LIBRARIES} -pthread -lgmock)
target_link_libraries(tests client network)
