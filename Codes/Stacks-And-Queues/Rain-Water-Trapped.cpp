int Solution::trap(const vector<int> &A) {
    int n=A.size();
    vector<int> left(n,0);
    vector<int> right(n,0);
    left[0]=A[0];
    right[n-1]=A[n-1];
    for(int i=1;i<A.size();i++){
        left[i]=max(left[i-1],A[i]);
    }
    for(int i=n-2;i>=0;i--){
        right[i]=max(right[i+1],A[i]);
    }
    int ans=0;
    for(int i=0;i<n;i++){
       ans+=min(left[i],right[i])-A[i];
    }
    return ans;
}
