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
    char ransomNote[] = "a";
    char magazine[] = "b";

    printf("Can be constructed: %s\r\n", canConstruct(ransomNote, magazine) ? "true" : "false");
    return 0;
}