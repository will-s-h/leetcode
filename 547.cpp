class Solution {
public:
    
    void dfs(int n, vector<bool>& v, vector<vector<int>>& e){
        v[n] = true;
        for(int i = 0; i < e.size(); i++){
            if(!v[i] && e[n][i]){
                dfs(i, v, e);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& e) { //O(n)
        vector<bool> visited(e.size());
        int num = 0;
        for(int i = 0; i < e.size(); i++){
            if(!visited[i]){
                num++;
                dfs(i, visited, e);
            }
        }
        
        return num;
    }
};
