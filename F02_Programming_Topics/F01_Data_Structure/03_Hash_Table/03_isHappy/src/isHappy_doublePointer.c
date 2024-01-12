/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\03_isHappy\src\isHappy_doublePointer.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-30 23:45:33
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-23 23:39:00
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 快乐数 - 双指针解法源文件
 */

/* solution method configuration file (解题方法配置文件) */
#include "methodCfg.h"
#if FAST_SLOW_POINTER_METHOD_EN
/* Standard header file (标准头文件) */
#include <stdbool.h>
/* common function header file (通用头文件) */
#include "commonFunc.h"
/* solution header file (题解头文件) */
#include "isHappy.h"

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 快乐数
 * isHappy函数用于判断一个数字是否为快乐数。
 *
 * 这段代码使用了一个类似于快慢指针的算法来判断一个数字是否为快乐数。
 *
 * 该算法使用两个指针，一个慢指针和一个快指针，每次慢指针移动一位，快指针移动两位，
 *      直到快指针指向的值为1或者快慢指针指向的值相同时，判断该数是否为快乐数。
 *      如果是快乐数，则返回true，否则返回false。
 * =================================================================================
 * @param {int} n       当前数字
 * @return {bool}       是否为快乐数
 */
bool isHappy(int n) {
    int slow = n;                           /* 初始化慢指针：指向当前数值 */
    int fast = getNext(n);                  /* 初始化快指针：指向下一数值 */
    while (fast != 1 && slow != fast) {     /* 当快指针的值不为 1 且快指针与慢指针指向的值不相同时，保持循环 */
        slow = getNext(slow);                   /* 慢指针一次移动一位 */
        fast = getNext(getNext(fast));          /* 快指针一次移动两位 */
    }
    return fast == 1;                       /* 当开始循环且快慢指针指向的值都为 1 时，返回 true */
}

#endif  /* FAST_SLOW_POINTER_METHOD_EN */