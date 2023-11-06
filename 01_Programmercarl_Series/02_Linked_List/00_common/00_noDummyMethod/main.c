/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\02_Linked_List\00_common\00_noDummyMethod\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 10:09:09
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-07 00:42:02
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 运行链表公共函数 - 未使用虚拟头节点
 */
/* 标准头文件 */
#include <stdio.h>
/* 通用头文件 */
#include "commonArray.h"
#include "commonLinkedList.h"

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试 1
 * 输入：{1, 2, 3}
 * 输出：{2, 3}
 * =================================================================================
 * @return {void}
 */
void test_1(void) {
    /* 实际结果 */
    struct ListNode *actualList = NULL;
    actualList = appendToLinkedList(actualList, 1);
    actualList = appendToLinkedList(actualList, 2);
    actualList = appendToLinkedList(actualList, 3);
    actualList = removeFromLinkedList(actualList, 1);

    /* 预期结果 */
    int nums[] = {2, 3};
    struct ListNode *expectList = arrayToLinkedList(nums, ARR_SIZE(nums));

    /* 比较结果 */
    validateLinkedList('1', expectList, actualList);

    /* 释放内存空间 */
    freeLinkedList(actualList);
    freeLinkedList(expectList);
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
    test_1();
    return 0;
}