class Solution {
public:
    int oneChar(char c){
        if(c == 'I') return 1;
        if(c == 'V') return 5;
        if(c == 'X') return 10;
        if(c == 'L') return 50;
        if(c == 'C') return 100;
        if(c == 'D') return 500;
        return 1000;
    }
    
    int romanToInt(string s) {
        int i = 0;
        int total = 0;
        while(i < s.length()){
            if(i+1 < s.length()){
                bool sub = false;
                if(s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X')) sub = true;
                if(s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C')) sub = true;
                if(s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M')) sub = true;
                if(sub){
                    total += oneChar(s[i+1]) - oneChar(s[i]);
                    i += 2;
                    continue;
                }
            }
            total += oneChar(s[i]);
            i++;
        }
        
        return total;
    }
};
