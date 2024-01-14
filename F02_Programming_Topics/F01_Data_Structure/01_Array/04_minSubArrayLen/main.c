/*
 * @FilePath     : \Practice_LeetCode_C\F02_Programming_Topics\F01_Data_Structure\01_Array\04_minSubArrayLen\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-15 02:18:08
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : leetcode 209.长度最小的子数组：https://leetcode.cn/problems/minimum-size-subarray-sum/
 * https://programmercarl.com/0209.%E9%95%BF%E5%BA%A6%E6%9C%80%E5%B0%8F%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84.html
 */
/* solution header file (题解头文件) */
#include "minSubArrayLen.h"
/* Standard header file (标准头文件) */
/* Common function header file (通用头文件) */
#include "commonSingleValue.h"
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
 * Input: target = 7, nums = [2, 3, 1, 2, 4, 3]
 * Outut: 2
 * =================================================================================
 * @return {void}
 */
void Test1(void) {
    /* 实际结果 */
    int nums[] = {2, 3, 1, 2, 4, 3};
    int numsSize = ARR_SIZE(nums);
    int target = 7;
    int actualLen = minSubArrayLen(target, nums, numsSize);

    /* 预期结果 */
    int expectLen = 2;

    /* 比较结果 */
    Validate_SingleValue('1', expectLen, actualLen);
}

/**
 * @description: Test 2
 * Input: target = 11, nums = [1, 1, 1, 1, 1, 1, 1, 1]
 * Outut: 0
 * =================================================================================
 * @return {void}
 */
void Test2(void) {
    /* 实际结果 */
    int nums[] = {1, 1, 1, 1, 1, 1, 1, 1};
    int numsSize = ARR_SIZE(nums);
    int target = 11;
    int actualLen = minSubArrayLen(target, nums, numsSize);

    /* 预期结果 */
    int expectLen = 0;

    /* 比较结果 */
    Validate_SingleValue('2', expectLen, actualLen);
}

/**
 * @description: Test 3
 * Input: target = 11, nums = [1, 2, 3, 4, 5]
 * Outut: 3
 * =================================================================================
 * @return {void}
 */
void Test3(void) {
    /* 实际结果 */
    int nums[] = {1, 2, 3, 4, 5};
    int numsSize = ARR_SIZE(nums);
    int target = 11;
    int actualLen = minSubArrayLen(target, nums, numsSize);

    /* 预期结果 */
    int expectLen = 3;

    /* 比较结果 */
    Validate_SingleValue('3', expectLen, actualLen);
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