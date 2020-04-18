int helper(vector<vector<int> >& A,int i,int j, vector<vector<int> >& mem)
{
    if(i>=A.size())return 0;
    if(j>=A[0].size())return 0;
    if(A[i][j]==1)
    {
        return 0;
    }
    if(mem[i][j])return mem[i][j];
    if(i==A.size()-1 && j==A[0].size()-1)
    {
        if(A[i][j]==0)
        {
            mem[i][j] = 1;
            return 1;
        }
        
        else
        {   
            mem[i][j] = 0;
            return 0;
        }
    }
    int sans1 = helper(A,i+1,j,mem);
    int sans2 = helper(A,i,j+1,mem);
    int ans = 0;
    
    if(A[i][j]!=1)ans = sans1+sans2;
    mem[i][j] = ans;
    return ans;
}

int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    
    vector<vector<int> > mem(A.size(),vector<int>(A[0].size()));
    return helper(A,0,0,mem);
}
