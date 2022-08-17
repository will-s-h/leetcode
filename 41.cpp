class Solution {
public:
    int firstMissingPositive(vector<int>& n){
        for(int i = 0; i < n.size(); i++){
            while(n[i] > 0 && n[i] <= n.size() && n[i] != n[n[i]-1]){
                swap(n[i], n[n[i]-1]);
            }
        }
        for(int i = 0; i < n.size(); i++){
            if(n[i] != i+1) return i+1;
        }
        return n.size()+1;
    }
    
    int hackable(vector<int>& nums) { //works by setting visited numbers to an arbitrary nonpositive number, one that must not show up in a test case
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 1) continue;
            int j = nums[i];
            while(j <= nums.size() && j > 0){
                int temp = nums[j-1];
                nums[j-1] = -956812; //essentially betting that test cases don't have -956812; can be hacked
                j = temp;
            }
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != -956812) return i+1;
        }
        
        return nums.size()+1;
    }
};
