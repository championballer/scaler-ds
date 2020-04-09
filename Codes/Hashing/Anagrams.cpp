vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    
    unordered_map<string, vector<int> > ourmap;
    vector<vector<int> > result;
    for(int i=0;i<A.size();i++)
    {
        string current = A[i];
        sort(current.begin(),current.end());
        if(!ourmap.count(current))
        {
            vector<int> sans;
            sans.push_back(i+1);
            ourmap[current]=sans;
        }
        
        else
        {
            ourmap[current].push_back(i+1);
            
        }
    }
    
    for(auto it=ourmap.begin();it!=ourmap.end();it++)
    {
        result.push_back(it->second);
    }
    
    return result;
}
