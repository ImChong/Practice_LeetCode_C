/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\07_Binary_Tree\08_nlevelOrder\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-28 09:44:35
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-23 10:44:52
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 429. N 叉树的层序遍历: https://leetcode.cn/problems/n-ary-tree-level-order-traversal/
 * https://programmercarl.com/0102.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86.html#_429-n%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86
 * 解法参考：https://leetcode.cn/problems/n-ary-tree-level-order-traversal/solutions/1400623/n-cha-shu-de-ceng-xu-bian-li-by-leetcode-lxdr/
 */

/* TODO: 重构 */

#include <stdio.h>
#include <stdlib.h>

/**********************************************************************************/
/*                                                                                */
/*                                MACRO CONSTANTS                                 */
/*                                                                                */
/**********************************************************************************/
#define MAX_LEVEL_SIZE  1000    /* 最大层数 */
#define MAX_NODE_SIZE   10000   /* 最大节点数 */
#define TEST_ARR_SIZE   10      /* 测试的数组的长度 */

/**********************************************************************************/
/*                                                                                */
/*                                MACRO FUNCTIONS                                 */
/*                                                                                */
/**********************************************************************************/
#define ARR_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))    /* 获取数组长度 */

/**********************************************************************************/
/*                                                                                */
/*                                 GLOBAL VARIABLES                               */
/*                                                                                */
/**********************************************************************************/
struct Node {
    int val;                    /* 节点值 */
    int numChildren;            /* 子节点个数 */
    struct Node **children;     /* 子节点指针数组 */
};

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
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
 * @param {Node} *root                  根节点
 * @param {int} *returnSize             返回数组的长度
 * @param {int} **returnColumnSizes     返回数组的列数
 * @return {int} **ans                  返回数组
 */
int **levelOrder(struct Node *root, int *returnSize, int **returnColumnSizes) {
    int **ans = (int **)malloc(sizeof(int *) * MAX_LEVEL_SIZE);                             /* 返回数组 */
    *returnColumnSizes = (int *)malloc(sizeof(int) * MAX_LEVEL_SIZE);                       /* 返回数组的列数 */
    if (!root) {                                                                            /* 如果根节点为空，则返回 */
        *returnSize = 0;                                                                        /* 返回数组的长度为 0 */
        return ans;                                                                             /* 返回空数组 */
    }
    struct Node **queue = (struct Node **)malloc(sizeof(struct Node *) * MAX_NODE_SIZE);    /* 队列 */
    int head = 0, tail = 0;                                                                 /* 队列头尾指针 */
    int level = 0;                                                                          /* 层数 */
    queue[tail++] = root;                                                                   /* 根节点入队 */

    while (head != tail){                                                                   /* 队列不为空时 */
        int cnt = tail - head;                                                                  /* 当前层的节点个数 */
        ans[level] = (int *)malloc(sizeof(int) * cnt);                                          /* 为当前层的节点个数分配空间 */
        for (int i = 0; i < cnt; i++) {                                                         /* 遍历当前层的节点 */
            struct Node *cur = queue[head++];                                                       /* 当前节点出队 */
            ans[level][i] = cur->val;                                                               /* 将当前节点的值存入当前层的数组 */
            for (int j = 0; j < cur->numChildren; j++) {                                            /* 遍历当前节点的子节点 */
                queue[tail++] = cur->children[j];                                                       /* 将子节点入队 */
            }
        }
        (*returnColumnSizes)[level++] = cnt;                                                    /* 将当前层的节点个数存入返回数组的列数 */
    }
    *returnSize = level;                                                                    /* 返回数组的长度为层数 */
    free(queue);                                                                            /* 释放队列空间 */
    return ans;                                                                             /* 返回数组 */
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
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));         /* 为新节点分配空间 */
    node->val = val;                                                        /* 节点值为传入值 */
    node->children = NULL;                                                  /* 子节点指针数组为空 */
    node->numChildren = 0;                                                  /* 子节点个数为 0 */
    return node;                                                            /* 返回新节点 */
}

/**
 * @description: 比较预期结果与运算结果
 * =================================================================================
 * @param {char} testNum                测试编号
 * @param {int} ***expected             预期结果
 * @param {int} ***result               运算结果
 * @param {int} *returnSize             运算结果数组的长度
 * @param {int} **returnColumnSizes     运算结果数组的列数
 * @return {void}
 */
void Validate2DArray(char testNum, int **expected, int **result, int returnSize, int *returnColumnSizes) {
    if (returnSize == 0 && expected != NULL) {                              /* 如果预期结果与运算结果的长度不相等 */
        printf("❌ Test %c failed\n", testNum);                                 /* 测试失败 */
        return;                                                                 /* 返回 */
    }
    for (int i = 0; i < returnSize; i++) {                                  /* 遍历运算结果数组 */
        for (int j = 0; j < returnColumnSizes[i]; j++) {                        /* 遍历运算结果数组的列数 */
            if (result[i][j] != expected[i][j]) {                                   /* 如果预期结果与运算结果不相等 */
                printf("❌ Test %c failed\n", testNum);                                 /* 测试失败 */
                return;                                                                 /* 返回 */
            }
        }
    }
    printf("✅ Test %c passed\n", testNum);                                 /* 测试成功 */
}

/**
 * @description: 释放预期结果数组所占用的空间
 * =================================================================================
 * @param {int} ***result
 * @param {int} *returnSize
 * @return {void}
 */
void ArrayFree2D(int **result, int returnSize) {
    for (int i = 0; i < returnSize; i++) {                                  /* 遍历二维数组的每一行 */
        free(result[i]);                                                        /* free每一行数组占用的空间 */
    }
    free(result);                                                           /* 最后free二维数组本身 */
}

/**
 * @description: 释放 N 叉树所占用的空间
 * =================================================================================
 * @param {struct Node} *root   根节点
 * @return {void}
 */
void freeTree(struct Node *root) {
    if (root == NULL) {                                                     /* 如果传入节点为 NULL 则返回 */
        return;
    }
    for (int i = 0; i < root->numChildren; i++) {                           /* 遍历子节点 */
        freeTree(root->children[i]);                                            /* 递归释放子节点所占用的空间 */
    }
    free(root->children);                                                   /* 释放子节点指针数组所占用的空间 */
    free(root);                                                             /* 释放根节点所占用的空间 */
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试 1 - []
 * =================================================================================
 * @return {void}
 */
void Test1(void) {
    /* 预期结果 */
    int **expected = NULL;

    /* 构建 N 叉树 */
    struct Node *root = NULL;

    /* 运算结果 */
    int returnSize = 0;
    int *returnColumnSizes;
    int **result = levelOrder(root, &returnSize, &returnColumnSizes);

    /* 测试输出结果 */
    Validate2DArray('1', expected, result, returnSize, returnColumnSizes);

    /* 释放内存空间 */
    ArrayFree2D(expected, returnSize);
    ArrayFree2D(result, returnSize);
    free(returnColumnSizes);
    freeTree(root);
}

/**
 * @description: 测试 2 - [1,null,3,2,4,null,5,6]
 *     1
 *    /|\
 *   3 2 4
 *  / \
 * 5   6
 * =================================================================================
 * @return {void}
 */
void Test2(void) {
    /* 预期结果 */
    /* int expected[3][3] = {{1}, {3, 2, 4}, {5, 6}}; */
    int **expected = (int **)malloc(sizeof(int *) * TEST_ARR_SIZE);
    expected[0] = (int *)malloc(sizeof(int) * TEST_ARR_SIZE);
    expected[0][0] = 1;
    expected[1] = (int *)malloc(sizeof(int) * TEST_ARR_SIZE);
    expected[1][0] = 3;
    expected[1][1] = 2;
    expected[1][2] = 4;
    expected[2] = (int *)malloc(sizeof(int) * TEST_ARR_SIZE);
    expected[2][0] = 5;
    expected[2][1] = 6;

    /* 构建 N 叉树 */
    struct Node *root = newNode(1);
    root->numChildren = 3;
    root->children = (struct Node **)malloc(sizeof(struct Node *) * root->numChildren);
    root->children[0] = newNode(3);
    root->children[0]->numChildren = 2;
    root->children[0]->children = (struct Node **)malloc(sizeof(struct Node *) * root->children[0]->numChildren);
    root->children[0]->children[0] = newNode(5);
    root->children[0]->children[1] = newNode(6);
    root->children[1] = newNode(2);
    root->children[2] = newNode(4);

    /* 运算结果 */
    int returnSize = 0;
    int *returnColumnSizes;
    int **result = levelOrder(root, &returnSize, &returnColumnSizes);

    /* 测试输出结果 */
    Validate2DArray('2', expected, result, returnSize, returnColumnSizes);

    /* 释放内存空间 */
    ArrayFree2D(expected, returnSize);
    ArrayFree2D(result, returnSize);
    free(returnColumnSizes);
    freeTree(root);
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
 * @return {void}
 */
void Test3(void) {
    /* 预期结果 */
    /* int expected[5][5] = {{1}, {2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13}, {14}}; */
    int **expected = (int **)malloc(sizeof(int *) * TEST_ARR_SIZE);
    expected[0] = (int *)malloc(sizeof(int) * TEST_ARR_SIZE);
    expected[0][0] = 1;
    expected[1] = (int *)malloc(sizeof(int) * TEST_ARR_SIZE);
    expected[1][0] = 2;
    expected[1][1] = 3;
    expected[1][2] = 4;
    expected[1][3] = 5;
    expected[2] = (int *)malloc(sizeof(int) * TEST_ARR_SIZE);
    expected[2][0] = 6;
    expected[2][1] = 7;
    expected[2][2] = 8;
    expected[2][3] = 9;
    expected[2][4] = 10;
    expected[3] = (int *)malloc(sizeof(int) * TEST_ARR_SIZE);
    expected[3][0] = 11;
    expected[3][1] = 12;
    expected[3][2] = 13;
    expected[4] = (int *)malloc(sizeof(int) * TEST_ARR_SIZE);
    expected[4][0] = 14;

    /* 构建 N 叉树 */
    struct Node *root = newNode(1);
    root->numChildren = 4;
    root->children = (struct Node **)malloc(sizeof(struct Node *) * root->numChildren);
    root->children[0] = newNode(2);
    struct Node *node_2 = root->children[0];

    root->children[1] = newNode(3);
    struct Node *node_3 = root->children[1];

    node_3->numChildren = 2;
    node_3->children = (struct Node **)malloc(sizeof(struct Node *) * node_3->numChildren);
    node_3->children[0] = newNode(6);
    struct Node *node_6 = node_3->children[0];

    node_3->children[1] = newNode(7);
    struct Node *node_7 = node_3->children[1];

    node_7->numChildren = 1;
    node_7->children = (struct Node **)malloc(sizeof(struct Node *) * node_7->numChildren);
    node_7->children[0] = newNode(11);
    struct Node *node_11 = node_7->children[0];

    node_11->numChildren = 1;
    node_11->children = (struct Node **)malloc(sizeof(struct Node *) * node_11->numChildren);
    node_11->children[0] = newNode(14);
    struct Node *node_14 = node_11->children[0];

    root->children[2] = newNode(4);
    struct Node *node_4 = root->children[2];

    node_4->numChildren = 1;
    node_4->children = (struct Node **)malloc(sizeof(struct Node *) * node_4->numChildren);
    node_4->children[0] = newNode(8);
    struct Node *node_8 = node_4->children[0];

    node_8->numChildren = 1;
    node_8->children = (struct Node **)malloc(sizeof(struct Node *) * node_8->numChildren);
    node_8->children[0] = newNode(12);
    struct Node *node_12 = node_8->children[0];

    root->children[3] = newNode(5);
    struct Node *node_5 = root->children[3];

    node_5->numChildren = 2;
    node_5->children = (struct Node **)malloc(sizeof(struct Node *) * node_5->numChildren);
    node_5->children[0] = newNode(9);
    struct  Node *node_9 = node_5->children[0];

    node_9->numChildren = 1;
    node_9->children = (struct Node **)malloc(sizeof(struct Node *) * node_9->numChildren);
    node_9->children[0] = newNode(13);
    struct Node *node_13 = node_9->children[0];

    node_5->children[1] = newNode(10);
    struct  Node *node_10 = node_5->children[1];

    /* 运算结果 */
    int returnSize = 0;
    int *returnColumnSizes;
    int **result = levelOrder(root, &returnSize, &returnColumnSizes);

    /* 测试输出结果 */
    Validate2DArray('3', expected, result, returnSize, returnColumnSizes);

    /* 释放内存空间 */
    ArrayFree2D(expected, returnSize);
    ArrayFree2D(result, returnSize);
    free(returnColumnSizes);
    freeTree(root);
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
    Test1();
    Test2();
    Test3();
    return 0;
}