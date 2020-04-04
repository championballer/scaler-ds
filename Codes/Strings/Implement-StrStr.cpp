int Solution::strStr(const string A, const string B) {
    
    int * lps = new int[B.length()];
    memset(lps,0,sizeof(int)*B.length());
    
    for(int i=1,j=0;i<B.length();)
    {
        if(B[i]==B[j])
        {
            lps[i] = j+1;
            i++;
            j++;
        }
        
        else
        {
            if(j==0)
            {
                lps[i] = 0;
                i++;
                continue;
            }
            
            else
            {
                j = lps[j-1];
            }
        }
    }
    
    for(int i=0,j=0;i<A.length();)
    {
        if(A[i]==B[j])
        {
            i++;
            j++;
            if(j==B.length())
            {
                return i-j;
            }
        }
        
        else
        {
            if(j==0)
            {
                i++;
                continue;
            }
            
            else
            {
                j = lps[j-1];
            }
        }
    }
    return -1;
    
}
