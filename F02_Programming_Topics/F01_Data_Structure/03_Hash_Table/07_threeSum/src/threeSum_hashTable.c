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
/* solution method configuration file (解题方法配置文件) */
#include "methodCfg.h"
#if HASH_TABLE_METHOD_EN
/* Standard header file (标准头文件) */
#include <stdlib.h>
/* Common function header file (通用头文件) */
#include "F01_Common_Functions/inc/common_array.h"
#include "common_hash_table.h"
/* solution header file (题解头文件) */
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
 * @param {int} arr_size                 数组大小
 * @param {int} *returnSize             返回数组大小
 * @param {int} **returnColumnSizes     返回数组列大小
 * @return {int} **ans                  返回数组
 */
int **threeSum(int *arr, int arr_size, int *returnSize, int **returnColumnSizes) {
    qsort(arr, arr_size, sizeof(int), Array_CmpElement);
    *returnSize = 0;
    *returnColumnSizes = (int *)malloc(sizeof(int) * arr_size * arr_size);
    int **ans = (int **)malloc(sizeof(int *) * arr_size * arr_size);
    for (int i = 0; i < arr_size; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }
        struct HashTable *table = HashTable_Init(arr_size);
        for (int j = i + 1; j < arr_size; j++) {
            int complement = -(arr[i] + arr[j]);
            if (HashTable_Search(table, complement)) {
                ans[*returnSize] = (int *)malloc(sizeof(int) * 3);
                ans[*returnSize][0] = arr[i];
                ans[*returnSize][1] = arr[j];
                ans[*returnSize][2] = complement;
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
                while (j + 1 < arr_size && arr[j] == arr[j + 1]) {
                    j++;
                }
            } else {
                HashTable_Insert(table, arr[j], j);
            }
        }
    }
    return ans;
}


#endif  /* HASH_TABLE_METHOD_EN */