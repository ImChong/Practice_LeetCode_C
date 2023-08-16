/* 242. 有效的字母异位词：https://leetcode.cn/problems/valid-anagram/ */
/* https://programmercarl.com/0242.%E6%9C%89%E6%95%88%E7%9A%84%E5%AD%97%E6%AF%8D%E5%BC%82%E4%BD%8D%E8%AF%8D.html */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* ==================================================================================================== */
/* ==================================================================================================== */
/* TODO: 目标函数 */
bool isAnagram(char *s, char *t) {
    int sLen = strlen(s);
    int tLen = strlen(t);
    if (sLen != tLen) {
        return false;
    }

    int count[26] = {0};
    for (int i = 0; i < sLen; i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return false;
        }
    }
    return true;
}
/* ==================================================================================================== */
/* ==================================================================================================== */

/* 主函数 */
int main(int argc, char const *argv[]) {
    // NOTE: Test case 1
    printf("======== Case 1 ======== \n");
    char s1[] = "anagram";
    char t1[] = "nagaram";
    printf("Test case 1: %d\n", isAnagram(s1, t1));

    // NOTE: Test case 2
    printf("======== Case 2 ======== \n");
    char s2[] = "rat";
    char t2[] = "car";
    printf("Test case 2: %d\n", isAnagram(s2, t2));

    return 0;
}