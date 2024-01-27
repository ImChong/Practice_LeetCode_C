#!/bin/bash
echo "Running cppcheck..."

# Exit immediately if a command exits with a non-zero status.
set -e

# run cppcheck on all .c and .h files in the target directory
TARGET_DIR="./F01_Common_Functions"
TARGET_FILE_TYPES=".*\.\(c\|h\|cc\)"

# Initialize file number counter
FILE_COUNT=0

for file in $(find $TARGET_DIR -regex $TARGET_FILE_TYPES)
do
    echo "=============================="
    cppcheck $file --output-file=cppcheck_output.txt    # run cppcheck and write output to file
    output=$(cat cppcheck_output.txt)                   # read file into variable
    echo "$output"                                      # print variable
    if echo "$output" | grep -q "error"; then           # check if variable contains "error"
        exit 1                                              # exit with error code
    fi

    FILE_COUNT=$((FILE_COUNT+1))
done

# finish up message
echo "=============================="
echo "All files have been checked!"
echo "Total number of files checked: $FILE_COUNT"