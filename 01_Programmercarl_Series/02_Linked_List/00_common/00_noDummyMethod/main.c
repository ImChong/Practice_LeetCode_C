/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\02_Linked_List\00_common\00_noDummyMethod\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 10:09:09
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-22 08:47:47
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 运行链表公共函数
 */
#include "commonArray.h"           /* 00_Basics\01_Common_Func\inc\commonArray.h */
#include "commonLinkedList.h"
#include "commonRingBuffer.h"

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
    int arr[] = {1, 2, 3, 4, 5};                                    /* 数组 */
    int arrSize = ARR_SIZE(arr);                                    /* 数组大小 */
    struct ListNode *ansList = arrayToLinkedList(arr, arrSize);     /* 数组转链表 */
    printList(ansList);                                             /* 打印链表 */

    ansList = appendToList(ansList, 6);                             /* 添加元素至链表末端 */
    printList(ansList);                                             /* 打印链表 */

    ansList = removeFromList(ansList, 2);                           /* 添加元素至链表末端 */
    printList(ansList);                                             /* 打印链表 */

    Test_RingBuffer();

    return 0;
}