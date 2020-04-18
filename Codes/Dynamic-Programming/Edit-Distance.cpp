int helper(string A, string B, int i, int j, vector<vector<int> > & mem)
{
    if(i>=A.length())return B.length()-j;
    if(j>=B.length())return A.length()-i;
    if(mem[i][j])return mem[i][j];
    
    int sans1 = helper(A,B,i+1,j,mem);
    int sans2 = helper(A,B,i,j+1,mem);
    int sans3 = helper(A,B,i+1,j+1,mem);
    int ans = 0;
    if(A[i]==B[j])ans = sans3;
    else ans = min(sans1,min(sans3,sans2))+1;
    
    mem[i][j] = ans;
    return ans;
}


int Solution::minDistance(string A, string B) {
    
    vector<vector<int> > mem(A.length(),vector<int>(B.length()));
    return helper(A,B,0,0,mem);
}
