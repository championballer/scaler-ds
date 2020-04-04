int Solution::solve(const string A, const string B) {

    string aux = "";
    aux+=B[0];
    for(int i=1;i<B.length();i++)
    {
        if(B[i]!=B[i-1])aux+=B[i];
    }
    return aux==A;
}
