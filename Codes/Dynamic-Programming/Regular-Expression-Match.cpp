int Solution::isMatch(const string A, const string B) {
    
    string C = A;
    reverse(C.begin(),C.end());
    string D = B;
    reverse(D.begin(),D.end());
    
    vector<int> prev(A.length()+1);
    vector<int> current(A.length()+1);
    prev[0] = 1;
    for(int i=1;i<=A.length();i++)prev[i] = 0;
    for(int j=1;j<=B.length();j++)
    {
        for(int i=0;i<=A.length();i++)
        {
            if(i==0)
            {
                //cout<<"j:"<<j<<endl;
                //cout<<D[j-1]<<endl;
                if(D[j-1]=='*')
                {
                    //cout<<"prev:"<<prev[i]<<endl;
                    current[i] = prev[i];
                }
                
                else current[i] = 0;
            }
            
            else
            {
                if(D[j-1]!='?' && D[j-1]!='*')
                {
                    if(D[j-1]==C[i-1])
                    {
                        current[i] = prev[i-1];
                    }
                    
                    else current[i] = 0;
                }
                
                else if(D[j-1]=='?')current[i] = prev[i-1];
                
                else
                {
                    
                    //cout<<"j:"<<j<<"i:"<<i<<endl;
                    //cout<<D[j-1]<<endl;
                    //cout<<current[i-1]<<" "<<prev[i-1]<<endl;
                    current[i] = current[i-1]||prev[i];
                }
            }
        }
        
        //for(int i=0;i<prev.size();i++)cout<<prev[i]<<" "<<current[i]<<endl;
        //cout<<endl;
        for(int i=0;i<prev.size();i++)prev[i] = current[i];
    }
    
    return current[A.length()];
}
