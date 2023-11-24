/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\07_Binary_Tree\00_common\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-11-24 20:28:34
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-24 23:09:19
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用二叉树源文件测试
 */
/* 标准头文件 */
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
 * @description: 测试 1
 * =================================================================================
 * @return {void}
 */
void test_1(void) {
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
    validateArray('1', expected, expectedSize, actual, actualSize, COMMON_FALSE);
}

/**
 * @description: 测试 2
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */

    /* 预期结果 */

    /* 比较结果 */

}

/**
 * @description: 测试 3
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    /* 实际结果 */

    /* 预期结果 */

    /* 比较结果 */

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
    test_1();
    // test_2();
    // test_3();
    return 0;
}