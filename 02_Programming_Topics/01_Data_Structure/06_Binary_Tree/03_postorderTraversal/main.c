/*
 * @FilePath     : \Practice_LeetCode_C\02_Programming_Topics\07_Binary_Tree\03_postorderTraversal\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-02 02:11:28
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  :
 * [1, 2, 3, 4, 5, 6, 7]
 * 树结构表示：
 *       1
 *      / \
 *     2   3
 *    / \ / \
 *   4  5 6  7
 *
 * 后序遍历 - 递归方法/迭代方法
 * [4, 5, 2, 6, 7, 3, 1]
 */
/* standard header file (标准头文件) */
#include <stdio.h>
/* common function header file (通用头文件) */
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
int main(int argc, const char *argv[]) {
    BTree_PrintTest();
    printf("--------------------\r\n");
    test_postOrderTraversal();
    return 0;
}