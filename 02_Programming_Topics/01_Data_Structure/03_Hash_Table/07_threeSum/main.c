/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_hashtable\07_threeSum\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-23 22:54:19
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-21 00:07:15
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 15. 三数之和：https://leetcode.cn/problems/3sum/
 * https://programmercarl.com/0015.%E4%B8%89%E6%95%B0%E4%B9%8B%E5%92%8C.html
 * https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0015.%E4%B8%89%E6%95%B0%E4%B9%8B%E5%92%8C.md
 *
 * 给一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。
 */
/* standard header file (标准头文件) */
#include <stdio.h>
#include <stdlib.h>
/* common function header file (通用头文件) */
#include "commonTypeDef.h"
#include "commonArray.h"
/* solution method configuration file (解题方法配置文件) */
#include "methodCfg.h"
/* 解题方法头文件 */
#include "threeSum.h"

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试 1
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 * =================================================================================
 * @return {void}
 */
void Test1(void) {
    /* 实际结果 */
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int numsSize = ARR_SIZE(nums);
    int actualRtnRowSize = 0;
    int *actualRtnColSize;
    int **actual2DArr = threeSum(nums, numsSize, &actualRtnRowSize, &actualRtnColSize);

    /* 预期结果 */
    int expectRtnRowSize = 2;
    int expectRtnColSize[] = {3, 3};
    int *expect2DArr[] = {(int[]){-1, -1, 2}, (int[]){-1, 0, 1, 2}};    /* *expect2DArr[] 内数组可以不同长度 */

    /* 比较结果 */
    Validate2DArray('1', expect2DArr, expectRtnRowSize, expectRtnColSize, actual2DArr, actualRtnRowSize, actualRtnColSize, COMMON_TRUE);

    /* 释放内存 */
    free(actualRtnColSize);
    ArrayFree2D(actual2DArr, actualRtnRowSize);
}

/**
 * @description: 测试 2
 * 输入：nums = [0,1,1]
 * 输出：[]
 * =================================================================================
 * @return {void}
 */
void Test2(void) {
    /* 实际结果 */
    int nums[] = {0, 1, 1};
    int numsSize = ARR_SIZE(nums);
    int actualRtnRowSize = 0;
    int *actualRtnColSize;
    int **actual2DArr = threeSum(nums, numsSize, &actualRtnRowSize, &actualRtnColSize);

    /* 预期结果 */
    int expectRtnRowSize = 0;
    int expectRtnColSize[] = {};
    int *expect2DArr[] = {};

    /* 比较结果 */
    Validate2DArray('2', expect2DArr, expectRtnRowSize, expectRtnColSize, actual2DArr, actualRtnRowSize, actualRtnColSize, COMMON_TRUE);

    /* 释放内存 */
    free(actualRtnColSize);
    ArrayFree2D(actual2DArr, actualRtnRowSize);
}

/**
 * @description: 测试 3
 * 输入：nums = [0,0,0]
 * 输出：[[0,0,0]]
 * =================================================================================
 * @return {void}
 */
void Test3(void) {
    /* 实际结果 */
    int nums[] = {0, 0, 0};
    int numsSize = ARR_SIZE(nums);
    int actualRtnRowSize = 0;
    int *actualRtnColSize;
    int **actual2DArr = threeSum(nums, numsSize, &actualRtnRowSize, &actualRtnColSize);

    /* 预期结果 */
    int expectRtnRowSize = 1;
    int expectRtnColSize[] = {3};
    int *expect2DArr[] = {(int[]){0, 0, 0}};

    /* 比较结果 */
    Validate2DArray('3', expect2DArr, expectRtnRowSize, expectRtnColSize, actual2DArr, actualRtnRowSize, actualRtnColSize, COMMON_TRUE);

    /* 释放内存 */
    free(actualRtnColSize);
    ArrayFree2D(actual2DArr, actualRtnRowSize);
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