/*
 * @FilePath     : \Practice_LeetCode_C\02_Programming_Topics\07_Binary_Tree\00_common\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-11-24 20:28:34
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-01 08:57:31
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用二叉树源文件测试
 */
/* Standard header file (标准头文件) */
#include <stdio.h>
/* Common function header file (通用头文件) */
#include "commonBinaryTree.h"
/* test helper header file (测试函数头文件) */
#include "testHelper.h"

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
int main(int argc, const char* argv[]) {
    BTree_PrintTestTree();
    printf("--------------------\r\n");
    test_preOrderTraversal();
    printf("--------------------\r\n");
    test_inOrderTraversal();
    printf("--------------------\r\n");
    test_postOrderTraversal();
    return 0;
}