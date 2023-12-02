/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\inc\commonLinkedList.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 10:10:06
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-07 23:23:16
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
int linkedListGet(struct ListNode *head, int index);        /* 获取链表中第index个节点的值 */
struct ListNode *linkedListAddAtHead(struct ListNode *head, int val);       /* 在链表头部添加一个节点 */
struct ListNode *linkedListAddAtTail(struct ListNode *head, int val);       /* 在链表尾部添加一个节点 */
struct ListNode *linkedListAddAtIndex(struct ListNode *head, int index, int val);       /* 在链表中第index个节点之前添加一个值为val的节点 */
struct ListNode *linkedListDeleteAtIndex(struct ListNode *head, int index);             /* 删除链表中第index个节点 */
struct ListNode *linkedListDeleteElement(struct ListNode *head, int val);       /* 从链表中删除第一个值为val的节点 */
int *linkedListGetIndexes(struct ListNode *head, int val, int *returnSize);     /* 获取链表中值为val的所有节点的索引 */

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
struct ListNode *linkedListFromArray(int *array, int size);       /* 将数组转换为链表 */
void linkedListPrint(struct ListNode *head);        /* 打印链表 */
void linkedListFree(struct ListNode *head);         /* 释放链表 */

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
void validateLinkedList(char testNum, struct ListNode *expectList, struct ListNode *actualList);       /* 验证链表 */


#endif  /* __COMMON_LINKED_LIST_H */    /* NOLINT(build/header_guard) */
