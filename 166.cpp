class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long n = numerator;
        long long d = denominator;
        if(n % d == 0) return to_string(n/d);
        string ans = to_string(n/d) + ".";
        if(n/d == 0 && d/n < 0) ans = "-" + ans; //edge case where n/d = 0 doesn't format properly
        n = (n%d)*10;
        
        vector<char> decimal;
        unordered_map<long long, int> m; //{remainder, index of first appearance}
        int pos = -1; //position of left parenthesis
        while(n != 0){
            if(m.count(n) > 0){ //already seen this remainder before
                pos = m[n];
                break;
            }
            
            m[n] = decimal.size();
            decimal.push_back(abs(n/d) + '0');
            n = (n%d)*10;
        }
        
        if(pos < 0) return (ans + string(decimal.begin(), decimal.end()));
        else return (ans + string(decimal.begin(), decimal.begin()+pos)
                    + "(" + string(decimal.begin()+pos,decimal.end()) +")");
    }
};
