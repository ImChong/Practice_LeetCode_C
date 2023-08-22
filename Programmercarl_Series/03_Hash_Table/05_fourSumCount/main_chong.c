/* 454. 四数相加 II：https://leetcode.cn/problems/4sum-ii/ */
/* https://programmercarl.com/0454.%E5%9B%9B%E6%95%B0%E7%9B%B8%E5%8A%A0II.html */
/* https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0454.%E5%9B%9B%E6%95%B0%E7%9B%B8%E5%8A%A0II.md */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

/* ==================================================================================================== */
/* ==================================================================================================== */
/* NOTE：哈希节点 */
struct HashNode {
    int key;
    int val;
    struct HashNode *next;
};

/* NOTE：哈希表 */
struct HashTable {
    int size;
    struct HashNode **table;
};

/* NOTE：创建哈希表 */
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

/* NOTE：插入哈希元素 */
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

/* TODO：目标函数 */
int fourSumCount(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* nums4, int nums4Size) {

    return 0;
}
/* ==================================================================================================== */
/* ==================================================================================================== */

/* NOTE：主函数 */
int main(int argc, char const *argv[]) {
    // NOTE: Test case 1
    printf("======== Case 1 ======== \n");
    int A[] = {1, 2};
    int B[] = {-2, -1};
    int C[] = {-1, 2};
    int D[] = {0, 2};
    int result = fourSumCount(A, ARRAY_SIZE(A), B, ARRAY_SIZE(B), C, ARRAY_SIZE(C), D, ARRAY_SIZE(D));
    printf("result: %d\n", result);

    return 0;
}