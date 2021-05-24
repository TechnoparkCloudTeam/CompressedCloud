cmake_minimum_required(VERSION 3.16)

project(asio)

set(CMAKE_CXX_STANDARD 20)


FIND_PACKAGE(PostgreSQL REQUIRED)
include_directories(${PostgreSQL_INCLUDE_DIRS})

set(BOOST_ROOT /usr/include/boost)
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS system thread)
include_directories(${Boost_INCLUDE_DIR})

add_executable(fdb  ../DataBases/PostgresDB/main.cpp
../DataBases/PostgresDB/Base/src/PostgreSQLDB.cpp
../DataBases/PostgresDB/MetaDB/src/MetaDB.cpp
../DataBases/PostgresDB/UserDB/src/UserDB.cpp)


find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ServerSynch/message.proto)


include_directories(ServerFileStorage/connection/include)
include_directories(ServerFileStorage/server/include)
include_directories(ServerFileStorage/fileStorageWorker/include)
include_directories(ServerFileStorage/Client/include)
include_directories(ServerSynch/connection/include)
include_directories(ServerSynch/fileStorageWorker/include)
include_directories(ServerSynch/server/include)


INCLUDE_DIRECTORIES(../DataBases/PostgresDB/Base/include
../DataBases/PostgresDB/MetaDB/include
../DataBases/PostgresDB/UserDB/include)



add_executable(serverFS 
ServerFileStorage/main.cpp 
ServerFileStorage/server/src/server.cpp 
ServerFileStorage/connection/src/connection.cpp 
ServerFileStorage/fileStorageWorker/src/FileStorageWorker.cpp 
${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(serverFS ${Boost_LIBRARIES} ${Protobuf_LIBRARIES}) 

add_executable(serverS 
ServerSynch/main.cpp 
ServerSynch/server/src/serverSynch.cpp 
ServerSynch/connection/src/connectionSynch.cpp 
../DataBases/PostgresDB/Base/src/PostgreSQLDB.cpp
../DataBases/PostgresDB/MetaDB/src/MetaDB.cpp
../DataBases/PostgresDB/UserDB/src/UserDB.cpp
${PROTO_SRCS} ${PROTO_HDRS})
target_include_directories(serverS PRIVATE ${PostgreSQL_INCLUDE_DIRS})

target_link_libraries(serverS ${Boost_LIBRARIES} ${Protobuf_LIBRARIES} ${PostgreSQL_LIBRARIES}) 





target_link_libraries(fdb ${Boost_LIBRARIES} ${PostgreSQL_LIBRARIES})