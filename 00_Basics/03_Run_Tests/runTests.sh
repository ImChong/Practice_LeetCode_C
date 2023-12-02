#!/bin/bash

set -e
for test in $(find ./build/bin -executable -type f); do
    $test
done