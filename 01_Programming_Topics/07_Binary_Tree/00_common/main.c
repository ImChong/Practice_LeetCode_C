/*
 * @FilePath     : \Practice_LeetCode_C\01_Programming_Topics\07_Binary_Tree\00_common\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-11-24 20:28:34
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-26 12:52:20
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用二叉树源文件测试
 */
/* 标准头文件 */
#include <stdio.h>
/* 通用头文件 */
#include "commonTypeDef.h"
#include "commonArray.h"
#include "commonBinaryTree.h"

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试前序遍历
 * [1, 2, 3, 4, 5, 6, 7]
 *  树结构表示：
 *       1
 *      / \
 *     2   3
 *    / \ / \
 *   4  5 6  7
 *
 * 前序遍历 - 递归方法/迭代方法
 * [1, 2, 4, 5, 3, 6, 7]
 * =================================================================================
 * @return {void}
 */
void test_preOrderTraversal(void) {
    /* 实际结果 */
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int arrSize = ARR_SIZE(arr);
    struct TreeNode *root = arrayToTree(arr, arrSize);
    int actualSize_recursion = 0;
    int *actual_recursion = preOrderTraversal_recursion(root, &actualSize_recursion);
    int actualSize_iteration = 0;
    int *actual_iteration = preOrderTraversal_iteration(root, &actualSize_iteration);

    /* 预期结果 */
    int expected[] = {1, 2, 4, 5, 3, 6, 7};
    int expectedSize = ARR_SIZE(expected);

    /* 比较结果 */
    printf("PreorderTraversal Recursion Method.\n");
    validateArray('1', expected, expectedSize, actual_recursion, actualSize_recursion, SORT_FALSE);
    printf("PreorderTraversal Iteration Method.\n");
    validateArray('2', expected, expectedSize, actual_iteration, actualSize_iteration, SORT_FALSE);

    /* 释放内存 */
    freeTree(root);
}

/**
 * @description: 测试中序遍历
 * [1, 2, 3, 4, 5, 6, 7]
 * 树结构表示：
 *       1
 *      / \
 *     2   3
 *    / \ / \
 *   4  5 6  7
 *
 * 中序遍历 - 递归方法
 * [4, 2, 5, 1, 6, 3, 7]
 * =================================================================================
 * @return {void}
 */
void test_inOrderTraversal(void) {
    /* 实际结果 */
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int arrSize = ARR_SIZE(arr);
    struct TreeNode *root = arrayToTree(arr, arrSize);
    int actualSize_recursion = 0;
    int *actual_recursion = inOrderTraversal_recursion(root, &actualSize_recursion);
    int actualSize_iteration = 0;
    int *actual_iteration = inOrderTraversal_iteration(root, &actualSize_iteration);

    /* 预期结果 */
    int expected[] = {4, 2, 5, 1, 6, 3, 7};
    int expectedSize = ARR_SIZE(expected);

    /* 比较结果 */
    printf("InorderTraversal Recursion Method.\n");
    validateArray('1', expected, expectedSize, actual_recursion, actualSize_recursion, SORT_FALSE);
    printf("InorderTraversal Iteration Method.\n");
    validateArray('2', expected, expectedSize, actual_iteration, actualSize_iteration, SORT_FALSE);

    /* 释放内存 */
    freeTree(root);
}

/**
 * @description: 测试后序遍历
 * [1, 2, 3, 4, 5, 6, 7]
 * 树结构表示：
 *       1
 *      / \
 *     2   3
 *    / \ / \
 *   4  5 6  7
 *
 * 后序遍历 - 递归方法/迭代方法
 * [4, 5, 2, 6, 7, 3, 1]
 * =================================================================================
 * @return {void}
 */
void test_postOrderTraversal(void) {
    /* 实际结果 */
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int arrSize = ARR_SIZE(arr);
    struct TreeNode *root = arrayToTree(arr, arrSize);
    int actualSize_recursion = 0;
    int *actual_recursion = postOrderTraversal_recursion(root, &actualSize_recursion);
    int actualSize_iteration = 0;
    int *actual_iteration = postOrderTraversal_iteration(root, &actualSize_iteration);

    /* 预期结果 */
    int expected[] = {4, 5, 2, 6, 7, 3, 1};
    int expectedSize = ARR_SIZE(expected);

    /* 比较结果 */
    printf("PostorderTraversal Recursion Method.\n");
    validateArray('1', expected, expectedSize, actual_recursion, actualSize_recursion, SORT_FALSE);
    printf("PostorderTraversal Iteration Method.\n");
    validateArray('2', expected, expectedSize, actual_iteration, actualSize_iteration, SORT_FALSE);

    /* 释放内存 */
    freeTree(root);
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
int main(int argc, const char* argv[]) {
    printTestTree();
    printf("--------------------\r\n");
    test_preOrderTraversal();
    printf("--------------------\r\n");
    test_inOrderTraversal();
    printf("--------------------\r\n");
    test_postOrderTraversal();
    return 0;
}