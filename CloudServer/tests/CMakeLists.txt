
cmake_minimum_required(VERSION 3.16)
project(Cloud_server_test)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-pthread -fpic")

set(BOOST_ROOT /usr/include/boost)
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS system thread)
 
include_directories(${Boost_INCLUDE_DIR})



INCLUDE_DIRECTORIES(../../SynchronizationServer/Sessions/ClientNetwork/include)
INCLUDE_DIRECTORIES(../../SynchronizationServer/Sessions/SessionOnServer/include)

INCLUDE_DIRECTORIES(../include)

ADD_LIBRARY(cloud STATIC
	../src/FileStorageServer.cpp
    ../../SynchronizationServer/Sessions/ClientNetwork/src/ClientNetwork.cpp
    ../../SynchronizationServer/Sessions/SessionOnServer/src/ClientSession.cpp)

enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIR})
message(${GTEST_LIBRARIES})
add_executable(tests CloudServer.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES} ${GMOCK_LIBRARIES} -pthread -lgmock)
target_link_libraries(tests cloud)
target_link_libraries(tests ${Boost_LIBRARIES})