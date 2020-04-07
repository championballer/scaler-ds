int helper(vector<int> & A, int x, int y)
{
    
    if(x>=y)return 0;
    // for(int i=x;i<=y;i++)cout<<A[i]<<" ";
    // cout<<endl;
    int mid = x+(y-x)/2;
    int lans = helper(A,x,mid);
    int rans = helper(A,mid+1,y);
    int current = 0;
    int i = x;
    int j = mid+1;
    vector<int> temp(y-x+1,0);
    int count = 0;
    while(i<mid+1 && j<=y)
    {
        if(A[i]<=A[j])
        {
            temp[count] = A[i];
            count++;
            i++;
        }
        
        else
        {
            temp[count] = A[j];
            //cout<<(mid+1-i)<<endl;
            current+=(mid+1-i);
            count++;
            j++;
        }
    }
    
    while(i<mid+1)
    {
        temp[count] = A[i];
        count++;
        i++;
    }
    
    while(j<=y)
    {
        temp[count] = A[j];
        
        j++;
        count++;
    }
    count = 0;
    
    for(int i=x;i<=y;i++) 
    {
        A[i] = temp[count];
        count++;
    }
    // for(int i=x;i<=y;i++)cout<<A[i]<<" ";
    // cout<<endl;
    return lans+rans+current;
    
}

/*
35 84 2 37 3 67 82 19 97 91 63 27 6 13 90 63 89 100 60 47 96 54 26 64 50 71 16 6 40 84 93 67 85 16 22 60
*/
int Solution::countInversions(vector<int> &A) {
    
    int ans = helper(A, 0, A.size()-1);
    return ans;
}
