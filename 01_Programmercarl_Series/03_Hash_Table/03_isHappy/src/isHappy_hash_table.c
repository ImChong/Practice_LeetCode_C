/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\03_isHappy\src\isHappy_hash_table.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-30 23:45:15
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-13 23:40:25
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 快乐数 - 哈希表法源文件
 */
/* 解题方法配置文件 */
#include "methodCfg.h"
#if HASH_TABLE_METHOD_EN
/* 标准头文件 */
#include <stdbool.h>
/* 通用头文件 */
#include "commonFunc.h"
/* 本文件头文件 */
#include "isHappy_hash_table.h"

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
 * 快乐数是指对于一个正整数，如果对其各个位上的数字分别平方，然后再将得到的数相加，最终结果为1，则该数为快乐数。
 * 这段代码使用了一个哈希表算法来判断一个数字是否为快乐数。
 * sum = a1^2 + a2^2 + ... ak^2
 *  first round:
 *      1 <= k <= 10
 *      1 <= sum <= 1 + 81 * 9 = 730
 *  second round:
 *      1 <= k <= 3
 *      1 <= sum <= 36 + 81 * 2 = 198
 *  third round:
 *      1 <= sum <= 81 * 2 = 162
 *  fourth round:
 *      1 <= sum <= 81 * 2 = 162
 * =================================================================================
 * @param {int} n       当前数字
 * @return {bool}       是否为快乐数
 */
bool isHappy(int n) {
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //

    int visited[163] = { 0 };
    int sum = getNext(getNext(n));
    int next_n = sum;

    while (next_n != 1) {
        sum = getNext(next_n);

        if (visited[sum]) return false;

        visited[sum] = 1;
        next_n = sum;
    };

    return true;
}

#endif  /* HASH_TABLE_METHOD_EN */