int Solution::largestRectangleArea(vector<int> &A) {
    
    int mx = 0;
    stack<int> st;
    int i = 0;
    for(i=0;i<A.size();)
    {
        if(st.empty() || A[st.top()]<=A[i])st.push(i++);
        
        else
        {
            int top = st.top();st.pop();
            int area = 0;
            if(!st.empty())
            {
                area = A[top]*(i-st.top()-1);
            }
            
            else
            {
                area = A[top]*i;
            }
            
            if(area>mx)mx = area;
        }
    }
    
    while(!st.empty())
    {
        int top = st.top();st.pop();
        int area = 0;
            if(!st.empty())
            {
                area = A[top]*(i-st.top()-1);
            }
            
            else
            {
                area = A[top]*i;
            }
            
            if(area>mx)mx = area;
    }
    return mx;
    
}
