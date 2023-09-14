/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


//防止递归深度太深，重复计算
int max(int a, int b) {
    return a > b ? a : b;
}

//104. 二叉树的最大深度
int maxDepth(struct TreeNode *root) {
    //分成求左子树的最大深度和右子树的最大深度
    if (root == NULL)
        return 0;
    //叶子结点
    if (root->left == NULL && root->right == NULL)
        return 1;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}