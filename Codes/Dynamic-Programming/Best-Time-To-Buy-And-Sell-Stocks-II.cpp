int Solution::maxProfit(const vector<int> &A) {
    if(A.size()==0 || A.size()==1)return 0;
    int profit = 0;
    for(int i=0;i<A.size()-1;i++)
    {
        if(A[i+1]>A[i])
        {
            profit+=A[i+1]-A[i];
        }
    }
    
    return profit;
}
