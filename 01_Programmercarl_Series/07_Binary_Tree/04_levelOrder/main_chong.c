/*
 * @File: main_chong.c
 * @Created Date: 2023-08-18 11:18:36 pm
 * @Author: Chong Liu
 * @Brief: 102. 二叉树的层序遍历: https://leetcode.cn/problems/binary-tree-level-order-traversal/
 * https://programmercarl.com/0102.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86.html
 * =================================================================================
 * Copyright (c) 2023 Chong Liu
 * =================================================================================
 * Last Modified: Chong Liu - 2023-09-02 12:44:31 pm
 */
#include <stdio.h>

/* NOTE: 树节点 */
struct TreeNode {
    int val;                    /* 节点的值 */
    struct TreeNode *left;      /* 左节点 */
    struct TreeNode *right;     /* 右节点 */
};

/* ==================================================================================================== */
/* ==================================================================================================== */
/* TODO: 目标函数 */
/**
 * @description:
 * =================================================================================
 * @param {TreeNode} *root
 * @param {int} *returnSize
 * @param {int} **returnColumnSizes
 * @return {*}
 */
int** levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes){

}

/* ==================================================================================================== */
/* ==================================================================================================== */
/* NOTE: 打印结果数组 */
void printArray(int *result, int returnSize) {
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\r\n");
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
    struct TreeNode n1, n2, n3, n4, n5, n6, n7;     /* 初始化3个树节点 */
    n1.val = 1;     /* n1节点赋值为 1 */
    n2.val = 2;     /* n2节点赋值为 2 */
    n3.val = 3;     /* n3节点赋值为 3 */
    n4.val = 4;     /* n4节点赋值为 4 */
    n5.val = 5;     /* n5节点赋值为 5 */
    n6.val = 6;     /* n6节点赋值为 6 */
    n7.val = 7;     /* n7节点赋值为 7 */

    n1.left = &n2;      /* n1节点的左节点为 n2节点 */
    n1.right = &n3;     /* n1节点的右节点为 n3节点 */

    n2.left = &n4;      /* n2节点的左节点为 n4节点 */
    n2.right = &n5;     /* n2节点的右节点为 n5节点 */

    n3.left = &n6;      /* n3节点的左节点为 n6节点 */
    n3.right = &n7;     /* n3节点的右节点为 n7节点 */

    n4.left = NULL;     /* n4节点的左节点为 NULL */
    n4.right = NULL;    /* n4节点的右节点为 NULL */

    n5.left = NULL;     /* n5节点的左节点为 NULL */
    n5.right = NULL;    /* n5节点的右节点为 NULL */

    n6.left = NULL;     /* n6节点的左节点为 NULL */
    n6.right = NULL;    /* n6节点的右节点为 NULL */

    n7.left = NULL;     /* n7节点的左节点为 NULL */
    n7.right = NULL;    /* n7节点的右节点为 NULL */

    int returnSize = 0;
    int *result = NULL;

    return 0;
}