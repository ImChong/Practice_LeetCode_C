/*
 * @FilePath     : \Practice_LeetCode_C\01_Programming_Topics\07_Binary_Tree\05_levelOrderBottom\src\levelOrderBottom.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-12-18 22:23:11
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-20 00:22:08
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 从下往上层序遍历二叉树源文件
 */
/* standard header file (标准头文件) */
#include <stdio.h>
#include <stdlib.h>
/* common function header file (通用头文件) */
#include "commonBinaryTree.h"

/**********************************************************************************/
/*                                                                                */
/*                                MACRO CONSTANTS                                 */
/*                                                                                */
/**********************************************************************************/
#define MAX_SIZE 2000           /* 初始化大小 */

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/* 107. 二叉树的层序遍历 II：从下往上层序遍历二叉树 */

/* 层序遍历 + 队列(迭代法)*/
/* 关键点：  1：采用队列结构存储每一层的结点
            2：因为队列的结构特性，操作是先进先出
            3：将全部的的每一层节点存储于Queue队列当中
            4：遍历结点的左右子结点，放在就继续放入Queue队列
            5：为了清晰的表示出每一层之间的间隔，这里在队列中插入null结点，表示换层了
            时间复杂度：O(n) 空间复杂度: O(n) */

/* 层序遍历 + 队列(迭代法) 优化 */
/* 关键点：  1：去掉用来表示换行的null指针
            2：通过交换打印输出的方式，完成结果的输出
            时间复杂度：O(n) 空间复杂度: O(n) */
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
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;                                                                    /* 初始化二叉树的层数为 0 */
    int **resultArray = (int **)malloc(sizeof(int *) * MAX_SIZE);                       /* 为结果二维数组分配空间 - 2000个 int* 类型数据 */
    *returnColumnSizes = (int *)malloc(sizeof(int) * MAX_SIZE);                         /* 用来记录二叉树每层的节点数（二维数组每行的列数）- 2000个 int 类型数据 */
    if (root == NULL) {                                                                 /* 如果根节点为 NULL */
        return resultArray;                                                                 /* 返回结果二维数组 */
    }

    struct TreeNode **treeNodeQueue = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * MAX_SIZE);     /* 初始化树节点的队列 treeNodeQueue - 2000个 struct TreeNode * 类型数据  */
    int queueFront = 0;                                                                 /* 队首索引 */
    int queueRear = 0;                                                                  /* 队尾索引 */
    treeNodeQueue[queueRear++] = root;                                                  /* 将树的根节点放入队尾，并且队尾索引 + 1 */
    while (queueFront < queueRear) {                                                    /* 当队首索引小于队尾索引时 - 保持循环 */
        int nodeNums = queueRear - queueFront;                                              /* 当前层的节点数 = 队尾索引 - 队首索引 */
        int *nodeValues = (int *)malloc(sizeof(int) * nodeNums);                            /* 为当前层节点的所有数值分配空间 */
        (*returnColumnSizes)[*returnSize] = nodeNums;                                       /* 记录当前层的节点数（当前行的列数） */
        for (int i = 0; i < nodeNums; i++) {                                                /* 遍历当前层的节点 */
            struct TreeNode *node = treeNodeQueue[queueFront++];                                /* 取出队首树节点 - 获取指针并将队首索引 + 1 */
            nodeValues[i] = node->val;                                                          /* 记录本层第 i 个节点数值 */
            if (node->left != NULL) {                                                           /* 如果当前节点的左节点不为 NULL */
                treeNodeQueue[queueRear++] = node->left;                                            /* 将左节点加入队尾 */
            }
            if (node->right != NULL) {                                                          /* 如果当前节点的右节点不为 NULL */
                treeNodeQueue[queueRear++] = node->right;                                           /* 将右节点加入队尾 */
            }
        }
        resultArray[(*returnSize)++] = nodeValues;                                          /* 将记录下来的当前层所有数值放入二维数组的当前层（二维数组的对应行），并将层数 + 1 */
    }

    for (int i = 0; 2 * i < *returnSize; i++) {                                         /* 循环层数的一半 */
        int *tmp1 = resultArray[i];                                                         /* 用临时指针保存第 i 层的数据 */
        resultArray[i] = resultArray[(*returnSize) - i - 1];                                /* 将第【i】层的数据替换为第【总层数 - i - 1】层的数据 */
        resultArray[(*returnSize) - i - 1] = tmp1;                                          /* 将第【总层数 - i - 1】层的数据替换为临时指针的数据，实现二维数组逆转 */
        int tmp2 = (*returnColumnSizes)[i];                                                 /* 用临时指针保存第 i 层的节点数 */
        (*returnColumnSizes)[i] = (*returnColumnSizes)[(*returnSize) - i - 1];              /* 将第【i】层的节点数替换为第【总层数 - i - 1】层的节点数 */
        (*returnColumnSizes)[(*returnSize) - i - 1] = tmp2;                                 /* 将第【总层数 - i - 1】层的节点数替换为临时指针的节点数，实现二维数组逆转 */
    }

    return resultArray;                                                                 /* 返回结果二维数组 */
}