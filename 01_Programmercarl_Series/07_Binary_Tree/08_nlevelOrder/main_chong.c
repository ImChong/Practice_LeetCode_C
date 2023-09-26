/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\07_Binary_Tree\08_nlevelOrder\main_chong.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-28 09:44:35
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-09-26 14:05:43
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 429. N 叉树的层序遍历: https://leetcode.cn/problems/n-ary-tree-level-order-traversal/
 * https://programmercarl.com/0102.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86.html#_429-n%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86
 * 解法参考：https://leetcode.cn/problems/n-ary-tree-level-order-traversal/solutions/1400623/n-cha-shu-de-ceng-xu-bian-li-by-leetcode-lxdr/
 */
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************************/
/*                                                                                */
/*                                MACRO CONSTANTS                                 */
/*                                                                                */
/**********************************************************************************/
#define MAX_LEVEL_SIZE  1000
#define MAX_NODE_SIZE   10000

/**********************************************************************************/
/*                                                                                */
/*                                MACRO FUNCTIONS                                 */
/*                                                                                */
/**********************************************************************************/
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))    /* 获取数组长度 */

/**********************************************************************************/
/*                                                                                */
/*                                 GLOBAL VARIABLES                               */
/*                                                                                */
/**********************************************************************************/
struct Node {
    int val;
    int numChildren;
    struct Node **children;
};

/**********************************************************************************/
/*                                                                                */
/*                                 TARGET FUNCTION                                */
/*                                                                                */
/**********************************************************************************/
/*
    对于「层序遍历」的题目，我们一般使用广度优先搜索。在广度优先搜索的每一轮中，我们会遍历同一层的所有节点。
        我们首先把根节点 root 放入队列中，随后在广度优先搜索的每一轮中，我们首先记录下当前队列中包含的节点个数（记为 cnt），即表示上一层的节点个数。
        在这之后，我们从队列中依次取出节点，直到取出了上一层的全部 cnt 个节点为止。
        当取出节点 cur 时，我们将 cur 的值放入一个临时列表，再将 cur 的所有子节点全部放入队列中。
        当这一轮遍历完成后，临时列表中就存放了当前层所有节点的值。
        这样一来，当整个广度优先搜索完成后，我们就可以得到层序遍历的结果。

    需要特殊判断树为空的情况。
*/
/* ============================================================================== */
/* ============================================================================== */
/**
 * @description: N 叉树的层序遍历
 * =================================================================================
 * @param {Node} *root
 * @param {int} *returnSize
 * @param {int} **returnColumnSizes
 * @return {int} **ans
 */
int **levelOrder(struct Node *root, int *returnSize, int **returnColumnSizes) {
    int **ans = (int **)malloc(sizeof(int *) * MAX_LEVEL_SIZE);
    *returnColumnSizes = (int *)malloc(sizeof(int) * MAX_LEVEL_SIZE);
    if (!root) {
        *returnSize = 0;
        return ans;
    }
    struct Node **queue = (struct Node **)malloc(sizeof(struct Node *) * MAX_NODE_SIZE);
    int head = 0, tail = 0;
    int level = 0;
    queue[tail++] = root;

    while (head != tail){
        int cnt = tail - head;
        ans[level] = (int *)malloc(sizeof(int) * cnt);
        for (int i = 0; i < cnt; i++) {
            struct Node *cur = queue[head++];
            ans[level][i] = cur->val;
            for (int j = 0; j < cur->numChildren; j++) {
                queue[tail++] = cur->children[j];
            }
        }
        (*returnColumnSizes)[level++] = cnt;
    }
    *returnSize = level;
    free(queue);
    return ans;
}

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 创建新节点
 * =================================================================================
 * @param {int} val
 * @return {struct Node} *node
 */
struct Node *newNode(int val) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->val = val;
    node->children = NULL;
    node->numChildren = 0;
    return node;
}

/**
 * @description: 释放树所占用的空间
 * =================================================================================
 * @param {struct Node} *root
 * @return {void}
 */
void freeTree(struct Node *root) {
    if (root == NULL) {             /* 如果传入节点为 NULL 则返回 */
        return;
    }

    /* TODO */
}

/**
 * @description: 比较预期结果与运算结果
 * =================================================================================
 * @param {char} testNum
 * @param {int} ***expected
 * @param {int} ***result
 * @param {int} *returnSize
 * @param {int} **returnColumnSizes
 * @return {void}
 */
void testAnswer(char testNum, int ***expected, int ***result, int *returnSize, int **returnColumnSizes) {
    for (int i = 0; i < (*returnSize); i++) {
        for (int j = 0; j < (*returnColumnSizes)[i]; j++) {
            if ((*result)[i][j] != (*expected)[i][j]) {
                printf("test %c failed\n", testNum);
                return;
            }
        }
    }
    printf("test %c passed\n", testNum);
}
/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试 1 - []
 * =================================================================================
 * @return {*}
 */
void test_1(void) {
    /* 预期结果 */
    int **expected = NULL;

    /* 运算结果 */
    struct Node *root = NULL;
    int returnSize = 0;
    int *returnColumnSizes;
    int **result = levelOrder(root, &returnSize, &returnColumnSizes);

    /* 测试结果输出 */
    testAnswer('1', &expected, &result, &returnSize, &returnColumnSizes);
}

/**
 * @description: 测试 2 - [1,null,3,2,4,null,5,6]
 *     1
 *    /|\
 *   3 2 4
 *  / \
 * 5   6
 * =================================================================================
 * @return {*}
 */
void test_2(void) {
    /* 预期结果 */
    int **expected = NULL;

    /* 运算结果 */
    struct Node *root = NULL;
    int returnSize = 0;
    int *returnColumnSizes;
    int **result = levelOrder(root, &returnSize, &returnColumnSizes);

    /* 测试结果输出 */
    testAnswer('2', &expected, &result, &returnSize, &returnColumnSizes);
}

/**
 * @description: 测试 3 - [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
 *         1
 *    /  |    |   \
 *   2   3    4    5
 *      / \   |   / \
 *     6   7  8  9  10
 *         |  |  |
 *        11 12 13
 *         |
 *        14
 * =================================================================================
 * @return {*}
 */
void test_3(void) {
    /* 预期结果 */
    int **expected = NULL;

    /* 运算结果 */
    struct Node *root = NULL;
    int returnSize = 0;
    int *returnColumnSizes;
    int **result = levelOrder(root, &returnSize, &returnColumnSizes);

    /* 测试结果输出 */
    testAnswer('3', &expected, &result, &returnSize, &returnColumnSizes);
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
    test_3();
    return 0;
}