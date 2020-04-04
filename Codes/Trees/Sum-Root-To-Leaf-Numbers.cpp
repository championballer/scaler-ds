int helper(TreeNode* A, int num)
{
    if(A==NULL)return 0;
    if(A->left==NULL && A->right==NULL)return ((num*10)%1003+(A->val))%1003;
    
    int cnum = ((num*10)%1003+(A->val))%1003;
    int lans = helper(A->left,cnum);
    int rans = helper(A->right,cnum);
    
    return (lans%1003+rans%1003)%1003;
}
 
int Solution::sumNumbers(TreeNode* A) {
    
    if(A==NULL)return 0;
    
    return helper(A,0);
 
}