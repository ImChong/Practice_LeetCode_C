/*
 * @FilePath     : \Practice_LeetCode_C\F02_Programming_Topics\F01_Data_Structure\02_Linked_List\05_RemoveNthFromEnd\src\remove_nth_from_end.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-12-29 00:49:55
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-02-05 11:21:17
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  :
 */
/* Standard header file (标准头文件) */
#include <stdlib.h>
/* solution header file (题解头文件) */
#include "F02_Programming_Topics/F01_Data_Structure/02_Linked_List/05_RemoveNthFromEnd/inc/remove_nth_from_end.h"
/* Common function header file (通用头文件) */
#include "F01_Common_Functions/inc/common_linked_list.h"

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 删除链表的倒数第 N 个结点
 * =================================================================================
 * @param {struct ListNode*} head       链表头节点
 * @param {int} n                       倒数第 n 个节点
 * @return {struct ListNode} *head      返回链表头节点
 */
struct ListNode *RemoveNthFromEnd(struct ListNode* head, int n) {
    if (!head || n <= 0) {                      /* 如果头节点不存在 或 n <= 0 时 */
        return head;                                /* 返回头节点 */
    }

    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));     /* 初始化虚拟头节点 */
    dummy->val = 0;                             /* 虚拟头节点值为0 */
    dummy->next = head;                         /* 虚拟头节点的下一节点指向链表头节点 */

    struct ListNode *first = dummy;             /* 设置第一指针指向虚拟头节点的位置 */
    struct ListNode *second = dummy;            /* 设置第二指针指向虚拟头节点的位置 */

    for (int i = 0; i <= n; i++) {              /* 循环 n + 1 次：需要末尾 NULL 作为循环结束条件，故 n + 1 */
        if (first != NULL) {                        /* 如果第一指针没有指向 NULL */
            first = first->next;                        /* 将第一指针向后移动一个位置 */
        } else {                                    /* 循环过程中第一指针指向了 NULL */
            return head;                                /* 则返回头节点，代表出界 */
        }
    }

    while (first != NULL) {                     /* 当第一指针未指向 NULL 时循环 */
        first = first->next;                        /* 第一指针向后移动一个位置 */
        second = second->next;                      /* 第二指针向后移动一个位置，直到第二指针指向待删除节点的前一节点 */
    }

    struct ListNode *tmp = second->next;        /* 用一个临时指针储存第二指针所指的下一节点：待删除节点 */
    second->next = second->next->next;          /* 将第二指针的下一节点指向下下节点 */
    free(tmp);                                  /* 删除指定节点 */

    struct ListNode *newHead = dummy->next;     /* 设置链表头节点为虚拟头节点的下一节点 */
    free(dummy);                                /* 删除虚拟头节点 */
    return newHead;                             /* 返回链表头节点 */
}
