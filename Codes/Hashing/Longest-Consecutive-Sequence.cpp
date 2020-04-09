int Solution::longestConsecutive(const vector<int> &A) {
    
    unordered_map<int,bool> ourmap;
    int ans = 0;
    for(int i=0;i<A.size();i++)
    {
        ourmap[A[i]] = false;
    }
    
    for(auto it = ourmap.begin();it!=ourmap.end();it++)
    {
        int current = 0;
        int s1 = it->first;
        int s2 = it->first+1;
        while(ourmap.count(s1) && ourmap[s1]==false)
        {
            current++;
            ourmap[s1] = true;
            if(current>ans)ans = current;
            s1--;
        }
        while(ourmap.count(s2)!=0 && ourmap[s2]==false)
        {
            current++;
            ourmap[s2] = true;
            if(current>ans)ans = current;
            s2++;
            
        }
    }
    return ans;
}
