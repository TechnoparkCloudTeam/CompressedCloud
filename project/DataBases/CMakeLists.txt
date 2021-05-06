include_directories(LocalDB/include)
ADD_LIBRARY(liblocalDB STATIC LocalDB/src/LocalDB.cpp)

INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
find_package (SQLite3)
include_directories(${SQLite3_INCLUDE_DIRS})

find_package(Boost)
FIND_PACKAGE(Boost COMPONENTS log REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(LocalDB LocalDB/src/main.cpp
        LOcalDB/src/LocalDB.cpp)

target_link_libraries (LocalDB ${SQLite3_LIBRARIES})
target_link_libraries (LocalDB  ${Boost_LIBRARIES})
ADD_SUBDIRECTORY(Tests)
