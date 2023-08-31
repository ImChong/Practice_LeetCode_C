/*
 * @File: binaryTreeCommon.c
 * @Created Date: 2023-08-28 9:44:35 am
 * @Author: Chong Liu
 * @Brief: 二叉树的常用函数
 * =================================================================================
 * Copyright (c) 2023 Chong Liu
 * =================================================================================
 * Last Modified: Chong Liu - 2023-08-31 8:32:10 pm
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

/* NOTE: 前序遍历: 递归 */
void preOrder(struct TreeNode *node, int *ret, int *returnSize) {
    if (node == NULL) {                             /* 如果当前节点为 NULL，直接返回 */
        return;
    }
    ret[(*returnSize)++] = node->val;               /* 把当前节点的值放入ret数组的 *returnSize 索引，并将 *returnSize 索引值 + 1 */
    preOrder(node->left, ret, returnSize);          /* 前序遍历左节点 */
    preOrder(node->right, ret, returnSize);         /* 前序遍历右节点 */
}

int *preorderTraversal(struct TreeNode *root, int *returnSize) {
    int *ret = (int *)malloc(sizeof(int) * 100);    /* 初始化一个100长度的 ret 数组，用于储存遍历答案 */
    *returnSize = 0;                                /* 初始化数的大小为 0 */
    preOrder(root, ret, returnSize);                /* 前序遍历根节点 */
    return ret;                                     /* 返回结果 ret 数组 */
}

/* NOTE: 中序遍历: 递归 */
void inOrder(struct TreeNode *node, int *ret, int *returnSize) {
    if (!node) {                                    /* 如果当前节点为 NULL，直接返回 */
        return;
    }
    inOrder(node->left, ret, returnSize);           /* 中序遍历左节点 */
    ret[(*returnSize)++] = node->val;               /* 把当前节点的值放入ret数组的 *returnSize 索引，并将 *returnSize 索引值 + 1 */
    inOrder(node->right, ret, returnSize);          /* 中序遍历右节点 */
}

int *inorderTraversal(struct TreeNode *root, int *returnSize) {
    int *ret = (int *)malloc(sizeof(int) * 100);    /* 初始化一个100长度的 ret 数组，用于储存遍历答案 */
    *returnSize = 0;                                /* 初始化数的大小为 0 */
    inOrder(root, ret, returnSize);                 /* 中序遍历根节点 */
    return ret;                                     /* 返回结果 ret 数组 */
}

/* NOTE: 后序遍历: 递归 */
void postOrder(struct TreeNode *node, int *ret, int *returnSize) {
    if (!node) {                                    /* 如果当前节点为 NULL，直接返回 */
        return;
    }
    postOrder(node->left, ret, returnSize);         /* 后序遍历左节点 */
    postOrder(node->right, ret, returnSize);        /* 后序遍历右节点 */
    ret[(*returnSize)++] = node->val;               /* 把当前节点的值放入ret数组的 *returnSize 索引，并将 *returnSize 索引值 + 1 */
}

int *postorderTraversal(struct TreeNode *root, int *returnSize) {
    int *ret = (int *)malloc(sizeof(int) * 100);    /* 初始化一个100长度的 ret 数组，用于储存遍历答案 */
    *returnSize = 0;                                /* 初始化数的大小为 0 */
    postOrder(root, ret, returnSize);               /* 后序遍历根节点 */
    return ret;                                     /* 返回结果 ret 数组 */
}

/* TODO: 前序遍历: 迭代 */

/* TODO: 前序遍历: 迭代 */

/* TODO: 前序遍历: 迭代 */

/* NOTE: 主函数 */
int main(int argc, const char* argv[]) {

    return 0;
}