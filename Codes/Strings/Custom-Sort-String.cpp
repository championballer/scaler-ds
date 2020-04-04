string Solution::solve(string A, string B) {
    map<char,int> ourmap;
    string result;
    for(int i=0;i<B.length();i++)
    {
        ourmap[B[i]]++;
    }
    
    for(int i=0;i<A.length();i++)
    {
        if(ourmap.count(A[i]))
        {
            for(int j=0;j<ourmap[A[i]];j++)
            {
                result+=A[i];
            }
            ourmap[A[i]] = 0;
        }
    }
    
    for(auto it=ourmap.begin();it!=ourmap.end();it++)
    {
        for(int j=0;j<it->second;j++)
        {
            result+=it->first;
        }
    }
    
    return result;
}
