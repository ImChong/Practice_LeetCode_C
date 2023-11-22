/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\08_fourSum\src\fourSum_hashTable.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-11-22 10:12:48
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-23 00:55:49
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 四数之和 - 哈希表
 */
#include "methodCfg.h"
#if HASH_TABLE_METHOD_EN
/* 标准头文件 */
#include <stdio.h>
/* 特殊头文件 */
#include "specialHashTable.h"
/* 本文件头文件 */
#include "fourSum.h"

/**********************************************************************************/
/*                                                                                */
/*                                MACRO CONSTANTS                                 */
/*                                                                                */
/**********************************************************************************/
#define HASH_SIZE     100

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
    int **ans = (int **)malloc(sizeof(int *) * (*returnSize));   /* 为返回数组分配空间 */

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
                int remain = target - nums[i] - nums[j] - nums[k];         /* 计算另外一个数 */
                struct HashNode *node = searchHashTable(table, remain + nums[k]);
                if (node != NULL) {
                    (*returnSize)++;
                    *returnColumnSizes = (int *)realloc(*returnColumnSizes, sizeof(int) * (*returnSize)); /* 为返回数组列大小分配空间 */
                    (*returnColumnSizes)[(*returnSize) - 1] = 4;                /* 设置返回数组列大小 */
                    ans = (int **)realloc(ans, sizeof(int *) * (*returnSize)); /* 为返回数组分配空间 */
                    ans[(*returnSize) - 1] = (int *)malloc(sizeof(int) * 4);   /* 为返回数组的每一行分配空间 */
                    ans[(*returnSize) - 1][0] = nums[node->index1];             /* 设置返回数组的每一行的第一个元素 */
                    ans[(*returnSize) - 1][1] = nums[node->index2];             /* 设置返回数组的每一行的第二个元素 */
                    ans[(*returnSize) - 1][2] = nums[j];                        /* 设置返回数组的每一行的第三个元素 */
                    ans[(*returnSize) - 1][3] = nums[k];                        /* 设置返回数组的每一行的第四个元素 */
                }
            }
        }
    }
    return 0;
}


#endif /* HASH_TABLE_METHOD_EN */