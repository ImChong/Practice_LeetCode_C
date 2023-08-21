/* 15. 三数之和：https://leetcode.cn/problems/3sum/ */
/* https://programmercarl.com/0015.%E4%B8%89%E6%95%B0%E4%B9%8B%E5%92%8C.html */
/* https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0015.%E4%B8%89%E6%95%B0%E4%B9%8B%E5%92%8C.md */

#include <stdio.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

/* TODO：目标函数 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){

    return NULL;
}

/* 打印结果 */
void printAns(int **result, int returnSize, int* returnColumnSizes) {
    for (int i = 0; i < returnSize; i++) {
        printf("Ans[%d]: ", i);
        for (int j = 0; j < returnColumnSizes[0]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

/* 释放结果空间 */
void freeAns(int **result, int** returnColumnSizes) {
    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);
}

/* 主函数 */
int main(int argc, const char* argv[]) {
    int nums[] = {-1, 0, 1, 2, -1, -4};

    int returnSize = 0;
    int *returnColumnSizes;

    int **result = threeSum(nums, ARRAY_SIZE(nums), &returnSize, &returnColumnSizes);
    printAns(result, returnSize, returnColumnSizes);
    freeAns(result, returnColumnSizes)
    return 0;
}