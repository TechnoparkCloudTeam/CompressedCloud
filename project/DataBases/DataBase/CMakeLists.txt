CMAKE_MINIMUM_REQUIRED(VERSION 3.16)
PROJECT(DataBase)

SET(CMAKE_CXX_STANDARD 20)

INCLUDE_DIRECTORIES(include)

ADD_LIBRARY(databaselib STATIC
        src/UserInfoDB.cpp
        src/PostgresDB.cpp
        src/MetaDB.cpp
        src/Commands.cpp
        )
ADD_EXECUTABLE(local main.cpp)
