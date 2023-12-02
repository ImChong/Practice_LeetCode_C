# @FilePath     : \Practice_LeetCode_C\CMakeLists.txt
# @Author       : Chong Liu
# @CreateDate   : 2023-12-01 01:52:32
# @LastEditors  : Chong Liu
# @LastEditTime : 2023-12-02 11:15:53
# =================================================================================
# Copyright (c) 2023 by Chong Liu, All Rights Reserved.
# =================================================================================
# @Description  : 此CMakeLists用于构建所有 00_Basics\01_Common_Func\test 下的测试文件
#                 构建生成的测试文件用于测试 00_Basics\01_Common_Func 下的所有通用函数
# =================================================================================
# 设置CMake最低版本
cmake_minimum_required(VERSION 3.20)

# 设置项目名称
project(LeetCodePractice)

# 添加编译选项
add_compile_options(-Wall -Wextra)

# 设置C/C++标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 11)

# 设置可执行文件输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 添加子目录
add_subdirectory(00_Basics/01_Common_Func)