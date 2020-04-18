int helper(vector<vector<int> > & A, int i, int j, vector<vector<int> > & mem)
{
    if(i>=A.size() || j>=A[i].size())
    {
       return INT_MAX;
    }
    
    if(mem[i][j]!=-1)return mem[i][j];
    
    int sans1 = helper(A,i+1,j,mem);
    int sans2 = helper(A,i+1,j+1,mem);

    if(sans1!=INT_MAX || sans2!=INT_MAX)mem[i][j] = A[i][j] + min(sans1,sans2);
    else mem[i][j] = A[i][j];
    return mem[i][j];
    
}

int Solution::minimumTotal(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A.size()==0)return 0;
    if(A.size()==1)return A[0][0];
    vector<vector<int> > mem(A.size());
    for(int i=0;i<A.size();i++)
    {
        mem[i] = vector<int>(A[i].size(),-1);
    }
    
    return helper(A,0,0,mem);
}
