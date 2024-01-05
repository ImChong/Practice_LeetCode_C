/*
 * @FilePath     : \Practice_LeetCode_C\01_Common_Functions\inc\commonStack.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-26 13:36:39
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-06 00:55:52
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用栈头文件
 */
#ifndef __COMMON_STACK_H        /* NOLINT(build/header_guard) */
#define __COMMON_STACK_H        /* NOLINT(build/header_guard) */

/* standard header file (标准头文件) */
#include <stdbool.h>

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
Stack *Stack_Init(int capacity);       /* 创建栈 */
void Stack_Push(Stack *obj, int x);      /* 入栈 */
void Stack_Pop(Stack *obj);              /* 出栈 */
int Stack_Top(Stack *obj);               /* 查看栈顶元素 */
bool Stack_IsEmpty(Stack *obj);            /* 判断栈是否为空 */
bool Stack_IsFull(Stack *obj);             /* 判断栈是否为满 */

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
void Stack_Print(Stack *obj);            /* 打印栈 */
void Stack_Free(Stack *obj);             /* 释放栈 */


#endif  /* __COMMON_STACK_H */      /* NOLINT(build/header_guard) */
