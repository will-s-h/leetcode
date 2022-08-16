class Solution {
public:
    vector<vector<char>> tele = {
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'}
    };
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0) return ans;
        
        queue<string> q; q.push("");
        
        for(char d : digits){
            int cur = q.front().length();
            while(q.front().length() == cur){
                string s = q.front(); q.pop();
                for(char c : tele[d-'2']){
                    q.push(s + c);            
                }
            }
        }
        
        
        while(!q.empty()){
            ans.push_back(q.front()); q.pop();
        }
        return ans;
    }
};
