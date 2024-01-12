/*
 * @FilePath     : \Practice_LeetCode_C\01_Programming_Topics\01_Array\03_sortedSquares\src\sortedSquares.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-12-28 17:25:06
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-29 10:22:56
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : solution source file
 */
/* Standard header file (标准头文件) */
#include <stdlib.h>
/* solution header file (题解头文件) */
#include "sortedSquares.h"

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 有序数组的平方
 * =================================================================================
 * @param {int} *nums           有序数组
 * @param {int} numsSize        数组大小
 * @param {int} *returnSize     返回数组大小
 * @return {int} *result        返回数组
 */
int *sortedSquares(int *nums, int numsSize, int *returnSize) {
    int *result = (int *)malloc(numsSize * sizeof(int));        /* 分配内存 */
    *returnSize = numsSize;                                     /* 返回数组大小 */

    int left = 0;                                               /* 左指针 */
    int right = numsSize - 1;                                   /* 右指针 */
    int index = numsSize - 1;                                   /* 返回数组索引 */

    while (left <= right) {                                     /* 循环条件：左指针小于等于右指针 */
        int leftSquare = nums[left] * nums[left];                   /* 左指针平方 */
        int rightSquare = nums[right] * nums[right];                /* 右指针平方 */

        if (leftSquare > rightSquare) {                             /* 左指针平方大于右指针平方 */
            result[index] = leftSquare;                                 /* 返回数组索引的值等于左指针平方 */
            left++;                                                     /* 左指针右移 */
        } else {                                                    /* 左指针平方小于等于右指针平方 */
            result[index] = rightSquare;                                /* 返回数组索引的值等于右指针平方 */
            right--;                                                    /* 右指针左移 */
        }
        index--;                                                    /* 返回数组索引左移 */
    }
    return result;                                              /* 返回数组 */
}
