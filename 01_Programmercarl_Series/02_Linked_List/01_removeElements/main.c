/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\02_Linked_List\01_removeElements\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-03 12:03:26
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 203. 移除链表元素：https://leetcode.cn/problems/remove-linked-list-elements/
 * https://programmercarl.com/0203.%E7%A7%BB%E9%99%A4%E9%93%BE%E8%A1%A8%E5%85%83%E7%B4%A0.html
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
 * @description: 创建链表
 * =================================================================================
 * @param {int} *array
 * @param {int} size
 * @return {*}
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
 * @return {*}
 */
void printList(struct ListNode *listPtr) {
    while (listPtr != NULL) {
        printf("%d ", listPtr->val);
        listPtr = listPtr->next;
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
/* TODO: 运行时长和内存占用可提升*/
/* ============================================================================== */
/* ============================================================================== */
/**
 * @description:
 * =================================================================================
 * @param {ListNode} *head
 * @param {int} val
 * @return {*}
 */
struct ListNode *removeElements(struct ListNode *head, int val){
    struct ListNode dummy;      /* 创建虚拟头节点 */
    dummy.next = head;          /* 将传入链表接在虚拟头节点后面 */

    struct ListNode *curr = &dummy;     /* 创建指针：用于遍历列表 */
    while (curr->next != NULL) {        /* 当指针下一节点不为空时循环 */
        if (curr->next->val == val) {           /* 当当前指针下一节点的值等于目标值时 */
            struct ListNode *tmp = curr->next;      /* 创建临时节点储存当前指针下一节点 */
            curr->next = curr->next->next;          /* 将当前指针节点的下一节点挂载为下下个节点 */
            free(tmp);                              /* 释放之前储存的临时节点 */
        } else {                                /* 当当前指针下一节点的值不等于目标值时 */
            curr = curr->next;                      /* 当前指针的位置 + 1 */
        }
    }
    return dummy.next;          /* 返回虚拟头节点后挂载的结果链表 */
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
    int arr[7] = {1, 2, 6, 3, 4, 5, 6};
    struct ListNode *head = createList(arr, 7);

    struct ListNode *ansList = removeElements(head, 6);
    printList(ansList);

    free(head);
    return 0;
}