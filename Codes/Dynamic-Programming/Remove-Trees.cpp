int dp[19][19];

int helper(vector<int> & A, int x, int y)
{
	
	if(dp[x][y]!=-1)return dp[x][y];
	if(y-x<2)return 0;
	if(y-x==2)
	{
		dp[x][y] = A[x]*A[x+1]*A[x+2];
		return dp[x][y];
	}
	int mn = INT_MAX;
	for(int i = x+1;i<y;i++)
	{
		mn = min((A[x]*A[i]*A[y]+helper(A,x,i)+helper(A,i,y)),mn);
	}
	return mn;
}

int Solution::solve(vector<int> &A) {
    memset(dp,-1,sizeof(dp));
    return helper(A,0,A.size()-1);
}
