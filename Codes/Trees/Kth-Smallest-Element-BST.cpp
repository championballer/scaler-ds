/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void rotation(TreeNode* current, stack<TreeNode*> & stk)
{
    while(current!=NULL)
    {
        stk.push(current);
        current=current->left;
    }
}

int Solution::kthsmallest(TreeNode* A, int B) {
    
    stack<TreeNode*> stk;
    rotation(A,stk);
    TreeNode* current = NULL;
    int count = 0;
    while(count!=B)
    {
        TreeNode* top = stk.top();
        stk.pop();
        count++;
        if(count==B)return top->val;
        current = top->right;
        rotation(current,stk);
    }
    
}
