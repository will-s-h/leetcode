class Solution {
public:
    int longestCommonSubsequence(string s, string t){ //O(NM)
        int N = s.length(); int M = t.length();
        vector<vector<int>> dp = vector<vector<int>>(N+1, vector<int>(M+1));

        //find longest subsequence
        for(int j = 1; j <= M; j++){
            for(int i = 1; i <= N; i++){
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]+(s[i-1] == t[j-1] ? 1 : 0));
            }
        }

        return dp[N][M];
    }
};
