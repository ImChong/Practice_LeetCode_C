/*
 * @FilePath     : \Practice_LeetCode_C\F01_Common_Functions\inc\commonHashTable.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-22 13:35:04
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-19 08:43:48
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : Common hash table header file
 */
#ifndef F01_COMMON_FUNCTIONS_INC_COMMONHASHTABLE_H_
#define F01_COMMON_FUNCTIONS_INC_COMMONHASHTABLE_H_

/**********************************************************************************/
/*                                                                                */
/*                               STRUCT DEFINITION                                */
/*                                                                                */
/**********************************************************************************/

/* Hash node structure for index-based operations */
struct IndexHashNode {
    int value;               /* Node value */
    int index;             /* Node index */
    struct IndexHashNode *next; /* Next node */
};

/* Hash table structure for index-based operations */
struct IndexHashTable {
    int size;                    /* Hash table size */
    struct IndexHashNode **slots; /* Hash table slots */
};

/**********************************************************************************/
/*                                                                                */
/*                               STRUCT DEFINITION                                */
/*                                                                                */
/**********************************************************************************/

/* Hash node structure for counter-based operations */
struct CounterHashNode {
    int value;               /* Node value */
    int counter;           /* Node counter */
    struct CounterHashNode *next; /* Next node */
};

/* Hash table structure for counter-based operations */
struct CounterHashTable {
    int size;                    /* Hash table size */
    struct CounterHashNode **slots; /* Hash table slots */
};

/**********************************************************************************/
/*                                                                                */
/*                               STRUCT DEFINITION                                */
/*                                                                                */
/**********************************************************************************/
/* Hash node structure */
struct HashNode {   /* FIXME: remove this structure, use IndexHashNode and CounterHashNode instead */
    int value;               /* Node value */
    int index;             /* Node index: set to -1 if not needed */
    int counter;           /* Node counter: set to 1 if index is set */
    struct HashNode *next; /* Next node */
};

/* Hash table structure */
struct HashTable {
    int size;                    /* Hash table size */
    struct HashNode **hashSlots; /* Hash table slots */
};

struct HashTable *HashTable_Init(int size);                         /* Initialize a hash table */
void HashTable_Insert(struct HashTable *table, int value, int index); /* Insert a hash node */
int HashTable_Search(struct HashTable *table, int value);             /* Get number of hash nodes with the given value */
void HashTable_Remove(struct HashTable *table, int value);            /* Remove a hash node */
void HashTable_Print(struct HashTable *table); /* Print hash table */
void HashTable_Free(struct HashTable *table);  /* Free hash table */

#endif /* F01_COMMON_FUNCTIONS_INC_COMMONHASHTABLE_H_ */
