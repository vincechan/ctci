cmake_minimum_required (VERSION 3.5)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

set(sources 
    src/test-main.cpp 
    src/ch1.1.cpp
    src/ch1.2.cpp
    src/ch1.3.cpp
    src/ch1.4.cpp
    src/ch1.5.cpp
    src/ch1.6.cpp
    src/ch1.7.cpp
    src/ch1.8.cpp
    src/ch2.1.cpp
    src/ch2.2.cpp
    src/ch2.3.cpp
    src/ch2.4.cpp
    src/ch2.5.cpp
    src/ch2.6.cpp
    src/ch2.7.cpp
    src/ch3.1.cpp
    src/ch3.2.cpp
    src/ch3.3.cpp
    src/ch3.4.cpp
    src/ch3.5.cpp
    src/ch3.6.cpp
    src/ch3.7.cpp
    src/ch4.3.cpp
    src/LinkedList.cpp
    src/Stack.cpp
    src/TreeNode.cpp
)

add_executable(runtest ${sources})
