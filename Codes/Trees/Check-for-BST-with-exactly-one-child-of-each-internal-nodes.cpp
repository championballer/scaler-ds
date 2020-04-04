//Time complexity -> O(N)

string Solution::solve(vector<int> &A) {
    
    if(A.size()==0 || A.size()==1)return "YES";
    
    vector<int> mn(A.size());
    vector<int> mx(A.size());
    
    mn[A.size()-1] = A[A.size()-1];
    mx[A.size()-1] = A[A.size()-1];
    for(int i=A.size()-2;i>=0;i--)
    {
        if(A[i]<mn[i+1])mn[i] = A[i];
        else mn[i] = mn[i+1];
        
        if(A[i]>mx[i+1])mx[i] = A[i];
        else mx[i] = mx[i+1];
    }
    
    
    for(int i=0;i<A.size()-1;i++)
    {
        if(A[i]>A[i+1])
        {
            if(A[i]>=mx[i+1])continue;
            else return "NO";
        }
        
        else
        {
            if(A[i]<=mn[i+1])continue;
            else return "NO";
        }
    }
    
    return "YES";
}
