#!/bin/bash
echo "Running clang-format..."

# Exit immediately if a command exits with a non-zero status.
set -e

# run cpplint on all .c and .h files in the target directory
TARGET_DIR="./01_Common_Functions"

# 查找所有的 C++ 文件并运行 clang-format
find $TARGET_DIR -regex '.*\.\(cpp\|hpp\|cc\|h\)' -exec clang-format -style=google -output-replacements-xml {} \; | grep "<replacement " > /dev/null

# 检查上一个命令的返回值
if [ $? -ne 1 ]; then
    echo "=============================="
    echo "Code style issues found"
    exit 1
fi

echo "=============================="
echo "No code style issues found"