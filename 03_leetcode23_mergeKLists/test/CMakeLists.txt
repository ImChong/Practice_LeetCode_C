add_executable(
    main_test
    main_test.cc
)

target_link_libraries(
    main_test
    gtest
    gtest_main
)

include(GoogleTest)
add_test(NAME test COMMAND main_test)
