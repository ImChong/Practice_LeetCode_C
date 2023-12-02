#!/bin/bash
echo "Running cppcheck..."

set -e  # Exit immediately if a command exits with a non-zero status.
TARGET_DIR="./00_Basics/01_Common_Func"

for file in "$TARGET_DIR"/*.{c,h}; do
    echo "Checking $file..."
    if [ -f "$file" ]; then
        cppcheck "$file" || { echo "cppcheck failed for $file"; exit 1; }
        echo "===> cppcheck passed for $file."
    fi
done