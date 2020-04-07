class node{
    public:
    
    int e;
    int r;
    
    node(int e,int r)
    {
        this->e = e;
        this->r = r;
    }
    
    bool operator <(const node& g)const{
        if(e!=g.e)return e<g.e;
        else return r>g.r;
    }
};

vector<int> Solution::solve(vector<int> &A, int B) {
    vector<int> result;
    priority_queue<node> pq;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]!=0)
        pq.push(node(A[i],i));
    }
    
    int t = 0;
    while(!pq.empty() && t<B)
    {
        node current = pq.top();
        int e = current.e;
        e--;
        int r = current.r;
        result.push_back(r);
        pq.pop();
        if(e>0)pq.push(node(e,r));
        t++;
    }
    
    return result;
}
