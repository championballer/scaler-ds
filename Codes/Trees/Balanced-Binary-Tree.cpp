/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
struct ans{
    int height;
    bool balanced;
}; 
 
ans helper(TreeNode* A)
{
    if(A==NULL)
    {
        ans a;
        a.height = 0;
        a.balanced = true;
        return a;
    }
    
    ans leftAns = helper(A->left);
    ans rightAns = helper(A->right);
    
    int height = max(leftAns.height, rightAns.height)+1;
    bool balanced = (abs(leftAns.height-rightAns.height)<=1) && (leftAns.balanced) && (rightAns.balanced);
    
    ans a;
    a.height = height;
    a.balanced = balanced;
    return a;
}
 
int Solution::isBalanced(TreeNode* A) {
    
    return helper(A).balanced;
}
