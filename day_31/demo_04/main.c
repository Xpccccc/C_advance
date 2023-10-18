/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */
/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 
 * @param root TreeNode类 
 * @return int整型
 */

//NC248 左叶子之和
int sumOfLeftLeaves(struct TreeNode* root ) {
    // write code here
    if( root == NULL)
        return 0;
    int sum = 0;
    if(root->left != NULL && root->left->left == NULL&&root->left->right == NULL)
        sum += root->left->val;
    int left = sumOfLeftLeaves(root->left);
    int right = sumOfLeftLeaves(root->right);
    sum += left+right;
    return sum;
}