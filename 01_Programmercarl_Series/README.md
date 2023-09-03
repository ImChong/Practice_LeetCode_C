# 代码随想录系列刷题练习

- [代码随想录系列刷题练习](#代码随想录系列刷题练习)
  - [01\_Array：数组](#01_array数组)
    - [一维数组](#一维数组)
    - [二维数组](#二维数组)
    - [访问数组元素](#访问数组元素)
    - [动态数组](#动态数组)
    - [优缺点](#优缺点)
  - [02\_Linked\_List：链表](#02_linked_list链表)
    - [单向链表](#单向链表)
    - [双向链表](#双向链表)
    - [优缺点](#优缺点-1)
  - [03\_Hash\_Table：哈希表](#03_hash_table哈希表)
    - [基础实现](#基础实现)
    - [示例结构定义](#示例结构定义)
    - [基础操作](#基础操作)
    - [优缺点](#优缺点-2)
  - [04\_String：字符串](#04_string字符串)
    - [字符串的定义和初始化](#字符串的定义和初始化)
    - [常用字符串操作](#常用字符串操作)
    - [字符串与内存](#字符串与内存)
  - [05\_Double\_Pointer：双指针算法](#05_double_pointer双指针算法)
    - [数组去重](#数组去重)
    - [快慢指针](#快慢指针)
    - [二分搜索](#二分搜索)
    - [双指针在排序数组中查找和为特定值的两个元素](#双指针在排序数组中查找和为特定值的两个元素)
  - [06\_Stack\_Queue：栈和队列](#06_stack_queue栈和队列)
    - [栈（Stack）](#栈stack)
    - [队列（Queue）](#队列queue)
  - [07\_Binary\_Tree：二叉树](#07_binary_tree二叉树)
  - [08\_Backtracking：回溯算法](#08_backtracking回溯算法)
  - [09\_Greedy：贪心算法](#09_greedy贪心算法)
  - [10\_Dynamic\_Programming：动态规划算法](#10_dynamic_programming动态规划算法)
  - [11\_Monotone\_Stack：单调栈](#11_monotone_stack单调栈)
  - [12\_Graph\_Theory：单调栈](#12_graph_theory单调栈)


<!-- 数组 -->
## 01_Array：数组
在C语言中，数组（Array）是一种数据结构，用于存储多个相同类型的数据项。数组的所有元素存储在连续的内存位置上。数组可以有一维、二维或多维，并且每个元素可以通过索引来访问。

### 一维数组
一维数组可以看作是一个列表。例如，一个包含5个整数的一维数组可以声明如下：
```c
int arr[5];
```
在这里，`arr` 是一个包含5个整数的数组。

初始化数组：
```c
int arr[5] = {1, 2, 3, 4, 5};
```

### 二维数组
二维数组可以看作是一个表格，有行和列。例如：
```c
int matrix[2][3];
```
这是一个有2行和3列的二维数组。

初始化二维数组：
```c
int matrix[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

### 访问数组元素
数组元素可以通过索引来访问。注意，C语言的数组索引是从0开始的。
```c
int first_element = arr[0];  // 访问第一个元素
int second_element = arr[1]; // 访问第二个元素
```

### 动态数组
C语言标准库提供了动态内存分配的函数，如 `malloc()`，以动态地创建数组。
```c
int *dynamic_array;
dynamic_array = (int *)malloc(5 * sizeof(int));
```
在这个例子中，`dynamic_array` 是一个指针，指向一个有5个整数的数组。

记住，在使用 `malloc()` 分配的内存后，最终需要使用 `free()` 函数来释放这些内存。

### 优缺点
数组的主要优点是访问速度快，因为它们存储在连续的内存位置上。但是，数组的大小是固定的，这是它的一个主要缺点，尤其是在不知道需要多少内存的情况下。


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

### 基础实现
一个简单的哈希表可能包括一个数组和一些链表。数组的每个元素都是链表的头指针。当你要添加一个键-值对时，首先使用哈希函数计算键的哈希值，然后用这个哈希值来确定应该在哪个数组索引（或哈希桶）中存储这个键-值对。然后，你将这个键-值对作为一个新节点添加到相应索引处链表的末尾。

这样做的好处是即使多个键的哈希值相同（这称为哈希冲突），它们也可以存储在同一个桶（数组的同一个位置）的链表中。

### 示例结构定义
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

### 基础操作
哈希表通常支持以下几种基本操作：

插入（Insert）: 插入一个新的键-值对。
删除（Delete）: 删除一个键-值对。
查找（Search）: 根据键查找值。
### 优缺点
- 优点
    - 快速访问: 哈希表通常提供常数时间复杂度的插入和查找操作。
- 缺点
    - 哈希冲突: 当两个键的哈希值相同时，需要有一种方法来处理这种冲突，这通常会使数据结构变得复杂。
    - 动态调整大小: 当哈希表变得太满或太空时，可能需要动态地调整其大小，这是一个代价高昂的操作。

哈希表是一种非常有用的数据结构，尤其是当你需要快速插入和查找操作，并且不需要元素保持有序时。不过，正确地实现一个哈希表需要解决多种问题，包括选择一个好的哈希函数和处理哈希冲突。

<!-- 字符串 -->
## 04_String：字符串
在C语言中，字符串是由字符组成的数组，以空字符（Null Character，ASCII码为0）结尾。这个结尾的空字符用于标识字符串的结束。在C标准库（`<string.h>`）中，有多种函数可用于处理字符串。

### 字符串的定义和初始化
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

### 常用字符串操作
1. **拼接（Concatenation）**: 将两个字符串连接起来。
2. **比较（Comparison）**: 比较两个字符串是否相等。
3. **查找（Search）**: 在一个字符串中查找一个字符或子字符串。
4. **长度（Length）**: 计算字符串的长度。

例如，使用 `<string.h> `库，你可以这样进行操作：
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
### 字符串与内存
由于C语言没有内建的字符串类型，所以字符串操作往往需要特别注意内存管理。例如，当你使用 `strcat` 函数拼接字符串时，你需要确保目标数组有足够的空间来容纳新增的字符和结尾的空字符。

<!-- 双指针算法 -->
## 05_Double_Pointer：双指针算法
"双指针算法"并不是C语言或其他编程语言的内置概念，而是一种常用的算法策略。在双指针算法中，我们使用两个指针而不是一个来遍历数组、链表或其他数据结构。这种算法通常用于解决需要在一维或二维数据结构中找到某种特定关系的问题。

以下是一些使用双指针算法的典型应用场景：
### 数组去重
假设你有一个排序过的整数数组，你希望去除其中的重复元素。
```c
int removeDuplicates(int* nums, int numsSize){
    if (numsSize == 0) return 0;
    int i = 0;
    for (int j = 1; j < numsSize; j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}
```
在这里，`i` 和 `j` 是两个指针，分别用于跟踪新数组的最后一个元素和原始数组的当前元素。

### 快慢指针
在链表中找到中点或检测循环通常使用快慢指针。
```c
struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    struct ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}
```

### 二分搜索
在有序数组中查找元素时，通常使用两个指针指向当前搜索范围的开始和结束，然后用二分法缩小搜索范围。
```c
int binarySearch(int* arr, int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}
```

### 双指针在排序数组中查找和为特定值的两个元素
```c
void twoSum(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            printf("Found: %d, %d\n", nums[left], nums[right]);
            return;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    printf("Not found\n");
}
```
以上只是双指针算法的几个例子。这种算法能有效地解决许多问题，通常能减少时间和/或空间复杂性。不过，编写双指针算法需要非常小心，以避免出现越界或其他错误。


<!-- 栈和队列 -->
## 06_Stack_Queue：栈和队列
栈（Stack）和队列（Queue）是两种基础的数据结构，它们用于存储和管理数据集合。尽管这两种数据结构在很多高级编程语言中都有内置的实现，C语言本身并没有提供这些数据结构的内置支持。然而，你可以使用数组或链表来实现它们。

### 栈（Stack）
栈是一个后进先出（Last-In-First-Out，LIFO）的数据结构。这意味着最后一个被添加到栈中的元素将是第一个被移除的。栈主要有两个基本操作：
1. **压栈（Push）**：在栈顶添加一个元素。
2. **出栈（Pop）**：移除并返回栈顶元素。

下面是使用数组实现栈的一个简单示例：
```c
#define MAX 10 // 定义栈的最大容量

int stack[MAX];
int top = -1; // 初始化栈顶指针

// 压栈操作
void push(int x) {
    if (top >= MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = x;
}

// 出栈操作
int pop() {
    if (top < 0) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}
```
### 队列（Queue）
队列是一个先进先出（First-In-First-Out，FIFO）的数据结构。这意味着第一个被添加到队列中的元素将是第一个被移除的。队列主要有两个基本操作：
1. **入队（Enqueue）**：在队尾添加一个元素。
2. **出队（Dequeue）**：移除并返回队首元素。

下面是使用数组实现队列的一个简单示例：
```c
#define MAX 10 // 定义队列的最大容量

int queue[MAX];
int front = 0; // 初始化队首指针
int rear = -1; // 初始化队尾指针

// 入队操作
void enqueue(int x) {
    if (rear >= MAX - 1) {
        printf("Queue overflow\n");
        return;
    }
    queue[++rear] = x;
}

// 出队操作
int dequeue() {
    if (front > rear) {
        printf("Queue underflow\n");
        return -1;
    }
    return queue[front++];
}
```
需要注意的是，以上的示例代码为了简单明了，并没有涉及动态分配内存或其他高级特性。

栈常用于实现函数调用、深度优先搜索（DFS）、表达式求值等；而队列常用于广度优先搜索（BFS）、任务调度等。在C语言中，你可以根据具体的需求，使用数组或链表等基础数据结构来实现这些高级数据结构。


<!-- 二叉树 -->
## 07_Binary_Tree：二叉树

<!-- 回溯算法 -->
## 08_Backtracking：回溯算法

<!-- 贪心算法 -->
## 09_Greedy：贪心算法

<!-- 动态规划算法 -->
## 10_Dynamic_Programming：动态规划算法

<!-- 单调栈 -->
## 11_Monotone_Stack：单调栈

<!-- 单调栈 -->
## 12_Graph_Theory：单调栈
