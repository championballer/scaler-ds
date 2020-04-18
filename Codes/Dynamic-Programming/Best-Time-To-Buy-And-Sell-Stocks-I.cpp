int Solution::maxProfit(const vector<int> &A) {
    if(A.size()==0)return 0;
    int mn = A[0];
    int profit = 0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]<=mn)mn = A[i];
        else{
            int diff = A[i]-mn;
            if(diff>profit)profit=diff;
        }
    }
    
    return profit;
}
