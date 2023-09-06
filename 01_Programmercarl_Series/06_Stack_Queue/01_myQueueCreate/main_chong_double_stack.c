/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\06_Stack_Queue\01_myQueueCreate\main_chong_double_stack.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-28 09:44:35
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-09-06 20:08:33
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 232. 用栈实现队列：https://leetcode.cn/problems/implement-queue-using-stacks/
 * https://programmercarl.com/0232.%E7%94%A8%E6%A0%88%E5%AE%9E%E7%8E%B0%E9%98%9F%E5%88%97.html
 * https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0232.%E7%94%A8%E6%A0%88%E5%AE%9E%E7%8E%B0%E9%98%9F%E5%88%97.md
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* ==================================================================================================== */
/* TODO: 添加注释 */
/* ==================================================================================================== */
/* NOTE: 栈结构体 */
typedef struct {
    int *stk;           /* 栈数组：用于存储数据 */
    int stkSize;        /* 栈大小：记录当前栈的大小 */
    int stkCapacity;    /* 栈容量：记录栈大小的最大值 */
} Stack;                /* 重命名结构体为 Stack */

/**
 * @description: 创建栈
 * =================================================================================
 * @param {int} capacity
 * @return {Stack *} ret
 */
Stack *stackCreate(int capacity) {
    Stack *ret = (Stack *)malloc(sizeof(Stack));        /* 为栈结构体分配空间 */
    ret->stk = (int *)malloc(sizeof(int) * capacity);   /* 为栈数组分配空间，大小为最大容量 */
    ret->stkSize = 0;                                   /* 当前栈大小为0 */
    ret->stkCapacity = capacity;                        /* 记录栈容量 */
    return ret;                                         /* 返回创建的栈结构体 */
}

/**
 * @description: 入栈
 * =================================================================================
 * @param {Stack *} obj
 * @param {int} x
 * @return {void}
 */
void stackPush(Stack *obj, int x) {
    obj->stk[obj->stkSize++] = x;                       /* 将数据存入栈结构体内数组的【栈大小】索引位置，存入后将【栈大小】+ 1 */
}

/**
 * @description: 出栈
 * =================================================================================
 * @param {Stack *} obj
 * @return {void}
 */
void stackPop(Stack *obj) {
    obj->stkSize--;                                     /* 将【栈大小】- 1 */
}

/**
 * @description: 查看栈顶元素
 * =================================================================================
 * @param {Stack *} obj
 * @return {int} 栈顶元素
 */
int stackTop(Stack *obj) {
    return obj->stk[obj->stkSize - 1];                  /* 返回栈结构体内【栈大小 - 1】索引位置处的数据 */
}

/**
 * @description: 确认栈是否为空
 * =================================================================================
 * @param {Stack *} obj
 * @return {bool} 栈是否为空
 */
bool stackEmpty(Stack* obj) {
    return obj->stkSize == 0;                           /* 返回确认 stkSize 栈大小是否为0 */
}

/**
 * @description: 释放栈空间
 * =================================================================================
 * @param {Stack *} obj
 * @return {void}
 */
void stackFree(Stack* obj) {
    free(obj->stk);                                     /* 释放栈结构体内 stk 数组的空间 */
}

/* NOTE: 队列结构体 */
typedef struct {
    Stack *inStack;     /* 入队栈 */
    Stack *outStack;    /* 出队栈 */
} MyQueue;              /* 重命名结构体为 MyQueue */

/**
 * @description: 创建队列
 * =================================================================================
 * @return {MyQueue *} ret
 */
MyQueue *myQueueCreate(void) {
    MyQueue *ret = (MyQueue *)malloc(sizeof(MyQueue));  /* 为队列结构体分配空间 */
    ret->inStack = stackCreate(100);                    /* 入队栈初始化可容纳 100 数据 */
    ret->outStack = stackCreate(100);                   /* 出队栈初始化可容纳 100 数据 */
    return ret;                                         /* 返回创建的队列结构体 */
}

/**
 * @description: 从入队栈反向并移动至出队栈
 * =================================================================================
 * @param {MyQueue *} obj
 * @return {void}
 */
void in2out(MyQueue *obj) {
    while (!stackEmpty(obj->inStack)) {                     /* 当入队栈不为空时 */
        stackPush(obj->outStack, stackTop(obj->inStack));       /* 将入队栈的栈顶元素放入出队栈 */
        stackPop(obj->inStack);                                 /* 去除入队栈的栈顶元素 */
    }
}

/**
 * @description: 入队
 * =================================================================================
 * @param {MyQueue *} obj
 * @param {int} x
 * @return {void}
 */
void myQueuePush(MyQueue* obj, int x) {
    stackPush(obj->inStack, x);                             /* 将元素放入入队栈 */
}

/**
 * @description: 出队
 * =================================================================================
 * @param {MyQueue *} obj
 * @return {int} x
 */
int myQueuePop(MyQueue* obj) {
    if (stackEmpty(obj->outStack)) {                        /* 如果出队栈为空 */
        in2out(obj);                                            /* 将入队栈内所有元素反向放入出队栈 */
    }
    int x = stackTop(obj->outStack);
    stackPop(obj->outStack);
    return x;
}

/**
 * @description: 查看队首元素
 * =================================================================================
 * @param {MyQueue *} obj
 * @return {int} 队首元素
 */
int myQueuePeek(MyQueue* obj) {
    if (stackEmpty(obj->outStack)) {
        in2out(obj);
    }
    return stackTop(obj->outStack);
}

/**
 * @description: 确认队列是否为空
 * =================================================================================
 * @param {MyQueue *} obj
 * @return {bool} 队列是否为空
 */
bool myQueueEmpty(MyQueue* obj) {
    return (stackEmpty(obj->inStack) && stackEmpty(obj->outStack));
}

/**
 * @description: 释放队列空间
 * =================================================================================
 * @param {MyQueue *} obj
 * @return {*}
 */
void myQueueFree(MyQueue* obj) {
    stackFree(obj->inStack);
    stackFree(obj->outStack);
}
/* ==================================================================================================== */
/* ==================================================================================================== */

/**
 * @description: 主函数
 * =================================================================================
 * @param {int} argc
 * @param {char*} argv
 * @return {int}
 */
int main(int argc, const char* argv[]) {
    /* NOTE: Test case 1 */
    printf("======== Case 1 ======== \n");
    MyQueue *myQueue = myQueueCreate();
    myQueuePush(myQueue, 1);
    myQueuePush(myQueue, 2);
    printf("myQueuePeek: %d \n", myQueuePeek(myQueue));
    printf("myQueuePop: %d \n", myQueuePop(myQueue));
    printf("myQueueEmpty: %d \n", myQueueEmpty(myQueue));
    myQueueFree(myQueue);
    return 0;
}