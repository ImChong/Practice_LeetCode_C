# 1. Dynamic_Programming：动态规划算法

动态规划（Dynamic Programming，简称DP）是一种用于解决多阶段决策问题的优化算法。动态规划通常用于解决那些具有重叠子问题和最优子结构性质的问题。在这种方法中，问题的解决方案是通过解决其子问题来找到的，并且这些子问题的解通常会被存储，以便在解决同样的子问题时不必重新计算。

- [1. Dynamic\_Programming：动态规划算法](#1-dynamic_programming动态规划算法)
  - [1.1. 基本思路](#11-基本思路)
  - [1.2. 示例：斐波那契数列](#12-示例斐波那契数列)
  - [1.3. 应用](#13-应用)
  - [1.4. Question List](#14-question-list)

## 1.1. 基本思路

1. **定义状态**：通常会使用一个数组（一维、二维或更高维）来存储子问题的解。
2. **状态转移方程**：定义如何从一个或多个较小子问题的解来得到当前子问题的解。
3. **初始条件和边界情况**：这是动态规划解决方案的起点。
4. **计算顺序**：确保在解决当前子问题之前，其依赖的所有子问题都已解决。
5. **返回结果**：根据具体问题，返回所需的解。

## 1.2. 示例：斐波那契数列

一个简单的动态规划问题是计算斐波那契数列（Fibonacci sequence）的第n项。这个问题具有重叠子问题和最优子结构的特性。

以下是用C语言实现的示例：

```c
#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) return n;

    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n = 10;
    printf("Fibonacci(%d) = %d\n", n, fibonacci(n));
    return 0;
}
```

在这个例子中：

- 状态是数组`dp`，其中`dp[i]`存储斐波那契数列的第`i`项。
- 状态转移方程是`dp[i] = dp[i - 1] + dp[i - 2]`。
- 初始条件是`dp[0] = 0`和`dp[1] = 1`。

## 1.3. 应用

动态规划在计算机科学和数学中有广泛的应用，包括：

- 序列对齐
- 最短路径问题（如Dijkstra算法和Floyd-Warshall算法）
- 文本和字符串比较（如Levenshtein距离）
- 组合优化（如背包问题）
- 计算几何（如最近点对问题）

动态规划是算法设计中非常强大的一种工具，但也需要一定的经验和直觉来正确地定义状态和状态转移方程。这是一个非常广泛和深入的主题，对于掌握算法和数据结构非常有帮助。

## 1.4. Question List

```txt
10_Dynamic_Programming/
├── 01_fib
├── 02_climbStairs
├── 03_minCostClimbingStairs
├── 04_uniquePaths
├── 05_uniquePathsWithObstacles
├── 06_integerBreak
├── 07_numTrees
├── 08_backpack_Series
├── 09_canPartition
├── 10_lastStoneWeightII
├── 11_findTargetSumWays
├── 12_findMaxForm
├── 13_change
├── 14_combinationSum4
├── 15_coinChange
├── 16_numSquares
├── 17_wordBreak
├── 18_houseRobber_Series
├── 19_buyAndSell_Series
└── README.md
```
