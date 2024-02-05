/*
 * @FilePath     : \Practice_LeetCode_C\F02_Programming_Topics\F01_Data_Structure\02_Linked_List\06_GetIntersectionNode\src\get_intersection_node.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-12-29 00:50:35
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-02-05 11:35:45
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  :
 */
/* Standard header file (标准头文件) */
#include <stdlib.h>
/* solution header file (题解头文件) */
#include "F02_Programming_Topics/F01_Data_Structure/02_Linked_List/06_GetIntersectionNode/inc/get_intersection_node.h"
/* Common function header file (通用头文件) */
#include "F01_Common_Functions/inc/common_linked_list.h"

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/*
    这段选中的代码实现了一个函数 getIntersectionNode，用于查找两个链表的交点。
    该函数接受两个链表 headA 和 headB 作为输入，如果存在交点，则返回交点，否则返回 NULL。

    该函数使用两个指针 pA 和 pB 分别指向链表 headA 和 headB 的头节点。
    然后，两个指针同时向后遍历链表，直到两个指针相遇，或者同时到达链表的末尾。如果两个指针相遇，则说明存在交点，返回交点；
    否则，返回 NULL。

    在遍历链表时，如果一个指针到达链表的末尾，则将其重定向到另一个链表的头节点，这样可以保证两个指针同时到达交点。
    这个过程可以通过两个指针的循环遍历来实现。

    该实现的时间复杂度为 O(m+n)，其中 m 和 n 分别是两个链表的长度。空间复杂度为 O(1)，因为只使用了两个指针来遍历链表。
    这个实现简单高效，易于理解。
*/
/* ============================================================================== */
/* ============================================================================== */
/**
 * @description: 获取两个链表的交点
 * =================================================================================
 * @param {ListNode} *headA     链表A头指针
 * @param {ListNode} *headB     链表B头指针
 * @return {*}
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *pA = headA;                /* 链表A指针 */
    struct ListNode *pB = headB;                /* 链表B指针 */
    while (pA != pB) {                          /* 循环条件：两个指针不相等 */
        pA = pA != NULL ? pA->next : headB;         /* 链表A指针后移 */
        pB = pB != NULL ? pB->next : headA;         /* 链表B指针后移 */
    }
    return pA;                                  /* 返回交点 */
}
