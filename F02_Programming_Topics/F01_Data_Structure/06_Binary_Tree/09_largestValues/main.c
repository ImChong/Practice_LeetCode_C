/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\07_Binary_Tree\09_largestValues\main_chong.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-18 23:18:36
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-09-28 17:32:30
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 515. 在每个树行中找最大值: https://leetcode.cn/problems/find-largest-value-in-each-tree-row/
 */

/* TODO: 重构 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**********************************************************************************/
/*                                                                                */
/*                                MACRO CONSTANTS                                 */
/*                                                                                */
/**********************************************************************************/
#define DFS_METHOD_EN   1       /* 方法一开关：深度优先搜索（注意：方法一与方法二不能同时开启） */
#define BFS_METHOD_EN   0       /* 方法二开关：广度优先搜索 */
#define MAX_NODE_SIZE   10000

/**********************************************************************************/
/*                                                                                */
/*                                MACRO FUNCTIONS                                 */
/*                                                                                */
/**********************************************************************************/
#define ARR_SIZE(arr)   (sizeof(arr) / sizeof((arr)[0]))    /* 获取数组长度 */
#define MAX(a, b)       ((a) > (b) ? (a) : (b))

/**********************************************************************************/
/*                                                                                */
/*                                 GLOBAL VARIABLES                               */
/*                                                                                */
/**********************************************************************************/
struct TreeNode {
    int val;                    /* 节点的值 */
    struct TreeNode *left;      /* 左节点 */
    struct TreeNode *right;     /* 右节点 */
};

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/*
    方法一：深度优先搜索
        用树的「先序遍历」来进行「深度优先搜索」处理
        用 curHeight 来标记遍历到的当前节点的高度
        当遍历到 curHeight 高度的节点就判断是否更新该层节点的最大值
*/
/* ============================================================================== */
/* ============================================================================== */
#if DFS_METHOD_EN

/**
 * @description: 深度优先搜索
 * =================================================================================
 * @param {int} *ans
 * @param {int} *index
 * @param {TreeNode} *root
 * @param {int} curHeight
 * @return {void}
 */
void dfs(int *ans, int *index, struct TreeNode* root, int curHeight) {
    if (curHeight == *index) {
        ans[(*index)++] = root->val;
    } else {
        ans[curHeight] = MAX(ans[curHeight], root->val);
    }
    if (root->left) {
        dfs(ans, index, root->left, curHeight + 1);
    }
    if (root->right) {
        dfs(ans, index, root->right, curHeight + 1);
    }
}

/**
 * @description: 在每个树行中找最大值
 * =================================================================================
 * @param {struct TreeNode} *root       树的根节点
 * @param {int} *returnSize             返回数组的大小
 * @return {int} *ans                   返回数组的首地址
 */
int* largestValues(struct TreeNode* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }
    int *ans = (int *)malloc(sizeof(int) * MAX_NODE_SIZE);
    *returnSize = 0;
    dfs(ans, returnSize, root, 0);
    return ans;
}
#endif /* DFS_METHOD_EN */

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/*
    方法二：广度优先搜索
        TODO
*/
/* ============================================================================== */
/* ============================================================================== */
#if BFS_METHOD_EN
/**
 * @description: 在每个树行中找最大值
 * =================================================================================
 * @param {struct TreeNode} *root       树的根节点
 * @param {int} *returnSize             返回数组的大小
 * @return {int} *ans                   返回数组的首地址
 */
int *largestValues(struct TreeNode *root, int *returnSize){
    /* TODO */
    return NULL;
}
#endif /* BFS_METHOD_EN */

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 创建树节点
 * =================================================================================
 * @param {int} value                   节点数值
 * @return {struct TreeNode} *node      二叉树节点
 */
struct TreeNode *newNode(int value) {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
 * @description: 打印一维数组 - NULL 用 INT_MIN 表示
 * =================================================================================
 * @param {int} *array      一维数组
 * @param {int} size        一维数组的大小
 * @return {void}
 */
void print1DArray(int *array, int size) {
    if (array == NULL || size == 0) {   /* 如果数组为空或者数组大小为 0 则返回 */
        printf("[]\n");
        return;
    }
    printf("[");                        /* 打印行边框 [ */
    for (int i = 0; i < size; ++i) {        /* 遍历 array 内的元素 */
        if (array[i] == INT_MIN) {              /* 如果元素为 INT_MIN 则打印 NULL */
            printf("NULL");
        } else {                                /* 否则打印元素值 */
            printf("%d", array[i]);                 /* 打印 array 内的元素 */
        }
        if (i < size - 1) {                     /* 打印分隔符：, */
            printf(", ");
        }
    }
    printf("]\n");                      /* 打印行边框 ] */
}

/**
 * @description: 数组转换为树 - NULL 用 INT_MIN 表示
 * =================================================================================
 * @param {int} *arr                    一维数组
 * @param {int} size                    一维数组的大小
 * @param {int} index                   数组索引
 * @param {struct TreeNode} **root      树的根节点
 * @return {void}
 */
void BTree_ArrayInit(int *arr, int size, int index, struct TreeNode **root) {
    if (index < size) {
        if (*(arr + index) == INT_MIN) {
            return;
        }
        *root = newNode(*(arr + index));
        BTree_ArrayInit(arr, size, 2 * index + 1, &((*root)->left));
        BTree_ArrayInit(arr, size, 2 * index + 2, &((*root)->right));
    }
}

/**
 * @description: 比较预期结果与运算结果
 * =================================================================================
 * @param {int} *expected   预期结果
 * @param {int} *result     运算结果
 * @param {int} returnSize  结果数组的大小
 * @return {void}
 */
void Validate_SingleValue(char testNum, int *expected, int *result, int returnSize) {
    if (returnSize == 0 && expected != NULL) {
        printf("test %c failed\n", testNum);
        return;
    }
    for (int i = 0; i < returnSize; ++i) {
        if (expected[i] != result[i]) {
            printf("test %c failed\n", testNum);
            return;
        }
    }
    printf("test %c passed\n", testNum);
}

/**
 * @description: 后续遍历释放树所占用的空间
 * =================================================================================
 * @param {struct TreeNode} *root      树的根节点
 * @return {void}
 */
void BTree_Free(struct TreeNode *root) {
    if (root == NULL) {             /* 如果传入节点为 NULL 则返回 */
        return;
    }

    BTree_Free(root->left);           /* 遍历释放左节点空间 */
    BTree_Free(root->right);          /* 遍历释放右节点空间 */
    free(root);                     /* 释放当前节点空间 */
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: Test 1 - [1, 3, 2, 5, 3, NULL, 9]
 *      1
 *     / \
 *    3   2
 *   / \   \
 *  5   3   9
 * output: [1,3,9]
 * =================================================================================
 * @return {void}
 */
void Test1(void) {
    /* Expect result (期望结果) */
    int expected[] = {1, 3, 9};

    /* 构建二叉树 */
    printf("Tree Array: \n");
    int treeArr[] = {1, 3, 2, 5, 3, INT_MIN, 9};            /* 二叉树数组 */
    print1DArray(treeArr, ARR_SIZE(treeArr));
    struct TreeNode *root = NULL;                           /* 初始化二叉树根节点为 NULL */
    BTree_ArrayInit(treeArr, ARR_SIZE(treeArr), 0, &root);      /* 二叉树数组转换为二叉树结构 */
    printf("\n");

    /* 运算结果 */
    int returnSize = 0;
    int *result = largestValues(root, &returnSize);

    /* 测试输出结果 */
    printf("Expected: \n");
    print1DArray(expected, ARR_SIZE(expected));
    printf("Result: \n");
    print1DArray(result, ARR_SIZE(result));
    Validate_SingleValue('1', expected, result, returnSize);

    /* Free memory (释放内存空间) */
    BTree_Free(root);
    free(result);
}

/**
 * @description: Test 2 - [1, 2, 3]
 *    1
 *   / \
 *  2   3
 * output: [1,3]
 * =================================================================================
 * @return {void}
 */
void Test2(void) {
    /* Expect result (期望结果) */
    int expected[] = {1, 3};

    /* 构建二叉树 */
    printf("Tree Array: \n");
    int treeArr[] = {1, 2, 3};                              /* 二叉树数组 */
    print1DArray(treeArr, ARR_SIZE(treeArr));
    struct TreeNode *root = NULL;                           /* 初始化二叉树根节点为 NULL */
    BTree_ArrayInit(treeArr, ARR_SIZE(treeArr), 0, &root);      /* 二叉树数组转换为二叉树结构 */
    printf("\n");

    /* 运算结果 */
    int returnSize = 0;
    int *result = largestValues(root, &returnSize);

    /* 测试输出结果 */
    printf("Expected: \n");
    print1DArray(expected, ARR_SIZE(expected));
    printf("Result: \n");
    print1DArray(result, ARR_SIZE(result));
    Validate_SingleValue('2', expected, result, returnSize);

    /* Free memory (释放内存空间) */
    BTree_Free(root);
    free(result);
}

/**********************************************************************************/
/*                                                                                */
/*                                  MAIN FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: Main function, entry of program.
 * =================================================================================
 * @param {int} argc        程序入参个数
 * @param {char} *argv[]    程序入参字符串数组
 * @return {int}            程序运行状态
 */
int main(int argc, const char *argv[]) {
    printf("====================\n");
    Test1();
    printf("====================\n");
    Test2();
    return 0;
}