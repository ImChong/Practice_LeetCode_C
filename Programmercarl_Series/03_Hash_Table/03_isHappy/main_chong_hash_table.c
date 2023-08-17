/* 202. 快乐数：https://leetcode.cn/problems/happy-number/ */
/* https://programmercarl.com/0202.%E5%BF%AB%E4%B9%90%E6%95%B0.html */
/* https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0202.%E5%BF%AB%E4%B9%90%E6%95%B0.md */

#include <stdio.h>
#include <stdbool.h>

/* ==================================================================================================== */
/* ==================================================================================================== */
/* NOTE: 获取下一数字 */
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
    int slow = n;
    int fast = getNext(n);
    while (fast != 1 && slow != fast) {
        slow = getNext(slow);
        fast = getNext(getNext(fast));
    }

    if (fast == 1) {
        return true;
    }

    int seen[1000] = {0};
    while (1) {
        if (seen[slow]) {
            return false;
        }
        seen[slow] = 1;
        slow = getNext(slow);
        if (slow == 1) {
            return true;
        }
    }
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