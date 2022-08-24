class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) { //O(N)
        vector<bool> v(nums.size());
        int num = 0;
        for(int i = 0; i < nums.size(); i++){
            num = (num*2 + nums[i]) % 5;
            v[i] = (num == 0);
        }
        return v;
    }
};
