/*
 * @File: binaryTreeCommon.c
 * @Created Date: 2023-08-28 9:44:35 am
 * @Author: Chong Liu
 * @Brief: 二叉树的常用函数
 * =================================================================================
 * Copyright (c) 2023 Chong Liu
 * =================================================================================
 * Last Modified: Chong Liu - 2023-09-01 10:49:41 am
 */

/* 用数组来存储二叉树: 如果父节点的数组下标是 i，那么它的左孩子就是 i * 2 + 1，右孩子就是 i * 2 + 2。*/
/*
 * 二叉树主要有两种遍历方式：
 *      深度优先遍历：先往深走，遇到叶子节点再往回走。
 *          前序遍历（递归法，迭代法）
 *          中序遍历（递归法，迭代法）
 *          后序遍历（递归法，迭代法）
 *      广度优先遍历：一层一层的去遍历。
 *          层次遍历（迭代法）
 */
#include <stdio.h>

/* NOTE: 树节点 */
struct TreeNode {
    int val;                    /* 节点的值 */
    struct TreeNode *left;      /* 左节点 */
    struct TreeNode *right;     /* 右节点 */
};

/* preorderTraversal_recursion()
 *  Functionality: 前序遍历 - 递归
 *  Arguments: struct TreeNode *root, int *returnSize
 *  Return: int *ret
 *  References:
 ***********************************************************************************
 *  IMPORTANT NOTICE FOR READER
 */
 void preOrder(struct TreeNode *node, int *ret, int *returnSize) {
    if (node == NULL) {                             /* 如果当前节点为 NULL，直接返回 */
        return;
    }
    ret[(*returnSize)++] = node->val;               /* 把当前节点的值放入ret数组的 *returnSize 索引，并将 *returnSize 索引值 + 1 */
    preOrder(node->left, ret, returnSize);          /* 前序遍历左节点 */
    preOrder(node->right, ret, returnSize);         /* 前序遍历右节点 */
}

int *preorderTraversal_recursion(struct TreeNode *root, int *returnSize) {
    int *ret = (int *)malloc(sizeof(int) * 100);    /* 初始化一个100长度的 ret 数组，用于储存遍历答案 */
    *returnSize = 0;                                /* 初始化数的大小为 0 */
    preOrder(root, ret, returnSize);                /* 前序遍历根节点 */
    return ret;                                     /* 返回结果 ret 数组 */
}

/* postorderTraversal_recursion()
 *  Functionality: 前序遍历 - 递归
 *  Arguments: struct TreeNode *root, int *returnSize
 *  Return: int *ret
 *  References:
 ***********************************************************************************
 *  IMPORTANT NOTICE FOR READER
 */
int* preorderTraversal_iteration(struct TreeNode *root, int *returnSize) {
    int *res = (int *)malloc(sizeof(int) * 2000);   /* 初始化一个2000长度的 ret 数组，用于储存遍历答案 */
    *returnSize = 0;                                /* 初始化数的大小为 0 */
    if (root == NULL) {                             /* 如果当前节点为 NULL，直接返回 */
        return res;
    }

    struct TreeNode *stk[2000];                     /* 用数组实现初始化一个2000容量的树节点栈 */
    struct TreeNode *node = root;                   /* 获取根节点的指针 */
    int stk_top = 0;                                /* 栈顶索引为 0 */
    while (stk_top > 0 || node != NULL) {           /* 当栈顶索引大于0 或者 节点指针不指向NULL */
        while (node != NULL) {                          /* 当结点指针不指向NULL */
            res[(*returnSize)++] = node->val;               /* 把当前节点的值放入ret数组的 *returnSize 索引，并将 *returnSize 索引值 + 1 */
            stk[stk_top++] = node;                          /* 将当前节点指针放入栈顶，并将栈顶索引 + 1 */
            node = node->left;                              /* 节点指针向左移动 */
        }
        node = stk[--stk_top];                          /* 当节点指针指向NULL - 左节点指针已经到头：获取栈顶节点指针，并将栈顶索引 - 1 */
        node = node->right;                             /* 节点指针向右移动 */
    }
    return res;                                     /* 返回结果数组 */
}

/* inorderTraversal_recursion()
 *  Functionality: 中序遍历 - 递归
 *  Arguments: struct TreeNode *root, int *returnSize
 *  Return: int *ret
 *  References:
 ***********************************************************************************
 *  IMPORTANT NOTICE FOR READER
 */
void inOrder(struct TreeNode *node, int *ret, int *returnSize) {
    if (node == NULL) {                             /* 如果当前节点为 NULL，直接返回 */
        return;
    }
    inOrder(node->left, ret, returnSize);           /* 中序遍历左节点 */
    ret[(*returnSize)++] = node->val;               /* 把当前节点的值放入ret数组的 *returnSize 索引，并将 *returnSize 索引值 + 1 */
    inOrder(node->right, ret, returnSize);          /* 中序遍历右节点 */
}

int *inorderTraversal_recursion(struct TreeNode *root, int *returnSize) {
    int *ret = (int *)malloc(sizeof(int) * 100);    /* 初始化一个100长度的 ret 数组，用于储存遍历答案 */
    *returnSize = 0;                                /* 初始化数的大小为 0 */
    inOrder(root, ret, returnSize);                 /* 中序遍历根节点 */
    return ret;                                     /* 返回结果 ret 数组 */
}

/* TODO: 中序遍历: 迭代 */


/* postorderTraversal_recursion()
 *  Functionality: 后序遍历 - 递归
 *  Arguments: struct TreeNode *root, int *returnSize
 *  Return: int *ret
 *  References:
 ***********************************************************************************
 *  IMPORTANT NOTICE FOR READER
 */
void postOrder(struct TreeNode *node, int *ret, int *returnSize) {
    if (node == NULL) {                             /* 如果当前节点为 NULL，直接返回 */
        return;
    }
    postOrder(node->left, ret, returnSize);         /* 后序遍历左节点 */
    postOrder(node->right, ret, returnSize);        /* 后序遍历右节点 */
    ret[(*returnSize)++] = node->val;               /* 把当前节点的值放入ret数组的 *returnSize 索引，并将 *returnSize 索引值 + 1 */
}

int *postorderTraversal_recursion(struct TreeNode *root, int *returnSize) {
    int *ret = (int *)malloc(sizeof(int) * 100);    /* 初始化一个100长度的 ret 数组，用于储存遍历答案 */
    *returnSize = 0;                                /* 初始化数的大小为 0 */
    postOrder(root, ret, returnSize);               /* 后序遍历根节点 */
    return ret;                                     /* 返回结果 ret 数组 */
}

/* TODO: 后序遍历: 迭代 */


/* main()
 *  Functionality: 主函数
 *  Arguments: int argc, const char* argv[]
 *  Return: int
 *  References: document/website...
 ***********************************************************************************
 *  IMPORTANT NOTICE FOR READER
 */
/* NOTE: 主函数 */
int main(int argc, const char* argv[]) {

    return 0;
}