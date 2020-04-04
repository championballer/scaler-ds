/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class capsule{
  public:
  int l;
  int s;
  bool v;
};

capsule helper(TreeNode* A)
{
    if(A==NULL)
    {
       capsule ans;
       ans.v = true;
       ans.l = INT_MIN;
       ans.s = INT_MAX;
       
       return ans;
    }
    
    if(A->left==NULL && A->right==NULL)
    {
        capsule ans;
        ans.v = true;
        ans.l = A->val;
        ans.s = A->val;
    }
    
    capsule sans1 = helper(A->left);
    capsule sans2 = helper(A->right);
    capsule ans;
    if(sans1.v && sans2.v)
    {
        //cout<<"Prev: "<<sans1.l<<" "<<sans2.s<<" "<<A->val<<endl;
        ans.v = A->val>sans1.l && A->val<sans2.s;
        
        ans.l = max(A->val,max(sans1.l,sans2.l));
        ans.s = min(A->val,min(sans1.s,sans2.s));
        //cout<<"Current: "<<ans.l<<" "<<ans.s<<" "<<ans.v<<endl;
        return ans;
    }
    
    else
    {
        ans.v = false;
        ans.l = max(A->val,max(sans1.l,sans2.l));
        ans.s = min(A->val,min(sans1.s,sans2.s));
        
        return ans;
    }
}

int Solution::isValidBST(TreeNode* A) {
    capsule ans = helper(A);
    return ans.v;
}
