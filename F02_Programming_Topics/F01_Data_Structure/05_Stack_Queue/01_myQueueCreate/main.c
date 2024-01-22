/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\06_Stack_Queue\01_myQueueCreate\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-27 01:10:12
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-27 01:16:08
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 232. 用栈实现队列：https://leetcode.cn/problems/implement-queue-using-stacks/
 * https://programmercarl.com/0232.%E7%94%A8%E6%A0%88%E5%AE%9E%E7%8E%B0%E9%98%9F%E5%88%97.html
 * https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0232.%E7%94%A8%E6%A0%88%E5%AE%9E%E7%8E%B0%E9%98%9F%E5%88%97.md
 */
#include <stdio.h>
#include "myQueue_double_stack.h"

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
    MyQueue *myQueue = myQueueCreate();
    myQueuePush(myQueue, 1);
    myQueuePush(myQueue, 2);
    printf("myQueuePeek: %d \n", myQueuePeek(myQueue));
    printf("myQueuePop: %d \n", myQueuePop(myQueue));
    printf("myQueueEmpty: %d \n", myQueueEmpty(myQueue));
    myQueueFree(myQueue);
}

/**
 * @description: 测试 2
 * =================================================================================
 * @return {void}
 */
void Test2(void) {
    /* Function call (函数调用) */

    /* Expect result (期望结果) */

    /* Validate result (验证函数调用结果) */

}

/**
 * @description: 测试 3
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
 * @description: 主函数
 * =================================================================================
 * @param {int} argc        程序入参个数
 * @param {char} *argv[]    程序入参字符串数组
 * @return {int}            程序运行状态
 */
int main(int argc, const char *argv[]) {
    Test1();
    return 0;
}