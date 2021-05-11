cmake_minimum_required(VERSION 3.16)
project(Client)

set(CMAKE_CXX_STANDARD 20)

set(BOOST_ROOT /usr/include/boost)
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS system thread)

ADD_SUBDIRECTORY(Watcher)
ADD_SUBDIRECTORY(ProgramInterface)
ADD_SUBDIRECTORY(Chunker)

INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
find_package (SQLite3)
include_directories(${SQLite3_INCLUDE_DIRS})

find_package(Boost)
FIND_PACKAGE(Boost COMPONENTS log REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})



INCLUDE_DIRECTORIES(ProgramInterface/include)
INCLUDE_DIRECTORIES(Chunker/include)
INCLUDE_DIRECTORIES(Watcher/include)
INCLUDE_DIRECTORIES(Indexer/include)
INCLUDE_DIRECTORIES(Application/include)

INCLUDE_DIRECTORIES(../DataBases/LocalDB/include)

ADD_LIBRARY(clientlib STATIC
        Watcher/src/Watcher.cpp
        ProgramInterface/src/ProgramInterface.cpp
        Chunker/src/Chunker.cpp)

add_executable(Client main.cpp ../DataBases/LocalDB/src/LocalDB.cpp)

target_link_libraries(Client ${SQLite3_LIBRARIES} ${Boost_LIBRARIES})