/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\inc\commonLinkedList.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 10:10:06
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-22 12:24:20
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

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
void validateAnswerLinkedList(char testNum, struct ListNode *expectList, struct ListNode *ansList);


#endif  /* __COMMON_LINKED_LIST_H */