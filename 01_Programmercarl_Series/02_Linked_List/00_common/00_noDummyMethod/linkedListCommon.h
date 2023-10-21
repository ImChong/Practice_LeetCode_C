/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\02_Linked_List\00_common\00_noDummyMethod\linkedListCommon.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 10:10:06
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-21 10:32:25
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 链表公共函数 - 未使用虚拟头节点
 */
#ifndef __LINKED_LIST_COMMON_H
#define __LINKED_LIST_COMMON_H

#include <stdio.h>
#include <stdlib.h>

/**********************************************************************************/
/*                                                                                */
/*                                 GLOBAL VARIABLES                               */
/*                                                                                */
/**********************************************************************************/
/* 节点定义 */
struct ListNode {
    int val;
    struct ListNode *next;
};

/**********************************************************************************/
/*                                                                                */
/*                                 UTILITY FUNCTIONS                              */
/*                                                                                */
/**********************************************************************************/
struct ListNode *arrayToLinkedList(int *array, int size);
struct ListNode *appendToList(struct ListNode *head, int val);
struct ListNode *removeFromList(struct ListNode *head, int val);
void printList(struct ListNode *head);
void freeList(struct ListNode *head);


#endif  /* __LINKED_LIST_COMMON_H */