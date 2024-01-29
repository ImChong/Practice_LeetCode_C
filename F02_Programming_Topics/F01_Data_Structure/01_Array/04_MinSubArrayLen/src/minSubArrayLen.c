/*
 * @FilePath     : \Practice_LeetCode_C\01_Programming_Topics\01_Array\04_minSubArrayLen\src\minSubArrayLen.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-12-28 17:28:08
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-29 14:53:24
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : solution source file
 */
/* Standard header file (标准头文件) */
#include <limits.h>
/* solution header file (题解头文件) */
#include "minSubArrayLen.h"

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 长度最小的子数组
 * =================================================================================
 * @param {int} target      目标值
 * @param {int} *nums       数组
 * @param {int} numsSize    数组大小
 * @return {int} minLen     最小长度
 */
int minSubArrayLen(int target, int *nums, int numsSize) {
    int minLen = INT_MAX;                                   /* 记录最小长度 */
    int sum = 0;                                            /* 记录子数组的合 */

    int left = 0, right = 0;                                /* 初始化左右指针 */
    for (; right < numsSize; right++) {                     /* 遍历数组 */
        sum += nums[right];                                     /* 添加右侧数字 */
        while (sum >= target) {                                 /* 当sum大于target时 */
            int subLen = right - left + 1;                          /* 计算子长度*/
            minLen = minLen < subLen ? minLen : subLen;             /* 更新最小子长度 */
            sum -= nums[left++];                                    /* 去除左侧数字*/
        }
    }
    return minLen == INT_MAX ? 0 : minLen;                  /* 返回最小长度 */
}
