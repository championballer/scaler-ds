int Solution::trailingZeroes(int A) {
    
    int result = 0;
    int x = 5;
    
    while(x<=A)
    {
        result += (A/x);
        x*=5;
    }
    
    return result;
}
