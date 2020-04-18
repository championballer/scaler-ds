int helper(string A,string B,int i,int j,vector<vector<int> > & mem)
{
    if(i>=A.length())return 0;
    if(j>=B.length())return 0;
    if(mem[i][j])return mem[i][j];

    int sans1 = helper(A,B,i+1,j,mem);
    int sans2 = helper(A,B,i,j+1,mem);
    int sans3 = helper(A,B,i+1,j+1,mem);
    int ans = 0;
    
    if(A[i]==B[j])ans = sans3+1;
    else ans = max(sans1,sans2);
    mem[i][j] = ans;
    return mem[i][j];
    
}

int Solution::solve(string A, string B) {
    
    vector<vector<int> > mem(A.length(),vector<int>(B.length()));
    return helper(A,B,0,0,mem);
    
}
