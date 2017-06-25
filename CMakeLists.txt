cmake_minimum_required(VERSION 3.6)
project(google)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp leetcode/004_median-of-two-sorted-arrays.cpp leetcode/031_next-permutation.cpp leetcode/042_trapping-rain-water.cpp leetcode/054_spiral_matrix.cpp leetcode/056_merge-intervals.cpp leetcode/057_insert-interval.cpp leetcode/066_plus-one.cpp leetcode/128_longest-consecutive-sequence.cpp leetcode/142_linked-list-cycle-II.cpp test/for_loop.cpp leetcode/162_find-peak-element.cpp leetcode/163_missing-ranges.cpp test/strings.cpp leetcode/228_summary-ranges.cpp leetcode/259_3sum-smaller.cpp leetcode/001_two-sum.cpp leetcode/167_two-sum-ii-input-array-is-sorted.cpp leetcode/170_two-sum-iii-data-structure-design.cpp leetcode/015_3sum.cpp leetcode/016_3sum-closest.cpp leetcode/018_4sum.cpp leetcode/454_4sum-ii.cpp leetcode/280_wiggle-sort.cpp leetcode/324_wiggle-sort-ii.cpp leetcode/289_game-of-life.cpp leetcode/380_insert-delete-getrandom-o1.cpp leetcode/166_fraction-to-recurring-decimal.cpp leetcode/338_counting-bits.cpp leetcode/005_longest-palindromic-substring.cpp)
#add_executable(google ${SOURCE_FILES} leetcode/004_median-of-two-sorted-arrays.cpp)
add_executable(google ${SOURCE_FILES})