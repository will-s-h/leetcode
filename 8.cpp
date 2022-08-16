class Solution {
public:
    int myAtoi(string s){
        int i = 0; int n = s.length();
        while(i < n && s[i] == ' ') i++;
        
        bool neg = false;
        if(i < n && s[i] == '-'){neg = true; i++;}
        else if(i < n && s[i] == '+') i++;
        int m = neg ? -1 : 1;
        
        int result = 0;
        while(i < n && s[i]-'0' >= 0 && s[i]-'0' < 10){
            if(result > INT_MAX/10) return INT_MAX;
            if(result < INT_MIN/10) return INT_MIN;
            result *= 10;
            
            int d = m*(s[i] - '0');
            if(result > INT_MAX - abs(d)) return INT_MAX;
            if(result < INT_MIN + abs(d)) return INT_MIN;
            result += d;
            i++;
        }
        
        return result;
    }
};
