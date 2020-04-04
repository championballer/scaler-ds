int helper(string & A, int i, int multiplier)
{
    if(i==A.length()-1)return A[i]-'A'+1;
    return (A[i]-'A'+1)*multiplier+helper(A,i+1,multiplier/26);
}

int Solution::titleToNumber(string A) {
    
    int multiplier = 1;
    for(int i=1;i<A.length();i++)multiplier*=26;
    //cout<<multiplier<<endl;
    return helper(A,0,multiplier);
}
