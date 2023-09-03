# N_Sum：nSum 问题
`nSum` 问题是指从一个整数数组中找到 `n` 个数，使其和为一个特定的目标值。最常见的版本是 `2Sum` 和 `3Sum`，但这种问题可以扩展到 `4Sum`、`5Sum` 等任意 `n`。

## 1. 2Sum 问题

给定一个数组和一个目标值，找到数组中两个数的和等于该目标值。解决方法通常是使用哈希表或双指针技巧。

## 2. 3Sum 问题

给定一个数组和一个目标值（通常是 0），找到数组中三个数的和等于该目标值的所有唯一组合。解决方法通常是排序数组，然后使用双指针技巧。

## 3. nSum 问题

对于更大的 `n`，问题变得更加复杂。但通常的解决方法是使用递归将 `nSum` 问题分解为 `(n-1)Sum`、`(n-2)Sum` 等，直到将问题简化为 `2Sum`。

## C语言代码示例 (2Sum)

这是一个使用哈希表解决 `2Sum` 问题的简单示例：

```c
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10000

typedef struct {
    int key;
    int value;
} HashEntry;

typedef struct {
    HashEntry data[MAX_SIZE];
    bool flag[MAX_SIZE];
} HashMap;

int hash(int key) {
    int index = key % MAX_SIZE;
    if (index < 0) index += MAX_SIZE;
    return index;
}

void insert(HashMap *map, int key, int value) {
    int index = hash(key);
    while (map->flag[index]) {
        if (map->data[index].key == key) {
            map->data[index].value = value;
            return;
        }
        index = (index + 1) % MAX_SIZE;
    }
    map->data[index].key = key;
    map->data[index].value = value;
    map->flag[index] = true;
}

int search(HashMap *map, int key) {
    int index = hash(key);
    while (map->flag[index]) {
        if (map->data[index].key == key) {
            return map->data[index].value;
        }
        index = (index + 1) % MAX_SIZE;
    }
    return -1;
}

bool twoSum(int nums[], int size, int target) {
    HashMap map;
    for (int i = 0; i < MAX_SIZE; i++) {
        map.flag[i] = false;
    }

    for (int i = 0; i < size; i++) {
        int complement = target - nums[i];
        if (search(&map, complement) != -1) {
            return true;
        }
        insert(&map, nums[i], i);
    }
    return false;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int size = sizeof(nums) / sizeof(nums[0]);
    int target = 9;

    if (twoSum(nums, size, target)) {
        printf("Found two numbers that add up to %d.\n", target);
    } else {
        printf("No such two numbers found.\n");
    }

    return 0;
}
```

此代码只显示了是否存在满足条件的两个数字，而没有指定这两个数字是什么。如果需要指定这两个数字或其索引，可以稍微修改代码以返回这些值。

对于更高维度的 `nSum` 问题，我们可以使用递归、排序和双指针技巧等组合方法来求解。