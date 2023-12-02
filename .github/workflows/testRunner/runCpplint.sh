#!/bin/bash
echo "Running cpplint..."

set -e  # Exit immediately if a command exits with a non-zero status.
TARGET_DIR="./00_Basics/01_Common_Func"



cpplint --recursive 00_Basics/01_Common_Func/**/*.c 00_Basics/01_Common_Func/**/*.h