class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last[256]; //index of last instance of character i
        fill(last, last+256, -1);

        int best = 0; //best length substring
        int prev = 0; //length of substring ending on previous character

        for(int i = 0; i < s.length(); i++){
            int substr = min(prev+1, i - last[s[i]]);
            best = max(best, substr);
            last[s[i]] = i;
            prev = substr;
        }

        return best;
    }
};
