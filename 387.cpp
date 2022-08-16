class Solution {
public:
    int firstUniqChar(string s) {
        int exists[26] = {};
        for(int i = 0; i < s.length(); i++){
            exists[s[i]-'a']++;
        }
        for(int i = 0; i < s.length(); i++){
            if(exists[s[i]-'a'] < 2) return i;
        }
        return -1;
    }
};
