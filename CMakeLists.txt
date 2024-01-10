# @FilePath     : \Practice_LeetCode_C\CMakeLists.txt
# @Author       : Chong Liu
# @CreateDate   : 2023-12-01 01:52:32
# @LastEditors  : Chong Liu
# @LastEditTime : 2023-12-02 11:15:53
# =================================================================================
# Copyright (c) 2023 by Chong Liu, All Rights Reserved.
# =================================================================================
# @Description  : This CMakeLists is used to build the test file for all the common function modules
#                 common function modules are under the F01_Common_Functions directory.
# =================================================================================
# Set the minimum version of CMake that can be used
cmake_minimum_required(VERSION 3.20)

# Set the project name
project(LeetCodePractice)

# Add compiler options
add_compile_options(-Wall -Wextra)

# Set the C / C++ standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the output path
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add the subdirectory
add_subdirectory(F01_Common_Functions)