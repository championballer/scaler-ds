/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    
    if(A==NULL && B==NULL)return 1;
    else if(A!=NULL && B==NULL)return 0;
    else if(A==NULL && B!=NULL)return 0;
    
    int ans1 = isSameTree(A->left,B->left);
    int ans2 = isSameTree(A->right,B->right);
    int ans3 = (A->val==B->val);
    
    return ans1&&ans2&&ans3;
    
}
