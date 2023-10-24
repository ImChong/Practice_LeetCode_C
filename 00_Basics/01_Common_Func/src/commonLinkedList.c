/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\src\commonLinkedList.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-22 13:13:38
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用链表源文件 - 未使用虚拟头节点
 */
#include <stdio.h>
#include <stdlib.h>
#include "commonLinkedList.h"

/**********************************************************************************/
/*                                                                                */
/*                                 UTILITY FUNCTIONS                              */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 创建链表 - 不使用虚拟头结点
 * =================================================================================
 * @param {int} *array                  数组
 * @param {int} size                    数组大小
 * @return {struct ListNode} *head      头节点指针
 */
struct ListNode *arrayToLinkedList(int *array, int size) {
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
 * @description: 添加元素至链表 - 不使用虚拟头结点
 * =================================================================================
 * @param {ListNode} *head              头节点指针
 * @param {int} val                     元素值
 * @return {struct ListNode} *head      头节点指针
 */
struct ListNode *appendToLinkedList(struct ListNode *head, int val) {
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }
    struct ListNode *tmp = head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = newNode;
    return head;
}

/**
 * @description: 移除链表元素
 * =================================================================================
 * @param {ListNode} *head              链表虚拟头节点
 * @param {int} val                     目标值
 * @return {struct ListNode} *head      返回链表虚拟头节点
 */
struct ListNode *removeFromLinkedList(struct ListNode *head, int val) {
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

/**
 * @description: 打印链表
 * =================================================================================
 * @param {ListNode} *head          头节点指针
 * @return {void}
 */
void printLinkedList(struct ListNode *head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

/**
 * @description: 释放链表
 * =================================================================================
 * @param {ListNode} *head          头节点指针
 * @return {void}
 */
void freeLinkedList(struct ListNode *head) {
    struct ListNode *tmp = NULL;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 验证答案
 * =================================================================================
 * @param {char} testNum            测试编号
 * @param {ListNode} *expectList    预期
 * @param {ListNode} *ansList       结果
 * @return {void}
 */
void validateLinkedList(char testNum, struct ListNode *expectList, struct ListNode *ansList) {
    struct ListNode *curr1 = expectList, *curr2 = ansList;
    while (curr1 != NULL && curr2 != NULL) {
        if (curr1->val != curr2->val) {
            printf("❌ Test %c Failed\n", testNum);
            return;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    if (curr1 == NULL && curr2 == NULL) {
        printf("✅ Test %c Passed\n", testNum);
    } else {
        printf("❌ Test %c Failed\n", testNum);
    }
}