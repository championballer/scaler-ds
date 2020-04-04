/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::invertTree(TreeNode* A) {
    if(A==NULL)return NULL;
    
    TreeNode * temp = A->right;
    A->right = A->left;
    A->left = temp;
    
    A->left = invertTree(A->left);
    A->right = invertTree(A->right);
    
    return A;
}
