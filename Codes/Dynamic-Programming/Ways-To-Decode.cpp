bool checkValid(string A)
{
    if(A.length()==1)
    {
        return A[0]!='0';
    }
    
    else
    {
        if(A[0]=='1')return true;
        else if(A[0]=='2')
        {
            return A[1]>='0' && A[1]<='6';
        }
        
    }
    
    return false;
}

int Solution::numDecodings(string A) {
    
    int f = 1;
    int s = 1;
    if(!checkValid(A.substr(A.length()-1,1)))
    {
        f = 0;
    }
    
    for(int i=A.length()-2;i>=0;i--)
    {
        int ans = 0;
        bool sans1 = checkValid(A.substr(i,1));
        if(sans1)ans+=f;
        bool sans2 = checkValid(A.substr(i,2));
        if(sans2)ans+=s;
        s = f;
        f = ans;
        
    }
    return f;
    
}
