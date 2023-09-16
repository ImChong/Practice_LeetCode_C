- [1. Monotone\_Stack：单调栈](#1-monotone_stack单调栈)
    - [1.0.1. 用途和应用](#101-用途和应用)
    - [1.0.2. 示例：找到下一个更大的元素](#102-示例找到下一个更大的元素)
    - [1.0.3. 总结](#103-总结)

# 1. Monotone_Stack：单调栈
单调栈（Monotonic Stack）是一种用于解决一类特殊问题的数据结构。单调栈本质上是一个栈，但它维护了栈内元素的某种单调性——单调递增或单调递减。

具体来说，当一个新元素需要入栈时，单调栈会先移除栈顶所有破坏单调性的元素，然后将新元素压入栈中。这样，栈内的元素始终保持单调递增或递减的顺序。

### 1.0.1. 用途和应用

单调栈主要用于解决数组中与元素顺序、大小有关的问题，如：

- 找到数组中每个元素的下一个更大（或更小）元素。
- 计算直方图中最大的矩形面积。

这类问题通常需要O(n)的时间复杂度来解决，而单调栈能够满足这一要求。

### 1.0.2. 示例：找到下一个更大的元素

给定一个数组，为每一个元素找出数组中第一个比它大的元素。

C语言代码示例：

```c
#include <stdio.h>
#include <stdlib.h>

void nextGreaterElement(int *nums, int *result, int size) {
    int *stack = (int*)malloc(size * sizeof(int));
    int top = -1; // 栈顶指针

    for (int i = 0; i < size; ++i) {
        // 栈非空且当前元素大于栈顶元素
        while (top >= 0 && nums[i] > nums[stack[top]]) {
            int idx = stack[top--]; // 出栈
            result[idx] = nums[i];
        }
        // 当前元素入栈
        stack[++top] = i;
    }

    // 栈中剩余的元素，它们没有下一个更大的元素
    while (top >= 0) {
        int idx = stack[top--];
        result[idx] = -1;
    }

    free(stack);
}

int main() {
    int nums[] = {4, 1, 2, 8, 5, 7};
    int size = sizeof(nums) / sizeof(nums[0]);
    int *result = (int*)malloc(size * sizeof(int));

    nextGreaterElement(nums, result, size);

    for (int i = 0; i < size; ++i) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}
```

在这个例子中，我们使用了一个单调递减栈。这个栈存储数组元素的索引，而不是元素本身。每当有一个新元素需要入栈时，我们会先弹出所有比它小的元素，然后将它入栈。

### 1.0.3. 总结

单调栈是一个强大的数据结构，尤其适用于解决数组和序列中与顺序和大小有关的问题。它通常能够在O(n)的时间复杂度内解决这类问题。