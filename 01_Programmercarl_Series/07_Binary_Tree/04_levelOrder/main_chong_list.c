/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\07_Binary_Tree\04_levelOrder\main_chong_list.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-11 21:17:11
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-09-13 22:20:31
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 102. 二叉树的层序遍历：从上往下层序遍历二叉树 - 此文件为数组解法
 * 102. 二叉树的层序遍历: https://leetcode.cn/problems/binary-tree-level-order-traversal/
 * https://programmercarl.com/0102.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86.html
 * 解法参考：https://leetcode.cn/problems/binary-tree-level-order-traversal/solutions/1286876/er-cha-shu-de-ceng-xu-bian-li-cyu-yan-xi-jdk8/
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
/* 层序遍历 - 借助数组数据结构，记录下 Tree 的下一层的所有结点。这样一层一层的遍历。直到结束 */

/* 层序遍历 + 数组队列 */
    /* 1：使用队列的数据结构存储对应的二叉树的结点 Queue */
    /* 2：使用变量 front 和 rear 维护队列，队列是具有先进先出的特点 */
    /* 3：使用 Queue[rear++] = root; 来入队 */
    /* 4：使用 nodeIt = Queue[front++]; 来出队 */
    /* 5：出队后，用nodeIt对应的子节点来操作，是否需要入队。 */

/* 1：采用队列结构存储每一层的结点 */
/* 2：因为队列的结构特性，操作是先进先出 */
/* 时间复杂度：O(n) 空间复杂度: O(n) */
/* ==================================================================================================== */
/* ==================================================================================================== */
#define MAX_SIZE 2000           /* 初始化大小 */

/**
 * TODO: 目标函数
 * @description: 二叉树的层序遍历
 * =================================================================================
 * @param {struct TreeNode} *root       二叉树的根节点
 * @param {int} *returnSize             二叉树的层数
 * @param {int} **returnColumnSizes     二叉树对应层级的节点数
 * @return {int} **resultArray          结果二维数组
 */
int** levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;                                                                    /* 初始化二叉树的层数为 0 */
    if (root == NULL) {                                                                 /* 如果根节点为 NULL */
        return NULL;                                                                        /* 返回 NULL */
    }

    int **resultArray = (int **)malloc(sizeof(int *) * MAX_SIZE);                       /* 为二维数组分配空间 - 2000个int*类型数据 */
    *returnColumnSizes = (int *)malloc(sizeof(int) * MAX_SIZE);                         /* 用来记录二叉树每层的节点数（二维数组每行的列数）- 2000个int类型数据 */

    struct TreeNode *treeNodeQueue[MAX_SIZE];                                           /* 数组作为树节点的队列 */
    int queueFront = 0;                                                                 /* 队首索引 */
    int queueRear = 0;                                                                  /* 队尾索引 */
    struct TreeNode *curNode;                                                           /* 当前树节点的指针 */

    treeNodeQueue[queueRear++] = root;                                                  /* 将树的根节点入队 */
    while (queueFront != queueRear) {                                                   /* 当队首索引不等于队尾索引时 - 保持循环 */
        int nodeNums = 0;                                                                   /* 二叉树当前层的节点数（结果二维数组当前行的列数） */
        int last = queueRear;                                                               /* 记录队尾索引 */
        resultArray[*returnSize] = (int *)malloc(sizeof(int) * (last - queueFront));        /* 为当前层的树节点记录数组分配空间 */
        while (queueFront < last) {                                                         /* 当队首索引小于队尾索引时 - 保持循环 */
            curNode = treeNodeQueue[queueFront++];                                          /* 取出队首树节点 */
            resultArray[*returnSize][nodeNums++] = curNode->val;                            /* 将队首树节点的值放入结果二维数组当前层的 nodeNums 索引，并将 nodeNums + 1 */
            if (curNode->left != NULL) {
                treeNodeQueue[queueRear++] = curNode->left;
            }
            if (curNode->right != NULL) {
                treeNodeQueue[queueRear++] = curNode->right;
            }
        }
        (*returnColumnSizes)[*returnSize] = nodeNums;
        (*returnSize)++;
    }

    return resultArray;
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
    int** result = levelOrder(root, &returnSize, &returnColumnSizes);
    print2DArray(result, returnSize, returnColumnSizes);

    return 0;
}