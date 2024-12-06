cmake_minimum_required(VERSION 3.22)
project(lc LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE "Release")

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    message(STATUS "Configuring for linux")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/usr/include -I/usr/local/include")
endif()

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME}
leetcode/max_count.cpp)
