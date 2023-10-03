/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\07_Binary_Tree\10_connect\main_chong.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-18 23:18:36
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-03 08:29:00
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 116. 填充每个节点的下一个右侧节点指针: https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/
 * 解法参考: https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/solutions/446938/tian-chong-mei-ge-jie-dian-de-xia-yi-ge-you-ce-2-4/
 */
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************************/
/*                                                                                */
/*                                MACRO CONSTANTS                                 */
/*                                                                                */
/**********************************************************************************/
#define LEVEL_ORDER_METHOD_EN   1   /* 层次遍历方法使能 */
#define NEXT_POINTER_METHOD_EN  1   /* 使用已建立的 next 指针方法使能 */

/**********************************************************************************/
/*                                                                                */
/*                                 GLOBAL VARIABLES                               */
/*                                                                                */
/**********************************************************************************/
/* 树节点 */
struct TreeNode {
    int val;                    /* 节点的值 */
    struct TreeNode *left;      /* 左节点 */
    struct TreeNode *right;     /* 右节点 */
};

/**********************************************************************************/
/*                                                                                */
/*                                 TARGET FUNCTION                                */
/*                                                                                */
/**********************************************************************************/
/* TODO: 目标函数 */

/* ============================================================================== */
/* ============================================================================== */

struct Node *connect(struct Node *root) {
    /* TODO */
	return NULL;
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

    return 0;
}