# 1. String：字符串

在C语言中，字符串是由字符组成的数组，以空字符（Null Character，ASCII码为0）结尾。这个结尾的空字符用于标识字符串的结束。在C标准库（`<string.h>`）中，有多种函数可用于处理字符串。

- [1. String：字符串](#1-string字符串)
  - [1.1. 字符串的定义和初始化](#11-字符串的定义和初始化)
  - [1.2. 常用字符串操作](#12-常用字符串操作)
  - [1.3. 字符串与内存](#13-字符串与内存)
  - [Question List](#question-list)

## 1.1. 字符串的定义和初始化

你可以通过几种不同的方式定义和初始化字符串。

1. 使用字符数组：

    ```c
    char str1[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    ```

    或者更简单地：

    ```c
    char str1[] = "Hello";
    ```

2. 使用字符指针（注意，这样定义的字符串是不可修改的）：

    ```c
    const char *str2 = "Hello";
    ```

## 1.2. 常用字符串操作

1. **拼接（Concatenation）**: 将两个字符串连接起来。
2. **比较（Comparison）**: 比较两个字符串是否相等。
3. **查找（Search）**: 在一个字符串中查找一个字符或子字符串。
4. **长度（Length）**: 计算字符串的长度。

例如，使用 `<string.h>` 库，你可以这样进行操作：

```c
#include <string.h>

// 计算字符串长度
int len = strlen("Hello");

// 字符串拼接
strcat(str1, " World");

// 字符串比较
int cmp = strcmp(str1, str2);

// 在字符串中查找字符
char *ch = strchr(str1, 'e');
```

## 1.3. 字符串与内存

由于C语言没有内建的字符串类型，所以字符串操作往往需要特别注意内存管理。例如，当你使用 `strcat` 函数拼接字符串时，你需要确保目标数组有足够的空间来容纳新增的字符和结尾的空字符。

## Question List

```txt
04_String/
├── 01_reverseString
├── 02_reverseStr
├── 03_replaceSpace
├── 04_reverseWords
├── 05_reverseLeftWords
├── 06_strStr
├── 07_repeatedSubstringPattern
└── README.md
```