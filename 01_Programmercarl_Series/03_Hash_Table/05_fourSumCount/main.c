/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\05_fourSumCount\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-23 22:54:19
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-10 23:45:34
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
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

/**********************************************************************************/
/*                                                                                */
/*                                 GLOBAL VARIABLES                               */
/*                                                                                */
/**********************************************************************************/
/* 哈希节点 */
struct HashNode {
    int key;
    int val;
    struct HashNode *next;
};

/* 哈希表 */
struct HashTable {
    int size;
    struct HashNode **table;
};

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/* 创建哈希表 */
struct HashTable *createHashTable(int size) {
    struct HashTable *newTable = (struct HashTable *)malloc(sizeof(struct HashTable));
    newTable->size = size;
    newTable->table = (struct HashNode **)malloc(sizeof(struct HashNode *) * size);
    for (int i = 0; i < size; i++) {
        newTable->table[i] = NULL;
    }
    return newTable;
}

/* TODO：哈希码，理解这个是什么意思 */
int hashCode(struct HashTable *table, int key) {
    return (key & 0x7fffffff) % table->size;
}

/* 插入哈希元素 */
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

/* 查找哈希元素 */
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

/* 释放哈希表 */
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
int fourSumCount(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* nums4, int nums4Size) {
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
    /* Test case 1 */
    printf("======== Case 1 ======== \n");
    int A[] = {1, 2};
    int B[] = {-2, -1};
    int C[] = {-1, 2};
    int D[] = {0, 2};
    int result = fourSumCount(A, ARRAY_SIZE(A), B, ARRAY_SIZE(B), C, ARRAY_SIZE(C), D, ARRAY_SIZE(D));
    printf("result: %d\n", result);

    return 0;
}