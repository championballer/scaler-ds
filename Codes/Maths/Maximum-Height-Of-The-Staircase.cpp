long long sqrt(long long A) {
    
    if(A==0)return 0;
    if(A<=3)return 1;
    
    long long low = 0;
    long long high = A;
    long long mid = low+(high-low)/2;
    while(low<=high)
    {
        mid = low+(high-low)/2;   
        if((mid==(A/mid)) || (mid<(A/mid) && mid+1>(A/(mid+1))))return mid;
        if(mid>(A/mid))high = mid-1;
        else low = mid+1;
    }
    
    return mid;
}

int Solution::solve(int A) {
    
    long long d = 1+(long long)8*A;
    return (-1+(int)sqrt(d))/2;
}
