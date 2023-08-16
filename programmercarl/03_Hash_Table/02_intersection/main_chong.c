/* 349. 两个数组的交集：https://leetcode.cn/problems/intersection-of-two-arrays/ */
/* https://programmercarl.com/0349.%E4%B8%A4%E4%B8%AA%E6%95%B0%E7%BB%84%E7%9A%84%E4%BA%A4%E9%9B%86.html */

#include <stdio.h>
#include <stdlib.h>

/* ==================================================================================================== */
/* ==================================================================================================== */
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

/* TODO: 目标函数 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);
    int *res = (int *)malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));
    int i = 0, j = 0, k = 0;
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] == nums2[j]) {
            if (k == 0 || res[k - 1] != nums1[i]) {
                res[k++] = nums1[i];
            }
            i++;
            j++;
        } else if (nums1[i] < nums2[j]) {
            i++;
        } else {
            j++;
        }
    }
    *returnSize = k;
    return res;
}
/* ==================================================================================================== */
/* ==================================================================================================== */

/* NOTE:主函数 */
/* FIXME: 用chatgpt生成更合适的答案 */
int main(int argc, char const *argv[]) {
    int nums1[] = {1, 2, 2, 1};
    int nums2[] = {2, 2}; 
    int returnSize = 0;

    int *ans = intersection(nums1, 4, nums2, 2, &returnSize);
    printf("return: %d\n", ans[0]);
    return 0;
}