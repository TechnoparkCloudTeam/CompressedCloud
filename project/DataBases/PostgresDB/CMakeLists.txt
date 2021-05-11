CMAKE_MINIMUM_REQUIRED(VERSION 3.13.4)
PROJECT(PostgreSQL)

SET(CMAKE_CXX_STANDARD 17)
#set(CMAKE_C_FLAGS "-pthread  -Wall -Werror -Wpedantic")
#SET(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -Wpedantic")
#set(CMAKE_CXX_FLAGS "-pthread -Wall -Werror -Wpedantic -fprofile-arcs -ftest-coverage")
#SET(MYCOMPILE_FLAGS "-std=c++2a")

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

#set(CMAKE_THREAD_LIBS_INIT "-lpthread")
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
#set(CMAKE_HAVE_THREADS_LIBRARY 1)
#set(CMAKE_USE_WIN32_THREADS_INIT 0)
#set(CMAKE_USE_PTHREADS_INIT 1)
#set(THREADS_PREFER_PTHREAD_FLAG ON)

#ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)



FIND_PACKAGE(PostgreSQL REQUIRED)

FIND_PACKAGE(Boost REQUIRED)
FIND_PACKAGE(Boost COMPONENTS log REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

#FIND_PACKAGE(Threads REQUIRED)
#SET(Boost_USE_MULTITHREADED ON)


ADD_EXECUTABLE(PostgresDB
        main.cpp
        Base/src/PostgreSQLDB.cpp
        MetaDB/src/MetaDB.cpp
        UserDB/src/UserDB.cpp)
        
#find_package(Threads)       
#target_link_libraries(PostgresDB PRIVATE ${CMAKE_THREAD_LIBS_INIT})

#TARGET_LINK_LIBRARIES(PostgresDB PRIVATE ${CMAKE_THREAD_LIBS_INIT})

# Add include directories to your target. PRIVATE is useful with multi-target projects - see documentation of target_include_directories for more info
target_include_directories(PostgresDB PRIVATE ${PostgreSQL_INCLUDE_DIRS})

# Add libraries to link your target againts. Again, PRIVATE is important for multi-target projects
target_link_libraries(PostgresDB PRIVATE ${PostgreSQL_LIBRARIES})


INCLUDE_DIRECTORIES(Base/include
        MetaDB/include
        UserDB/include)

ADD_LIBRARY(MetaDB-dev SHARED
        Base/src/PostgreSQLDB.cpp
        MetaDB/src/MetaDB.cpp
        )
target_include_directories(MetaDB-dev PRIVATE ${PostgreSQL_INCLUDE_DIRS})
target_link_libraries(MetaDB-dev PRIVATE ${PostgreSQL_LIBRARIES} ${Boost_LIBRARIES})

ADD_LIBRARY(UserDB-dev SHARED
        Base/src/PostgreSQLDB.cpp
        UserDB/src/UserDB.cpp
        )
target_include_directories(UserDB-dev PRIVATE ${PostgreSQL_INCLUDE_DIRS})
target_link_libraries(UserDB-dev PRIVATE ${PostgreSQL_LIBRARIES} ${Boost_LIBRARIES})


#find_library(PTHREAD_LIBRARY pthread)
#target_link_libraries(PostgresDB PRIVATE ${PTHREAD_LIBRARY})
