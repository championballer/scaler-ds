int Solution::maxProduct(const vector<int> &A) {
    
    int mx_ans = A[0];
    int current_p = 1;
    int current_n = 1;
    
    for(int i=0;i<A.size();i++)
    {
        current_n*=A[i];
        current_p*=A[i];
        int temp = current_p;
        
        if(current_n>current_p)
        {
            swap(current_n,current_p);
            temp = current_p;
        }
        
        else if(current_p<0)current_p = 1;
        else if(current_p==0)
        {
            current_p = 1;
            current_n = 1;
        }
        
        mx_ans = max(mx_ans,temp);
        
    }
    
    return mx_ans;
}
