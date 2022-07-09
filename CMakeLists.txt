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
        prototype/class-initialize.cpp
        prototype/function-object.cpp prototype/callable-objects.cpp)