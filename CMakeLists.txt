cmake_minimum_required(VERSION 3.6)
project(google)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp leetcode/004_median-of-two-sorted-arrays.cpp)
add_executable(google ${SOURCE_FILES} leetcode/004_median-of-two-sorted-arrays.cpp)