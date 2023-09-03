# 代码随想录系列刷题练习

[数组](01_Array/README.md)                      <!-- 数组 -->

[链表](02_Linked_List/README.md)                <!-- 链表 -->

[链表](03_Hash_Table/README.md)                 <!-- 哈希表 -->

[字符串](04_String/README.md)                   <!-- 字符串 -->

[双指针算法](05_Double_Pointer/README.md)       <!-- 双指针算法 -->




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
