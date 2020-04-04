/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void leftNext(TreeNode* leftCurrent, stack<TreeNode*> & leftStk)
{
    while(leftCurrent!=NULL)
    {
        leftStk.push(leftCurrent);
        leftCurrent = leftCurrent -> left;
    }
}

void rightNext(TreeNode* rightCurrent, stack<TreeNode*> & rightStk)
{
    while(rightCurrent!=NULL)
    {
        rightStk.push(rightCurrent);
        rightCurrent = rightCurrent -> right;
    }
}

int Solution::t2Sum(TreeNode* A, int B) {
    
    if(A==NULL)return 0;
    if(A->left==NULL && A->right==NULL)return 0;
    stack<TreeNode* > leftStk;
    stack<TreeNode* > rightStk;
    
    TreeNode* leftCurrent = A;
    TreeNode* leftTop = NULL;
    TreeNode* rightCurrent = A;
    TreeNode* rightTop = NULL;
    
    leftNext(leftCurrent,leftStk);
    leftTop = leftStk.top();
    leftStk.pop();
    leftCurrent = leftTop -> right;
    leftNext(leftCurrent,leftStk);
    //cout<<leftTop->val<<endl;
    rightNext(rightCurrent,rightStk);
    rightTop = rightStk.top();
    rightStk.pop();
    rightCurrent = rightTop -> left;
    rightNext(rightCurrent,rightStk);
    //cout<<rightTop->val<<endl;
    while(leftTop!=rightTop)
    {
        //cout<<leftTop->val<<" "<<rightTop->val<<endl;
        if(rightTop->val+leftTop->val==B)return 1;
        else if(rightTop->val+leftTop->val>B)
        {
            if(rightStk.empty())break;
            rightTop = rightStk.top();
            rightStk.pop();
            rightCurrent = rightTop->left;
            rightNext(rightCurrent,rightStk);
        }
        
        else
        {
            if(leftStk.empty())break;
            leftTop = leftStk.top();
            leftStk.pop();
            leftCurrent = leftTop->right;
            leftNext(leftCurrent,leftStk);
        }
    }
    
    
    return 0;
}
