cmake_minimum_required(VERSION 3.6)
project(google)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
file(GLOB leetcode "leetcode/*.cpp")
file(GLOB mianjing_2sigma "mianjing_2sigma")
file(GLOB mianjing_fb, "mianjing_fb/*.cpp")
file(GLOB mianJing_google "mianJing_google")
file(GLOB mianJing_spotify "mianJing_spotify")
file(GLOB prototype "prototype/*.cpp")
file(GLOB test "test/*.cpp")

add_executable(
        google
        main.cpp
        ${leetcode}
        ${mianjing_2sigma}
        ${mainjing_fb}
        ${mianJing_google}
        ${mainJing_spotify}
        ${prototype}
        ${test}
        leetcode/953_verifying-an-alien-dictionary.cpp
        mianjing_fb/task_sheduler.cpp
        mianjing_fb/maze_walking.cpp
        mianjing_fb/select_kth_element.cpp
        mianjing_fb/graph_clone.cpp
        mianjing_fb/intersection_of_two_sorted_arrays.cpp
        mianjing_fb/sorted_iterator_over_k_sorted_lists.cpp
        mianJing_google/dice-combinations.cpp
        mianJing_google/array-difference.cpp mianJing_google/AlliesAssociated.cpp prototype/union-find.cpp)