class Solution {
public:
    bool repeatedSubstringPattern(string s){ //O(n), using KMP. runtime: 23 ms
        int n = (int) s.length();
        vector<int> dp(n);
        for(int i = 1; i < n; i++){
            int j = dp[i-1];
            while(j > 0 && s[j] != s[i]) j = dp[j-1];
            if(s[j] == s[i]) dp[i] = j+1;
        }
        return dp[n-1] && (n%(n-dp[n-1]) == 0);
    }
    
    bool slow(string s) { //O(n sigma(n)), where sigma(n) is the divisor function. runtime: 36 ms (actually not that bad)
        //see [https://math.stackexchange.com/questions/3043181/growth-rate-of-a-divisor-function] for details on the divisor function's growth.
        for(int l = 1; l < s.length()/2 + 1; l++){
            if(s.length() % l != 0) continue;
            bool works = true;
            string sub = s.substr(0, l);
            for(int i = l; i < s.length(); i += l){
                if(s.substr(i,l) != sub){
                    works = false;
                    break;
                }
            }
            if(works) return true;
        }
        
        return false;
    }
};
