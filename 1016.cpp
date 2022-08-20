class Solution {
public:
    bool queryString(string s, int n) { //O(32S), check all substrings of length 31 or less. in other words, O(S log N), since 32 comes from log_2(N)
        
        unordered_set<int> us;
        
        for(int l = 0; l < s.length(); l++){
            int sub = 0;
            for(int r = l; (r < s.length()) && (r < l+31); r++){
                sub *= 2; 
                sub += (s[r] == '1' ? 1 : 0);
                if(sub <= n) us.insert(sub);
                else break;
            }
        }
        
        for(int i = n; i >= 1; i--){
            if(us.count(i) < 1) return false;
        }
        
        return true;
    }
};
