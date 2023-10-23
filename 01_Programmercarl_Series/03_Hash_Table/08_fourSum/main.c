/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\08_fourSum\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-23 22:54:19
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-22 22:50:35
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 18. 四数之和：https://leetcode.cn/problems/4sum/
 * https://programmercarl.com/0018.%E5%9B%9B%E6%95%B0%E4%B9%8B%E5%92%8C.html
 * https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0018.%E5%9B%9B%E6%95%B0%E4%B9%8B%E5%92%8C.md
 */
#include <stdio.h>
#include "commonHelper.h"           /* 00_Basics\01_Common_Func\inc\commonHelper.h */

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description:
 * =================================================================================
 * @param {int} *nums
 * @param {int} numsSize
 * @param {int} target
 * @param {int} *returnSize
 * @param {int} **returnColumnSizes
 * @return {int} **ans
 */
int **fourSum(int *nums, int numsSize, int target, int *returnSize, int **returnColumnSizes){

    return NULL;
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

    /* 预期结果 */

    /* 比较结果 */

}

/**
 * @description: 测试 2
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */

    /* 预期结果 */

    /* 比较结果 */

}

/**
 * @description: 测试 3
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    /* 实际结果 */

    /* 预期结果 */

    /* 比较结果 */

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
int main(int argc, const char* argv[]) {
    // Test Case 1
    int nums1[] = {1, 0, -1, 0, -2, 2};
    int numsSize1 = 6;
    int target1 = 0;
    int returnSize1 = 0;
    int *expected1[] = {(int[]){-2, -1, 1, 2}, (int[]){-2, 0, 0, 2}, (int[]){-1, 0, 0, 1}};
    int expectedSizes1[] = {4, 4, 4};

    // Test Case 2
    int nums2[] = {0, 0, 0, 0};
    int numsSize2 = 4;
    int target2 = 0;
    int returnSize2 = 0;
    int *expected2[] = {(int[]){0, 0, 0, 0}};
    int expectedSizes2[] = {4};

    // Test Case 3
    int nums3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int numsSize3 = 10;
    int target3 = 20;
    int returnSize3 = 0;
    int *expected3[] = {(int[]){1, 2, 7, 10}, (int[]){1, 3, 6, 10}, (int[]){1, 4, 5, 10}, (int[]){1, 4, 6, 9}, (int[]){2, 3, 5, 10}, (int[]){2, 3, 6, 9}, (int[]){2, 4, 5, 9}, (int[]){3, 4, 5, 8}, (int[]){3, 4, 6, 7}};
    int expectedSizes3[] = {4, 4, 4, 4, 4, 4, 4, 4, 4};
    return 0;
}