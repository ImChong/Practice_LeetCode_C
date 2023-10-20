/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\05_fourSumCount\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-23 22:54:19
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-21 07:53:23
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
    struct HashTable *newTable = (struct HashTable *)malloc(sizeof(struct HashTable));      /* 为哈希表分配空间 */
    newTable->size = size;                                                                  /* 设置哈希表大小 */
    newTable->table = (struct HashNode **)malloc(sizeof(struct HashNode *) * size);         /* 为哈希节点分配空间 */
    for (int i = 0; i < size; i++) {                                                        /* 遍历哈希表 */
        newTable->table[i] = NULL;                                                              /* 将哈希表的每个节点都设置为空 */
    }
    return newTable;                                                                        /* 返回哈希表 */
}

/**
 * @description: 哈希码 - 获取键在哈希表中的槽位
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
    int slot = hashCode(table, key);                                                    /* 计算哈希码 */
    struct HashNode *currentNode = table->table[slot];                                  /* 获取哈希表的哈希节点 */
    while (currentNode) {                                                               /* 遍历哈希节点 */
        if (currentNode->key == key) {                                                      /* 如果哈希节点的键等于 key */
            currentNode->val++;                                                                 /* 将哈希节点的值加 1 */
            return;                                                                             /* 返回 */
        }
        currentNode = currentNode->next;                                                    /* 否则，将哈希节点指向下一个节点 */
    }
    struct HashNode *newNode = (struct HashNode *)malloc(sizeof(struct HashNode));      /* 为新节点分配空间 */
    newNode->key = key;                                                                 /* 设置新节点的键 */
    newNode->val = 1;                                                                   /* 设置新节点的值 */
    newNode->next = table->table[slot];                                                 /* 将新节点的下一个节点指向哈希表的哈希节点 */
    table->table[slot] = newNode;                                                       /* 将哈希表的哈希节点指向新节点 */
}

/**
 * @description: 查找哈希元素
 * =================================================================================
 * @param {HashTable} *table        哈希表
 * @param {int} key                 键
 * @return {int}                    值
 */
int find(struct HashTable *table, int key) {
    int slot = hashCode(table, key);                                                    /* 计算哈希码 */
    struct HashNode *currentNode = table->table[slot];                                  /* 获取哈希表的哈希节点 */
    while (currentNode) {                                                               /* 遍历哈希节点 */
        if (currentNode->key == key) {                                                      /* 如果哈希节点的键等于 key */
            return currentNode->val;                                                            /* 返回哈希节点的值 */
        }
        currentNode = currentNode->next;                                                    /* 否则，将哈希节点指向下一个节点 */
    }
    return 0;                                                                           /* 如果没有找到，返回 0 */
}

/**
 * @description: 释放哈希表
 * =================================================================================
 * @param {HashTable} *table        哈希表
 * @return {void}
 */
void freeHashTable(struct HashTable *table) {
    for (int i = 0; i < table->size; i++) {                                             /* 遍历哈希表 */
        struct HashNode *currentNode = table->table[i];                                     /* 获取哈希表的哈希节点 */
        while (currentNode) {                                                               /* 遍历哈希节点 */
            struct HashNode *tmp = currentNode;                                                 /* 临时节点 */
            currentNode = currentNode->next;                                                    /* 将哈希节点指向下一个节点 */
            free(tmp);                                                                          /* 释放临时节点 */
        }
    }
    free(table->table);                                                                 /* 释放哈希表的哈希节点 */
    free(table);                                                                        /* 释放哈希表 */
}

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 四数相加 II
 * 这是一个C函数，名为fourSumCount，它接受八个参数：四个整数数组及其各自的大小。该函数返回一个整数值。
 *
 * 该函数首先使用自定义的哈希表数据结构创建一个哈希表。哈希表的大小为第一个和第二个输入数组大小的乘积的两倍。
 * 哈希表的目的是存储第一个和第二个输入数组中所有可能的整数对的和。
 * 该函数然后遍历第一个和第二个输入数组中的每个整数对，并将它们的和插入到哈希表中。
 *
 * 接下来，该函数将变量count初始化为0。
 * 该函数然后遍历最后两个输入数组中的每个整数对，并检查它们的和的负数是否存在于哈希表中。
 * 如果存在，则该函数将增加count变量的值。
 * 最后，该函数释放为哈希表分配的内存，并返回count变量的值。
 *
 * 该函数的目的是找到四元组（a，b，c，d），使得a + b + c + d = 0，其中a是第一个输入数组的元素，b是第二个输入数组的元素，c是第三个输入数组的元素，d是第四个输入数组的元素。
 * 该函数通过使用哈希表来存储第一个和第二个输入数组中所有可能的整数对的和来实现此目的。
 * 然后，该函数遍历最后两个输入数组中的每个整数对，并检查它们的和的负数是否存在于哈希表中。
 * 如果存在，则该函数将增加count变量的值。
 *
 * 为了提高此代码的可读性，该函数可以受益于更具描述性的变量名称。
 * 此外，可以添加注释以解释代码的每个部分的目的。
 * 在性能方面，哈希表大小可以进行优化，以减少冲突数量并提高查找时间。
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
    struct HashTable *hashTable = createHashTable(2 * nums1Size * nums2Size);       /* 创建哈希表 */
    for (int i = 0; i < nums1Size; i++) {                                           /* 遍历数组1 */
        for (int j = 0; j < nums2Size; j++) {                                           /* 遍历数组2 */
            insert(hashTable, nums1[i] + nums2[j]);                                         /* 将数组1和数组2的和插入哈希表 */
        }
    }

    int count = 0;                                                                  /* 计数器 */
    for (int i = 0; i < nums3Size; i++) {                                               /* 遍历数组3 */
        for (int j = 0; j < nums4Size; j++) {                                               /* 遍历数组4 */
            count += find(hashTable, -1 * (nums3[i] + nums4[j]));                               /* 如果数组3和数组4的和的负数存在于哈希表中，计数器加 1 */
        }
    }

    freeHashTable(hashTable);                                                       /* 释放哈希表 */
    return count;                                                                   /* 返回计数器 */
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
 * 输入：nums1 = [1,1], nums2 = [-1,-1], nums3 = [1,-1], nums4 = [1,-1]
 * 输出：8
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */
    int A[] = {1,1};
    int B[] = {-1,-1};
    int C[] = {1,-1};
    int D[] = {1,-1};
    int actual = fourSumCount(A, ARR_SIZE(A), B, ARR_SIZE(B), C, ARR_SIZE(C), D, ARR_SIZE(D));

    /* 预期结果 */
    int expect = 8;

    /* 比较结果 */
    validateAnswer('2', expect, actual);
}

/**
 * @description: 测试 3
 * 输入：nums1 = [0,1,-1], nums2 = [-1,1,0], nums3 = [0,0,1], nums4 = [-1,1,1]
 * 输出：17
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    /* 实际结果 */
    int A[] = {0,1,-1};
    int B[] = {-1,1,0};
    int C[] = {0,0,1};
    int D[] = {-1,1,1};
    int actual = fourSumCount(A, ARR_SIZE(A), B, ARR_SIZE(B), C, ARR_SIZE(C), D, ARR_SIZE(D));

    /* 预期结果 */
    int expect = 17;

    /* 比较结果 */
    validateAnswer('3', expect, actual);
}

/**
 * @description: 测试 4
 * 输入：nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
 * 输出：1
 * =================================================================================
 * @return {void}
 */
void test_4(void) {
    /* 实际结果 */
    int A[] = {0};
    int B[] = {0};
    int C[] = {0};
    int D[] = {0};
    int actual = fourSumCount(A, ARR_SIZE(A), B, ARR_SIZE(B), C, ARR_SIZE(C), D, ARR_SIZE(D));

    /* 预期结果 */
    int expect = 1;

    /* 比较结果 */
    validateAnswer('4', expect, actual);
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
    test_2();
    test_3();
    test_4();
    return 0;
}