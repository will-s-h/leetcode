class Solution {
public:
    void sortColors(vector<int>& nums) { //O(N), move 0s to the left, move 2s to the right
        int l = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                swap(nums[l], nums[i]);
                l++;
            }
        }
        
        int r = nums.size()-1;
        for(int i = nums.size()-1; i >= 0; i--){
            if(nums[i] == 2){
                swap(nums[r], nums[i]);
                r--;
            }
        }
    }
};
