# 设置CMake的最低版本要求
cmake_minimum_required(VERSION 3.0)

# 项目名称
project(MyCProject)

# 设置生成文件目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# 添加可执行文件
add_executable(my_app main.c)
