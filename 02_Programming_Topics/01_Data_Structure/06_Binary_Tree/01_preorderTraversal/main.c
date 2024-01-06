/*
 * @FilePath     : \Practice_LeetCode_C\02_Programming_Topics\07_Binary_Tree\01_preorderTraversal\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-02 02:08:22
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 144.二叉树的前序遍历：https://leetcode.cn/problems/binary-tree-preorder-traversal/
 * https://programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E8%BF%AD%E4%BB%A3%E9%81%8D%E5%8E%86.html
 * [1, 2, 3, 4, 5, 6, 7]
 *  树结构表示：
 *       1
 *      / \
 *     2   3
 *    / \ / \
 *   4  5 6  7
 *
 * 前序遍历 - 递归方法/迭代方法
 * [1, 2, 4, 5, 3, 6, 7]
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
    BTree_PrintTestTree();
    printf("--------------------\r\n");
    test_preOrderTraversal();
    return 0;
}