int Solution::countMinSquares(int A) {
    
    vector<int> dp(A+1);
    dp[0] = 0;
    for(int i=1;i<=A;i++)
    {
        int mn = INT_MAX;
        for(int j=1;j*j<=i;j++)
        {
            //cout<<i<<"-"<<j<<"-"<<dp[i-(j*j)]<<"\n";
            int current = dp[i-(j*j)];
            if(current<mn)mn = current;
        }
        dp[i] = mn+1;
    }
    
    return dp[A];
    
}
