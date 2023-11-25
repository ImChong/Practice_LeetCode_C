/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\07_Binary_Tree\00_common\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-11-24 20:28:34
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-25 11:05:04
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

/**
 * @description: 打印示意树结构
 * =================================================================================
 * @return {void}
 */
void printTestTree(void) {
    printf("Test Tree:\n");
    printf("      1 \n");
    printf("     / \\ \n");
    printf("    2   3 \n");
    printf("   / \\ / \\ \n");
    printf("  4  5 6  7 \n");
    printf("\n");
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试 1
 * [1, 2, 3, 4, 5, 6, 7]
 *  树结构表示：
 *       1
 *      / \
 *     2   3
 *    / \ / \
 *   4  5 6  7
 * 前序遍历 - 递归方法
 * [1, 2, 4, 5, 3, 6, 7]
 * =================================================================================
 * @return {void}
 */
void test_1(void) {
    printf("PreorderTraversal Recursion Method.\n");

    /* 实际结果 */
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int arrSize = ARR_SIZE(arr);
    struct TreeNode *root = arrayToTree(arr, arrSize);
    int actualSize = 0;
    int *actual = preorderTraversal_recursion(root, &actualSize);

    /* 预期结果 */
    int expected[] = {1, 2, 4, 5, 3, 6, 7};
    int expectedSize = ARR_SIZE(expected);

    /* 比较结果 */
    validateArray('1', expected, expectedSize, actual, actualSize, COMMON_FALSE);

    /* 释放内存 */
    freeTree(root);
}

/**
 * @description: 测试 2
 * [1, 2, 3, 4, 5, 6, 7]
 *  树结构表示：
 *       1
 *      / \
 *     2   3
 *    / \ / \
 *   4  5 6  7
 * 前序遍历 - 迭代方法
 * [1, 2, 4, 5, 3, 6, 7]
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    printf("PreorderTraversal Iteration Method.\n");

    /* 实际结果 */
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int arrSize = ARR_SIZE(arr);
    struct TreeNode *root = arrayToTree(arr, arrSize);
    int actualSize = 0;
    int *actual = preorderTraversal_iteration(root, &actualSize);

    /* 预期结果 */
    int expected[] = {1, 2, 4, 5, 3, 6, 7};
    int expectedSize = ARR_SIZE(expected);

    /* 比较结果 */
    validateArray('2', expected, expectedSize, actual, actualSize, COMMON_FALSE);

    /* 释放内存 */
    freeTree(root);
}

/* ============================================================================== */
/* ============================================================================== */

/**
 * @description: 测试 3
 * [1, 2, 3, 4, 5, 6, 7]
 * 树结构表示：
 *       1
 *      / \
 *     2   3
 *    / \ / \
 *   4  5 6  7
 * 中序遍历 - 递归方法
 * [4, 2, 5, 1, 6, 3, 7]
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    printf("InorderTraversal Recursion Method.\n");

    /* 实际结果 */
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int arrSize = ARR_SIZE(arr);
    struct TreeNode *root = arrayToTree(arr, arrSize);
    int actualSize = 0;
    int *actual = inorderTraversal_recursion(root, &actualSize);

    /* 预期结果 */
    int expected[] = {4, 2, 5, 1, 6, 3, 7};
    int expectedSize = ARR_SIZE(expected);

    /* 比较结果 */
    validateArray('3', expected, expectedSize, actual, actualSize, COMMON_FALSE);

    /* 释放内存 */
    freeTree(root);
}

/**
 * @description: 测试 4
 * [1, 2, 3, 4, 5, 6, 7]
 * 树结构表示：
 *       1
 *      / \
 *     2   3
 *    / \ / \
 *   4  5 6  7
 * 中序遍历 - 迭代方法
 * [4, 2, 5, 1, 6, 3, 7]
 * =================================================================================
 * @return {void}
 */
void test_4(void) {
    printf("InorderTraversal Iteration Method.\n");

    /* 实际结果 */
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int arrSize = ARR_SIZE(arr);
    struct TreeNode *root = arrayToTree(arr, arrSize);
    int actualSize = 0;
    int *actual = inorderTraversal_iteration(root, &actualSize);

    /* 预期结果 */
    int expected[] = {4, 2, 5, 1, 6, 3, 7};
    int expectedSize = ARR_SIZE(expected);

    /* 比较结果 */
    validateArray('4', expected, expectedSize, actual, actualSize, COMMON_FALSE);

    /* 释放内存 */
    freeTree(root);
}

/* ============================================================================== */
/* ============================================================================== */

/* TODO */

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

    test_1();
    test_2();

    test_3();
    test_4();
    return 0;
}