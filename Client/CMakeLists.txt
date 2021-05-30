cmake_minimum_required(VERSION 3.16)
project(Client)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BOOST_ROOT /usr/include/boost)
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS system thread)

INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
find_package (SQLite3)
include_directories(${SQLite3_INCLUDE_DIRS})

find_package(Boost)
FIND_PACKAGE(Boost COMPONENTS log REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})


find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ../Server/Message/message.proto)


INCLUDE_DIRECTORIES(ProgramInterface/include)
INCLUDE_DIRECTORIES(Watcher/include)
INCLUDE_DIRECTORIES(Indexer/include)
INCLUDE_DIRECTORIES(Application/include)
include_directories(RequestCoordinator/include)
include_directories(../Server/Message)
include_directories(../Server/Message/CodeHeader/include)
INCLUDE_DIRECTORIES(../DataBases/LocalDB/include)
INCLUDE_DIRECTORIES(../Server/ServerFileStorage/fileStorageWorker/include)
INCLUDE_DIRECTORIES(../Server/ClientNetwork/include)

add_executable(Client main.cpp 
../DataBases/LocalDB/src/LocalDB.cpp
ProgramInterface/src/ProgramInterface.cpp 
Application/src/Application.cpp 
Indexer/src/Indexer.cpp 
../Server/ServerFileStorage/fileStorageWorker/src/FileStorageWorker.cpp
../Server/ClientNetwork/src/ClientNetwork
Watcher/src/FileSysEvent.cpp
Watcher/src/Watcher.cpp
Watcher/src/WatcherMessage.cpp
Watcher/src/WatcherNotification.cpp
Watcher/src/WatcherNotifierBuilder.cpp
RequestCoordinator/src/RequestCoordinator.cpp
../Server/Message/CodeHeader/src/CodeHeader.cpp
${PROTO_SRCS} ${PROTO_HDRS}
)

target_link_libraries(Client ${SQLite3_LIBRARIES} ${Boost_LIBRARIES} ${Protobuf_LIBRARIES})
