/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//100. 相同的树
bool isSameTree(struct TreeNode *p, struct TreeNode *q) {
    //判断根是否相同，左右子树是否相同
    if (p == NULL && q == NULL)
        return true;
    if (p == NULL || q == NULL) // 一个为空，一个不为空
        return false;
    if (p->val != q->val) //这里不能用 == 用的话直接就返回了
        return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}