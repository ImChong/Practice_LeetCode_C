/* 用数组来存储二叉树: 如果父节点的数组下标是 i，那么它的左孩子就是 i * 2 + 1，右孩子就是 i * 2 + 2。*/
/* 
 * 二叉树主要有两种遍历方式：
 *      深度优先遍历：先往深走，遇到叶子节点再往回走。
 *      广度优先遍历：一层一层的去遍历。
 */


#include <stdio.h>

/* NOTE: 树节点 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/* NOTE: 主函数 */
int main(int argc, const char* argv[]) {

    return 0;
}