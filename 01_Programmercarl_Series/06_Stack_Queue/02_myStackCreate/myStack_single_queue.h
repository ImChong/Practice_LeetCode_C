/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\06_Stack_Queue\02_myStackCreate\myStack_single_queue.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-27 00:38:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-27 00:51:04
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 用一个链表实现栈
 */
#ifndef __MY_STACK_SINGLE_QUEUE_H
#define __MY_STACK_SINGLE_QUEUE_H

/**********************************************************************************/
/*                                                                                */
/*                                 GLOBAL VARIABLES                               */
/*                                                                                */
/**********************************************************************************/
typedef struct tagListNode {
    struct tagListNode *next;   /* 指向下一个链表元素的指针 */
    int val;                    /* 元素数值 */
} ListNode;                     /* 链表节点结构体 */

typedef struct {
    ListNode *top;              /* 栈顶节点指针 */
} MyStack;                      /* 栈结构体 */

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
MyStack *myStackCreate();                   /* 创建栈 */
void myStackPush(MyStack *obj, int x);      /* 入栈 */
int myStackPop(MyStack* obj);               /* 出栈 */
int myStackTop(MyStack *obj);               /* 获取栈顶元素 */
bool myStackEmpty(MyStack* obj);            /* 判断栈是否为空 */
void myStackFree(MyStack* obj);             /* 释放栈 */


#endif  /* __MY_STACK_SINGLE_QUEUE_H */