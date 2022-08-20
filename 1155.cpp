class Solution {
public:
    
    const int M = 1e9 + 7;
    
    int numRollsToTarget(int n, int k, int target) { // DP, O(nkt)
        if(n*k < target) return 0;
        vector<vector<int>> dp = vector<vector<int>>(n+1, vector<int>(target+1));
        dp[0][0] = 1;
        
        for(int r = 1; r <= n; r++){ //roll number
            for(int t = target; t >= 0; t--){
                for(int f = 1; f <= k; f++){
                    if(t-f >= 0) dp[r][t] += dp[r-1][t-f];
                    dp[r][t] %= M;
                }
            } 
        }
        
        return dp[n][target];
    }
};
