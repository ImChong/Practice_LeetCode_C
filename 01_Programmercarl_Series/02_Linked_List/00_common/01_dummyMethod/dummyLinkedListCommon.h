/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\02_Linked_List\00_common\01_dummyMethod\dummyLinkedListCommon.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 10:33:41
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-21 10:39:38
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 链表公共函数 - 使用虚拟头节点
 */
#ifndef __DUMMY_LINKED_LIST_COMMON_H
#define __DUMMY_LINKED_LIST_COMMON_H

/**********************************************************************************/
/*                                                                                */
/*                                 GLOBAL VARIABLES                               */
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


#endif  /* __DUMMY_LINKED_LIST_COMMON_H */
