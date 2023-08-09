#include <stdio.h>

/* 27. 移除元素：https://leetcode.cn/problems/remove-element/ */
/* https://programmercarl.com/0027.%E7%A7%BB%E9%99%A4%E5%85%83%E7%B4%A0.html */
int removeElement(int *nums, int numsSize, int val) {
    int i, j;
    for (i = 0, j = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[j] = nums[i];
            j++;
        }
    }
    return j;
}

int main() {
    int nums[] = {3, 2, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int val = 3;

    int newSize = removeElement(nums, numsSize, val);
    printf("New size of the array after removing %d: %d\n", val, newSize);

    // Print the modified array
    printf("Modified array: ");
    for (int i = 0; i < newSize; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
};