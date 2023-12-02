#!/bin/bash
echo "Running cppcheck..."

set -e  # Exit immediately if a command exits with a non-zero status.
TARGET_DIR="./00_Basics/01_Common_Func"

find $TARGET_DIR \
    -type f \( -name "*.c" -o -name "*.h" \) \
    -exec echo "===============" \; \
    -exec cppcheck {} \; \
    || { echo "cppcheck failed for {}"; exit 1; }