#define MOD 1000000007
typedef long long ll;

int Solution::solve(vector<int> &A, int B) {
    
    ll count = 0;
    int i=0;
    int j=A.size()-1;
    
    while(i<=j)
    {
        ll area = (A[i]*(ll)A[j]);
        
        if(area>=B)j--;
        else
        {
            count = count + (((((j-i)*2)%MOD)+1)%MOD);
            i++;
        }
    }
    return int(count%MOD);
}
