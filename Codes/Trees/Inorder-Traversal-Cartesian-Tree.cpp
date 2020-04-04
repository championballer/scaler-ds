int maxi(vector<int> &A, int si, int ei)
{
    int mx = si;
    for(int i=si+1;i<=ei;i++)
    {
        if(A[i]>A[mx])mx = i;
    }
    
    return mx;
}
 
TreeNode* helper(vector<int>& A, int si, int ei)
{
    if(si>ei)return NULL;
    
    int mxi = maxi(A,si,ei);
    
    TreeNode* root = new TreeNode(A[mxi]);
    root->left = helper(A,si,mxi-1);
    root->right = helper(A,mxi+1,ei);
    
    return root;
}
 
TreeNode* Solution::buildTree(vector<int> &A) {
    return helper(A,0,A.size()-1);    
}