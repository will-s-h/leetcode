class Solution {
public:
    bool isPalindrome(int x){
        string s = to_string(x);
        for(int i = 0; i < s.length()/2; i++){
            if(s[i] != s[s.length()-i-1]) return false;
        }
        return true;
    }
    
    bool wostring(int x) { // w/o converting into string
        if(x < 0) return false;
        int digits = 0; int y = x;
        while(y > 0){
            digits++; 
            y /= 10;
        }
        
        int d = 1; stack<int> s;
        while(x > 0){
            if(d <= (digits+1)/2){
                s.push(x % 10);
                x /= 10;
            }
            if(d == (digits+1)/2 && digits % 2 == 1){
                s.pop();
            }
            if(d > (digits+1)/2){
                if(x % 10 != s.top()) return false;
                s.pop(); x /= 10;
            }
            d++;
        }
        
        return true;
    }
};
