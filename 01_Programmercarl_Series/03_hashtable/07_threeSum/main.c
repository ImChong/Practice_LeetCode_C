/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\07_threeSum\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-23 22:54:19
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-05 22:11:54
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
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 * =================================================================================
 * @return {void}
 */
void test_1(void) {
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
    validate2DArray('1', expect2DArr, expectRtnRowSize, expectRtnColSize, actual2DArr, actualRtnRowSize, actualRtnColSize);

    /* 释放内存 */
    free(actualRtnColSize);
    free2DArray(actual2DArr, actualRtnRowSize);
}

/**
 * @description: 测试 2
 * 输入：nums = [0,1,1]
 * 输出：[]
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
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
    validate2DArray('2', expect2DArr, expectRtnRowSize, expectRtnColSize, actual2DArr, actualRtnRowSize, actualRtnColSize);

    /* 释放内存 */
    free(actualRtnColSize);
    free2DArray(actual2DArr, actualRtnRowSize);
}

/**
 * @description: 测试 3
 * 输入：nums = [0,0,0]
 * 输出：[[0,0,0]]
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
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
    validate2DArray('3', expect2DArr, expectRtnRowSize, expectRtnColSize, actual2DArr, actualRtnRowSize, actualRtnColSize);

    /* 释放内存 */
    free(actualRtnColSize);
    free2DArray(actual2DArr, actualRtnRowSize);
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