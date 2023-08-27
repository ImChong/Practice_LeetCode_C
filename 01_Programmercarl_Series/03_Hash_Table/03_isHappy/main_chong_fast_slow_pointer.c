/* 202. 快乐数：https://leetcode.cn/problems/happy-number/ */
/* https://programmercarl.com/0202.%E5%BF%AB%E4%B9%90%E6%95%B0.html */
/* https://github.com/youngyangyang04/leetcode-master/blob/master/problems/02c02.%E5%BF%AB%E4%B9%90%E6%95%B0.md */

#include <stdio.h>
#include <stdbool.h>

/* ==================================================================================================== */
/* ==================================================================================================== */
/* NOTE: 获取下一数字 */
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
    int slow = n;                           /* 初始化慢指针：指向当前数值 */
    int fast = getNext(n);                  /* 初始化快指针：指向下一数值 */
    while (fast != 1 && slow != fast) {     /* 当快指针的值不为 1 或快指针与慢指针指向的值不相同时，保持循环 */
        slow = getNext(slow);               /* 慢指针一次移动一位 */
        fast = getNext(getNext(fast));      /* 快指针一次移动两位 */
    }
    return fast == 1;                       /* 当开始循环且快慢指针指向的值都为 1 时，返回 true */
}
/* ==================================================================================================== */
/* ==================================================================================================== */

/* NOTE: 主函数 */
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