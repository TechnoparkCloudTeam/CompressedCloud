cmake_minimum_required(VERSION 3.16)

project(asio)

set(CMAKE_CXX_STANDARD 20)

set(BOOST_ROOT /usr/include/boost)
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS system thread)

include_directories(${Boost_INCLUDE_DIR})
find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})


protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS message.proto)

include_directories(connection/include)
include_directories(server/include)


add_executable(mai main.cpp server/src/server.cpp connection/src/connection.cpp ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(mai ${Boost_LIBRARIES} ${Protobuf_LIBRARIES}) 

add_executable(client client.cpp ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(client ${Boost_LIBRARIES} ${Protobuf_LIBRARIES})