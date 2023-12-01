include(ExternalProject)

set_directory_properties(PROPERTIES EP_PREFIX ${CMAKE_BINARY_DIR}/ThirdParty)

ExternalProject_Add(
    googletest
    GIT_REPOSITORY git@github.com:google/googletest.git
    GIT_TAG v1.14.0
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
)

include_directories(${CMAKE_BINARY_DIR}/ThirdParty/include)
link_directories(${CMAKE_BINARY_DIR}/ThirdParty/lib)

# 添加Google Test的依赖
enable_testing()
add_subdirectory(${CMAKE_BINARY_DIR}/ThirdParty/src/googletest)

# 添加头文件路径
include_directories(cfg)
include_directories(inc)
include_directories(inc/commonDef)

# 创建一个新的测试目标
add_executable(commonArrayTest test/commonArrayTest.cc src/commonArray.c)

# 将Google Test库链接到你的测试目标
add_dependencies(commonArrayTest googletest)
target_link_libraries(commonArrayTest gtest gtest_main)