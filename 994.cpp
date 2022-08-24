class Solution {
public:
    struct rotten{int i, j, t;};
    int orangesRotting(vector<vector<int>>& grid) { //O(NM)
        int n = grid.size(); int m = grid[0].size();
        int fresh = 0;
        queue<rotten> q;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) fresh++;
                else if(grid[i][j] == 2) q.push({i,j,1});
            }
        }
        
        int t = 0;
        while(!q.empty() && fresh > 0){
            rotten r = q.front(); q.pop();
            t = r.t;
            
            if(r.i-1 >= 0 && grid[r.i-1][r.j] == 1){
                fresh--;
                grid[r.i-1][r.j] = 2;
                q.push({r.i-1, r.j, r.t+1});
            }
            if(r.i+1 < n && grid[r.i+1][r.j] == 1){
                fresh--;
                grid[r.i+1][r.j] = 2;
                q.push({r.i+1, r.j, r.t+1});
            }
            if(r.j-1 >= 0 && grid[r.i][r.j-1] == 1){
                fresh--;
                grid[r.i][r.j-1] = 2;
                q.push({r.i, r.j-1, r.t+1});
            }
            if(r.j+1 < m && grid[r.i][r.j+1] == 1){
                fresh--;
                grid[r.i][r.j+1] = 2;
                q.push({r.i, r.j+1, r.t+1});
            }
        }
        
        if(fresh > 0) return -1;
        return t;
    }
};
