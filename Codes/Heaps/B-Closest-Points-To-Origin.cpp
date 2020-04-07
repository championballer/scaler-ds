long long squ(long long a){return (long long)a*a;}

class node{
    public:
    int x;
    int y;
    float d;
    
    node(int x,int y,float d)
    {
        this->x = x;
        this->y = y;
        this->d = d;
    }
    
    bool operator <(const node & g)const{
        return d>g.d;
    }
};

vector<vector<int> > Solution::solve(vector<vector<int> > &A, int B) {
    
    vector<vector<int> > result;
    priority_queue<node> pq;
    for(int i=0;i<A.size();i++)
    {
        int x = A[i][0];
        int y = A[i][1];
        int d = sqrt(squ(x)+squ(y));
        
        pq.push(node(x,y,d));
    }
    
    for(int i=0;i<B;i++)
    {
        node top = pq.top();
        pq.pop();
        
        vector<int> current;
        current.push_back(top.x);
        current.push_back(top.y);
        result.push_back(current);
    }
    return result;
}
