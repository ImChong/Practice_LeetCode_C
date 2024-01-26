/*
 * @FilePath     : \Practice_LeetCode_C\F01_Common_Functions\src\commonQueue.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-26 13:40:03
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-13 00:04:13
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用队列源文件
 */
/* Common function configuration file (通用函数配置文件) */
#include "compile_cfg.h"
#if COMMON_QUEUE_EN /* whether compile this file, the definition of this macro can be found in compileCfg.h */
/* Header file (本文件头文件) */
#include "commonQueue.h"
/* Standard header file (标准头文件) */
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************************/
/*                                                                                */
/*                                 UTILITY FUNCTIONS                              */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 初始化队列
 * =================================================================================
 * @param {int} queueSize       数据长度
 * @return {Queue} *obj         初始化后队列的指针
 */
Queue *Queue_Init(int queueSize) {
    Queue *obj = (Queue *)malloc(sizeof(Queue));            /* NOLINT(readability/casting) */
    obj->list = (int *)malloc(sizeof(int) * queueSize);     /* NOLINT(readability/casting) */
    obj->head = -1;                                         /* 队列头初始化为 -1 */
    obj->tail = -1;                                         /* 队列尾初始化为 -1 */
    obj->size = queueSize;                                  /* 队列大小为 k */
    return obj;                                             /* 返回初始化后的队列对象指针 */
}

/**
 * @description: 入队
 * =================================================================================
 * @param {Queue} *queue        队列指针
 * @param {int} val             入队元素
 * @return {void}
 */
void Queue_En(Queue *queue, int val) {
    if (queue->head == -1) {                        /* 如果队列头为索引 -1 */
        queue->head = 0;                            /* 将队列头改为索引 0 */
    }
    /* 队列尾 + 1，（% queue->size）是为了防止新添加的元素超出队列内数组大小。超出部分从 0 开始：环形队列 */
    queue->tail = (queue->tail + 1) % queue->size;
    queue->list[queue->tail] = val;                 /* 将元素添加至队列内数组，索引为队列尾所指索引 */
}

/**
 * @description: 出队
 * =================================================================================
 * @param {Queue} *queue        队列指针
 * @return {int} headVal        队首元素
 */
int Queue_De(Queue *queue) {
    int headVal = queue->list[queue->head];         /* 取出队首元素并赋值给 headVal */
    if (queue->head == queue->tail) {               /* 如果队列头索引等于队列尾索引 */
        queue->head = -1;                           /* 队列头索引设置为 -1 */
        queue->tail = -1;                           /* 队列尾索引设置为 -1 */
        return headVal;                             /* 返回之前取出的队首元素 */
    }
    /* 队列头 + 1，（% queue->size）是为了防止新队列头索引超出队列内数组大小。超出部分从 0 开始：环形队列 */
    queue->head = (queue->head + 1) % queue->size;
    return headVal;                                 /* 返回之前取出的队首元素 */
}

/**
 * @description: 判读队列是否为空
 * =================================================================================
 * @param {Queue} *queue        队列指针
 * @return {int}                0：队列不为空，1：队列为空
 */
int Queue_IsEmpty(Queue *queue) {
    return queue->head == -1;                       /* 判断队列头是否为 -1，若队列头为 -1 则队列为空 */
}

/**
 * @description: 判断队列是否为满
 * =================================================================================
 * @param {Queue} *queue        队列指针
 * @return {int}                0：队列不为满，1：队列为满
 */
int Queue_IsFull(Queue *queue) {
    return (queue->tail + 1) % queue->size == queue->head;    /* 判断队列是否为满，若队列尾 + 1 等于队列头则队列为满 */
}

/**
 * @description: 打印队列
 * =================================================================================
 * @param {Queue} *queue        队列指针
 * @return {void}
 */
void Queue_Print(Queue *queue) {
    printf("Queue (size = %d): [", queue->size);
    for (int i = queue->head; i <= queue->tail; i++) {
        printf("%d", queue->list[i]);
        if (i != queue->tail) {
            printf(", ");
        }
    }
    printf("]\n");
}

/**
 * @description: 释放队列空间
 * =================================================================================
 * @param {Queue} *queue      队列指针
 * @return {void}
 */
void Queue_Free(Queue *queue) {
    free(queue->list);                              /* 释放队列内数组空间 */
    queue->list = NULL;                             /* 将队列内数组指针置空 */
    free(queue);                                    /* 释放队列空间 */
    queue = NULL;                                   /* 将队列指针置空 */
}


#endif      /* COMMON_QUEUE_EN */
