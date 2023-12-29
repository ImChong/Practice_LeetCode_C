#!/bin/bash

# Exit immediately if a command exits with a non-zero status.
set -e

# set test names
tests=("commonArrayTest" \
    "commonBinaryTreeTest" \
    "commonCmdTest" \
    "commonHashTableTest" \
    "commonLinkedListTest" \
    "commonLinkedListDummyTest" \
    "commonQueueTest" \
    "commonRingBufferTest" \
    "commonSingleValueTest" \
    "commonStackTest" \
    "commonStringTest"
)

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
done

# finish up message
echo "=========================================================================================="
echo "All executables have been run!"