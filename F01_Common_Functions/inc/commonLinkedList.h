/*
 * @FilePath     : \Practice_LeetCode_C\F01_Common_Functions\inc\commonLinkedList.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 10:10:06
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-15 10:33:56
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : Common linked list header file
 */
#ifndef F01_COMMON_FUNCTIONS_INC_COMMONLINKEDLIST_H_
#define F01_COMMON_FUNCTIONS_INC_COMMONLINKEDLIST_H_

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

/**********************************************************************************/
/*                                                                                */
/*                                 UTILITY FUNCTIONS                              */
/*                                                                                */
/**********************************************************************************/
/* Add a node of value val before the first element of the linked list */
struct ListNode *LinkedList_AddAtHead(struct ListNode *head, int val);
/* Add a node of value val to the last element of the linked list */
struct ListNode *LinkedList_AddAtTail(struct ListNode *head, int val);
/* Add a node of value val before the index-th node in the linked list */
struct ListNode *LinkedList_AddAtIndex(struct ListNode *head, int index, int val);
/* Delete the index-th node in the linked list */
struct ListNode *LinkedList_DeleteAtIndex(struct ListNode *head, int index);
/* Delete the first occurrence of the value */
struct ListNode *LinkedList_DeleteValueOnce(struct ListNode *head, int val);
/* Get the value of the index-th node in the linked list */
int LinkedList_GetValueAtIndex(struct ListNode *head, int index);
/* Get all indexes of the value in the linked list */
int *LinkedList_GetValueIndexes(struct ListNode *head, int val, int *returnSize);

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
struct ListNode *LinkedList_ArrayInit(int *array, int size); /* Initialize linked list from array */
void LinkedList_Print(struct ListNode *head);                /* Print linked list */
void LinkedList_Free(struct ListNode *head);                 /* Free linked list */

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/* Validate linked list */
void Validate_LinkedList(char testNum, struct ListNode *expectList, struct ListNode *actualList);

#endif /* F01_COMMON_FUNCTIONS_INC_COMMONLINKEDLIST_H_ */
