bool checkop(string c)
{
	if(c=="/" || c=="+" || c=="*" || c=="-")return true;
	else return false;
}

int Solution::evalRPN(vector<string> &infix) {
    
    stack<int> mystack;

	for(int i=0;i<infix.size();i++)
	{
		if(checkop(infix[i]))
		{
			int arg1 = mystack.top();
			mystack	.pop();
			int arg2 = mystack.top();
			mystack.pop();

			int comp = 0;
			if(infix[i]=="+")comp = arg2+arg1;
			else if(infix[i]=="*")comp = arg2*arg1;
			else if(infix[i]=="/")comp = arg2/arg1;
			else comp = arg2-arg1;

			mystack.push(comp);
		}

		else
		{
			mystack.push(int(stoi(infix[i])));
		}
	}
	
	return mystack.top();
}
