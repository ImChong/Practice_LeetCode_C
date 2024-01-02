/*
 * @FilePath     : \Practice_LeetCode_C\01_Programming_Topics\01_Array\02_removeElement\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-29 10:16:42
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 27. 移除元素：https://leetcode.cn/problems/remove-element/
 *      https://programmercarl.com/0027.%E7%A7%BB%E9%99%A4%E5%85%83%E7%B4%A0.html
 */
/* standard header file (标准头文件) */
#include <stdio.h>
/* common function header file (通用头文件) */
#include "commonTypeDef.h"
#include "commonArray.h"
/* solution method configuration header file (解题方法配置文件) */

/* solution header file (题解头文件) */
#include "removeElement.h"

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
    int nums[] = {3, 2, 2, 3};
    int removeVal = 3;
    int resultLen = removeElement(nums, ARR_SIZE(nums), removeVal);

    /* 预期结果 */
    int expectNums[] = {2, 2};
    int expectLen = ARR_SIZE(expectNums);

    /* 比较结果 */
    validateArray('1', expectNums, expectLen, nums, resultLen, COMMON_FALSE);
}

/**
 * @description: 测试 2
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */
    int nums[] = {0, 1, 2, 2, 3, 0, 4, 2};
    int removeVal = 2;
    int resultLen = removeElement(nums, ARR_SIZE(nums), removeVal);

    /* 预期结果 */
    int expectNums[] = {0, 1, 3, 0, 4};
    int expectLen = ARR_SIZE(expectNums);

    /* 比较结果 */
    validateArray('2', expectNums, expectLen, nums, resultLen, COMMON_FALSE);
}

/**
 * @description: 测试 3
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    /* 实际结果 */
    int nums[] = {1};
    int removeVal = 2;
    int resultLen = removeElement(nums, ARR_SIZE(nums), removeVal);

    /* 预期结果 */
    int expectNums[] = {1};
    int expectLen = ARR_SIZE(expectNums);

    /* 比较结果 */
    validateArray('3', expectNums, expectLen, nums, resultLen, COMMON_FALSE);
}

/**
 * @description: 测试 4
 * =================================================================================
 * @return {void}
 */
void test_4(void) {
    /* 实际结果 */
    int nums[] = {1};
    int removeVal = 1;
    int resultLen = removeElement(nums, ARR_SIZE(nums), removeVal);

    /* 预期结果 */
    int expectNums[] = {};
    int expectLen = ARR_SIZE(expectNums);

    /* 比较结果 */
    validateArray('4', expectNums, expectLen, nums, resultLen, COMMON_FALSE);
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
    test_4();
    return 0;
};