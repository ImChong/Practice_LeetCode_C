/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\inc\commonStack.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-26 13:36:39
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-27 00:03:52
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
Stack *stackCreate(int capacity);
void stackPush(Stack *obj, int x);
void stackPop(Stack *obj);
int stackTop(Stack *obj);
bool stackEmpty(Stack *obj);
void stackFree(Stack *obj);


#endif  /* __COMMON_STACK_H */