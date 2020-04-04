/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void helper(TreeNode* root,vector<vector<int> > & result,vector<int> & current)
{
    if(root->left==NULL && root->right==NULL)
    {
        current.push_back(root->val);
        result.push_back(current);
        current.pop_back();
    }
    current.push_back(root->val);
    if(root->left)
    {
        helper(root->left,result,current);
    }
    
    if(root->right)
    {
        helper(root->right,result,current);
    }
    
    current.pop_back();
}

vector<vector<int> > Solution::solve(TreeNode* A) {

    vector<vector<int> > result;
    if(A==NULL)return result;
    vector<int> current;
    helper(A,result,current);
    return result;
}
