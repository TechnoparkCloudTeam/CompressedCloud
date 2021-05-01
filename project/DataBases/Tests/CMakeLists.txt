cmake_minimum_required(VERSION 3.16)
project(Client_test)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-pthread -fpic")
 

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fpic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpic")

INCLUDE_DIRECTORIES(../FileStorageServer/include)
INCLUDE_DIRECTORIES(../DataBase/include)
INCLUDE_DIRECTORIES(../LocalDB/include)
ADD_LIBRARY(databases SHARED
	../LocalDB/src/LocalDB.cpp
        ../LocalDB/src/ChunkDB.cpp
        ../LocalDB/src/UserDB.cpp
        ../LocalDB/src/FileDB.cpp
        ../LocalDB/src/DeviceDB.cpp
        ../FileStorageServer/src/FileStorage.cpp
        ../DataBase/src/UserInfoDB.cpp
        ../DataBase/src/PostgresDB.cpp
        ../DataBase/src/MetaDB.cpp
        ../DataBase/src/Commands.cpp)
	
enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIR})
message(${GTEST_LIBRARIES})
add_executable(tests database_tests.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES} ${GMOCK_LIBRARIES} -pthread -lgmock)
