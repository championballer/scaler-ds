int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    
    vector<vector<int> > dp(A.size(),vector<int>(A[0].size()));
    
    int x = A.size();
    int y = A[0].size();
    
    if(A[x-1][y-1]<0)
    {
        dp[x-1][y-1] = 1+abs(A[x-1][y-1]);
    }
    
    else dp[x-1][y-1] = 1;
    
    for(int i=x-2;i>=0;i--)
    {
        int current = dp[i+1][y-1] - A[i][y-1];
        if(current>0)dp[i][y-1] = current;
        else dp[i][y-1] = 1;
    }
    
    for(int j=y-2;j>=0;j--)
    {
        int current = dp[x-1][j+1] - A[x-1][j];
        if(current>0)dp[x-1][j] = current;
        else dp[x-1][j] = 1;
    }
    
    for(int i=x-2;i>=0;i--)
    {
        for(int j=y-2;j>=0;j--)
        {
            int current = min(dp[i+1][j],dp[i][j+1])-A[i][j];
            if(current>0)dp[i][j] = current;
            else dp[i][j] = 1;
        }
    }
    
    return dp[0][0];
    
}
