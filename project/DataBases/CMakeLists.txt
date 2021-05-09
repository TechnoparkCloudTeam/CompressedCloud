cmake_minimum_required(VERSION 3.16)

project(DB)

set(CMAKE_CXX_STANDARD 20)

set(BOOST_ROOT /usr/include/boost)
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS system thread)

include_directories(LocalDB/include)
ADD_LIBRARY(liblocalDB STATIC LocalDB/src/LocalDB.cpp)

INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
find_package (SQLite3)
include_directories(${SQLite3_INCLUDE_DIRS})

find_package(Boost)
FIND_PACKAGE(Boost COMPONENTS log REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(LocalDB LocalDB/src/main.cpp
        LocalDB/src/LocalDB.cpp)

target_link_libraries (LocalDB ${SQLite3_LIBRARIES})
target_link_libraries (LocalDB  ${Boost_LIBRARIES})
