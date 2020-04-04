int Solution::solve(vector<int> &A, int B) {
    
    int result = 0;
    int i=0, j = A.size()-1;
    while(i<j)
    {
        if(A[i]+A[j]==B)
        {
            result++;
            i++;
            j--;
        }
        
        else if(A[i]+A[j]>B)j--;
        else i++;
    }
    
    return result;
}
