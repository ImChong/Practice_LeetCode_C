# 设置CMake最低版本
cmake_minimum_required(VERSION 3.20)
# 设置项目名称
project(LeetCodePractice)

# 设置可执行文件输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 添加子目录
add_subdirectory(00_Basics)