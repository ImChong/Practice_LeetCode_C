/*
 * @FilePath     : \Practice_LeetCode_C\F02_Programming_Topics\F01_Data_Structure\02_Linked_List\01_removeElements\src\remove_elements.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-12-29 00:19:21
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-02-02 19:25:07
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : Solution source file for remove elements
 */
/* Standard header file (标准头文件) */
#include <stdlib.h>
/* solution header file (题解头文件) */
#include "F02_Programming_Topics/F01_Data_Structure/02_Linked_List/01_removeElements/inc/remove_elements.h"
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
 * @description: 移除链表元素
 * TODO: 运行时长和内存占用可提升
 * =================================================================================
 * @param {ListNode} *head              链表虚拟头节点
 * @param {int} val                     目标值
 * @return {struct ListNode} *head      返回链表虚拟头节点
 */
struct ListNode *RemoveElements(struct ListNode *head, int val) {
    struct ListNode dummy;                          /* 创建虚拟头节点 */
    dummy.next = head;                              /* 将传入链表接在虚拟头节点后面 */

    struct ListNode *curr = &dummy;                 /* 创建指针：用于遍历列表 */
    while (curr->next != NULL) {                    /* 遍历链表 */
        if (curr->next->val == val) {                   /* 当前节点的下一个节点的值等于目标值 */
            struct ListNode *tmp = curr->next;              /* 保存当前节点的下一个节点 */
            curr->next = curr->next->next;                  /* 当前节点的下一个节点指向下下个节点 */
            free(tmp);                                      /* 释放当前节点的下一个节点 */
        } else {                                        /* 当前节点的下一个节点的值不等于目标值 */
            curr = curr->next;                              /* 当前节点指向下一个节点 */
        }
    }
    return dummy.next;                              /* 返回链表虚拟头节点 */
}
