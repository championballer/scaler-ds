/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    
    vector<vector<int> > result;
    
    queue<TreeNode*> parents;
    queue<TreeNode*> children;
    stack<TreeNode*> buffer;
    int flag = 0;
    parents.push(A);
    while(!parents.empty())
    {
        vector<int> current;
        while(!parents.empty())
        {
            TreeNode* top = parents.front();
            parents.pop();
            current.push_back(top->val);
            
            if(!flag)
            {
                if(top->left)children.push(top->left);
                if(top->right)children.push(top->right);
            }
            
            else
            {
                if(top->right)children.push(top->right);
                if(top->left)children.push(top->left);
            }
        }    
        result.push_back(current);
        flag = (flag+1)%2;
            
        while(!children.empty())
        {
            buffer.push(children.front());
            children.pop();
        }
            
        while(!buffer.empty())
        {
            parents.push(buffer.top());
            buffer.pop();
        }
    }
    return result;
}
