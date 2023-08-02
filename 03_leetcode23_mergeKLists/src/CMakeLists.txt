include_directories(${CMAKE_SOURCE_DIR}/include)

# 单独编译成一个 lib 库
add_library(lib_leetcode023 OBJECT leetcode023_func.c)
# main.c 编译成一个可执行文件，因为里面包含 main 函数
add_executable(main_leetcode023 main.c)

# 最后的可执行文件必须和上面的lib进行链接
target_link_libraries(main_leetcode023 lib_leetcode023)

# TODO 如何在上面已有的 exe 中增加一个新的源文件，参与编译？
# 1: 新建一个文件，比如 newfile.cpp
# 2: 如果这个文件参与库的编译链接，那么将该文件添加到上面的 add_library() 参数列表的最后
# 3: 如果这个文件只参与最后 exe 的编译链接，那么将其添加到上面的 add_executable() 参数列表的最后。

# 如果新文件中要参与最后的 googletest的测试，那么必须添加到 add_library 最后。

# TODO 如何增加一个新的可执行文件 ？
# 1： 在 src 目录下新建一个 .cpp/.c 文件，编辑并且保存；比如叫 newfile.cpp
# 2： 增加一行 add_executable(newfile newfile.cpp)
# 3:  重新执行 cmake build 即可。

# ！！注意！！
# 1： 头文件要添加到 include 目录下，如果添加到了其它目录下，务必在这里调用 include_directories
# 2： 如果新增的文件既不被add_library，也不add_executable，那么就不会被编译。
