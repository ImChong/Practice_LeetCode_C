/*
 * @FilePath     : \Practice_LeetCode_C\F01_Common_Functions\inc\commonQueue.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-26 13:38:47
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-18 23:05:25
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : Common queue header file
 */
#ifndef F01_COMMON_FUNCTIONS_INC_COMMON_QUEUE_H_
#define F01_COMMON_FUNCTIONS_INC_COMMON_QUEUE_H_

/**********************************************************************************/
/*                                                                                */
/*                                 GLOBAL VARIABLES                               */
/*                                                                                */
/**********************************************************************************/
/* Queue structure */
typedef struct {
    int *list; /* Data list */
    int head;  /* Queue head */
    int tail;  /* Queue tail */
    int size;  /* Queue size */
} Queue;

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
Queue *Queue_Init(int queueSize);     /* Initialize queue */
void Queue_En(Queue *queue, int val); /* Enqueue */
int Queue_De(Queue *queue);           /* Dequeue */
int Queue_IsEmpty(Queue *queue);      /* Check if queue is empty */
int Queue_IsFull(Queue *queue);       /* Check if queue is full */

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
void Queue_Print(Queue *queue); /* Print queue */
void Queue_Free(Queue *queue);  /* Free queue */

#endif /* F01_COMMON_FUNCTIONS_INC_COMMON_QUEUE_H_ */
