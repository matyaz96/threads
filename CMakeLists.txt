cmake_minimum_required(VERSION 3.0)
project(Threads)
find_package(Threads REQUIRED)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES_PTHREAD_1 thread_1.cpp)
set(SOURCE_FILES_PTHREAD_2 thread_2.cpp)
set(SOURCE_FILES_JOIN join.cpp)



add_executable(thread_1 ${SOURCE_FILES_PTHREAD_1})
add_executable(thread_2 ${SOURCE_FILES_PTHREAD_2})
add_executable(join ${SOURCE_FILES_JOIN})

target_link_libraries(thread_1 Threads::Threads)
target_link_libraries(thread_2 Threads::Threads)
target_link_libraries(join Threads::Threads)