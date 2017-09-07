cmake_minimum_required (VERSION 3.5)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

set(sources src/test-main.cpp src/ch01.cpp)

add_executable(runtest ${sources})
