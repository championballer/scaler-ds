vector<int> extractSubarray(vector<int> & A, int s, int e)
{
    vector<int> result;
    for(int i=s;i<=e;i++)
    {
        result.push_back(A[i]);
    }
    
    return result;
}

vector<int> Solution::solve(vector<int> &A, int B) {
    
    int i=0,j=0;
    int currentSum = A[i];
    
    for(;i<A.size();)
    {
        
        if(i==j)
        {
            if(A[i]==B)return {A[i]};
            else if(j!=A.size()-1)
            {
                j++;
                currentSum+=A[j];
            }
        
            else return {-1};
        }
        
        else
        {
            if(currentSum==B)
            {
                return extractSubarray(A,i,j);
            }
            
            else if(currentSum<B)
            {
                if(j!=A.size()-1)
                {
                    j++;
                    currentSum+=A[j];
                }
                
                else return {-1};
            }
            
            else
            {
                currentSum-=A[i];
                i++;
            }
        }
    }
    
    return {-1};
}
