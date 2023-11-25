/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\inc\commonQueue.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-26 13:38:47
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-25 23:00:01
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用队列头文件
 */
#ifndef __COMMON_QUEUE_H
#define __COMMON_QUEUE_H

/**********************************************************************************/
/*                                                                                */
/*                                 GLOBAL VARIABLES                               */
/*                                                                                */
/**********************************************************************************/
typedef struct {
    int *data;      /* 数据 */
    int head;       /* 队列头 */
    int tail;       /* 队列尾 */
    int size;       /* 队列大小 */
} Queue;            /* 队列结构体 */

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
Queue *initQueue(int queueSize);        /* 初始化队列 */
void enQueue(Queue *queue, int val);    /* 入队 */
int deQueue(Queue *queue);              /* 出队 */
int isQueueEmpty(Queue *queue);         /* 判断队列是否为空 */
int isQueueFull(Queue *queue);          /* 判断队列是否为满 */
void freeQueue(Queue *queue);           /* 释放队列 */


#endif  /* __COMMON_QUEUE_H */