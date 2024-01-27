/*
 * @FilePath     : \Practice_LeetCode_C\F01_Common_Functions\inc\common_stack.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-26 13:36:39
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-27 11:27:31
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : Common stack header file
 */
#ifndef F01_COMMON_FUNCTIONS_INC_COMMON_STACK_H_
#define F01_COMMON_FUNCTIONS_INC_COMMON_STACK_H_

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
Stack *Stack_Init(int capacity);    /* Initialize stack */
void Stack_Push(Stack *obj, int x); /* Push element x onto stack */
void Stack_Pop(Stack *obj);         /* Pop an element from the stack */
int Stack_Top(Stack *obj);          /* Check the top element of the stack */
bool Stack_IsEmpty(Stack *obj);     /* Check whether the stack is empty */
bool Stack_IsFull(Stack *obj);      /* Check whether the stack is full */

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
void Stack_Print(Stack *obj); /* Print stack */
void Stack_Free(Stack *obj);  /* Free stack */

#endif /* F01_COMMON_FUNCTIONS_INC_COMMON_STACK_H_ */
