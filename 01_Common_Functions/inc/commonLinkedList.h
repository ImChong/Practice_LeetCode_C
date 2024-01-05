/*
 * @FilePath     : \Practice_LeetCode_C\01_Common_Functions\inc\commonLinkedList.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 10:10:06
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-06 00:50:10
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用链表头文件 - 未使用虚拟头节点
 */
#ifndef __COMMON_LINKED_LIST_H      /* NOLINT(build/header_guard) */
#define __COMMON_LINKED_LIST_H      /* NOLINT(build/header_guard) */

/**********************************************************************************/
/*                                                                                */
/*                               STRUCT DEFINITION                                */
/*                                                                                */
/**********************************************************************************/
/* 节点定义 */
struct ListNode {
    int val;                    /* 节点数值 */
    struct ListNode *next;      /* 下一节点地址 */
};

/**********************************************************************************/
/*                                                                                */
/*                                 UTILITY FUNCTIONS                              */
/*                                                                                */
/**********************************************************************************/
int LinkedList_Get(struct ListNode *head, int index);        /* 获取链表中第index个节点的值 */
struct ListNode *LinkedList_AddAtHead(struct ListNode *head, int val);       /* 在链表头部添加一个节点 */
struct ListNode *LinkedList_AddAtTail(struct ListNode *head, int val);       /* 在链表尾部添加一个节点 */
struct ListNode *LinkedList_AddAtIndex(struct ListNode *head,
                                       int index,
                                       int val);       /* 在链表中第index个节点之前添加一个值为val的节点 */
struct ListNode *LinkedList_DeleteAtIndex(struct ListNode *head, int index);             /* 删除链表中第index个节点 */
struct ListNode *LinkedList_DeleteValue(struct ListNode *head, int val);       /* 从链表中删除第一个值为val的节点 */
int *LinkedList_GetIndexes(struct ListNode *head, int val, int *returnSize);     /* 获取链表中值为val的所有节点的索引 */

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
struct ListNode *LinkedList_FromArray(int *array, int size);       /* 将数组转换为链表 */
void LinkedList_Print(struct ListNode *head);        /* 打印链表 */
void LinkedList_Free(struct ListNode *head);         /* 释放链表 */

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
void Validate_LinkedList(char testNum, struct ListNode *expectList, struct ListNode *actualList);       /* 验证链表 */


#endif  /* __COMMON_LINKED_LIST_H */    /* NOLINT(build/header_guard) */
