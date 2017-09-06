cmake_minimum_required (VERSION 3.5)

add_definitions(-std=c++11)

set(sources src/test-main.cpp src/ch01.cpp)

add_executable(runtest ${sources})
