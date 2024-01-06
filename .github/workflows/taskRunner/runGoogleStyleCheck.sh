#!/bin/bash
echo "Running clang-format..."

# Exit immediately if a command exits with a non-zero status.
set -e

# run clang-format on all .c and .h files in the target directory
TARGET_DIR="./01_Common_Functions"
TARGET_FILE_TYPES=".*\.\(c\|h\|cc\)"

# Initialize a counter for the number of issues found
ISSUE_COUNT=0

# Process each file and check for style issues
for file in $(find $TARGET_DIR -regex $TARGET_FILE_TYPES)
do
    # Run clang-format and capture any needed replacements
    OUTPUT=$(clang-format -style=file -output-replacements-xml $file)
    if echo "$OUTPUT" | grep -q "<replacement "; then
        # If replacements are found, print the file name and issue details
        echo "=============================="
        echo "Code style issue in file: $file"
        echo "Replacement suggestions:"
        echo "$OUTPUT" | grep -oP '(?<=<replacement ).*(?=</replacement>)'
        # Increment the issue count
        ISSUE_COUNT=$((ISSUE_COUNT+1))
    fi
done

# Check if any issues were found
if [ $ISSUE_COUNT -ne 0 ]; then
    echo "=============================="
    echo "Code style issues found: $ISSUE_COUNT"
    exit 1
fi

echo "=============================="
echo "No code style issues found"
