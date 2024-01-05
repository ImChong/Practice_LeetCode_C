/*
 * @FilePath     : \Practice_LeetCode_C\01_Programming_Topics\06_Stack_Queue\01_myQueueCreate\src\myQueue_doubleStack.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-28 09:44:35
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-29 00:59:24
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 用两个栈实现队列：入队栈 和 出队栈
 * 每次读取数据的时候将入队栈元素全部压入出队栈，并读取出队栈的栈顶元素
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "commonStack.h"
#include "myQueue_doubleStack.h"

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 创建队列
 * =================================================================================
 * @return {MyQueue *} ret      返回创建的队列结构体
 */
MyQueue *myQueueCreate(void) {
    MyQueue *ret = (MyQueue *)malloc(sizeof(MyQueue));  /* 为队列结构体分配空间 */
    ret->inStack = Stack_Create(LEN);                    /* 入队栈初始化可容纳 LEN 数据 */
    ret->outStack = Stack_Create(LEN);                   /* 出队栈初始化可容纳 LEN 数据 */
    return ret;                                         /* 返回创建的队列结构体 */
}

/**
 * @description: 从入队栈反向并移动至出队栈
 * =================================================================================
 * @param {MyQueue *} obj       队列结构体
 * @return {void}
 */
void in2out(MyQueue *obj) {
    while (!stackEmpty(obj->inStack)) {                     /* 当入队栈不为空时 */
        Stack_Push(obj->outStack, stackTop(obj->inStack));       /* 将入队栈的栈顶元素放入出队栈 */
        stackPop(obj->inStack);                                 /* 去除入队栈的栈顶元素 */
    }
}

/**
 * @description: 入队
 * =================================================================================
 * @param {MyQueue} *obj        队列结构体
 * @param {int} x               入队元素
 * @return {void}
 */
void myQueuePush(MyQueue *obj, int x) {
    Stack_Push(obj->inStack, x);                             /* 将元素放入入队栈 */
}

/**
 * @description: 出队
 * =================================================================================
 * @param {MyQueue} *obj        队列结构体
 * @return {int} x              出队元素
 */
int myQueuePop(MyQueue *obj) {
    if (stackEmpty(obj->outStack)) {                        /* 如果出队栈为空 */
        in2out(obj);                                            /* 将入队栈内所有元素反向放入出队栈 */
    }
    int x = stackTop(obj->outStack);                        /* 取出出队栈的栈顶元素，并赋值给 x */
    stackPop(obj->outStack);                                /* 移除出队栈内的栈顶元素 */
    return x;                                               /* 返回出队栈栈顶元素 x */
}

/**
 * @description: 查看队首元素
 * =================================================================================
 * @param {MyQueue *} obj       队列结构体
 * @return {int} x              队首元素
 */
int myQueuePeek(MyQueue *obj) {
    if (stackEmpty(obj->outStack)) {                        /* 如果出队栈为空 */
        in2out(obj);                                            /* 将入队栈内所有元素反向放入出队栈 */
    }
    return stackTop(obj->outStack);                         /* 返回出队栈栈顶元素 */
}

/**
 * @description: 确认队列是否为空
 * =================================================================================
 * @param {MyQueue *} obj       队列结构体
 * @return {bool}               队列是否为空
 */
bool myQueueEmpty(MyQueue* obj) {
    return (stackEmpty(obj->inStack) && stackEmpty(obj->outStack));     /* 返回入队栈和出队栈是否都为空 */
}

/**
 * @description: 释放队列空间
 * =================================================================================
 * @param {MyQueue *} obj       队列结构体
 * @return {void}
 */
void myQueueFree(MyQueue* obj) {
    stackFree(obj->inStack);                                /* 释放入队栈空间 */
    stackFree(obj->outStack);                               /* 释放出队栈空间 */
}

