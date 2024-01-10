/*
 * @FilePath     : \Practice_LeetCode_C\01_Common_Functions\inc\commonLinkedListDummy.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 10:33:41
 * @LastEditors: Chong Liu liuc12@miamioh.edu
 * @LastEditTime: 2024-01-04 17:01:15
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : Common dummy linked list header file
 */
#ifndef __COMMON_LINKED_LIST_DUMMY_H /* NOLINT(build/header_guard) */
#define __COMMON_LINKED_LIST_DUMMY_H /* NOLINT(build/header_guard) */

/**********************************************************************************/
/*                                                                                */
/*                               STRUCT DEFINITION                                */
/*                                                                                */
/**********************************************************************************/
struct ListNode {
    int val;               /* 节点数值 */
    struct ListNode *next; /* 下一节点地址 */
};

typedef struct {
    struct ListNode *head; /* 链表虚拟头节点 */
    int size;              /* 链表长度 */
} DummyLinkedList;

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
DummyLinkedList *DLinkedList_Init(void);                           /* 创建使用虚拟头节点的链表 */
int DLinkedList_GetAtIndex(DummyLinkedList *dummyHead, int index); /* 获取链表中第index个节点的值 */
void DLinkedList_AddAtHead(DummyLinkedList *dummyHead, int val);   /* 在链表头部添加一个节点 */
void DLinkedList_AddAtTail(DummyLinkedList *dummyHead, int val);   /* 在链表尾部添加一个节点 */
void DLinkedList_AddAtIndex(DummyLinkedList *dummyHead, int index,
                            int val); /* 在链表中第index个节点之前添加一个值为val的节点 */
void DLinkedList_DeleteAtIndex(DummyLinkedList *dummyHead, int index); /* 删除链表中第index个节点 */
void DLinkedList_DeleteValue(DummyLinkedList *dummyHead, int val);     /* 从链表中删除值为val的所有节点 */
int *DLinkedList_GetIndexes(DummyLinkedList *dummyHead, int val,
                            int *returnSize); /* 获取链表中值为val的所有节点的索引 */

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
void DLinkedList_ArrayInit(DummyLinkedList *dummyHead, int *nums, int numsSize); /* 将数组转换为链表 */
void DLinkedList_Print(DummyLinkedList *dummyHead);                              /* 打印链表 */
void DLinkedList_Free(DummyLinkedList *dummyHead);                               /* 释放链表 */

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
void Validate_DLinkedList(char testNum, DummyLinkedList *expect, DummyLinkedList *actual); /* 验证链表 */

#endif /* __COMMON_LINKED_LIST_DUMMY_H */ /* NOLINT(build/header_guard) */
