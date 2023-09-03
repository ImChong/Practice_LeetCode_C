# Buy_And_Sell：股票买卖问题
股票买卖问题是一类经常在编程面试中出现的问题，也是动态规划和贪心算法的经典应用之一。这类问题通常需要考虑如何最大化通过买入和卖出股票获得的利润。

## 基本版本

最简单的版本是这样的：给定一个数组，其中第 \(i\) 个元素表示第 \(i\) 天股票的价格，你只允许完成一次交易（即买入和卖出一支股票一次），设计一个算法来找出最大利润。

在这个基础版本中，一种简单的方法是使用一次循环遍历每一个价格，并持续更新当前最低价格和当前最大利润。

## 多次交易

有时问题会稍微复杂一些，允许你进行多次交易。但你必须在再次购买之前出售掉之前的股票。

在这个版本中，贪心算法是非常直接的解法。你只需要找出所有上涨的日子，在这些日子买进前一天的股票并在当天卖出。

## 有冷冻期或交易费用

还有更复杂的版本，比如在卖出股票后需要等待一段冷冻期才能再买，或者每次交易都需要支付一定的手续费。

这些问题通常通过动态规划来解决，状态转移方程会稍微复杂一些。

## C语言代码示例（基础版本）

```c
#include <stdio.h>
#include <limits.h>

// 找出一次交易能获得的最大利润
int maxProfit(int prices[], int size) {
    int minPrice = INT_MAX;  // 记录最小价格
    int maxProfit = 0;  // 记录最大利润

    for (int i = 0; i < size; ++i) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];  // 更新最小价格
        } else if (prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;  // 更新最大利润
        }
    }

    return maxProfit;
}

int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int size = sizeof(prices) / sizeof(prices[0]);

    int result = maxProfit(prices, size);
    printf("最大利润为：%d\n", result);

    return 0;
}
```

这个例子中的 `maxProfit` 函数遍历一次价格数组，通过不断更新 `minPrice` 和 `maxProfit` 来找出一次交易中能获得的最大利润。

不同版本的股票买卖问题有不同的解决方案，包括贪心算法、动态规划等，都是非常好的算法练习题。