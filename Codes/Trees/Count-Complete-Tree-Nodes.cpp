/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::solve(TreeNode* A) {
    
    if(A==NULL)return 0;
    if(A->left==NULL && A->right==NULL)return 1;
    
    int leftAns = solve(A->left);
    int rightAns = solve(A->right);
    
    return leftAns+rightAns+1;
}
