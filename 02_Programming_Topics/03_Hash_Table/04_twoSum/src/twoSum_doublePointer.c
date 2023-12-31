/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\04_twoSum\src\twoSum_double_pointer.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-31 00:23:15
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-31 00:35:39
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 两数之和 - 双指针法源文件
 */
/* 解题方法配置文件 */
#include "methodCfg.h"
#if DOUBLE_POINTER_METHOD_EN
/* standard header file (标准头文件) */
#include <stdlib.h>
/* 本文件头文件 */
#include "twoSum.h"

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 两数之和
 * 这段代码是一个 C 语言函数，名为 twoSum，它接受四个参数：一个整型数组 nums，数组的大小 numsSize，一个目标整数 target，以及一个指向整数的指针 returnSize。
 *
 * 函数的作用是在数组 nums 中找到两个数，它们的和等于 target，并返回这两个数在数组中的下标。
 * 如果找不到这样的两个数，则返回 NULL。
 *
 * 函数使用了两个嵌套的 for 循环来遍历数组，找到符合条件的两个数。如果找到了，函数会动态分配一个长度为 2 的整型数组，将符合条件的两个数的下标存入数组中，并将 returnSize 指向的整数修改为 2，最后返回这个数组。
 * 如果找不到符合条件的两个数，则将 returnSize 指向的整数修改为 0，返回 NULL。
 * =================================================================================
 * @param {int} *nums           输入数组
 * @param {int} numsSize        输入数组长度
 * @param {int} target          目标值
 * @param {int} *returnSize     返回数组长度
 * @return {int} *result        返回数组
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    for (int i = 0; i < numsSize; i++) {                            /* 慢指针遍历数组 */
        for (int j = i + 1; j < numsSize; j++) {                        /* 快指针遍历数组，快指针恒大于慢指针 */
            if (nums[i] + nums[j] == target) {                              /* 如果快指针和慢指针所指的值和为target*/
                int *result = (int *)malloc(2 * sizeof(int));                   /* 为结果数组分配空间 */
                result[0] = i;                                                      /* 结果数组的第 0 位为慢指针 */
                result[1] = j;                                                      /* 结果数组的第 1 位为快指针 */
                *returnSize = 2;                                                    /* 将返回数组大小修改为2 */
                return result;                                                      /* 返回结果数组 */
            }
        }
    }
    *returnSize = 0;                                                /* 如果快慢指针所指的和没有等于target的情况，将返回数组大小修改为0 */
    return NULL;                                                    /* 返回 NULL*/
}

#endif  /* DOUBLE_POINTER_METHOD_EN */