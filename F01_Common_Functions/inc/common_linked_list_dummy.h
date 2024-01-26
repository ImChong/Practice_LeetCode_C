/*
 * @FilePath     : \Practice_LeetCode_C\F01_Common_Functions\inc\commonLinkedListDummy.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 10:33:41
 * @LastEditors: Chong Liu liuc12@miamioh.edu
 * @LastEditTime: 2024-01-04 17:01:15
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : Common dummy linked list header file
 */
#ifndef F01_COMMON_FUNCTIONS_INC_COMMON_LINKED_LIST_DUMMY_H_
#define F01_COMMON_FUNCTIONS_INC_COMMON_LINKED_LIST_DUMMY_H_

/**********************************************************************************/
/*                                                                                */
/*                               STRUCT DEFINITION                                */
/*                                                                                */
/**********************************************************************************/
/* Linked list node structure */
struct ListNode {
    int val;               /* Node value */
    struct ListNode *next; /* Next node */
};

/* Dummy linked list head structure */
typedef struct {
    struct ListNode *head; /* Dummy head node */
    int size;              /* Linked list size */
} DummyLinkedList;

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/* Initialize a dummy linked list */
DummyLinkedList *DLinkedList_Init(void);
/* Get the value of the index-th node in the linked list */
int DLinkedList_GetValueAtIndex(DummyLinkedList *dummyHead, int index);
/* Add a node of value val before the first element of the linked list */
void DLinkedList_AddAtHead(DummyLinkedList *dummyHead, int val);
/* Add a node of value val to the last element of the linked list */
void DLinkedList_AddAtTail(DummyLinkedList *dummyHead, int val);
/* Add a node of value val before the index-th node in the linked list */
void DLinkedList_AddAtIndex(DummyLinkedList *dummyHead, int index, int val);
/* Delete the index-th node in the linked list */
void DLinkedList_DeleteAtIndex(DummyLinkedList *dummyHead, int index);
/* Delete all the nodes with the given value */
void DLinkedList_DeleteValue(DummyLinkedList *dummyHead, int val);
/* Delete the first node with the given value */
void DLinkedList_DeleteValueOnce(DummyLinkedList *dummyHead, int val);      /* TODO */
/* Get all the indexes of a value */
int *DLinkedList_GetValueIndexes(DummyLinkedList *dummyHead, int val, int *returnSize);

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
/* Initialize dummy linked list from array */
void DLinkedList_ArrayInit(DummyLinkedList *dummyHead, int *nums, int numsSize);
/* Print dummy linked list */
void DLinkedList_Print(DummyLinkedList *dummyHead);
/* Free dummy linked list */
void DLinkedList_Free(DummyLinkedList *dummyHead);

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/* Validate dummy linked list */
void Validate_DLinkedList(char testNum, DummyLinkedList *expect, DummyLinkedList *actual);

#endif /* F01_COMMON_FUNCTIONS_INC_COMMON_LINKED_LIST_DUMMY_H_ */
