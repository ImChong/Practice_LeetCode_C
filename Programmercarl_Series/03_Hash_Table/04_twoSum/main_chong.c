/* 1. 两数之和：https://leetcode.cn/problems/two-sum/ */
/* https://programmercarl.com/0001.%E4%B8%A4%E6%95%B0%E4%B9%8B%E5%92%8C.html */
/* https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0001.%E4%B8%A4%E6%95%B0%E4%B9%8B%E5%92%8C.md */

#include <stdio.h>
#include <stdlib.h>

/* ==================================================================================================== */
/* ==================================================================================================== */
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                int *result = (int *)malloc(2 * sizeof(int));
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}
/* ==================================================================================================== */
/* ==================================================================================================== */

/* 打印索引值 */
void printIndices(int *indices) {
    if (indices) {
        printf("Indices: [%d, %d]\n", indices[0], indices[1]);
        free(indices);
    } else {
        printf("No solution found.\n");
    }
}

/* NOTE: 主函数 */
int main(int argc, char const *argv[]) {
    // NOTE: Test case 1
    printf("======== Case 1 ======== \n");
    int nums1[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;

    int *indices = twoSum(nums1, sizeof(nums1)/sizeof(nums1[0]), target, &returnSize);
    printIndices(indices);

    // NOTE: Test case 2
    printf("======== Case 2 ======== \n");
    int nums2[] = {3, 2, 4};
    target = 6;

    indices = twoSum(nums2, sizeof(nums2)/sizeof(nums2[0]), target, &returnSize);
    printIndices(indices);

    // NOTE: Test case 3
    printf("======== Case 3 ======== \n");
    int nums3[] = {3, 3};
    target = 6;

    indices = twoSum(nums3, sizeof(nums3)/sizeof(nums3[0]), target, &returnSize);
    printIndices(indices);

    return 0;
}