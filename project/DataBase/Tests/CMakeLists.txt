cmake_minimum_required(VERSION 3.16)
project(Database_test)
set(CMAKE_CXX_STANDARD 20)

INCLUDE_DIRECTORIES(../FileStorage/include)
INCLUDE_DIRECTORIES(../MetaDataBase/include)
ADD_LIBRARY(database STATIC
        ../FileStorage/src/FileStorage.cpp
        ../MetaDataBase/src/MetaDataBase.cpp)


enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIR})
message(${GTEST_LIBRARIES})
add_executable(tests database_tests.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES} -lpthread)
target_link_libraries(tests database)
