/*
 * @FilePath     : \Practice_LeetCode_C\01_Programming_Topics\01_Array\01_binarySearch\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-29 10:05:35
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 704. 二分查找：https://leetcode.cn/problems/binary-search/
 *      https://programmercarl.com/0704.%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
 */
/* standard header file (标准头文件) */
#include <stdio.h>
/* common function header file (通用头文件) */
#include "commonSingleValue.h"
#include "commonArray.h"
/* solution method configuration header file (解题方法配置文件) */

/* solution header file (题解头文件) */
#include "binarySearch.h"

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
    int nums[] = {-1, 0, 3, 5, 9, 12};                  /* 有序数组 */
    int numsSize = ARR_SIZE(nums);
    int target = 9;
    int ans = binarySearch(nums, numsSize, target);

    /* 预期结果 */
    int expect = 4;

    /* 比较结果 */
    validateSingleValue('1', expect, ans);
}

/**
 * @description: 测试 2
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */
    int nums[] = {-1, 0, 3, 5, 9, 12};                  /* 有序数组 */
    int numsSize = ARR_SIZE(nums);
    int target = 2;
    int ans = binarySearch(nums, numsSize, target);

    /* 预期结果 */
    int expect = -1;

    /* 比较结果 */
    validateSingleValue('2', expect, ans);
}

/**
 * @description: 测试 3
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    /* 实际结果 */
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};       /* 有序数组 */
    int numsSize = ARR_SIZE(nums);
    int target = 5;
    int ans = binarySearch(nums, numsSize, target);

    /* 预期结果 */
    int expect = 4;

    /* 比较结果 */
    validateSingleValue('3', expect, ans);
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