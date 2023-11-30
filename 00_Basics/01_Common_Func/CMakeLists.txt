# 添加Google Test的依赖
enable_testing()
# add_subdirectory(googletest)


# 添加头文件路径
include_directories(cfg)
include_directories(inc)
include_directories(inc/commonDef)

# 创建一个新的测试目标
add_executable(commonArrayTest tests/commonArrayTest.cc src/commonArray.c)

# 将Google Test库链接到你的测试目标
# target_link_libraries(commonArrayTest gtest gtest_main)