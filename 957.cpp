class Solution {
public:
    uint8_t nextDay(uint8_t code) {
        code = ~ ((code << 1) ^ (code >> 1));
        if (code % 2) code -= 1;
        if (code / 128) code -= 128;
        return code;
    }
    
    vector<int> prisonAfterNDays(vector<int>& cells, int n) { //O(1)
        uint8_t code = 0;
        for (int i : cells) {
            code *= 2;
            code += i;
        }
        
        // find the cycle
        uint8_t originalCode = code;
        int cycle = 1;
        unordered_map<uint8_t, int> m; // {code, day}
        for (int i = 0; i <= min(n-1, 256); i++) {
            if (m.count(code)) {
                cycle = i-m[code];
                n -= i;
                break;
            } else {
                m[code] = i;
            }
            
            code = nextDay(code);
        }
        
        n %= cycle;
        
        for (int i = 0; i < n; i++) {
            code = nextDay(code);
        }
        
        vector<int> results(8);
        for(int i = 0; i < 8; i++) {
            results[7-i] = (code % 2);
            code /= 2;
        }
        return results;
    }
};
