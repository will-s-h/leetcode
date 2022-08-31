class Solution {
public:
    
    vector<vector<int>> ans;
    vector<vector<int>> ocean;
    int m, n;
    
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    void floodfill(queue<pair<int,int>>& q, vector<vector<int>>& h, int val){
        while(!q.empty()){
            pair<int,int> p = q.front(); q.pop();
            int i = p.first; int j = p.second;
            if(ocean[i][j] == 3) ans.push_back({i,j});
            
            for(int d = 0; d < 4; d++){
                int x = i + dx[d]; int y = j + dy[d];
                if(x >= 0 && x < m && y >= 0 && y < n){
                    if((ocean[x][y] & val) == 0 && h[x][y] >= h[i][j]){
                        ocean[x][y] |= val;
                        q.push({x,y});
                    }
                }
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) { //O(NM)
        m = h.size(); n = h[0].size();
        ans = vector<vector<int>>();
        ocean = vector<vector<int>>(m, vector<int>(n));
        //0 means none, 1 means pacific, 2 means atlantic, 3 means both
        
        queue<pair<int,int>> q;
        for(int i = 0; i < m; i++) {q.push({i, 0}); ocean[i][0] |= 1;}
        for(int j = 1; j < n; j++) {q.push({0, j}); ocean[0][j] |= 1;}
        
        floodfill(q, h, 1);
        
        for(int i = 0; i < m; i++) {q.push({i, n-1}); ocean[i][n-1] |= 2;}
        for(int j = 0; j < n-1; j++) {q.push({m-1, j}); ocean[m-1][j] |= 2;}
        
        floodfill(q, h, 2);
        
        return ans;
    }
};
