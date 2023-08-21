/* 15. 三数之和：https://leetcode.cn/problems/3sum/ */
/* https://programmercarl.com/0015.%E4%B8%89%E6%95%B0%E4%B9%8B%E5%92%8C.html */
/* https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0015.%E4%B8%89%E6%95%B0%E4%B9%8B%E5%92%8C.md */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

/* 比较函数 */
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

/* TODO：目标函数 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (numsSize < 3) {
        return NULL;
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    int **ans = (int **)malloc(sizeof(int *) * numsSize * numsSize);
    *returnColumnSizes = (int *)malloc(sizeof(int) * numsSize * numsSize);
    int i, j, k, sum;

    int indexLeft = 0;
    int indexMiddle = 0;
    int indexRight = 0;

    for (indexLeft = 0; indexLeft < numsSize - 2; indexLeft++) {
        if (nums[indexLeft] > 0) {
            return ans;
        }

        if (indexLeft > 0 && nums[indexLeft] == nums[indexLeft - 1]) {
            continue;
        }
        indexMiddle = indexLeft + 1;
        indexRight = numsSize - 1;

        while (indexMiddle < indexRight) {
            sum = nums[indexLeft] + nums[indexMiddle] + nums[indexRight];
            if (sum == 0) {
                ans[*returnSize] = (int*)malloc(sizeof(int) * 3);
                (*returnColumnSizes)[*returnSize] = 3;
                ans[*returnSize][0] = nums[indexLeft];
                ans[*returnSize][1] = nums[indexMiddle];
                ans[*returnSize][2] = nums[indexRight];
                *returnSize += 1;
                while (indexMiddle < indexRight && nums[indexMiddle] == nums[++indexMiddle]);
                while (indexMiddle < indexRight && nums[indexRight] == nums[--indexRight]);
            } else if (sum > 0) {
                indexRight--;
            } else {
                indexMiddle++;
            }
        }
    }
    return ans;
}

/* 打印结果 */
void printAns(int **result, int returnSize, int *returnColumnSizes) {
    for (int i = 0; i < returnSize; i++) {
        printf("Ans[%d]: ", i);
        for (int j = 0; j < returnColumnSizes[0]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

/* 释放结果空间 */
void freeAns(int ***result, int *returnSize, int **returnColumnSizes) {
    for (int i = 0; i < *returnSize; i++) {
        free((*result)[i]);
    }
    free(*result);
    free(*returnColumnSizes);
}

/* 主函数 */
int main(int argc, const char* argv[]) {
    int nums[] = {-1, 0, 1, 2, -1, -4};

    int returnSize = 0;
    int *returnColumnSizes;

    int **result = threeSum(nums, ARRAY_SIZE(nums), &returnSize, &returnColumnSizes);
    printAns(result, returnSize, returnColumnSizes);
    freeAns(&result, &returnSize, &returnColumnSizes);
    return 0;
}