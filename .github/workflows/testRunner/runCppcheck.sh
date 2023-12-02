#!/bin/bash
echo "Running cppcheck..."

# Exit immediately if a command exits with a non-zero status.
set -e

# run cppcheck on all .c and .h files in the target directory
TARGET_DIR="./00_Basics/01_Common_Func"

for file in $(find $TARGET_DIR -name '*.c' -or -name '*.h')
do
    echo "=============================="
    cppcheck $file --output-file=cppcheck_output.txt    # run cppcheck and write output to file
    output=$(cat cppcheck_output.txt)                   # read file into variable
    echo "$output"                                      # print variable
    if echo "$output" | grep -q "error"; then           # check if variable contains "error"
        exit 1                                              # exit with error code
    fi
done

# finish up message
echo "=============================="
echo "All files have been checked!"