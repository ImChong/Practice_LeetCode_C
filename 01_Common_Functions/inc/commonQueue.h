/*
 * @FilePath     : \Practice_LeetCode_C\01_Common_Functions\inc\commonQueue.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-26 13:38:47
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-05 21:47:27
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用队列头文件
 */
#ifndef __COMMON_QUEUE_H        /* NOLINT(build/header_guard) */
#define __COMMON_QUEUE_H        /* NOLINT(build/header_guard) */

/**********************************************************************************/
/*                                                                                */
/*                                 GLOBAL VARIABLES                               */
/*                                                                                */
/**********************************************************************************/
typedef struct {
    int *list;      /* 数据 */
    int head;       /* 队列头 */
    int tail;       /* 队列尾 */
    int size;       /* 队列大小 */
} Queue;            /* 队列结构体 */

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
Queue *Queue_Init(int queueSize);        /* 初始化队列 */
void Queue_En(Queue *queue, int val);    /* 入队 */
int Queue_De(Queue *queue);              /* 出队 */
int Queue_IsEmpty(Queue *queue);         /* 判断队列是否为空 */
int Queue_IsFull(Queue *queue);          /* 判断队列是否为满 */

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
void printQueue(Queue *queue);          /* 打印队列 */
void freeQueue(Queue *queue);           /* 释放队列 */


#endif  /* __COMMON_QUEUE_H */      /* NOLINT(build/header_guard) */
