class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& p, int k) { //O(N log N)
        priority_queue<pair<int,int>> q;
        int MV = INT_MIN;
        
        for(int i = 0; i < p.size(); i++){
            while(!q.empty() && p[i][0]-q.top().second > k) q.pop();
            if(!q.empty()){
                MV = max(MV, p[i][0] + p[i][1] + q.top().first);
            }
            q.push({p[i][1]-p[i][0], p[i][0]});
        }
        
        return MV;
    }
};
