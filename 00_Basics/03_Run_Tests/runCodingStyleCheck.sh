#!/bin/bash

set -e  # Exit immediately if a command exits with a non-zero status.

TARGET_DIR="./00_Basics/01_Common_Func"

for file in "$TARGET_DIR"/*; do
    clang-format -i "$file" || { echo "clang-format check failed for $file"; exit 1; }
    cppcheck "$file" || { echo "cppcheck failed for $file"; exit 1; }
done