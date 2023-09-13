/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\07_Binary_Tree\05_levelOrderBottom\main_chong.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-28 09:44:35
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-09-13 17:53:45
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 107. 二叉树的层序遍历 II：从下往上层序遍历二叉树
 * 107. 二叉树的层序遍历 II: https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/
 * https://programmercarl.com/0102.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86.html#_102-%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86
 *
 */
#include <stdio.h>
#include <stdlib.h>

/* NOTE: 树节点 */
struct TreeNode {
    int val;                    /* 节点的值 */
    struct TreeNode *left;      /* 左节点 */
    struct TreeNode *right;     /* 右节点 */
};

/* ==================================================================================================== */
/* ==================================================================================================== */
/* 107. 二叉树的层序遍历 II：从下往上层序遍历二叉树 */
/* ==================================================================================================== */
/* ==================================================================================================== */

/**
 * TODO: 目标函数
 * @description: 二叉树的层序遍历
 * =================================================================================
 * @param {struct TreeNode} *root       二叉树的根节点
 * @param {int} *returnSize             二叉树的层数
 * @param {int} **returnColumnSizes     二叉树对应层级的节点数
 * @return {int} **resultArray          结果二维数组
 */
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    /* TODO */






    return NULL;
}

/* ==================================================================================================== */
/* ==================================================================================================== */
/* ==================================================================================================== */
/* ==================================================================================================== */

/**
 * @description: 创建树节点
 * =================================================================================
 * @param {int} value                   树节点的数值
 * @return {struct TreeNode} *node      新树节点的指针
 */
struct TreeNode *newNode(int value) {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));     /* 初始化树节点：为树节点分配空间 */
    node->val = value;                                                              /* 树节点的值为 value */
    node->left = NULL;                                                              /* 树节点的左子节点为 NULL */
    node->right = NULL;                                                             /* 树节点的右子节点为 NULL */
    return node;                                                                    /* 返回树节点 */
}

/**
 * @description: 打印二维数组
 * =================================================================================
 * @param {int} **array                 二维数组
 * @param {int} size                    二维数组的行数
 * @param {int} *columnSizes            二维数组行数对应的列数
 * @return {void}
 */
void print2DArray(int **array, int size, int *columnSizes) {
    printf("[\n");                                          /* 打印总边框 [ */
    for (int i = 0; i < size; ++i) {                        /* 遍历二维数组的行 */
        printf("  [");                                          /* 打印行边框 [ */
        for (int j = 0; j < columnSizes[i]; ++j) {                  /* 遍历 i 行内的元素 */
            printf("%d", array[i][j]);                                  /* 打印 i 行内的元素 */
            if (j < columnSizes[i] - 1) {                               /* 打印分隔符：, */
                printf(", ");
            }
        }
        printf("]\n");                                          /* 打印行边框 ] */
    }
    printf("]\n");                                          /* 打印总边框 ] */
}

/**
 * @description: 主函数
 * =================================================================================
 * @param {int} argc        程序入参个数
 * @param {char} *argv[]    程序入参字符串数组
 * @return {int}            程序运行状态
 */
int main(int argc, const char *argv[]) {
    /*
     * 创建以下树结构
     *      1
     *     / \
     *    2   3
     *   / \ / \
     *  4  5 6  7
     */
    struct TreeNode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    root->left->left = newNode(4);
    root->left->right = newNode(5);

    root->right->left = newNode(6);
    root->right->right = newNode(7);

    int returnSize = 0;
    int *returnColumnSizes;

    /* NOTE: 函数调用 */
    int** result = levelOrderBottom(root, &returnSize, &returnColumnSizes);
    print2DArray(result, returnSize, returnColumnSizes);

    return 0;
}