#include <stdio.h>

int removeElement(int *nums, int numsSize, int val) {
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