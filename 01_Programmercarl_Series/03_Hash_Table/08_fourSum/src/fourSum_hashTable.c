/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\08_fourSum\src\fourSum_hashTable.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-11-22 10:12:48
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-22 23:56:48
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 四数之和 - 哈希表
 */
#include "methodCfg.h"
#if HASH_TABLE_METHOD_EN
/* 标准头文件 */
#include <stdlib.h>
/* 通用头文件 */
#include "commonArray.h"
#include "commonHashTable.h"

/**********************************************************************************/
/*                                                                                */
/*                                MACRO CONSTANTS                                 */
/*                                                                                */
/**********************************************************************************/
#define HASH_SIZE     1000

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
    qsort(nums, numsSize, sizeof(int), compareElements);

    return 0;
}


#endif /* HASH_TABLE_METHOD_EN */