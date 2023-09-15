/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\07_Binary_Tree\06_rightSideView\main_chong.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-28 09:44:35
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-09-15 08:55:37
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 199. 二叉树的右视图: https://leetcode.cn/problems/binary-tree-right-side-view/
 * https://programmercarl.com/0102.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86.html#_199-%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%8F%B3%E8%A7%86%E5%9B%BE
 * 解法参考：https://leetcode.cn/problems/binary-tree-right-side-view/solutions/214060/199-er-cha-shu-de-you-shi-tu-by-hamiguaex163com/
 * 解法参考：https://leetcode.cn/problems/binary-tree-right-side-view/solutions/1453989/by-goodgoodday-2kho/
 *
 *       1
 *      / \
 *     2   3
 *    / \ / \
 *   4  5 6  7
 *
 * 二叉树的右视图：
 * [1,3,7]
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
/* TODO: 目标函数 */
/* ==================================================================================================== */

/**
 * @description: 二叉树的前序遍历
 * =================================================================================
 * @param {struct TreeNode} *root   二叉树的根节点
 * @param {int} *returnArr          结果数组
 * @param {int} height              二叉树的高度
 * @param {int} *returnSize         结果数组的大小
 * @return {*}
 */
void preorder(struct TreeNode *root, int *returnArr, int height, int *returnSize) {
    if (root == NULL) {
        return;
    }
    
    if (height + 1 > *returnSize) {
        *returnSize = height + 1;
    }

    returnArr[height] = root->val;
    return;
}

/**
 * @description: 二叉树的右视图
 * =================================================================================
 * @param {TreeNode} *root
 * @param {int} *returnSize
 * @return {int} *resultArray
 */
int *rightSideView(struct TreeNode *root, int *returnSize){

    return NULL;
}
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
 * @description: 打印一维数组
 * =================================================================================
 * @param {int} *array      一维数组
 * @param {int} size        一维数组的大小
 * @return {void}
 */
void print1DArray(int *array, int size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        printf("%d", array[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
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


    return 0;
}