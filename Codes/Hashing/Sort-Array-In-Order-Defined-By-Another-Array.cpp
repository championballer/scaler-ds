vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    sort(A.begin(),A.end());
    map<int,int> ourmap;
    for(int i=0;i<A.size();i++)
    {
        ourmap[A[i]]++;
    }
    
    // for(auto it = ourmap.begin();it!=ourmap.end();it++)
    // {
    //     cout<<it->first<<" "<<it->second<<endl;
    // }
    vector<int> result;
    for(int i=0;i<B.size();i++)
    {
        if(ourmap.count(B[i]))
        {
            int k = ourmap[B[i]];
            for(int j=0;j<k;j++)
            {
                result.push_back(B[i]);
                ourmap[B[i]]--;
            }
        }
    }
    
    for(auto it = ourmap.begin();it!=ourmap.end();it++)
    {
        if(it->second)
        {
            
            for(int j=0;j<it->second;j++)
            {
                result.push_back(it->first);
            }
        }
    }
    return result;
    
}
