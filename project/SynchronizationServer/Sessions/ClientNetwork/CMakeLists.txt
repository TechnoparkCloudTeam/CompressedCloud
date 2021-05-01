cmake_minimum_required(VERSION 3.16)

project(ClientNetwork)

set(CMAKE_CXX_STANDARD 20)

set(BOOST_ROOT /usr/include/boost)
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS system thread)
 
include_directories(${Boost_INCLUDE_DIR})
include_directories(include)

add_executable(ClientNetwork src/ClientNetwork.cpp main.cpp)
target_link_libraries(ClientNetwork ${Boost_LIBRARIES})
