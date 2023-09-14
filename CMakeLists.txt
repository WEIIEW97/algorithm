cmake_minimum_required(VERSION 3.22)
project(lc)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE "Release")

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME}
dfs.cpp)
