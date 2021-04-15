

cmake_minimum_required(VERSION 3.16)
project(Client_test)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-pthread -fpic")
 

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fpic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpic")

INCLUDE_DIRECTORIES(../FileStorage/include)
INCLUDE_DIRECTORIES(../MetaDataBase/include)
ADD_LIBRARY(database STATIC
        ../FileStorage/src/FileStorage.cpp
        ../MetaDataBase/src/MetaDataBase.cpp)
INCLUDE_DIRECTORIES(../../Network/CommunicateWithUser/include)
INCLUDE_DIRECTORIES(../../Network/Syncho/include)
ADD_LIBRARY(network STATIC
	../../Network/CommunicateWithUser/src/UserAccess.cpp
	../../Network/CommunicateWithUser/src/RequestsProcessor.cpp
	../../Network/Syncho/src/Synchronisator.cpp)
	
enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIR})
message(${GTEST_LIBRARIES})
add_executable(tests database_tests.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES} ${GMOCK_LIBRARIES} -pthread -lgmock)
target_link_libraries(tests database network)
