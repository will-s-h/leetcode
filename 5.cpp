class Solution {
public:
    string longestPalindrome(string s){ //O(n^2)
        int longest = 0;
        string longPal;

        for(int i = 0; i < s.length(); i++){
            int l = i; int r = i;

            while(l-1 >= 0 && r+1 < s.length() && s[l-1] == s[r+1]){
                l--;
                r++;
            } 

            if(r-l+1 > longest){
                longest = r-l+1;
                longPal = s.substr(l, r-l+1);
            }

            l = i+1; r = i;
            while(l-1 >= 0 && r+1 < s.length() && s[l-1] == s[r+1]){
                l--;
                r++;
            }

            if(r-l+1 > longest){
                longest = r-l+1;
                longPal = s.substr(l, r-l+1);
            }
        }

        return longPal;
    }
};
