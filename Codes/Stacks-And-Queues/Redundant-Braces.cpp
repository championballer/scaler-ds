int Solution::braces(string A) {
    
    stack<char> st;
    for(int i=0;i<A.length();i++)
    {
        if(A[i]==')')
        {
            if(st.top()=='(')return 1;
            else
            {
                while(st.top()!='(')st.pop();
                st.pop();
            }
        }
        
        else
        {
            if(A[i]>='a' && A[i]<='z')continue;
            st.push(A[i]);
        }
    }
    
    return 0;
}
