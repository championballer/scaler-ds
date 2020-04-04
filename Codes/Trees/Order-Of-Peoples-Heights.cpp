int find(vector<int>& result,int infront)
{
    int ans = 0;
    for(int i=0;i<result.size();i++)
    {
        if(ans==infront && result[i]==-1)return i;
        if(result[i]==-1)ans++;
        
        
    }
    
    return ans;
}


vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    
    vector<pair<int,int > > v;
    for(int i=0;i<A.size();i++)
    {
        v.push_back(make_pair(A[i],B[i]));
    }
    
    sort(v.begin(),v.end());
    
    vector<int> result(A.size(),-1);
    
    for(int i=0;i<v.size();i++)
    {
        int element = v[i].first;
        int infront = v[i].second;
        
        int index = find(result,infront);
        //cout<<index<<endl;
        result[index] = element;
    }
    return result;
}
