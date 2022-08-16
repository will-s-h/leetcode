class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); //O(n log n)
        
        vector<vector<int>> sols;
        
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int sum = -nums[i];
            
            int l = i+1; //left index
            int r = nums.size()-1; //right index
            
            while(l < r){
                while(l < r && nums[l] + nums[r] > sum){
                    r--;
                }
                
                if(l < r && nums[l] + nums[r] == sum){
                    sols.push_back({nums[i], nums[l], nums[r]});
                }
                
                l++;
                
                while(l < r && nums[l] == nums[l-1]) l++;
            }
        }
        
        return sols;
    }
};
