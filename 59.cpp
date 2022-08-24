class Solution {
public:
    vector<vector<int>> generateMatrix(int n) { //O(N^2)
        int di[4] = {0,1,0,-1};
        int dj[4] = {1,0,-1,0};
        
        int i = 0; int j = 0; int d = 0; int val = 1;
        vector<vector<int>> v(n, vector<int>(n));
        
        while(true){
            v[i][j] = val;
            int i_ = i + di[d];
            int j_ = j + dj[d];
            if(i_ < 0 || i_ >= n || j_ < 0 || j_ >= n || v[i_][j_] > 0){
                d += 1; d %= 4;
            }
            i += di[d]; j += dj[d];
            val++;
            if(val > n*n) break;
        }
        
        return v;
    }
};
