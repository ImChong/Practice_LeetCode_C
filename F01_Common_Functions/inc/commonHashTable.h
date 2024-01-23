/*
 * @FilePath     : \Practice_LeetCode_C\F01_Common_Functions\inc\commonHashTable.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-22 13:35:04
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-20 08:29:43
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : Common hash table header file
 */
#ifndef F01_COMMON_FUNCTIONS_INC_COMMONHASHTABLE_H_
#define F01_COMMON_FUNCTIONS_INC_COMMONHASHTABLE_H_

/* Common function header file (通用头文件) */
#include "common_type_def.h"

/**********************************************************************************/
/*                                                                                */
/*                               STRUCT DEFINITION                                */
/*                                                                                */
/**********************************************************************************/
/* Whether the HashNode stores counter, if not, it stores index */
#define COUNTER_TRUE COMMON_TRUE
#define COUNTER_FALSE COMMON_FALSE

/* Hash node structure */
struct HashNode {
    int value;              /* Node value */
    union {
        int index;          /* Node index */
        int counter;        /* Node counter */
    };
    struct HashNode *next;  /* Next node */
};

/* Hash table structure */
struct HashTable {
    int size;                    /* Hash table size */
    struct HashNode **slots; /* Hash table slots */
};

/* Initialize a hash table */
struct HashTable *HashTable_Init(int size);
/* Insert a hash node */
void HashTable_Insert(struct HashTable *table, int value, int index_or_counter, int isCounter);
/* Get number of hash nodes with the given value */
int HashTable_Search(struct HashTable *table, int value);
/* Remove a hash node */
void HashTable_Remove(struct HashTable *table, int value);
/* Print hash table */
void HashTable_Print(struct HashTable *table);
/* Free hash table */
void HashTable_Free(struct HashTable *table);

#endif /* F01_COMMON_FUNCTIONS_INC_COMMONHASHTABLE_H_ */
