int Solution::longestSubsequenceLength(const vector<int> &A) {
    
    if(A.size()==0)return 0;
    vector<int> left(A.size());
    left[0] = 1;
    for(int i=1;i<A.size();i++)
    {
        int mx = 0;
        for(int j=i-1;j>=0;j--)
        {
            if(A[i]>A[j] && left[j]>mx)mx=left[j];
        }
        left[i] = mx+1;
    }
    
    vector<int> right(A.size());
    right[A.size()-1] = 1;
    for(int i=A.size()-2;i>=0;i--)
    {
        int mx = 0;
        for(int j=i+1;j<A.size();j++)
        {
            if(A[i]>A[j] && right[j]>mx)mx = right[j];
        }
        right[i] = mx+1;
    }
    
    vector<int> fans(A.size());
    int mx = 0;
    for(int i=0;i<A.size();i++)
    {
        fans[i] = left[i]+right[i]-1;
        if(fans[i]>mx)mx = fans[i];
    }
    
    
    return mx;
}
