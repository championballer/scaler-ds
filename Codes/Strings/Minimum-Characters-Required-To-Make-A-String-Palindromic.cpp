int Solution::solve(string A) {
    
    string rev = A;
    reverse(rev.begin(),rev.end());
    string composite = A+"$"+rev;
    
    int * pre = new int[composite.length()];
    pre[0] = 0;
    for(int i=1,j=0;i<composite.length();)
    {
        if(composite[j]!=composite[i])
        {
            if(j==0)
            {
                pre[i] = 0;
                i++;
                continue;
            }
            
            else
            {
                j = pre[j-1];
            }
        }
        
        else
        {
            
            pre[i] = j+1;
            i++;
            j++;
        }
    }
    
    return A.length()-pre[composite.length()-1];
}
