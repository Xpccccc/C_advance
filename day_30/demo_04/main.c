/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void exchangeNode(struct TreeNode *root, struct TreeNode *left, struct TreeNode *right) {
    struct TreeNode *tmp = left;
    left = right;
    right = tmp;
    //根指向新的左右结点
    root->left = left;
    root->right = right;
}

//226. 翻转二叉树
struct TreeNode *invertTree(struct TreeNode *root) {
    if (root == NULL)
        return NULL;
    //交换左右结点
    exchangeNode(root, root->left, root->right);
    root->left = invertTree(root->left);
    root->right = invertTree(root->right);
    return root;
}