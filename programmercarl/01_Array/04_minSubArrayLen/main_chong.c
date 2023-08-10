/* 209.长度最小的子数组：https://leetcode.cn/problems/minimum-size-subarray-sum/ */
/* https://programmercarl.com/0209.%E9%95%BF%E5%BA%A6%E6%9C%80%E5%B0%8F%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84.html */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* DONE: 目标函数 */
int minSubArrayLen(int target, int *nums, int numsSize) {
    int minLen = INT_MAX;
    int sum = 0;

    int left = 0, right = 0;
    for (; right < numsSize; right++) {
        sum += nums[right];                             /* 添加右侧数字 */
        while (sum >= target) {                         /* 当sum大于target时 */
            int subLen = right - left + 1;              /* 计算子长度*/
            minLen = minLen < subLen ? minLen : subLen; /* 更新最小子长度 */
            sum -= nums[left++];                        /* 去除左侧数字*/
        }
    }
    return minLen == INT_MAX ? 0 : minLen;  /* 返回最小长度 */
}

int main(int argc, char const *argv[]) {
    int nums[] = {2, 3, 1, 2, 4, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int s = 7;

    int result = minSubArrayLen(s, nums, numsSize);
    printf("Minimum size of subarray whose sum is at least %d: %d\n", s, result);

    return 0;
}