/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\06_Stack_Queue\02_myStackCreate\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-27 00:35:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-27 02:55:14
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 225. 用队列实现栈：https://leetcode.cn/problems/implement-stack-using-queues/
 * https://programmercarl.com/0225.%E7%94%A8%E9%98%9F%E5%88%97%E5%AE%9E%E7%8E%B0%E6%A0%88.html
 * https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0225.%E7%94%A8%E9%98%9F%E5%88%97%E5%AE%9E%E7%8E%B0%E6%A0%88.md
 */
#include <stdio.h>
#include "methodCfg.h"
#if SINGLE_QUEUE_METHOD_EN
#include "myStack_single_queue.h"
#elif DOUBLE_QUEUE_METHOD_EN
#include "myStack_double_queue.h"
#endif

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: Test 1
 * =================================================================================
 * @return {void}
 */
void Test1(void) {
    /* Function call (函数调用) */

    /* Expect result (期望结果) */

    /* Validate result (验证函数调用结果) */

    /* Test case 1 */
    printf("======== Case 1 ======== \n");
    MyStack *myStack = myStackCreate();
    myStackPush(myStack, 1);
    myStackPush(myStack, 2);
    printf("myStackTop: %d \n", myStackTop(myStack));
    printf("myStackPop: %d \n", myStackPop(myStack));
    printf("myStackEmpty: %d \n", myStackEmpty(myStack));
    myStackFree(myStack);
}

/**
 * @description: Test 2
 * =================================================================================
 * @return {void}
 */
void Test2(void) {
    /* Function call (函数调用) */

    /* Expect result (期望结果) */

    /* Validate result (验证函数调用结果) */

}

/**
 * @description: Test 3
 * =================================================================================
 * @return {void}
 */
void Test3(void) {
    /* Function call (函数调用) */

    /* Expect result (期望结果) */

    /* Validate result (验证函数调用结果) */

}

/**********************************************************************************/
/*                                                                                */
/*                                  MAIN FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: Main function, entry of program.
 * =================================================================================
 * @param {int} argc        程序入参个数
 * @param {char} *argv[]    程序入参字符串数组
 * @return {int}            程序运行状态
 */
int main(int argc, const char *argv[]) {
    Test1();
    return 0;
}