class Solution {
public:
    
    int flips;
    
    void dfs(int n, vector<bool>& visited, vector<vector<int>>& edges, vector<vector<int>>& opp){
        visited[n] = true;
        for(int next : opp[n]){
            if(!visited[next]){
                dfs(next, visited, edges, opp);
            }
        }
        
        for(int next : edges[n]){
            if(!visited[next]){
                flips++;
                dfs(next, visited, edges, opp);
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) { //O(n)
        flips = 0;
        vector<vector<int>> edges(n);
        vector<vector<int>> opp(n);
        
        for(vector<int>& v : connections){
            int a = v[0]; int b = v[1];
            edges[a].push_back(b);
            opp[b].push_back(a);
        }
        
        vector<bool> visited(n);
        dfs(0, visited, edges, opp);
        return flips;
    }
};
