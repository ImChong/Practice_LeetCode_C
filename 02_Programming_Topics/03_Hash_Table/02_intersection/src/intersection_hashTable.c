/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\02_intersection\src\intersection_hashTable.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-29 11:36:49
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-23 23:30:45
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 两个数组的交集 - 哈希表解法源文件
 */
/* solution method configuration file (解题方法配置文件) */
#include "methodCfg.h"
#if HASH_TABLE_METHOD_EN
/* standard header file (标准头文件) */
#include <stdlib.h>
#include <string.h>
/* common function header file (通用头文件) */
#include "commonHashTable.h"
/* solution header file (题解头文件) */
#include "intersection.h"

/**********************************************************************************/
/*                                                                                */
/*                                MACRO CONSTANTS                                 */
/*                                                                                */
/**********************************************************************************/
#define HASH_SIZE 10

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
    struct HashTable *hashTable = createHashTable(HASH_SIZE);
    for (int i = 0; i < numsASize; i++) {
        insertHashTable(hashTable, numsA[i], -1);
    }

    // printHashTable(hashTable);

    int *result = (int *)malloc(sizeof(int) * (numsASize < numsBSize ? numsASize : numsBSize));
    *returnSize = 0;
    for (int i = 0; i < numsBSize; i++) {
        if (searchHashTable(hashTable, numsB[i])) {
            result[(*returnSize)++] = numsB[i];
            removeHashTable(hashTable, numsB[i]);
        }
    }
    return result;
}

#endif  /* HASH_TABLE_METHOD_EN */