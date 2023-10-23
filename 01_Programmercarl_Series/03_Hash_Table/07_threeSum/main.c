/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\07_threeSum\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-23 22:54:19
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-23 15:17:42
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 15. 三数之和：https://leetcode.cn/problems/3sum/
 * https://programmercarl.com/0015.%E4%B8%89%E6%95%B0%E4%B9%8B%E5%92%8C.html
 * https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0015.%E4%B8%89%E6%95%B0%E4%B9%8B%E5%92%8C.md
 *
 * 给一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。
 *
 */
#include <stdio.h>
#include <stdlib.h>
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
 * @description: 比较函数
 * =================================================================================
 * @param {void} *a     a项
 * @param {void} *b     b项
 * @return {int}        比较结果
 */
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

/**
 * @description: 三数之和
 * =================================================================================
 * @param {int} *arr                    数组
 * @param {int} arrSize                 数组大小
 * @param {int} *returnSize             返回数组大小
 * @param {int} **returnColumnSizes     返回数组列大小
 * @return {int} **ans                  返回数组
 */
int **threeSum(int *arr, int arrSize, int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;
    if (arrSize < 3) {
        return NULL;
    }
    qsort(arr, arrSize, sizeof(int), cmp);
    int **ans = (int **)malloc(sizeof(int *) * arrSize * arrSize);
    *returnColumnSizes = (int *)malloc(sizeof(int) * arrSize * arrSize);
    int i, j, k, sum;

    int indexLeft = 0;
    int indexMiddle = 0;
    int indexRight = 0;

    for (indexLeft = 0; indexLeft < arrSize - 2; indexLeft++) {
        if (arr[indexLeft] > 0) {
            return ans;
        }

        if (indexLeft > 0 && arr[indexLeft] == arr[indexLeft - 1]) {
            continue;
        }
        indexMiddle = indexLeft + 1;
        indexRight = arrSize - 1;

        while (indexMiddle < indexRight) {
            sum = arr[indexLeft] + arr[indexMiddle] + arr[indexRight];
            if (sum == 0) {
                ans[*returnSize] = (int*)malloc(sizeof(int) * 3);
                (*returnColumnSizes)[*returnSize] = 3;
                ans[*returnSize][0] = arr[indexLeft];
                ans[*returnSize][1] = arr[indexMiddle];
                ans[*returnSize][2] = arr[indexRight];
                *returnSize += 1;
                while (indexMiddle < indexRight && arr[indexMiddle] == arr[++indexMiddle]);
                while (indexMiddle < indexRight && arr[indexRight] == arr[--indexRight]);
            } else if (sum > 0) {
                indexRight--;
            } else {
                indexMiddle++;
            }
        }
    }
    return ans;
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
    int nums =

    /* 预期结果 */

    /* 比较结果 */

    // Test Case 1
    int nums1[] = {-1, 0, 1, 2, -1, -4};
    int numsSize1 = 6;
    int returnSize1 = 0;
    int *expected1[] = {(int[]){-1, -1, 2}, (int[]){-1, 0, 1}};
    int expectedSizes1[] = {3, 3};
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


    // Test Case 2
    int nums2[] = {0, 0, 0, 0};
    int numsSize2 = 4;
    int returnSize2 = 0;
    int *expected2[] = {(int[]){0, 0, 0}};
    int expectedSizes2[] = {3};
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

    // Test Case 3
    int nums3[] = {1, 2, -2, -1};
    int numsSize3 = 4;
    int returnSize3 = 0;
    int *expected3[] = {};
    int expectedSizes3[] = {0};
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
int main(int argc, const char *argv[]) {





}