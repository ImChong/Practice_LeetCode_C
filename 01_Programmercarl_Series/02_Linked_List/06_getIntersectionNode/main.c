/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\02_Linked_List\06_getIntersectionNode\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-14 20:53:11
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 面试题 02.07. 链表相交：https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/
 * https://programmercarl.com/%E9%9D%A2%E8%AF%95%E9%A2%9802.07.%E9%93%BE%E8%A1%A8%E7%9B%B8%E4%BA%A4.html
 */
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************************/
/*                                                                                */
/*                                MACRO FUNCTIONS                                 */
/*                                                                                */
/**********************************************************************************/
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))        /* 获取数组长度 */

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
 * @description: 打印链表
 * =================================================================================
 * @param {ListNode} *listPtr
 * @param {char} listChar
 * @return {void}
 */
void printList(struct ListNode *listPtr, char listChar) {
    printf("linked list %c: ", listChar);
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
 * @description: 获取两个链表的交点
 * =================================================================================
 * @param {ListNode} *headA
 * @param {ListNode} *headB
 * @return {*}
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *pA = headA;
    struct ListNode *pB = headB;
    while (pA != pB) {
        pA = pA != NULL ? pA->next : headB;
        pB = pB != NULL ? pB->next : headA;
    }
    return pA;
}

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 验证答案
 * =================================================================================
 * @param {char} testNum    测试编号
 * @param {int} expect      预期
 * @param {int} actual      实际
 * @return {void}
 */
void validateAnswer(char testNum, int expect, int actual) {
    if (expect == actual) {
        printf("✅ Test %c Passed\n", testNum);
    } else {
        printf("❌ Test %c Failed\n", testNum);
    }
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

}

/**
 * @description: 测试 2
 * =================================================================================
 * @return {void}
 */
void test_2(void) {

}

/**
 * @description: 测试 3
 * =================================================================================
 * @return {void}
 */
void test_3(void) {

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
    int arrA1[] = {4, 1, 8, 4, 5};
    struct ListNode *listA = arrayToLinkedList(arrA1, 5);
    printList(listA, 'A');

    int arrB1[] = {5, 0, 1};
    struct ListNode *listB = arrayToLinkedList(arrB1, 3);
    /* 将B链表挂载至A链表 */
    struct ListNode *current = listB;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = listA->next->next;
    printList(listB, 'B');

    struct ListNode *intersectNode = getIntersectionNode(listA, listB);
    if (intersectNode != NULL) {
        printf("Intersection: %d\n", intersectNode->val);
    } else {
        printf("Intersection: NULL\n");
    }

    /* Case 2 */
    printf("======== Case 2 ======== \n");
    int arrA2[] = {2, 6, 4};
    listA = arrayToLinkedList(arrA2, 3);
    printList(listA, 'A');

    int arrB2[] = {1, 5};
    listB = arrayToLinkedList(arrB2, 2);
    printList(listB, 'B');

    intersectNode = getIntersectionNode(listA, listB);
    if (intersectNode != NULL) {
        printf("Intersection: %d\n", intersectNode->val);
    } else {
        printf("Intersection: NULL\n");
    }

    return 0;
}