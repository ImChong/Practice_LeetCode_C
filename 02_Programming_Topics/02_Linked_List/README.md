# 1. Linked_List (链表)

在C语言中，链表（Linked List）是一种复杂的数据结构，用于存储多个元素。与数组不同，链表的元素不是在内存中连续存储的。每个元素（通常称为节点）都包含数据和一个指向下一个元素的指针。链表可以有多种形式，包括单向链表、双向链表和循环链表。

- [1. Linked\_List (链表)](#1-linked_list-链表)
  - [1.1. Singly Linked List](#11-singly-linked-list)
  - [1.2. Doubly Linked List](#12-doubly-linked-list)
  - [1.3. Advantages and Disadvantages](#13-advantages-and-disadvantages)
  - [1.4. Question List](#14-question-list)

## 1.1. Singly Linked List

```c
struct Node {
    int data;
    struct Node* next;
};
```

## 1.2. Doubly Linked List

```c
struct DoublyNode {
    int data;
    struct DoublyNode* next;
    struct DoublyNode* prev;
};
```

## 1.3. Advantages and Disadvantages

- Advantages
  - Dynamic size: The size of the linked list can change dynamically at runtime.
  - Easy insertion and deletion: Compared to arrays, adding or deleting nodes is usually faster, without the need to move other elements.
- Disadvantages
  - Access speed: The elements of the linked list are not stored continuously, so the access speed is usually slower than arrays.
  - More memory overhead: Because each node needs an additional pointer field to store the address of the next node.
Linked lists are a very flexible data structure, especially suitable for situations that require frequent insertion and deletion operations. However, if you need quick access (for example, random access) or do not need to frequently insert and delete elements, arrays may be a better choice.

## 1.4. Question List

```txt
02_Linked_List/
├── 00_common
├── 01_removeElements
├── 02_myLinkedListCreate
├── 03_reverseList
├── 04_swapPairs
├── 05_removeNthFromEnd
├── 06_getIntersectionNode
├── 07_detectCycle
├── 07_hasCycle
├── 08_mergeTwoLists
├── 09_partition
├── 10_mergeKLists
├── 11_middleNode
└── README.md
```