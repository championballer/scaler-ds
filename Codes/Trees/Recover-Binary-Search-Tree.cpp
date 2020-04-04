/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void inorder(TreeNode* A, vector<int> & in)
{
    if(A==NULL)return;
    if(A->left==NULL && A->right==NULL)
    {
        in.push_back(A->val);
        return;
    }
    
    inorder(A->left,in);
    in.push_back(A->val);
    inorder(A->right,in);
    
}

vector<int> Solution::recoverTree(TreeNode* A) {
    vector<int> in;
    inorder(A,in);
    vector<int> ans;
    int f = 0;
    int s = 0;
    int t = 0;
    int flag = 0;
    for(int i=1;i<in.size();i++)
    {
        if(in[i]<in[i-1])
        {
            if(!flag)
            {
                f = in[i-1];
                s = in[i];
                flag = 1 ;
            }
            
            else
            {
                s = in[i];
                //t = in[i];
            }
        }
    }
    
    ans.push_back(min(f,s));
    ans.push_back(max(f,s));
    
    return ans;
}
