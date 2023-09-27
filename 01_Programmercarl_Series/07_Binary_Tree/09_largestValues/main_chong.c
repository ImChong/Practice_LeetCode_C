/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\07_Binary_Tree\09_largestValues\main_chong.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-18 23:18:36
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-09-27 23:21:51
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 515. 在每个树行中找最大值: https://leetcode.cn/problems/find-largest-value-in-each-tree-row/
 */
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************************/
/*                                                                                */
/*                                MACRO FUNCTIONS                                 */
/*                                                                                */
/**********************************************************************************/
#define ARR_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))    /* 获取数组长度 */

/**********************************************************************************/
/*                                                                                */
/*                                 GLOBAL VARIABLES                               */
/*                                                                                */
/**********************************************************************************/
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
/* TODO: 目标函数 */

/* ============================================================================== */
/* ============================================================================== */

int *largestValues(struct TreeNode *root, int *returnSize){
    /* TODO */
    return NULL;
}

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 创建树节点
 * =================================================================================
 * @param {int} value                   节点数值
 * @return {struct TreeNode} *node      二叉树节点
 */
struct TreeNode *newNode(int value) {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
 * @description: 数组转换为树
 * =================================================================================
 * @param {int} *arr
 * @param {int} size
 * @param {int} index
 * @param {struct TreeNode} **root
 * @return {void}
 */
void arrayToTree(int *arr, int size, int index, struct TreeNode **root) {
    if (index < size) {
        *root = newNode(*(arr + index));
        arrayToTree(arr, size, 2 * index + 1, &((*root)->left));
        arrayToTree(arr, size, 2 * index + 2, &((*root)->right));
    }
}

/**
 * @description: 后续遍历释放树所占用的空间
 * =================================================================================
 * @param {struct TreeNode} *root      树的根节点
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
 * @param {int} *array      一维数组
 * @param {int} size        一维数组的大小
 * @return {void}
 */
void print1DArray(int *array, int size) {
    printf("[");                        /* 打印行边框 [ */
    for (int i = 0; i < size; ++i) {        /* 遍历 array 内的元素 */
        printf("%d", array[i]);                 /* 打印 array 内的元素 */
        if (i < size - 1) {                     /* 打印分隔符：, */
            printf(", ");
        }
    }
    printf("]\n");                      /* 打印行边框 ] */
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: [1,3,2,5,3,NULL,9]
 *      1
 *     / \
 *    3   2
 *   / \   \
 *  5   3   9
 * output: [1,3,9]
 * =================================================================================
 * @return {*}
 */
void test_1(void) {
    /* 预期结果 */
    int expected[] = {1, 3, 9};

    /* 构建二叉树 */
    int treeArr[] = {1, 3, 2, 5, 3, NULL, 9};
    struct TreeNode *root = NULL;
    printf("Tree Array: \n");
    print1DArray(treeArr, ARR_SIZE(treeArr));
    /* TODO */
}

/**
 * @description: [1,2,3]
 *    1
 *   / \
 *  2   3
 * output: [1,3]
 * =================================================================================
 * @return {*}
 */
void test_2(void) {
    int expected[] = {1, 3};
    /* TODO */
}

/**********************************************************************************/
/*                                                                                */
/*                                  MAIN FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 主函数
 * =================================================================================
 * @param {int} argc        程序入参个数
 * @param {char} *argv[]    程序入参字符串数组
 * @return {int}            程序运行状态
 */
int main(int argc, const char *argv[]) {
    test_1();
    test_2();
    return 0;
}