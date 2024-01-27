#!/bin/bash

# Exit immediately if a command exits with a non-zero status.
set -e

# set test names
tests=("common_array_test" \
    "common_binary_tree_test" \
    "common_cmd_test" \
    "common_hash_table_test" \
    "common_linked_list_test" \
    "common_linked_list_dummy_test" \
    "common_queue_test" \
    "common_ring_buffer_test" \
    "common_single_value_test" \
    "common_stack_test" \
    "common_string_test"
)

# Initialize file number counter
FILE_COUNT=0

# run gtest executables in the build/bin directory
for test in "${tests[@]}"; do
    # find all the files that has the same name as test in the ./build/bin/ folder
    file=$(find ./build/bin/ -type f -executable -name "$test*")
    echo "=========================================================================================="
    # if the result file is an executable file
    if [[ -f $file && -x $file ]]; then
        echo "Executable $file found. Starting test..."
        echo "=========================================================================================="
        $file   # run GTest executables
    else
        echo "Executable $test not found."
        echo "=========================================================================================="
    fi

    FILE_COUNT=$((FILE_COUNT+1))
done

# finish up message
echo "=========================================================================================="
echo "All executables have been run!"
echo "Total number of test run: $FILE_COUNT"