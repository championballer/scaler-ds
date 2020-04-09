bool checkValid(const vector<string> & A, int x, int y)
{
    
    if(x==8 && y==8 && A[x][y]=='.')return true;
    //row check
    for(int i=0;i<A.size();i++)
    {
        if(i==x)continue;
        if(A[i][y]==A[x][y])return false;
    }
    // cout<<"col"<<endl;
    //col check
    for(int j=0;j<A.size();j++)
    {
        if(j==y)continue;
        if(A[x][j]==A[x][y])return false;
    }
    //grid check
    // cout<<"grid"<<endl;
    // cout<<x<<" "<<y<<endl;
    int sx = (x/3)*3;
    int sy = (y/3)*3;
    // cout<<sx<<" "<<sy<<endl;
    for(int i=sx;i<sx+3;i++)
    {
        for(int j=sy;j<sy+3;j++)
        {
            if(i==x && j==y)continue;
            //cout<<A[x][y]<<" "<<A[i][j]<<endl;
            if(A[i][j]==A[x][y])return false;
        }
        //cout<<endl;
    }
    
    return true;
}

bool helper(const vector<string>& A, int i,int j)
{
    //cout<<i<<" "<<j<<" "<<A[i][j]<<endl;
    if(i>=A.size() || j>=A.size())return false;
    if(i==A.size()-1 && j==A.size()-1)
    {
        return checkValid(A,i,j);
    }
    if(A[i][j]=='.')
    {
        if(j+1<A.size())
        {
            return helper(A,i,j+1);
        }
        
        else return helper(A,i+1,0);
        
    }
    
    
    bool sans = checkValid(A,i,j);
    if(!sans)return sans;
    else if(j+1<A.size())
    {
        return helper(A,i,j+1);
    }
    
    else return helper(A,i+1,0);
}

int Solution::isValidSudoku(const vector<string> &A) {
   
    return helper(A,0,0);
}
