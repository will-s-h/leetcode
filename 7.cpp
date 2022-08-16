class Solution {
public:
    int reverse(int x) {
        int result = 0;

        while(x != 0){
            if(result > INT_MAX/10 || result < INT_MIN/10) return 0;
            result *= 10;
            
            if(result > INT_MAX-abs(x%10) || result < INT_MIN+abs(x%10)) return 0;
            result += x%10;

            x /= 10;
        }

        return result;
    }
};
