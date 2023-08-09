/* 27. 移除元素：https://leetcode.cn/problems/remove-element/ */
/* https://programmercarl.com/0027.%E7%A7%BB%E9%99%A4%E5%85%83%E7%B4%A0.html */

#include <stdio.h>

int removeElement(int *nums, int numsSize, int val) {
    int quick, slow;            /* 初始化快慢指针 */
    for (quick = 0, slow = 0; quick < numsSize; quick++) {  /* 快指针遍历数组 */
        if (nums[quick] != val) {       /* 当快指针所指向的值不等于val时*/
            nums[slow] = nums[quick];   /* 慢指针的值等于快指针的值 */
            slow++;                     /* 慢指针位置 + 1 */
        }
    }
    return slow;    /* 返回慢指针  */
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