# 1. Binary_Tree：二叉树

在C语言中，二叉树（Binary Tree）是一种特殊的树形数据结构，在这种结构中，每个节点最多有两个子节点，通常被称为“左子节点”和“右子节点”。

- [1. Binary\_Tree：二叉树](#1-binary_tree二叉树)
  - [1.1. 定义](#11-定义)
  - [1.2. 创建和初始化](#12-创建和初始化)
  - [1.3. 遍历](#13-遍历)
  - [1.4. 应用](#14-应用)
  - [Question List](#question-list)

## 1.1. 定义

一个典型的二叉树节点在C语言中可以用结构体（struct）来定义：

```c
struct Node {
    int data;  // 节点存储的数据
    struct Node *left;  // 指向左子节点的指针
    struct Node *right;  // 指向右子节点的指针
};
```

## 1.2. 创建和初始化

以下是如何创建和初始化一个简单的二叉树的例子：

```c
#include <stdlib.h>

struct Node *newNode(int data) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    // 创建根节点
    struct Node *root = newNode(1);

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

## 1.3. 遍历

二叉树有多种遍历方法，包括：

1. **前序遍历（Preorder）**：先访问根节点，然后遍历左子树，最后遍历右子树。
2. **中序遍历（Inorder）**：先遍历左子树，然后访问根节点，最后遍历右子树。
3. **后序遍历（Postorder）**：先遍历左子树，然后遍历右子树，最后访问根节点。

例如，前序遍历的代码可能如下：

```c
void preorder(struct Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
```

## 1.4. 应用

二叉树在计算机科学和编程中有广泛的应用，包括但不限于：

1. **二叉搜索树（Binary Search Trees）**：用于高效地搜索、插入和删除数据。
2. **堆（Heaps）**：用于实现优先队列。
3. **平衡树（如AVL Trees, Red-Black Trees等）**：用于维护排序数据的高效访问和修改。
4. **用于解析表达式**：编译器可能使用二叉树来解析和求值数学或逻辑表达式。
5. **文件系统的目录结构**：可以看作是一种树形结构，虽然通常不是二叉树。

二叉树是数据结构和算法中非常重要的一个概念，掌握它有助于解决许多复杂的问题。

## 1.5. Question List

```txt
07_Binary_Tree/
├── 00_common
├── 01_preorderTraversal
├── 02_inorderTraversal
├── 03_postorderTraversal
├── 04_levelOrder
├── 05_levelOrderBottom
├── 06_rightSideView
├── 07_averageOfLevels
├── 08_nlevelOrder
├── 09_largestValues
├── 10_connect
├── 11_connectII
├── 12_maxDepth
├── 13_minDepth
├── 14_invertTree
├── 15_isSymmetric
├── 16_countNodes
├── 17_isBalanced
├── 18_binaryTreePaths
├── 19_sumOfLeftLeaves
├── 20_findBottomLeftValue
├── 21_hasPathSum
├── 22_pathSum
├── 23_buildTree
├── 24_constructMaximumBinaryTree
├── 25_mergeTrees
├── 26_searchBST
├── 27_isValidBST
├── 28_getMinimumDifference
├── 29_findMode
├── 30_lowestCommonAncestor
├── 31_insertIntoBST
├── 32_deleteNode
├── 33_trimBST
├── 34_sortedArrayToBST
├── 35_convertBST
└── README.md
```
