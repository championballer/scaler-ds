vector<int> Solution::solve(vector<int> &A) {
    
    int sieve[1000001];
    for(int i=0;i<=1000000;i++)sieve[i] = i;
    
    //Getting the highest prime factor for each number to be able to use multiplication principle
    for(int i=2;i*i<=1000000;i++)
    {
        if(sieve[i]==i)
        {
            for(int j=2*i;j<1000001;j+=i)
            {
                sieve[j] = i; 
            }    
        }
    }
    
    vector<int> result;
    for(int i=0;i<A.size();i++)
    {
        int current = A[i];
        int count = 1;
        while(current!=1)
        {
            int y = sieve[current];
            int small_count = 0;
            while(current%y==0)
            {
                small_count++;
                current/=y;
            }
            count = count*(1+small_count);
        }
        result.push_back(count);
        
    }
    
    return result;
}
