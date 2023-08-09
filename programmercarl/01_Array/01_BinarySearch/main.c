
/* 704. 二分查找：https://leetcode.cn/problems/binary-search/ */
/* https://programmercarl.com/0704.%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE */

#include <stdio.h>

int search(int *nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;

    while (left <= right) {                 /* 闭区间：当左指针 <= 右指针时持续运行 */
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {          /* 如果中间值等于目标：返回index */
            return mid;
        } else if (nums[mid] < target) {    /* 如果中间数小于目标值 */
            left = mid + 1;                 /* 左指针 + 1位 */
        } else {                            /* 如果中间数大于目标值 */
            right = mid - 1;                /* 右指针 - 1位 */
        }
    }
    return -1;
}

int main() {
    int nums[] = {-1, 0, 3, 5, 9, 12};      /* 有序数组 */
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 0;

    int result = search(nums, numsSize, target);
    printf("Index of %d in the array: %d\n", target, result);

    return 0;
}