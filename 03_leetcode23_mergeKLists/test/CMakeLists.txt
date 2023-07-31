add_executable(
    main_test
    ${CMAKE_CURRENT_SOURCE_DIR}/main_test.cc
)

target_link_libraries(
    main_test
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(main_test)