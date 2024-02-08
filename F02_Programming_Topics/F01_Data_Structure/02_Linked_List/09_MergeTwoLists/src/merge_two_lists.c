/*
 * @FilePath     : \Practice_LeetCode_C\F02_Programming_Topics\F01_Data_Structure\02_Linked_List\09_MergeTwoLists\src\merge_two_lists.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-12-29 00:53:17
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-02-08 22:06:41
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  :
 */
/* Standard header file (标准头文件) */
#include <stdlib.h>
/* solution header file (题解头文件) */
#include "F02_Programming_Topics/F01_Data_Structure/02_Linked_List/09_MergeTwoLists/inc/merge_two_lists.h"
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
 * @description: 合并两个有序链表
 * =================================================================================
 * @param {ListNode} *list1     链表1
 * @param {ListNode} *list2     链表2
 * @return {ListNode} *head     合并后的链表头节点
 */
struct ListNode *MergeTwoLists(struct ListNode *list1, struct ListNode *list2) {
    if (!list1) {
        return list2;
    }
    if (!list2) {
        return list1;
    }

    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *currNode = head;

    while (list1 && list2) {
        if (list1->val < list2->val) {
            currNode->next = list1;
            list1 = list1->next;
        } else {
            currNode->next = list2;
            list2 = list2->next;
        }
        currNode = currNode->next;
    }

    if (list1) {
        currNode->next = list1;
    } else {
        currNode->next = list2;
    }
    return head->next;
}