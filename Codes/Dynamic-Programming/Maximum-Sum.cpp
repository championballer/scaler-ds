int Solution::solve(vector<int> &A, int B, int C, int D) {
    
    vector<int> f(A.size(),0);
    vector<int> s(A.size(),0);
    vector<int> t(A.size(),0);
    
    for(int i=0;i<A.size();i++)
    {
        f[i] = A[i]*B;
        s[i] = A[i]*C;
        t[i] = A[i]*D;
    }
    
    vector<int> amxl(A.size(),0);
    vector<int> amxr(A.size(),0);
    int mx = INT_MIN;
    for(int i=0;i<A.size();i++)
    {
        mx = max(mx,f[i]);
        amxl[i] = mx;
        //cout<<amxl[i]<<" ";
    }
    
    //cout<<endl;
    
    
    
    mx = INT_MIN;
    for(int i=A.size()-1;i>=0;i--)
    {
        mx = max(mx,t[i]);
        amxr[i] = mx;
        //cout<<amxr[i]<<" ";
    }
    
    //cout<<endl;
    
    int result = INT_MIN;
    for(int i=0;i<A.size();i++)
    {
        result = max(result,amxl[i]+s[i]+amxr[i]);
    }
    
    return result;
}
