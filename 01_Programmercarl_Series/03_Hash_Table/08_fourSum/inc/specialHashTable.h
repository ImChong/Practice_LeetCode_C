/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\08_fourSum\inc\specialHashTable.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-11-23 00:23:13
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-23 00:28:45
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



#endif  /* __SPECIAL_HASH_TABLE_H */