/* 383. 赎金信：https://leetcode.cn/problems/ransom-note/ */
/* https://programmercarl.com/0383.%E8%B5%8E%E9%87%91%E4%BF%A1.html */
/* https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0383.%E8%B5%8E%E9%87%91%E4%BF%A1.md */

#include <stdio.h>
#include <stdbool.h>

bool canConstruct(char * ransomNote, char * magazine){
    int counter[26] = {0};
    return true;
}

int main(int argc, char const *argv[]) {
    // NOTE: Test case 1
    printf("======== Case 1 ======== \n");
    char r1[] = "a";
    char m1[] = "b";
    printf("Can be constructed: %s\r\n", canConstruct(r1, m1) ? "true" : "false");

    // NOTE: Test case 2
    printf("======== Case 2 ======== \n");
    char r2[] = "aa";
    char m2[] = "ab";
    printf("Can be constructed: %s\r\n", canConstruct(r2, m2) ? "true" : "false");

    // NOTE: Test case 3
    printf("======== Case 3 ======== \n");
    char r3[] = "aa";
    char r4[] = "aab";
    printf("Can be constructed: %s\r\n", canConstruct(r3, r4) ? "true" : "false");
    return 0;
}