/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\08_fourSum\inc\specialHashTable.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-11-23 00:23:13
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-23 01:09:40
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 特殊哈希表头文件
 */
#ifndef __SPECIAL_HASH_TABLE_H
#define __SPECIAL_HASH_TABLE_H

/**********************************************************************************/
/*                                                                                */
/*                                 GLOBAL VARIABLES                               */
/*                                                                                */
/**********************************************************************************/
/* 哈希节点 */
struct HashNode {
    int sum;
    int index1;
    int index2;
    struct HashNode* next;
};

/* 哈希表 */
struct HashTable {
    int size;                       /* 哈希表大小 */
    struct HashNode **hashSlots;    /* 哈希槽位 */
};

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
struct HashTable *HashTable_Create(int size);                                        /* 创建哈希表 */
int getHashSlot(struct HashTable *table, int val);                                  /* 获取哈希槽位 */
void HashTable_Insert(struct HashTable *table, int val, int index1, int index2);     /* 插入哈希节点 */
struct HashNode *HashTable_Search(struct HashTable *table, int val);                 /* 查找哈希表（返回最新哈希节点） */
void HashTable_Free(struct HashTable *table);                                        /* 释放哈希表 */
void HashTable_Print(struct HashTable *table);                                       /* 打印哈希表 */


#endif  /* __SPECIAL_HASH_TABLE_H */