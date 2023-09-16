/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void preOrder(struct TreeNode *root, int *ret, int *i) {
    if (root == NULL)
        return;
    ret[(*i)++] = root->val;
    preOrder(root->left, ret, i);//i已经是指针了，不需要&
    preOrder(root->right, ret, i);
}

//144. 二叉树的中序遍历
int *preorderTraversal(struct TreeNode *root, int *returnSize) {
    int *ret = (int *) malloc(sizeof(int) * 100);
    int j = 0;
    preOrder(root, ret, &j);
    *returnSize = j;
    return ret;
}