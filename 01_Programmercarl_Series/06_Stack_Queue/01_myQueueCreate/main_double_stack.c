/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\06_Stack_Queue\01_myQueueCreate\main_double_stack.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-28 09:44:35
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-26 23:58:33
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
#include "commonStack.h"



/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/* 用两个栈实现队列：入队栈 和 出队栈 */
/* 每次读取数据的时候将入队栈元素全部压入出队栈，并读取出队栈的栈顶元素 */
/* ============================================================================== */
/* ============================================================================== */
/* 队列结构体 */
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
void myQueuePush(MyQueue *obj, int x) {
    stackPush(obj->inStack, x);                             /* 将元素放入入队栈 */
}

/**
 * @description: 出队
 * =================================================================================
 * @param {MyQueue *} obj
 * @return {int} x
 */
int myQueuePop(MyQueue *obj) {
    if (stackEmpty(obj->outStack)) {                        /* 如果出队栈为空 */
        in2out(obj);                                            /* 将入队栈内所有元素反向放入出队栈 */
    }
    int x = stackTop(obj->outStack);                        /* 取出出队栈的栈顶元素，并赋值给 x */
    stackPop(obj->outStack);                                /* 移除出队栈内的栈顶元素 */
    return x;                                               /* 返回出队栈栈顶元素 x */
}

/**
 * @description: 查看队首元素
 * =================================================================================
 * @param {MyQueue *} obj
 * @return {int} 队首元素
 */
int myQueuePeek(MyQueue *obj) {
    if (stackEmpty(obj->outStack)) {                        /* 如果出队栈为空 */
        in2out(obj);                                            /* 将入队栈内所有元素反向放入出队栈 */
    }
    return stackTop(obj->outStack);                         /* 返回出队栈栈顶元素 */
}

/**
 * @description: 确认队列是否为空
 * =================================================================================
 * @param {MyQueue *} obj
 * @return {bool} 队列是否为空
 */
bool myQueueEmpty(MyQueue* obj) {
    return (stackEmpty(obj->inStack) && stackEmpty(obj->outStack));     /* 返回入队栈和出队栈是否都为空 */
}

/**
 * @description: 释放队列空间
 * =================================================================================
 * @param {MyQueue *} obj
 * @return {*}
 */
void myQueueFree(MyQueue* obj) {
    stackFree(obj->inStack);                                /* 释放入队栈空间 */
    stackFree(obj->outStack);                               /* 释放出队栈空间 */
}

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 验证答案
 * =================================================================================
 * @param {char} testNum    测试编号
 * @param {int} expect      预期
 * @param {int} actual      实际
 * @return {void}
 */
void validateSingleValue(char testNum, int expect, int actual) {
    if (expect == actual) {
        printf("✅ Test %c Passed\n", testNum);
    } else {
        printf("❌ Test %c Failed\n", testNum);
    }
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
 * @param {int} argc
 * @param {char*} argv[]
 * @return {int}
 */
int main(int argc, const char* argv[]) {
    /* Test case 1 */
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