int Solution::numDistinct(string A, string B) {
    
    vector<vector<int> > dp(A.length()+1,vector<int>(B.length()+1,0));
    
    for(int i=0;i<=A.length();i++)
    {
        dp[i][0] = 1;
    }
    
    int a = A.length();
    int b = B.length();
    for(int i=1;i<=A.length();i++)
    {
        for(int j=1;j<=B.length();j++)
        {
            if(A[a-i]==B[b-j])
            {
                dp[i][j] = dp[i-1][j]+dp[i-1][j-1];
            }
            
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[A.length()][B.length()];
}
