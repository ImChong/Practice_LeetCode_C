/*
 * @FilePath     : \Practice_LeetCode_C\F01_Common_Functions\inc\commonHashTable.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-22 13:35:04
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-19 08:47:23
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

/* Initialize a hash table */
struct IndexHashTable *IndexHashTable_Init(int size);
/* Insert a hash node */
void IndexHashTable_Insert(struct IndexHashTable *table, int value, int index);
/* Get number of hash nodes with the given value */
int IndexHashTable_Search(struct IndexHashTable *table, int value);
/* Remove a hash node */
void IndexHashTable_Remove(struct IndexHashTable *table, int value);
/* Print hash table */
void IndexHashTable_Print(struct IndexHashTable *table);
/* Free hash table */
void IndexHashTable_Free(struct IndexHashTable *table);

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

/* Initialize a hash table */
struct CounterHashTable *CounterHashTable_Init(int size);
/* Insert a hash node */
void CounterHashTable_Insert(struct CounterHashTable *table, int value, int index);
/* Get number of hash nodes with the given value */
int CounterHashTable_Search(struct CounterHashTable *table, int value);
/* Remove a hash node */
void CounterHashTable_Remove(struct CounterHashTable *table, int value);
/* Print hash table */
void CounterHashTable_Print(struct CounterHashTable *table);
/* Free hash table */
void CounterHashTable_Free(struct CounterHashTable *table);

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

/* Initialize a hash table */
struct HashTable *HashTable_Init(int size);
/* Insert a hash node */
void HashTable_Insert(struct HashTable *table, int value, int index);
/* Get number of hash nodes with the given value */
int HashTable_Search(struct HashTable *table, int value);
/* Remove a hash node */
void HashTable_Remove(struct HashTable *table, int value);
/* Print hash table */
void HashTable_Print(struct HashTable *table);
/* Free hash table */
void HashTable_Free(struct HashTable *table);

#endif /* F01_COMMON_FUNCTIONS_INC_COMMONHASHTABLE_H_ */
