class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) { //O(N^2) DP
        vector<int> dp(books.size()+1); //dp[i] = minheight with shelf ending on book i;
        
        for(int i = 0; i < books.size(); i++){
            int curW = books[i][0];
            int curH = books[i][1];
            dp[i+1] = dp[i] + curH;
            for(int j = i-1; j >= 0; j--){
                if(curW + books[j][0] > shelfWidth) break;
                curW += books[j][0];
                curH = max(curH, books[j][1]);
                dp[i+1] = min(dp[i+1], dp[j] + curH);
            }
        }
        
        return dp[(int) books.size()];
    }
};
