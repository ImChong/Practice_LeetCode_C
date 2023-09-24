/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\07_Binary_Tree\07_averageOfLevels\main_chong_BFS.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-28 09:44:35
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-09-24 12:39:32
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 637. 二叉树的层平均值: https://leetcode.cn/problems/average-of-levels-in-binary-tree/
 * https://programmercarl.com/0102.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86.html#_637-%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%B9%B3%E5%9D%87%E5%80%BC
 * 解法参考：https://leetcode.cn/problems/average-of-levels-in-binary-tree/solutions/410522/er-cha-shu-de-ceng-ping-jun-zhi-by-leetcode-soluti/
 *
 * 方法二：广度优先搜索
 *       1
 *      / \
 *     2   3
 *    / \ / \
 *   4  5 6  7
 *
 * sums:        [1,    5,  22]
 * counts:      [1,    2,   4]
 * averages:    [1,  2.5, 5.5]
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1001   /* 定义数组的最大大小 */

/* 树节点 */
struct TreeNode {
    int val;                    /* 节点的值 */
    struct TreeNode *left;      /* 左节点 */
    struct TreeNode *right;     /* 右节点 */
};

/* ==================================================================================================== */
/* ==================================================================================================== */
/* 目标函数 */
/*
    Breadth-first search (BFS) - 广度优先搜索算法
    使用一个队列来存储每一层的节点。
    在遍历每一层节点时，它计算该层节点值的平均值，并将该平均值存储在数组中。
    最后，函数返回该数组的指针。
*/
/* ==================================================================================================== */
/* ==================================================================================================== */

/**
 * @description: 计算二叉树每一层节点值的平均值
 * =================================================================================
 * @param {TreeNode} *root      根节点指针
 * @param {int} *returnSize     返回数组大小的指针
 * @return {double} *averages   平均值数组的指针
 */
double *averageOfLevels(struct TreeNode *root, int *returnSize) {
    double *averages = malloc(sizeof(double) * MAX_SIZE);                       /* 为平均值数组分配空间 */
    struct TreeNode **queue = malloc(sizeof(struct TreeNode*) * MAX_SIZE);      /* 为队列分配空间 */
    *returnSize = 0;                                                            /* 初始化返回数组大小为0 */

    int qleft = 0, qright = 0;                                                  /* 定义队列左右指针 */
    queue[qright++] = root;                                                     /* 将根节点加入队列 */
    while (qleft < qright) {                                                    /* 当队列不为空时循环 */
        double sum = 0;                                                             /* 定义当前层节点值之和 */
        int size = qright - qleft;                                                  /* 定义当前层节点数 */
        for (int i = 0; i < size; i++) {                                            /* 遍历当前层节点 */
            struct TreeNode* node = queue[qleft++];                                     /* 取出当前层节点 */
            sum += node->val;                                                           /* 将当前层节点值加到当前层节点值之和上 */
            struct TreeNode *left = node->left, *right = node->right;                   /* 取出当前层节点的左右子节点 */
            if (left != NULL) {                                                         /* 如果左子节点不为空 */
                queue[qright++] = left;                                                     /* 将左子节点加入队列 */
            }
            if (right != NULL) {                                                        /* 如果右子节点不为空 */
                queue[qright++] = right;                                                    /* 将右子节点加入队列 */
            }
        }
        averages[(*returnSize)++] = sum / size;                                     /* 将当前层节点值之和除以当前层节点数得到当前层节点值的平均值 */
    }
    return averages;                                                            /* 返回平均值数组的指针 */
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
 * @description: 后续遍历释放树所占用的空间
 * =================================================================================
 * @param {TreeNode} *root
 * @return {void}
 */
void freeTree(struct TreeNode *root) {
    if (root == NULL) {             /* 如果传入节点为 NULL 则返回 */
        return;
    }

    freeTree(root->left);           /* 遍历释放左节点空间 */
    freeTree(root->right);          /* 遍历释放右节点空间 */
    free(root);                     /* 释放当前节点空间 */
}

/**
 * @description: 打印一维数组
 * =================================================================================
 * @param {double} *array      一维数组
 * @param {int} size        一维数组的大小
 * @return {void}
 */
void print1DArray(double *array, int size) {
    printf("[");                        /* 打印行边框 [ */
    for (int i = 0; i < size; ++i) {        /* 遍历 array 内的元素 */
        printf("%.3f", array[i]);                 /* 打印 array 内的元素 */
        if (i < size - 1) {                     /* 打印分隔符：, */
            printf(", ");
        }
    }
    printf("]\n");                      /* 打印行边框 ] */
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

    /* 函数调用 */
    double* result = averageOfLevels(root, &returnSize);
    print1DArray(result, returnSize);

    freeTree(root);     /* 释放树所占用的空间 */
    free(result);       /* 释放结果一维数组的内存空间 */
    return 0;
}