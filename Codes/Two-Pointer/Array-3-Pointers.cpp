int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int i=0,j=0,k=0;
    int mn = INT_MAX;
    while(i!=A.size() && j!=B.size() && k!=C.size())
    {
        int option1 = abs(A[i]-B[j]);
        int option2 = abs(B[j]-C[k]);
        int option3 = abs(C[k]-A[i]);
        
        int mx = max(option1,max(option2,option3));
        if(mx<mn)mn = mx;
        if(option1==mx)
        {
            if(A[i]<B[j])i++;
            else j++;
        }
        
        else if(option2==mx)
        {
            if(B[j]<C[k])j++;
            else k++;
        }
        
        else if(option3==mx)
        {
            if(C[k]<A[i])k++;
            else i++;
        }
    }
    
    return mn;
}
