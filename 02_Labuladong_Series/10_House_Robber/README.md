# House_Robber：打家劫舍问题
打家劫舍问题是一个常见的算法问题，通常用于介绍或练习动态规划（Dynamic Programming）概念。该问题在不同的版本和变种下有多种表述，但基本思想通常是一致的。

## 基础版本

在最简单的版本中，假设你是一个专业的窃贼，计划去一个社区偷窃。每个房子都存放着一定数量的财宝，但有一个限制：你不能连续偷窃两个相邻的房子，否则会触发警报。

问题是：给定一个数组，其中每个元素表示每个房子中存放的财宝数量，你应如何选择偷窃哪些房子，以便最大化总收益？

## 动态规划解决

这个问题可以通过动态规划来解决。你可以创建一个一维数组（或者只用两个变量）来存储到目前为止可以获得的最大收益。

状态转移方程可能是这样的：
\[
\text{dp}[i] = \max(\text{dp}[i-1], \text{dp}[i-2] + \text{nums}[i])
\]
其中，\(\text{dp}[i]\) 表示到第 \(i\) 个房子为止可以获得的最大收益，\(\text{nums}[i]\) 是第 \(i\) 个房子中存放的财宝数量。

## C语言代码示例

```c
#include <stdio.h>

// 返回打家劫舍能获得的最大收益
int rob(int nums[], int size) {
    if (size == 0) return 0;
    if (size == 1) return nums[0];

    int prev1 = 0, prev2 = 0;
    for (int i = 0; i < size; ++i) {
        int temp = prev1;
        prev1 = (prev1 > prev2 + nums[i]) ? prev1 : prev2 + nums[i];
        prev2 = temp;
    }

    return prev1;
}

int main() {
    int nums[] = {2, 7, 9, 3, 1};
    int size = sizeof(nums) / sizeof(nums[0]);

    int result = rob(nums, size);
    printf("最大收益为：%d\n", result);

    return 0;
}
```

在这个例子中，我们使用两个变量 `prev1` 和 `prev2` 来跟踪到当前房子为止的最大收益。通过遍历每个房子并更新这两个变量，我们最终可以找到整个数组的最大收益。

这个问题有多种变种，比如有的版本会将房子排列成一个环形（即第一个和最后一个房子是相邻的），或者每个房子都有不同的警报触发条件等。但不管是哪种变种，动态规划通常都是解决这类问题的关键。