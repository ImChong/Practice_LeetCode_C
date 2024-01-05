/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\05_fourSumCount\src\fourSumCount_hash_table.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-31 12:15:07
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-19 21:26:34
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 四数相加 - 哈希表法源文件
 */
/* solution method configuration file (解题方法配置文件) */
#include "methodCfg.h"
#if HASH_TABLE_METHOD_EN
/* common function header file (通用头文件) */
#include "commonHashTable.h"
/* solution header file (题解头文件) */
#include "fourSumCount.h"

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 四数相加 II
 * 这是一个C函数，名为fourSumCount，它接受八个参数：四个整数数组及其各自的大小。该函数返回一个整数值。
 *
 * 该函数首先使用自定义的哈希表数据结构创建一个哈希表。哈希表的大小为第一个和第二个输入数组大小的乘积的两倍。
 * 哈希表的目的是存储第一个和第二个输入数组中所有可能的整数对的和。
 * 该函数然后遍历第一个和第二个输入数组中的每个整数对，并将它们的和插入到哈希表中。
 *
 * 接下来，该函数将变量count初始化为0。
 * 该函数然后遍历最后两个输入数组中的每个整数对，并检查它们的和的负数是否存在于哈希表中。
 * 如果存在，则该函数将增加count变量的值。
 * 最后，该函数释放为哈希表分配的内存，并返回count变量的值。
 *
 * 该函数的目的是找到四元组（a，b，c，d），使得a + b + c + d = 0，其中a是第一个输入数组的元素，b是第二个输入数组的元素，c是第三个输入数组的元素，d是第四个输入数组的元素。
 * 该函数通过使用哈希表来存储第一个和第二个输入数组中所有可能的整数对的和来实现此目的。
 * 然后，该函数遍历最后两个输入数组中的每个整数对，并检查它们的和的负数是否存在于哈希表中。
 * 如果存在，则该函数将增加count变量的值。
 *
 * 为了提高此代码的可读性，该函数可以受益于更具描述性的变量名称。
 * 此外，可以添加注释以解释代码的每个部分的目的。
 * 在性能方面，哈希表大小可以进行优化，以减少冲突数量并提高查找时间。
 * =================================================================================
 * @param {int} *nums1          数组1
 * @param {int} nums1Size       数组1大小
 * @param {int} *nums2          数组2
 * @param {int} nums2Size       数组2大小
 * @param {int} *nums3          数组3
 * @param {int} nums3Size       数组3大小
 * @param {int} *nums4          数组4
 * @param {int} nums4Size       数组4大小
 * @return {int}                四元组之和为 0 的不同元组的个数
 */
int fourSumCount(int *nums1, int nums1Size, int *nums2, int nums2Size,
                    int *nums3, int nums3Size, int *nums4, int nums4Size) {
    struct HashTable *hashTable = HashTable_Init(2 * nums1Size * nums2Size);       /* 创建哈希表 */
    for (int i = 0; i < nums1Size; i++) {                                           /* 遍历数组1 */
        for (int j = 0; j < nums2Size; j++) {                                           /* 遍历数组2 */
            HashTable_Insert(hashTable, nums1[i] + nums2[j], -1);                            /* 将数组1和数组2的和插入哈希表 */
        }
    }

    // HashTable_Print(hashTable);                                                      /* 打印哈希表 */

    int count = 0;                                                                  /* 计数器 */
    for (int i = 0; i < nums3Size; i++) {                                               /* 遍历数组3 */
        for (int j = 0; j < nums4Size; j++) {                                               /* 遍历数组4 */
            count += HashTable_Search(hashTable, -1 * (nums3[i] + nums4[j]));                               /* 如果数组3和数组4的和的负数存在于哈希表中，计数器加 1 */
        }
    }

    HashTable_Free(hashTable);                                                       /* 释放哈希表 */
    return count;                                                                   /* 返回计数器 */
}

#endif /* HASH_TABLE_METHOD_EN */