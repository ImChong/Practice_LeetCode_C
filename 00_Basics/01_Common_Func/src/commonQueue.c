/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\src\commonQueue.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-26 13:40:03
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-23 15:01:50
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用队列源文件
 */
/* 编译配置文件 */
#include "compileCfg.h"
#if COMMON_QUEUE_EN         /* 在每一道题 cfg 文件夹下的 compileCfg.h 开启编译宏定义 */
/* 标准头文件 */
#include <stdlib.h>
/* 常用头文件 */
#include "commonQueue.h"

/**********************************************************************************/
/*                                                                                */
/*                                 UTILITY FUNCTIONS                              */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 初始化队列
 * =================================================================================
 * @param {int} k           数据长度
 * @return {Queue} *obj     初始化后队列的指针
 */
Queue *initQueue(int k) {
    Queue *obj = (Queue *)malloc(sizeof(Queue));    /* 为队列分配空间 */
    obj->data = (int *)malloc(sizeof(int) * k);     /* 为队列内数组分配空间，大小为 k */
    obj->head = -1;                                 /* 队列头初始化为 -1 */
    obj->tail = -1;                                 /* 队列尾初始化为 -1 */
    obj->size = k;                                  /* 队列大小为 k */
    return obj;                                     /* 返回初始化后的队列对象指针 */
}

/**
 * @description: 入队
 * =================================================================================
 * @param {Queue} *obj      队列指针
 * @param {int} x           入队元素
 * @return {void}
 */
void enQueue(Queue *obj, int x) {
    if (obj->head == -1) {                      /* 如果队列头为索引 -1 */
        obj->head = 0;                          /* 将队列头改为索引 0 */
    }
    obj->tail = (obj->tail + 1) % obj->size;    /* 队列尾 + 1，（% obj->size）是为了防止新添加的元素超出队列内数组大小。超出部分从 0 开始：环形队列 */
    obj->data[obj->tail] = x;                   /* 将元素添加至队列内数组，索引为队列尾所指索引 */
}

/**
 * @description: 出队
 * =================================================================================
 * @param {Queue} *obj      队列指针
 * @return {int} a          队首元素
 */
int deQueue(Queue *obj) {
    int a = obj->data[obj->head];               /* 取出队首元素并赋值给 a */
    if (obj->head == obj->tail) {               /* 如果队列头索引等于队列尾索引 */
        obj->head = -1;                             /* 队列头索引设置为 -1 */
        obj->tail = -1;                             /* 队列尾索引设置为 -1 */
        return a;                                   /* 返回之前取出的队首元素 */
    }
    obj->head = (obj->head + 1) % obj->size;    /* 队列头 + 1，（% obj->size）是为了防止新队列头索引超出队列内数组大小。超出部分从 0 开始：环形队列 */
    return a;                                   /* 返回之前取出的队首元素 */
}

/**
 * @description: 判读队列是否为空
 * =================================================================================
 * @param {Queue} *obj      队列指针
 * @return {int}            0：队列不为空，1：队列为空
 */
int isQueueEmpty(Queue *obj) {
    return obj->head == -1;                     /* 判断队列头是否为 -1，若队列头为 -1 则队列为空 */
}

/**
 * @description: 释放队列空间
 * =================================================================================
 * @param {Queue} *obj      队列指针
 * @return {void}
 */
void freeQueue(Queue *obj) {
    free(obj->data);                            /* 释放队列内数组空间 */
    obj->data = NULL;                           /* 将队列内数组指针置空 */
    free(obj);                                  /* 释放队列空间 */
    obj = NULL;                                 /* 将队列指针置空 */
}


#endif      /* COMMON_QUEUE_EN */