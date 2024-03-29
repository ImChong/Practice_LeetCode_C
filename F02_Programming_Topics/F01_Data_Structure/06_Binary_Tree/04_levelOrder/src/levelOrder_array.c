/*
 * @FilePath     : \Practice_LeetCode_C\01_Programming_Topics\07_Binary_Tree\04_levelOrder\src\BTree_LevelOrder_Array.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-11-26 18:25:56
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-06 00:04:51
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 层序遍历二叉树源文件 - 数组实现
 *
 * 层序遍历 - 借助数组队列数据结构，记录下 Tree 的下一层的所有结点。这样一层一层的遍历。直到结束
 * 关键点： 1：使用队列的数据结构存储对应的二叉树的结点Queue
 *          2：使用变量front和rear维护队列，队列是具有先进先出的特点
 *          3：使用Queue[front++] = root;来入队
 *          4: 使用nodeIt = Queue[rear++];来出队
 *          5：出队后，用 nodeIt 对应的子节点来操作，是否需要入队。
 */
/* solution method configuration file (解题方法配置文件) */
#include "methodCfg.h"
#if ARRAY_METHOD_EN
/* Standard header file (标准头文件) */
#include <stdio.h>
/* Common function header file (通用头文件) */
#include "commonBinaryTree.h"
/* solution header file (题解头文件) */
#include "levelOrder.h"

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
    *returnSize = 0;                                                                                /* 初始化二叉树的层数为 0 */
    if (root == NULL) {                                                                             /* 如果根节点为 NULL */
        return NULL;                                                                                    /* 返回 NULL */
    }

    int **resultArray = (int **)malloc(sizeof(int *) * MAX_SIZE);                                   /* 为结果二维数组分配空间 - 2000个 int* 类型数据 */
    *returnColumnSizes = (int *)malloc(sizeof(int) * MAX_SIZE);                                     /* 用来记录二叉树每层的节点数（二维数组每行的列数）- 2000个 int 类型数据 */

    struct TreeNode *treeNodeQueue[MAX_SIZE];                                                       /* 数组作为树节点的队列 treeNodeQueue - 2000个 struct TreeNode * 类型数据  */
    int queueFront = 0;                                                                             /* 队首索引 */
    int queueRear = 0;                                                                              /* 队尾索引 */
    struct TreeNode *curNode;                                                                       /* 当前树节点的指针 */

    treeNodeQueue[queueRear++] = root;                                                              /* 将树的根节点入队 */
    while (queueFront != queueRear) {                                                               /* 当队首索引不等于队尾索引时 - 保持循环 */
        int nodeNums = 0;                                                                               /* 二叉树当前层的节点数（结果二维数组当前行的列数） */
        int layerEndIndex = queueRear;                                                                  /* 记录当前层队尾索引 */
        resultArray[*returnSize] = (int *)malloc(sizeof(int) * (layerEndIndex - queueFront));           /* 为当前层的树节点记录数组分配空间 */
        while (queueFront < layerEndIndex) {                                                            /* 当队首索引小于队尾索引时 - 保持循环 */
            curNode = treeNodeQueue[queueFront++];                                                         /* 取出当前队首树节点，并将队首索引 + 1 */
            resultArray[*returnSize][nodeNums++] = curNode->val;                                           /* 将当前队首树节点的值放入结果二维数组当前层的 nodeNums 索引，并将 nodeNums + 1 */
            if (curNode->left != NULL) {                                                                   /* 如果当前队首树节点的左节点不为 NULL */
                treeNodeQueue[queueRear++] = curNode->left;                                                    /* 将当前队首树节点的左节点放入队尾 */
            }
            if (curNode->right != NULL) {                                                                  /* 如果当前队首树节点的右节点不为 NULL */
                treeNodeQueue[queueRear++] = curNode->right;                                                   /* 将当前队首树节点的右节点放入队尾 */
            }
        }
        (*returnColumnSizes)[*returnSize] = nodeNums;                                                  /* 将当前层的节点数计入 *returnColumnSizes 对应的二叉树层数（二维数组的行数） */
        (*returnSize)++;                                                                               /* 二叉树层数（二维数组行数） + 1 */
    }
    return resultArray;                                                                             /* 返回结果二维数组 */
}


#endif  /* ARRAY_METHOD_EN */