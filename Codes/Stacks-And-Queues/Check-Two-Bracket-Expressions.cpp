string helper(string s)
{
    string aux = "";
    int flag = 0;
    for(int i=0;i<s.length();)
	{
		if(i==0 && isalnum(s[i]))
		{
			aux+="+";
			aux+=s[i];
			i++;
			continue;
		}

		else if(i==0 && !isalnum(s[i]))
		{
			if(s[i]=='(')
			{
				flag = 1;
				i++;
				continue;
				

			}
			aux+=s[i];
			i++;
		}

		else if(isalnum(s[i]) && (s[i-1]!='+' && s[i-1]!='-'))
		{
			aux+='+';
			aux+=s[i];
			i++;
		}

		else
		{
			if(i==s.length()-1 && flag)
			{
				i++;
			}

			else
			{
				aux+=s[i];
				i++;	
			}
			
		}


	}

	return aux;
}

bool compare(string s1,string s2)
{
    for(int i=0;i<s1.length();i++)
    {
        if(s1[i]!=s2[i])return false;
    }
    
    return true;
}

string convert(string aux)
{
    stack<char> ourstack;
    int m_count = 0;
    string tocmp="";
    for(int i=0;i<aux.length();i++)
    {
        if(isalnum(aux[i]))tocmp+=aux[i];
        
        else if(aux[i]=='+' || aux[i]=='-')
        {
            if(aux[i+1]=='(')
            {
                if(aux[i]=='-')
                {
                    m_count++;
                }
                
                ourstack.push(aux[i]);
            }
            
            else if(isalnum(aux[i+1]))
            {
                if(aux[i]=='-')
                {
                    if(m_count%2==1)tocmp+='+';
                    else tocmp+='-';
                }
                
                else
                {
                    if(m_count%2==1)tocmp+='-';
                    else tocmp+='+';
                }
            }
            
            
        }
        
        else if(aux[i]==')')
            {
                char top = ourstack.top();
                ourstack.pop();
                if(top=='-')m_count--;
            }
    }
    
    return tocmp;
}
int Solution::solve(string A, string B) {
    
    string aux = helper(A);
    string aux2 = helper(B);
    //cout<<aux<<endl;
    //cout<<aux2<<endl;
    string tocmp1 = convert(aux);
    //cout<<tocmp1<<endl;
    string tocmp2 = convert(aux2);
    //cout<<tocmp2<<endl;
    //cout<<tocmp1<<endl;
    //cout<<tocmp2<<endl;
    return compare(tocmp1,tocmp2);
}
