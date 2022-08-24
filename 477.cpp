class Solution {
public:
    int totalHammingDistance(vector<int>& nums) { //O(32*N)
        int n = nums.size();
        int has[31] = {};
        for(int n : nums){
            for(int p = 0; p < 31; p++){
                has[p] += ((n & (1 << p)) > 0);
            }
        }
        int sum = 0;
        for(int i = 0; i < 31; i++){
            sum += (n-has[i])*(has[i]);
        }
        return sum;
    }
};
