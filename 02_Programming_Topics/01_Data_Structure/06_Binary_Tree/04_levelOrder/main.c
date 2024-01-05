/*
 * @FilePath     : \Practice_LeetCode_C\01_Programming_Topics\07_Binary_Tree\04_levelOrder\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-11 21:17:11
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-16 00:41:14
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 102. 二叉树的层序遍历：从上往下层序遍历二叉树 - 此文件为数组解法
 * 102. 二叉树的层序遍历: https://leetcode.cn/problems/binary-tree-level-order-traversal/
 * https://programmercarl.com/0102.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86.html
 * 解法参考：https://leetcode.cn/problems/binary-tree-level-order-traversal/solutions/1286876/er-cha-shu-de-ceng-xu-bian-li-cyu-yan-xi-jdk8/
 *
 *       1
 *      / \
 *     2   3
 *    / \ / \
 *   4  5 6  7
 *
 * 层序遍历：
 * [
 *   [1]
 *   [2, 3]
 *   [4, 5, 6, 7]
 * ]
 */
/* standard header file (标准头文件) */
#include <stdio.h>
#include <stdlib.h>
/* common function header file (通用头文件) */
#include "commonTypeDef.h"
#include "commonArray.h"
#include "commonBinaryTree.h"
/* solution method configuration file (解题方法配置文件) */
#include "methodCfg.h"
/* solution header file (题解头文件) */
#include "levelOrder.h"

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试层序遍历
 * [1, 2, 3, 4, 5, 6, 7]
 *  树结构表示：
 *       1
 *      / \
 *     2   3
 *    / \ / \
 *   4  5 6  7
 *
 * 层序遍历 - 数组解法 / 结构体解法
 * [
 *  [1]
 *  [2, 3]
 *  [4, 5, 6, 7]
 * ]
 * =================================================================================
 * @return {void}
 */
void test_levelOrderTraversal(void) {
    /* 实际结果 */
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int arrSize = ARR_SIZE(arr);
    struct TreeNode *root = BTree_ArrayInit(arr, arrSize);
    int actualReturnSize = 0;
    int *actualReturnColumnSizes = NULL;
    int **actualArray = levelOrder(root, &actualReturnSize, &actualReturnColumnSizes);

    /* 预期结果 */
    int expectedReturnSize = 3;
    int expectedReturnColumnSizes[] = {1, 2, 4};
    int *expectedArray[4] = {
        (int[]){1},
        (int[]){2, 3},
        (int[]){4, 5, 6, 7}
    };

    /* 比较结果 */
    Validate_Array2D('1',
                        expectedArray, expectedReturnSize, expectedReturnColumnSizes,
                        actualArray, actualReturnSize, actualReturnColumnSizes,
                        SORT_FALSE);

    /* 释放内存 */
    Array_Free(&actualReturnColumnSizes);
    Array_Free2D(&actualArray, actualReturnSize);
    BTree_Free(root);
}

/**
 * @description: 测试层序遍历
 * [1, 2, 3, 4, 5, 6, 7]
 *  树结构表示：
 *       1
 *      / \
 *     2   3
 *    / \ / \
 *   4  5 6  7
 *
 * 层序遍历 - 通用函数
 * [
 *  [1]
 *  [2, 3]
 *  [4, 5, 6, 7]
 * ]
 * =================================================================================
 * @return {void}
 */
void test_levelOrderTraversal_CommonFunc(void) {
    /* TODO */
    return;
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
    BTree_PrintTest();
    printf("--------------------\r\n");
#if ARRAY_METHOD_EN
    printf("ARRAY_METHOD_EN\n");
#elif STRUCT_METHOD_EN
    printf("STRUCT_METHOD_EN\n");
#endif
    test_levelOrderTraversal();
    return 0;
}