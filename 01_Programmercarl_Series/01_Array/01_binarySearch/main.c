/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\01_Array\01_binarySearch\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-03 11:53:32
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 704. 二分查找：https://leetcode.cn/problems/binary-search/
 * https://programmercarl.com/0704.%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
 */
#include <stdio.h>

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
 * @return {int} ans
 */
int search(int *nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;

    while (left <= right) {                 /* 闭区间：当左指针 <= 右指针时持续运行 */
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {          /* 如果中间值等于目标：返回index */
            return mid;
        } else if (nums[mid] < target) {    /* 如果中间数小于目标值 */
            left = mid + 1;                 /* 左指针 + 1位 */
        } else {                            /* 如果中间数大于目标值 */
            right = mid - 1;                /* 右指针 - 1位  */
        }
    }
    return -1;
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
    int nums[] = {-1, 0, 3, 5, 9, 12};      /* 有序数组 */
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 0;

    int result = search(nums, numsSize, target);
    printf("Index of %d in the array: %d\n", target, result);

    return 0;
}