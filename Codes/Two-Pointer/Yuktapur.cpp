int Solution::solve(vector<int> &A, int B) {
    
    int mn = INT_MAX;
    int i = 0;
    int j = B;
    while(j<A.size())
    {
        mn = min(mn,A[i]-A[j]);
        i++;
        j=i+B;
    }
    
    return mn;
}
