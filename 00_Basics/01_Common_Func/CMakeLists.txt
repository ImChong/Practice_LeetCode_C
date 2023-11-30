# 将所有源文件添加到一个变量中
set(SRC_FILES
    src/commonArray.c
    src/commonBinaryTree.c
    src/commonCmd.c
    src/commonHashTable.c
)

include_directories(inc)
add_library(common_func ${SRC_FILES})