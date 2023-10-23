/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\08_fourSum\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-23 22:54:19
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-23 22:07:19
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 18. 四数之和：https://leetcode.cn/problems/4sum/
 * https://programmercarl.com/0018.%E5%9B%9B%E6%95%B0%E4%B9%8B%E5%92%8C.html
 * https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0018.%E5%9B%9B%E6%95%B0%E4%B9%8B%E5%92%8C.md
 *
 * 给一个由 n 个整数组成的数组 nums ，和一个目标值 target 。
 * 请找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
 *      0 <= a, b, c, d < n
 *      a、b、c 和 d 互不相同
 *      nums[a] + nums[b] + nums[c] + nums[d] == target
 *
 * 可以按 任意顺序 返回答案
 */
#include <stdio.h>
#include "commonHelper.h"           /* 00_Basics\01_Common_Func\inc\commonHelper.h */
#include "commonArray.h"            /* 00_Basics\01_Common_Func\inc\commonArray.h */

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 四数之和
 * =================================================================================
 * @param {int} *nums                   数组
 * @param {int} numsSize                数组大小
 * @param {int} target                  目标值
 * @param {int} *returnSize             返回数组大小
 * @param {int} **returnColumnSizes     返回数组列大小
 * @return {int} **ans                  返回数组
 */
int **fourSum(int *nums, int numsSize, int target, int *returnSize, int **returnColumnSizes) {

    return NULL;
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试 1
 * 输入：nums = [1,0,-1,0,-2,2], target = 0
 * 输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 * =================================================================================
 * @return {void}
 */
void test_1(void) {
    /* 实际结果 */
    int nums[] = {1, 0, -1, 0, -2, 2};

    /* 预期结果 */

    /* 比较结果 */


    // Test Case 1
    int nums1[] = {1, 0, -1, 0, -2, 2};
    int numsSize1 = 6;
    int target1 = 0;
    int returnSize1 = 0;
    int *expected1[] = {(int[]){-2, -1, 1, 2}, (int[]){-2, 0, 0, 2}, (int[]){-1, 0, 0, 1}};
    int expectedSizes1[] = {4, 4, 4};
}

/**
 * @description: 测试 2
 * 输入：nums = [2,2,2,2,2], target = 8
 * 输出：[[2,2,2,2]]
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
 * 输入：nums = [1,2,3,4,5,6,7,8,9,10], target = 20
 * 输出：[[1,2,7,10],[1,3,6,10],[1,4,5,10],[1,4,6,9],[2,3,5,10],[2,3,6,9],[2,4,5,9],[3,4,5,8],[3,4,6,7]]
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    /* 实际结果 */

    /* 预期结果 */

    /* 比较结果 */

    // Test Case 3
    int nums3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int numsSize3 = 10;
    int target3 = 20;
    int returnSize3 = 0;
    int *expected3[] = {(int[]){1, 2, 7, 10}, (int[]){1, 3, 6, 10}, (int[]){1, 4, 5, 10}, (int[]){1, 4, 6, 9}, (int[]){2, 3, 5, 10}, (int[]){2, 3, 6, 9}, (int[]){2, 4, 5, 9}, (int[]){3, 4, 5, 8}, (int[]){3, 4, 6, 7}};
    int expectedSizes3[] = {4, 4, 4, 4, 4, 4, 4, 4, 4};
    return 0;
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
    test_1();

    return 0;
}