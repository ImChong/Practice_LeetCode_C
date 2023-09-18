/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\07_Binary_Tree\07_averageOfLevels\main_chong_DFS.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-28 09:44:35
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-09-18 19:04:18
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 637. 二叉树的层平均值: https://leetcode.cn/problems/average-of-levels-in-binary-tree/
 * https://programmercarl.com/0102.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86.html#_637-%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%B9%B3%E5%9D%87%E5%80%BC
 * 解法参考：https://leetcode.cn/problems/average-of-levels-in-binary-tree/solutions/410522/er-cha-shu-de-ceng-ping-jun-zhi-by-leetcode-soluti/
 *
 * 方法一：深度优先搜索
 *       1
 *      / \
 *     2   3
 *    / \ / \
 *   4  5 6  7
 *
 * sums:        [4,  8, 15]
 * counts:      [1,  2,  3]
 * averages:    [4,  4,  5]
 */
#include <stdio.h>
#include <stdlib.h>

/* 树节点 */
struct TreeNode {
    int val;                    /* 节点的值 */
    struct TreeNode *left;      /* 左节点 */
    struct TreeNode *right;     /* 右节点 */
};

/* ==================================================================================================== */
/* ==================================================================================================== */
/* TODO: 目标函数 */
/*
    Depth-First-Search (DFS) - 深度优先搜索算法
*/

/* ==================================================================================================== */
/* ==================================================================================================== */
int countsSize;
int sumsSize;

void
/**
 * @description: 二叉树的层平均值
 * =================================================================================
 * @param {TreeNode} *root
 * @param {int} *returnSize
 * @return {double} *averages
 */
double *averageOfLevels(struct TreeNode *root, int *returnSize){
    /* TODO */

}
/* ==================================================================================================== */
/* ==================================================================================================== */
/* ==================================================================================================== */
/* ==================================================================================================== */

/**
 * @description: 主函数
 * =================================================================================
 * @param {int} argc
 * @param {char} *argv[]
 * @return {*}
 */
int main(int argc, const char *argv[]) {

    return 0;
}