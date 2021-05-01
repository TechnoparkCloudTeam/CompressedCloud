cmake_minimum_required(VERSION 3.16)
project(Synch_server_test)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-pthread -fpic")

set(BOOST_ROOT /usr/include/boost)
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS system thread)
 
include_directories(${Boost_INCLUDE_DIR})

INCLUDE_DIRECTORIES(../Sessions/ClientNetwork/include)
INCLUDE_DIRECTORIES(../Sessions/SessionOnServer/include)
INCLUDE_DIRECTORIES(../MessageQueues/include)
INCLUDE_DIRECTORIES(../Server/include)
INCLUDE_DIRECTORIES(../Synchronizator/include)


ADD_LIBRARY(synchserver STATIC
	../Sessions/ClientNetwork/src/ClientNetwork.cpp
    ../Sessions/SessionOnServer/src/ClientSession.cpp
    ../MessageQueues/src/MessageQueues.cpp
    ../Synchronizator/src/Synchronizator.cpp)

enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIR})
message(${GTEST_LIBRARIES})
add_executable(tests SynchronizationServerTest.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES} ${GMOCK_LIBRARIES} -pthread -lgmock)
target_link_libraries(tests synchserver)
target_link_libraries(tests ${Boost_LIBRARIES})
