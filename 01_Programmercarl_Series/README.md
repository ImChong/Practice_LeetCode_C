# 代码随想录系列刷题练习

<!-- 数组 -->
[数组](01_Array/README.md)

<!-- 链表 -->
[链表](02_Linked_List/README.md)

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
在C语言中，二叉树（Binary Tree）是一种特殊的树形数据结构，在这种结构中，每个节点最多有两个子节点，通常被称为“左子节点”和“右子节点”。

### 定义
一个典型的二叉树节点在C语言中可以用结构体（struct）来定义：
```c
struct Node {
    int data;  // 节点存储的数据
    struct Node* left;  // 指向左子节点的指针
    struct Node* right;  // 指向右子节点的指针
};
```

### 创建和初始化
以下是如何创建和初始化一个简单的二叉树的例子：
```c
#include <stdlib.h>

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    // 创建根节点
    struct Node* root = newNode(1);

    // 添加左子节点和右子节点
    root->left = newNode(2);
    root->right = newNode(3);

    // 为左子节点添加子节点
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    // 为右子节点添加子节点
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    // 此时，我们有了一个拥有7个节点的二叉树。

    return 0;
}
```

### 遍历
二叉树有多种遍历方法，包括：

1. **前序遍历（Preorder）**：先访问根节点，然后遍历左子树，最后遍历右子树。
2. **中序遍历（Inorder）**：先遍历左子树，然后访问根节点，最后遍历右子树。
3. **后序遍历（Postorder）**：先遍历左子树，然后遍历右子树，最后访问根节点。

例如，前序遍历的代码可能如下：
```c
void preorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
```

### 应用
二叉树在计算机科学和编程中有广泛的应用，包括但不限于：

1. **二叉搜索树（Binary Search Trees）**：用于高效地搜索、插入和删除数据。
2. **堆（Heaps）**：用于实现优先队列。
3. **平衡树（如AVL Trees, Red-Black Trees等）**：用于维护排序数据的高效访问和修改。
4. **用于解析表达式**：编译器可能使用二叉树来解析和求值数学或逻辑表达式。
5. **文件系统的目录结构**：可以看作是一种树形结构，虽然通常不是二叉树。

二叉树是数据结构和算法中非常重要的一个概念，掌握它有助于解决许多复杂的问题。

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
