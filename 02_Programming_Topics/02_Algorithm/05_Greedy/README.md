# 1. Greedy：贪心算法

贪心算法（Greedy Algorithm）是一种在每一步选择中都采取在当前状态下最好或最优（即最有利）的选择，从而希望导致结果是全局最好或最优的算法。

贪心算法在C语言中通常使用循环和条件语句来实现，并不需要像回溯或动态规划那样复杂的数据结构。然而，贪心算法并不是所有问题都适用，它适用的问题需要具有“贪心选择性质”（即局部最优选择能导致全局最优解）和“最优子结构”（一个问题的最优解包含其子问题的最优解）。

- [1. Greedy：贪心算法](#1-greedy贪心算法)
  - [1.1. 示例：硬币找零问题](#11-示例硬币找零问题)
    - [1.1.1. 注意事项](#111-注意事项)
  - [1.2. Question List](#12-question-list)

## 1.1. 示例：硬币找零问题

假设我们有面值为1, 5, 10, 25的硬币无限多，现在需要找零n分钱，如何用最少的硬币找零？

这个问题可以使用贪心算法解决：

1. 每次都选择面值最大（不大于找零总数的）的硬币。
2. 减去已找零的硬币面值，更新找零总数。
3. 重复以上两步，直到找零总数变为0。

C语言代码示例：

```c
#include <stdio.h>

void coinChange(int n) {
    int coins[] = {25, 10, 5, 1}; // 硬币面值
    int count = 0; // 计数器

    for (int i = 0; i < 4; i++) {
        int coinValue = coins[i];
        while (n >= coinValue) {
            printf("使用面值为 %d 的硬币\n", coinValue);
            n -= coinValue; // 减去硬币面值
            count++; // 增加硬币数量
        }
    }
    printf("总共使用了 %d 枚硬币\n", count);
}

int main() {
    int n = 93; // 需要找零的总数
    coinChange(n);
    return 0;
}
```

### 1.1.1. 注意事项

虽然贪心算法在某些问题上非常高效和简单，但它也有局限性。有的问题不能通过贪心算法得到全局最优解，因此在应用贪心算法之前，需要确定问题是否具有贪心选择性质和最优子结构。

总之，贪心算法是一种思想或策略，而非固定的算法框架。它在各种实际问题中有广泛的应用，包括但不限于任务调度、数据压缩和网络路由等。

## 1.2. Question List

```txt
09_Greedy/
├── 01_findContentChildren
├── 02_wiggleMaxLength
├── 03_maxSubArray
├── 04_maxProfit
├── 05_canJump
├── 06_jump
├── 07_largestSumAfterKNegations
├── 08_canCompleteCircuit
├── 09_candy
├── 10_lemonadeChange
├── 11_reconstructQueue
├── 12_findMinArrowShots
├── 13_eraseOverlapIntervals
├── 14_partitionLabels
├── 15_merge
├── 16_monotoneIncreasingDigits
├── 17_minCameraCover
└── README.md
```
