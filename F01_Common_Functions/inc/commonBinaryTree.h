/*
 * @FilePath     : \Practice_LeetCode_C\F01_Common_Functions\inc\commonBinaryTree.h
 * @Author       : Chong Liu
 * @CreateDate   : 2024-01-08 09:53:52
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-15 11:22:08
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
/* Tree array queue structure */
typedef struct {
    struct TreeNode **array; /* Tree node queue array */
    int head;                /* Queue head index */
    int tail;                /* Queue tail index */
    int size;                /* Queue size */
} TreeArrQueue;

/* Tree array queue operations */
TreeArrQueue *BTree_InitArrQueue(int queueSize);                   /* Initialize queue */
void BTree_EnArrQueue(TreeArrQueue *queue, struct TreeNode *node); /* Enqueue a tree node */
struct TreeNode *BTree_DeArrQueue(TreeArrQueue *queue);            /* Dequeue a tree node */
int BTree_ArrQueueIsEmpty(TreeArrQueue *queue);                    /* Check if the queue is empty */
int BTree_ArrQueueIsFull(TreeArrQueue *queue);                     /* Check if the queue is full */
void BTree_ArrQueuePrint(TreeArrQueue *queue);                     /* Print queue */
void BTree_ArrQueueFree(TreeArrQueue *queue);                      /* Free queue */

/**********************************************************************************/
/*                                                                                */
/*                               STRUCT DEFINITION                                */
/*                                                                                */
/**********************************************************************************/
/* Tree linked list queue node structure */
struct TreeLkListNode {
    struct TreeNode *node;     /* Tree node */
    struct TreeLkListNode *next; /* Pointer to next tree linked list queue node */
};

/* Tree linked list queue structure */
typedef struct {
    struct TreeLkListNode *head; /* Queue head */
    int size;                  /* Queue size */
} TreeLKListQueue;

/* Tree linked list queue operations */
TreeLKListQueue *BTree_InitListQueue(void);                            /* Initialize queue */
void BTree_EnListQueue(TreeLKListQueue *queue, struct TreeNode *node); /* Enqueue a tree linked list queue node */
struct TreeNode *BTree_DeListQueue(TreeLKListQueue *queue);            /* Dequeue a tree linked list queue node */
int BTree_ListQueueIsEmpty(TreeLKListQueue *queue);                    /* Check if the queue is empty */
int BTree_ListQueueIsFull(TreeLKListQueue *queue);                     /* Check if the queue is full */
void BTree_ListQueuePrint(TreeLKListQueue *queue);                     /* Print queue */
void BTree_ListQueueFree(TreeLKListQueue *queue);                      /* Free queue */

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
int *BTree_PreOrderTraversal(struct TreeNode *root, int *returnSize);
int *BTree_InOrderTraversal(struct TreeNode *root, int *returnSize);
int *BTree_PostOrderTraversal(struct TreeNode *root, int *returnSize);
/* Level order traversal from top to bottom */
int **BTree_LevelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes);
/* Level order traversal from bottom to top */
int **BTree_LevelOrderBottom(struct TreeNode *root, int *returnSize, int **returnColumnSizes);

#endif /* F01_COMMON_FUNCTIONS_INC_COMMONBINARYTREE_H_ */
