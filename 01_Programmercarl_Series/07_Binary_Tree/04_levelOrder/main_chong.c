/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\07_Binary_Tree\04_levelOrder\main_chong.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-11 21:17:11
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-09-12 10:41:33
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
/* 层序遍历 借助其他数据结构，记录下，Tree 的下一层的所有结点。这样一层一层的遍历。直到结束 */

/* 层序遍历 + 链表队列 */
    /* 1：使用队列的数据结构存储对应的二叉树的结点 Queue */
    /* 2：使用变量 front 和 rear 维护队列，队列是具有先进先出的特点 */
    /* 3：使用 Queue[rear++] = root; 来入队 */
    /* 4：使用 nodeIt = Queue[front++]; 来出队 */
    /* 5：出队后，用nodeIt对应的子节点来操作，是否需要入队。 */

/* 1：采用队列结构存储每一层的结点 */
/* 2：因为队列的结构特性，操作是先进先出 */
/* 时间复杂度：O(n) 空间复杂度: O(n) */
/* ==================================================================================================== */
struct Queue {                  /* 队列结构体 */
    struct TreeNode *node;      /* 树节点指针 */
    struct Queue    *next;      /* 指向下一元素的指针 */
};

/**
 * @description: 入队
 * =================================================================================
 * @param {struct Queue} *queueHead     链表队列的虚拟头节点
 * @param {struct TreeNode} *node       待入队树节点元素
 * @return {void}
 */
void enQueue(struct Queue *queueHead, struct TreeNode *node) {
    /* TODO */
    struct Queue *queueIt = queueHead;
    while (queueIt->next != NULL) {
        queueIt->next = queueIt->next;
    }
    struct Queue *queueNew = (struct Queue *)malloc(sizeof(struct Queue));
    queueNew->node = node;
    queueNew->next = NULL;
    queueIt->next = queueNew;
}

/**
 * @description: 出队
 * =================================================================================
 * @param {struct Queue} *queueHead     链表队列的虚拟头节点
 * @return {struct TreeNode} *node      出队树节点元素
 */
struct TreeNode *deQueue(struct Queue *queueHead) {
    /* TODO */
    struct Queue *queueIt = queueHead->next;
    struct TreeNode *node;
    if (queueIt != NULL) {
        queueHead->next = queueIt->next;
        node = queueIt->node;
        free(queueIt);
        return node;
    }
    return NULL;
}

/**
 * @description: 释放队列空间
 * =================================================================================
 * @param {struct Queue} *queueHead     链表队列的虚拟头节点
 * @return {void}
 */
void freeQueue(struct Queue *queueHead) {
    /* TODO */
    struct Queue *queueIt = queueHead->next;
    struct Queue *queuePre = queueHead->next;
    if (queueIt != NULL) {
        queuePre = queueIt;
        queueIt = queueIt->next;
        free(queuePre);
    }
    free(queueHead);
}

/**
 * @description: 广度优先搜索算法 Breadth-First Search
 * =================================================================================
 * @param {int} *returnSize             二叉树的层数
 * @param {int} **returnColumnSizes     二叉树对应层级的节点数
 * @param {int} **returnNum             结果二维数组
 * @param {struct Queue} *queueHead     链表队列的虚拟头节点
 * @return {void}
 */
void bfs(int *returnSize, int **returnColumnSizes, int **returnNum, struct Queue *queueHead) {
    /* TODO */
}

/**
 * @description:
 * =================================================================================
 * @param {struct TreeNode} *root       二叉树的根节点
 * @param {int} *returnSize             二叉树的层数
 * @param {int} **returnColumnSizes     二叉树对应层级的节点数
 * @return {int} **result               结果二维数组
 */
int** levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes) {
    /* TODO */
}

/* ==================================================================================================== */
/* ==================================================================================================== */

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
 * @description: 打印二维数组
 * =================================================================================
 * @param {int} **array
 * @param {int} size
 * @param {int} *columnSizes
 * @return {void}
 */
void print2DArray(int **array, int size, int *columnSizes) {
    printf("[\n");
    for (int i = 0; i < size; ++i) {
        printf("  [");
        for (int j = 0; j < columnSizes[i]; ++j) {
            printf("%d", array[i][j]);
            if (j < columnSizes[i] - 1) {
                printf(", ");
            }
        }
        printf("]\n");
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