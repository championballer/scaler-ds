/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A==NULL || (A->left==NULL && A->right==NULL))return A;
    
    TreeNode* left = flatten(A->left);
    TreeNode* new_right = flatten(A->right);
    TreeNode* right = A->right;
    A->right = left;
    A->left = NULL;
    TreeNode* current = A;
    while(current->right!=NULL)
    {
        current = current->right;
    }
    
    current->right = new_right;
    
    return A;
}
