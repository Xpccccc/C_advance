/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//965. 单值二叉树

bool isUnivalTree(struct TreeNode* root){
    if(root == NULL)
        return true;
    if(root->left && root->val != root->left->val) //root->left确保左子树不空
        return false;
    if(root->right && root->val != root->right->val) //root->left确保右子树不空
        return false;
    //到这一步表示这层调用满足条件
    return isUnivalTree(root->left)&&isUnivalTree(root->right); //左子树右子树都满足条件就返回true
}