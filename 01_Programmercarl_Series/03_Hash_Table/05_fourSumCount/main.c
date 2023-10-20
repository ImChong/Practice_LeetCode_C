/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\05_fourSumCount\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-23 22:54:19
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-20 21:28:23
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 454. 四数相加 II：https://leetcode.cn/problems/4sum-ii/
 * https://programmercarl.com/0454.%E5%9B%9B%E6%95%B0%E7%9B%B8%E5%8A%A0II.html
 * https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0454.%E5%9B%9B%E6%95%B0%E7%9B%B8%E5%8A%A0II.md
 */
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************************/
/*                                                                                */
/*                                MACRO FUNCTIONS                                 */
/*                                                                                */
/**********************************************************************************/
#define ARR_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))          /* 获取数组长度 */

/**********************************************************************************/
/*                                                                                */
/*                                 GLOBAL VARIABLES                               */
/*                                                                                */
/**********************************************************************************/
/* 哈希节点 */
struct HashNode {
    int key;                    /* 键 */
    int val;                    /* 值 */
    struct HashNode *next;      /* 下一个节点 */
};

/* 哈希表 */
struct HashTable {
    int size;                   /* 哈希表大小 */
    struct HashNode **table;    /* 哈希表 */
};

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 创建哈希表
 * =================================================================================
 * @param {int} size                        哈希表大小
 * @return {struct HashTable} *newTable     哈希表
 */
struct HashTable *createHashTable(int size) {
    struct HashTable *newTable = (struct HashTable *)malloc(sizeof(struct HashTable));
    newTable->size = size;
    newTable->table = (struct HashNode **)malloc(sizeof(struct HashNode *) * size);
    for (int i = 0; i < size; i++) {
        newTable->table[i] = NULL;
    }
    return newTable;
}

/**
 * @description: 哈希码
 * TODO：哈希码，理解这个是什么意思
 * =================================================================================
 * @param {HashTable} *table        哈希表
 * @param {int} key                 键
 * @return {int}                    哈希码
 */
int hashCode(struct HashTable *table, int key) {
    return (key & 0x7fffffff) % table->size;        /* 0x7fffffff 是一个十六进制数，等于 2^31 - 1，即 2147483647 */
}

/**
 * @description: 插入哈希元素
 * =================================================================================
 * @param {HashTable} *table        哈希表
 * @param {int} key                 键
 * @return {void}
 */
void insert(struct HashTable *table, int key) {
    int slot = hashCode(table, key);
    struct HashNode *currentNode = table->table[slot];
    while (currentNode) {
        if (currentNode->key == key) {
            currentNode->val++;
            return;
        }
        currentNode = currentNode->next;
    }
    struct HashNode *newNode = (struct HashNode *)malloc(sizeof(struct HashNode));
    newNode->key = key;
    newNode->val = 1;
    newNode->next = table->table[slot];
    table->table[slot] = newNode;
}

/**
 * @description: 查找哈希元素
 * =================================================================================
 * @param {HashTable} *table        哈希表
 * @param {int} key                 键
 * @return {int}                    值
 */
int find(struct HashTable *table, int key) {
    int slot = hashCode(table, key);
    struct HashNode *currentNode = table->table[slot];
    while (currentNode) {
        if (currentNode->key == key) {
            return currentNode->val;
        }
        currentNode = currentNode->next;
    }
    return 0;
}

/**
 * @description: 释放哈希表
 * =================================================================================
 * @param {HashTable} *table        哈希表
 * @return {void}
 */
void freeHashTable(struct HashTable *table) {
    for (int i = 0; i < table->size; i++) {
        struct HashNode *currentNode = table->table[i];
        while (currentNode) {
            struct HashNode *tmp = currentNode;
            currentNode = currentNode->next;
            free(tmp);
        }
    }
    free(table->table);
    free(table);
}

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/* TODO */
/* ============================================================================== */
/* ============================================================================== */
/**
 * @description: 四数相加 II
 * =================================================================================
 * @param {int} *nums1          数组1
 * @param {int} nums1Size       数组1大小
 * @param {int} *nums2          数组2
 * @param {int} nums2Size       数组2大小
 * @param {int} *nums3          数组3
 * @param {int} nums3Size       数组3大小
 * @param {int} *nums4          数组4
 * @param {int} nums4Size       数组4大小
 * @return {int}                四元组之和为 0 的不同元组的个数
 */
int fourSumCount(int *nums1, int nums1Size, int *nums2, int nums2Size, int *nums3, int nums3Size, int *nums4, int nums4Size) {
    struct HashTable *hashTable = createHashTable(2 * nums1Size * nums2Size);
    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            insert(hashTable, nums1[i] + nums2[j]);
        }
    }

    int count = 0;
    for (int i = 0; i < nums3Size; i++) {
        for (int j = 0; j < nums4Size; j++) {
            count += find(hashTable, -1 * (nums3[i] + nums4[j]));
        }
    }

    freeHashTable(hashTable);
    return count;
}

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 验证答案
 * =================================================================================
 * @param {char} testNum    测试编号
 * @param {int} expect      预期
 * @param {int} actual      实际
 * @return {void}
 */
void validateAnswer(char testNum, int expect, int actual) {
    if (expect == actual) {
        printf("✅ Test %c Passed\n", testNum);
    } else {
        printf("❌ Test %c Failed\n", testNum);
    }
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试 1
 * 输入：nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
 * 输出：2
 *
 * 两个元组如下：
 * 1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
 * 2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
 * =================================================================================
 * @return {void}
 */
void test_1(void) {
    /* 实际结果 */
    int A[] = {1, 2};
    int B[] = {-2, -1};
    int C[] = {-1, 2};
    int D[] = {0, 2};
    int actual = fourSumCount(A, ARR_SIZE(A), B, ARR_SIZE(B), C, ARR_SIZE(C), D, ARR_SIZE(D));

    /* 预期结果 */
    int expect = 2;

    /* 比较结果 */
    validateAnswer('1', expect, actual);
}

/**
 * @description: 测试 2
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */

    /* 预期结果 */

    /* 比较结果 */

}

/**
 * @description: 测试 3
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    /* 实际结果 */

    /* 预期结果 */

    /* 比较结果 */

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
int main(int argc, char const *argv[]) {
    test_1();
    return 0;
}