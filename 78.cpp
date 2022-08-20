class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) { //O(N*2^N)
        vector<vector<int>> sol;
        for(int s = 0; s < (1 << nums.size()); s++){
            vector<int> v;
            for(int p = 0; p < nums.size(); p++){
                if(s & (1 << p)) v.push_back(nums[p]);
            }
            sol.push_back(v);
        }
        return sol;
    }
};
