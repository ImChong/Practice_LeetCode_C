/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\06_Stack_Queue\01_myQueueCreate\myQueue_double_stack.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-27 01:10:38
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-27 01:23:20
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 用两个栈实现队列：入队栈 和 出队栈
 */
#ifndef __MY_QUEUE_DOUBLE_STACK_H
#define __MY_QUEUE_DOUBLE_STACK_H

#include <stdbool.h>
#include "commonStack.h"

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
/* 队列结构体 */
typedef struct {
    Stack *inStack;     /* 入队栈 */
    Stack *outStack;    /* 出队栈 */
} MyQueue;              /* 重命名结构体为 MyQueue */

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
MyQueue *myQueueCreate(void);               /* 创建队列 */
void in2out(MyQueue *obj);                  /* 从入队栈反向并移动至出队栈 */
void myQueuePush(MyQueue *obj, int x);      /* 入队 */
int myQueuePop(MyQueue *obj);               /* 出队 */
int myQueuePeek(MyQueue *obj);              /* 获取队首元素 */
bool myQueueEmpty(MyQueue* obj);            /* 判断队列是否为空 */
void myQueueFree(MyQueue* obj);             /* 释放队列 */


#endif  /* __MY_QUEUE_DOUBLE_STACK_H */