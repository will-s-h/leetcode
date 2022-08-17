class Solution {
public:
    string morse[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> m;
        for(string word : words){
            string morseRep = "";
            for(char c : word){
                morseRep += morse[c-'a'];
            }
            m.insert(morseRep);
        }
        
        return m.size();
    }
};
