/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\08_fourSum\src\fourSum_doublePointer.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-11-22 10:12:48
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-23 23:56:39
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 四数之和 - 双指针: https://leetcode.cn/problems/4sum/solutions/436368/si-shu-zhi-he-by-leetcode-solution/
 */
#include "methodCfg.h"
#if DOUBLE_POINTER_METHOD_EN
/* standard header file (标准头文件) */
#include <stdio.h>
#include <stdlib.h>
/* common function header file (通用头文件) */
#include "commonArray.h"
/* 本文件头文件 */
#include "fourSum.h"

/**********************************************************************************/
/*                                                                                */
/*                                MACRO CONSTANTS                                 */
/*                                                                                */
/**********************************************************************************/
#define NUM_SIZE        1000

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
    int **quadruplets = (int **)malloc(sizeof(int *) * NUM_SIZE);
    *returnSize = 0;
    *returnColumnSizes = (int *)malloc(sizeof(int) * NUM_SIZE);
    if (nums == NULL || numsSize < 4) {
        return quadruplets;
    }
    qsort(nums, numsSize, sizeof(int), compareElements);
    int len = numsSize;
    for (int i = 0; i < len - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
            break;
        }
        if (nums[i] + nums[len - 3] + nums[len - 2] + nums[len - 1] < target) {
            continue;
        }
        for (int j = i + 1; j < len - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue;
            }
            if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                break;
            }
            if (nums[i] + nums[j] + nums[len - 2] + nums[len - 1] < target) {
                continue;
            }
            int left = j + 1, right = len - 1;
            while (left < right) {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target) {
                    int *quad = (int *)malloc(sizeof(int) * 4);
                    quad[0] = nums[i];
                    quad[1] = nums[j];
                    quad[2] = nums[left];
                    quad[3] = nums[right];
                    quadruplets[*returnSize] = quad;
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    left++;
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }
    return quadruplets;
}


#endif /* DOUBLE_POINTER_METHOD_EN */