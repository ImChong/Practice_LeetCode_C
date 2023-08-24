/* 用数组来存储二叉树: 如果父节点的数组下标是 i，那么它的左孩子就是 i * 2 + 1，右孩子就是 i * 2 + 2。*/
/* 
 * 二叉树主要有两种遍历方式：
 *      深度优先遍历：先往深走，遇到叶子节点再往回走。
 *          前序遍历（递归法，迭代法）
 *          中序遍历（递归法，迭代法）
 *          后序遍历（递归法，迭代法）
 *      广度优先遍历：一层一层的去遍历。
 *          层次遍历（迭代法）
 */


#include <stdio.h>

/* NOTE: 树节点 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/* NOTE: 前序遍历: 递归 */
void preOrder(struct TreeNode *node, int *ret, int *returnSize) {
    if (node == NULL) {
        return;
    }
    ret[(*returnSize)++] = node->val;
    preOrder(node->left, ret, returnSize);
    preOrder(node->right, ret, returnSize);
}

int *preorderTraversal(struct TreeNode *root, int *returnSize) {
    int *ret = (int *)malloc(sizeof(int) * 100);
    *returnSize = 0;
    preOrder(root, ret, returnSize);
    return ret;
}

/* NOTE: 中序遍历: 递归 */
void inOrder(struct TreeNode *node, int *ret, int *returnSize) {
    if (!node) {
        return;
    }
    inOrder(node->left, ret, returnSize);
    ret[(*returnSize)++] = node->val;
    inOrder(node->right, ret, returnSize);
}

int *inorderTraversal(struct TreeNode *root, int *returnSize) {
    int *ret = (int *)malloc(sizeof(int) * 100);
    *returnSize = 0;
    inOrder(root, ret, returnSize);
    return ret;
}

/* NOTE: 后序遍历: 递归 */
void postOrder(struct TreeNode *node, int *ret, int *returnSize) {
    if (!node) {
        return;
    }
    postOrder(node->left, ret, returnSize);
    postOrder(node->right, ret, returnSize);
    ret[(*returnSize)++] = node->val;
}

int *postorderTraversal(struct TreeNode *root, int *returnSize) {
    int *ret = (int *)malloc(sizeof(int) * 100);
    *returnSize = 0;
    postOrder(root, ret, returnSize);
    return ret;
}

/* TODO: 前序遍历: 迭代 */

/* TODO: 前序遍历: 迭代 */

/* TODO: 前序遍历: 迭代 */

/* NOTE: 主函数 */
int main(int argc, const char* argv[]) {

    return 0;
}