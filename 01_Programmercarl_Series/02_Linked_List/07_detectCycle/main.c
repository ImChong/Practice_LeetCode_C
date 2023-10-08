/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\02_Linked_List\07_detectCycle\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-08 22:35:53
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 142. 环形链表 II：https://leetcode.cn/problems/linked-list-cycle-ii/
 * https://programmercarl.com/0142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II.html
 */
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
/**
 * @description: 创建链表，不使用虚拟头结点
 * =================================================================================
 * @param {int} *array
 * @param {int} size
 * @return {struct ListNode} *head
 */
struct ListNode *createList(int *array, int size) {
    struct ListNode *head = NULL;       /* 头节点指针 */
    struct ListNode *current = NULL;    /* 当前节点指针 */

    for (int i = 0; i < size; i++) {
        /* 创建新结点 */
        struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
        new_node->val = array[i];
        new_node->next = NULL;

        /* 如果链表为空，则将新结点设置为头结点 */
        if (head == NULL) {
            head = new_node;
        } else {
            /* 否则，将新结点追加到链表末尾 */
            current->next = new_node;
        }
        current = new_node;
    }
    return head;
}

/**
 * @description: 打印链表
 * =================================================================================
 * @param {ListNode} *listPtr
 * @return {void}
 */
void printList(struct ListNode *listPtr) {
    int i = 0;  /* 防止无限循环 */
    while (listPtr != NULL && i < 20) {
        printf("%d ", listPtr->val);
        listPtr = listPtr->next;
        i++;
    }
    printf("\n");
}

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/* TODO: 固定的套路能找到环，但是为什么会找到开始入环的第一个节点需要探索一下。 */
/* ============================================================================== */
/* ============================================================================== */
/**
 * @description: 环形链表 II
 * =================================================================================
 * @param {ListNode} *head
 * @return {*}
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *fast = head;   /* 创建快指针，将指针指向头节点 */
    struct ListNode *slow = head;   /* 创建慢指针，将指针指向头节点 */

    while (fast && fast->next) {    /* 当快指针节点和快指针节点的下一位节点存在时 */
        slow = slow->next;              /* 慢指针向后移动一位 */
        fast = fast->next->next;        /* 快指针向后移动两位 */
        if (slow == fast) {             /* 如果快指针和慢指针相遇 */
            slow = head;                    /* 慢指针指向头节点 */  /* FIXME: 为什么慢指针回到头节点再遍历后相遇的值是环的起始点？ */
            while (slow != fast) {          /* 如果慢指针不等于快指针 */
                slow = slow->next;              /* 慢指针向后移动一位 */
                fast = fast->next;              /* 快指针向后移动一位 */
            }
            return slow;                    /* 返回慢指针 */
        }
    }
    return NULL;                    /* 如果无环则返回NULL */
}

/**********************************************************************************/
/*                                                                                */
/*                                  MAIN FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 主函数
 * =================================================================================
 * @param {int} argc        程序入参个数
 * @param {char} *argv[]    程序入参字符串数组
 * @return {int}            程序运行状态
 */
int main(int argc, const char* argv[]) {
    /* Case 1 */
    printf("======== Case 1 ======== \n");
    int arr1[] = {3, 2, 0, -4};
    struct ListNode *ansList = createList(arr1, 4);
    struct ListNode *pPos = ansList;
    struct ListNode *pTail = ansList;
    while (pTail->next != NULL) {   /* 获取链表尾部节点 */
        pTail = pTail->next;
    }
    pPos = pPos->next;          /* 获取链表指定节点 */
    pTail->next = pPos;         /* 将尾节点指向指定节点 */
    printList(ansList);
    printf("Pos: %d\n", detectCycle(ansList)->val);

    /* Case 2 */
    printf("======== Case 2 ======== \n");
    struct ListNode b1 = {1, NULL}, b2 = {2, NULL};
    b1.next = &b2; b2.next = &b1;
    printList(&b1);
    printf("Pos: %d\n", detectCycle(&b1)->val);

    /* Case 3 */
    printf("======== Case 3 ======== \n");
    int arr3[] = {3, 2, 0, -4, -5, -6};
    ansList = createList(arr3, 6);
    pPos = ansList;
    pTail = ansList;
    while (pTail->next != NULL) {   /* 获取链表尾部节点 */
        pTail = pTail->next;
    }
    pPos = pPos->next->next;          /* 获取链表指定节点 */
    pTail->next = pPos;         /* 将尾节点指向指定节点 */
    printList(ansList);
    printf("Pos: %d\n", detectCycle(ansList)->val);

    return 0;
}