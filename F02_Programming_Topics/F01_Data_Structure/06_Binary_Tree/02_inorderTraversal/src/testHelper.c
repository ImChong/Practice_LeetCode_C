/*
 * @FilePath     : \Practice_LeetCode_C\02_Programming_Topics\07_Binary_Tree\02_inorderTraversal\src\testHelper.c
 * @Author       : Chong Liu
 * @CreateDate   : 2024-01-02 02:00:54
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-02 02:03:44
 * =================================================================================
 * Copyright (c) 2024 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : test helper source file
 */
/* Standard header file (标准头文件) */
#include <stdio.h>
/* Common function header file (通用头文件) */
#include "F01_Common_Functions/inc/common_def/common_type_def.h"
#include "F01_Common_Functions/inc/common_array.h"
#include "commonBinaryTree.h"
/* test helper header file (测试函数头文件) */
#include "testHelper.h"

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试中序遍历
 * [1, 2, 3, 4, 5, 6, 7]
 *  树结构表示：
 *       1
 *      / \
 *     2   3
 *    / \ / \
 *   4  5 6  7
 *
 * 中序遍历 - 递归方法/迭代方法
 * [4, 2, 5, 1, 6, 3, 7]
 * =================================================================================
 * @return {void}
 */
void test_inOrderTraversal(void) {
    /* Function call (函数调用) */
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int arrSize = ARR_SIZE(arr);
    struct TreeNode *root = BTree_ArrayInit(arr, arrSize);
    int actualSize_recursion = 0;
    int *actual_recursion = BTree_InOrderTraversal_Recursion(root, &actualSize_recursion);
    int actualSize_iteration = 0;
    int *actual_iteration = BTree_InOrderTraversal_Iteration(root, &actualSize_iteration);

    /* Expect result (期望结果) */
    int expected[] = {4, 2, 5, 1, 6, 3, 7};
    int expectedSize = ARR_SIZE(expected);

    /* Validate result (验证函数调用结果) */
    printf("InorderTraversal Recursion Method.\n");
    Validate_Array('1', expected, expectedSize, actual_recursion, actualSize_recursion, SORT_FALSE);
    printf("InorderTraversal Iteration Method.\n");
    Validate_Array('2', expected, expectedSize, actual_iteration, actualSize_iteration, SORT_FALSE);

    /* Free memory (释放内存) */
    BTree_Free(root);
}