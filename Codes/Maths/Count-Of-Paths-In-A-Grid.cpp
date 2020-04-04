#define MOD 1000000007
int Solution::solve(int A) {
    long long  int C[A+1];
    C[0]=C[1]=1;
    for(int i=2;i<=A;i++)
    {
        C[i]=0;
        for(int j=0;j<i;j++)
        {
            int x=(C[j]%MOD*C[i-j-1]%MOD)%MOD;
            C[i]+=x;
            C[i]=C[i]%MOD;
        }
    }
    
    return (int)C[A-1];
    
}
