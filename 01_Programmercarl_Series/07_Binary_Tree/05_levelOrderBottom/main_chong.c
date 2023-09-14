/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\07_Binary_Tree\05_levelOrderBottom\main_chong.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-28 09:44:35
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-09-14 15:18:56
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 107. 二叉树的层序遍历 II：从下往上层序遍历二叉树
 * 107. 二叉树的层序遍历 II: https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/
 * https://programmercarl.com/0102.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86.html#_102-%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86
 * 解法参考：https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/solutions/402560/er-cha-shu-de-ceng-ci-bian-li-ii-by-leetcode-solut/
 * 解法参考：https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/solutions/1298370/er-cha-shu-de-ceng-xu-bian-li-ii-cyu-yan-u762/
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

/* NOTE: 层序遍历 + 队列(迭代法)*/
/* 关键点：  1：采用队列结构存储每一层的结点
            2：因为队列的结构特性，操作是先进先出
            3：将全部的的每一层节点存储于Queue队列当中
            4：遍历结点的左右子结点，放在就继续放入Queue队列
            5：为了清晰的表示出每一层之间的间隔，这里在队列中插入null结点，表示换层了
            时间复杂度：O(n) 空间复杂度: O(n) */

/* NOTE: 层序遍历 + 队列(迭代法) 优化 */
/* 关键点：  1：去掉用来表示换行的null指针
            2：通过交换打印输出的方式，完成结果的输出
            时间复杂度：O(n) 空间复杂度: O(n) */
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
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    /* TODO */
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
        int *treeLevel = (int *)malloc(sizeof(int) * nodeNums);                             /* 为当前层节点数的数值分配空间 */
        (*returnColumnSizes)[*returnSize] = nodeNums;                                       /* 记录当前层的节点数（当前行的列数） */
        for (int i = 0; i < nodeNums; i++) {
            struct TreeNode *node = treeNodeQueue[queueFront++];
            treeLevel[i] = node->val;
            if (node->left != NULL) {
                treeNodeQueue[queueRear++] = node->left;
            }
            if (node->right != NULL) {
                treeNodeQueue[queueRear++] = node->right;
            }
        }
        resultArray[(*returnSize)++] = treeLevel;
    }

    for (int i = 0; 2 * i < *returnSize; i++) {
        int *tmp1 = resultArray[i];
        resultArray[i] = resultArray[(*returnSize) - i - 1];
        resultArray[(*returnSize) - i - 1] = tmp1;
        int tmp2 = (*returnColumnSizes)[i];
        (*returnColumnSizes)[i] = (*returnColumnSizes)[(*returnSize) - i - 1];
        (*returnColumnSizes)[(*returnSize) - i - 1] = tmp2;
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
    int** result = levelOrderBottom(root, &returnSize, &returnColumnSizes);
    print2DArray(result, returnSize, returnColumnSizes);

    return 0;
}