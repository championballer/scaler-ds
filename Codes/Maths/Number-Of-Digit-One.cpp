int Solution::solve(int A) {
    
    int count = 0;
    long long step = 10000000000;
    int n = A;
    while(step>0)
    {
        int t1 = n/step;
        int t2 = n%step;
        int t3 = step/10;
        int current = (long long)t1*t3 + min(max(t2-t3+1,0),t3);
        //cout<<"c:"<<current<<" s:"<<step<<endl;
        count+=current;
        step/=10;
    }
    
    return count;
    
}
