#!/bin/bash

# Exit immediately if a command exits with a non-zero status.
set -e

# run gtest executables in the build/bin directory
for test in $(find ./build/bin -executable -type f); do
    echo "=============================="
    $test
done

echo "=============================="
echo "All executables have been run!"