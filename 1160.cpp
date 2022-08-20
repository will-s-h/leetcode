class Solution {
public:
    int countCharacters(vector<string>& words, string chars) { //O(NM + L), where N is number of words, M is max word length, and L is length of chars
        char have[26] = {};
        for(char c : chars){
            have[c-'a']++;
        }
        
        int total = 0;
        for(string w : words){
            char need[26] = {};
            bool works = true;
            for(char c : w){
                need[c-'a']++;
                if(need[c-'a'] > have[c-'a']){
                    works = false;
                    break;
                }
            }
            if(works) total += w.length();
        }
        
        return total;
    }
};
