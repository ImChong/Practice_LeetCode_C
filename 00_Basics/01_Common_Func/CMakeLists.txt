# 将所有源文件添加到一个变量中
set(SRC_FILES
    src/commonArray.c
    # src/commonBinaryTree.c
    # TODO: 添加其他源文件
)

# 添加头文件路径
include_directories(cfg)
include_directories(inc)
include_directories(inc/commonDef)

# 生成静态库
add_library(common_func ${SRC_FILES})

# 生成可执行测试文件
# TODO：调用 google test对所有的.c文件进行测试