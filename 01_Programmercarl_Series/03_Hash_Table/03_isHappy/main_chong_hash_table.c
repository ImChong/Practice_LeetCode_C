/* 202. 快乐数：https://leetcode.cn/problems/happy-number/ */
/* https://programmercarl.com/0202.%E5%BF%AB%E4%B9%90%E6%95%B0.html */
/* https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0202.%E5%BF%AB%E4%B9%90%E6%95%B0.md */

#include <stdio.h>
#include <stdbool.h>

/* ==================================================================================================== */
/* ==================================================================================================== */
/* 获取下一数字 */
int getNext(int n) {
    int sum = 0;            /* 计算总和 */
    while (n > 0) {         /* 当数字大于0时保持循环 */
        int d = n % 10;         /* 获取个位的数值 */
        sum += d * d;           /* 总和加上个位数值的平方 */
        n /= 10;                /* 去除个位的数字 */
    }
    return sum;             /* 返回总和 */
}

/* TODO: 目标函数 */
bool isHappy(int n) {
    // sum = a1^2 + a2^2 + ... ak^2
    // first round:
    // 1 <= k <= 10
    // 1 <= sum <= 1 + 81 * 9 = 730
    // second round:
    // 1 <= k <= 3
    // 1 <= sum <= 36 + 81 * 2 = 198
    // third round:
    // 1 <= sum <= 81 * 2 = 162
    // fourth round:
    // 1 <= sum <= 81 * 2 = 162

    int visited[163] = { 0 };               /* 初始化访问数组 */
    int sum = getNext(getNext(n));          /* sum指向后两位指针 */
    int next_n = sum;                       /* 下一位设置为sum */

    while (next_n != 1) {
        sum = getNext(next_n);

        if (visited[sum]) return false;

        visited[sum] = 1;
        next_n = sum;
    };

    return true;
}
/* ==================================================================================================== */
/* ==================================================================================================== */

/* 主函数 */
int main(int argc, char const *argv[]) {
    // NOTE: Test case 1
    printf("======== Case 1 ======== \n");
    int n = 19;
    if (isHappy(n)) {
        printf("%d is happy number!\n", n);
    } else {
        printf("%d is not happy number!\n", n);
    }

    // NOTE: Test case 2
    printf("======== Case 2 ======== \n");
    n = 2;
    if (isHappy(n)) {
        printf("%d is happy number!\n", n);
    } else {
        printf("%d is not happy number!\n", n);
    }


    return 0;
}