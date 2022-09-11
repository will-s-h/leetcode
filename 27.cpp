class Solution {
public:
    int removeElement(vector<int>& nums, int val) { //O(N)
        int j = 0;
        for(int k = 0; k < nums.size(); k++){
            if(nums[k] != val){
                nums[j] = nums[k];
                j++;
            }
        }
        return j;
    }
};
