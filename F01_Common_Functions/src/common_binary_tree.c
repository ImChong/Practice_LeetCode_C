/*
 * @FilePath     : \Practice_LeetCode_C\F01_Common_Functions\src\common_binary_tree.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-01 20:07:37
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-26 10:30:35
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用二叉树源文件
 *
 * 二叉树主要有两种遍历方式：
 *   深度优先遍历：先往深走，遇到叶子节点再往回走。
 *       前序遍历（递归法，迭代法）
 *       中序遍历（递归法，迭代法）
 *       后序遍历（递归法，迭代法）
 *   广度优先遍历：一层一层的去遍历。
 *       层次遍历（迭代法）
 *
 * 数组形式表示：
 * [1, 2, 3, 4, 5, 6, 7]    用数组来存储二叉树: 如果父节点的数组下标是 i，那么它的左孩子就是 i * 2 + 1，右孩子就是 i * 2 + 2。
 * 树结构表示：
 *       1
 *      / \
 *     2   3
 *    / \ / \
 *   4  5 6  7
 *
 * 前序遍历：
 * [1, 2, 4, 5, 3, 6, 7]
 *
 * 中序遍历：
 * [4, 2, 5, 1, 6, 3, 7]
 *
 * 后序遍历：
 * [4, 5, 2, 6, 7, 3, 1]
 */
/* Common function configuration file (通用函数配置文件) */
#include "compile_cfg.h"    /* NOLINT */
#if COMMON_BINARY_TREE_EN /* whether compile this file, the definition of this macro can be found in compileCfg.h */
/* Header file (本文件头文件) */
#include "F01_Common_Functions/inc/common_binary_tree.h"
/* Standard header file (标准头文件) */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/* Common function header file (通用头文件) */
#include "F01_Common_Functions/inc/common_def/common_type_def.h"

/**********************************************************************************/
/*                                                                                */
/*                                MACRO CONSTANTS                                 */
/*                                                                                */
/**********************************************************************************/
#define MAX_SIZE 1000               /* 数组和栈的大小 */
#define MAX_QUEUE_SIZE 1000         /* 队列的最大容量 */

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/*
 * 树结构表示：
 *       1
 *      / \
 *     2   3
 *    / \ / \
 *   4  5 6  7
 *
 * 前序遍历：
 * [1, 2, 4, 5, 3, 6, 7]
 */
/* ============================================================================== */
/* ============================================================================== */
#if BTREE_ORDER_TRAVERSAL_RECURSION_METHOD_EN
/**
 * @description: 前序遍历
 * =================================================================================
 * @param {TreeNode} *node      当前节点指针
 * @param {int} *ans            用于储存遍历答案的数组
 * @param {int} *returnSize     用于储存遍历答案的数组的大小
 * @return {void}
 */
STATIC_FUNC void PreOrder(struct TreeNode *node, int *ans, int *returnSize) {
    if (node == NULL) {     /* 如果当前节点为 NULL，直接返回 */
        return;
    }
    ans[(*returnSize)++] = node->val;       /* 把当前节点的值放入ret数组的*returnSize索引，并将*returnSize索引值+1 */
    PreOrder(node->left, ans, returnSize);      /* 前序遍历左节点 */
    PreOrder(node->right, ans, returnSize);     /* 前序遍历右节点 */
}

/**
 * @description: 前序遍历 - 递归方法
 * =================================================================================
 * @param {TreeNode} *root      根节点指针
 * @param {int} *returnSize     用于储存遍历答案的数组的大小
 * @return {int} *ans           用于储存遍历答案的数组
 */
int *BTree_PreOrderTraversal(struct TreeNode *root, int *returnSize) {
    int *ans = (int *)malloc(sizeof(int) * MAX_SIZE);   /* NOLINT */
    *returnSize = 0;                                    /* 初始化数组的大小为 0 */
    PreOrder(root, ans, returnSize);                    /* 前序遍历根节点 */
    return ans;                                         /* 返回结果 ans 数组 */
}
#endif /* BTREE_ORDER_TRAVERSAL_RECURSION_METHOD_EN */

#if BTREE_ORDER_TRAVERSAL_ITERATION_METHOD_EN
/**
 * @description: 前序遍历 - 迭代方法
 * =================================================================================
 * @param {TreeNode} *root      根节点指针
 * @param {int} *returnSize     用于储存遍历答案的数组的大小
 * @return {int} *ans           用于储存遍历答案的数组
 */
int *BTree_PreOrderTraversal(struct TreeNode *root, int *returnSize) {
    int *ans = (int *)malloc(sizeof(int) * MAX_SIZE);   /* NOLINT */
    *returnSize = 0;                                    /* 初始化数组的大小为 0 */
    if (root == NULL) {                                 /* 如果当前节点为 NULL，直接返回 */
        return ans;
    }

    struct TreeNode *stk[MAX_SIZE];                     /* 用数组实现初始化一个MAX_SIZE容量的树节点栈 */
    int stk_top = 0;                                    /* 栈顶索引为 0 */
    struct TreeNode *node = root;                       /* 获取根节点的指针 */
    while (stk_top > 0 || node != NULL) {               /* 当栈顶索引大于0 或者 节点指针不指向NULL */
        while (node != NULL) {                              /* 当结点指针不指向NULL */
            ans[(*returnSize)++] = node->val;                   /* 把当前节点的值放入ret数组的 *returnSize 索引 */
            stk[stk_top++] = node;                              /* 入栈：将当前节点指针放入栈顶，并将栈顶索引 + 1 */
            node = node->left;                                  /* 节点指针向左移动 */
        }
        node = stk[--stk_top];                              /* 出栈：获取栈顶节点指针，并将栈顶索引 - 1 */
        node = node->right;                                 /* 节点指针向右移动 */
    }
    return ans;                                         /* 返回结果数组 */
}
#endif /* BTREE_ORDER_TRAVERSAL_ITERATION_METHOD_EN */

/**********************************************************************************/
/*                                                                                */
/*                                 UTILITY FUNCTIONS                              */
/*                                                                                */
/**********************************************************************************/
/*
 * 树结构表示：
 *       1
 *      / \
 *     2   3
 *    / \ / \
 *   4  5 6  7
 *
 * 中序遍历：
 * [4, 2, 5, 1, 6, 3, 7]
 */
/* ============================================================================== */
/* ============================================================================== */
#if BTREE_ORDER_TRAVERSAL_RECURSION_METHOD_EN
/**
 * @description: 中序遍历
 * =================================================================================
 * @param {TreeNode} *node      当前节点指针
 * @param {int} *ans            用于储存遍历答案的数组
 * @param {int} *returnSize     用于储存遍历答案的数组的大小
 * @return {void}
 */
STATIC_FUNC void inOrder(struct TreeNode *node, int *ans, int *returnSize) {
    if (node == NULL) {                                 /* 如果当前节点为 NULL，直接返回 */
        return;
    }
    inOrder(node->left, ans, returnSize);
    ans[(*returnSize)++] = node->val;
    inOrder(node->right, ans, returnSize);
}

/**
 * @description: 中序遍历 - 递归方法
 * =================================================================================
 * @param {TreeNode} *root      根节点指针
 * @param {int} *returnSize     用于储存遍历答案的数组的大小
 * @return {int} *ans           用于储存遍历答案的数组
 */
int *BTree_InOrderTraversal(struct TreeNode *root, int *returnSize) {
    int *ans = (int *)malloc(sizeof(int) * MAX_SIZE);   /* NOLINT */
    *returnSize = 0;                                    /* 初始化数组的大小为 0 */
    inOrder(root, ans, returnSize);                     /* 中序遍历根节点 */
    return ans;                                         /* 返回结果 ans 数组 */
}
#endif /* BTREE_ORDER_TRAVERSAL_RECURSION_METHOD_EN */

#if BTREE_ORDER_TRAVERSAL_ITERATION_METHOD_EN
/**
 * @description: 中序遍历 - 迭代方法
 * =================================================================================
 * @param {TreeNode} *root      根节点指针
 * @param {int} *returnSize     用于储存遍历答案的数组的大小
 * @return {int} *ans           用于储存遍历答案的数组
 */
int *BTree_InOrderTraversal(struct TreeNode *root, int *returnSize) {
    int *ans = (int *)malloc(sizeof(int) * MAX_SIZE);   /* NOLINT */
    *returnSize = 0;                                    /* 初始化数组的大小为 0 */
    if (root == NULL) {                                 /* 如果当前节点为 NULL，直接返回 */
        return ans;
    }

    struct TreeNode **stk =
        (struct TreeNode **)malloc(sizeof(struct TreeNode *) * MAX_SIZE);   /* NOLINT */
    int stk_top = 0;                                    /* 栈顶索引为 0 */
    struct TreeNode *node = root;                       /* 获取根节点的指针 */
    while (node != NULL || stk_top > 0) {               /* 当栈顶索引大于0 或者 节点指针不指向NULL */
        while (node != NULL) {                              /* 当结点指针不指向NULL */
            stk[stk_top++] = node;                              /* 入栈：将当前节点指针放入栈顶，并将栈顶索引 + 1 */
            node = node->left;                                  /* 节点指针向左移动 */
        }
        node = stk[--stk_top];                              /* 出栈：获取栈顶节点指针，并将栈顶索引 - 1 */
        ans[(*returnSize)++] = node->val;
        node = node->right;                                 /* 节点指针向右移动 */
    }
    return ans;                                         /* 返回结果数组 */
}
#endif /* BTREE_ORDER_TRAVERSAL_ITERATION_METHOD_EN */

/**********************************************************************************/
/*                                                                                */
/*                                 UTILITY FUNCTIONS                              */
/*                                                                                */
/**********************************************************************************/
/*
 * 树结构表示：
 *       1
 *      / \
 *     2   3
 *    / \ / \
 *   4  5 6  7
 *
 * 后序遍历：
 * [4, 5, 2, 6, 7, 3, 1]
 */
/* ============================================================================== */
/* ============================================================================== */
#if BTREE_ORDER_TRAVERSAL_RECURSION_METHOD_EN
/**
 * @description: 后序遍历
 * =================================================================================
 * @param {TreeNode} *node      当前节点指针
 * @param {int} *ans            用于储存遍历答案的数组
 * @param {int} *returnSize     用于储存遍历答案的数组的大小
 * @return {void}
 */
STATIC_FUNC void postOrder(struct TreeNode *node, int *ans, int *returnSize) {
    if (node == NULL) {                                     /* 如果当前节点为 NULL，直接返回 */
        return;
    }
    postOrder(node->left, ans, returnSize);                 /* 后序遍历左节点 */
    postOrder(node->right, ans, returnSize);                /* 后序遍历右节点 */
    ans[(*returnSize)++] = node->val;
}

/**
 * @description: 后序遍历 - 递归方法
 * =================================================================================
 * @param {TreeNode} *root      根节点指针
 * @param {int} *returnSize     用于储存遍历答案的数组的大小
 * @return {int} *ans           用于储存遍历答案的数组
 */
int *BTree_PostOrderTraversal(struct TreeNode *root, int *returnSize) {
    int *ans = (int *)malloc(sizeof(int) * MAX_SIZE);       /* NOLINT */
    *returnSize = 0;                                        /* 初始化数组的大小为 0 */
    postOrder(root, ans, returnSize);                       /* 后序遍历根节点 */
    return ans;                                             /* 返回结果 ans 数组 */
}
#endif /* BTREE_ORDER_TRAVERSAL_RECURSION_METHOD_EN */

#if BTREE_ORDER_TRAVERSAL_ITERATION_METHOD_EN
/**
 * @description: 后序遍历 - 迭代方法
 * =================================================================================
 * @param {TreeNode} *root      根节点指针
 * @param {int} *returnSize     用于储存遍历答案的数组的大小
 * @return {int} *ans           用于储存遍历答案的数组
 */
int *BTree_PostOrderTraversal(struct TreeNode *root, int *returnSize) {
    int *ans = (int *)malloc(sizeof(int) * MAX_SIZE);       /* NOLINT */
    *returnSize = 0;                                        /* 初始化数组的大小为 0 */
    if (root == NULL) {                                     /* 如果当前节点为 NULL，直接返回 */
        return ans;
    }

    struct TreeNode *stk[MAX_SIZE];                         /* 用数组实现初始化一个MAX_SIZE容量的树节点栈 */
    int stk_top = 0;                                        /* 栈顶索引为 0 */
    struct TreeNode *node = root;                           /* 获取根节点的指针 */
    struct TreeNode *prev = NULL;                           /* 设置前节点的指针为 NULL */
    while (node != NULL || stk_top > 0) {                   /* 当栈顶索引大于0 或者 节点指针不指向NULL */
        while (node != NULL) {                                  /* 当结点指针不指向NULL */
            stk[stk_top++] = node;                                  /* 入栈：将当前节点指针放入栈顶，并将栈顶索引 + 1 */
            node = node->left;                                      /* 节点指针向左移动 */
        }
        node = stk[--stk_top];                                  /* 出栈：获取栈顶节点指针，并将栈顶索引 - 1 */
        if (node->right == NULL || node->right == prev) {       /* 如果右节点为NULL 或者 右节点为前节点 */
            ans[(*returnSize)++] = node->val;                       /* 把当前节点的值放入ret数组的 *returnSize 索引 */
            prev = node;                                            /* 给前节点指针赋值为当前节点 */
            node = NULL;                                            /* 把当前节点指针赋值为 NULL*/
        } else {                                                /* 否则 */
            stk[stk_top++] = node;                                  /* 入栈：将当前节点指针放入栈顶，并将栈顶索引 + 1 */
            node = node->right;                                     /* 节点指针向右移动 */
        }
    }
    return ans;                                             /* 返回结果数组 */
}
#endif /* BTREE_ORDER_TRAVERSAL_ITERATION_METHOD_EN */

/**********************************************************************************/
/*                                                                                */
/*                                 UTILITY FUNCTIONS                              */
/*                                                                                */
/**********************************************************************************/
/*
 * 树结构表示：
 *       1
 *      / \
 *     2   3
 *    / \ / \
 *   4  5 6  7
 *
 * 层序遍历：
 * [
 *   [1]
 *   [2, 3]
 *   [4, 5, 6, 7]
 * ]
 */
/* ============================================================================== */
/* ============================================================================== */
#if BTREE_LEVEL_ORDER_ARRAY_METHOD_EN
/**
 * @description: 层序遍历 - 数组方法
 * =================================================================================
 * @param {TreeNode} *root                  根节点指针
 * @param {int} *returnSize                 用于储存遍历答案的数组的大小
 * @param {int} **returnColumnSizes         用于储存遍历答案的数组的每一行的大小
 * @return {int} **ans                      用于储存遍历答案的数组
 */
int **BTree_LevelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;        /* 初始化二叉树的层数为 0 */
    if (root == NULL) {     /* 如果根节点为 NULL */
        return NULL;        /* 返回 NULL */
    }

    int **resultArray = (int **)malloc(sizeof(int *) * MAX_SIZE);   /* NOLINT */
    *returnColumnSizes = (int *)malloc(sizeof(int) * MAX_SIZE);     /* NOLINT */

    struct TreeNode *treeNodeQueue[MAX_SIZE];   /* 数组作为树节点的队列 treeNodeQueue  */
    int queueFront = 0;     /* 队首索引 */
    int queueRear = 0;      /* 队尾索引 */
    struct TreeNode *curNode;       /* 当前树节点的指针 */

    treeNodeQueue[queueRear++] = root;      /* 将树的根节点入队 */
    while (queueFront != queueRear) {       /* 当队首索引不等于队尾索引时 - 保持循环 */
        int nodeNums = 0;       /* 二叉树当前层的节点数（结果二维数组当前行的列数） */
        int layerEndIndex = queueRear;      /* 记录当前层队尾索引 */
        resultArray[*returnSize] =
            (int *)malloc(sizeof(int) * (layerEndIndex - queueFront));      /* NOLINT */
        while (queueFront < layerEndIndex) {        /* 当队首索引小于队尾索引时 - 保持循环 */
            curNode = treeNodeQueue[queueFront++];      /* 取出当前队首树节点，并将队首索引 + 1 */
            resultArray[*returnSize][nodeNums++] = curNode->val;
            if (curNode->left != NULL) {        /* 如果当前队首树节点的左节点不为 NULL */
                treeNodeQueue[queueRear++] = curNode->left;     /* 将当前队首树节点的左节点放入队尾 */
            }
            if (curNode->right != NULL) {       /* 如果当前队首树节点的右节点不为 NULL */
                treeNodeQueue[queueRear++] = curNode->right;        /* 将当前队首树节点的右节点放入队尾 */
            }
        }
        (*returnColumnSizes)[*returnSize] = nodeNums;       /* 将当前层的节点数计入 *returnColumnSizes */
        (*returnSize)++;        /* 二叉树层数（二维数组行数） + 1 */
    }
    return resultArray;     /* 返回结果二维数组 */
}
#endif /* BTREE_LEVEL_ORDER_ARRAY_METHOD_EN */

#if BTREE_LEVEL_ORDER_STRUCT_METHOD_EN
/**
 * @description: Breadth First Search - 广度优先搜索
 * =================================================================================
 * @param {int} *returnSize                 二叉树的层数
 * @param {int} **returnColumnSizes         二叉树对应层级的节点数
 * @param {int} **resultArray               结果二维数组
 * @param {TreeLkListQueue} *queueHead        链表队列头指针
 * @return {int}
 */
STATIC_FUNC void BreadthFirstSearch(int *returnSize, int **returnColumnSizes, int **resultArray,
                                        TreeLkListQueue *queueHead) {
    struct TreeLkListNode *currentNode = queueHead->head;
    if (currentNode->node == NULL) {
        return;
    }

    int count = 0;
    resultArray[*returnSize] = (int *)malloc(sizeof(int) * MAX_QUEUE_SIZE);     /* NOLINT */

    while (1) {
        struct TreeNode *node = BTree_DeListQueue(queueHead);
        if (node == NULL) {
            break;
        }
        resultArray[*returnSize][count] = node->val;
        count++;
        if (node->left != NULL) {
            BTree_EnListQueue(queueHead, node->left);
        }
        if (node->right != NULL) {
            BTree_EnListQueue(queueHead, node->right);
        }
    }

    BTree_EnListQueue(queueHead, NULL);
    (*returnColumnSizes)[*returnSize] = count;
    *returnSize = *returnSize + 1;
    BreadthFirstSearch(returnSize, returnColumnSizes, resultArray, queueHead);
}

/**
 * @description: 层序遍历 - 结构体树链表队列方法
 * =================================================================================
 * @param {TreeNode} *root                  根节点指针
 * @param {int} *returnSize                 用于储存遍历答案的数组的大小
 * @param {int} **returnColumnSizes         用于储存遍历答案的数组的每一行的大小
 * @return {int} **ans                      用于储存遍历答案的数组
 */
int **BTree_LevelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }

    int **ans = (int **)malloc(sizeof(int *) * MAX_QUEUE_SIZE);     /* NOLINT */
    *returnColumnSizes = (int *)malloc(sizeof(int) * MAX_QUEUE_SIZE);       /* NOLINT */

    TreeLkListQueue *queueHead = (TreeLkListQueue *)malloc(sizeof(TreeLkListQueue));    /* NOLINT */
    queueHead->head = NULL;

    BTree_EnListQueue(queueHead, root);
    BTree_EnListQueue(queueHead, NULL);
    BreadthFirstSearch(returnSize, returnColumnSizes, ans, queueHead);
    BTree_ListQueueFree(queueHead);
    return ans;
}
#endif /* BTREE_LEVEL_ORDER_STRUCT_METHOD_EN */

/**********************************************************************************/
/*                                                                                */
/*                                 UTILITY FUNCTIONS                              */
/*                                                                                */
/**********************************************************************************/
/*
 * 树结构表示：
 *       1
 *      / \
 *     2   3
 *    / \ / \
 *   4  5 6  7
 *
 * 层序遍历：
 * [
 *   [4, 5, 6, 7]
 *   [2, 3]
 *   [1]
 * ]
 */
/* ============================================================================== */
/* ============================================================================== */
/**
 * @description: 二叉树的层序遍历
 * =================================================================================
 * @param {struct TreeNode} *root       二叉树的根节点
 * @param {int} *returnSize             二叉树的层数
 * @param {int} **returnColumnSizes     二叉树对应层级的节点数
 * @return {int} **resultArray          结果二维数组
 */
int **BTree_LevelOrderBottom(struct TreeNode *root, int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;
    int **resultArray = (int **)malloc(sizeof(int *) * MAX_SIZE);       /* NOLINT */
    *returnColumnSizes = (int *)malloc(sizeof(int) * MAX_SIZE);         /* NOLINT */
    if (root == NULL) {
        return resultArray;
    }

    struct TreeNode **treeNodeQueue =
        (struct TreeNode **)malloc(sizeof(struct TreeNode *) * MAX_SIZE);   /* NOLINT */
    int queueFront = 0;
    int queueRear = 0;
    treeNodeQueue[queueRear++] = root;
    while (queueFront < queueRear) {
        int nodeNums = queueRear - queueFront;
        int *nodeValues = (int *)malloc(sizeof(int) * nodeNums);    /* NOLINT */
        (*returnColumnSizes)[*returnSize] = nodeNums;
        for (int i = 0; i < nodeNums; i++) {
            struct TreeNode *node = treeNodeQueue[queueFront++];
            nodeValues[i] = node->val;
            if (node->left != NULL) {
                treeNodeQueue[queueRear++] = node->left;
            }
            if (node->right != NULL) {
                treeNodeQueue[queueRear++] = node->right;
            }
        }
        resultArray[(*returnSize)++] = nodeValues;
    }

    for (int i = 0; 2 * i < *returnSize; i++) {
        int *tmp1 = resultArray[i];
        resultArray[i] = resultArray[(*returnSize) - i - 1];
        resultArray[(*returnSize) - i - 1] = tmp1;
        int tmp2 = (*returnColumnSizes)[i];
        (*returnColumnSizes)[i] = (*returnColumnSizes)[(*returnSize) - i - 1];
        (*returnColumnSizes)[(*returnSize) - i - 1] = tmp2;
    }

    return resultArray;
}

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/* 树列表队列操作 */
/* ============================================================================== */
/**
 * @description: 创建一个新的二叉树节点队列
 * =================================================================================
 * @param {int} queueSize       队列的大小
 * @return {TreeArrQueue} *queue   新的二叉树节点队列指针
 */
TreeArrQueue *BTree_InitArrQueue(int queueSize) {
    TreeArrQueue *queue = (TreeArrQueue *)malloc(sizeof(TreeArrQueue));         /* NOLINT */
    queue->array = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * queueSize); /* NOLINT */
    queue->head = 0;
    queue->tail = 0;
    queue->size = queueSize;
    return queue;
}

/**
 * @description: 将节点加入队列
 * =================================================================================
 * @param {TreeArrQueue} *queue    二叉树节点队列指针
 * @param {TreeNode} *node      节点指针
 * @return {void}
 */
void BTree_EnArrQueue(TreeArrQueue *queue, struct TreeNode *node) {
    if ((queue->tail + 1) % queue->size == queue->head) {
        printf("Queue is full.\n");
        return;
    }
    queue->array[queue->tail] = node;
    queue->tail = (queue->tail + 1) % queue->size;
}

/**
 * @description: 从队列中取出一个节点
 * =================================================================================
 * @param {TreeArrQueue} *queue        二叉树节点队列指针
 * @return {TreeNode} *node         节点指针
 */
struct TreeNode *BTree_DeArrQueue(TreeArrQueue *queue) {
    if (queue->head == queue->tail) {
        printf("Queue is empty.\n");
        return NULL;
    }
    struct TreeNode *node = queue->array[queue->head];
    queue->head = (queue->head + 1) % queue->size;
    return node;
}

/**
 * @description: 判断队列是否为空
 * =================================================================================
 * @param {TreeArrQueue} *queue        二叉树节点队列指针
 * @return {int}                    如果队列为空，返回1；否则返回0
 */
int BTree_ArrQueueIsEmpty(TreeArrQueue *queue) {
    return queue->head == queue->tail;
}

/**
 * @description: 判断队列是否为满
 * =================================================================================
 * @param {TreeArrQueue} *queue        二叉树节点队列指针
 * @return {int}                    如果队列为满，返回1；否则返回0
 */
int BTree_ArrQueueIsFull(TreeArrQueue *queue) {
    return (queue->tail + 1) % queue->size == queue->head;
}

/**
 * @description: 打印二叉树节点队列
 * =================================================================================
 * @param {TreeArrQueue} *queue        二叉树节点队列指针
 * @return {void}
 */
void BTree_ArrQueuePrint(TreeArrQueue *queue) {
    printf("TreeArrQueue (size = %d): [", queue->size);
    for (int i = queue->head; i != queue->tail; i = (i + 1) % queue->size) {
        printf("%d", queue->array[i]->val);
        if ((i + 1) % queue->size != queue->tail) {
            printf(", ");
        }
    }
    printf("]\n");
}

/**
 * @description: 释放二叉树节点队列的空间
 * =================================================================================
 * @param {TreeArrQueue} *queue    二叉树节点队列指针
 * @return {void}
 */
void BTree_ArrQueueFree(TreeArrQueue *queue) {
    free(queue->array);
    free(queue);
}

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/* 树链表队列操作 */
/* ============================================================================== */
/**
 * @description: 创建一个新的二叉树节点链表队列
 * =================================================================================
 * @return {TreeLkListQueue} *queue   新的二叉树节点链表队列指针
 */
TreeLkListQueue *BTree_InitListQueue(void) {
    TreeLkListQueue *queue = (TreeLkListQueue *)malloc(sizeof(TreeLkListQueue));     /* NOLINT */
    queue->head = NULL;
    queue->size = 0;
    return queue;
}

/**
 * @description: 将节点加入队列
 * =================================================================================
 * @param {TreeLkListQueue} *queue    二叉树节点链表队列指针
 * @param {TreeNode} *node          节点指针
 * @return {void}
 */
void BTree_EnListQueue(TreeLkListQueue *queue, struct TreeNode *node) {
    if (queue->head == NULL) {
        queue->head = (struct TreeLkListNode *)malloc(sizeof(struct TreeLkListNode));
        queue->head->node = node;
        queue->head->next = NULL;
        queue->size++;
    } else {
        struct TreeLkListNode *current = queue->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = (struct TreeLkListNode *)malloc(sizeof(struct TreeLkListNode));
        current->next->node = node;
        current->next->next = NULL;
        queue->size++;
    }
    return;
}

/**
 * @description: 从队列中取出一个节点
 * =================================================================================
 * @param {TreeLkListQueue} *queue    二叉树节点链表队列指针
 * @return {TreeNode} *node         节点指针
 */
struct TreeNode *BTree_DeListQueue(TreeLkListQueue *queue) {
    if (queue->head == NULL) {
        printf("Queue is empty.\n");
        return NULL;
    }
    struct TreeNode *node = queue->head->node;
    struct TreeLkListNode *temp = queue->head;
    queue->head = queue->head->next;
    free(temp);
    queue->size--;
    return node;
}

/**
 * @description: 判断队列是否为空
 * =================================================================================
 * @param {TreeLkListQueue} *queue    二叉树节点链表队列指针
 * @return {int}                    如果队列为空，返回1；否则返回0
 */
int BTree_ListQueueIsEmpty(TreeLkListQueue *queue) {
    return queue->head == NULL;
}

/**
 * @description: 判断队列是否为满
 * =================================================================================
 * @param {TreeLkListQueue} *queue    二叉树节点链表队列指针
 * @return {int}                    如果队列为满，返回1；否则返回0
 */
int BTree_ListQueueIsFull(TreeLkListQueue *queue) {
    /* TODO */
    (void)queue;
    return 0;
}

/**
 * @description: 打印二叉树节点链表队列
 * =================================================================================
 * @param {TreeLkListQueue} *queue    二叉树节点链表队列指针
 * @return {void}
 */
void BTree_ListQueuePrint(TreeLkListQueue *queue) {
    printf("TreeLkListQueue (size = %d): [", queue->size);
    struct TreeLkListNode *current = queue->head;
    while (current != NULL) {
        printf("%d", current->node->val);
        if (current->next != NULL) {
            printf(", ");
        }
        current = current->next;
    }
    printf("]\n");
}

/**
 * @description: 释放二叉树节点链表队列的空间
 * =================================================================================
 * @param {TreeLkListQueue} *queue    二叉树节点链表队列指针
 * @return {void}
 */
void BTree_ListQueueFree(TreeLkListQueue *queue) {
    struct TreeLkListNode *current = queue->head;
    while (current != NULL) {
        struct TreeLkListNode *temp = current;
        current = current->next;
        free(temp);
    }
    free(queue);
}

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/* 树操作 */
/* ============================================================================== */
/**
 * @description: 创建一个新的树节点
 * =================================================================================
 * @param {int} value           节点的值
 * @return {TreeNode} *node     新的树节点指针
 */
struct TreeNode *BTree_InitNode(int value) {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
 * @description: 将数组转换为二叉树
 * =================================================================================
 * @param {int*} arr                数组指针
 * @param {int} arr_size             数组大小
 * @return {TreeNode} *node         根节点指针
 */
struct TreeNode *BTree_ArrayInit(int* arr, int arr_size) {
    if (arr_size == 0) {
        return NULL;
    }

    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = arr[0];
    root->left = NULL;
    root->right = NULL;

    TreeArrQueue *queue = BTree_InitArrQueue(arr_size);
    queue->array[queue->tail++] = root;

    for (int i = 1; i < arr_size; i++) {
        struct TreeNode *node = queue->array[queue->head++];
        if (i < arr_size) {
            node->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            node->left->val = arr[i];
            node->left->left = NULL;
            node->left->right = NULL;
            queue->array[queue->tail++] = node->left;
        }
        if (++i < arr_size) {
            node->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            node->right->val = arr[i];
            node->right->left = NULL;
            node->right->right = NULL;
            queue->array[queue->tail++] = node->right;
        }
    }
    BTree_ArrQueueFree(queue);
    return root;
}

/**
 * @description: 将二叉树转换为数组
 * =================================================================================
 * @param {TreeNode} *root      根节点指针
 * @param {int} *returnSize     数组长度指针
 * @return {int} *result        转换后的数组指针
 */
int *BTree_ToArray(struct TreeNode *root, int *returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int *result = (int *)malloc(MAX_SIZE * sizeof(int));    /* NOLINT */
    TreeArrQueue *q = BTree_InitArrQueue(MAX_SIZE);
    BTree_EnArrQueue(q, root);
    int index = 0;

    while (!BTree_ArrQueueIsEmpty(q)) {
        struct TreeNode *current = BTree_DeArrQueue(q);
        if (current) {
            result[index] = current->val;
            BTree_EnArrQueue(q, current->left);
            BTree_EnArrQueue(q, current->right);
        } else {
            result[index] = INT_MIN;
        }
        index++;
    }

    *returnSize = index;
    BTree_ArrQueueFree(q);
    return result;
}

/**
 * @description: 打印示意树结构
 * =================================================================================
 * @return {void}
 */
void BTree_PrintTestTree(void) {
    printf("Test Tree:\n");
    printf("      1 \n");
    printf("     / \\ \n");
    printf("    2   3 \n");
    printf("   / \\ / \\ \n");
    printf("  4  5 6  7 \n");
    printf("\n");
}

/**
 * @description: 打印二叉树
 * =================================================================================
 * @param {TreeNode} *root      根节点指针
 * @return {void}
 */
void BTree_PrintValue(struct TreeNode *root) {
    if (root == NULL) {             /* 如果传入节点为 NULL 则返回 */
        return;
    }
    printf("%d ", root->val);       /* 打印当前节点的值 */
    BTree_PrintValue(root->left);          /* 遍历打印左节点 */
    BTree_PrintValue(root->right);         /* 遍历打印右节点 */
}

/**
 * @description: 释放二叉树的空间
 * =================================================================================
 * @param {TreeNode} *root      根节点指针
 * @return {void}
 */
void BTree_Free(struct TreeNode *root) {
    if (root == NULL) {             /* 如果传入节点为 NULL 则返回 */
        return;
    }
    BTree_Free(root->left);           /* 遍历释放左节点空间 */
    BTree_Free(root->right);          /* 遍历释放右节点空间 */
    free(root);                     /* 释放当前节点空间 */
}

#endif      /* COMMON_BINARY_TREE_EN */
