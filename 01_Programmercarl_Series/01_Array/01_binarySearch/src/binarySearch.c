/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\01_Array\01_binarySearch\src\binarySearch.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-31 11:53:53
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-31 11:57:09
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 二分查找源文件
 */
#include "binarySearch.h"

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 二分查找
 * =================================================================================
 * @param {int} *nums       有序数组
 * @param {int} numsSize    数组大小
 * @param {int} target      目标值
 * @return {int} ans        目标值在数组中的索引
 */
int binarySearch(int *nums, int numsSize, int target) {
    int left = 0;                               /* 左指针 */
    int right = numsSize - 1;                   /* 右指针 */

    while (left <= right) {                     /* 循环条件：左指针小于等于右指针 */
        int mid = left + (right - left) / 2;        /* 中间指针 */

        if (nums[mid] == target) {                  /* 找到目标值 */
            return mid;                                 /* 返回索引 */
        } else if (nums[mid] < target) {            /* 目标值在右侧 */
            left = mid + 1;                             /* 左指针右移 */
        } else {                                    /* 目标值在左侧 */
            right = mid - 1;                            /* 右指针左移 */
        }
    }
    return -1;                                  /* 未找到目标值 */
}