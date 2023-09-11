/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\06_Stack_Queue\02_myStackCreate\main_chong_double_queue.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-25 20:30:05
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-09-11 14:21:50
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 225. 用队列实现栈：https://leetcode.cn/problems/implement-stack-using-queues/
 * https://programmercarl.com/0225.%E7%94%A8%E9%98%9F%E5%88%97%E5%AE%9E%E7%8E%B0%E6%A0%88.html
 * https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0225.%E7%94%A8%E9%98%9F%E5%88%97%E5%AE%9E%E7%8E%B0%E6%A0%88.md
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* ==================================================================================================== */
/* 方法一：用两个队列实现栈 */
/* ==================================================================================================== */
#define LEN 20      /* 长度为 20 */

typedef struct {
    int *data;      /* 数据 */
    int head;       /* 队列头 */
    int tail;       /* 队列尾 */
    int size;       /* 队列大小 */
} Queue;

typedef struct {
    Queue *queue1;  /* 队列 1 */
    Queue *queue2;  /* 队列 2 */
} MyStack;          /* 栈结构体：包含两个队列 */

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
    return obj;

    int a[10] = {0};
    int *a = (int *)malloc(sizeof(int) * 10);
}

/**
 * @description:
 * =================================================================================
 * @param {Queue} *obj
 * @param {int} x
 * @return {*}
 */
void enQueue(Queue *obj, int x) {
    if (obj->head == -1) {
        obj->head = 0;
    }
    obj->tail = (obj->tail + 1) % obj->size;
    obj->data[obj->tail] = x;
}

/**
 * @description:
 * =================================================================================
 * @param {Queue} *obj
 * @return {*}
 */
int deQueue(Queue *obj) {
    int a = obj->data[obj->head];
    if (obj->head == obj->tail) {
        obj->head = -1;
        obj->tail = -1;
        return a;
    }
    obj->head = (obj->head + 1) % obj->size;
    return a;
}

/**
 * @description:
 * =================================================================================
 * @param {Queue} *obj
 * @return {*}
 */
int isQueueEmpty(Queue *obj) {
    return obj->head == -1;
}

/**
 * @description:
 * =================================================================================
 * @return {*}
 */
MyStack* myStackCreate() {
    MyStack *obj = (MyStack *)malloc(sizeof(MyStack));
    obj->queue1 = initQueue(LEN);
    obj->queue2 = initQueue(LEN);
    return obj;
}

/**
 * @description:
 * =================================================================================
 * @param {MyStack*} obj
 * @param {int} x
 * @return {*}
 */
void myStackPush(MyStack* obj, int x) {
    if (isQueueEmpty(obj->queue1)) {
        enQueue(obj->queue2, x);
    } else {
        enQueue(obj->queue1, x);
    }
}

/**
 * @description:
 * =================================================================================
 * @param {MyStack*} obj
 * @return {*}
 */
int myStackPop(MyStack* obj) {
    if (isQueueEmpty(obj->queue1)) {
        while (obj->queue2->head != obj->queue2->tail) {
            enQueue(obj->queue1, deQueue(obj->queue2));
        }
        return deQueue(obj->queue2);
    }
    while (obj->queue1->head != obj->queue1->tail) {
        enQueue(obj->queue2, deQueue(obj->queue1));
    }
    return deQueue(obj->queue1);
}

/**
 * @description:
 * =================================================================================
 * @param {MyStack*} obj
 * @return {*}
 */
int myStackTop(MyStack* obj) {
    if (isQueueEmpty(obj->queue1)) {
        return obj->queue2->data[obj->queue2->tail];
    }
    return obj->queue1->data[obj->queue1->tail];
}

/**
 * @description:
 * =================================================================================
 * @param {MyStack*} obj
 * @return {*}
 */
bool myStackEmpty(MyStack* obj) {
    if (obj->queue1->head == -1 && obj->queue2->head == -1) {
        return true;
    }
    return false;
}

/**
 * @description:
 * =================================================================================
 * @param {MyStack*} obj
 * @return {*}
 */
void myStackFree(MyStack* obj) {
    free(obj->queue1->data);
    obj->queue1->data = NULL;
    free(obj->queue1);
    obj->queue1 = NULL;
    free(obj->queue2->data);
    obj->queue2->data = NULL;
    free(obj->queue2);
    obj->queue2 = NULL;
    free(obj);
    obj = NULL;
}
/* ==================================================================================================== */
/* ==================================================================================================== */

/**
 * @description: 主函数
 * =================================================================================
 * @param {int} argc
 * @param {char*} argv
 * @return {*}
 */
int main(int argc, const char *argv[]) {
    /* NOTE: Test case 1 */
    printf("======== Case 1 ======== \n");
    MyStack *myStack = myStackCreate();
    myStackPush(myStack, 1);
    myStackPush(myStack, 2);
    printf("myStackTop: %d \n", myStackTop(myStack));
    printf("myStackPop: %d \n", myStackPop(myStack));
    printf("myStackEmpty: %d \n", myStackEmpty(myStack));
    myStackFree(myStack);
    return 0;
}