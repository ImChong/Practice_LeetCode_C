/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\06_canConstruct\src\canConstruct.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-11-01 22:54:19
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-20 23:18:07
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 赎金信源文件
 */
/* 解题方法配置文件 */
#include "methodCfg.h"
#if HASH_TABLE_METHOD_EN
/* 标准头文件 */
#include <stdbool.h>

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 赎金信
 * 该函数接受两个参数 ransomNote 和 magazine，分别表示勒索信和杂志。
 * 函数的返回值为布尔类型，表示勒索信是否可以用杂志中的字符构造出来。
 *
 * 函数的实现思路是，首先遍历杂志中的字符，统计每个字符出现的次数，
 * 然后遍历勒索信中的字符，每遇到一个字符就将其在计数器中的数量减一，
 * 如果减一后数量小于零，则说明杂志中没有足够的该字符，无法构造出勒索信，返回 false。
 * 如果遍历完勒索信中的所有字符后都没有返回 false，则说明可以构造出勒索信，返回 true。
 * =================================================================================
 * @param {char} *ransomNote        勒索信
 * @param {char} *magazine          杂志
 * @return {bool}                   是否可以构造
 */
bool canConstruct(char *ransomNote, char *magazine) {
    int counter[26] = {0};                              /* 计数器 */

    for (int i = 0; magazine[i] != '\0'; i++) {         /* 统计杂志中的字符出现的次数 */
        counter[magazine[i] - 'a']++;                       /* 以字符的 ASCII 码作为数组下标，每遇到一个字符就将其在计数器中的数量 + 1 */
    }

    for (int i = 0; ransomNote[i] != '\0'; i++) {       /* 遍历勒索信中的字符 */
        counter[ransomNote[i] - 'a']--;                     /* 每遇到一个字符就将其在计数器中的数量 - 1 */

        if (counter[ransomNote[i] - 'a'] < 0) {             /* 如果减一后数量小于零 */
            return false;                                       /* 则说明杂志中没有足够的该字符，无法构造出勒索信，返回 false */
        }
    }
    return true;                                        /* 如果遍历完勒索信中的所有字符后都没有返回 false，则说明可以构造出勒索信，返回 true */
}


#endif /* HASH_TABLE_METHOD_EN */