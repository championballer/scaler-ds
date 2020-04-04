/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
    
    vector<int> result;
    TreeNode* current = A;
    stack<TreeNode*> st;
    
    while(current!=NULL || !st.empty())
    {
        if(current==NULL)
        {
            TreeNode* top = st.top();
            st.pop();
            result.push_back(top->val);
            current = top->right;
        }
        
        else
        {
            st.push(current);
            current = current->left;
        }
        
    }
    
    return result;
}