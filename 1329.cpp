class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) { //O(NM)
        int m = mat.size();
        int n = mat[0].size();
        
        for(int i = m-1; i >= 0; i--){
            int x = i; int y = 0;
            vector<int> v;
            while(x < m && y < n){
                v.push_back(mat[x][y]);
                x++; y++;
            }
            sort(v.begin(), v.end());
            x = i; y = 0;
            
            for(int j = 0; j < v.size(); j++){
                mat[x][y] = v[j];
                x++; y++;
            }
        }
        
        for(int j = 1; j < n; j++){
            int x = 0; int y = j;
            vector<int> v;
            while(x < m && y < n){
                v.push_back(mat[x][y]);
                x++; y++;
            }
            sort(v.begin(), v.end());
            x = 0; y = j;
            
            for(int i = 0; i < v.size(); i++){
                mat[x][y] = v[i];
                x++; y++;
            }
        }
        return mat;
    }
};
