/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\04_twoSum\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-10 23:39:22
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-18 19:55:36
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 1. 两数之和：https://leetcode.cn/problems/two-sum/
 * https://programmercarl.com/0001.%E4%B8%A4%E6%95%B0%E4%B9%8B%E5%92%8C.html
 * https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0001.%E4%B8%A4%E6%95%B0%E4%B9%8B%E5%92%8C.md
 */
/* Standard header file (标准头文件) */
#include <stdio.h>
#include <stdlib.h>
/* Common function header file (通用头文件) */
#include "F01_Common_Functions/inc/common_def/common_type_def.h"
#include "F01_Common_Functions/inc/common_array.h"
/* solution method configuration file (解题方法配置文件) */
#include "methodCfg.h"
/* solution header file (题解头文件) */
#include "twoSum.h"

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: Test 1
 * 输入：nums = [2,7,11,15], target = 9
 * 输出：[0,1]
 * =================================================================================
 * @return {void}
 */
void Test1(void) {
    /* Function call (函数调用) */
    int nums[] = {2, 7, 11, 15};
    int numsSize = ARR_SIZE(nums);
    int target = 9;
    int actualSize = 0;
    int *actual = twoSum(nums, numsSize, target, &actualSize);

    /* Expect result (期望结果) */
    int expect[] = {0, 1};
    int expectSize = ARR_SIZE(expect);

    /* Validate result (验证函数调用结果) */
    Validate_Array('1', expect, expectSize, actual, actualSize, COMMON_FALSE);

    /* Free memory (释放内存) */
    free(actual);
}

/**
 * @description: Test 2
 * 输入：nums = [3,2,4], target = 6
 * 输出：[1,2]
 * =================================================================================
 * @return {void}
 */
void Test2(void) {
    /* Function call (函数调用) */
    int nums[] = {3, 2, 4};
    int numsSize = ARR_SIZE(nums);
    int target = 6;
    int actualSize = 0;
    int *actual = twoSum(nums, numsSize, target, &actualSize);

    /* Expect result (期望结果) */
    int expect[] = {1, 2};
    int expectSize = ARR_SIZE(expect);

    /* Validate result (验证函数调用结果) */
    Validate_Array('2', expect, expectSize, actual, actualSize, COMMON_FALSE);

    /* Free memory (释放内存) */
    free(actual);
}

/**
 * @description: Test 3
 * 输入：nums = [3,3], target = 6
 * 输出：[0,1]
 * =================================================================================
 * @return {void}
 */
void Test3(void) {
    /* Function call (函数调用) */
    int nums[] = {3, 3};
    int numsSize = ARR_SIZE(nums);
    int target = 6;
    int actualSize = 0;
    int *actual = twoSum(nums, numsSize, target, &actualSize);

    /* Expect result (期望结果) */
    int expect[] = {0, 1};
    int expectSize = ARR_SIZE(expect);

    /* Validate result (验证函数调用结果) */
    Validate_Array('3', expect, expectSize, actual, actualSize, COMMON_FALSE);

    /* Free memory (释放内存) */
    free(actual);
}

/**
 * @description: 测试 4
 * 输入：nums = [3,3], target = 7
 * 输出：NULL
 * =================================================================================
 * @return {void}
 */
void Test4(void) {
    /* Function call (函数调用) */
    int nums[] = {3, 3};
    int numsSize = ARR_SIZE(nums);
    int target = 7;
    int actualSize = 0;
    int *actual = twoSum(nums, numsSize, target, &actualSize);

    /* Expect result (期望结果) */
    int *expect = NULL;
    int expectSize = 0;

    /* Validate result (验证函数调用结果) */
    Validate_Array('4', expect, expectSize, actual, actualSize, COMMON_FALSE);
}

/**********************************************************************************/
/*                                                                                */
/*                                  MAIN FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: Main function, entry of program.
 * =================================================================================
 * @param {int} argc        程序入参个数
 * @param {char} *argv[]    程序入参字符串数组
 * @return {int}            程序运行状态
 */
int main(int argc, char const *argv[]) {
#if DOUBLE_POINTER_METHOD_EN
    printf("DOUBLE_POINTER_METHOD_EN\r\n");
#elif HASH_TABLE_METHOD_EN
    printf("HASH_TABLE_METHOD_EN\r\n");
#endif
    Test1();
    Test2();
    Test3();
    Test4();
    return 0;
}