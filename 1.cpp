class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> newnums;
        
        for(int i = 0; i < nums.size(); i++){
            newnums.push_back({nums[i], i});
        }
        
        sort(newnums.begin(), newnums.end());
        
        int l = 0; int r = newnums.size()-1;
        
        vector<int> sol;
        
        while(l < r){
            while(l < r && newnums[l].first + newnums[r].first > target){
                r--;
            }
            
            if(l == r) break;
            
            if(newnums[l].first + newnums[r].first == target){
                sol.push_back(newnums[l].second);
                sol.push_back(newnums[r].second);
                return sol;
            }
            
            l++;
        }
        
        return sol;
    }
};
