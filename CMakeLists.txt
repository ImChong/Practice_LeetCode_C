# 设置CMake最低版本
cmake_minimum_required(VERSION 3.20)
# 设置项目名称
project(LeetCodePractice)
# 设置C/C++标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 11)

# 设置可执行文件输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 添加子目录
add_subdirectory(00_Basics)