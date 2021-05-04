cmake_minimum_required(VERSION 3.16)

project(asio)

set(CMAKE_CXX_STANDARD 20)

set(BOOST_ROOT /usr/include/boost)
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS system thread)
 
include_directories(${Boost_INCLUDE_DIR})
include_directories(queue/include)
include_directories(client/ClientNetwork/include)
include_directories(CloudServer/Server/include)
include_directories(message/include)

add_executable(testserver CloudServer/Server/server.cpp)
target_link_libraries(testserver ${Boost_LIBRARIES})


