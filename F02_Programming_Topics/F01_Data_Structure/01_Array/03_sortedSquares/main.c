/*
 * @FilePath     : \Practice_LeetCode_C\F02_Programming_Topics\F01_Data_Structure\01_Array\03_sortedSquares\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-15 02:16:48
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : leetcode 977.有序数组的平方：https://leetcode.cn/problems/squares-of-a-sorted-array/
 *      https://programmercarl.com/0977.%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E7%9A%84%E5%B9%B3%E6%96%B9.html
 */
/* solution header file (题解头文件) */
#include "sortedSquares.h"
/* Standard header file (标准头文件) */
#include <stdlib.h>
/* Common function header file (通用头文件) */
#include "commonTypeDef.h"
#include "commonArray.h"
/* solution method configuration header file (解题方法配置文件) */
// #include "methodCfg"     /* Uncomment this line if solution has multiple methods */

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: Test 1
 * Input: nums = [-4, -1, 0, 3, 10]
 * Outut: [0, 1, 9, 16, 100]
 * =================================================================================
 * @return {void}
 */
void Test1(void) {
    /* Function call (函数调用) */
    int nums[] = {-4, -1, 0, 3, 10};
    int numsSize = ARR_SIZE(nums);
    int actualSize = 0;
    int *actualNums = sortedSquares(nums, numsSize, &actualSize);

    /* Expect result (期望结果) */
    int expectNums[] = {0, 1, 9, 16, 100};
    int expectSize = ARR_SIZE(expectNums);

    /* 比较结果 */
    Validate_Array('1', expectNums, expectSize, actualNums, actualSize, COMMON_FALSE);

    /* 释放内存 */
    free(actualNums);
}

/**
 * @description: Test 2
 * Input: nums = [-7, -3, 2, 3, 11]
 * Outut: [4, 9, 9, 49, 121]
 * =================================================================================
 * @return {void}
 */
void Test2(void) {
    /* Function call (函数调用) */
    int nums[] = {-7, -3, 2, 3, 11};
    int numsSize = ARR_SIZE(nums);
    int actualSize;
    int *actualNums = sortedSquares(nums, numsSize, &actualSize);

    /* Expect result (期望结果) */
    int expectNums[] = {4, 9, 9, 49, 121};
    int expectSize = ARR_SIZE(expectNums);

    /* 比较结果 */
    Validate_Array('2', expectNums, expectSize, actualNums, actualSize, COMMON_FALSE);

    /* 释放内存 */
    free(actualNums);
}

/**
 * @description: Test 3
 * Input: nums = [1]
 * =================================================================================
 * @return {void}
 */
void Test3(void) {
    /* Function call (函数调用) */
    int nums[] = {1};
    int numsSize = ARR_SIZE(nums);
    int actualSize;
    int *actualNums = sortedSquares(nums, numsSize, &actualSize);

    /* Expect result (期望结果) */
    int expectNums[] = {1};
    int expectSize = ARR_SIZE(expectNums);

    /* 比较结果 */
    Validate_Array('3', expectNums, expectSize, actualNums, actualSize, COMMON_FALSE);

    /* 释放内存 */
    free(actualNums);
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
    Test1();
    Test2();
    Test3();
    return 0;
}