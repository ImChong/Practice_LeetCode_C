/*
 * @FilePath     : \Practice_LeetCode_C\F01_Common_Functions\inc\commonStack.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-26 13:36:39
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-18 23:15:33
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : Common stack header file
 */
#ifndef F01_COMMON_FUNCTIONS_INC_COMMONSTACK_H_
#define F01_COMMON_FUNCTIONS_INC_COMMONSTACK_H_

/* Standard header file (标准头文件) */
#include <stdbool.h>

/**********************************************************************************/
/*                                                                                */
/*                                 GLOBAL VARIABLES                               */
/*                                                                                */
/**********************************************************************************/
/* Stack structure */
typedef struct {
    int *stk;        /* Stack array */
    int stkSize;     /* Stack size */
    int stkCapacity; /* Stack capacity */
} Stack;             /* Rename struct Stack to Stack */

/**********************************************************************************/
/*                                                                                */
/*                                 UTILITY FUNCTIONS                              */
/*                                                                                */
/**********************************************************************************/
Stack *Stack_Init(int capacity);    /* 创建栈 */
void Stack_Push(Stack *obj, int x); /* 入栈 */
void Stack_Pop(Stack *obj);         /* 出栈 */
int Stack_Top(Stack *obj);          /* 查看栈顶元素 */
bool Stack_IsEmpty(Stack *obj);     /* 判断栈是否为空 */
bool Stack_IsFull(Stack *obj);      /* 判断栈是否为满 */

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
void Stack_Print(Stack *obj); /* 打印栈 */
void Stack_Free(Stack *obj);  /* 释放栈 */

#endif /* F01_COMMON_FUNCTIONS_INC_COMMONSTACK_H_ */
