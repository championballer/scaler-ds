void pad(string &A, string &B)
{
    if(A.length()==B.length())return;
    string toPad = "";
    string result = "";
    if(A.length()<B.length())
    {
        toPad = A;

    }
    else
    {
        toPad = B;
    }

    for(int i=0;i<max(B.length(),A.length())-min(B.length(),A.length());i++)
    {
        result+="0";
    }

    result+=toPad;
    if(toPad==A)A = result;
    else B = result;
}

string Solution::addBinary(string A, string B) {
    
    pad(A,B);
    string result = "";
    int sum=0,carry=0;
    for(int i=A.length()-1;i>=0;i--)
    {
        // cout<<A[i]<<" "<<A[i]-48<<endl;
        // cout<<B[i]<<" "<<B[i]-48<<endl;
        int current = A[i]-48+B[i]-48+carry;
        sum = current%2;
        carry = current/2;
        // cout<<"sum:"<<sum<<endl;
        // cout<<"carry:"<<carry<<endl;
        char sum_char = sum+48;
        char carry_char = carry+48;
        // cout<<carry_char+1<<endl;
        if(i==0)
        {
             string first_two = "";
             if(carry_char!='0')
             first_two+=carry_char;
             first_two+=sum_char;
             result = first_two+result;
             return result;
         }
         result = sum_char+result;
    }
    return result;
}
