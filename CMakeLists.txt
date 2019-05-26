cmake_minimum_required(VERSION 3.6)
project(google)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
file(GLOB leetcode "leetcode/*.cpp")
file(GLOB mianjing_2sigma "mianjing_2sigma")
file(GLOB mianJing_google "mianJing_google")
file(GLOB prototype "prototype")

add_executable(
        google
        main.cpp
        ${leetcode}
        ${mianjing_2sigma}
        ${mianJing_google}
        ${prototype}
        prototype/bits.cpp)