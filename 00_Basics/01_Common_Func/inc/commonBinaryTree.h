/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\inc\commonBinaryTree.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 19:27:05
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-24 22:54:41
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用二叉树头文件
 */
#ifndef __COMMON_BINARY_TREE_H
#define __COMMON_BINARY_TREE_H

/**********************************************************************************/
/*                                                                                */
/*                                 GLOBAL VARIABLES                               */
/*                                                                                */
/**********************************************************************************/
/* 树节点 */
struct TreeNode {
    int val;                    /* 节点的值 */
    struct TreeNode *left;      /* 左节点 */
    struct TreeNode *right;     /* 右节点 */
};

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
void preOrder(struct TreeNode *node, int *ret, int *returnSize);                /* 前序遍历 */
int *preorderTraversal_recursion(struct TreeNode *root, int *returnSize);
int *preorderTraversal_iteration(struct TreeNode *root, int *returnSize);
/* ============================================================================== */
/* ============================================================================== */
void inOrder(struct TreeNode *node, int *ret, int *returnSize);                 /* 中序遍历 */
int *inorderTraversal_recursion(struct TreeNode *root, int *returnSize);
int *inorderTraversal_iteration(struct TreeNode *root, int *returnSize);
/* ============================================================================== */
/* ============================================================================== */
void postOrder(struct TreeNode *node, int *ret, int *returnSize);               /* 后序遍历 */
int *postorderTraversal_recursion(struct TreeNode *root, int *returnSize);
int *postorderTraversal_iteration(struct TreeNode *root, int *returnSize);

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
struct TreeNode *newNode(int value);
struct TreeNode *arrayToTree(int* arr, int arrSize)
void freeTree(struct TreeNode *root);
void printTree(struct TreeNode *root);


#endif  /* __COMMON_BINARY_TREE_H */