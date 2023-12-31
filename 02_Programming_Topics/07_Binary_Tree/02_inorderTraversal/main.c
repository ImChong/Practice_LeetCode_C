/*
 * @FilePath     : \Practice_LeetCode_C\01_Programming_Topics\07_Binary_Tree\02_inOrderTraversal\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-26 18:11:00
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 94. 二叉树的中序遍历：https://leetcode.cn/problems/binary-tree-inorder-traversal/description/
 * [1, 2, 3, 4, 5, 6, 7]
 * 树结构表示：
 *       1
 *      / \
 *     2   3
 *    / \ / \
 *   4  5 6  7
 *
 * 中序遍历 - 递归方法/迭代方法
 * [4, 2, 5, 1, 6, 3, 7]
 */
/* standard header file (标准头文件) */
#include <stdio.h>
#include <stdlib.h>
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
    printTestTree();
    printf("--------------------\r\n");
    test_inOrderTraversal();
    return 0;
}