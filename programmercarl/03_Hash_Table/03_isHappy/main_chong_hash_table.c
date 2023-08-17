/* 202. 快乐数：https://leetcode.cn/problems/happy-number/ */
/* https://programmercarl.com/0202.%E5%BF%AB%E4%B9%90%E6%95%B0.html */

#include <stdio.h>
#include <stdbool.h>

/* ==================================================================================================== */
/* ==================================================================================================== */
/* 获取下一数字 */
int getNext(int n) {
    int sum = 0;
    while (n > 0) {
        int d = n % 10;
        sum += d * d;
        n /= 10;
    }
    return sum;
}

/* TODO: 目标函数 */
bool isHappy(int n) {
    
    return false;
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