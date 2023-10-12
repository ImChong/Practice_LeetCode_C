/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\02_Linked_List\00_common\linkedListCommon.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-08 22:22:20
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 链表公共函数
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
 * @param {int} *array                  数组
 * @param {int} size                    数组大小
 * @return {struct ListNode} *head      头节点指针
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
 * @description: 添加元素至链表
 * =================================================================================
 * @param {ListNode} *head              头节点指针
 * @param {int} val                     元素值
 * @return {struct ListNode} *head      头节点指针
 */
struct ListNode *appendToList(struct ListNode *head, int val) {
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
 * @description: 打印链表
 * =================================================================================
 * @param {ListNode} *listPtr       链表指针
 * @return {void}
 */
void printList(struct ListNode *listPtr) {
    while (listPtr != NULL) {
        printf("%d ", listPtr->val);
        listPtr = listPtr->next;
    }
    printf("\n");
}

/**
 * @description: 释放链表
 * =================================================================================
 * @param {ListNode} *listPtr       链表指针
 * @return {void}
 */
void freeList(struct ListNode *listPtr) {
    struct ListNode *tmp = NULL;
    while (listPtr != NULL) {
        tmp = listPtr;
        listPtr = listPtr->next;
        free(tmp);
    }
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
int main(int argc, const char *argv[]) {
    int arr[] = {1, 2, 3, 4, 5};
    struct ListNode *ansList = createList(arr, 5);
    ansList = appendToList(ansList, 6);
    printList(ansList);
    return 0;
}
