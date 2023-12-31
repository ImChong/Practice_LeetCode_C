/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\src\commonHashTable.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-22 13:36:07
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-15 23:25:01
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用哈希表源文件
 */
/* 编译配置文件 */
#include "compileCfg.h"
#if COMMON_HASH_TABLE_EN    /* 在每一道题 cfg 文件夹下的 compileCfg.h 开启编译宏定义 */
/* standard header file (标准头文件) */
#include <stdio.h>
#include <stdlib.h>
/* 常用头文件 */
#include "commonTypeDef.h"
#include "commonHashTable.h"

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
    struct HashTable *newTable = (struct HashTable *)malloc(sizeof(struct HashTable));      /* 为哈希表分配空间 */
    newTable->size = size;      /* 设置哈希表大小 */
    newTable->hashSlots = (struct HashNode **)malloc(sizeof(struct HashNode *) * size);     /* 为哈希节点分配空间 */
    for (int i = 0; i < size; i++) {        /* 遍历哈希表 */
        newTable->hashSlots[i] = NULL;      /* 将哈希表的每个节点都设置为空 */
    }
    return newTable;        /* 返回哈希表 */
}

/**
 * @description: 获取元素值在哈希表中的槽位
 * =================================================================================
 * @param {HashTable} *table    哈希表
 * @param {int} val             元素值
 * @return {int} slot           槽位
 */
STATIC_FUNC int getHashSlot(struct HashTable *table, int val) {
    return abs(val) % table->size;      /* 获取元素值在哈希表中的槽位 */
}

/**
 * @description: 插入哈希元素
 * =================================================================================
 * @param {HashTable} *table    哈希表
 * @param {int} val             元素值
 * @param {int} index           元素索引（输入-1如果不需要索引）
 * @return {void}
 */
void insertHashTable(struct HashTable *table, int val, int index) {
    int slot = getHashSlot(table, val);     /* 获取元素值在哈希表中的槽位 */
    struct HashNode *currentNode = table->hashSlots[slot];      /* 获取哈希表的哈希节点 */
    while (currentNode) {       /* 如果存在哈希节点，则遍历哈希节点 */
        if (currentNode->val == val && currentNode->index == index) {       /* 如果哈希节点的键等于 val */
            currentNode->counter++;     /* 元素个数 + 1 */
            return;     /* 返回 */
        }
        currentNode = currentNode->next;        /* 否则，将哈希节点指向下一个节点 */
    }
    struct HashNode *newNode = (struct HashNode *)malloc(sizeof(struct HashNode));  /* 为新节点分配空间 */
    newNode->val = val;     /* 设置新节点的值 */
    newNode->counter = 1;       /* 元素个数初始化为 1 */
    newNode->index = index;     /* 设置新节点的索引 */
    newNode->next = table->hashSlots[slot];     /* 将新节点的下一个节点指向哈希表的哈希节点 */
    table->hashSlots[slot] = newNode;       /* 将哈希表的哈希节点设置为新节点 */
}

/**
 * @description: 查找哈希元素
 * =================================================================================
 * @param {HashTable} *table    哈希表
 * @param {int} val             元素值
 * @return {int} counter        元素个数
 */
int searchHashTable(struct HashTable *table, int val) {
    int slot = getHashSlot(table, val);     /* 获取元素值在哈希表中的槽位 */
    struct HashNode *currentNode = table->hashSlots[slot];      /* 获取哈希表的哈希节点 */
    int counter = 0;        /* 元素个数 */
    while (currentNode) {       /* 如果存在哈希节点，则遍历哈希节点 */
        if (currentNode->val == val) {      /* 如果哈希节点的键等于 val */
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
 * @param {int} val             元素值
 * @return {void}
 */
void removeHashTable(struct HashTable *table, int val) {
    int slot = getHashSlot(table, val);     /* 获取元素值在哈希表中的槽位 */
    struct HashNode *currentNode = table->hashSlots[slot];      /* 获取哈希表的哈希节点 */
    struct HashNode *prevNode = NULL;       /* 前一个节点 */
    while (currentNode) {       /* 如果存在哈希节点，则遍历哈希节点 */
        if (currentNode->val == val) {      /* 如果哈希节点的键等于 val */
            if (prevNode) {     /* 如果前一个节点存在 */
                prevNode->next = currentNode->next;     /* 将前一个节点的下一个节点指向当前节点的下一个节点 */
            } else {        /* 如果前一个节点不存在 */
                table->hashSlots[slot] = currentNode->next;     /* 将哈希表的哈希节点设置为当前节点的下一个节点 */
            }
            free(currentNode);      /* 释放当前节点 */
            return;     /* 返回 */
        }
        prevNode = currentNode;     /* 将前一个节点指向当前节点 */
        currentNode = currentNode->next;        /* 将哈希节点指向下一个节点 */
    }
}

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 打印哈希表
 * =================================================================================
 * @param {HashTable} *table    哈希表
 * @return {void}
 */
void printHashTable(struct HashTable *table) {
    printf("Hash Table (slot size: %d):\n", table->size);
    for (int i = 0; i < table->size; i++) {
        printf("    Hash Slot [%d]: ", i);
        struct HashNode *currentNode = table->hashSlots[i];
        while (currentNode) {
            if (currentNode->index == -1) {
                printf("%d (count: %d)", currentNode->val, currentNode->counter);
            } else {
                printf("%d (index: %d)", currentNode->val, currentNode->index);
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
void freeHashTable(struct HashTable *table) {
    for (int i = 0; i < table->size; i++) {     /* 遍历哈希表 */
        struct HashNode *currentNode = table->hashSlots[i];     /* 获取哈希表的哈希节点 */
        while (currentNode) {       /* 遍历哈希节点 */
            struct HashNode *tmp = currentNode;     /* 临时节点 */
            currentNode = currentNode->next;        /* 将哈希节点指向下一个节点 */
            free(tmp);      /* 释放临时节点 */
        }
    }
    free(table->hashSlots);     /* 释放哈希表的哈希列表 */
    free(table);        /* 释放哈希表 */
}


#endif  /* COMMON_HASH_TABLE_EN */
