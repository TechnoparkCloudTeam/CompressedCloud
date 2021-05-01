cmake_minimum_required(VERSION 3.16)

project(Synchronizator)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)
include_directories(../MessageQueues/include)
include_directories(../Sessions/SessionOnServer/include)
include_directories(../../DataBases/LocalDB/include)

include_directories(${Boost_INCLUDE_DIR})
find_package(Boost COMPONENTS system thread)

add_executable(Synchronizator src/Synchronizator.cpp main.cpp)
target_link_libraries(Synchronizator ${Boost_LIBRARIES})
