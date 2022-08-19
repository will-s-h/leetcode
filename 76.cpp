class Solution {
public:
    
    int charToInt(char c){
        if(c - 'a' >= 0 && c - 'z' <= 0) return c-'a';
        else return c-'A'+26;
    }
    
    string minWindow(string s, string t) { //O(m + n), two pointers
        vector<int> needs(52);
        for(int i = 0; i < t.length(); i++){
            needs[charToInt(t[i])]++;
        }
        
        vector<int> cur(52);
        int numRight = 52;
        for(int i = 0; i < 52; i++){
            if(needs[i] > 0) numRight--;
        }
        
        int l = 0;
        int r = -1;
        int minLength = s.length()+1;
        int lAns = -1;
        
        while(l < s.length()){
            while(r+1 < s.length() && numRight < 52){
                r++;
                int c = charToInt(s[r]);
                if(cur[c] == needs[c]-1) numRight++;
                cur[c]++;
            }
            
            if(numRight == 52){
                if(r-l+1 < minLength){
                    minLength = r-l+1;
                    lAns = l;
                }
            }
            
            int c = charToInt(s[l]);
            if(cur[c] == needs[c]) numRight--;
            cur[c]--;
            l++;
        }
        
        if(minLength <= s.length()) return s.substr(lAns, minLength);
        else return "";
    }
};
