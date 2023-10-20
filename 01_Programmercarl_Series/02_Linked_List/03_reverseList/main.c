/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\02_Linked_List\03_reverseList\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-20 11:07:01
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 206. 反转链表：https://leetcode.cn/problems/reverse-linked-list/
 * https://programmercarl.com/0206.%E7%BF%BB%E8%BD%AC%E9%93%BE%E8%A1%A8.html
 */
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************************/
/*                                                                                */
/*                                MACRO FUNCTIONS                                 */
/*                                                                                */
/**********************************************************************************/
#define ARR_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))        /* 获取数组长度 */

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
 * @description: 创建链表 - 不使用虚拟头结点
 * =================================================================================
 * @param {int} *array                  数组
 * @param {int} size                    数组大小
 * @return {struct ListNode} *head      链表头指针
 */
struct ListNode *arrayToLinkedList(int *array, int arrSize) {
    struct ListNode *head = NULL;                                                           /* 链表头指针 */
    struct ListNode *current = NULL;                                                        /* 当前节点指针 */

    for (int i = 0; i < arrSize; i++) {                                                     /* 遍历数组 */
        struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));         /* 新建节点 */
        new_node->val = array[i];                                                               /* 将数组元素赋值给新节点 */
        new_node->next = NULL;                                                                  /* 将新节点的下一节点指针设置为NULL */

        if (head == NULL) {                                                                     /* 如果链表为空 */
            head = new_node;                                                                        /* 将新节点设置为头结点 */
        } else {                                                                                /* 如果链表不为空 */
            current->next = new_node;                                                               /* 将新节点追加到链表末尾 */
        }
        current = new_node;                                                                     /* 将当前节点指针指向新节点 */
    }
    return head;                                                                            /* 返回头结点指针 */
}

/**
 * @description: 打印链表
 * =================================================================================
 * @param {ListNode} *listPtr
 * @return {void}
 */
void printList(struct ListNode *listPtr) {
    printf("linked list: ");
    while (listPtr != NULL) {
        printf("%d ", listPtr->val);
        listPtr = listPtr->next;
    }
    printf("\n");
}

/**
 * @description: 释放链表内存
 * =================================================================================
 * @param {ListNode} *head      链表头指针
 * @return {void}
 */
void freeLinkedList(struct ListNode *head) {
    struct ListNode *current = head;
    while (current != NULL) {
        struct ListNode *temp = current;
        current = current->next;
        free(temp);
    }
}

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 反转链表
 * =================================================================================
 * @param {ListNode*} head
 * @return {struct ListNode} *prev
 */
struct ListNode *reverseList(struct ListNode* head){
    struct ListNode *prev = NULL;   /* 初始化前一节点指针为NULL */
    struct ListNode *curr = head;   /* 初始化现节点指针头结点 */
    struct ListNode *next = NULL;   /* 初始化下一节点指针为NULL */

    while (curr != NULL) {          /* 如果当前指针指向的节点不为 NULL */
        next = curr->next;              /* 位移指针：配置下一节点*/
        curr->next = prev;              /* 改变链表指向：将现节点的下一节点指针指向前一节点 */
        prev = curr;                    /* 位移指针：将现节点指针设置为前节点指针*/
        curr = next;                    /* 位移指针：将下一节点指针设置为现节点指针 */
    }
    return prev;                    /* 返回前一节点指针 */
}

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 验证答案
 * =================================================================================
 * @param {char} testNum        测试编号
 * @param {ListNode} *expect    预期
 * @param {ListNode} *actual    实际
 * @return {void}
 */
void validateAnswerList(char testNum, struct ListNode *expect, struct ListNode *actual) {
    if (expect == NULL && actual == NULL) {
        printf("✅ Test %c Passed\n", testNum);
        return;
    }
    while (expect != NULL && actual != NULL) {
        if (expect->val != actual->val) {
            printf("❌ Test %c Failed\n", testNum);
            return;
        }
        expect = expect->next;
        actual = actual->next;
    }
    printf("✅ Test %c Passed\n", testNum);
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试 1
 * =================================================================================
 * @return {void}
 */
void test_1(void) {
    /* 实际结果 */
    int arr[] = {1, 2, 3, 4, 5};
    int arrSize = ARR_SIZE(arr);
    struct ListNode *arrList = arrayToLinkedList(arr, arrSize);
    struct ListNode *ansList = reverseList(arrList);

    /* 预期结果 */
    int expect[] = {5, 4, 3, 2, 1};
    int expectSize = ARR_SIZE(expect);
    struct ListNode *expectList = arrayToLinkedList(expect, expectSize);

    /* 比较结果 */
    validateAnswerList('1', expectList, ansList);

    /* 释放内存 */
    freeLinkedList(arrList);
    freeLinkedList(expectList);
}

/**
 * @description: 测试 2
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */
    int arr[] = {1};
    int arrSize = ARR_SIZE(arr);
    struct ListNode *arrList = arrayToLinkedList(arr, arrSize);
    struct ListNode *ansList = reverseList(arrList);

    /* 预期结果 */
    int expect[] = {1};
    int expectSize = ARR_SIZE(expect);
    struct ListNode *expectList = arrayToLinkedList(expect, expectSize);

    /* 比较结果 */
    validateAnswerList('2', expectList, ansList);

    /* 释放内存 */
    freeLinkedList(arrList);
    freeLinkedList(expectList);
}

/**
 * @description: 测试 3
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    /* 实际结果 */
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arrSize = ARR_SIZE(arr);
    struct ListNode *arrList = arrayToLinkedList(arr, arrSize);
    struct ListNode *ansList = reverseList(arrList);

    /* 预期结果 */
    int expect[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int expectSize = ARR_SIZE(expect);
    struct ListNode *expectList = arrayToLinkedList(expect, expectSize);

    /* 比较结果 */
    validateAnswerList('3', expectList, ansList);

    /* 释放内存 */
    freeLinkedList(arrList);
    freeLinkedList(expectList);
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
int main(int argc, char const *argv[]) {
    test_1();
    test_2();
    test_3();
    return 0;
}