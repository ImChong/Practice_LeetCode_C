/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\06_Stack_Queue\02_myStackCreate\myStack_single_queue.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-25 20:30:05
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-27 00:59:19
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 用一个链表实现栈
 */
#include "methodCfg.h"

#if SINGLE_QUEUE_METHOD_EN
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "myStack_single_queue.h"

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 创建栈
 * =================================================================================
 * @return {MyStack} *stk   栈指针
 */
MyStack *myStackCreate() {
    MyStack *stk = (MyStack *)calloc(1, sizeof(MyStack));   /* 为栈分配空间并初始化为 0 */
    return stk;                                             /* 返回栈指针 */
}

/**
 * @description: 入栈
 * =================================================================================
 * @param {MyStack} *obj    栈指针
 * @param {int} x           入栈元素
 * @return {void}
 */
void myStackPush(MyStack *obj, int x) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));  /* 为链表节点分配空间 */
    node->val = x;                                          /* 节点值初始化为 x */
    node->next = obj->top;                                  /* 下一节点指向当前栈顶节点 */
    obj->top = node;                                        /* 当前栈顶节点设置为当前新创建的节点 */
}

/**
 * @description: 出栈
 * =================================================================================
 * @param {MyStack*} obj    栈指针
 * @return {int} val        出栈元素
 */
int myStackPop(MyStack* obj) {
    ListNode *node = obj->top;      /* 获取当前栈顶元素的指针并存入当前元素指针 */
    int val = node->val;            /* 获取当前元素的值 */
    obj->top = node->next;          /* 将当前栈顶元素设置为下一元素 */
    free(node);                     /* 将当前元素的空间释放 */
    return val;                     /* 返回出栈元素的值 */
}

/**
 * @description: 栈顶元素
 * =================================================================================
 * @param {MyStack} *obj    栈指针
 * @return {int}            栈顶元素值
 */
int myStackTop(MyStack *obj) {
    return obj->top->val;           /* 返回栈顶元素值 */
}

/**
 * @description: 栈是否为空
 * =================================================================================
 * @param {MyStack} *obj    栈指针
 * @return {bool}           0：栈不为空，1：栈顶为空
 */
bool myStackEmpty(MyStack* obj) {
    return (obj->top == NULL);      /* 确认栈顶元素是否为 NULL */
}

/**
 * @description: 释放栈空间
 * =================================================================================
 * @param {MyStack} *obj    栈指针
 * @return {void}
 */
void myStackFree(MyStack *obj) {
    while (obj->top != NULL) {          /* 当栈顶指针不为 NULL 时 */
        ListNode *node = obj->top;          /* 获取栈顶元素的指针并存入当前元素指针 */
        obj->top = obj->top->next;          /* 将栈顶元素指针后移 */
        free(node);                         /* 释放当前元素指针所指空间 */
    }
    free(obj);                          /* 释放栈空间 */
}

#endif  /* SINGLE_QUEUE_METHOD */