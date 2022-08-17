class Solution {
public:
    bool isNumber(string s) {
        if(s.length() < 1) return false;
        int i = 0; if(s[i] == '+' || s[i] == '-') i++;
        
        int numDots = 0;
        bool hasNum = false;
        bool hasE = false;
        while(i < s.length()){
            if(s[i] == '.') {numDots++; i++; continue;}
            if(s[i] == 'e' || s[i] == 'E'){hasE = true; i++; break;}
            if(s[i]-'0' < 0 || s[i]-'9' > 0) return false;
            i++;
            if(!hasNum) hasNum = true;
        }
        
        if(!hasNum || numDots > 1) return false;
        
        if(hasE){
            hasNum = false;
            if(i < s.length() && (s[i] == '+' || s[i] == '-')) i++;
            while(i < s.length()){
                if(s[i]-'0' < 0 || s[i]-'9' > 0) return false;
                i++;
                if(!hasNum) hasNum = true;
            }
            
            if(!hasNum) return false;
        }
        
        return true;
    }
};
