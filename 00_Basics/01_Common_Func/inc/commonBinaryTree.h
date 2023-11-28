/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\inc\commonBinaryTree.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 19:27:05
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-26 22:47:06
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用二叉树头文件
 */
#ifndef __COMMON_BINARY_TREE_H
#define __COMMON_BINARY_TREE_H

/**********************************************************************************/
/*                                                                                */
/*                                MACRO CONSTANTS                                 */
/*                                                                                */
/**********************************************************************************/
#define MAX_QUEUE_SIZE 1000      /* 队列的最大容量 */

/**********************************************************************************/
/*                                                                                */
/*                                 GLOBAL VARIABLES                               */
/*                                                                                */
/**********************************************************************************/
/* 树节点 */
struct TreeNode {
    int val;                        /* 节点的值 */
    struct TreeNode *left;          /* 左节点 */
    struct TreeNode *right;         /* 右节点 */
};

/* 树队列 */
typedef struct {
    struct TreeNode **array;        /* 树节点数组 */
    int head;                       /* 队首指针 */
    int tail;                       /* 队尾指针 */
    int size;                       /* 队列大小 */
} TreeArrQueue;

/* 树链表 */
struct TreeListNode {
    struct TreeNode *node;          /* 树节点指针 */
    struct TreeListNode *next;      /* 指向下一元素的指针 */
};

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/* ============================================================================== */
/* 前序遍历 */
/* ============================================================================== */
void preOrder(struct TreeNode *node, int *ret, int *returnSize);
int *preorderTraversal_recursion(struct TreeNode *root, int *returnSize);
int *preorderTraversal_iteration(struct TreeNode *root, int *returnSize);
/* ============================================================================== */
/* 中序遍历 */
/* ============================================================================== */
void inOrder(struct TreeNode *node, int *ret, int *returnSize);
int *inorderTraversal_recursion(struct TreeNode *root, int *returnSize);
int *inorderTraversal_iteration(struct TreeNode *root, int *returnSize);
/* ============================================================================== */
/* 后序遍历 */
/* ============================================================================== */
void postOrder(struct TreeNode *node, int *ret, int *returnSize);
int *postorderTraversal_recursion(struct TreeNode *root, int *returnSize);
int *postorderTraversal_iteration(struct TreeNode *root, int *returnSize);

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/* ============================================================================== */
/* 树队列操作 */
/* ============================================================================== */
TreeArrQueue *newTreeArrQueue(int queueSize);                         /* 创建队列 */
void enTreeArrQueue(TreeArrQueue *queue, struct TreeNode *node);      /* 将节点加入队列 */
struct TreeNode *deTreeArrQueue(TreeArrQueue *queue);                 /* 从队列中取出一个节点 */
int isTreeArrQueueEmpty(TreeArrQueue *queue);                         /* 判断队列是否为空 */
int isTreeArrQueueFull(TreeArrQueue *queue);                          /* 判断队列是否为满 */
void printTreeArrQueue(TreeArrQueue *queue);                          /* 打印队列 */
void freeTreeArrQueue(TreeArrQueue *queue);                           /* 释放队列 */
/* ============================================================================== */
/* 树链表操作 */
/* ============================================================================== */
/* TODO */
/* ============================================================================== */
/* 树操作 */
/* ============================================================================== */
struct TreeNode *newTreeNode(int value);                        /* 创建新节点 */
struct TreeNode *arrayToTree(int *arr, int arrSize);            /* 将数组转换为树 */
int *treeToArray(struct TreeNode *root, int *returnSize);       /* 将树转换为数组 */
void printTestTree(void);                                       /* 打印测试树 */
void printTree(struct TreeNode *root);                          /* 打印树 */
void freeTree(struct TreeNode *root);                           /* 释放树的内存 */


#endif  /* __COMMON_BINARY_TREE_H */