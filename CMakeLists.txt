cmake_minimum_required(VERSION 3.6)
project(google)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp leetcode/004_median-of-two-sorted-arrays.cpp leetcode/031_next-permutation.cpp leetcode/042_trapping-rain-water.cpp leetcode/054_spiral_matrix.cpp leetcode/056_merge-intervals.cpp leetcode/057_insert-interval.cpp)
add_executable(google ${SOURCE_FILES} leetcode/004_median-of-two-sorted-arrays.cpp)