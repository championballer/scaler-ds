string Solution::simplifyPath(string A) {
    
    stack<string> st;
    for(int i=0;i<A.length();)
    {
        if(A[i]=='/')
        {
            i++;
            continue;
        }
        else if(isalpha(A[i]))
        {
            string a = "";
            while(isalpha(A[i]))
            {
                a+=A[i];
                i++;
            }
            
            st.push(a);
        }
        
        else if(A[i]=='.' && (i+1!=A.length() && A[i+1]=='.'))
        {
            if(!st.empty())
            st.pop();
            i+=2;
        }
        else
        {
            i++;
        }
    }
    
    stack<string> rev;
    while(!st.empty())
    {
        rev.push(st.top());
        st.pop();
    }
    string ans = "/";
    while(!rev.empty())
    {
        ans+=rev.top();rev.pop();
        if(!rev.empty())ans+='/';
    }
    return ans;
}
