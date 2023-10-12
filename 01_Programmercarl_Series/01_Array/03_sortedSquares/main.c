/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\01_Array\03_sortedSquares\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-12 23:39:32
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 977.有序数组的平方：https://leetcode.cn/problems/squares-of-a-sorted-array/
 * https://programmercarl.com/0977.%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E7%9A%84%E5%B9%B3%E6%96%B9.html
 */
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************************/
/*                                                                                */
/*                                MACRO FUNCTIONS                                 */
/*                                                                                */
/**********************************************************************************/
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))        /* 获取数组长度 */

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
    int *result = (int *)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    int left = 0;
    int right = numsSize - 1;
    int index = numsSize - 1;

    while (left <= right) {
        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];

        if (leftSquare > rightSquare) {
            result[index] = leftSquare;
            left++;
        } else {
            result[index] = rightSquare;
            right--;
        }
        index--;
    }
    return result;
}

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 验证答案
 * =================================================================================
 * @param {char} testNum        测试编号
 * @param {int} *expectNums     预期结果
 * @param {int} expectLen       预期结果长度
 * @param {int} *actualNums     实际结果
 * @param {int} actualLen       实际结果长度
 * @return {*}
 */
void validateAnswer(char testNum, int *expectNums, int expectLen, int *actualNums, int actualLen) {
    if (expectLen != actualLen) {
        printf("❌ Test %c Failed\n", testNum);
    } else {
        for (int i = 0; i < expectLen; i++) {
            if (expectNums[i] != actualNums[i]) {
                printf("❌ Test %c Failed\n", testNum);
            }
        }
        printf("✅ Test %c Passed\n", testNum);
    }
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
    int numsSize = ARRAY_SIZE(nums);
    int returnSize;
    int *returnNums = sortedSquares(nums, numsSize, &returnSize);

    /* 预期结果 */
    int expectNums[] = {0, 1, 9, 16, 100};
    int expectSize = ARRAY_SIZE(expectNums);

    /* 比较结果 */
    validateAnswer('1', expectNums, expectSize, returnNums, returnSize);

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
    int numsSize = ARRAY_SIZE(nums);
    int returnSize;
    int *returnNums = sortedSquares(nums, numsSize, &returnSize);

    /* 预期结果 */
    int expectNums[] = {4, 9, 9, 49, 121};
    int expectSize = ARRAY_SIZE(expectNums);

    /* 比较结果 */
    validateAnswer('2', expectNums, expectSize, returnNums, returnSize);

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
    int numsSize = ARRAY_SIZE(nums);
    int returnSize;
    int *returnNums = sortedSquares(nums, numsSize, &returnSize);

    /* 预期结果 */
    int expectNums[] = {1};
    int expectSize = ARRAY_SIZE(expectNums);

    /* 比较结果 */
    validateAnswer('3', expectNums, expectSize, returnNums, returnSize);

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