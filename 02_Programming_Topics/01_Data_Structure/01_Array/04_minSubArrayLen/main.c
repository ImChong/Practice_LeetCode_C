/*
 * @FilePath     : \Practice_LeetCode_C\01_Programming_Topics\01_Array\04_minSubArrayLen\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-29 14:54:54
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 209.长度最小的子数组：https://leetcode.cn/problems/minimum-size-subarray-sum/
 * https://programmercarl.com/0209.%E9%95%BF%E5%BA%A6%E6%9C%80%E5%B0%8F%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84.html
 */
/* standard header file (标准头文件) */

/* common function header file (通用头文件) */
#include "commonSingleValue.h"
#include "commonArray.h"
/* solution method configuration header file (解题方法配置文件) */

/* solution header file (题解头文件) */
#include "minSubArrayLen.h"

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
    int nums[] = {2, 3, 1, 2, 4, 3};
    int numsSize = ARR_SIZE(nums);
    int target = 7;
    int resultLen = minSubArrayLen(target, nums, numsSize);

    /* 预期结果 */
    int expectLen = 2;

    /* 比较结果 */
    validateSingleValue('1', expectLen, resultLen);
}

/**
 * @description: 测试 2
 * =================================================================================
 * @return {void}
 */
void Test2(void) {
    /* 实际结果 */
    int nums[] = {1, 1, 1, 1, 1, 1, 1, 1};
    int numsSize = ARR_SIZE(nums);
    int target = 11;
    int resultLen = minSubArrayLen(target, nums, numsSize);

    /* 预期结果 */
    int expectLen = 0;

    /* 比较结果 */
    validateSingleValue('2', expectLen, resultLen);
}

/**
 * @description: 测试 3
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    /* 实际结果 */
    int nums[] = {1, 2, 3, 4, 5};
    int numsSize = ARR_SIZE(nums);
    int target = 11;
    int resultLen = minSubArrayLen(target, nums, numsSize);

    /* 预期结果 */
    int expectLen = 3;

    /* 比较结果 */
    validateSingleValue('3', expectLen, resultLen);
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
    test_3();
    return 0;
}