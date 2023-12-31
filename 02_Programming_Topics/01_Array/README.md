# 1. Array (数组)

In C language, an array is a data structure used to store multiple items of the same type. All elements of an array are stored in contiguous memory locations. Arrays can be one-dimensional, two-dimensional, or multi-dimensional, and each element can be accessed using an index.

- [1. Array (数组)](#1-array-数组)
  - [1.1. One-Dimensional Array](#11-one-dimensional-array)
  - [1.2. Two-Dimensional Array](#12-two-dimensional-array)
  - [1.3. Accessing Array Elements](#13-accessing-array-elements)
  - [1.4. Dynamic Arrays](#14-dynamic-arrays)
  - [1.5. Pros and Cons](#15-pros-and-cons)
  - [1.6. Question List](#16-question-list)

## 1.1. One-Dimensional Array

A one-dimensional array can be seen as a list. For example, a one-dimensional array containing 5 integers can be declared as follows:

```c
int arr[5];
```

Here, `arr` is an array containing 5 integers.

Initializing the array:

```c
int arr[5] = {1, 2, 3, 4, 5};
```

## 1.2. Two-Dimensional Array

A two-dimensional array can be seen as a table with rows and columns. For example:

```c
int matrix[2][3];
```

This is a two-dimensional array with 2 rows and 3 columns.

Initializing the two-dimensional array:

```c
int matrix[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

## 1.3. Accessing Array Elements

Array elements can be accessed using indexes. Note that array indexes in C start from 0.

```c
int first_element = arr[0];  // 访问第一个元素
int second_element = arr[1]; // 访问第二个元素
```

## 1.4. Dynamic Arrays

The C standard library provides functions for dynamic memory allocation, such as `malloc()`, to dynamically create arrays.

```c
int *dynamic_array;
dynamic_array = (int *)malloc(5 * sizeof(int));
```

In this example, `dynamic_array` is a pointer that points to an array of 5 integers.

Remember, after allocating memory using `malloc()`, it is necessary to free that memory using the `free()` function.

## 1.5. Pros and Cons

The main advantage of arrays is fast access speed because they are stored in contiguous memory locations. However, a major drawback of arrays is that their size is fixed, which can be especially problematic when the required amount of memory is unknown.

## 1.6. Question List

```txt
01_Array/
├── 01_binarySearch
├── 02_removeElement
├── 03_sortedSquares
├── 04_minSubArrayLen
├── 05_generateMatrix
└── README.md
```
