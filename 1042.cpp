class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) { //O(N+M)
        vector<int> color(n);
        vector<vector<int>> edges(n);
        
        for(vector<int>& e : paths){
            edges[e[0]-1].push_back(e[1]-1);
            edges[e[1]-1].push_back(e[0]-1);
        }
        
        //greedy
        for(int i = 0; i < n; i++){
            bool used[5] = {};
            for(int next : edges[i]){
                used[color[next]] = true;
            }
            for(int c = 1; c <= 4; c++){
                if(!used[c]) {color[i] = c; break;}
            }
        }
        
        return color;
    }
};
