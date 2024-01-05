/*
 * @FilePath     : \Practice_LeetCode_C\02_Programming_Topics\01_Data_Structure\01_Array\03_sortedSquares\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-05 17:24:28
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 977.有序数组的平方：https://leetcode.cn/problems/squares-of-a-sorted-array/
 *      https://programmercarl.com/0977.%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E7%9A%84%E5%B9%B3%E6%96%B9.html
 */
/* standard header file (标准头文件) */
#include <stdlib.h>
/* common function header file (通用头文件) */
#include "commonTypeDef.h"
#include "commonArray.h"
/* solution method configuration header file (解题方法配置文件) */
/* solution header file (题解头文件) */
#include "sortedSquares.h"

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
void Test1(void) {
    /* 实际结果 */
    int nums[] = {-4, -1, 0, 3, 10};
    int numsSize = ARR_SIZE(nums);
    int returnSize;
    int *returnNums = sortedSquares(nums, numsSize, &returnSize);

    /* 预期结果 */
    int expectNums[] = {0, 1, 9, 16, 100};
    int expectSize = ARR_SIZE(expectNums);

    /* 比较结果 */
    validateArray('1', expectNums, expectSize, returnNums, returnSize, COMMON_FALSE);

    /* 释放内存 */
    free(returnNums);
}

/**
 * @description: 测试 2
 * =================================================================================
 * @return {void}
 */
void Test2(void) {
    /* 实际结果 */
    int nums[] = {-7, -3, 2, 3, 11};
    int numsSize = ARR_SIZE(nums);
    int returnSize;
    int *returnNums = sortedSquares(nums, numsSize, &returnSize);

    /* 预期结果 */
    int expectNums[] = {4, 9, 9, 49, 121};
    int expectSize = ARR_SIZE(expectNums);

    /* 比较结果 */
    validateArray('2', expectNums, expectSize, returnNums, returnSize, COMMON_FALSE);

    /* 释放内存 */
    free(returnNums);
}

/**
 * @description: 测试 3
 * =================================================================================
 * @return {void}
 */
void Test3(void) {
    /* 实际结果 */
    int nums[] = {1};
    int numsSize = ARR_SIZE(nums);
    int returnSize;
    int *returnNums = sortedSquares(nums, numsSize, &returnSize);

    /* 预期结果 */
    int expectNums[] = {1};
    int expectSize = ARR_SIZE(expectNums);

    /* 比较结果 */
    validateArray('3', expectNums, expectSize, returnNums, returnSize, COMMON_FALSE);

    /* 释放内存 */
    free(returnNums);
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