/*
 * @FilePath     : \Practice_LeetCode_C\F01_Common_Functions\inc\commonHashTable.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-22 13:35:04
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-18 23:07:31
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : Common hash table header file
 */
#ifndef F01_COMMON_FUNCTIONS_INC_COMMONHASHTABLE_H_
#define F01_COMMON_FUNCTIONS_INC_COMMONHASHTABLE_H_

/**********************************************************************************/
/*                                                                                */
/*                                 GLOBAL VARIABLES                               */
/*                                                                                */
/**********************************************************************************/
/* TODO: Seperate the HashNode to HashIndexNode and HashCounterNode*/
/* Hash node structure */
struct HashNode {
    int val;               /* Node value */
    int index;             /* Node index: set to -1 if not needed */
    int counter;           /* Node counter: set to 1 if index is set */
    struct HashNode *next; /* Next node */
};

/* Hash table structure */
struct HashTable {
    int size;                    /* Hash table size */
    struct HashNode **hashSlots; /* Hash table slots */
};

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
struct HashTable *HashTable_Init(int size);                         /* Initialize a hash table */
void HashTable_Insert(struct HashTable *table, int val, int index); /* Insert a hash node */
int HashTable_Search(struct HashTable *table, int val);             /* Get number of hash nodes with the given value */
void HashTable_Remove(struct HashTable *table, int val);            /* Remove a hash node */

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
void HashTable_Print(struct HashTable *table); /* Print hash table */
void HashTable_Free(struct HashTable *table);  /* Free hash table */

#endif /* F01_COMMON_FUNCTIONS_INC_COMMONHASHTABLE_H_ */
