/*
 * @FilePath     : \Practice_LeetCode_C\01_Common_Functions\inc\commonBinaryTree.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 19:27:05
 * @LastEditors: Chong Liu liuc12@miamioh.edu
 * @LastEditTime: 2024-01-05 18:55:33
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用二叉树头文件
 */
#ifndef __COMMON_BINARY_TREE_H  /* NOLINT(build/header_guard) */
#define __COMMON_BINARY_TREE_H  /* NOLINT(build/header_guard) */

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

/* 树列表队列 */
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

/* 树链表队列 */
typedef struct {
    struct TreeListNode *head;      /* 链表头指针 */
    int size;                       /* 链表大小 */
} TreeListQueue;

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/* ============================================================================== */
/* 前序遍历 */
/* ============================================================================== */
int *preOrderTraversal_recursion(struct TreeNode *root, int *returnSize);   /* 递归实现 */
int *preOrderTraversal_iteration(struct TreeNode *root, int *returnSize);   /* 迭代实现 */

/* ============================================================================== */
/* 中序遍历 */
/* ============================================================================== */
int *inOrderTraversal_recursion(struct TreeNode *root, int *returnSize);    /* 递归实现 */
int *inOrderTraversal_iteration(struct TreeNode *root, int *returnSize);    /* 迭代实现 */

/* ============================================================================== */
/* 后序遍历 */
/* ============================================================================== */
int *postOrderTraversal_recursion(struct TreeNode *root, int *returnSize);  /* 递归实现 */
int *postOrderTraversal_iteration(struct TreeNode *root, int *returnSize);  /* 迭代实现 */

/* ============================================================================== */
/* 层序遍历 */
/* ============================================================================== */
int **levelOrder_array(struct TreeNode *root, int *returnSize, int **returnColumnSizes);
int **levelOrder_struct(struct TreeNode *root, int *returnSize, int **returnColumnSizes);
int **levelOrderBottom(struct TreeNode *root, int *returnSize, int **returnColumnSizes);

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/* ============================================================================== */
/* 树列表队列操作 */
/* ============================================================================== */
TreeArrQueue *BTree_InitArrQueue(int queueSize);                       /* 创建队列 */
void BTree_EnArrQueue(TreeArrQueue *queue, struct TreeNode *node);    /* 将节点加入队列 */
struct TreeNode *BTree_DeArrQueue(TreeArrQueue *queue);               /* 从队列中取出一个节点 */
int BTree_ArrQueueIsEmpty(TreeArrQueue *queue);                       /* 判断队列是否为空 */
int BTree_ArrQueueIsFull(TreeArrQueue *queue);                        /* 判断队列是否为满 */
void printTreeArrQueue(TreeArrQueue *queue);                        /* 打印队列 */
void freeTreeArrQueue(TreeArrQueue *queue);                         /* 释放队列 */

/* ============================================================================== */
/* 树链表队列操作 */
/* ============================================================================== */
TreeListQueue *BTree_InitListQueue(void);                              /* 创建队列 */
void enTreeListQueue(TreeListQueue *queue, struct TreeNode *node);  /* 将节点加入队列 */
struct TreeNode *deTreeListQueue(TreeListQueue *queue);             /* 从队列中取出一个节点 */
int isTreeListQueueEmpty(TreeListQueue *queue);                     /* 判断队列是否为空 */
int isTreeListQueueFull(TreeListQueue *queue);                      /* 判断队列是否为满 */
void printTreeListQueue(TreeListQueue *queue);                      /* 打印队列 */
void freeTreeListQueue(TreeListQueue *queue);                       /* 释放队列 */

/* ============================================================================== */
/* 树操作 */
/* ============================================================================== */
struct TreeNode *BTree_InitNode(int value);                            /* 创建新节点 */
struct TreeNode *BTree_Init(int *arr, int arrSize);                /* 将数组转换为树 */
int *BTree_ToArray(struct TreeNode *root, int *returnSize);           /* 将树转换为数组 */
void BTree_PrintTest(void);                                           /* 打印测试树 */
void BTree_Print(struct TreeNode *root);                              /* 打印树 */
void BTree_Free(struct TreeNode *root);                               /* 释放树的内存 */


#endif  /* __COMMON_BINARY_TREE_H */    /* NOLINT(build/header_guard) */
