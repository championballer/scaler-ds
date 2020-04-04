/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::minDepth(TreeNode* A) {
    
    if(A==NULL)return 0;
    if(A->left==NULL && A->right==NULL)return 1;
    
    int leftAns = INT_MAX;
    if(A->left!=NULL)leftAns = minDepth(A->left);
    
    int rightAns = INT_MAX;
    if(A->right!=NULL)rightAns = minDepth(A->right);
    
    return min(leftAns,rightAns)+1;
}
