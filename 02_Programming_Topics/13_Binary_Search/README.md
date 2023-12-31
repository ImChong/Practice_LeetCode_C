# 1. Binary_Search：二分查找

二分查找（Binary Search）是一种在排序数组中查找特定元素的搜索算法。它比线性查找（从头到尾逐个检查）要高效得多，因为它每次都将待查找的部分减半。二分查找的前提是数组已经排序。

- [1. Binary\_Search：二分查找](#1-binary_search二分查找)
  - [1.1. 基本思想](#11-基本思想)
  - [1.2. C语言代码示例](#12-c语言代码示例)
  - [1.3. 注意](#13-注意)


## 1.1. 基本思想

二分查找的基本思想是将数组分为三个部分：

1. 中间元素
2. 中间元素左边的所有元素
3. 中间元素右边的所有元素

比较我们要查找的值与中间元素的值：

- 如果目标值与中间元素相等，则查找成功。
- 如果目标值小于中间元素，则在左边的子数组中继续查找。
- 如果目标值大于中间元素，则在右边的子数组中继续查找。

这个过程一直重复，直到找到目标值，或者子数组的大小变为0（表示元素不在数组中）。

## 1.2. C语言代码示例

下面是一个使用二分查找在排序数组中查找特定元素的简单C语言示例：

```c
#include <stdio.h>

int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // 防止(left+right)可能的溢出

        if (arr[mid] == target) {
            return mid; // 找到目标，返回索引
        } else if (arr[mid] < target) {
            left = mid + 1; // 查找右边部分
        } else {
            right = mid - 1; // 查找左边部分
        }
    }

    return -1; // 未找到目标，返回-1
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int result = binary_search(arr, size, target);

    if (result != -1) {
        printf("元素 %d 在索引 %d 处找到。\n", target, result);
    } else {
        printf("元素 %d 未在数组中找到。\n", target);
    }

    return 0;
}
```

这个程序尝试在数组中查找数字7，并输出找到的位置。如果找不到，则输出一个消息说明这一点。

## 1.3. 注意

二分查找只适用于已排序的数组。对于未排序的数据集，首先需要对其进行排序，或者使用其他查找方法（如线性查找）。
