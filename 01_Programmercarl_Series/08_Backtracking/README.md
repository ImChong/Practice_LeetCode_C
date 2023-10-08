# 1. Backtracking：回溯算法

回溯算法是一种试探性的算法，它尝试通过探索所有可能的解决方案来找到一个问题的所有解。当探索到某一步时，如果认为这不是一个有希望的解，它会“回溯”到上一步，然后尝试其他路径。

回溯算法可以看作是一个决策树的深度优先遍历：从根开始，对每一个可能的决策方向进行探索，如果某一方向上不能找到解，则返回到上一个分支点，继续尝试其他可能的方向。

在C语言中，回溯通常使用递归实现。

- [1. Backtracking：回溯算法](#1-backtracking回溯算法)
  - [1.1. 回溯法解决的问题 \& 力扣题目总结](#11-回溯法解决的问题--力扣题目总结)
  - [1.2. 示例：N皇后问题](#12-示例n皇后问题)
  - [1.3. 回溯算法模板框架](#13-回溯算法模板框架)

## 1.1. 回溯法解决的问题 & 力扣题目总结

- [关于回溯算法，你该了解这些！](https://programmercarl.com/%E5%9B%9E%E6%BA%AF%E7%AE%97%E6%B3%95%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80.html#google_vignette)
- 组合问题：N个数里面按一定规则找出k个数的集合
  - [77.组合](https://programmercarl.com/0077.%E7%BB%84%E5%90%88.html)
  - [216.组合总和III](https://programmercarl.com/0216.%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8CIII.html)
  - [17.电话号码的字母组合](https://programmercarl.com/0017.%E7%94%B5%E8%AF%9D%E5%8F%B7%E7%A0%81%E7%9A%84%E5%AD%97%E6%AF%8D%E7%BB%84%E5%90%88.html)
  - [39.组合总和](https://programmercarl.com/0039.%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8C.html)
  - [40.组合总和II](https://programmercarl.com/0040.%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8CII.html)
- 分割问题：一个字符串按一定规则有几种切割方式
  - [131.分割回文串](https://programmercarl.com/0131.%E5%88%86%E5%89%B2%E5%9B%9E%E6%96%87%E4%B8%B2.html)
  - [93.复原IP地址](https://programmercarl.com/0093.%E5%A4%8D%E5%8E%9FIP%E5%9C%B0%E5%9D%80.html)
- 子集问题：一个N个数的集合里有多少符合条件的子集
  - [78.子集](https://programmercarl.com/0078.%E5%AD%90%E9%9B%86.html)
  - [90.子集II](https://programmercarl.com/0090.%E5%AD%90%E9%9B%86II.html)
- 排列问题：N个数按一定规则全排列，有几种排列方式
  - [46.全排列](https://programmercarl.com/0046.%E5%85%A8%E6%8E%92%E5%88%97.html)
  - [47.全排列II](https://programmercarl.com/0047.%E5%85%A8%E6%8E%92%E5%88%97II.html)
- 棋盘问题：N皇后，解数独等等
  - [51.N皇后](https://programmercarl.com/0051.N%E7%9A%87%E5%90%8E.html)
  - [37.解数独](https://programmercarl.com/0037.%E8%A7%A3%E6%95%B0%E7%8B%AC.html)
- 其他
  - [491.递增子序列](https://programmercarl.com/0491.%E9%80%92%E5%A2%9E%E5%AD%90%E5%BA%8F%E5%88%97.html)
  - [332.重新安排行程](https://programmercarl.com/0332.%E9%87%8D%E6%96%B0%E5%AE%89%E6%8E%92%E8%A1%8C%E7%A8%8B.html)
- [回溯算法总结篇](https://programmercarl.com/%E5%9B%9E%E6%BA%AF%E6%80%BB%E7%BB%93.html)

## 1.2. 示例：N皇后问题

一个经典的回溯问题是N皇后问题。给定一个N x N的棋盘，目标是放置N个皇后，使得没有两个皇后互相攻击（即它们不在同一行、列或对角线上）。

以下是C语言中使用回溯算法解决N皇后问题的简化版本：

```c
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N 4

// 检查在棋盘上放置皇后是否安全
bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    // 检查这一列
    for (i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // 检查左上到右下的对角线
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // 检查右上到左下的对角线
    for (i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQueens(int board[N][N], int row) {
    if (row >= N)
        return true;

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;

            if (solveNQueens(board, row + 1))
                return true;

            // 如果放置皇后并不导致解决方案，则移除皇后（回溯）
            board[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int board[N][N] = { {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0} };

    if (!solveNQueens(board, 0)) {
        printf("Solution does not exist");
    } else {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
```

以上代码是N皇后问题的一个基本解法。使用回溯算法的关键是，当我们确定当前的选择不会导致解决方案时，我们返回上一步并尝试其他选择。

回溯算法适用于组合优化问题，它可以找到所有可能的解，并从中选择最佳的。这种方法通常不是最高效的，但对于某些问题，如N皇后或旅行商问题（TSP），它是已知的最佳方法之一。

## 1.3. 回溯算法模板框架

```c
void backtracking(参数) {
    if (终止条件) {
        存放结果;
        return;
    }

    for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
        处理节点;
        backtracking(路径，选择列表); // 递归
        回溯，撤销处理结果
    }
}
```
