/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\08_fourSum\src\customHashTable.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-11-23 00:23:33
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-23 23:26:56
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 特殊哈希表源文件
 */
/* standard header file (标准头文件) */
#include <stdio.h>
#include <stdlib.h>
/* Common function configuration file (通用函数配置文件) */
#include "compileCfg.h"
/* solution header file (题解头文件) */
#include "customHashTable.h"

#if CUSTOM_HASH_TABLE_EN
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
struct HashTable *HashTable_Init(int size) {
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

/**
 * @description: 插入哈希元素
 * =================================================================================
 * @param {HashTable} *table    哈希表
 * @param {int} val             元素值
 * @param {int} index1          索引1
 * @param {int} index2          索引2
 * @return {void}
 */
void HashTable_Insert(struct HashTable *table, int val, int index1, int index2) {
    int slot = getHashSlot(table, val);                                                 /* 获取元素值在哈希表中的槽位 */
    struct HashNode *newNode = (struct HashNode *)malloc(sizeof(struct HashNode));      /* 为哈希节点分配空间 */
    newNode->sum = val;                                                                 /* 设置哈希节点的元素值 */
    newNode->index1 = index1;                                                           /* 设置哈希节点的索引1 */
    newNode->index2 = index2;                                                           /* 设置哈希节点的索引2 */
    newNode->next = table->hashSlots[slot];                                             /* 设置哈希节点的下一个节点 */
    table->hashSlots[slot] = newNode;                                                   /* 设置哈希表的哈希节点 */
}

/**
 * @description: 查找哈希表
 * =================================================================================
 * @param {HashTable} *table                哈希表
 * @param {int} val                         元素值
 * @return {struct HashNode} *currentNode   哈希节点
 */
struct HashNode *HashTable_Search(struct HashTable *table, int val)  {
    int slot = getHashSlot(table, val);                                                 /* 获取元素值在哈希表中的槽位 */
    struct HashNode *currentNode = table->hashSlots[slot];                              /* 获取哈希表的哈希节点 */
    while (currentNode) {                                                               /* 如果存在哈希节点，则遍历哈希节点 */
        if (currentNode->sum == val) {                                                      /* 如果哈希节点的键等于 val */
            return currentNode;                                                                 /* 返回哈希节点 */
        }
        currentNode = currentNode->next;                                                    /* 否则，将哈希节点指向下一个节点 */
    }
    return NULL;                                                                        /* 如果不存在哈希节点，返回 NULL */
}

/**
 * @description: 释放哈希表
 * =================================================================================
 * @param {HashTable} *table    哈希表
 * @return {void}
 */
void HashTable_Free(struct HashTable *table) {
    for (int i = 0; i < table->size; i++) {                                             /* 遍历哈希表 */
        struct HashNode *currentNode = table->hashSlots[i];                                 /* 获取哈希表的哈希节点 */
        while (currentNode) {                                                               /* 遍历哈希节点 */
            struct HashNode *tmp = currentNode;                                                 /* 临时节点 */
            currentNode = currentNode->next;                                                    /* 将哈希节点指向下一个节点 */
            free(tmp);                                                                          /* 释放临时节点 */
        }
    }
    free(table->hashSlots);                                                             /* 释放哈希表的哈希列表 */
    free(table);                                                                        /* 释放哈希表 */
}

/**
 * @description: 打印哈希表
 * =================================================================================
 * @param {HashTable} *table    哈希表
 * @return {void}
 */
void HashTable_Print(struct HashTable *table) {
    printf("Hash Table (slot size: %d):\n", table->size);
    for (int i = 0; i < table->size; i++) {
        printf("    Hash Slot [%d]: ", i);
        struct HashNode *currentNode = table->hashSlots[i];
        while (currentNode) {
            printf("[%d, (%d, %d)]", currentNode->sum, currentNode->index1, currentNode->index2);
            printf(" -> ");
            currentNode = currentNode->next;
        }
        printf("Null\n");
    }
}


#endif  /* SPECIAL_HASH_TABLE_EN */