set(gtest_headers "D:/wecode_build_tools/googletest/include")
set(gtest_libs "D:/wecode_build_tools/googletest/lib")

add_executable(test_leetcode023 test_leetcode023.cc)
target_include_directories(test_leetcode023 PUBLIC "${gtest_headers}" ${CMAKE_SOURCE_DIR}/include)

#和 googletest 的库进行链接
target_link_directories(test_leetcode003 PUBLIC "${gtest_libs}")
target_link_libraries(test_leetcode023 lib_leetcode003 gtest)

# ！！注意！！
# 测试用例的可执行文件的名字必须用 test_ 开始，这样该用例才能够出现在 googleTest 用例树中
# 这个可执行文件并且必须位于 ${workspaceFolder}/bin 目录中，CMake的默认就是输出到这个目录中。

# test_leetcode023 是包含googletest用例的可执行文件，add_test 之后可以被CMake来执行
add_test(NAME example_test COMMAND test_leetcode023)

# TODO : 如果有更多的其它可执行文件，可以编译仿照上面的过程编译链接之后通过 add_test 加入到CMake的测试列表中来。
# add_test(NAME test_yourName COMMAND test_yourExeProgram)
