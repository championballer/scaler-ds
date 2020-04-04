/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    vector<vector<int> > result;
    if(A==NULL)return result;
    
    queue<pair<TreeNode*,int> > pendingNodes;
    pendingNodes.push(make_pair(A,0));
    map<int, vector<int> > ourmap;
    
    while(!pendingNodes.empty())
    {
        TreeNode* front = pendingNodes.front().first;
        int dis = pendingNodes.front().second;
        pendingNodes.pop();
        ourmap[dis].push_back(front->val);
        if(front->left!=NULL)
        pendingNodes.push(make_pair(front->left,dis-1));
        if(front->right!=NULL)
        pendingNodes.push(make_pair(front->right,dis+1));
    }
    
    for(auto it = ourmap.begin();it!=ourmap.end();it++)
    {
        vector<int> small;
        for(int i = 0;i<it->second.size();i++)
        {
            small.push_back(it->second[i]);
        }
        result.push_back(small);
    }
    
    return result;
}