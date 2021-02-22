cmake_minimum_required(VERSION 3.17)
project(LeetCode)

set(CMAKE_CXX_STANDARD 11)
include_directories(include)
set(SOURCES src/1004.cpp)
add_executable(LeetCode main.cpp ${SOURCES})