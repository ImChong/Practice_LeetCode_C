/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\07_Binary_Tree\04_levelOrder\main_chong.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-11 21:17:11
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-09-11 23:21:01
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 102. 二叉树的层序遍历: https://leetcode.cn/problems/binary-tree-level-order-traversal/
 * https://programmercarl.com/0102.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86.html
 */
#include <stdio.h>

/* NOTE: 树节点 */
struct TreeNode {
    int val;                    /* 节点的值 */
    struct TreeNode *left;      /* 左节点 */
    struct TreeNode *right;     /* 右节点 */
};

/* ==================================================================================================== */
/* TODO: 关键点 */
    /* 1：采用队列结构存储每一层的结点 */
    /* 2：因为队列的结构特性，操作是先进先出 */
    /* 时间复杂度：O(n) 空间复杂度: O(n) */
/* ==================================================================================================== */
struct Queue {
    struct TreeNode *node;
    struct Queue    *next;
};

/**
 * @description: 入队
 * =================================================================================
 * @param {struct Queue} *queueHead
 * @param {struct TreeNode} *node
 * @return {void}
 */
void enQueue(struct Queue *queueHead, struct TreeNode *node) {
    /* TODO */
}

/**
 * @description: 出队
 * =================================================================================
 * @param {struct Queue} *queueHead
 * @return {struct TreeNode} *node
 */
struct TreeNode *deQueue(struct Queue *queueHead) {

}

/**
 * @description: 释放队列空间
 * =================================================================================
 * @param {struct Queue} *queueHead
 * @return {void}
 */
void freeQueue(struct Queue *queueHead) {

}

/**
 * @description: 广度优先搜索算法 Breadth-First Search
 * =================================================================================
 * @param {int} *returnSize
 * @param {int} **returnColumnSizes
 * @param {int} **returnNum
 * @param {struct Queue} *queueHead
 * @return {void}
 */
void bfs(int *returnSize, int **returnColumnSizes, int **returnNum, struct Queue *queueHead) {

}

/**
 * @description:
 * =================================================================================
 * @param {struct TreeNode} *root
 * @param {int} *returnSize
 * @param {int} **returnColumnSizes
 * @return {int} **result
 */
int** levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes) {
    /* TODO */
}

/* ==================================================================================================== */
/* ==================================================================================================== */

/**
 * @description: 打印结果数组
 * =================================================================================
 * @param {int} *result
 * @param {int} returnSize
 * @return {void}
 */
void printArray(int *result, int returnSize) {
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\r\n");
}

/**
 * @description: 创建树节点
 * =================================================================================
 * @param {int} value
 * @return {struct TreeNode} *node
 */
struct TreeNode *newNode(int value) {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    return node;
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
    int** result = levelOrder(root, &returnSize, &returnColumnSizes);

    /* NOTE: 打印结果 */
    printf("[\n");
    for (int i = 0; i < returnSize; ++i) {
        printf("  [");
        for (int j = 0; j < returnColumnSizes[i]; ++j) {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }
    printf("]\n");

    return 0;
}