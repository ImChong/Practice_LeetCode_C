/* 1. 两数之和：https://leetcode.cn/problems/two-sum/ */
/* https://programmercarl.com/0001.%E4%B8%A4%E6%95%B0%E4%B9%8B%E5%92%8C.html */
/* https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0001.%E4%B8%A4%E6%95%B0%E4%B9%8B%E5%92%8C.md */

#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {

    return NULL;
}

/* NOTE: 主函数 */
int main(int argc, char const *argv[]) {
    // NOTE: Test case 1
    printf("======== Case 1 ======== \n");
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;

    int *indices = twoSum(nums, sizeof(nums)/sizeof(nums[0]), target, &returnSize);
    if (indices) {
        printf("Indices: [%d, %d]\n", indices[0], indices[1]);
        free(indices);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}