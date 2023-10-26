/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\src\commonStack.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-26 13:36:54
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-27 02:26:27
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用栈源文件
 */
#include "compileCfg.h"

#if STACK_MODULE_EN
#include <stdlib.h>
#include <stdbool.h>
#include "commonStack.h"

/**********************************************************************************/
/*                                                                                */
/*                                 UTILITY FUNCTIONS                              */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 创建栈
 * =================================================================================
 * @param {int} capacity        栈容量
 * @return {Stack} *ret         返回创建的栈结构体
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
 * @param {Stack *} obj     栈结构体
 * @param {int} x           入栈元素
 * @return {void}
 */
void stackPush(Stack *obj, int x) {
    obj->stk[obj->stkSize++] = x;                       /* 将数据存入栈结构体内数组的【栈大小】索引位置，存入后将【栈大小】+ 1 */
}

/**
 * @description: 出栈
 * =================================================================================
 * @param {Stack *} obj     栈结构体
 * @return {void}
 */
void stackPop(Stack *obj) {
    obj->stkSize--;                                     /* 将【栈大小】- 1 */
}

/**
 * @description: 查看栈顶元素
 * =================================================================================
 * @param {Stack *} obj     栈结构体
 * @return {int} x          栈顶元素
 */
int stackTop(Stack *obj) {
    return obj->stk[obj->stkSize - 1];                  /* 返回栈结构体内【栈大小 - 1】索引位置处的数据 */
}

/**
 * @description: 确认栈是否为空
 * =================================================================================
 * @param {Stack *} obj     栈结构体
 * @return {bool}           栈是否为空
 */
bool stackEmpty(Stack *obj) {
    return obj->stkSize == 0;                           /* 返回确认 stkSize 栈大小是否为0 */
}

/**
 * @description: 释放栈空间
 * =================================================================================
 * @param {Stack *} obj     栈结构体
 * @return {void}
 */
void stackFree(Stack *obj) {
    free(obj->stk);                                     /* 释放栈结构体内 stk 数组的空间 */
}


#endif /* STACK_MODULE_EN */