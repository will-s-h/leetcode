class Solution {
public:
    int hammingDistance(int x, int y) {
        int m = x^y;
        int dist = 0;
        while(m > 0){
            dist += m%2;
            m/=2;
        }
        return dist;
    }
};
