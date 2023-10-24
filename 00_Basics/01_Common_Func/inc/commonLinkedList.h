/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\inc\commonLinkedList.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 10:10:06
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-23 19:08:39
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用链表头文件 - 未使用虚拟头节点
 */
#ifndef __COMMON_LINKED_LIST_H
#define __COMMON_LINKED_LIST_H

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
struct ListNode *arrayToLinkedList(int *array, int size);       /* 将数组转换为链表 */
struct ListNode *appendToList(struct ListNode *head, int val);      /* 在链表尾部添加一个节点 */
struct ListNode *removeFromList(struct ListNode *head, int val);        /* 从链表中删除一个节点 */
void printList(struct ListNode *head);      /* 打印链表 */
void freeList(struct ListNode *head);       /* 释放链表 */

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
void validateLinkedList(char testNum, struct ListNode *expectList, struct ListNode *ansList);       /* 验证链表 */


#endif  /* __COMMON_LINKED_LIST_H */