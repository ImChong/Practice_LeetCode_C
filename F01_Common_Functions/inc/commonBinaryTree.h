/*
 * @FilePath     : \Practice_LeetCode_C\F01_Common_Functions\inc\commonBinaryTree.h
 * @Author       : Chong Liu
 * @CreateDate   : 2024-01-08 09:53:52
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-15 11:01:01
 * =================================================================================
 * Copyright (c) 2024 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : Common binary tree header file
 */
#ifndef F01_COMMON_FUNCTIONS_INC_COMMONBINARYTREE_H_
#define F01_COMMON_FUNCTIONS_INC_COMMONBINARYTREE_H_

/**********************************************************************************/
/*                                                                                */
/*                               STRUCT DEFINITION                                */
/*                                                                                */
/**********************************************************************************/
/* Tree node structure */
struct TreeNode {
    int val;                /* Node value */
    struct TreeNode *left;  /* Left node */
    struct TreeNode *right; /* Right node */
};

/* Tree node operations */
struct TreeNode *BTree_InitNode(int value);                 /* Initialize a tree node */
struct TreeNode *BTree_ArrayInit(int *arr, int arrSize);    /* Initialize a tree from array */
int *BTree_ToArray(struct TreeNode *root, int *returnSize); /* Transform a tree to array */
void BTree_PrintTestTree(void);                             /* Print test tree */
void BTree_PrintValue(struct TreeNode *root);               /* Print tree value as an array */
void BTree_Free(struct TreeNode *root);                     /* Free tree */

/**********************************************************************************/
/*                                                                                */
/*                               STRUCT DEFINITION                                */
/*                                                                                */
/**********************************************************************************/
/* Tree Array Queue Structure */
typedef struct {
    struct TreeNode **array; /* 树节点数组 */
    int head;                /* 队首指针 */
    int tail;                /* 队尾指针 */
    int size;                /* 队列大小 */
} TreeArrQueue;

/* 列表树队列操作 */
TreeArrQueue *BTree_InitArrQueue(int queueSize);                   /* 创建队列 */
void BTree_EnArrQueue(TreeArrQueue *queue, struct TreeNode *node); /* 将节点加入队列 */
struct TreeNode *BTree_DeArrQueue(TreeArrQueue *queue);            /* 从队列中取出一个节点 */
int BTree_ArrQueueIsEmpty(TreeArrQueue *queue);                    /* 判断队列是否为空 */
int BTree_ArrQueueIsFull(TreeArrQueue *queue);                     /* 判断队列是否为满 */
void BTree_ArrQueuePrint(TreeArrQueue *queue);                     /* 打印队列 */
void BTree_ArrQueueFree(TreeArrQueue *queue);                      /* 释放队列 */

/**********************************************************************************/
/*                                                                                */
/*                               STRUCT DEFINITION                                */
/*                                                                                */
/**********************************************************************************/
/* 树链表节点 */
struct TreeListNode {
    struct TreeNode *node;     /* 树节点指针 */
    struct TreeListNode *next; /* 指向下一元素的指针 */
};

/* 树链表队列头 */
typedef struct {
    struct TreeListNode *head; /* 链表头指针 */
    int size;                  /* 链表大小 */
} TreeListQueue;

/* 链表树队列操作 */
TreeListQueue *BTree_InitListQueue(void);                            /* 创建队列 */
void BTree_EnListQueue(TreeListQueue *queue, struct TreeNode *node); /* 将节点加入队列 */
struct TreeNode *BTree_DeListQueue(TreeListQueue *queue);            /* 从队列中取出一个节点 */
int BTree_ListQueueIsEmpty(TreeListQueue *queue);                    /* 判断队列是否为空 */
int BTree_ListQueueIsFull(TreeListQueue *queue);                     /* 判断队列是否为满 */
void BTree_ListQueuePrint(TreeListQueue *queue);                     /* 打印队列 */
void BTree_ListQueueFree(TreeListQueue *queue);                      /* 释放队列 */

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
int *BTree_PreOrderTraversal(struct TreeNode *root, int *returnSize);                          /* 前序遍历 */
int *BTree_InOrderTraversal(struct TreeNode *root, int *returnSize);                           /* 中序遍历 */
int *BTree_PostOrderTraversal(struct TreeNode *root, int *returnSize);                         /* 后序遍历 */
int **BTree_LevelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes);       /* 层序遍历 */
int **BTree_LevelOrderBottom(struct TreeNode *root, int *returnSize, int **returnColumnSizes); /* 自底向上层序遍历 */

#endif /* F01_COMMON_FUNCTIONS_INC_COMMONBINARYTREE_H_ */
