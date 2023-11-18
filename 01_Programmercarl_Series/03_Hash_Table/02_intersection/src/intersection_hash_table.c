/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\02_intersection\src\intersection_hash_table.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-29 11:36:49
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-18 16:03:55
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 两个数组的交集 - 哈希表解法源文件
 */
/* 解题方法配置文件 */
#include "methodCfg.h"
#if HASH_TABLE_METHOD_EN
/* 标准头文件 */
#include <stdlib.h>
#include <string.h>
/* 通用头文件 */
#include "commonHashTable.h"
/* 本文件头文件 */
#include "intersection_hash_table.h"

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 两个数组的交集
 * =================================================================================
 * @param {int} *numsA          数组1
 * @param {int} numsASize       数组1大小
 * @param {int} *numsB          数组2
 * @param {int} numsBSize       数组2大小
 * @param {int} *returnSize     返回数组大小
 * @return {int} *result        返回结果数组
 */
int *intersection(int *numsA, int numsASize, int *numsB, int numsBSize, int *returnSize) {
    struct HashTable *hashTable = createHashTable(HASH_SLOT_SIZE);
    for (int i = 0; i < numsASize; i++) {
        insertHashTable(hashTable, numsA[i]);
    }

    printHashTable(hashTable);

    int *result = (int *)malloc(sizeof(int) * (numsASize < numsBSize ? numsASize : numsBSize));
    *returnSize = 0;
    for (int i = 0; i < numsBSize; i++) {
        if (searchHashTable(hashTable, numsB[i])) {
            result[(*returnSize)++] = numsB[i];
            hashTable->hashList[abs(numsB[i]) % HASH_SLOT_SIZE] = NULL;
        }
    }
    return result;
}

#endif  /* HASH_TABLE_METHOD_EN */