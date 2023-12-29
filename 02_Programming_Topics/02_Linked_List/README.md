# 1. Linked_List：链表

在C语言中，链表（Linked List）是一种复杂的数据结构，用于存储多个元素。与数组不同，链表的元素不是在内存中连续存储的。每个元素（通常称为节点）都包含数据和一个指向下一个元素的指针。链表可以有多种形式，包括单向链表、双向链表和循环链表。

- [1. Linked\_List：链表](#1-linked_list链表)
  - [1.1. 单向链表](#11-单向链表)
  - [1.2. 双向链表](#12-双向链表)
  - [1.3. 优缺点](#13-优缺点)
  - [1.4. Question List](#14-question-list)

## 1.1. 单向链表

```c
struct Node {
    int data;
    struct Node* next;
};
```

## 1.2. 双向链表

```c
struct DoublyNode {
    int data;
    struct DoublyNode* next;
    struct DoublyNode* prev;
};
```

## 1.3. 优缺点

- 优点
  - 动态大小：链表的大小可以在运行时动态改变。
  - 插入和删除方便：与数组相比，添加或删除节点通常更快，不需要移动其他元素。
- 缺点
  - 访问速度：链表的元素不是连续存储的，所以访问速度通常比数组慢。
  - 更多的内存开销：因为每个节点都需要一个额外的指针字段来存储下一个节点的地址。

链表是一种非常灵活的数据结构，特别适用于需要频繁插入和删除操作的场合。然而，如果你需要快速访问（例如，随机访问）或者不需要经常插入和删除元素，数组可能是更好的选择。

## 1.4. Question List

```txt
.
├───00_common
│   ├───00_noDummyMethod
│   │   ├───cfg
│   │   ├───inc
│   │   └───src
│   └───01_dummyMethod
│       ├───cfg
│       ├───inc
│       └───src
├───01_removeElements
│   ├───cfg
│   ├───inc
│   └───src
├───02_myLinkedListCreate
│   ├───cfg
│   ├───inc
│   └───src
├───03_reverseList
│   ├───cfg
│   ├───inc
│   └───src
├───04_swapPairs
│   ├───cfg
│   ├───inc
│   └───src
├───05_removeNthFromEnd
│   ├───cfg
│   ├───inc
│   └───src
├───06_getIntersectionNode
│   ├───cfg
│   ├───inc
│   └───src
├───07_detectCycle
│   ├───cfg
│   ├───inc
│   └───src
├───07_hasCycle
│   ├───cfg
│   ├───inc
│   └───src
├───08_mergeTwoLists
│   ├───cfg
│   ├───inc
│   └───src
├───09_partition
│   ├───cfg
│   ├───inc
│   └───src
├───10_mergeKLists
│   ├───cfg
│   ├───inc
│   └───src
└───11_middleNode
    ├───cfg
    ├───inc
    └───src
```