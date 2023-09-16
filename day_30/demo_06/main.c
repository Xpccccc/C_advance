/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//101. 对称二叉树
bool Compare(struct TreeNode *lt, struct TreeNode *rt) {
    //子树所走的指针方向也对称下去
    //比如左边的指向左边的左边，则右边的就指向右边的右边
    //比如左边的指向左边的右边，则右边的就指向右边的左边

    //当前结点
    if (lt == NULL && rt == NULL)
        return true;
    if (lt == NULL || rt == NULL)
        return false;
    if (lt->val != rt->val)
        return false;
    //左边结点 右边结点
    if (lt->left == NULL && rt->right == NULL)
        return Compare(lt->right, rt->left);
    if (lt->right == NULL && rt->left == NULL)
        return Compare(lt->left, rt->right);
    if (lt->left == NULL || rt->right == NULL)
        return false;
    if (lt->right == NULL || rt->left == NULL)
        return false;
    return Compare(lt->left, rt->right) && Compare(lt->right, rt->left);
}

bool isSymmetric(struct TreeNode *root) {
    //子树所走的指针方向也对称下去
    return Compare(root, root);
}