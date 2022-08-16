class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> sol(s.length());
        fill(sol.begin(), sol.end(), s.length());
        
        int last = -s.length();
        for(int i = 0; i < s.length(); i++){
            if(s[i] == c) last = i;
            sol[i] = min(sol[i], i-last);
        }
        
        last = 2*s.length();
        for(int i = s.length()-1; i >= 0; i--){
            if(s[i] == c) last = i;
            sol[i] = min(sol[i], last-i);
        }
        
        return sol;
    }
};
