/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\06_Stack_Queue\02_myStackCreate\myStack_double_queue.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-25 20:30:05
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-27 01:04:58
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 用两个队列实现栈
 */
#include "methodCfg.h"

#if DOUBLE_QUEUE_METHOD_EN
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "F01_Common_Functions/inc/common_queue.h"
#include "myStack_double_queue.h"

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
 * @return {MyStack} *obj   栈指针
 */
MyStack *myStackCreate() {
    MyStack *obj = (MyStack *)malloc(sizeof(MyStack));  /* 为栈结构体分配空间 */
    obj->queue1 = Queue_Init(LEN);                       /* 初始化队列 1 大小为 20 */
    obj->queue2 = Queue_Init(LEN);                       /* 初始化队列 2 大小为 20 */
    return obj;                                         /* 返回栈指针 */
}

/**
 * @description: 入栈
 * =================================================================================
 * @param {MyStack} *obj    栈指针
 * @param {int} x           入栈元素
 * @return {void}
 */
void myStackPush(MyStack *obj, int x) {
    if (Queue_IsEmpty(obj->queue1)) {        /* 如果队列 1 为空 */
        Queue_En(obj->queue2, x);                /* 将元素入队队列 2 */
    } else {                                /* 如果队列 1 不为空 */
        Queue_En(obj->queue1, x);                /* 将元素入队队列 1 */
    }
}

/**
 * @description: 出栈
 * =================================================================================
 * @param {MyStack} *obj    栈指针
 * @return {int}            出栈元素
 */
int myStackPop(MyStack *obj) {
    if (Queue_IsEmpty(obj->queue1)) {                        /* 如果队列 1 为空 */
        while (obj->queue2->head != obj->queue2->tail) {        /* 当队列 2 的队首元素索引不等于队列 2 队尾元素索引时 */
            Queue_En(obj->queue1, Queue_De(obj->queue2));             /* 将队列 2 的队首元素放入队列 1 的队尾 */
        }
        return Queue_De(obj->queue2);                            /* 返回队列 2 的队首元素 */
    }
    while (obj->queue1->head != obj->queue1->tail) {        /* 如果队列 1 的队首元素索引不等于队列 1 队尾元素索引时 */
        Queue_En(obj->queue2, Queue_De(obj->queue1));             /* 将队列 1 的队首元素放入队列 2 的队尾 */
    }
    return Queue_De(obj->queue1);                            /* 返回队列 1 的队首元素 */
}

/**
 * @description: 获取栈顶元素
 * =================================================================================
 * @param {MyStack} *obj    栈指针
 * @return {int}            栈顶元素
 */
int myStackTop(MyStack* obj) {
    if (Queue_IsEmpty(obj->queue1)) {                        /* 如果队列 1 为空 */
        return obj->queue2->data[obj->queue2->tail];            /* 返回队列 2 的队尾元素 */
    }
    return obj->queue1->data[obj->queue1->tail];            /* 否则返回队列 1 的队尾元素 */
}

/**
 * @description: 栈是否为空
 * =================================================================================
 * @param {MyStack} *obj    栈指针
 * @return {bool}           0：栈不为空，1：栈为空
 */
bool myStackEmpty(MyStack *obj) {
    if (obj->queue1->head == -1 && obj->queue2->head == -1) {   /* 如果队列 1 和队列 2 的队首元素索引均为 -1 */
        return true;                                                /* 判断栈为空 */
    }
    return false;                                               /* 否则，判断栈为非空 */
}

/**
 * @description: 释放栈空间
 * =================================================================================
 * @param {MyStack*} obj    栈指针
 * @return {void}
 */
void myStackFree(MyStack* obj) {
    Queue_Free(obj->queue1);         /* 释放队列 1 空间 */
    Queue_Free(obj->queue2);         /* 释放队列 2 空间 */
    free(obj);                      /* 释放栈内存 */
    obj = NULL;                     /* 将栈指针指向 NULL */
}

#endif  /* DOUBLE_QUEUE_METHOD */