/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    
    queue<TreeLinkNode*> parents;
    queue<TreeLinkNode*> children;
    parents.push(A);
    
    while(!parents.empty())
    {
        TreeLinkNode* top = NULL;
        TreeLinkNode* next = NULL;
        while(!parents.empty() || next!=NULL)
        {
            if(top==NULL)
            {
                top = parents.front();
                parents.pop();
            }
            
            else
            {
                top = next;
            }
            
            if(!parents.empty())
            {
                next = parents.front();
                parents.pop();
            }
                
            else next = NULL;
            
            top->next = next;
            if(top->left)children.push(top->left);
            if(top->right)children.push(top->right);
        }
        
        while(!children.empty())
        {
            parents.push(children.front());
            children.pop();
        }
    }
    
}
