int Solution::lis(const vector<int> &A) {
    
    if(A.size()==0)return 0;
    vector<int> left(A.size());
    left[0] = 1;
    int gmx = 1;
    for(int i=1;i<A.size();i++)
    {
        int mx = 0;
        for(int j=i-1;j>=0;j--)
        {
            if(A[i]>A[j] && left[j]>mx)mx=left[j];
        }
        left[i] = mx+1;
        if(left[i]>gmx)gmx = left[i];
    }
    
    return gmx;
    
}
