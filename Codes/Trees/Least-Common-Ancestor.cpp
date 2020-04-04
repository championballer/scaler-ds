/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
pair<int,TreeNode*> helper(TreeNode* A, int B, int C)
{
    if(A==NULL)
    {
        pair<int,TreeNode*> ans;
        ans.first = 0;
        ans.second = NULL;
        return ans;
    }
    
    pair<int,TreeNode*> sans1 = helper(A->left,B,C);
    pair<int,TreeNode*> sans2 = helper(A->right,B,C);
    
    int flag = 0;
    if(A->val==B && A->val==C)
    {
        flag = 2;
    }
    
    else if(A->val==B || A->val==C)flag = 1;
    
    pair<int,TreeNode*> ans;
    ans.first = sans1.first+sans2.first+flag;
    if(ans.first==2 && sans1.second==NULL && sans2.second==NULL)ans.second = A;
    else if(sans1.second)
    {
        ans.second = sans1.second;
    }
    
    else
    {
        ans.second = sans2.second;
    }
    
    return ans;
}
int Solution::lca(TreeNode* A, int B, int C) {
    
    pair<int,TreeNode*> ans = helper(A,B,C);
    if(ans.second==NULL)return -1;
    else return ans.second->val;
}
