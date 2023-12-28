/*
 * @FilePath     : \Practice_LeetCode_C\01_Programming_Topics\01_Array\02_removeElement\src\unitTest.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-12-28 11:47:42
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-28 12:29:41
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  :
 */
/* 标准头文件 */
#include <stdio.h>
/* 通用头文件 */
#include "commonTypeDef.h"
#include "commonArray.h"
/* 题解头文件 */
#include "removeElement.h"
/* 单元测试头文件 */
#include "unitTest.h"

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
