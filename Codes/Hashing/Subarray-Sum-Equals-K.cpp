int Solution::solve(vector<int> &A, int B) {
    
    int ans = 0;
    unordered_map<int,int> ourmap;
    int current = 0;
    
    for(int i=0;i<A.size();i++)
    {
        current+=A[i];
        if(current==B)ans++;
        if(ourmap.count(current-B))
        {
            ans+=ourmap[current-B];
        }
        
        ourmap[current]++;
    }
    
    return ans;
}
