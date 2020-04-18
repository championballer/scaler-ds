int Solution::solve(int A) {
    
    if(A==0)return 0;
    if(A==1)return 1;
    vector<int> dp(A+1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3;i<=A;i++)
    {
        dp[i] = ((dp[i-1]%10003)+(((i-1)%10003)*((dp[i-2])%10003))%10003)%10003;
        //cout<<i<<":"<<dp[i]<<endl;
    }
    return dp[A]%10003;
}
