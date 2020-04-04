int Solution::solve(string A) {
int * pre = new int[A.length()];
	memset(pre,0,sizeof(int)*A.length());
    pre[0] = 0;
    
    for(int i=1,j=0;i<A.length();)
    {
        if(A[i]==A[j])
        {
            pre[i] = j+1;
            i++;
            j++;
            continue;
        }
        
        else
        {
            if(j==0)
            {
                pre[i] = 0;
                i++;
                continue;
            }
            
            j = pre[j-1];
        }
    }


    
    int x = pre[A.length()-1];
    int diff = A.length()-x;
    if(diff==A.length())return 0;
    else if(A.length()%diff==0)return 1;
    else return 0;
}
