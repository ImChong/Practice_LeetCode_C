/*
 * @FilePath     : \Practice_LeetCode_C\01_Programming_Topics\07_Binary_Tree\04_levelOrder\src\levelOrder_struct.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-11-26 18:26:03
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-06 00:00:03
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 层序遍历二叉树源文件 - 结构体实现
 *
 * 层序遍历 - 借助链表结构体队列数据结构，记录下 Tree 的下一层的所有结点。这样一层一层的遍历。直到结束
 *
 * 层序遍历 + 结构体链表队列
 * 关键点： 1：使用队列的数据结构存储对应的二叉树的结点Queue
 *          2：使用变量front和rear维护队列，队列是具有先进先出的特点
 *          3：使用Queue[front++] = root;来入队
 *          4: 使用nodeIt = Queue[rear++];来出队
 *          5：出队后，用 nodeIt 对应的子节点来操作，是否需要入队。
 *
 * 广度优先搜索
 * 关键点： 1：采用队列结构存储每一层的结点
 *          2：因为队列的结构特性，操作是先进先出
 *             时间复杂度：O(n) 空间复杂度: O(n)
 */
/* 解题方法配置文件 */
#include "methodCfg.h"
#if STRUCT_METHOD_EN
/* 标准头文件 */
#include <stdio.h>
/* 通用头文件 */
#include "commonBinaryTree.h"
/* 本文件头文件 */
#include "levelOrder.h"

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 广度优先搜索算法 Breadth-First Search
 * =================================================================================
 * @param {int} *returnSize             二叉树的层数
 * @param {int} **returnColumnSizes     二叉树对应层级的节点数
 * @param {int} **resultArray           结果二维数组
 * @param {struct Queue} *queueHead     链表队列的虚拟头节点
 * @return {void}
 */
void breadthFirstSearch(int *returnSize, int **returnColumnSizes, int **resultArray, struct Queue *queueHead) {
    struct Queue *queueIt = queueHead->next;                /* 初始化当前队列节点的指针为队首指针 */
    if (queueIt->node == NULL) {                            /* 如果队首节点的树节点指针为 NULL */
        return;                                                 /* 返回 */
    }

    int count = 0;                                                          /* 初始化计数器 count 为 0 */
    resultArray[*returnSize] = (int *)malloc(sizeof(int) * MAX_SIZE);       /* 结果二维数组的行号对应二叉树的层数：为二维数组的第 returnSize 行分配空间 - 2000个int类型数据 */

    while (1) {                                             /* 持续循环 */
        struct TreeNode *node = deQueue(queueHead);             /* 将队首树节点出队 */
        if (node == NULL) {                                     /* 如果队首树节点为 NULL */
            break;                                                  /* 停止循环 */
        }
        resultArray[*returnSize][count] = node->val;            /* 结果二维数组的 returnSize 行 count 列赋值为队首树节点的值 */
        count++;                                                /* 计数器count + 1 */
        if (node->left != NULL) {                               /* 如果队首树节点的左节点不为 NULL */
            enQueue(queueHead, node->left);                         /* 将队首树节点的左节点入队 */
        }
        if (node->right != NULL) {                              /* 如果队首树节点的右节点不为 NULL */
            enQueue(queueHead, node->right);                        /* 将队首树节点的右节点入队 */
        }
    }

    enQueue(queueHead, NULL);                               /* 将 NULL 入队 */
    (*returnColumnSizes)[*returnSize] = count;              /* *returnColumnSizes 数组的 *returnSize 位有 count 个节点 */
    *returnSize = *returnSize + 1;                          /* 二叉树的层数 + 1 */
    breadthFirstSearch(returnSize, returnColumnSizes, resultArray, queueHead);      /* 进行下一层的遍历 */
}

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 二叉树的层序遍历
 * =================================================================================
 * @param {struct TreeNode} *root       二叉树的根节点
 * @param {int} *returnSize             二叉树的层数
 * @param {int} **returnColumnSizes     二叉树对应层级的节点数
 * @return {int} **resultArray          结果二维数组
 */
int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;                                                                /* 初始化二叉树的层数为 0 */
    if (root == NULL) {                                                             /* 如果根节点为 NULL */
        return NULL;                                                                    /* 返回 NULL */
    }

    int **resultArray = (int **)malloc(sizeof(int *) * MAX_SIZE);                   /* 为二维数组分配空间 - 2000个int*类型数据 */
    *returnColumnSizes = (int *)malloc(sizeof(int) * MAX_SIZE);                     /* 用来记录二叉树每层的节点数（二维数组每行的列数）- 2000个int类型数据 */

    struct Queue *queueHead = (struct Queue *)malloc(sizeof(struct Queue));         /* 为链表队列的虚拟头节点分配空间 */
    queueHead->next = NULL;                                                         /* 虚拟头节点的下一队列节点为 NULL */
    queueHead->node = NULL;                                                         /* 虚拟头节点保存的树节点为 NULL */

    enQueue(queueHead, root);                                                       /* 将树的根节点入队 */
    enQueue(queueHead, NULL);                                                       /* 将 NULL 入队，表示当前树的层级结束 */
    breadthFirstSearch(returnSize, returnColumnSizes, resultArray, queueHead);      /* 开始广度优先搜索算法 */
    freeQueue(queueHead);                                                           /* 释放队列空间 */
    return resultArray;                                                             /* 返回结果二维数组 */
}


#endif  /* STRUCT_METHOD_EN */