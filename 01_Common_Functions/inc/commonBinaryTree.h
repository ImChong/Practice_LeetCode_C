/*
 * @FilePath     : \Practice_LeetCode_C\01_Common_Functions\inc\commonBinaryTree.h
 * @Author       : Chong Liu
 * @CreateDate   : 2024-01-08 09:53:52
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-08 10:02:57
 * =================================================================================
 * Copyright (c) 2024 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  :
 */
#ifndef __COMMON_BINARY_TREE_H  /* NOLINT(build/header_guard) */
#define __COMMON_BINARY_TREE_H  /* NOLINT(build/header_guard) */

/**********************************************************************************/
/*                                                                                */
/*                               STRUCT DEFINITION                                */
/*                                                                                */
/**********************************************************************************/
/* 树节点 */
struct TreeNode {
    int val;                        /* 节点的值 */
    struct TreeNode *left;          /* 左节点 */
    struct TreeNode *right;         /* 右节点 */
};

/* 树操作 */
struct TreeNode *BTree_InitNode(int value);                             /* 创建新节点 */
struct TreeNode *BTree_Init(int *arr, int arrSize);                     /* 将数组转换为树 */
int *BTree_ToArray(struct TreeNode *root, int *returnSize);             /* 将树转换为数组 */
void BTree_PrintTestTree(void);                                         /* 打印测试树 */
void BTree_PrintValue(struct TreeNode *root);                           /* 打印树 */
void BTree_Free(struct TreeNode *root);                                 /* 释放树的内存 */

/**********************************************************************************/
/*                                                                                */
/*                               STRUCT DEFINITION                                */
/*                                                                                */
/**********************************************************************************/
/* 列表树队列 */
typedef struct {
    struct TreeNode **array;        /* 树节点数组 */
    int head;                       /* 队首指针 */
    int tail;                       /* 队尾指针 */
    int size;                       /* 队列大小 */
} TreeArrQueue;

/* 列表树队列操作 */
TreeArrQueue *BTree_InitArrQueue(int queueSize);                        /* 创建队列 */
void BTree_EnArrQueue(TreeArrQueue *queue, struct TreeNode *node);      /* 将节点加入队列 */
struct TreeNode *BTree_DeArrQueue(TreeArrQueue *queue);                 /* 从队列中取出一个节点 */
int BTree_ArrQueueIsEmpty(TreeArrQueue *queue);                         /* 判断队列是否为空 */
int BTree_ArrQueueIsFull(TreeArrQueue *queue);                          /* 判断队列是否为满 */
void BTree_ArrQueuePrint(TreeArrQueue *queue);                          /* 打印队列 */
void BTree_ArrQueueFree(TreeArrQueue *queue);                           /* 释放队列 */

/**********************************************************************************/
/*                                                                                */
/*                               STRUCT DEFINITION                                */
/*                                                                                */
/**********************************************************************************/
/* 树链表节点 */
struct TreeListNode {
    struct TreeNode *node;          /* 树节点指针 */
    struct TreeListNode *next;      /* 指向下一元素的指针 */
};

/* 树链表队列头 */
typedef struct {
    struct TreeListNode *head;      /* 链表头指针 */
    int size;                       /* 链表大小 */
} TreeListQueue;

/* 链表树队列操作 */
TreeListQueue *BTree_InitListQueue(void);                               /* 创建队列 */
void BTree_EnListQueue(TreeListQueue *queue, struct TreeNode *node);    /* 将节点加入队列 */
struct TreeNode *BTree_DeListQueue(TreeListQueue *queue);               /* 从队列中取出一个节点 */
int BTree_ListQueueIsEmpty(TreeListQueue *queue);                       /* 判断队列是否为空 */
int BTree_ListQueueIsFull(TreeListQueue *queue);                        /* 判断队列是否为满 */
void BTree_ListQueuePrint(TreeListQueue *queue);                        /* 打印队列 */
void BTree_ListQueueFree(TreeListQueue *queue);                         /* 释放队列 */

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
int *BTree_PreOrderTraversal(struct TreeNode *root, int *returnSize);   /* 前序遍历 */
int *BTree_InOrderTraversal(struct TreeNode *root, int *returnSize);    /* 中序遍历 */
int *BTree_PostOrderTraversal(struct TreeNode *root, int *returnSize);  /* 后序遍历 */
int **BTree_LevelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes);        /* 层序遍历 */
int **BTree_LevelOrderBottom(struct TreeNode *root, int *returnSize, int **returnColumnSizes);  /* 自底向上层序遍历 */

#endif  /* __COMMON_BINARY_TREE_H */    /* NOLINT(build/header_guard) */
