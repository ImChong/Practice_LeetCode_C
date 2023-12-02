#!/bin/bash

set -e  # Exit immediately if a command exits with a non-zero status.
for test in $(find ./build/bin -executable -type f); do
    $test
done