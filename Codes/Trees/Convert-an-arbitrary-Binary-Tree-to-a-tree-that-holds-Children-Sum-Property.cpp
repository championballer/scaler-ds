/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void balance(TreeNode* A, int diff)
{
    if(A==NULL)return;
    A->val+=diff;
    if(A->left!=NULL)balance(A->left,diff);
    else if(A->right!=NULL)balance(A->right,diff);
    return;
}
 
TreeNode* Solution::solve(TreeNode* A) {
    
    if(A==NULL)return A;
    if(A->left==NULL && A->right==NULL)return A;
    TreeNode* leftTree = solve(A->left);
    TreeNode* rightTree = solve(A->right);
    
    int diff = 0;
    if(A->left==NULL)diff = A->right->val - A->val;
    else if (A->right==NULL)diff = A->left->val - A->val;
    else diff = (A->right->val+A->left->val) - A->val;
    
    if(diff==0)return A;
    if(diff>0)A->val+=diff;
    if(diff<0)
    {
        if(A->left!=NULL)balance(A->left,abs(diff));
        else balance(A->right,abs(diff));
    }
    
    return A;
}
