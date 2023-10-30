/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\04_twoSum\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-10 23:39:22
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-31 00:34:04
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 1. 两数之和：https://leetcode.cn/problems/two-sum/
 * https://programmercarl.com/0001.%E4%B8%A4%E6%95%B0%E4%B9%8B%E5%92%8C.html
 * https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0001.%E4%B8%A4%E6%95%B0%E4%B9%8B%E5%92%8C.md
 */
/* 标准头文件 */
#include <stdio.h>
#include <stdlib.h>
/* 通用头文件 */
#include "commonArray.h"
/* 解题方法配置文件 */
#include "methodCfg.h"
#if DOUBLE_POINTER_METHOD_EN
#include "twoSum_double_pointer.h"
#elif HASH_TABLE_METHOD_EN
#include "twoSum_hash_table.h"
#endif

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试 1
 * 输入：nums = [2,7,11,15], target = 9
 * 输出：[0,1]
 * =================================================================================
 * @return {void}
 */
void test_1(void) {
    /* 实际结果 */
    int nums[] = {2, 7, 11, 15};
    int numsSize = ARR_SIZE(nums);
    int target = 9;
    int actualSize = 0;
    int *actual = twoSum(nums, numsSize, target, &actualSize);

    /* 预期结果 */
    int expect[] = {0, 1};
    int expectSize = ARR_SIZE(expect);

    /* 比较结果 */
    validateArray('1', expect, expectSize, actual, actualSize);

    /* 释放内存 */
    free(actual);
}

/**
 * @description: 测试 2
 * 输入：nums = [3,2,4], target = 6
 * 输出：[1,2]
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */
    int nums[] = {3, 2, 4};
    int numsSize = ARR_SIZE(nums);
    int target = 6;
    int actualSize = 0;
    int *actual = twoSum(nums, numsSize, target, &actualSize);

    /* 预期结果 */
    int expect[] = {1, 2};
    int expectSize = ARR_SIZE(expect);

    /* 比较结果 */
    validateArray('2', expect, expectSize, actual, actualSize);

    /* 释放内存 */
    free(actual);
}

/**
 * @description: 测试 3
 * 输入：nums = [3,3], target = 6
 * 输出：[0,1]
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    /* 实际结果 */
    int nums[] = {3, 3};
    int numsSize = ARR_SIZE(nums);
    int target = 6;
    int actualSize = 0;
    int *actual = twoSum(nums, numsSize, target, &actualSize);

    /* 预期结果 */
    int expect[] = {0, 1};
    int expectSize = ARR_SIZE(expect);

    /* 比较结果 */
    validateArray('3', expect, expectSize, actual, actualSize);

    /* 释放内存 */
    free(actual);
}

/**
 * @description: 测试 4
 * 输入：nums = [3,3], target = 7
 * 输出：NULL
 * =================================================================================
 * @return {void}
 */
void test_4(void) {
    /* 实际结果 */
    int nums[] = {3, 3};
    int numsSize = ARR_SIZE(nums);
    int target = 7;
    int actualSize = 0;
    int *actual = twoSum(nums, numsSize, target, &actualSize);

    /* 预期结果 */
    int *expect = NULL;
    int expectSize = 0;

    /* 比较结果 */
    validateArray('4', expect, expectSize, actual, actualSize);
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
int main(int argc, char const *argv[]) {
#if DOUBLE_POINTER_METHOD_EN
    printf("DOUBLE_POINTER_METHOD_EN\n");
#elif HASH_TABLE_METHOD_EN
    printf("HASH_TABLE_METHOD_EN\n");
#endif
    test_1();
    test_2();
    test_3();
    test_4();
    return 0;
}