class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n);
        dp[0] = matrix[0];
        for(int r = 1; r < n; r++){
            dp[r] = vector<int>(n);
            fill(dp[r].begin(), dp[r].end(), INT_MAX);
            for(int c = 0; c < n; c++){
                for(int i = -1; i <= 1; i++){
                    if(c+i >= 0 && c+i < n) dp[r][c] = min(dp[r][c], dp[r-1][c+i] + matrix[r][c]);
                }
            }
        }
        
        int msum = INT_MAX;
        for(int c = 0; c < n; c++){
            msum = min(msum, dp[n-1][c]);
        }
        return msum;
    }
};
