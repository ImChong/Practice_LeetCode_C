# C语言编码知识笔记
- [C语言编码知识笔记](#c语言编码知识笔记)
- [1. 内存分配和初始化](#1-内存分配和初始化)


# 1. 内存分配和初始化
> struct TreeNode *root; 和 struct TreeNode *root = malloc(sizeof(struct TreeNode)); 有什么区别？
```c
struct TreeNode *root;
```
这行代码仅声明了一个名为 root 的指针，该指针用于指向 struct TreeNode 类型的对象。然而，这个指针目前没有指向任何有效的内存地址，也就是说，它是一个"悬挂"或"未初始化"的指针。在许多情况下，编译器不会为这个指针分配默认值（即，它可能包含随机内存地址），所以在使用这个指针之前进行解引用或赋值操作是非常危险的。
```c
struct TreeNode *root = malloc(sizeof(struct TreeNode));
```
这行代码做了更多的事情：
1. 它声明了一个名为 root 的指针，用于指向 struct TreeNode 类型的对象。
2. 它使用 malloc 函数分配了足够存储一个 struct TreeNode 对象的内存。sizeof(struct TreeNode) 计算所需的内存大小。
3. malloc 返回的内存地址被赋给了 root 指针。

这样，root 就指向了一个有效的内存地址，您可以安全地对该内存进行读写操作（假设 malloc 成功，没有返回 NULL）。