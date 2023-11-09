/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\02_intersection\src\intersection_hash_table.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-29 11:36:49
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-10 00:12:25
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
/* 本文件头文件 */
#include "intersection_hash_table.h"

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 创建哈希表
 * =================================================================================
 * @return {HashTable *} hashTable      哈希表
 */
HashTable *createHashTable(void) {
    HashTable *hashTable = (HashTable *)malloc(sizeof(HashTable));
    memset(hashTable, 0, sizeof(HashTable) * HASH_SIZE);
    return hashTable;
}

/**
 * @description: 在哈希表中插入元素
 * =================================================================================
 * @param {HashTable *} hashTable       哈希表
 * @param {int} key                     插入的元素值
 * @return {void}
 */
void insertHashTable(HashTable *hashTable, int key) {
    int hashKey = abs(key) % HASH_SIZE;
    HashNode *node = (HashNode *)malloc(sizeof(HashNode));
    node->key = key;
    node->next = hashTable->hashList[hashKey];
    hashTable->hashList[hashKey] = node;
}

/**
 * @description: 在哈希表中查找元素
 * =================================================================================
 * @param {HashTable *} hashTable
 * @param {int} key
 * @return {*}
 */
int searchHashTable(HashTable *hashTable, int key) {
    int hashKey = abs(key) % HASH_SIZE;
    HashNode *node = hashTable->hashList[hashKey];
    while (node) {
        if (node->key == key) {
            return 1;
        }
        node = node->next;
    }
    return 0;
}

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
 * @return {int} *res           返回结果数组
 */
int *intersection(int *numsA, int numsASize, int *numsB, int numsBSize, int *returnSize) {
    HashTable *hashTable = createHashTable();
    for (int i = 0; i < numsASize; i++) {
        insertHashTable(hashTable, numsA[i]);
    }
}

#endif  /* HASH_TABLE_METHOD_EN */