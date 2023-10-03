/* 977.有序数组的平方：https://leetcode.cn/problems/squares-of-a-sorted-array/ */
/* https://programmercarl.com/0977.%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E7%9A%84%E5%B9%B3%E6%96%B9.html */

#include <stdio.h>
#include <stdlib.h>

int *sortedSquares(int *nums, int numsSize, int *returnSize) {
    int *result = (int *)malloc(numsSize * sizeof(int));    /* 创建返回数组 */
    *returnSize = numsSize;     /* 确定返回大小 */

    int left = 0;                   /* 左指针 */
    int right = numsSize - 1;       /* 右指针 */
    int index = numsSize - 1;       /* 当前索引：从后往前 */

    while (left <= right) {         /* 当左指针的位置 <= 右指针的位置时 */
        int leftSquare = nums[left] * nums[left];       /* 计算左指针所指值的平方：左平方 */
        int rightSquare = nums[right] * nums[right];    /* 计算右指针所指值的平方：右平方 */

        if (leftSquare > rightSquare) {     /* 如果左平方 > 右平方 */
            result[index] = leftSquare;         /* 返回数组当前索引的值设置为左平方 */
            left++;                             /* 左指针位置 + 1 */
        } else {                            /* 如果左平方 < 右平方 */
            result[index] = rightSquare;        /* 返回数组当前索引的值设置为右平方 */
            right--;                            /* 右指针位置 - 1 */
        }
        index--;                            /* 索引值位置 - 1：从小到大排列 */
    }
    return result;
}

int main(int argc, char const *argv[]) {
    int nums[] = {-4, -1, 0, 3, 10};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int *result = sortedSquares(nums, numsSize, &returnSize);

    printf("Sorted Squares: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);

    return 0;
}