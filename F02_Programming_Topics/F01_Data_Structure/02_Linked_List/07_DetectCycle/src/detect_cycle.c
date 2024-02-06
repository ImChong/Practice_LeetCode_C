/*
 * @FilePath     : \Practice_LeetCode_C\F02_Programming_Topics\F01_Data_Structure\02_Linked_List\07_DetectCycle\src\detect_cycle.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-12-29 00:51:28
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-02-06 11:21:05
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  :
 */
/* Standard header file (标准头文件) */
#include <stdlib.h>
/* solution header file (题解头文件) */
#include "F02_Programming_Topics/F01_Data_Structure/02_Linked_List/07_DetectCycle/inc/detect_cycle.h"
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
 * @description: 环形链表 II
 * TODO: 固定的套路能找到环，但是为什么会找到开始入环的第一个节点需要探索一下。
 * =================================================================================
 * @param {ListNode} *head
 * @return {*}
 */
struct ListNode *DetectCycle(struct ListNode *head) {
    struct ListNode *fast = head;   /* 创建快指针，将指针指向头节点 */
    struct ListNode *slow = head;   /* 创建慢指针，将指针指向头节点 */

    while (fast && fast->next) {    /* 当快指针节点和快指针节点的下一位节点存在时 */
        slow = slow->next;              /* 慢指针向后移动一位 */
        fast = fast->next->next;        /* 快指针向后移动两位 */
        if (slow == fast) {             /* 如果快指针和慢指针相遇 */
            /* FIXME: 为什么慢指针回到头节点再遍历后相遇的值是环的起始点？ */
            slow = head;                    /* 慢指针指向头节点 */
            while (slow != fast) {          /* 如果慢指针不等于快指针 */
                slow = slow->next;              /* 慢指针向后移动一位 */
                fast = fast->next;              /* 快指针向后移动一位 */
            }
            return slow;                    /* 返回慢指针 */
        }
    }
    return NULL;                    /* 如果无环则返回NULL */
}
