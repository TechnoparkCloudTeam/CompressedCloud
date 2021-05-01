cmake_minimum_required(VERSION 3.16)
project(Application)
set(CMAKE_CXX_STANDARD 20)

INCLUDE_DIRECTORIES(Application)
INCLUDE_DIRECTORIES(../../SynchronizationServer/Sessions/ClientNetwork/include)
INCLUDE_DIRECTORIES(../../DataBases/LocalDB/include)
include_directories(${Boost_INCLUDE_DIR})
find_package(Boost COMPONENTS system thread)

add_executable(Application src/Application.cpp main.cpp)
target_link_libraries(Application ${Boost_LIBRARIES})
