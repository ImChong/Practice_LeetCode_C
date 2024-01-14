/*
 * @FilePath     : \Practice_LeetCode_C\F02_Programming_Topics\F01_Data_Structure\01_Array\01_binarySearch\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2024-01-10 11:06:55
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-15 02:11:12
 * =================================================================================
 * Copyright (c) 2024 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : leetcode 704. 二分查找：https://leetcode.cn/problems/binary-search/
 *      https://programmercarl.com/0704.%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
 */
/* solution header file (题解头文件) */
#include "binarySearch.h"
/* Standard header file (标准头文件) */
#include <stdio.h>
/* Common function header file (通用头文件) */
#include "commonArray.h"
#include "commonSingleValue.h"
/* solution method configuration file (解题方法配置文件) */
// #include "methodCfg"     /* Uncomment this line if solution has multiple methods */

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: Test 1
 * Input: nums = [-1, 0, 3, 5, 9, 12], target = 9
 * Outut: 4
 * =================================================================================
 * @return {void}
 */
void Test1(void) {
    /* Function call (函数调用) */
    int nums[] = {-1, 0, 3, 5, 9, 12}; /* Sorted array */
    int target = 9;
    int actual = binarySearch(nums, ARR_SIZE(nums), target);

    /* Expect result (期望结果) */
    int expect = 4;

    /* 比较结果 */
    Validate_SingleValue('1', expect, actual);
}

/**
 * @description: Test 2
 * Input: nums = [-1, 0, 3, 5, 9, 12], target = 2
 * Outut: -1
 * =================================================================================
 * @return {void}
 */
void Test2(void) {
    /* Function call (函数调用) */
    int nums[] = {-1, 0, 3, 5, 9, 12}; /* Sorted array */
    int target = 2;
    int actual = binarySearch(nums, ARR_SIZE(nums), target);

    /* Expect result (期望结果) */
    int expect = -1;

    /* 比较结果 */
    Validate_SingleValue('2', expect, actual);
}

/**
 * @description: Test 2
 * Input: nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], target = 5
 * Outut: 4
 * =================================================================================
 * @return {void}
 */
void Test3(void) {
    /* Function call (函数调用) */
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; /* Sorted array */
    int target = 5;
    int actual = binarySearch(nums, ARR_SIZE(nums), target);

    /* Expect result (期望结果) */
    int expect = 4;

    /* 比较结果 */
    Validate_SingleValue('3', expect, actual);
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