/*
 * @FilePath     : \Practice_LeetCode_C\02_Programming_Topics\07_Binary_Tree\01_preorderTraversal\src\testHelper.c
 * @Author       : Chong Liu
 * @CreateDate   : 2024-01-01 01:05:33
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-01 01:08:42
 * =================================================================================
 * Copyright (c) 2024 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : test helper source file
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
    struct TreeNode *root = BTree_ArrayInit(arr, arrSize);
    int actualSize_recursion = 0;
    int *actual_recursion = preOrderTraversal_recursion(root, &actualSize_recursion);
    int actualSize_iteration = 0;
    int *actual_iteration = preOrderTraversal_iteration(root, &actualSize_iteration);

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