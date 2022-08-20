class Solution {
public:
    int numJewelsInStones(string jewels, string stones) { //O(N+M)
        bool s[256] = {};
        for(int i = 0; i < jewels.length(); i++){
            s[jewels[i]] = true;
        }
        
        int num = 0;
        for(int i = 0; i < stones.length(); i++){
            if(s[stones[i]]) num++;
        }
        return num;
    }
};
