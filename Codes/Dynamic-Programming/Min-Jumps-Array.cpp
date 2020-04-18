int Solution::jump(vector<int> &A) {
    
    if(A.size()==1)return 0;
    int mx = A[0];
    int steps = A[0];
    int jump = 1;
    if(steps==0)return -1;
    for(int i=1;i<A.size();i++)
    {
        if(mx==A.size()-1)return jump+1;
        mx = max(mx,A[i]+i);
        steps--;
        
        if(steps==0)
        {
            jump++;
            if(mx<i)return -1;
            steps = mx-i;
        }
    }
    
}