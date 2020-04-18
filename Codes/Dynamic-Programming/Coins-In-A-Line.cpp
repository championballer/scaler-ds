int dp[1000][1000];

int helper(vector<int> & A, int i,int j)
{
    if(i>A.size())return 0;
    if(j<0)return 0;
    if(i==j)return A[i];
    if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    
    dp[i][j] = max(A[i]+min(helper(A,i+2,j),helper(A,i+1,j-1)),A[j]+min(helper(A,i,j-2),helper(A,i+1,j-1)));
    
    return dp[i][j];
}
int Solution::maxcoin(vector<int> &A) {
    
    memset(dp,-1,sizeof(dp));
    return helper(A,0,A.size()-1);
}
