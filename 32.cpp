class Solution {
public:
    int longestValidParentheses(string s) { //O(n) time and memory, using DP
        int n = s.length(); vector<int> dp(n+1);
        s = " " + s; int m = 0;
        for(int i = 2; i <= n; i++){
            if(s[i] == ')'){
                if(s[i-1-dp[i-1]] == '(')  dp[i] = dp[i-1] + 2 + dp[i-1-dp[i-1]-1];
                m = max(m, dp[i]);
            }
        }
        return m;
    }
};
