# Include the external project module
include(ExternalProject)
set_directory_properties(PROPERTIES EP_PREFIX ${CMAKE_BINARY_DIR}/ThirdParty/googletest)    # Set the download location

# Add the googletest library
ExternalProject_Add(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
)

# Include the gtest library
include_directories(${CMAKE_BINARY_DIR}/ThirdParty/googletest/include)
link_directories(${CMAKE_BINARY_DIR}/ThirdParty/googletest/lib)

# Add the header files
include_directories(${CMAKE_SOURCE_DIR})    # Root directory
include_directories(cfg)                    # Configuration file
include_directories(inc)                    # Header files
include_directories(inc/common_def)         # Common definition header files

# Create the test targets
set(TEST_TARGETS
    commonArray
    commonBinaryTree
    commonCmd
    commonHashTable
    commonLinkedList
    commonLinkedListDummy
    commonQueue
    commonRingBuffer
    commonSingleValue
    commonStack
    commonString
)

# Loop through each test target
foreach(TARGET ${TEST_TARGETS})
    # Set the target source file
    set(TARGET_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/src/${TARGET}.c)
    # Set the target test name
    set(TARGET_TEST_NAME ${TARGET}Test)
    # Set the target test source file
    set(TARGET_TEST_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/test/${TARGET_TEST_NAME}.cc)

    # Check if the target source file and target test source file exist
    if(EXISTS ${TARGET_SOURCE} AND EXISTS ${TARGET_TEST_SOURCE})
        # Create the test target
        add_executable(${TARGET_TEST_NAME} ${TARGET_TEST_SOURCE} ${TARGET_SOURCE})
        # Add the dependency of the test target
        add_dependencies(${TARGET_TEST_NAME} googletest)
        # Add the link library of the test target
        target_link_libraries(${TARGET_TEST_NAME} gtest gtest_main)
    else()
        # Print the error message
        message(STATUS "Either ${TARGET} or ${TARGET_TEST_NAME} does not exist.")
        # Escape the current loop
        continue()
    endif()
endforeach()