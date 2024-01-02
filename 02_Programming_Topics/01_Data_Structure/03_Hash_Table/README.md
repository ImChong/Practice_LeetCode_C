# 1. Hash_Table (哈希表)

In C language, a hash table is a data structure used for fast lookup and insertion of elements. A hash table is typically implemented using a combination of an array and linked lists (or other data structures). It uses a hash function to calculate the position (also known as hash bucket or hash slot) where a key should be stored.

- [1. Hash\_Table (哈希表)](#1-hash_table-哈希表)
  - [1.1. Basic Implementation](#11-basic-implementation)
  - [1.2. Example Structure Definition](#12-example-structure-definition)
  - [1.3. Basic Operations](#13-basic-operations)
  - [1.4. Advantages and Disadvantages](#14-advantages-and-disadvantages)
  - [1.5. Question List](#15-question-list)

Hash tables are commonly used to implement associative arrays, which are data structures used to store key-value pairs. With a key, you can quickly find the corresponding value.

## 1.1. Basic Implementation

A simple hash table may consist of an array and some linked lists. Each element of the array is a head pointer of a linked list. When you want to add a key-value pair, you first calculate the hash value of the key using a hash function, and then use this hash value to determine which array index (or hash bucket) to store the key-value pair. Then, you add this key-value pair as a new node to the end of the corresponding index's linked list.

The advantage of doing this is that even if multiple keys have the same hash value (known as hash collision), they can still be stored in the same bucket (the same position in the array) in the linked list.

## 1.2. Example Structure Definition

```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    int value;
    struct Node *next;
};

struct HashTable {
    int size;
    struct Node **list;
};

struct HashTable *createHashTable(int size);

```

## 1.3. Basic Operations

Hash tables typically support the following basic operations:

Insert: Insert a new key-value pair.
Delete: Delete a key-value pair.
Search: Find the value based on the key.

## 1.4. Advantages and Disadvantages

- Advantages
  - Fast Access: Hash tables typically provide constant time complexity for insertion and lookup operations.
- Disadvantages
  - Hash Collisions: When two keys have the same hash value, there needs to be a way to handle this collision, which can make the data structure more complex.
  - Dynamic Resizing: When the hash table becomes too full or too empty, it may need to be dynamically resized, which is a costly operation.

Hash tables are a very useful data structure, especially when you need fast insertion and lookup operations and don't require elements to be sorted. However, implementing a hash table correctly requires addressing various issues, including choosing a good hash function and handling hash collisions.

## 1.5. Question List

```txt
03_Hash_Table/
├── 01_isAnagram
├── 02_intersection
├── 03_isHappy
├── 04_twoSum
├── 05_fourSumCount
├── 06_canConstruct
├── 07_threeSum
├── 08_fourSum
└── README.md
```
