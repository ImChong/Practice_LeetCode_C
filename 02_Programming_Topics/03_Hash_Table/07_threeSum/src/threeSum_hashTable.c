/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\07_threeSum\src\threeSum_hashTable.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-11-13 23:44:54
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-23 01:16:05
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 三数之和源文件 - 哈希表法
 */
/* 解题方法配置文件 */
#include "methodCfg.h"
#if HASH_TABLE_METHOD_EN
/* standard header file (标准头文件) */
#include <stdlib.h>
/* 通用头文件 */
#include "commonArray.h"
#include "commonHashTable.h"
/* 本文件头文件 */
#include "threeSum.h"

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 三数之和
 * =================================================================================
 * @param {int} *arr                    数组
 * @param {int} arrSize                 数组大小
 * @param {int} *returnSize             返回数组大小
 * @param {int} **returnColumnSizes     返回数组列大小
 * @return {int} **ans                  返回数组
 */
int **threeSum(int *arr, int arrSize, int *returnSize, int **returnColumnSizes) {
    qsort(arr, arrSize, sizeof(int), compareElements);
    *returnSize = 0;
    *returnColumnSizes = (int *)malloc(sizeof(int) * arrSize * arrSize);
    int **ans = (int **)malloc(sizeof(int *) * arrSize * arrSize);
    for (int i = 0; i < arrSize; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }
        struct HashTable *table = createHashTable(arrSize);
        for (int j = i + 1; j < arrSize; j++) {
            int complement = -(arr[i] + arr[j]);
            if (searchHashTable(table, complement)) {
                ans[*returnSize] = (int *)malloc(sizeof(int) * 3);
                ans[*returnSize][0] = arr[i];
                ans[*returnSize][1] = arr[j];
                ans[*returnSize][2] = complement;
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
                while (j + 1 < arrSize && arr[j] == arr[j + 1]) {
                    j++;
                }
            } else {
                insertHashTable(table, arr[j], j);
            }
        }
    }
    return ans;
}


#endif  /* HASH_TABLE_METHOD_EN */