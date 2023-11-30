# 添加Google Test的依赖
enable_testing()
# add_subdirectory(googletest)


# 添加头文件路径
include_directories(cfg)
include_directories(inc)
include_directories(inc/commonDef)

# 创建一个新的测试目标
add_executable(commonArrayTest tests/commonArrayTest.cc)

# 生成可执行测试文件
# TODO：调用 google test对所有的.c文件进行测试