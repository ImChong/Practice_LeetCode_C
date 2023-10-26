/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\06_Stack_Queue\02_myStackCreate\main_double_queue.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-25 20:30:05
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-27 00:31:53
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 225. 用队列实现栈：https://leetcode.cn/problems/implement-stack-using-queues/
 * https://programmercarl.com/0225.%E7%94%A8%E9%98%9F%E5%88%97%E5%AE%9E%E7%8E%B0%E6%A0%88.html
 * https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0225.%E7%94%A8%E9%98%9F%E5%88%97%E5%AE%9E%E7%8E%B0%E6%A0%88.md
 *
 * 方法一：用两个队列实现栈
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "commonQueue.h"

/**********************************************************************************/
/*                                                                                */
/*                                MACRO CONSTANTS                                 */
/*                                                                                */
/**********************************************************************************/
#define LEN 20      /* 长度为 20 */

/**********************************************************************************/
/*                                                                                */
/*                                 GLOBAL VARIABLES                               */
/*                                                                                */
/**********************************************************************************/
typedef struct {
    Queue *queue1;  /* 队列 1 */
    Queue *queue2;  /* 队列 2 */
} MyStack;          /* 栈结构体：包含两个队列 */

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
    obj->queue1 = initQueue(LEN);                       /* 初始化队列 1 大小为 20 */
    obj->queue2 = initQueue(LEN);                       /* 初始化队列 2 大小为 20 */
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
    if (isQueueEmpty(obj->queue1)) {        /* 如果队列 1 为空 */
        enQueue(obj->queue2, x);                /* 将元素入队队列 2 */
    } else {                                /* 如果队列 1 不为空 */
        enQueue(obj->queue1, x);                /* 将元素入队队列 1 */
    }
}

/**
 * @description: 出栈
 * =================================================================================
 * @param {MyStack} *obj    栈指针
 * @return {int}            出栈元素
 */
int myStackPop(MyStack *obj) {
    if (isQueueEmpty(obj->queue1)) {                        /* 如果队列 1 为空 */
        while (obj->queue2->head != obj->queue2->tail) {        /* 当队列 2 的队首元素索引不等于队列 2 队尾元素索引时 */
            enQueue(obj->queue1, deQueue(obj->queue2));             /* 将队列 2 的队首元素放入队列 1 的队尾 */
        }
        return deQueue(obj->queue2);                            /* 返回队列 2 的队首元素 */
    }
    while (obj->queue1->head != obj->queue1->tail) {        /* 如果队列 1 的队首元素索引不等于队列 1 队尾元素索引时 */
        enQueue(obj->queue2, deQueue(obj->queue1));             /* 将队列 1 的队首元素放入队列 2 的队尾 */
    }
    return deQueue(obj->queue1);                            /* 返回队列 1 的队首元素 */
}

/**
 * @description: 获取栈顶元素
 * =================================================================================
 * @param {MyStack} *obj    栈指针
 * @return {int}            栈顶元素
 */
int myStackTop(MyStack* obj) {
    if (isQueueEmpty(obj->queue1)) {                        /* 如果队列 1 为空 */
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
    freeQueue(obj->queue1);         /* 释放队列 1 空间 */
    freeQueue(obj->queue2);         /* 释放队列 2 空间 */
    free(obj);                      /* 释放栈内存 */
    obj = NULL;                     /* 将栈指针指向 NULL */
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试 1
 * =================================================================================
 * @return {void}
 */
void test_1(void) {
    /* 实际结果 */

    /* 预期结果 */

    /* 比较结果 */

}

/**
 * @description: 测试 2
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */

    /* 预期结果 */

    /* 比较结果 */

}

/**
 * @description: 测试 3
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    /* 实际结果 */

    /* 预期结果 */

    /* 比较结果 */

}

/**********************************************************************************/
/*                                                                                */
/*                                  MAIN FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 主函数
 * =================================================================================
 * @param {int} argc        程序入参个数
 * @param {char} *argv[]    程序入参字符串数组
 * @return {int}            程序运行状态
 */
int main(int argc, const char *argv[]) {
    /* Test case 1 */
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