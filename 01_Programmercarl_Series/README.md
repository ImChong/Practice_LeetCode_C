# 代码随想录系列刷题练习

- [代码随想录系列刷题练习](#代码随想录系列刷题练习)
  - [01\_Array：数组](#01_array数组)
  - [02\_Linked\_List：链表](#02_linked_list链表)
    - [单向链表](#单向链表)
    - [双向链表](#双向链表)
    - [优缺点](#优缺点)
  - [03\_Hash\_Table：哈希表](#03_hash_table哈希表)
    - [](#)
  - [04\_String](#04_string)
  - [05\_Double\_Pointer](#05_double_pointer)
  - [06\_Stack\_Queue](#06_stack_queue)
  - [07\_Binary\_Tree](#07_binary_tree)
  - [08\_Backtracking](#08_backtracking)
  - [09\_Greedy](#09_greedy)
  - [10\_Dynamic\_Programming](#10_dynamic_programming)
  - [11\_Monotone\_Stack](#11_monotone_stack)
  - [12\_Graph\_Theory](#12_graph_theory)


<!-- 数组 -->
## 01_Array：数组
在C语言中，数组（Array）是一种数据结构，用于存储多个相同类型的数据项。数组的所有元素存储在连续的内存位置上。数组可以有一维、二维或多维，并且每个元素可以通过索引来访问。

<!-- 链表 -->
## 02_Linked_List：链表
在C语言中，链表（Linked List）是一种复杂的数据结构，用于存储多个元素。与数组不同，链表的元素不是在内存中连续存储的。每个元素（通常称为节点）都包含数据和一个指向下一个元素的指针。链表可以有多种形式，包括单向链表、双向链表和循环链表。
### 单向链表
```c
struct Node {
    int data;
    struct Node* next;
};
```
### 双向链表
```c
struct DoublyNode {
    int data;
    struct DoublyNode* next;
    struct DoublyNode* prev;
};

```
### 优缺点
- 优点
    - 动态大小：链表的大小可以在运行时动态改变。
    - 插入和删除方便：与数组相比，添加或删除节点通常更快，不需要移动其他元素。
- 缺点
    - 访问速度：链表的元素不是连续存储的，所以访问速度通常比数组慢。
    - 更多的内存开销：因为每个节点都需要一个额外的指针字段来存储下一个节点的地址。

链表是一种非常灵活的数据结构，特别适用于需要频繁插入和删除操作的场合。然而，如果你需要快速访问（例如，随机访问）或者不需要经常插入和删除元素，数组可能是更好的选择。

<!-- 哈希表 -->
## 03_Hash_Table：哈希表
在C语言中，哈希表（Hash Table）是一种用于快速查找和添加元素的数据结构。哈希表通常用数组和链表（或其他数据结构）组合实现。它使用一个哈希函数来计算一个键（Key）应存储在哪个位置（也称作哈希桶或哈希槽）。

哈希表通常用于实现关联数组，即用于存储键-值对（Key-Value Pairs）的数据结构。通过键，你可以很快地找到相应的值。

###


<!-- 字符串 -->
## 04_String


<!-- 双指针 -->
## 05_Double_Pointer


<!-- 栈和队列 -->
## 06_Stack_Queue

<!-- 二叉树 -->
## 07_Binary_Tree

<!-- 回溯算法 -->
## 08_Backtracking

<!-- 贪心算法 -->
## 09_Greedy

<!-- 动态规划算法 -->
## 10_Dynamic_Programming

<!-- 单调栈 -->
## 11_Monotone_Stack

<!-- 图论 -->
## 12_Graph_Theory
