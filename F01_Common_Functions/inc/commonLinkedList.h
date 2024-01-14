/*
 * @FilePath     : \Practice_LeetCode_C\F01_Common_Functions\inc\commonLinkedList.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 10:10:06
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-15 02:41:03
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
/* 节点定义 */
struct ListNode {
    int val;               /* 节点数值 */
    struct ListNode *next; /* 下一节点地址 */
};

/**********************************************************************************/
/*                                                                                */
/*                                 UTILITY FUNCTIONS                              */
/*                                                                                */
/**********************************************************************************/
int LinkedList_GetAtIndex(struct ListNode *head, int index);           /* 获取链表中第index个节点的值 */
struct ListNode *LinkedList_AddAtHead(struct ListNode *head, int val); /* 在链表头部添加一个节点 */
struct ListNode *LinkedList_AddAtTail(struct ListNode *head, int val); /* 在链表尾部添加一个节点 */
struct ListNode *LinkedList_AddAtIndex(struct ListNode *head, int index,
                                       int val); /* 在链表中第index个节点之前添加一个值为val的节点 */
struct ListNode *LinkedList_DeleteAtIndex(struct ListNode *head, int index); /* 删除链表中第index个节点 */
struct ListNode *LinkedList_DeleteValue(struct ListNode *head, int val); /* 从链表中删除第一个值为val的节点 */
int *LinkedList_GetValueIndexes(struct ListNode *head,
                                int val,
                                int *returnSize);   /* Get all indexes of the value in the linked list */

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
struct ListNode *LinkedList_ArrayInit(int *array, int size); /* 将数组转换为链表 */
void LinkedList_Print(struct ListNode *head);                /* 打印链表 */
void LinkedList_Free(struct ListNode *head);                 /* 释放链表 */

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
void Validate_LinkedList(char testNum, struct ListNode *expectList, struct ListNode *actualList); /* 验证链表 */

#endif /* F01_COMMON_FUNCTIONS_INC_COMMONLINKEDLIST_H_ */
