/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void inOrder(struct TreeNode *root, int *ret, int *i) {
    if (root == NULL)
        return;
    inOrder(root->left, ret, i);//i已经是指针了，不需要&
    inOrder(root->right, ret, i);
    ret[(*i)++] = root->val;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//145. 二叉树的后序遍历
int *postorderTraversal(struct TreeNode *root, int *returnSize) {
    int *ret = (int *) malloc(sizeof(int) * 100);
    int j = 0;
    inOrder(root, ret, &j);
    *returnSize = j;
    return ret;
}