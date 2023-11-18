/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\03_isHappy\inc\isHappy.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-30 23:52:16
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-18 19:02:45
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 快乐数 - 公共函数头文件
 */
#ifndef __IS_HAPPY_H
#define __IS_HAPPY_H

/* 标准头文件 */
#include <stdbool.h>

int getNext(int n);     /* 计算下一个数 */
bool isHappy(int n);    /* 判断是否为快乐数 */

#endif  /* __IS_HAPPY_H */
