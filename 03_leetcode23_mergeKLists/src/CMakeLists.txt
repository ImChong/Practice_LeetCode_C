include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(lib_leetcode023 OBJECT leetcode023.c)
add_executable(leetcode023 main.c)

target_link_libraries(leetcode023 lib_leetcode023)
