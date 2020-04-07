int Solution::solve(vector<vector<int> > &A) {
    vector<int> s;
    vector<int> e;
    
    for(int i=0;i<A.size();i++)
    {
        int x = A[i][0];
        int y = A[i][1];
        
        s.push_back(x);
        e.push_back(y);
    }
    
    sort(s.begin(),s.end());
    sort(e.begin(),e.end());
    
    int mx = 0;
    int count = 0;
    int i = 0,j=0;
    while(i<A.size())
    {
        if(s[i]<e[j])
        {
            i++;
            count++;
            if(count>mx)mx = count;
        }
        
        else
        {
            j++;
            count--;
        }
    }
    
    return mx;
}
