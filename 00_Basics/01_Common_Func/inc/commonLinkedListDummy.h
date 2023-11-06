/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\inc\commonLinkedListDummy.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 10:33:41
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-07 00:53:39
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用虚拟头节点链表头文件 - 使用虚拟头节点
 */
#ifndef __COMMON_LINKED_LIST_DUMMY_H
#define __COMMON_LINKED_LIST_DUMMY_H

/**********************************************************************************/
/*                                                                                */
/*                               STRUCT DEFINITION                                */
/*                                                                                */
/**********************************************************************************/
struct ListNode {
    int val;                    /* 节点数值 */
    struct ListNode *next;      /* 下一节点地址 */
};

typedef struct {
    struct ListNode *head;      /* 链表虚拟头节点 */
    int size;                   /* 链表长度 */
} MyLinkedList;

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
MyLinkedList *myLinkedListCreate(void);     /* 创建使用虚拟头节点的链表 */
int myLinkedListGet(MyLinkedList *dummyHead, int index);        /* 获取链表中第index个节点的值 */
void myLinkedListAddAtHead(MyLinkedList *dummyHead, int val);       /* 在链表头部添加一个节点 */
void myLinkedListAddAtTail(MyLinkedList *dummyHead, int val);       /* 在链表尾部添加一个节点 */
void myLinkedListAddAtIndex(MyLinkedList *dummyHead, int index, int val);       /* 在链表中第index个节点之前添加一个值为val的节点 */
void myLinkedListDeleteAtIndex(MyLinkedList *dummyHead, int index);     /* 删除链表中第index个节点 */
void myLinkedListFree(MyLinkedList *dummyHead);     /* 释放链表 */

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
void arrayToMyLinkedList(MyLinkedList *dummyHead, int *nums, int numsSize);     /* 将数组转换为链表 */
void printMyLinkedList(MyLinkedList *dummyHead);      /* 打印链表 */

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
void validateMyLinkedList(char testNum, MyLinkedList *expect, MyLinkedList *actual);        /* 验证链表 */


#endif  /* __COMMON_LINKED_LIST_DUMMY_H */
