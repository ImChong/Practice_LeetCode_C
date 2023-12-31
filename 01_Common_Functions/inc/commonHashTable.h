/*
 * @FilePath     : \Practice_LeetCode_C\01_Common_Functions\inc\commonHashTable.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-22 13:35:04
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-06 01:11:03
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : Common hash table header file
 */
#ifndef __COMMON_HASH_TABLE_H /* NOLINT(build/header_guard) */
#define __COMMON_HASH_TABLE_H /* NOLINT(build/header_guard) */

/**********************************************************************************/
/*                                                                                */
/*                                 GLOBAL VARIABLES                               */
/*                                                                                */
/**********************************************************************************/
/* 哈希节点 */
struct HashNode {
    int val;               /* 元素值 */
    int index;             /* 元素索引（如果不需要索引，此项可以设置为 -1） */
    int counter;           /* 元素个数（如果需要索引，此项则默认为 1） */
    struct HashNode *next; /* 下一个节点 */
};

/* 哈希表 */
struct HashTable {
    int size;                    /* 哈希表大小 */
    struct HashNode **hashSlots; /* 哈希槽位 */
};

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
struct HashTable *HashTable_Init(int size);                         /* 创建哈希表 */
void HashTable_Insert(struct HashTable *table, int val, int index); /* 插入哈希节点 */
int HashTable_Search(struct HashTable *table, int val);             /* 查找哈希表（返回元素个数） */
void HashTable_Remove(struct HashTable *table, int val);            /* 删除哈希节点 */

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
void HashTable_Print(struct HashTable *table); /* 打印哈希表 */
void HashTable_Free(struct HashTable *table);  /* 释放哈希表 */

#endif /* __COMMON_HASH_TABLE_H */ /* NOLINT(build/header_guard) */
