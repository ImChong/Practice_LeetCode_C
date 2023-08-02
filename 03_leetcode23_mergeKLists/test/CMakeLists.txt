add_executable(test_leetcode023 test_leetcode023.cc)
target_include_directories(test_leetcode023 PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(test_leetcode023 lib_leetcode003 gtest)


add_test(NAME test COMMAND main_test)
