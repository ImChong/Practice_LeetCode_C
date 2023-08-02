add_executable(test_leetcode023 test_leetcode023.cc)

target_link_libraries(
    main_test
    gtest
    gtest_main
)

include(GoogleTest)
add_test(NAME test COMMAND main_test)
