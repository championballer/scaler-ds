/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
stack<TreeNode*> inorder;
TreeNode* current;
TreeNode* top; 

BSTIterator::BSTIterator(TreeNode *root) {
    
    current = root;
    top = NULL;
    while(current!=NULL)
    {
        inorder.push(current);
        current = current->left;
    }
    
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return !inorder.empty();
}

/** @return the next smallest number */
int BSTIterator::next() {
    
    top = inorder.top();
    inorder.pop();
    
    current = top->right;
    while(current!=NULL)
    {
        inorder.push(current);
        current = current->left;
    }
    
    return top->val;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
