cmake_minimum_required(VERSION 3.0.0)
project(leetcode23 VERSION 0.1.0 LANGUAGES C)
# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
# 设置可执行文件的输出路径为build/bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

include_directories(include)

enable_testing()

add_executable(leetcode23 ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c)

# add_subdirectory(test)