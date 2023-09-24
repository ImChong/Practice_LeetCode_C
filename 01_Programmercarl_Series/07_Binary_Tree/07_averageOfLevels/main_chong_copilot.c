/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\07_Binary_Tree\07_averageOfLevels\main_chong_copilot.c
 * @Author       : Chong Liu - Copilot
 * @CreateDate   : 2023-09-24 09:23:09
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-09-24 16:29:45
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 这份代码完全由copilot生成。
 */
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************************/
/*                                                                                */
/*                                MACRO CONSTANTS                                 */
/*                                                                                */
/**********************************************************************************/
#define MAX_SIZE 1001   /* 定义数组的最大大小 */

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
/*                                 TARGET FUNCTION                                */
/*                                                                                */
/**********************************************************************************/
/* 深度优先搜索算法 */
int countsSize;     /* 记录每层节点数的数组的大小 */
int sumsSize;       /* 记录每层节点值之和的数组的大小 */
void depthFirstSearch(struct TreeNode *root, int level, int *counts, double *sums) {
    if (root == NULL) {                                         /* 如果当前节点为空，直接返回 */
        return;
    }
    if (level < sumsSize) {                                     /* 如果当前层数小于记录节点值之和的数组的大小 */
        sums[level] += root->val;                                   /* 将当前节点的值加到对应层的节点值之和上 */
        counts[level] += 1;                                         /* 对应层的节点数加1 */
    } else {                                                    /* 如果当前层数大于等于记录节点值之和的数组的大小 */
        sums[sumsSize++] = (double)root->val;                       /* 在记录节点值之和的数组中新增一个元素，将当前节点的值赋值给它 */
        counts[countsSize++] = 1;                                   /* 在记录节点数的数组中新增一个元素，将1赋值给它 */
    }
    depthFirstSearch(root->left, level + 1, counts, sums);      /* 递归遍历左子树 */
    depthFirstSearch(root->right, level + 1, counts, sums);     /* 递归遍历右子树 */
}

/* 二叉树的层平均值 */
double *averageOfLevels(struct TreeNode *root, int *returnSize) {
    countsSize = sumsSize = 0;                                  /* 初始化记录节点数和节点值之和的数组的大小 */
    int *counts = malloc(sizeof(int) * MAX_SIZE);                   /* 动态分配一个大小为1001的int类型数组，用于记录每层节点数 */
    double *sums = malloc(sizeof(double) * MAX_SIZE);               /* 动态分配一个大小为1001的double类型数组，用于记录每层节点值之和 */
    depthFirstSearch(root, 0, counts, sums);                    /* 调用深度优先搜索算法，遍历二叉树，更新counts和sums数组 */
    double *averages = malloc(sizeof(double) * MAX_SIZE);           /* 动态分配一个大小为1001的double类型数组，用于记录每层节点值的平均值 */
    *returnSize = sumsSize;                                     /* 将返回的数组的大小设置为记录节点值之和的数组的大小 */
    for (int i = 0; i < sumsSize; i++) {                        /* 遍历每层节点值之和的数组 */
        averages[i] = sums[i] / counts[i];                          /* 计算每层节点值的平均值，存入averages数组中 */
    }
    free(counts);                                               /* 释放动态分配的内存 */
    free(sums);
    return averages;                                            /* 返回每层节点值的平均值组成的数组 */
}

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/* 创建树节点 */
struct TreeNode *createNode(int val) {
    struct TreeNode *node = malloc(sizeof(struct TreeNode));    /* 动态分配一个大小为struct TreeNode的内存空间 */
    node->val = val;                                            /* 将节点的值设置为val */
    node->left = NULL;                                          /* 将左节点设置为NULL */
    node->right = NULL;                                         /* 将右节点设置为NULL */
    return node;                                                /* 返回创建的节点 */
}

/* 创建二叉树 */
struct TreeNode *createTree() {
    struct TreeNode *root = createNode(3);                      /* 创建根节点 */
    root->left = createNode(9);                                 /* 创建左节点 */
    root->right = createNode(20);                               /* 创建右节点 */
    root->right->left = createNode(15);                         /* 创建右子树的左节点 */
    root->right->right = createNode(7);                         /* 创建右子树的右节点 */
    return root;                                                /* 返回创建的二叉树的根节点 */
}

/* 打印数组 */
void printArray(double *arr, int size) {
    printf("[");                                                /* 打印左括号 */
    for (int i = 0; i < size; i++) {                            /* 遍历数组 */
        printf("%.2f", arr[i]);                                     /* 打印数组元素 */
        if (i != size - 1) {                                        /* 如果不是最后一个元素 */
            printf(", ");                                               /* 打印逗号和空格 */
        }
    }
    printf("]\n");                                              /* 打印右括号和换行符 */
}

/**********************************************************************************/
/*                                                                                */
/*                                  MAIN FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/* 测试 */
int main() {
    struct TreeNode *root = createTree();                       /* 创建二叉树 */
    int returnSize;                                             /* 定义返回的数组的大小 */
    double *averages = averageOfLevels(root, &returnSize);      /* 计算每层节点值的平均值 */
    printArray(averages, returnSize);                           /* 打印每层节点值的平均值 */
    free(averages);                                             /* 释放动态分配的内存 */
    return 0;                                                   /* 返回0表示程序正常结束 */
}