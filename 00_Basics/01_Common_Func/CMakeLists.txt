include(ExternalProject)                                                                    # 引入ExternalProject模块
set_directory_properties(PROPERTIES EP_PREFIX ${CMAKE_BINARY_DIR}/ThirdParty/googletest)    # 设置下载目录

ExternalProject_Add(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
)

include_directories(${CMAKE_BINARY_DIR}/ThirdParty/googletest/include)
link_directories(${CMAKE_BINARY_DIR}/ThirdParty/googletest/lib)

# 添加Google Test的依赖
enable_testing()

# 添加头文件路径
include_directories(cfg)                # 配置文件
include_directories(inc)                # 头文件
include_directories(inc/commonDef)      # 公共定义头文件

# 创建一个新的测试目标
add_executable(commonArrayTest test/commonArrayTest.cc src/commonArray.c)   # 测试目标 commonArray

# 将Google Test库链接到你的测试目标
add_dependencies(commonArrayTest googletest)
target_link_libraries(commonArrayTest gtest gtest_main)