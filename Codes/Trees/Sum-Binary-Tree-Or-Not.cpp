/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct capsule{
    int sum = 0;
    bool boolean = false;
};

capsule helper(TreeNode* A)
{
    if(A==NULL)
    {
        capsule ans;
        ans.sum = 0;
        ans.boolean = true;
        return ans;
    }
    
    if(A->left==NULL && A->right==NULL)
    {
        capsule ans;
        ans.sum = A->val;
        ans.boolean = true;
        return ans;
    }
    
    capsule leftAns = helper(A->left);
    capsule rightAns = helper(A->right);
    
    capsule ans;
    ans.sum = leftAns.sum+rightAns.sum+A->val;
    ans.boolean = leftAns.boolean && rightAns.boolean && (A->val==leftAns.sum+rightAns.sum);
    return ans;
}
int Solution::solve(TreeNode* A) {
    
    return helper(A).boolean;
    
    
}
