class node{
    public:
    int a;
    int b;
    
    node(int a, int b){
        this->a = a;
        this->b = b;
    }
    
    bool operator < (const node& g)const{
        return b<g.b;
    }
};

int t;
int cap;
int size;
unordered_map<int,int> val;
unordered_map<int,int> tm;
set<node> pages;
LRUCache::LRUCache(int capacity) {
    cap = capacity;
    size = 0;
    val.clear();
    tm.clear();
    pages.clear();
    t = 0;
}

int LRUCache::get(int key) {
    if(val.count(key)==0 || val[key]==-1)
    {
        t++;
        return -1;
    }
    
    else
    {
        int current_time = tm[key];
        int to_return = val[key];
        pages.erase(node(key,current_time));
        pages.insert(node(key,t));
        tm[key] = t;
        t++;
        return to_return;
    }
    
    
}

void LRUCache::set(int key, int value) {
    if(val.count(key)==0 || val[key]==-1)
    {
        if(size<cap)
        {
            val[key] = value;
            tm[key] = t;
            size++;
            pages.insert(node(key,t));
        }
        
        else
        {
            auto it = pages.begin();
            int page = it->a;
            val[page] = -1;
            pages.erase(it);
            pages.insert(node(key,t));
            val[key] = value;
            tm[key] = t;
            
        }
        
    }
    
    else
    {
        int current_time = tm[key];
        pages.erase(node(key,current_time));
        pages.insert(node(key,t));
        val[key] = value;
        tm[key] = t;
    }
    
    t++;
}
