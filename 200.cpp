class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int numIslands(vector<vector<char>>& grid) { //O(NM)
        int g = 0;
        int m = grid.size(); int n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    g++;
                    queue<pair<int,int>> q; q.push({i,j}); grid[i][j] = '0';
                    while(!q.empty()){
                        pair<int,int> p = q.front(); q.pop();
                        int i_ = p.first; int j_ = p.second;
                        
                        for(int d = 0; d < 4; d++){
                            int newi = i_+dx[d]; int newj = j_+dy[d];
                            if(newi >= 0 && newi < m && newj >= 0 && newj < n && grid[newi][newj] == '1'){
                                grid[newi][newj] = '0';
                                q.push({newi,newj});
                            }
                        }
                    }
                }
            }
        }
        
        return g;
    }
};
