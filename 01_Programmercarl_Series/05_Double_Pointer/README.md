# 1. Double_Pointer：双指针算法

"双指针算法"并不是C语言或其他编程语言的内置概念，而是一种常用的算法策略。在双指针算法中，我们使用两个指针而不是一个来遍历数组、链表或其他数据结构。这种算法通常用于解决需要在一维或二维数据结构中找到某种特定关系的问题。

- [1. Double\_Pointer：双指针算法](#1-double_pointer双指针算法)
  - [1.1. 数组去重](#11-数组去重)
  - [1.2. 快慢指针](#12-快慢指针)
  - [1.3. 二分搜索](#13-二分搜索)
  - [1.4. 双指针在排序数组中查找和为特定值的两个元素](#14-双指针在排序数组中查找和为特定值的两个元素)

以下是一些使用双指针算法的典型应用场景：

## 1.1. 数组去重

假设你有一个排序过的整数数组，你希望去除其中的重复元素。

```c
int removeDuplicates(int* nums, int numsSize){
    if (numsSize == 0) return 0;
    int i = 0;
    for (int j = 1; j < numsSize; j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}
```

在这里，`i` 和 `j` 是两个指针，分别用于跟踪新数组的最后一个元素和原始数组的当前元素。

## 1.2. 快慢指针

在链表中找到中点或检测循环通常使用快慢指针。

```c
struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    struct ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}
```

## 1.3. 二分搜索

在有序数组中查找元素时，通常使用两个指针指向当前搜索范围的开始和结束，然后用二分法缩小搜索范围。

```c
int binarySearch(int* arr, int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}
```

## 1.4. 双指针在排序数组中查找和为特定值的两个元素

```c
void twoSum(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            printf("Found: %d, %d\n", nums[left], nums[right]);
            return;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    printf("Not found\n");
}
```

以上只是双指针算法的几个例子。这种算法能有效地解决许多问题，通常能减少时间和/或空间复杂性。不过，编写双指针算法需要非常小心，以避免出现越界或其他错误。
