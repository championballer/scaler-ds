bool check_comp(char c1, char c2){
    if(c1 == '[' && c2 == ']')return true;
    if(c1 == '{' && c2 == '}')return true;
    if(c1 == '<' && c2 == '>')return true;
    if(c1 == '(' && c2 == ')')return true;
    return false;
}
int Solution::LBSlength(const string A) {
    int l = A.size();
    stack<pair<char, int> >s;
    s.push({'$', -1});
    int ans = 0;
    for(int i = 0; i < l; ++i){
         if(A[i] == '[' || A[i] == '{' || A[i] == '<' || A[i] == '(')s.push({A[i], i});
         else{
             auto it = s.top();s.pop();
             if(s.empty())s.push({A[i], i});
             else{
                 if(check_comp(it.first, A[i]))ans = max(ans, i - s.top().second);
                 else{
                     while(!s.empty())s.pop();
                     s.push({A[i], i});
                 }
             }
         }
    }
    return ans;
}