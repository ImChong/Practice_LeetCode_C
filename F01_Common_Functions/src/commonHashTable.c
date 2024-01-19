/*
 * @FilePath     : \Practice_LeetCode_C\F01_Common_Functions\src\commonHashTable.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-22 13:36:07
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-19 09:05:47
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用哈希表源文件
 */
/* Common function configuration file (通用函数配置文件) */
#include "compileCfg.h"
#if COMMON_HASH_TABLE_EN /* whether compile this file, the definition of this macro can be found in compileCfg.h */
/* Header file (本文件头文件) */
#include "commonHashTable.h"
/* Standard header file (标准头文件) */
#include <stdio.h>
#include <stdlib.h>
/* Common function header file (通用头文件) */
#include "commonTypeDef.h"

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
    struct HashTable *newTable = (struct HashTable *)malloc(sizeof(struct HashTable));      /* 为哈希表分配空间 */
    newTable->size = size;      /* 设置哈希表大小 */
    newTable->slots = (struct HashNode **)malloc(sizeof(struct HashNode *) * size);     /* 为哈希节点分配空间 */
    for (int i = 0; i < size; i++) {        /* 遍历哈希表 */
        newTable->slots[i] = NULL;      /* 将哈希表的每个节点都设置为空 */
    }
    return newTable;        /* 返回哈希表 */
}

/**
 * @description: 获取元素值在哈希表中的槽位
 * =================================================================================
 * @param {HashTable} *table    哈希表
 * @param {int} value             元素值
 * @return {int} slot           槽位
 */
STATIC_FUNC int getHashSlot(struct HashTable *table, int value) {
    return abs(value) % table->size;      /* 获取元素值在哈希表中的槽位 */
}

/**
 * @description: 插入哈希元素
 * =================================================================================
 * @param {HashTable} *table    哈希表
 * @param {int} value             元素值
 * @param {int} index           元素索引（输入-1如果不需要索引）
 * @return {void}
 */
void HashTable_Insert(struct HashTable *table, int value, int index_or_counter, int isCounter) {
    /* FIXME: Change this function based on leetcode questions */
    int slot = value % table->size;
    struct HashNode *node = (struct HashNode *)malloc(sizeof(struct HashNode));
    node->value = value;
    if (isCounter) {
        node->counter = index_or_counter;
    } else {
        node->index = index_or_counter;
    }
    node->next = table->slots[slot];
    table->slots[slot] = node;
}

/**
 * @description: 查找哈希元素
 * =================================================================================
 * @param {HashTable} *table    哈希表
 * @param {int} value             元素值
 * @return {int} counter        元素个数
 */
int HashTable_Search(struct HashTable *table, int value) {
    int slot = getHashSlot(table, value);     /* 获取元素值在哈希表中的槽位 */
    struct HashNode *currentNode = table->slots[slot];      /* 获取哈希表的哈希节点 */
    int counter = 0;        /* 元素个数 */
    while (currentNode) {       /* 如果存在哈希节点，则遍历哈希节点 */
        if (currentNode->value == value) {      /* 如果哈希节点的键等于 value */
            counter += currentNode->counter;        /* 计算元素个数 */
        }
        currentNode = currentNode->next;        /* 否则，将哈希节点指向下一个节点 */
    }
    return counter;     /* 如果没有找到，返回 0 */
}

/**
 * @description: 删除哈希元素
 * =================================================================================
 * @param {HashTable} *table    哈希表
 * @param {int} value             元素值
 * @return {void}
 */
void HashTable_Remove(struct HashTable *table, int value) {
    int slot = getHashSlot(table, value);     /* 获取元素值在哈希表中的槽位 */
    struct HashNode *currentNode = table->slots[slot];      /* 获取哈希表的哈希节点 */
    struct HashNode *prevNode = NULL;       /* 前一个节点 */
    while (currentNode) {       /* 如果存在哈希节点，则遍历哈希节点 */
        if (currentNode->value == value) {      /* 如果哈希节点的键等于 value */
            if (prevNode) {     /* 如果前一个节点存在 */
                prevNode->next = currentNode->next;     /* 将前一个节点的下一个节点指向当前节点的下一个节点 */
            } else {        /* 如果前一个节点不存在 */
                table->slots[slot] = currentNode->next;     /* 将哈希表的哈希节点设置为当前节点的下一个节点 */
            }
            free(currentNode);      /* 释放当前节点 */
            return;     /* 返回 */
        }
        prevNode = currentNode;     /* 将前一个节点指向当前节点 */
        currentNode = currentNode->next;        /* 将哈希节点指向下一个节点 */
    }
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
        struct HashNode *currentNode = table->slots[i];
        while (currentNode) {
            if (currentNode->index == -1) {
                printf("%d (count: %d)", currentNode->value, currentNode->counter);
            } else {
                printf("%d (index: %d)", currentNode->value, currentNode->index);
            }
            printf(" -> ");
            currentNode = currentNode->next;
        }
        printf("Null\n");
    }
}

/**
 * @description: 释放哈希表
 * =================================================================================
 * @param {HashTable} *table    哈希表
 * @return {void}
 */
void HashTable_Free(struct HashTable *table) {
    for (int i = 0; i < table->size; i++) {     /* 遍历哈希表 */
        struct HashNode *currentNode = table->slots[i];     /* 获取哈希表的哈希节点 */
        while (currentNode) {       /* 遍历哈希节点 */
            struct HashNode *tmp = currentNode;     /* 临时节点 */
            currentNode = currentNode->next;        /* 将哈希节点指向下一个节点 */
            free(tmp);      /* 释放临时节点 */
        }
    }
    free(table->slots);     /* 释放哈希表的哈希列表 */
    free(table);        /* 释放哈希表 */
}


#endif  /* COMMON_HASH_TABLE_EN */
