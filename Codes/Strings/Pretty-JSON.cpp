vector<string> Solution::prettyJSON(string json) {
    
     vector<string> ans;
            if (json.length() == 0) return ans;
            // remove all spaces. 
            json.erase(remove(json.begin(), json.end(), ' '), json.end());
 
            string indent = "";
            string current = "";
            int i = 0, len = json.length();
            while (i < len) {
                current.push_back(json[i]);
                switch(json[i]) {
                    case ',':
                        ans.push_back(current);
                        current = indent;
                        i++;
                        break;
                    case ':':
                        i++;
                        if (json[i] == '{' || json[i] == '[') {
                            ans.push_back(current);
                            current = indent;
                        }
                        break;
                    case '{':
                    case '[':
                        i++;
                        ans.push_back(current);
                        if (i < len && (json[i] != '}' || json[i] != ']')) {
                            indent.push_back('\t');
                        }
                        current = indent;
                        break;
                    case '}':
                    case ']':
                        i++;
                        if (i < len && json[i] == ',') break;
                        ans.push_back(current);
                        if (i < len && (json[i] == '}' || json[i] == ']')) {
                            if (!indent.empty()) indent.pop_back();
                        }
                        current = indent;
                        break;
                    default : 
                        i++;
                        if (i < len && (json[i] == '}' || json[i] == ']')) {
                            ans.push_back(current);
                            if (!indent.empty()) indent.pop_back();
                            current = indent;
                        }
                }
            }
            return ans;
}