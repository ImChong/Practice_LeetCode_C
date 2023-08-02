cmake_minimum_required(VERSION 3.0.0)
project(leetcode23 VERSION 0.1.0 LANGUAGES C)
include(CTest)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# GoogleTest requires at least C++14
set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(include)

add_subdirectory(src)
enable_testing()
add_subdirectory(test)



# project(gTestTemplate)
# cmake_minimum_required(VERSION 3.16)
# include(CTest)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# add_subdirectory(src)
# enable_testing()#如果要使用ctest，必须在source root directory中调用该函数
# add_subdirectory(test)

# TODO 如果有更多的和 src 并列的子目录中，并且其中存在源代码，请把他们也加入进来，否则这些文件不会参与编译
# add_subdirectory( your_new_folder )
