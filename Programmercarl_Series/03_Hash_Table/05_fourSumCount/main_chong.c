/* 454. 四数相加 II：https://leetcode.cn/problems/4sum-ii/ */
/* https://programmercarl.com/0454.%E5%9B%9B%E6%95%B0%E7%9B%B8%E5%8A%A0II.html */
/* https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0454.%E5%9B%9B%E6%95%B0%E7%9B%B8%E5%8A%A0II.md */

#include <stdio.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

/* ==================================================================================================== */
/* ==================================================================================================== */


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