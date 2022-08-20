class Solution {
public:
    int findPeakElement(vector<int>& nums) { //O(log N)
        if(nums.size() == 1 || nums[0] > nums[1]) return 0;
        if(nums[nums.size()-1] > nums[nums.size()-2]) return nums.size()-1;
        
        int lo = 1;
        int hi = nums.size()-2;
        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]) return mid;
            else if(nums[mid] < nums[mid-1]){
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        return lo;
    }
};
