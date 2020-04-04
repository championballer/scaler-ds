class TrieNode{
public:
	char val;
	int occur;
	bool term;
	vector<TrieNode* > children;

	TrieNode(char val)
	{
		this->val = val;
		occur = 1;
		children.assign(26,NULL);
	}
};

void ins(TrieNode* root, string str)
{
	TrieNode* current = root;
	for(int i=0;i<str.length();i++)
	{
		int x = str[i]-'a';

		if(i==str.length()-1)
		{
			current->term = true;
		}

		if(current->children[x]!=NULL)
		{
			current = current->children[x];
			current->occur++;
		}

		else
		{
			current->children[x] = new TrieNode(str[i]);
			
			current = current->children[x];
		}

		
	}
}

string pr(TrieNode* root,string str)
{
	TrieNode* current = root;
	string result="";
	for(int i=0;i<str.length();i++)
	{
		int x = str[i]-'a';
		current = current->children[x];
		if(current->occur==1)
		{
			result+=str[i];
			return result;
		}
		else
		{
			result+=str[i];
		}
	}

	return result;
}

vector<string> Solution::prefix(vector<string> &A) {
    
    vector<string> result;
    TrieNode* root = new TrieNode('\0');
    for(int i=0;i<A.size();i++)
    {
        ins(root,A[i]);
    }
    
    for(int i=0;i<A.size();i++)
    {
        string to_push = pr(root,A[i]);
        result.push_back(to_push);
    }
    
    return result;
}
