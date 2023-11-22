/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\08_fourSum\src\fourSum_hashTable.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-11-22 10:12:48
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-23 01:06:30
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 四数之和 - 哈希表
 */
#include "methodCfg.h"
#if HASH_TABLE_METHOD_EN
/* 标准头文件 */
#include <stdio.h>
#include <stdlib.h>
/* 特殊头文件 */
#include "specialHashTable.h"
/* 本文件头文件 */
#include "fourSum.h"

/**********************************************************************************/
/*                                                                                */
/*                                MACRO CONSTANTS                                 */
/*                                                                                */
/**********************************************************************************/
#define HASH_SIZE     20

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
    *returnSize = 0;
    int **ans = (int **)malloc(sizeof(int *) * HASH_SIZE);   /* 为返回数组分配空间 */
    *returnColumnSizes = (int *)malloc(sizeof(int) * HASH_SIZE); /* 为返回数组列大小分配空间 */

    struct HashTable *table = createHashTable(HASH_SIZE);       /* 创建哈希表 */
    for (int i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {                      /* 去重 */
            continue;
        }
        for (int j = i + 1; j < numsSize - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) {                  /* 去重 */
                continue;
            }
            insertHashTable(table, nums[i] + nums[j], i, j);            /* 插入哈希节点 */
            for (int k = j + 1; k < numsSize - 1; k++) {
                if (k > j + 1 && nums[k] == nums[k - 1]) {                  /* 去重 */
                    continue;
                }
                for (int l = k + 1; l < numsSize; l++) {
                    if (l > k + 1 && nums[l] == nums[l - 1]) {                  /* 去重 */
                        continue;
                    }
                    struct HashNode *node = searchHashTable(table, target - nums[k] - nums[l]);
                    if (node) {
                        ans[*returnSize] = (int *)malloc(sizeof(int) * 4);
                        ans[*returnSize][0] = nums[node->index1];
                        ans[*returnSize][1] = nums[node->index2];
                        ans[*returnSize][2] = nums[k];
                        ans[*returnSize][3] = nums[l];
                        (*returnColumnSizes)[*returnSize] = 4;
                        (*returnSize)++;
                    }
                }
            }
        }
    }

    printHashTable(table);  /* 打印哈希表 */
    freeHashTable(table);   /* 释放哈希表 */
    return NULL;
}


#endif /* HASH_TABLE_METHOD_EN */