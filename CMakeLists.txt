cmake_minimum_required(VERSION 3.22)
project(lc LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE "Release")

set(CMAKE_CXX_STANDARD 20)

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    message(STATUS "Configuring for linux")
    include_directories(
        "/usr/include"
        "/usr/local/include"
        )
endif()

add_executable(${PROJECT_NAME}
is_power_of_four.cpp)

