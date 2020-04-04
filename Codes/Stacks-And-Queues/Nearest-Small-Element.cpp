vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> result;
    stack<int> st;
    for(int i=0;i<A.size();i++)
    {
        if(st.empty())
        {
            result.push_back(-1);
            st.push(A[i]);
        }
        
        else
        {
            while(!st.empty() && st.top()>=A[i])st.pop();
            if(st.empty())
            {
                result.push_back(-1);
                st.push(A[i]);
            }
            
            else
            {
                result.push_back(st.top());
                st.push(A[i]);
            }
        }
    }
    
    return result;
}
