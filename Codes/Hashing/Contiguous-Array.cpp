int Solution::solve(vector<int> &A) {
    
    vector<int> aux;
    vector<int> leftsum;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]==0)aux.push_back(-1);
        else aux.push_back(1);
    }
    
    if(A[0]==1)leftsum.push_back(1);
    else leftsum.push_back(-1);
    
    for(int i=1;i<aux.size();i++)
    {
        leftsum.push_back(leftsum[i-1]+aux[i]);
    }
    
    unordered_map<int,int> ourmap;
    
    int maxsize = 0;
    for(int i=0;i<leftsum.size();i++)
    {
        if(leftsum[i]==0)maxsize = i+1;
    }
    for(int i=0;i<leftsum.size();i++)
    {
        if(ourmap.count(leftsum[i]))
        {
            int diff = i-ourmap[leftsum[i]];
            if(diff>maxsize)maxsize = diff;
        }
        
        else
        {
            ourmap[leftsum[i]] = i;
        }
    }
    return maxsize;
}
