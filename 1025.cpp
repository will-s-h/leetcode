class Solution {
public:
    bool divisorGame(int n) {
        if(n <= 1) return false;
        vector<bool> dp(n+1);
        
        for(int i = 2; i <= n; i++){
            for(int j = 1; j < i; j++){
                if(i % j != 0) continue;
                if(!dp[i-j]) dp[i] = true;
            }
        }
        
        return dp[n];
    }
};
