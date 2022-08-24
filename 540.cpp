class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) { //O(log N)
        if(nums.size() == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        else if(nums[nums.size()-1] != nums[nums.size()-2]) return nums[nums.size()-1];
        int lo = 1;
        int hi = nums.size()-2;
        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            bool even = (mid % 2 == 0);
            bool plus = nums[mid] == nums[mid+1];
            bool minus = nums[mid] == nums[mid-1];
            if(!plus && !minus) return nums[mid];
            else if(even ? plus : minus) lo = mid+1;
            else hi = mid-1;
        }
        
        return nums[lo];
    }
};
