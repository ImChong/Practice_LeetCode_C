#!/bin/bash
echo "Running cpplint..."

# Exit immediately if a command exits with a non-zero status.
set -e

# run cpplint on all .c and .h files in the target directory
TARGET_DIR="./F01_Common_Functions"
TARGET_FILE_TYPES=".*\.\(cpp\|hpp\|cc\|c\|h\)"

for file in $(find $TARGET_DIR -regex $TARGET_FILE_TYPES)
do
    echo "=============================="
    cpplint --linelength=120 $file            # run cpplint, change line length to 120
done

# finish up message
echo "=============================="
echo "All files have been linted!"