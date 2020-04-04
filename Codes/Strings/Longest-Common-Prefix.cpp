string Solution::longestCommonPrefix(vector<string> &A) {
    
    if(A.size()==0)return "";
    string prefix = A[0];
    
    for(int i=1;i<A.size();i++)
    {
        string current = "";
        for(int j=0;j<min(prefix.length(),A[i].length());j++)
        {
            if(prefix[j]==A[i][j])current+=prefix[j];
            else break;
        }
        
        prefix = current;
    }
    
    return prefix;
}
