int Solution::climbStairs(int A) {
    
    vector<int> dp(A+1);
    dp[0] = 1;
    for(int i=1;i<A+1;i++)
    {
        int ans1 = 0;
        int ans2 = 0;
        if(i-1>=0)ans1 = dp[i-1];
        if(i-2>=0)ans2 = dp[i-2];
        
        dp[i] = ans1+ans2;
        
    }
    
    return dp[A];
    
}
