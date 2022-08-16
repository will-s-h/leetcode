class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string, unordered_set<string>> m; //{domain}, {local}
        int num = 0;
        for(string s : emails){
            int atIndex = -1;
            for(int i = 0; i < s.length(); i++){
                if(s[i] == '@') {atIndex = i; break;}
            }
            
            string domain = s.substr(atIndex+1, s.length()-atIndex-1);
            
            string local = "";
            for(int i = 0; i < atIndex; i++){
                if(s[i] == '.') continue;
                if(s[i] == '+') break;
                local += s[i];
            }
            
            if(m[domain].count(local) == 0){
                m[domain].insert(local);
                num++;
            }
        }
        
        return num;
    }
};
