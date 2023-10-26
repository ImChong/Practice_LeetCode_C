/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\06_Stack_Queue\02_myStackCreate\myStack_double_queue.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-27 00:38:35
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-27 01:05:56
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 用双队列实现栈
 */
#ifndef __MY_STACK_DOUBLE_QUEUE_H
#define __MY_STACK_DOUBLE_QUEUE_H

#include "methodCfg.h"

#if DOUBLE_QUEUE_METHOD
#include <stdbool.h>
#include "commonQueue.h"

/**********************************************************************************/
/*                                                                                */
/*                                MACRO CONSTANTS                                 */
/*                                                                                */
/**********************************************************************************/
#define LEN 100     /* 长度为 100 */

/**********************************************************************************/
/*                                                                                */
/*                                 GLOBAL VARIABLES                               */
/*                                                                                */
/**********************************************************************************/
typedef struct {
    Queue *queue1;  /* 队列 1 */
    Queue *queue2;  /* 队列 2 */
} MyStack;          /* 栈结构体：包含两个队列 */

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
MyStack *myStackCreate();                   /* 创建栈 */
void myStackPush(MyStack *obj, int x);      /* 入栈 */
int myStackPop(MyStack *obj);               /* 出栈 */
int myStackTop(MyStack* obj);               /* 获取栈顶元素 */
bool myStackEmpty(MyStack *obj);            /* 判断栈是否为空 */
void myStackFree(MyStack* obj);             /* 释放栈 */

#endif  /* DOUBLE_QUEUE_METHOD */

#endif  /* __MY_STACK_DOUBLE_QUEUE_H */