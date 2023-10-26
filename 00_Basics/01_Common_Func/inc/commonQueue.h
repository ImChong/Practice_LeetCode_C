/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\inc\commonQueue.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-26 13:38:47
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-27 00:27:22
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
Queue *initQueue(int k);
void enQueue(Queue *obj, int x);
int deQueue(Queue *obj);
int isQueueEmpty(Queue *obj);

#endif  /* __COMMON_QUEUE_H */