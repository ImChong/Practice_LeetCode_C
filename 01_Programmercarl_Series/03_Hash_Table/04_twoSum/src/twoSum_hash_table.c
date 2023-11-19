/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\04_twoSum\src\twoSum_hash_table.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-31 00:23:15
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-19 21:20:41
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 两数之和 - 哈希表法源文件
 */
/* 解题方法配置文件 */
#include "methodCfg.h"
#if HASH_TABLE_METHOD_EN
/* 标准头文件 */
#include <stdio.h>
#include <stdlib.h>
/* 通用头文件 */
#include "commonHashTable.h"
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
 * =================================================================================
 * @param {int} *nums           输入数组
 * @param {int} numsSize        输入数组长度
 * @param {int} target          目标值
 * @param {int} *returnSize     返回数组长度
 * @return {int} *result        返回数组
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    struct HashTable *table = createHashTable(numsSize);
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int slot = getHashSlot(table, complement);
        struct HashNode *currentNode = table->hashSlots[slot];
        while (currentNode) {
            if (currentNode->val == complement) {
                int *result = (int *)malloc(sizeof(int) * 2);
                result[0] = currentNode->index;
                result[1] = i;
                *returnSize = 2;
                return result;
            }
            currentNode = currentNode->next;
        }
        insertHashTable(table, nums[i], i);
    }
    // printHashTable(table);
    *returnSize = 0;
    return NULL;
}

#endif  /* HASH_TABLE_METHOD_EN */