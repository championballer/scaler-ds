int Solution::numOptions(vector<int> &A, int B, int C) {
    
    int ways = 0;
    int sum = 0;
    int i=0,j=0;
    while(i!=A.size() && j!=A.size())
    {
        if(i==j)
        {
            if(A[i]>C)
            {
                i++;
                j++;
            }
            
            else
            {
                if(A[i]>=B && A[i]<=C)ways++;
                j++;
            }
            
            sum = A[i];
        }
        
        else
        {
            sum+=A[j];
            if(sum>C)
            {   
                i++;
                j=i;
            }
            else if(sum>=B && sum<=C)
            {
                ways++;
                j++;
            }
            
            else
            {
                j++;
            }
            
            if(j==A.size() && i!=A.size())
            {
                i++;
                j=i;
            }
        }
    }
    
    return ways;
}
