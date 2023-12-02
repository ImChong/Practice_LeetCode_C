#!/bin/bash
echo "Running cpplint..."

# Exit immediately if a command exits with a non-zero status.
# set -e

# run cpplint on all .c and .h files in the target directory
TARGET_DIR="./00_Basics/01_Common_Func"

for file in $(find $TARGET_DIR -name '*.c' -or -name '*.h')
do
    echo "=============================="
    cpplint --linelength=120 $file
done