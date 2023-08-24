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
void preorder(struct TreeNode *root, int *res, int *resSize) {
    if (root == NULL) {
        return;
    }
    res[(*resSize)++] = root->val;
    preorder(root->left, res, resSize);
    preorder(root->right, res, resSize);
}

int* preorderTraversal_recursion(struct TreeNode* root, int* returnSize) {
    int *res = (int *)malloc(sizeof(int) * 2000);
    *returnSize = 0;
    preorder(root, res, returnSize);
    return res;
}

/* TODO: 目标函数：迭代遍历  */
int* preorderTraversal_iteration(struct TreeNode* root, int* returnSize) {
    return NULL;
}

/* ==================================================================================================== */
/* ==================================================================================================== */

/* NOTE：主函数 */
int main(int argc, const char* argv[]) {
    /* NOTE: Test case 1 */
    printf("======== Case 1 ======== \n");
    struct TreeNode n1, n2, n3;
    n1.val = 1;
    n2.val = 2;
    n3.val = 3;
    n1.left = NULL;
    n1.right = &n2;
    n2.left = &n3;
    n2.right = NULL;
    n3.left = NULL;
    n3.right = NULL;

    int returnSize = 0;
    int *result = preorderTraversal_recursion(&n1, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }

    free(result);
    return 0;
}