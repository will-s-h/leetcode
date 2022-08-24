class Solution {
public:
    bool buddyStrings(string s, string goal) { //O(N)
        if(s.length() != goal.length()) return false;
        int seen[256] = {};
        bool zeroWorks = false;
        int numDif = 0;
        char c1 = 0; char c2 = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != goal[i]){
                numDif++;
                if(numDif == 1){
                    c1 = goal[i];
                    c2 = s[i];
                } else if(numDif == 2){
                    if(s[i] != c1 || goal[i] != c2) return false;
                } else{
                    return false;
                }
            }
            else{
                seen[(int) s[i]]++;
                if(seen[(int) s[i]] >= 2) zeroWorks = true;
            }
        }
        return (numDif == 2 || (numDif == 0 && zeroWorks));
    }
};
