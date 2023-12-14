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
    executable=$(find ./build/bin/ -type f -executable -name "$test*")
    echo "=========================================================================================="
    if [[ -f $executable && -x $executable ]]; then
        echo "Executable $executable found. Starting test..."
        echo "=========================================================================================="
        $executable   # run GTest executables
    else
        echo "Executable $test not found."
        echo "=========================================================================================="
    fi
done

# finish up message
echo "=========================================================================================="
echo "All executables have been run!"