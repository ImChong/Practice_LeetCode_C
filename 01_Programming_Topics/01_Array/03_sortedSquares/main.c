/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\01_Array\03_sortedSquares\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-18 14:28:43
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 977.有序数组的平方：https://leetcode.cn/problems/squares-of-a-sorted-array/
 * https://programmercarl.com/0977.%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E7%9A%84%E5%B9%B3%E6%96%B9.html
 */
/* 标准头文件 */
#include <stdio.h>
#include <stdlib.h>
/* 通用头文件 */
#include "commonTypeDef.h"
#include "commonArray.h"

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 有序数组的平方
 * =================================================================================
 * @param {int} *nums           有序数组
 * @param {int} numsSize        数组大小
 * @param {int} *returnSize     返回数组大小
 * @return {int} *result        返回数组
 */
int *sortedSquares(int *nums, int numsSize, int *returnSize) {
    int *result = (int *)malloc(numsSize * sizeof(int));        /* 分配内存 */
    *returnSize = numsSize;                                     /* 返回数组大小 */

    int left = 0;                                               /* 左指针 */
    int right = numsSize - 1;                                   /* 右指针 */
    int index = numsSize - 1;                                   /* 返回数组索引 */

    while (left <= right) {                                     /* 循环条件：左指针小于等于右指针 */
        int leftSquare = nums[left] * nums[left];                   /* 左指针平方 */
        int rightSquare = nums[right] * nums[right];                /* 右指针平方 */

        if (leftSquare > rightSquare) {                             /* 左指针平方大于右指针平方 */
            result[index] = leftSquare;                                 /* 返回数组索引的值等于左指针平方 */
            left++;                                                     /* 左指针右移 */
        } else {                                                    /* 左指针平方小于等于右指针平方 */
            result[index] = rightSquare;                                /* 返回数组索引的值等于右指针平方 */
            right--;                                                    /* 右指针左移 */
        }
        index--;                                                    /* 返回数组索引左移 */
    }
    return result;                                              /* 返回数组 */
}

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
void test_2(void) {
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
void test_3(void) {
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
    test_1();
    test_2();
    test_3();
    return 0;
}