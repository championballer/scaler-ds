int Solution::solve(vector<int> &A, int B) {
    vector<int> final(A);
    priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > > pq;
    for(int i=0;i<final.size();i++)
    {
        pq.push(make_pair(final[i]+A[i],i));
    }
    
    int t = 0;
    while(t!=B)
    {
        pair<int,int> top = pq.top();
        pq.pop();
        int sum = top.first;
        int index = top.second;
        final[index] = sum;
        pq.push(make_pair(sum+A[index],index));
        
        t++; 
    }
    
    int mx = INT_MIN;
    for(int i=0;i<final.size();i++)mx = max(final[i],mx);
    return mx;
}
