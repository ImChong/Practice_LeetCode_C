/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\08_fourSum\src\specialHashTable.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-11-23 00:23:33
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-23 00:35:54
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 特殊哈希表源文件
 */
/* 标准头文件 */
#include <stdio.h>
/* 本文件头文件 */
#include "specialHashTable.h"

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 创建哈希表
 * =================================================================================
 * @param {int} size                        哈希表大小
 * @return {struct HashTable} *newTable     哈希表
 */
struct HashTable *createHashTable(int size) {
    struct HashTable *newTable = (struct HashTable *)malloc(sizeof(struct HashTable));
    newTable->size = size;
    newTable->hashSlots = (struct HashNode **)malloc(sizeof(struct HashNode *) * size);
    for (int i = 0; i < size; i++) {
        newTable->hashSlots[i] = NULL;
    }
    return newTable;
}

/**
 * @description: 获取元素值在哈希表中的槽位
 * =================================================================================
 * @param {HashTable} *table    哈希表
 * @param {int} val             元素值
 * @return {int} slot           槽位
 */
int getHashSlot(struct HashTable *table, int val) {
    return abs(val) % table->size;                                                      /* 获取元素值在哈希表中的槽位 */
}