/*
 * @FilePath     : \Practice_LeetCode_C\F02_Programming_Topics\F01_Data_Structure\02_Linked_List\04_swapPairs\src\swap_pairs.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-12-29 00:48:58
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-02-02 20:00:40
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  :
 */
/* Standard header file (标准头文件) */
#include <stdlib.h>
/* solution header file (题解头文件) */
#include "F02_Programming_Topics/F01_Data_Structure/02_Linked_List/04_swapPairs/inc/swap_pairs.h"
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
 * @description: 两两交换链表中的节点
 * =================================================================================
 * @param {struct ListNode} *head       链表头结点
 * @return {struct ListNode} *head      交换后的链表头结点
 */
struct ListNode *SwapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {       /* 递归终止条件 */
        return head;                                    /* 返回头结点 */
    }

    struct ListNode* newHead = head->next;          /* 交换后的头结点 */
    struct ListNode* prev = NULL;                   /* 前一节点指针 */

    while (head && head->next) {                    /* 循环条件：链表不为空 */
        struct ListNode *first = head;                  /* 第一个节点指针 */
        struct ListNode *second = head->next;           /* 第二个节点指针 */

        first->next = second->next;                     /* 改变链表指向：将第一个节点指针指向第三个节点 */
        second->next = first;                           /* 改变链表指向：将第二个节点指针指向第一个节点 */

        if (prev) {                                     /* 如果前一节点指针不为空 */
            prev->next = second;                            /* 改变链表指向：将前一节点指针指向第二个节点 */
        }
        prev = first;                                   /* 位移指针：将前一节点指针设置为第一个节点指针 */
        head = first->next;                             /* 位移指针：将头结点指针设置为第三个节点指针 */
    }
    return newHead;                                 /* 返回交换后的头结点 */
}
