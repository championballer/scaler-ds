int Solution::solve(vector<vector<int> > &A) {
    
    vector<vector<int> > dp(A.size(),vector<int>(A[0].size(),0));
    int row = A.size();
    int col = A[0].size();
    
    if(A[row-1][col-1]!=1)dp[row-1][col-1] = 1;
    else return 0;
    
    for(int i=row-2;i>=0;i--)
    {
        if(A[i][col-1]==1)
        {
            dp[i][col-1] = 0;
        }
        
        else
        {
            dp[i][col-1] = dp[i+1][col-1];
        }
    }
    
    for(int j=col-2;j>=0;j--)
    {
        if(A[row-1][j]==1)
        {
            dp[row-1][j] = 0;
        }
        
        else
        {
            dp[row-1][j] = dp[row-1][j+1];
        }
    }
    
    for(int i=row-2;i>=0;i--)
    {
        for(int j=col-2;j>=0;j--)
        {
            if(A[i][j]==1)dp[i][j] = 0;
            else dp[i][j] = ((dp[i+1][j]%1000000007)+(dp[i][j+1]%1000000007))%1000000007;
        }
    }
    
    return dp[0][0]%1000000007;
}
