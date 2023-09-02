# 1. C 语言编码知识笔记
- [1. C 语言编码知识笔记](#1-c-语言编码知识笔记)
  - [1.1. 研发通识](#11-研发通识)
    - [1.1.1. 正则表达式](#111-正则表达式)
  - [1.2. 内存分配和初始化](#12-内存分配和初始化)
    - [1.2.1. struct TreeNode \*root; 和 struct TreeNode \*root = malloc(sizeof(struct TreeNode)); 有什么区别？](#121-struct-treenode-root-和-struct-treenode-root--mallocsizeofstruct-treenode-有什么区别)
    - [1.2.2. struct TreeNode \*stk\[MAX\_SIZE\]; 和 struct TreeNode \*\*stk = (struct TreeNode \*\*)malloc(sizeof(struct TreeNode \*) \* MAX\_SIZE); 的区别？](#122-struct-treenode-stkmax_size-和-struct-treenode-stk--struct-treenode-mallocsizeofstruct-treenode---max_size-的区别)
      - [1.2.2.1. 堆栈存储 vs 堆存储](#1221-堆栈存储-vs-堆存储)
      - [1.2.2.2. 生命周期](#1222-生命周期)
      - [1.2.2.3. 可扩展性](#1223-可扩展性)
      - [1.2.2.4. 初始化](#1224-初始化)
      - [1.2.2.5. 语法和类型](#1225-语法和类型)

## 1.1. 研发通识

### 1.1.1. 正则表达式

正则表达式（Regular Expression，常简写为 regex 或 regexp）是一种用于匹配字符串中字符组合的模式。正则表达式常用于字符串匹配、查找、以及替换操作。

在正则表达式中，有多种特殊符号和字符，用于定义字符串的搜索模式。例如：

- .（点）通常用于匹配任何单一字符。
- * 表示前面的字符可以出现零次或多次。
- + 表示前面的字符可以出现一次或多次。
- ? 表示前面的字符可以出现零次或一次。
- [abc] 用于匹配方括号内列出的任何单一字符。
- ^ 和 $ 分别用于匹配字符串的开始和结束。
- | 用于分隔不同的匹配选项（或运算）。

例如，正则表达式 a.b 可以匹配 "acb"、"aab"、"abb" 等，其中的 . 可以是任何字符。

正则表达式广泛应用于很多编程语言，如 Python、JavaScript、Java、Perl、C# 等，也用于很多文本编辑器和工具，如 grep、sed、awk 等，以进行复杂的文本操作。

因为正则表达式提供了强大而灵活的匹配功能，所以它在数据分析、文本处理、数据验证等方面都有广泛的应用。

需要注意的是，正则表达式的语法和特性可能因语言和工具的不同而有所差异。所以，在使用正则表达式之前，最好查阅相关工具或编程语言的文档。


---

## 1.2. 内存分配和初始化
### 1.2.1. struct TreeNode *root; 和 struct TreeNode *root = malloc(sizeof(struct TreeNode)); 有什么区别？

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


### 1.2.2. struct TreeNode *stk[MAX_SIZE]; 和 struct TreeNode **stk = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * MAX_SIZE); 的区别？
```c
struct TreeNode *stk[MAX_SIZE];
```
和
```c
struct TreeNode **stk = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * MAX_SIZE);
```
都用于创建一个指针数组，该数组的元素类型为 `struct TreeNode*`。但两者有几个主要区别：
#### 1.2.2.1. 堆栈存储 vs 堆存储
- `struct TreeNode *stk[MAX_SIZE];`：在栈内存中分配空间。
- `struct TreeNode **stk = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * MAX_SIZE);`：在堆内存中分配空间。
#### 1.2.2.2. 生命周期
- 栈内存：存活期限是函数调用期间。当函数返回后，这个空间就会被回收。
- 堆内存：直到你明确地使用 `free()` 释放它，否则它将一直存在。
#### 1.2.2.3. 可扩展性
- 栈内存：大小在编译时需要确定，并且不能动态更改。
- 堆内存：你可以在运行时动态分配和调整大小。
#### 1.2.2.4. 初始化
- 栈内存：编译器会自动初始化（通常是零初始化）。
- 堆内存：默认情况下不进行初始化，必须手动进行初始化。
#### 1.2.2.5. 语法和类型
- `struct TreeNode *stk[MAX_SIZE];` 是一个指针数组。
- `struct TreeNode **stk = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * MAX_SIZE);` 是一个指向指针数组的指针。

尽管这两种方式都可以达到相似的目的，但它们适用于不同的场景和需求。堆内存更适用于动态和长寿命的数据，而栈内存更适用于短寿命和固定大小的数据。