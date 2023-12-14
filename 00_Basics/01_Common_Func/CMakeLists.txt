# 引入ExternalProject模块
include(ExternalProject)                                                                    # 引入ExternalProject模块
set_directory_properties(PROPERTIES EP_PREFIX ${CMAKE_BINARY_DIR}/ThirdParty/googletest)    # 设置下载目录

# 添加Google Test的下载和编译
ExternalProject_Add(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
)

# 添加Google Test的头文件和库文件的搜索路径
include_directories(${CMAKE_BINARY_DIR}/ThirdParty/googletest/include)
link_directories(${CMAKE_BINARY_DIR}/ThirdParty/googletest/lib)

# 添加头文件路径
include_directories(cfg)                # 配置文件
include_directories(inc)                # 头文件
include_directories(inc/commonDef)      # 公共定义头文件

# 创建一个包含所有测试目标的列表
set(TEST_TARGETS
    commonArray
    commonBinaryTree
    commonCmd
    commonHashTable
    commonLinkedList
    commonLinkedListDummy
    commonQueue
    commonString
)

# 对每个测试目标执行操作
foreach(TARGET ${TEST_TARGETS})
    # 设置测试目标的名称
    set(TEST_TARGET_NAME ${TARGET}Test)
    set(TEST_SOURCE test/${TEST_TARGET_NAME}.cc)
    set(TARGET_SOURCE src/${TARGET}.c)

    # 检查源文件是否存在
    if(EXISTS ${TEST_SOURCE} AND EXISTS ${TARGET_SOURCE})
        # 将测试目标添加到构建系统
        add_executable(${TEST_TARGET_NAME} ${TEST_SOURCE} ${TARGET_SOURCE})
        # 添加测试目标的依赖项
        add_dependencies(${TEST_TARGET_NAME} googletest)
        # 添加测试目标的链接库
        target_link_libraries(${TEST_TARGET_NAME} gtest gtest_main)
    else()
        if(NOT EXISTS ${TEST_SOURCE})
            message("File ${TEST_SOURCE} does not exist.")
        endif()
        if(NOT EXISTS ${TARGET_SOURCE})
            message("File ${TARGET_SOURCE} does not exist.")
        endif()
    endif()
endforeach()