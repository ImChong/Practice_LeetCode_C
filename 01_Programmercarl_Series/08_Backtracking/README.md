# Backtracking：回溯算法
回溯算法是一种试探性的算法，它尝试通过探索所有可能的解决方案来找到一个问题的所有解。当探索到某一步时，如果认为这不是一个有希望的解，它会“回溯”到上一步，然后尝试其他路径。

回溯算法可以看作是一个决策树的深度优先遍历：从根开始，对每一个可能的决策方向进行探索，如果某一方向上不能找到解，则返回到上一个分支点，继续尝试其他可能的方向。

在C语言中，回溯通常使用递归实现。

## 回溯法解决的问题
- 组合问题：N个数里面按一定规则找出k个数的集合
- 切割问题：一个字符串按一定规则有几种切割方式
- 子集问题：一个N个数的集合里有多少符合条件的子集
- 排列问题：N个数按一定规则全排列，有几种排列方式
- 棋盘问题：N皇后，解数独等等

## 示例：N皇后问题
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

## 回溯算法模板框架
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