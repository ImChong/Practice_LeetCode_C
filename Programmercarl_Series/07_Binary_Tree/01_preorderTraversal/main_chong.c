/* 144.二叉树的前序遍历：https://leetcode.cn/problems/binary-tree-preorder-traversal/ */

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/* ==================================================================================================== */
/* ==================================================================================================== */
/* TODO: 目标函数: 递归遍历 */
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    return NULL;
}

/* TODO: 目标函数：迭代遍历  */


/* ==================================================================================================== */
/* ==================================================================================================== */

/* NOTE：主函数 */
int main(int argc, const char* argv[]) {
    struct TreeNode n1, n2, n3;
    n1.val = 1;
    n2.val = 2;
    n3.val = 3;
    n1.right = &n2;
    n2.left = &n3;

    int returnSize;
    int *result = preorderTraversal(&n1, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }

    free(result);
    return 0;
}