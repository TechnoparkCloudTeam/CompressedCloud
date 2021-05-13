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
include_directories(fileStorageWorker/include)
include_directories(Client/include)
include_directories(../ServerSynch/connection/include)
include_directories(../ServerSynch/fileStorageWorker/include)
include_directories(../ServerSynch/server/include)
include_directories(../statusRequest)


add_executable(serverFS main.cpp server/src/server.cpp connection/src/connection.cpp fileStorageWorker/src/FileStorageWorker.cpp ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(serverFS ${Boost_LIBRARIES} ${Protobuf_LIBRARIES}) 

add_executable(serverS ../ServerSync/main.cpp ../ServerSync/server/src/server.cpp ../ServerSync/connection/src/connection.cpp ../ServerSync/fileStorageWorker/src/FileStorageWorker.cpp ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(serverS ${Boost_LIBRARIES} ${Protobuf_LIBRARIES}) 

add_executable(client client.cpp ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(client ${Boost_LIBRARIES} ${Protobuf_LIBRARIES})

add_executable(clientnetwork Client/clientNetwork.cpp Client/src/ClientNetwork.cpp ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(clientnetwork ${Boost_LIBRARIES} ${Protobuf_LIBRARIES})