class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) { //O(n log n)
        auto cmp = [](vector<int>& v1, vector<int>& v2){
            return (v1[0]-v1[1]) < (v2[0]-v2[1]);
        };
        
        sort(costs.begin(), costs.end(), cmp);
        
        int totalCost = 0;
        for(int i = 0; i < costs.size()/2; i++){
            totalCost += costs[i][0];
        }
        
        for(int i = costs.size()/2; i < costs.size(); i++){
            totalCost += costs[i][1];
        }
        
        return totalCost;
    }
};
