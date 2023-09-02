# 1. C 语言编码知识笔记
- [1. C 语言编码知识笔记](#1-c-语言编码知识笔记)
  - [1.1. 内存分配和初始化](#11-内存分配和初始化)
    - [1.1.1. struct TreeNode \*root; 和 struct TreeNode \*root = malloc(sizeof(struct TreeNode)); 有什么区别？](#111-struct-treenode-root-和-struct-treenode-root--mallocsizeofstruct-treenode-有什么区别)
    - [1.1.2. struct TreeNode \*stk\[MAX\_SIZE\]; 和 struct TreeNode \*\*stk = (struct TreeNode \*\*)malloc(sizeof(struct TreeNode \*) \* MAX\_SIZE); 的区别？](#112-struct-treenode-stkmax_size-和-struct-treenode-stk--struct-treenode-mallocsizeofstruct-treenode---max_size-的区别)
      - [1.1.2.1. 堆栈存储 vs 堆存储](#1121-堆栈存储-vs-堆存储)
      - [1.1.2.2. 生命周期](#1122-生命周期)
      - [1.1.2.3. 可扩展性](#1123-可扩展性)
      - [1.1.2.4. 初始化](#1124-初始化)
      - [1.1.2.5. 语法和类型](#1125-语法和类型)


## 1.1. 内存分配和初始化
### 1.1.1. struct TreeNode *root; 和 struct TreeNode *root = malloc(sizeof(struct TreeNode)); 有什么区别？
---
```c
struct TreeNode *root;
```
这行代码仅声明了一个名为 `root` 的指针，该指针用于指向 `struct TreeNode` 类型的对象。然而，这个指针目前没有指向任何有效的内存地址，也就是说，它是一个"悬挂"或"未初始化"的指针。在许多情况下，编译器不会为这个指针分配默认值（即，它可能包含随机内存地址），所以在使用这个指针之前进行解引用或赋值操作是非常危险的。
```c
struct TreeNode *root = malloc(sizeof(struct TreeNode));
```
这行代码做了更多的事情：
1. 它声明了一个名为 `root` 的指针，用于指向 `struct TreeNode` 类型的对象。
2. 它使用 `malloc` 函数分配了足够存储一个 `struct TreeNode` 对象的内存。`sizeof(struct TreeNode)` 计算所需的内存大小。
3. `malloc` 返回的内存地址被赋给了 `root` 指针。

这样，`root` 就指向了一个有效的内存地址，您可以安全地对该内存进行读写操作（假设 `malloc` 成功，没有返回 `NULL`）。

### 1.1.2. struct TreeNode *stk[MAX_SIZE]; 和 struct TreeNode **stk = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * MAX_SIZE); 的区别？
---
```c
struct TreeNode *stk[MAX_SIZE];
```
和
```c
struct TreeNode **stk = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * MAX_SIZE);
```
都用于创建一个指针数组，该数组的元素类型为 `struct TreeNode*`。但两者有几个主要区别：
#### 1.1.2.1. 堆栈存储 vs 堆存储
- `struct TreeNode *stk[MAX_SIZE];`：在栈内存中分配空间。
- `struct TreeNode **stk = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * MAX_SIZE);`：在堆内存中分配空间。
#### 1.1.2.2. 生命周期
- 栈内存：存活期限是函数调用期间。当函数返回后，这个空间就会被回收。
- 堆内存：直到你明确地使用 `free()` 释放它，否则它将一直存在。
#### 1.1.2.3. 可扩展性
- 栈内存：大小在编译时需要确定，并且不能动态更改。
- 堆内存：你可以在运行时动态分配和调整大小。
#### 1.1.2.4. 初始化
- 栈内存：编译器会自动初始化（通常是零初始化）。
- 堆内存：默认情况下不进行初始化，必须手动进行初始化。
#### 1.1.2.5. 语法和类型
- `struct TreeNode *stk[MAX_SIZE];` 是一个指针数组。
- `struct TreeNode **stk = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * MAX_SIZE);` 是一个指向指针数组的指针。

尽管这两种方式都可以达到相似的目的，但它们适用于不同的场景和需求。堆内存更适用于动态和长寿命的数据，而栈内存更适用于短寿命和固定大小的数据。