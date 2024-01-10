# 1. String (字符串)

In C language, a string is an array of characters that ends with a null character (ASCII code 0). This null character is used to indicate the end of the string. The C standard library (`<string.h>`) provides multiple functions for string manipulation.

- [1. String (字符串)](#1-string-字符串)
  - [1.1. Definition and Initialization of Strings](#11-definition-and-initialization-of-strings)
  - [1.2. Common String Operations](#12-common-string-operations)
  - [1.3. Strings and Memory](#13-strings-and-memory)
  - [1.4. Question List](#14-question-list)

## 1.1. Definition and Initialization of Strings

You can define and initialize strings in several different ways.

1. Using a character array:

  ```c
  char str1[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
  ```

  Or, more simply:

  ```c
  char str1[] = "Hello";
  ```

2. Using a character pointer (note that strings defined this way are not modifiable):

    ```c
    const char *str2 = "Hello";
    ```

## 1.2. Common String Operations

1. **Concatenation**: Join two strings together.
2. **Comparison**: Compare two strings for equality.
3. **Search**: Find a character or substring within a string.
4. **Length**: Calculate the length of a string.

For example, using the `<string.h>` library, you can perform these operations:

```c
#include <string.h>

// Calculate the length of a string
int len = strlen("Hello");

// String concatenation
strcat(str1, " World");

// String comparison
int cmp = strcmp(str1, str2);

// Locate a character in a string
char *ch = strchr(str1, 'e');
```

## 1.3. Strings and Memory

Since C language does not have a built-in string type, string operations often require special attention to memory management. For example, when using the `strcat` function to concatenate strings, you need to ensure that the target array has enough space to accommodate the added characters and the terminating null character.

## 1.4. Question List

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