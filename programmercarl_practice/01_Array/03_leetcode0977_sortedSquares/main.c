#include <stdio.h>

int *sortedSquares(int *nums, int numsSize, int *returnSize) {

    return 0;
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

    printf("Hello World");
    return 0;
}