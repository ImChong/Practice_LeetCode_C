#!/bin/bash
echo "Running cppcheck..."

set -e  # Exit immediately if a command exits with a non-zero status.
TARGET_DIR="./00_Basics/01_Common_Func"

find $TARGET_DIR \
    -type f \( -name "*.c" -o -name "*.h" \) \
    -exec echo " =============== " \; \
    -exec echo "Checking file: {} ..." \; \
    -exec cppcheck {} 2>&1 | tee cppcheck_output.txt \;

if grep -q "error:" cppcheck_output.txt; then
    echo "cppcheck found errors"
    exit 1
fi