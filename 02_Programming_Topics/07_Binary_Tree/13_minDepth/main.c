/*
 * @FilePath     : \Practice_LeetCode_C\01_Programming_Topics\07_Binary_Tree\13_minDepth\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-28 09:44:35
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-26 17:41:47
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 111. 二叉树的最小深度: https://leetcode.cn/problems/minimum-depth-of-binary-tree/
 * 解法参考: https://leetcode.cn/problems/minimum-depth-of-binary-tree/solutions/382646/er-cha-shu-de-zui-xiao-shen-du-by-leetcode-solutio/
 */

/* TODO: 重构 */
/* standard header file (标准头文件) */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* 通用头文件 */
#include "commonSingleValue.h"
#include "commonBinaryTree.h"

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 二叉树的最小深度
 * =================================================================================
 * @param {struct TreeNode} *root
 * @return {int} ans
 */
int minDepth(struct TreeNode *root){
    /* TODO */
    return 0;
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试函数 1
 * =================================================================================
 * @return {void}
 */
void test_1(void) {
    /* 预期结果 */
    int expect = 2;

    /* 构建二叉树 */
    struct TreeNode *root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    /* 实际结果 */
    int actual = minDepth(root);

    /* 比较结果 */
    validateSingleValue('1', expect, actual);

    /* 释放内存空间 */
    free(root->right->right);
    free(root->right->left);
    free(root->right);
    free(root->left);
    free(root);
}

/**
 * @description: 测试函数 2
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 预期结果 */
    int expect = 5;

    /* 构建二叉树 */
    struct TreeNode *root = newNode(2);
    /* TODO */

    /* 实际结果 */
    int actual = minDepth(root);

    /* 比较结果 */
    validateSingleValue('2', expect, actual);

    /* 释放内存空间 */
    free(root->right);
    free(root);
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
    test_2();
    return 0;
}