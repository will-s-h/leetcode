class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) { //O(N)
        int n = cost.size();
        vector<int> dp(n);
        
        for(int i = 2; i < n; i++){
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        
        return min(dp[n-1] + cost[n-1], dp[n-2] + cost[n-2]);
    }
};
