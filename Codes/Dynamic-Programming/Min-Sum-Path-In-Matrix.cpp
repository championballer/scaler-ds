int helper(vector<vector<int> >&A,int i,int j,vector<vector<int> >& mem)
{
    if(i>=A.size())return INT_MAX;
    if(j>=A[0].size())return INT_MAX;
    if(i==A.size()-1 && j==A[0].size()-1)return A[i][j];
    if(mem[i][j])return mem[i][j];
    
    int sans1 = helper(A,i+1,j,mem);
    int sans2 = helper(A,i,j+1,mem);
    int ans = min(sans1,sans2)+A[i][j];
    mem[i][j] = ans;
    
    return ans;
    
    
}

int Solution::minPathSum(vector<vector<int> > &A) {
    
    vector<vector<int> > mem(A.size(),vector<int>(A[0].size()));
    return helper(A,0,0,mem);
}
