/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\inc\commonHashTable.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-22 13:35:04
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-23 11:54:19
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用哈希表头文件
 */
#ifndef __COMMON_HASH_TABLE_H
#define __COMMON_HASH_TABLE_H

/**********************************************************************************/
/*                                                                                */
/*                                 GLOBAL VARIABLES                               */
/*                                                                                */
/**********************************************************************************/
/* 哈希节点 */
struct HashNode {
    int key;                    /* 键 */
    int val;                    /* 值 */
    struct HashNode *next;      /* 下一个节点 */
};

/* 哈希表 */
struct HashTable {
    int size;                   /* 哈希表大小 */
    struct HashNode **table;    /* 哈希表 */
};

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
struct HashTable *createHashTable(int size);
int getHashCode(struct HashTable *table, int key);
void insertHashTable(struct HashTable *table, int key);
int searchHashTable(struct HashTable *table, int key);
void freeHashTable(struct HashTable *table);


#endif  /* __COMMON_HASH_TABLE_H */