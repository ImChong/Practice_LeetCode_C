/*
 * @FilePath     : \Practice_LeetCode_C\02_Programming_Topics\07_Binary_Tree\00_common\src\testHelper.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-12-31 21:06:03
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-31 21:10:35
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : test helper source file (测试函数源文件)
 */
/* standard header file (标准头文件) */
#include <stdio.h>
/* common function header file (通用头文件) */
#include "commonTypeDef.h"
#include "commonArray.h"
#include "commonBinaryTree.h"
/* test helper header file (测试函数头文件) */
#include "testHelper.h"

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
    struct TreeNode *root = BTree_Init(arr, arrSize);
    int actualSize_recursion = 0;
    int *actual_recursion = BTree_PreOrderTraversal_Recursion(root, &actualSize_recursion);
    int actualSize_iteration = 0;
    int *actual_iteration = BTree_PreOrderTraversal_Iteration(root, &actualSize_iteration);

    /* 预期结果 */
    int expected[] = {1, 2, 4, 5, 3, 6, 7};
    int expectedSize = ARR_SIZE(expected);

    /* 比较结果 */
    printf("PreorderTraversal Recursion Method.\n");
    Validate_Array('1', expected, expectedSize, actual_recursion, actualSize_recursion, SORT_FALSE);
    printf("PreorderTraversal Iteration Method.\n");
    Validate_Array('2', expected, expectedSize, actual_iteration, actualSize_iteration, SORT_FALSE);

    /* 释放内存 */
    BTree_Free(root);
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
    struct TreeNode *root = BTree_Init(arr, arrSize);
    int actualSize_recursion = 0;
    int *actual_recursion = inOrderTraversal_recursion(root, &actualSize_recursion);
    int actualSize_iteration = 0;
    int *actual_iteration = inOrderTraversal_iteration(root, &actualSize_iteration);

    /* 预期结果 */
    int expected[] = {4, 2, 5, 1, 6, 3, 7};
    int expectedSize = ARR_SIZE(expected);

    /* 比较结果 */
    printf("InorderTraversal Recursion Method.\n");
    Validate_Array('1', expected, expectedSize, actual_recursion, actualSize_recursion, SORT_FALSE);
    printf("InorderTraversal Iteration Method.\n");
    Validate_Array('2', expected, expectedSize, actual_iteration, actualSize_iteration, SORT_FALSE);

    /* 释放内存 */
    BTree_Free(root);
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
    struct TreeNode *root = BTree_Init(arr, arrSize);
    int actualSize_recursion = 0;
    int *actual_recursion = postOrderTraversal_recursion(root, &actualSize_recursion);
    int actualSize_iteration = 0;
    int *actual_iteration = postOrderTraversal_iteration(root, &actualSize_iteration);

    /* 预期结果 */
    int expected[] = {4, 5, 2, 6, 7, 3, 1};
    int expectedSize = ARR_SIZE(expected);

    /* 比较结果 */
    printf("PostorderTraversal Recursion Method.\n");
    Validate_Array('1', expected, expectedSize, actual_recursion, actualSize_recursion, SORT_FALSE);
    printf("PostorderTraversal Iteration Method.\n");
    Validate_Array('2', expected, expectedSize, actual_iteration, actualSize_iteration, SORT_FALSE);

    /* 释放内存 */
    BTree_Free(root);
}