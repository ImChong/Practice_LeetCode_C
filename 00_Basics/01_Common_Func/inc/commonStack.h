/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\inc\commonStack.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-26 13:36:39
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-27 00:05:44
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用栈头文件
 */
#ifndef __COMMON_STACK_H
#define __COMMON_STACK_H

/**********************************************************************************/
/*                                                                                */
/*                                 GLOBAL VARIABLES                               */
/*                                                                                */
/**********************************************************************************/
/* 栈结构体 */
typedef struct {
    int *stk;           /* 栈数组：用于存储数据 */
    int stkSize;        /* 栈大小：记录当前栈的大小 */
    int stkCapacity;    /* 栈容量：记录栈大小的最大值 */
} Stack;                /* 重命名结构体为 Stack */

/**********************************************************************************/
/*                                                                                */
/*                                 UTILITY FUNCTIONS                              */
/*                                                                                */
/**********************************************************************************/
Stack *stackCreate(int capacity);       /* 创建栈 */
void stackPush(Stack *obj, int x);      /* 入栈 */
void stackPop(Stack *obj);              /* 出栈 */
int stackTop(Stack *obj);               /* 查看栈顶元素 */
bool stackEmpty(Stack *obj);            /* 判断栈是否为空 */
void stackFree(Stack *obj);             /* 释放栈 */


#endif  /* __COMMON_STACK_H */