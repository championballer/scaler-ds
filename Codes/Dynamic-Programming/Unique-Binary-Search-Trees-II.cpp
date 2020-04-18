int Solution::numTrees(int A) {
    
    vector<int> dp(A+1);
    dp[0] = 1;
    for(int i=1;i<=A;i++)
    {
        int current = 0;
        for(int j=1;j<=i;j++)
        {
            current+=(dp[i-j]*dp[j-1]);
        }
        
        dp[i] = current;
    }
    
    return dp[A];
}
