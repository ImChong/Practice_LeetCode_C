#!/bin/bash
echo "Running cppcheck..."

# Exit immediately if a command exits with a non-zero status.
set -e

# run cppcheck on all .c and .h files in the target directory
TARGET_DIR="./00_Basics/01_Common_Func"

for file in $(find $TARGET_DIR -name '*.c' -or -name '*.h')
do
    echo "=============================="
    output=$(cppcheck $file)
    echo "$output"
    echo "test point 1"
    if echo "$output" | grep -q "error"; then   # if output contains "error"
        echo "test point 2"
        echo "cppcheck found errors!"
        exit 1                                      # exit with error
    fi
done